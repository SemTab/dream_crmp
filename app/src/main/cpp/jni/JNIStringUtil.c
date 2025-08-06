/*
 * Copyright 2000 Perforce Software.  All rights reserved.
 *
 * This file is part of Perforce - the FAST SCM System.
 *
 * Author: Michael Bishop
 *
 * Tabs: 4 spaces
 *
 * Use these methods to convert between C strings and Java strings
 * as well as byte and char arrays.
 *
 */


#include "JNIStringUtil.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>


/*===========================================================================*\
 *
 *	Routine:	getStringClass()
 *
 *	Comments:	Utility method to get the String class.
 *
\*===========================================================================*/

jclass getStringClass( JNIEnv * env );
jclass getStringClass( JNIEnv * env )
{
	return env->FindClass( "java/lang/String" );
}


/*===========================================================================*\
 *
 *	Routine:	cchar_to_jchar()
 *
 *	Comments:	Converts a single-byte char to a double-byte char.  
 *
\*===========================================================================*/

jchar cchar_to_jchar( JNIEnv * env, char c )
{
	env; // unused
	
	/*
	** Is the character in the ASCII set?
	*/
	if ( c & 0x80 )
	{
		/*
		** XXX
		** Really, there should be code here to do the necessary
		** codepage conversion
		*/
		return (jchar)c;
	}
	else
	{
		return (jchar)c;
	}
}


/*===========================================================================*\
 *
 *	Routine:	jstring_to_cstring()
 *
 *	Comments:	Converts a java string to a cstring.
 *
 *              The caller must dispose of the memory returned.  
 *
\*===========================================================================*/

char * jstring_to_cstring( JNIEnv * env, jstring string )
{
	/*
	** Do nothing if null
	*/
	if ( string == NULL )
	{
		return NULL;
	}
	else
	{
		jbyte * theBytes;
		
		jclass stringClass = getStringClass( env );
		
		/*
		** Getting the bytes of a string will run the default CharToByteConverter
		** on the string so we get back codepage encoded bytes!
		*/
		jmethodID getBytesMethodID = env->GetMethodID( stringClass, "getBytes", "()[B" );
		
		assert( getBytesMethodID );

		jbyteArray byteArray = (jbyteArray)env->CallObjectMethod( string, getBytesMethodID );
		
		if ( !byteArray ) return NULL;
		
		/*
		** Now that we have the array, let's see how many bytes are in it
		** We will have to allocate that many chars + 1 for the null
		*/
		jsize arraySize = env->GetArrayLength( byteArray );
		
		theBytes = (char *)malloc( (arraySize + 1) * sizeof(jbyte) );
		
		/*
		** Now, get the bytes out of the byte array and stick them in the
		** string.
		*/
		jboolean isCopy;
		
		jbyte * theBytesRef = env->GetByteArrayElements( byteArray, &isCopy );
		
		memcpy( theBytes, theBytesRef, arraySize );

		/*
		** isCopy tells us if JNI allocated memory for us to use or if we were pointing
		** directly into the java string. We don't care since we made a copy ourselves
		** So, just delete whatever they allocated if they did.
		*/
		if ( isCopy )
		{
			free( theBytesRef );
		}
		
		/*
		** Polish it off by putting a null byte on the end.
		*/
		theBytes[arraySize] = 0;

		return theBytes;
	}
}


/*===========================================================================*\
 *
 *	Routine:	cstring_to_jstring()
 *
 *	Comments:	Converts a c string and returns a java string.
 *
 *              You can pass in a null-terminated c string.
 *
\*===========================================================================*/

jstring cstring_to_jstring( JNIEnv * env, const char * string )
{
	/*
	** Just pass it to the more general method which acts on
	** an arbitrary length of bytes.
	*/
	return cstring_to_jstring2( env, string, strlen(string) );
}


/*===========================================================================*\
 *
 *	Routine:	cstring_to_jstring2()
 *
 *	Comments:	Converts a c string and returns a java string.
 *
 *              You can pass in a pointer to any arbitrary array of bytes.
 *              You must also pass in how many of those bytes to create the
 *              string from.
 *
\*===========================================================================*/

