package com.dmob.cr;

import android.app.Application;
import com.dmob.launcher.utils.CrashHandler;

public class DreamApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        
        // Устанавливаем обработчик для перехвата краша
        Thread.setDefaultUncaughtExceptionHandler(new CrashHandler(this));
    }
}
