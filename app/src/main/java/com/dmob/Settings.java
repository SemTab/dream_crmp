package com.dmob;

import android.os.Environment;

public class Settings {
    public static String privacyLink = "dg.bdsrvs.run";

    public static String PR_NAME = "DREAM MOBILE";

    public static final String path_cache = Environment.getExternalStorageDirectory() + "/Dream/";
    public static final String path_settings = path_cache + "SAMP/settings.ini";

    public static String URL_WEB = "https://dmobile.icu";
    public static String URL_DONATE = "https://dmobile.icu/donate";
    public static String URL_VK = "https://vk.com/dreammobile.online";
    public static String URL_TG = "https://t.me/dream_bonus";
    public static String URL_FORUM = "https://forum.dmobile.icu";
    public static String URL_SUPPORT = "https://dmobile.icu";

    // public static String URL_FILES = "https://weikton.ru/cache.zip";
    // public static String DOWNLOAD_FILENAME = "cache.zip";

    public static final String GAME_PATH = Environment.getExternalStorageDirectory() + "/Dream"; // путь к игре
    public static final String GAME_URL = "https://cdn.bdsrvs.run/brp/files";
    public static final String GAME_URL_2 = "https://cdn.bdsrvs.run/brp/api.json";
    
    // Настройка проверки файлов
    public static final String SKIP_FILES_CHECK = "skip_files_check"; // Ключ для настройки в INI файле
}
