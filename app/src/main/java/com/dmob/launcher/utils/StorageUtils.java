package com.dmob.launcher.utils;

import android.os.Environment;
import android.os.StatFs;
import android.util.Log;

import java.io.File;

public class StorageUtils {
    private static final String TAG = "StorageUtils";
    
    /**
     * Получает свободное место на внешнем хранилище в байтах
     */
    public static long getAvailableSpace() {
        try {
            File externalDir = Environment.getExternalStorageDirectory();
            StatFs stat = new StatFs(externalDir.getPath());
            long availableBlocks = stat.getAvailableBlocks();
            long blockSize = stat.getBlockSize();
            long availableSpace = availableBlocks * blockSize;
            
            Log.i(TAG, "Available space: " + formatBytes(availableSpace));
            return availableSpace;
        } catch (Exception e) {
            Log.e(TAG, "Error getting available space: " + e.getMessage(), e);
            return 0;
        }
    }
    
    /**
     * Получает общее место на внешнем хранилище в байтах
     */
    public static long getTotalSpace() {
        try {
            File externalDir = Environment.getExternalStorageDirectory();
            StatFs stat = new StatFs(externalDir.getPath());
            long totalBlocks = stat.getBlockCount();
            long blockSize = stat.getBlockSize();
            long totalSpace = totalBlocks * blockSize;
            
            Log.i(TAG, "Total space: " + formatBytes(totalSpace));
            return totalSpace;
        } catch (Exception e) {
            Log.e(TAG, "Error getting total space: " + e.getMessage(), e);
            return 0;
        }
    }
    
    /**
     * Проверяет достаточно ли места для загрузки файлов
     * @param requiredSpace требуемое место в байтах
     * @return true если места достаточно, false если нет
     */
    public static boolean hasEnoughSpace(long requiredSpace) {
        long availableSpace = getAvailableSpace();
        boolean hasSpace = availableSpace >= requiredSpace;
        
        Log.i(TAG, "Required: " + formatBytes(requiredSpace) + 
              ", Available: " + formatBytes(availableSpace) + 
              ", Has enough: " + hasSpace);
        
        return hasSpace;
    }
    
    /**
     * Получает сколько места нужно освободить
     * @param requiredSpace требуемое место в байтах
     * @return место которое нужно освободить в байтах, или 0 если места достаточно
     */
    public static long getSpaceToFree(long requiredSpace) {
        long availableSpace = getAvailableSpace();
        
        if (availableSpace >= requiredSpace) {
            return 0;
        }
        
        long spaceToFree = requiredSpace - availableSpace;
        Log.i(TAG, "Space to free: " + formatBytes(spaceToFree));
        
        return spaceToFree;
    }
    
    /**
     * Форматирует размер в байтах в читаемый формат
     */
    public static String formatBytes(long bytes) {
        if (bytes <= 0) return "0 B";
        
        final String[] units = new String[]{"B", "KB", "MB", "GB", "TB"};
        int digitGroups = (int) (Math.log10(bytes) / Math.log10(1024));
        
        return String.format("%.2f %s", bytes / Math.pow(1024, digitGroups), units[digitGroups]);
    }
}
