package com.dmob.launcher.activity;

import android.graphics.Bitmap;

/**
 * Класс для временного хранения изображения истории.
 * Используется вместо передачи Bitmap через Intent, так как большие изображения
 * могут вызвать исключение при сериализации.
 */
public class StoriesImageCache {
    public static Bitmap bitmap;
} 