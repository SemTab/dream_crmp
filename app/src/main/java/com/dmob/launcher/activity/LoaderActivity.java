package com.dmob.launcher.activity;
import static com.dmob.Settings.GAME_PATH;
import static com.dmob.Settings.GAME_URL;
import static com.dmob.Settings.GAME_URL_2;
import static com.dmob.Settings.SKIP_FILES_CHECK;

import android.Manifest;
import android.animation.AnimatorInflater;
import android.animation.AnimatorSet;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.view.WindowManager;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.security.MessageDigest;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.HashMap;

import java.io.FileNotFoundException;
import java.net.MalformedURLException;
import java.net.SocketTimeoutException;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import androidx.core.app.NotificationManagerCompat;
import androidx.viewpager2.widget.ViewPager2;

import com.dmob.cr.R;
import com.dmob.cr.core.GTASA;
import com.dmob.launcher.network.FileCheckSumSHA;
import com.dmob.launcher.network.HTMLFileDownloader;
import com.dmob.launcher.network.Interface;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

import org.ini4j.Wini;

import com.dmob.Settings;

public class LoaderActivity extends AppCompatActivity {
    private TextView loadingInfo;
    private ProgressBar progressLoading, progressLoadingCancel;
    private TextView percentsCommonInfo;
    private TextView downloadSizeSpeedInfo;
    private Handler handler;
    private TextView repeatButton;

