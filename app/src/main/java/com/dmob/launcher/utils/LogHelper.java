package com.dmob.launcher.utils;

import android.content.Context;
import android.os.Environment;
import android.util.Log;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

/**
 * Вспомогательный класс для логирования в приложении
 * Позволяет как выводить логи в LogCat, так и сохранять их в файл
 */
public class LogHelper {
    // Тэги для разных модулей
    public static final String TAG_API = "BR-RP-API";
    public static final String TAG_MAIN = "BR-RP";
    public static final String TAG_NETWORK = "BR-RP-NETWORK";
    
    // Включить сохранение логов в файл
    private static final boolean SAVE_TO_FILE = false;
    
    // Директория для сохранения логов
    private static String logDir = null;
    private static final SimpleDateFormat DATE_FORMAT = new SimpleDateFormat("yyyy-MM-dd_HH-mm-ss", Locale.getDefault());
    private static final SimpleDateFormat LOG_TIME_FORMAT = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS", Locale.getDefault());
    
    // Имя файла для логов
    private static String logFileName = null;
    
    /**
     * Инициализирует логгер
     * @param context контекст приложения
     */
    public static void init(Context context) {
        if (SAVE_TO_FILE) {
            try {
                // Создаем директорию для логов
                File externalDir = context.getExternalFilesDir(null);
                if (externalDir != null) {
                    logDir = externalDir.getAbsolutePath() + "/logs";
                    File logDirFile = new File(logDir);
                    if (!logDirFile.exists()) {
                        logDirFile.mkdirs();
                    }
                    
                    // Создаем новый лог-файл с текущей датой
                    logFileName = logDir + "/brp_log_" + DATE_FORMAT.format(new Date()) + ".txt";
                    
                    // Записываем заголовок в лог-файл
                    try (BufferedWriter writer = new BufferedWriter(new FileWriter(logFileName, true))) {
                        writer.write("======== BR-RP LOG START ========\n");
                        writer.write("Date: " + LOG_TIME_FORMAT.format(new Date()) + "\n");
                        writer.write("=============================\n\n");
                    }
                    
                    Log.i(TAG_MAIN, "Логирование в файл активировано: " + logFileName);
                } else {
                    Log.e(TAG_MAIN, "Не удалось получить директорию для логов");
                }
            } catch (Exception e) {
                Log.e(TAG_MAIN, "Ошибка при инициализации логирования: " + e.getMessage(), e);
            }
        }
    }
    
    /**
     * Записывает информационное сообщение в лог
     * @param tag тег для группировки логов
     * @param message сообщение для записи
     */
    public static void i(String tag, String message) {
        Log.i(tag, message);
        writeToFile("I", tag, message);
    }
    
    /**
     * Записывает отладочное сообщение в лог
     * @param tag тег для группировки логов
     * @param message сообщение для записи
     */
    public static void d(String tag, String message) {
        Log.d(tag, message);
        writeToFile("D", tag, message);
    }
    
    /**
     * Записывает предупреждение в лог
     * @param tag тег для группировки логов
     * @param message сообщение для записи
     */
    public static void w(String tag, String message) {
        Log.w(tag, message);
        writeToFile("W", tag, message);
    }
    
    /**
     * Записывает ошибку в лог
     * @param tag тег для группировки логов
     * @param message сообщение для записи
     */
    public static void e(String tag, String message) {
        Log.e(tag, message);
        writeToFile("E", tag, message);
    }
    
    /**
     * Записывает ошибку в лог с указанием исключения
     * @param tag тег для группировки логов
     * @param message сообщение для записи
     * @param throwable исключение
     */
    public static void e(String tag, String message, Throwable throwable) {
        Log.e(tag, message, throwable);
        writeToFile("E", tag, message + "\nException: " + throwable.toString());
        
        // Записываем стек вызовов
        StackTraceElement[] stackTrace = throwable.getStackTrace();
        StringBuilder stackTraceStr = new StringBuilder();
        for (StackTraceElement element : stackTrace) {
            stackTraceStr.append("    at ").append(element.toString()).append("\n");
        }
        writeToFile("E", tag, stackTraceStr.toString());
    }
    
    /**
     * Записывает информацию о JSON-ответе в лог
     * @param tag тег для группировки логов
     * @param url URL запроса
     * @param responseCode код ответа
     * @param responseBody тело ответа
     */
    public static void logJsonResponse(String tag, String url, int responseCode, String responseBody) {
        String message = "JSON Response from " + url + 
                "\nCode: " + responseCode + 
                "\nBody: " + (responseBody != null ? responseBody : "null");
        
        if (responseCode >= 200 && responseCode < 300) {
            i(tag, message);
        } else {
            e(tag, message);
        }
    }
    
    /**
     * Записывает сообщение в лог-файл
     * @param level уровень лога (I, D, W, E)
     * @param tag тег для группировки логов
     * @param message сообщение для записи
     */
    private static void writeToFile(String level, String tag, String message) {
        if (!SAVE_TO_FILE || logFileName == null) {
            return;
        }
        
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(logFileName, true))) {
            writer.write(LOG_TIME_FORMAT.format(new Date()));
            writer.write(" " + level + "/" + tag + ": " + message + "\n");
        } catch (IOException e) {
            Log.e(TAG_MAIN, "Ошибка при записи в лог-файл: " + e.getMessage());
        }
    }
    
    /**
     * Добавляет разделитель в лог-файл
     * @param tag тег для группировки логов
     * @param title заголовок разделителя
     */
    public static void addSeparator(String tag, String title) {
        String separator = "==== " + title + " ====";
        i(tag, separator);
    }
} 