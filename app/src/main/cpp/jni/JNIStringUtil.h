
#ifndef __jnistringutil_h__
#define __jnistringutil_h__

#include <jni.h>

char * jstring_to_cstring( JNIEnv * env, jstring string );
jstring cstring_to_jstring2( JNIEnv * env, const char * string, unsigned long length );
jstring cstring_to_jstring( JNIEnv * env, const char * string );
jcharArray charptr_to_jcharArray( JNIEnv * env, const char * data, unsigned long size );
jbyteArray voidptr_to_jbyteArray( JNIEnv * env, const void * bytes, unsigned long size );
jintArray intArray_to_jintArray( JNIEnv * env, const long * ints, unsigned long size );
jchar * charptr_to_jcharptr( JNIEnv * env, const char * bytes, unsigned long size );
jcharArray jcharptr_to_jcharArray( JNIEnv * env, const jchar * chars, unsigned long size );
char ** jStringArray_to_charptrptr( JNIEnv * env, jobjectArray jStringArray, unsigned long * size );
jobjectArray charptrptr_to_jStringArray( JNIEnv * env, const char * const* cArray, unsigned long size );
jobjectArray charptrptrNullEnded_to_jStringArray( JNIEnv * env, const char * const* cArray );
jchar cchar_to_jchar( JNIEnv * env, char c );

#endif /* #ifndef __jnistringutil_h__ */