jstring cstring_to_jstring2( JNIEnv * env, const char * string, unsigned long length )
{
	/*
	** Do nothing if null
	*/
	if ( string == NULL )
	{
		return NULL;
	}
	else
	{
		jclass stringClass = getStringClass( env );
		
		/*
		** Find the String constructor that takes a byte array
		*/
		jmethodID getBytesMethodID = env->GetMethodID( stringClass, "<init>", "([B)V" );
		
		assert( getBytesMethodID );
		
		/*
		** Get a java byte array from the bytes that were passed in
		*/
		jbyteArray jBytes = voidptr_to_jbyteArray( env, (const void *)string, length );
		
		/*
		** Call the constructor, passing in the java byte array.
		*/
		return(jstring)env->NewObject( stringClass, getBytesMethodID, jBytes );
	}
}


/*===========================================================================*\
 *
 *	Routine:	voidptr_to_jbyteArray()
 *
 *	Comments:	Converts an arbitrary run of bytes to a java byte array
 *              object.
 *
 *              You can pass in a pointer to any arbitrary array of bytes.
 *              You must also pass in how many of those bytes to create the
 *              java array from.
 *
\*===========================================================================*/

jbyteArray voidptr_to_jbyteArray( JNIEnv * env, const void * bytes, unsigned long size )
{
	/*
	** Do nothing if null
	*/
	if ( bytes == NULL )
	{
		return NULL;
	}
	else
	{
		/*
		** Make an array object to hold them
		*/
		jbyteArray theArray = env->NewByteArray( size );
		
		/*
		** Copy in the contents
		*/
		env->SetByteArrayRegion( theArray, 0, size, (const char *)bytes );
		
		return theArray;
	}
}


/*===========================================================================*\
 *
 *	Routine:	intArray_to_jintArray()
 *
 *	Comments:	.
 *
\*===========================================================================*/

jintArray intArray_to_jintArray( JNIEnv * env, const long * ints, unsigned long size )
{
	/*
	** Do nothing if null
	*/
	if ( ints == NULL )
	{
		return NULL;
	}
	else
	{
		/*
		** Make an array object to hold them
		*/
		jintArray theArray = env->NewIntArray( size );
		
		/*
		** Copy in the contents
		*/
		env->SetIntArrayRegion( theArray, 0, size, ints );
		
		return theArray;
	}
}


/*===========================================================================*\
 *
 *	Routine:	charptr_to_jcharArray()
 *
 *	Comments:	Converts an arbitrary run of chars to a java char
 *              (double-byte) array object.
 *
 *              You can pass in a pointer to any arbitrary array of chars.
 *              You must also pass in how many of those chars to create the
 *              java char array from.
 *
\*===========================================================================*/

jcharArray charptr_to_jcharArray( JNIEnv * env, const char * data, unsigned long size )
{
	jcharArray returnVal = NULL;
	
	/*
	** First, get a run of jchars (double-byte)
	*/
	jchar * chars = charptr_to_jcharptr( env, data, size );
	
	if ( chars )
	{
		/*
		** Make a java char array from them
		*/
		returnVal = jcharptr_to_jcharArray( env, chars, size );
		
		/*
		** Get rid of those chars
		*/
		free( chars );
	}
	
	return returnVal;
}

/*===========================================================================*\
 *
 *	Routine:	jcharptr_to_jcharArray()
 *
 *	Comments:	Converts an arbitrary run of jchars to a java char
 *              array object.
 *
 *              You can pass in a pointer to any arbitrary array of jchars.
 *              You must also pass in how many of those chars to create the
 *              java char array object from.
 *
\*===========================================================================*/

jcharArray jcharptr_to_jcharArray( JNIEnv * env, const jchar * chars, unsigned long size )
{
	/*
	** Do nothing if null.
	*/
	if ( chars == NULL )
	{
		return NULL;
	}
	else
	{
		/*
		** Create the object
		*/
		jcharArray theArray = env->NewCharArray( size );
		
		/*
		** Copy in the contents
		*/
		env->SetCharArrayRegion( theArray, 0, size, chars );
		
		return theArray;
	}
}


/*===========================================================================*\
 *
 *	Routine:	jStringArray_to_charptrptr()
 *
 *	Comments:	Converts a java string array object to a c array of strings.
 *
 *              Also returned is the size of the array.
 *
 *              You CANNOT pass in NULL to the "size" parameter.
 *
\*===========================================================================*/

