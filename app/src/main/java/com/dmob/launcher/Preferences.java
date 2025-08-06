package com.dmob.launcher;

import android.content.Context;
import android.content.SharedPreferences;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Preferences {
    private static final String NAME = "preferences";
    public static final String EMAIL = "EMAIL";
    public static final String FILES = "FILES";
    public static final String NICKNAME = "NICKNAME";
    public static final String NOTIFICATION = "NOTIFICATION";
    public static final String GRAPHICS = "GRAPHICS";
    public static final String VOICECHAT = "VOICE_CHAT";
    public static final String FIRST_START = "FIRST_START";
    public static String USER_FCM_KEY = "USER_FCM_REG_KEY";

    public static <T> void putObject(Context context, String str, T t) {
        SharedPreferences.Editor edit = context.getSharedPreferences(NAME, 0).edit();
        edit.putString(str, new Gson().toJson((Object) t));
        edit.apply();
    }

    public static <T> T getObject(Context context, String str, Class<T> cls) {
        SharedPreferences sharedPreferences = context.getSharedPreferences(NAME, 0);
        if (sharedPreferences.contains(str)) {
            return new Gson().fromJson(sharedPreferences.getString(str, ""), cls);
        }
        return null;
    }

    public static <T> void putList(Context context, String str, ArrayList<T> arrayList) {
        SharedPreferences.Editor edit = context.getSharedPreferences(NAME, 0).edit();
        edit.putString(str, new Gson().toJson((Object) arrayList));
        edit.apply();
    }


    public static void putFilesData(Context context, String str, HashMap<String, String> hashMap) {
        SharedPreferences.Editor edit = context.getSharedPreferences(NAME, 0).edit();
        edit.putString(str, new GsonBuilder().enableComplexMapKeySerialization().setPrettyPrinting().create().toJson((Object) hashMap, new TypeToken<HashMap<String, String>>() {
        }.getType()));
        edit.apply();
    }

    public static HashMap<String, String> restoreFilesData(Context context, String str) {
        HashMap<String, String> hashMap = new HashMap<>();
        SharedPreferences sharedPreferences = context.getSharedPreferences(NAME, 0);
        if (sharedPreferences.contains(str)) {
            hashMap.putAll((Map) new Gson().fromJson(sharedPreferences.getString(str, ""), new TypeToken<HashMap<String, String>>() {
            }.getType()));
        }
        return hashMap;
    }

    public static void putString(Context context, String str, String str2) {
        SharedPreferences.Editor edit = context.getSharedPreferences(NAME, 0).edit();
        edit.putString(str, str2);
        edit.apply();
    }

    public static String getString(Context context, String str) {
        return context.getSharedPreferences(NAME, 0).getString(str, "");
    }

    public static String getString(Context context, String str, String str2) {
        return context.getSharedPreferences(NAME, 0).getString(str, str2);
    }

    public static void putBoolean(Context context, String str, boolean z) {
        SharedPreferences.Editor edit = context.getSharedPreferences(NAME, 0).edit();
        edit.putBoolean(str, z);
        edit.apply();
    }

    public static boolean getBoolean(Context context, String str) {
        return context.getSharedPreferences(NAME, 0).getBoolean(str, false);
    }

    public static boolean getBoolean(Context context, String str, boolean z) {
        return context.getSharedPreferences(NAME, 0).getBoolean(str, z);
    }

    public static void clear(Context context, String str) {
        context.getSharedPreferences(NAME, 0).edit().remove(str).apply();
    }

    public static boolean existKey(Context context, String str) {
        return context.getSharedPreferences(NAME, 0).contains(str);
    }
}