    private static final int GAME_NOTIFICATION_ID = 2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_load);
        initialize(savedInstanceState);

        handler = new Handler();
        
   //     // Анимация для эффекта свечения логотипа
   //     View logoGlowLoad = findViewById(R.id.logoGlowLoad);
   //     AnimatorSet pulseAnimation = (AnimatorSet) AnimatorInflater.loadAnimator(this, R.anim.logo_pulse);
   //     pulseAnimation.setTarget(logoGlowLoad);
   //     pulseAnimation.start();

        // чтобы экран не тух
        this.getWindow().clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        if (Build.VERSION.SDK_INT >= 23 &&
                (checkSelfPermission(Manifest.permission.READ_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED ||
                        checkSelfPermission(Manifest.permission.WRITE_EXTERNAL_STORAGE) == PackageManager.PERMISSION_DENIED)) {

            requestPermissions(new String[] {
                    Manifest.permission.READ_EXTERNAL_STORAGE,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE}, 1000);
        } else {
            InstallGame();
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == 1000) {
            InstallGame();
        }
    }

    public static void writeFile(String path, String str) {
        File file = new File(path);

        try {
            if (!file.exists())
                file.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
        FileWriter fileWriter = null;

        try {
            fileWriter = new FileWriter(new File(path), false);
            fileWriter.write(str);
            fileWriter.flush();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (fileWriter != null)
                    fileWriter.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void ReloadApp()
    {
        startActivity(new Intent(getApplicationContext(), MainActivity.class));
        finish();
    }

    private final HashMap<String, String> controlHashesList = new HashMap<>();
    private final HashMap<String, Long> fileSizesList = new HashMap<>();

    private File checkFile;
    private InitControlHashesTask loadHashesTask = null;
    private DownloadFilesTask downloadTask = null;

    private class InitControlHashesTask extends AsyncTask<String, Void, Integer> {
        @Override
        protected Integer doInBackground(String... params) {
            String dirPath = params[0];
            File dirFile = new File(dirPath);
            if (!dirFile.exists() || !dirFile.isDirectory())
                dirFile.mkdirs();

            String checkFilePath = dirPath + "/api.json";
            Log.i("BR-RP-API", "Путь к api.json: " + checkFilePath);
            
            checkFile = new File(checkFilePath);
            if (checkFile.exists()) {
                Log.i("BR-RP-API", "Существующий файл api.json найден, удаляем для обновления");
                boolean isDeleted = checkFile.delete();
                if (!isDeleted) {
                    Log.e("BR-RP-API", "Не удалось удалить существующий файл хешей: " + checkFilePath);
                } else {
                    Log.i("BR-RP-API", "Существующий файл api.json успешно удален");
                }
            }

            Log.i("BR-RP-API", "Начинаем загрузку api.json с URL: " + GAME_URL_2);
            int httpResult = HTMLFileDownloader.startDownload(GAME_URL_2, checkFilePath);
            Log.i("BR-RP-API", "Результат загрузки api.json: " + httpResult);
            
            if (httpResult == HttpURLConnection.HTTP_OK) {
                Log.i("BR-RP-API", "Файл api.json успешно загружен");
            

                Log.i("BR-RP-API", "Начинаем парсинг api.json");
                JSONParser parser = new JSONParser();
                try {
                    Log.d("BR-RP-API", "Чтение файла: " + dirPath + "/api.json");
                    Object obj = parser.parse(new FileReader(dirPath + "/api.json"));
                    Log.i("BR-RP-API", "Файл api.json успешно прочитан и распарсен");

                    try {
                        Log.d("BR-RP-API", "Пытаемся парсить как JSONObject");
                        JSONObject jsonObject = (JSONObject) obj;

                        int allCount = jsonObject.keySet().size();
                        Log.i("BR-RP-API", "Найдено " + allCount + " файлов для проверки/загрузки в формате JSONObject");
                        int counter = 0;

                        for (Object key : jsonObject.keySet()) {
                            if (isCancelled()) {
                                Log.i("BR-RP-API", "Парсинг api.json отменен пользователем");
                                return 0;
                            }
                            counter++;

                            JSONArray jsonArray = (JSONArray) jsonObject.get(key);
                            String fileName = (String) key;
                            String fileHash = (String) jsonArray.get(0);
                            Long fileSize = (Long) jsonArray.get(1);
                            
                            Log.d("BR-RP-API", String.format("Файл %d/%d: %s, хеш: %s, размер: %d байт", 
                                counter, allCount, fileName, fileHash, fileSize));

                            controlHashesList.put(fileName, fileHash);
                            fileSizesList.put(fileName, fileSize);

                            int progress = (int) ((float) counter / allCount * 100f);
                            runOnUiThread(() -> {
                                loadingInfo.setText("Подготовка...");
                                percentsCommonInfo.setText(progress + "%");
                                progressLoading.setProgress(progress);
                            });
                        }
                        
                        Log.i("BR-RP-API", "Парсинг api.json успешно завершен, обработано " + counter + " файлов");
                        return 1;
                    } catch (ClassCastException e) {
                        // Попробуем парсить как JSONArray
                        Log.i("BR-RP-API", "Формат JSONObject не подошел, пробуем парсить как JSONArray: " + e.getMessage());
                        try {
                            JSONArray jsonArray = (JSONArray) obj;
                            int allCount = jsonArray.size();
                            Log.i("BR-RP-API", "Найдено " + allCount + " файлов для проверки/загрузки в формате JSONArray");
                            int counter = 0;
                            
                            for (Object item : jsonArray) {
                                if (isCancelled()) {
                                    Log.i("BR-RP-API", "Парсинг api.json отменен пользователем");
                                    return 0;
                                }
                                counter++;
                                
                                JSONObject jsonItem = (JSONObject) item;
                                String fileName = (String) jsonItem.get("file");
                                String fileHash = (String) jsonItem.get("hash");
                                Long fileSize = (Long) jsonItem.get("size");
                                
                                Log.d("BR-RP-API", String.format("Файл %d/%d: %s, хеш: %s, размер: %d байт", 
                                    counter, allCount, fileName, fileHash, fileSize));
                                
                                controlHashesList.put(fileName, fileHash);
                                fileSizesList.put(fileName, fileSize);
                                
                                int progress = (int) ((float) counter / allCount * 100f);
                                runOnUiThread(() -> {
                                    loadingInfo.setText("Подготовка...");
                                    percentsCommonInfo.setText(progress + "%");
                                    progressLoading.setProgress(progress);
                                });
                            }
                            
                            Log.i("BR-RP-API", "Парсинг api.json успешно завершен, обработано " + counter + " файлов");
                            return 1;
                        } catch (Exception ex) {
                            Log.e("BR-RP-API", "Ошибка загрузки контрольных хешей (JSONArray): " + ex.getMessage(), ex);
                            return 0;
                        }
                    }
                }
                catch (Exception e) {
                    Log.e("BR-RP-API", "Ошибка загрузки контрольных хешей: " + e.getMessage(), e);
                }
            }
            return 1;
        }

        @Override
        protected void onPostExecute(Integer result) {
            super.onPostExecute(result);
            loadHashesTask = null;

            if (result == 0) {
                showMessage("Загрузка прервана");
                progressLoading.setVisibility(View.INVISIBLE);
                progressLoadingCancel.setVisibility(View.VISIBLE);
            } else {
                downloadTask = new DownloadFilesTask();
                downloadTask.execute(new File(GAME_PATH));
            }
        }

        @Override
        protected void onCancelled() {
            if (checkFile.exists())
                checkFile.delete();

            loadHashesTask = null;
            progressLoading.setVisibility(View.INVISIBLE);
            progressLoadingCancel.setVisibility(View.VISIBLE);
            super.onCancelled();
        }
    }

    private class DownloadFilesTask extends AsyncTask<File, Void, Integer> {

        private int allCount = 0;
        private int loadingCount = 0;
        private int counter = 0;
        @Override
        protected Integer doInBackground(File... params) {
            File directory = params[0];
            String dirPath = directory.getPath();
            try {
                MessageDigest md = MessageDigest.getInstance("SHA-256");
                int count_in_keyset = controlHashesList.keySet().size();
                long totalSizeOfFiles = 0L;

                // Сбрасываем счетчики перед началом загрузки
                speedQueue.clear();
                sumSpeed = 0;
                allBytesDownloaded = 0;
                
                runOnUiThread(() -> {
                    downloadSizeSpeedInfo.setText("0.0 МБ из 0.0 МБ");
                });

                Iterator<String> iterator = controlHashesList.keySet().iterator();
                while (iterator.hasNext()) {

                    if (isCancelled())
                        return 0;

                    ConnectivityManager connectivityManager = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
                    NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();
                    if (networkInfo == null || !networkInfo.isConnected())
                        return 0;

                    allCount++;
                    String key = iterator.next();
                    String absoluteFilePath = dirPath + "/" + key;
                    System.out.println("LoadGameCacheFiles CHECK " + absoluteFilePath);

                    String hash = null;
                    if (new File(absoluteFilePath).exists())
                        hash = FileCheckSumSHA.getCheckSum(absoluteFilePath, md);

                    if (hash == null || !hash.equals(controlHashesList.get(key))) {
                        totalSizeOfFiles += fileSizesList.get(key);
                        loadingCount++;
                        System.out.println("LoadGameCacheFiles NEED TO UPD " + absoluteFilePath);
                    }
                    else {
                        iterator.remove();
                    }

                    int progress = (int) ((float) allCount / count_in_keyset * 100);
                    runOnUiThread(() -> {
                        loadingInfo.setText("Проверка... ");
                        percentsCommonInfo.setText(progress + "%");
                        progressLoading.setProgress(progress);
                    });
                }

                if (loadingCount == 0) {
                    return 1;
                }

                percentsCommonInfo.setVisibility(View.VISIBLE);

                runOnUiThread(() -> {
                    loadingInfo.setText("");
                    percentsCommonInfo.setText("0%");
                    progressLoading.setVisibility(View.VISIBLE);
                    progressLoadingCancel.setVisibility(View.INVISIBLE);
                    progressLoading.setProgress(0);
                });

                for (String key : controlHashesList.keySet()) {

                    if (isCancelled())
                        return 0;

                    ConnectivityManager connectivityManager = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
                    NetworkInfo networkInfo = connectivityManager.getActiveNetworkInfo();
                    if (networkInfo == null || !networkInfo.isConnected())
                        return 0;

                    String absoluteFilePath = dirPath + "/" + key;

                    String fileURL = GAME_URL + "/" + key;
                    System.out.println("LoadGameCacheFiles " + absoluteFilePath);
                    System.out.println("LoadGameCacheFiles " + fileURL);

                    if (new File(absoluteFilePath).exists() && (
                            key.equals("gta_sa.set") || key.equals("SAMP/settings.ini") ||
                                    key.equals("gtasatelem.set") ||
                                    key.equals("SAMP/logcat.log") ||
                                    key.equals("SAMP/crash.log") ||
                                    key.equals("Adjustable.cfg"))) {
                        System.out.println("LoadGameCacheFiles Settings loading skipped");
                        continue;
                    }

                    int progress = (int) ((float) counter / loadingCount * 100);

                    if (downloadFileInThread(
                            fileURL,
                            absoluteFilePath,
                            totalSizeOfFiles) == HttpURLConnection.HTTP_OK) {

                        counter++;
                        runOnUiThread(() -> {
                            percentsCommonInfo.setText(progress + "%");
                            progressLoading.setProgress(progress);
                        });
                        System.out.println("LoadGameCacheFiles File downloaded");
                    }
                }
                return 1;
            }
            catch (MalformedURLException ex) {
                System.err.println("/ LoadGameCacheFiles Ошибка при создании URL: " + ex.getMessage());
                ex.printStackTrace();
                return 0;
            } catch (FileNotFoundException ex) {
                System.err.println("/ LoadGameCacheFiles Файл не найден: " + ex.getMessage());
                ex.printStackTrace();
                return 0;
            } catch (SocketTimeoutException ex) {
                System.err.println("/ LoadGameCacheFiles Соединение разорвано: " + ex.getMessage());
                ex.printStackTrace();
                return 0;
            } catch (Exception ex) {
                System.err.println("/ LoadGameCacheFiles Ошибка: " + ex.getMessage());
                ex.printStackTrace();
                return 0;
            }
        }

        @Override
        protected void onPostExecute(Integer result) {
            super.onPostExecute(result);
            if (checkFile.exists())
                checkFile.delete();

            downloadTask = null;
            progressLoading.setVisibility(View.INVISIBLE);
            progressLoadingCancel.setVisibility(View.VISIBLE);

            NotificationManagerCompat notificationManager = NotificationManagerCompat.from(getApplicationContext());
            notificationManager.cancel(GAME_NOTIFICATION_ID);
            
            // Сбрасываем счетчики и информацию о загрузке при завершении
            speedQueue.clear();
            sumSpeed = 0;
            
            // Если загрузка успешна, отображаем общее количество загруженных данных
            if (result == 1) {
                float totalDownloadedMB = allBytesDownloaded / 1024.0f / 1024.0f;
                runOnUiThread(() -> {
                    downloadSizeSpeedInfo.setText(String.format("Всего загружено: %.1f МБ", totalDownloadedMB));
                });
            } else {
                runOnUiThread(() -> {
                    downloadSizeSpeedInfo.setText("Загрузка прервана");
                });
            }

            if (result == 0) {
                System.out.println("/ LoadGameCacheFiles Загрузчик файлов завершил работу, возврат в меню");
                // showMessage("Загрузка была прервана");
                // repeatButton.setVisibility(View.VISIBLE);
            } else {
                System.out.println("/ LoadGameCacheFiles Загрузчик файлов завершил работу, запуск игры");
                startActivity(new Intent(getApplicationContext(), GTASA.class));
                finish();
            }
        }

        @Override
        protected void onCancelled() {
            if (checkFile.exists())
                checkFile.delete();

            downloadTask = null;

            NotificationManagerCompat notificationManager = NotificationManagerCompat.from(getApplicationContext());
            notificationManager.cancel(GAME_NOTIFICATION_ID);
            
            // Сбрасываем счетчики и информацию о загрузке при отмене
            speedQueue.clear();
            sumSpeed = 0;
            
            runOnUiThread(() -> {
                downloadSizeSpeedInfo.setText("Загрузка отменена");
            });

            System.out.println("/ LoadGameCacheFiles Загрузчик файлов завершил работу, возврат в меню");
            // repeatButton.setVisibility(View.VISIBLE);
            super.onCancelled();
        }
    }

    @Override
    public void onBackPressed() {
        if (loadHashesTask != null) {
            loadHashesTask.cancel(true);
        }
        if (downloadTask != null) {
            downloadTask.cancel(true);
        }
    }

    private final int windowSize = 25;
    private Queue<Float> speedQueue = new LinkedList<>();
    private float sumSpeed = 0;
    private long allBytesDownloaded = 0;

    private int downloadFileInThread(
            String urlFrom,
            String pathTo,
            long totalSizeOfFiles) {

        try {
            URL url = new URL(urlFrom);
            HttpURLConnection httpConn = (HttpURLConnection) url.openConnection();
            httpConn.connect();
            int responseCode = httpConn.getResponseCode();

            if (responseCode == HttpURLConnection.HTTP_OK) {
                File file = new File(pathTo);
                if (file.exists()) file.delete();
                File parentDir = file.getParentFile();
                if (!parentDir.exists()) {
                    parentDir.mkdirs();
                }
                file.createNewFile();

                InputStream inputStream = httpConn.getInputStream();
                FileOutputStream outputStream = new FileOutputStream(pathTo);

                byte[] buffer = new byte[4096];
                int bytesRead = -1;
                long bytesDownloaded = 0;
                long bytesAll = httpConn.getContentLength();
                long startTime = System.currentTimeMillis();

                while ((bytesRead = inputStream.read(buffer)) != -1) {
                    outputStream.write(buffer, 0, bytesRead);
                    bytesDownloaded += bytesRead;
                    allBytesDownloaded += bytesRead;

                    int elapsedSeconds = (int) ((System.currentTimeMillis() - startTime) / 1000);
                    if (elapsedSeconds < 1)
                        elapsedSeconds = 1;

                    float currentDownloadSpeed = (float) bytesDownloaded / elapsedSeconds;

                    if(bytesAll > 10485760) {
                        speedQueue.add(currentDownloadSpeed);
                        sumSpeed += currentDownloadSpeed;
                        if (speedQueue.size() > windowSize) {
                            sumSpeed -= speedQueue.remove();
                        }
                    }

                    float averageDownloadSpeed = 0f;
                    if (speedQueue.size() > 0) {
                        averageDownloadSpeed = sumSpeed / speedQueue.size();
                    }

                    int prepareSecondsLeft = 5;
                    if (averageDownloadSpeed > 0)
                        prepareSecondsLeft = Math.round((totalSizeOfFiles - allBytesDownloaded) / averageDownloadSpeed);
                    int secondsLeft = prepareSecondsLeft;

                    double prepareProgress = ((double) bytesDownloaded / bytesAll) * 100d;
                    if(prepareProgress < 0d) prepareProgress = 0d;
                    else if(prepareProgress > 100d) prepareProgress = 100d;
                    double fileProgress = prepareProgress;
                    float speedOfLoadingInMBPS = (averageDownloadSpeed / 1024f) / 1024f;

                    // Создаем финальные переменные для использования в runOnUiThread
                    final float finalSpeedMbps = speedOfLoadingInMBPS;
                    final long finalBytesDownloaded = bytesDownloaded;
                    final long finalBytesAll = bytesAll;

                    runOnUiThread(() -> {
                        String fileName = String.format(
                                "Загрузка %s...", file.getName());

                        loadingInfo.setText(fileName);
                        
                        // Обновляем информацию о загрузке: скачано/всего + скорость
                        String downloadInfo = String.format("%.1f МБ из %.1f МБ (%.1f МБ/с)", 
                                finalBytesDownloaded / 1024.0f / 1024.0f,
                                finalBytesAll / 1024.0f / 1024.0f,
                                finalSpeedMbps);
                        downloadSizeSpeedInfo.setText(downloadInfo);
                    });
                }

                outputStream.close();
                inputStream.close();
            } else {
                System.out.println("downloadFileInThread Cache Ошибка при загрузке файла. Код ответа: " + responseCode);
            }
            return responseCode;
        } catch (IOException ex) {
            System.out.println("/ downloadFileInThread Cache Исключение при загрузке файла: " + ex.getMessage());
            ex.printStackTrace();
        }
        return -1;
    }

    private void InstallGame()
    {
        if (loadHashesTask != null) {
            loadHashesTask.cancel(true);
        }
        if (downloadTask != null) {
            downloadTask.cancel(true);
        }
        progressLoading.setVisibility(View.VISIBLE);
        progressLoadingCancel.setVisibility(View.INVISIBLE);
        loadingInfo.setVisibility(View.VISIBLE);
        progressLoading.setMax(100);
        
        // Сбрасываем счетчики скорости и информацию о загрузке
        speedQueue.clear();
        sumSpeed = 0;
        allBytesDownloaded = 0;
        downloadSizeSpeedInfo.setText("0.0 МБ из 0.0 МБ");

        // Проверяем, нужно ли пропустить проверку файлов
        try {
            Wini w = new Wini(new File(Settings.path_settings));
            String skipFileCheck = w.get("client", SKIP_FILES_CHECK);
            if (skipFileCheck == null) {
                skipFileCheck = "0"; // Значение по умолчанию
            }
            boolean isSkipFileCheck = "1".equals(skipFileCheck);
            
            if (isSkipFileCheck) {
                // Пропускаем проверку и сразу запускаем игру
                loadingInfo.setText("Запуск игры...");
                percentsCommonInfo.setText("Проверка файлов отключена");
                
                // Небольшая задержка перед запуском для визуального отображения сообщения
                new Handler().postDelayed(() -> {
                    startActivity(new Intent(getApplicationContext(), GTASA.class));
                    finish();
                }, 1500);
                return;
            }
        } catch (Exception e) {
            e.printStackTrace();
            // В случае ошибки продолжаем обычную проверку файлов
        }

        // Обычная проверка файлов
        loadHashesTask = new InitControlHashesTask();
        loadHashesTask.execute(GAME_PATH);
    }

    private void initialize(Bundle savedInstanceState) {
        loadingInfo = findViewById(R.id.brp_launcher_load_progress_titile);
        progressLoading = findViewById(R.id.brp_launcher_load_progress_bar);
        percentsCommonInfo = findViewById(R.id.brp_launcher_load_progress_text);
        progressLoadingCancel = findViewById(R.id.brp_launcher_load_progress_bar_inter);
        downloadSizeSpeedInfo = findViewById(R.id.brp_launcher_load_progress_text_2);
    }

    public void showMessage(String _s) {
        Toast.makeText(getApplicationContext(), _s, Toast.LENGTH_LONG).show();
    }
}
