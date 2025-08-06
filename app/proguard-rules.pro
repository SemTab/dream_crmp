# new security for all sources by Weikton

-keep class com.nvidia.** {*;}
-keep class com.wardrumstudios.** {*;}
-keepclassmembers  class com.nvidia.** {*;}
-keepclassmembers  class com.wardrumstudios.** {*;}
-keepclasseswithmembernames class * {
     native <methods>;
 }

-keepattributes SourceFile
-keepattributes SourceFile
-renamesourcefileattribute SourceFile

-keepattributes SourceFile, LineNumberTable

-keep public class * extends android.view.View {
    public <init>(android.content.Context);
    public <init>(android.content.Context, android.util.AttributeSet);
    public <init>(android.content.Context, android.util.AttributeSet, int);
}

-keep class * implements android.os.Parcelable {
    public static final android.os.Parcelable$Creator *;
}

-keep public class * extends android.app.Activity
-keep public class * extends android.app.Application
-keep public class * extends android.app.Service
-keep public class * extends android.content.BroadcastReceiver
-keep public class * extends android.content.ContentProvider
-keep public class * extends android.app.backup.BackupAgentHelper
-keep public class * extends android.preference.Preference
-keep public class com.android.vending.licensing.ILicensingService

-keepattributes *Annotation*

-keep class com.google.gson.** { *; }
-keep interface com.google.gson.** { *; }
-keepattributes Signature

-dontwarn retrofit2.**
-keep class retrofit2.** { *; }
-keepattributes Signature
-keepattributes Exceptions
-keepattributes RuntimeVisibleAnnotations
-keepattributes RuntimeInvisibleAnnotations
-keepattributes RuntimeVisibleParameterAnnotations
-keepattributes RuntimeInvisibleParameterAnnotations

-dontwarn okhttp3.**
-keep class okhttp3.** { *; }
-keep interface okhttp3.** { *; }

-dontwarn rx.**
-keep class rx.** { *; }
-keep interface rx.** { *; }

-keepclassmembers class * {
    @javax.inject.Inject <fields>;
    @javax.inject.Inject <init>(...);
}


-keepattributes SourceFile,LineNumberTable

-keep public class * extends android.view.View {
    public <init>(android.content.Context);
    public <init>(android.content.Context, android.util.AttributeSet);
    public <init>(android.content.Context, android.util.AttributeSet, int);
}

-keep class * implements android.os.Parcelable {
    public static final android.os.Parcelable$Creator *;
}

#-keepclassmembers class **.R$* {
#    public static <fields>;
#}

-keep public class * extends android.app.Activity
-keep public class * extends android.app.Application
-keep public class * extends android.app.Service
-keep public class * extends android.content.BroadcastReceiver
-keep public class * extends android.content.ContentProvider
-keep public class * extends android.app.backup.BackupAgentHelper
-keep public class * extends android.preference.Preference
-keep public class com.android.vending.licensing.ILicensingService

-keepattributes *Annotation*

-keep class com.google.gson.** { *; }
-keep interface com.google.gson.** { *; }
-keepattributes Signature

-dontwarn retrofit2.**
-keep class retrofit2.** { *; }
-keepattributes Signature
-keepattributes Exceptions
-keepattributes RuntimeVisibleAnnotations
-keepattributes RuntimeInvisibleAnnotations
-keepattributes RuntimeVisibleParameterAnnotations
-keepattributes RuntimeInvisibleParameterAnnotations

-dontwarn okhttp3.**
-keep class okhttp3.** { *; }
-keep interface okhttp3.** { *; }

-dontwarn rx.**
-keep class rx.** { *; }
-keep interface rx.** { *; }

-keepclassmembers class * {
    @javax.inject.Inject <fields>;
    @javax.inject.Inject <init>(...);
}