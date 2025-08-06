package com.dmob.launcher.network;

import android.util.Log;
import com.dmob.launcher.utils.LogHelper;
import java.net.HttpURLConnection;
import java.net.URL;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.IOException;
import java.io.File;

public class HTMLFileDownloader {
    private static final String TAG = LogHelper.TAG_NETWORK;
    
    public static int startDownload(String urlFrom, String pathTo) {
        LogHelper.i(TAG, "Начало загрузки файла: " + urlFrom + " -> " + pathTo);
        long startTime = System.currentTimeMillis();
        
        try {
            URL url = new URL(urlFrom);
            HttpURLConnection httpConn = (HttpURLConnection) url.openConnection();
            httpConn.setRequestProperty("User-Agent", "BR-RP App Downloader");
            httpConn.setConnectTimeout(30000); // 30 секунд на подключение
            httpConn.setReadTimeout(30000);    // 30 секунд на чтение
            LogHelper.d(TAG, "Установка соединения с " + urlFrom);
            
            httpConn.connect();
            int responseCode = httpConn.getResponseCode();
            String responseMessage = httpConn.getResponseMessage();
            
            LogHelper.i(TAG, "Ответ сервера: " + responseCode + " " + responseMessage);

            if (responseCode == HttpURLConnection.HTTP_OK) {
                int contentLength = httpConn.getContentLength();
                String contentType = httpConn.getContentType();
                
                LogHelper.i(TAG, "Начинаем загрузку файла. Размер: " + 
                      (contentLength > 0 ? contentLength + " байт" : "неизвестен") + 
                      ", тип: " + (contentType != null ? contentType : "неизвестен"));
                
                File file = new File(pathTo);
                if (file.exists()) {
                    LogHelper.d(TAG, "Файл уже существует, удаляем: " + pathTo);
                    file.delete();
                }
                
                file.getParentFile().mkdirs();
                file.createNewFile();
                LogHelper.d(TAG, "Создан новый файл: " + pathTo);

                InputStream inputStream = httpConn.getInputStream();
                FileOutputStream outputStream = new FileOutputStream(pathTo);

                byte[] buffer = new byte[4096];
                int bytesRead = -1;
                long totalBytesRead = 0;
                long lastLogTime = System.currentTimeMillis();

                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                    totalBytesRead += bytesRead;
                    
                    // Логируем прогресс каждые 500 мс (для больших файлов)
                    long currentTime = System.currentTimeMillis();
                    if (currentTime - lastLogTime > 500 && contentLength > 0) {
                        int progress = (int)((totalBytesRead * 100) / contentLength);
                        LogHelper.d(TAG, "Прогресс загрузки: " + progress + "% (" + 
                               totalBytesRead + "/" + contentLength + " байт)");
                        lastLogTime = currentTime;
                    }
                }
                
                outputStream.close();
                inputStream.close();
                
                long endTime = System.currentTimeMillis();
                float downloadTime = (endTime - startTime) / 1000.0f;
                float downloadSpeed = totalBytesRead / (downloadTime * 1024); // КБ/с
                
                LogHelper.i(TAG, String.format(
                    "Файл успешно загружен. Размер: %d байт, время: %.1f сек, скорость: %.1f КБ/с",
                    totalBytesRead, downloadTime, downloadSpeed));
            } else {
                LogHelper.e(TAG, "Ошибка при загрузке файла. Код ответа: " + responseCode + " " + responseMessage);
            }
            
            httpConn.disconnect();
            return responseCode;
        } catch (IOException ex) {
            LogHelper.e(TAG, "Исключение при загрузке файла: " + ex.getMessage(), ex);
        }
        
        long endTime = System.currentTimeMillis();
        LogHelper.i(TAG, "Загрузка завершена с ошибкой за " + (endTime - startTime) + " мс");
        return -1;
    }
}
