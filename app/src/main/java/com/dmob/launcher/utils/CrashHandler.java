package com.dmob.launcher.utils;

import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import android.os.Build;
import android.util.Log;

import androidx.core.app.NotificationCompat;

import com.dmob.cr.R;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

public class CrashHandler implements Thread.UncaughtExceptionHandler {
    private static final String TAG = "CrashHandler";
    private static final String CHANNEL_ID = "crash_notifications";
    private static final int NOTIFICATION_ID = 9999;
    
    private Context context;
    private Thread.UncaughtExceptionHandler defaultHandler;
    
    public CrashHandler(Context context) {
        this.context = context;
        this.defaultHandler = Thread.getDefaultUncaughtExceptionHandler();
        createNotificationChannel();
    }
    
    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            NotificationChannel channel = new NotificationChannel(
                    CHANNEL_ID,
                    "Crash Notifications",
                    NotificationManager.IMPORTANCE_HIGH
            );
            channel.setDescription("Notifications about app crashes");
            
            NotificationManager notificationManager = 
                    context.getSystemService(NotificationManager.class);
            if (notificationManager != null) {
                notificationManager.createNotificationChannel(channel);
            }
        }
    }
    
    @Override
    public void uncaughtException(Thread thread, Throwable throwable) {
        try {
            String crashLog = getCrashLog(thread, throwable);
            saveCrashLog(crashLog);
            showCrashNotification(crashLog);
            
            Log.e(TAG, "App crashed: " + crashLog);
        } catch (Exception e) {
            Log.e(TAG, "Error in crash handler: " + e.getMessage(), e);
        }
        
        // Вызываем стандартный обработчик
        if (defaultHandler != null) {
            defaultHandler.uncaughtException(thread, throwable);
        }
    }
    
    private String getCrashLog(Thread thread, Throwable throwable) {
        StringWriter sw = new StringWriter();
        PrintWriter pw = new PrintWriter(sw);
        
        pw.println("=== CRASH LOG ===");
        pw.println("Time: " + new SimpleDateFormat("yyyy-MM-dd HH:mm:ss", Locale.getDefault()).format(new Date()));
        pw.println("Thread: " + thread.getName());
        pw.println("Exception: " + throwable.getClass().getSimpleName());
        pw.println("Message: " + throwable.getMessage());
        pw.println("\nStack trace:");
        throwable.printStackTrace(pw);
        
        // Добавляем информацию о причине
        Throwable cause = throwable.getCause();
        if (cause != null) {
            pw.println("\nCaused by:");
            cause.printStackTrace(pw);
        }
        
        pw.close();
        return sw.toString();
    }
    
    private void saveCrashLog(String crashLog) {
        try {
            String crashDir = context.getExternalFilesDir(null) + "/crashes";
            File dir = new File(crashDir);
            if (!dir.exists()) {
                dir.mkdirs();
            }
            
            String timestamp = new SimpleDateFormat("yyyy-MM-dd_HH-mm-ss", Locale.getDefault()).format(new Date());
            File crashFile = new File(dir, "crash_" + timestamp + ".log");
            
            FileWriter writer = new FileWriter(crashFile);
            writer.write(crashLog);
            writer.close();
            
            Log.i(TAG, "Crash log saved to: " + crashFile.getAbsolutePath());
        } catch (IOException e) {
            Log.e(TAG, "Error saving crash log: " + e.getMessage(), e);
        }
    }
    
    private void showCrashNotification(String crashLog) {
        try {
            // Берем первые 200 символов для уведомления
            String shortMessage = crashLog.length() > 200 ? 
                    crashLog.substring(0, 200) + "..." : crashLog;
            
            // Извлекаем основную информацию об ошибке
            String[] lines = crashLog.split("\n");
            String exceptionInfo = "";
            for (String line : lines) {
                if (line.contains("Exception:") || line.contains("Message:")) {
                    exceptionInfo += line + "\n";
                }
            }
            
            NotificationCompat.Builder builder = new NotificationCompat.Builder(context, CHANNEL_ID)
                    .setSmallIcon(R.drawable.ic_baseline_notifications_24)
                    .setContentTitle("App Crashed")
                    .setContentText(exceptionInfo.isEmpty() ? "Unknown error" : exceptionInfo)
                    .setStyle(new NotificationCompat.BigTextStyle()
                            .bigText(shortMessage))
                    .setPriority(NotificationCompat.PRIORITY_HIGH)
                    .setAutoCancel(true);
            
            NotificationManager notificationManager = 
                    (NotificationManager) context.getSystemService(Context.NOTIFICATION_SERVICE);
            if (notificationManager != null) {
                notificationManager.notify(NOTIFICATION_ID, builder.build());
            }
        } catch (Exception e) {
            Log.e(TAG, "Error showing crash notification: " + e.getMessage(), e);
        }
    }
}