char ** jStringArray_to_charptrptr( JNIEnv * env, jobjectArray jStringArray, unsigned long * size )
{
	assert( size );
	
	/*
	** Do nothing if null
	*/
	if ( jStringArray == NULL )
	{
		*size = 0;
		return NULL;
	}
	else
	{
		jsize arraySize = env->GetArrayLength( jStringArray );
		
		char ** cStringArray = NULL;
		
		if ( arraySize )
		{
			/*
			** Allocate a length of char *'s
			*/
			cStringArray = (char **)malloc( sizeof(char*) * arraySize );	
			
			int i = 0;
			
			/*
			** Now, for every string in the java string array object,
			** get a corresponding c string and set that entry in our
			** array to that c string.
			*/
			for ( i = 0; i < arraySize; i++ )
			{
				jobject currentjString = env->GetObjectArrayElement( jStringArray, i );
				cStringArray[i] = jstring_to_cstring( env, (jstring)currentjString );
			}
		}
		
		*size = arraySize;
		
		return cStringArray;
	}
	
}


/*===========================================================================*\
 *
 *	Routine:	charptrptrNullEnded_to_jStringArray()
 *
 *	Comments:	Converts a c array of c strings to a java string array object.
 *
 *              The array passed in has to have the last entry set to NULL.
 *
 *              eg:
 *
 *              char ** temp = { "first", "middle", "last", NULL };
 *
\*===========================================================================*/

jobjectArray charptrptrNullEnded_to_jStringArray( JNIEnv * env, const char * const* cArray )
{
	/*
	** Get the length of the c string array
	*/
	int i = 0;
	while ( cArray[i] ) i++;
	
	/*
	** Pass it to the method that expects the length
	*/
	return charptrptr_to_jStringArray( env, cArray, i );
}


/*===========================================================================*\
 *
 *	Routine:	charptrptr_to_jStringArray()
 *
 *	Comments:	Converts a c array of c strings to a java string array object.
 *
 *              You must also pass in the number of entries in the string
 *              array.
 *
 *              NOTE: If it is an array with the last entry set to NULL,
 *              use charptrptrNullEnded_to_jStringArray().
 *
\*===========================================================================*/

jobjectArray charptrptr_to_jStringArray( JNIEnv * env, const char * const* cArray, unsigned long size )
{
	/*
	** Do nothing if null
	*/
	if ( cArray == NULL )
	{
		return NULL;
	}
	else
	{
		int i = 0;
		
		/*
		** Make a java array object that holds strings
		*/
		jobjectArray stringArray = env->NewObjectArray( size, getStringClass( env ), NULL );
		
		/*
		** Copy them in
		*/
		for ( i = 0; i < size; i++)
		{
			env->SetObjectArrayElement( stringArray, i, cstring_to_jstring( env, cArray[i] ) );
		}
		
		return stringArray;
	}
	
}


/*===========================================================================*\
 *
 *	Routine:	charptr_to_jcharptr()
 *
 *	Comments:	Converts an arbitrary run of chars to a run of java chars
 *              (double-byte) of the same length.
 *
 *              You can pass in a pointer to any arbitrary array of chars.
 *              You must also pass in how many of those chars to create the
 *              java chars from.
 *
 *              The caller must dispose of the memory returned by this method.
 *
\*===========================================================================*/

jchar * charptr_to_jcharptr( JNIEnv * env, const char * data, unsigned long size )
{
	jstring javaString = NULL;
	jchar * sourceChars = NULL;
	jchar * destChars = NULL;
	
	/*
	** First, make a java string from the data
	*/
	javaString = cstring_to_jstring2( env, data, size );
	if ( !javaString ) goto bail;
	
	jboolean isCopy = JNI_FALSE;
	
	/*
	** Next, get the chars from the java string. They have now been
	** converted to double-byte format.
	*/
	sourceChars = env->GetStringChars( javaString, &isCopy );
	if ( !sourceChars ) goto bail;
	
	/*
	** Allocate our buffer
	*/
	destChars = (jchar *)malloc( size * sizeof(jchar) );
	if ( !destChars ) goto bail;
	
	/*
	** Copy them into our buffer
	*/
	memcpy( destChars, sourceChars, size * sizeof(jchar) );
	
bail:
	if ( sourceChars )
	{
		env->ReleaseStringChars( javaString, sourceChars );
	}
	
	if ( javaString )
	{
		env->DeleteLocalRef( javaString );
	}
	
	return destChars;
}
