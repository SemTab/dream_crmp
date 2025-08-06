package com.dmob.launcher.network;

import android.util.Log;
import com.dmob.launcher.utils.LogHelper;
import com.dmob.launcher.adapter.FaqInfo;
import com.dmob.launcher.model.News;
import com.dmob.launcher.model.Servers;
import com.dmob.launcher.model.ServersResponse;
import com.dmob.launcher.model.LauncherStatus;

import java.util.List;
import java.util.concurrent.TimeUnit;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import okhttp3.logging.HttpLoggingInterceptor;
import retrofit2.Call;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;
import retrofit2.http.GET;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

public interface Interface {
    @GET("https://cdn.bdsrvs.run/brp/mnbvcxzlkjhgfdsapoiuytrewqzx.php")
    Call<ServersResponse> getServers();

    @GET("https://cdn.bdsrvs.run/brp/asdkfjlqwertyuiopzxcvbnmghrw.php")
    Call<List<News>> getNews();

    @GET("https://cdn.bdsrvs.run/brp/plmoknijbuhvygctfxrdzeswaqyt.php")
    Call<List<FaqInfo>> getFaq();
    
    @GET("https://cdn.bdsrvs.run/brp/qzxwemrtyubnalksjdhfgvcxzpoi.php")
    Call<LauncherStatus> getLauncherStatus();
    
    /**
     * Создает настроенный экземпляр Retrofit с логированием
     * 
     * @param baseUrl базовый URL для API
     * @return экземпляр Interface для API-запросов
     */
    static Interface createWithLogs(String baseUrl) {
        // Создаем логгер для HTTP-запросов
        HttpLoggingInterceptor loggingInterceptor = new HttpLoggingInterceptor(message -> 
            LogHelper.d(LogHelper.TAG_NETWORK, message));
        loggingInterceptor.setLevel(HttpLoggingInterceptor.Level.BODY);
        
        // Настраиваем OkHttpClient с логированием и таймаутами
        OkHttpClient client = new OkHttpClient.Builder()
            .addInterceptor(loggingInterceptor)
            .addInterceptor(chain -> {
                Request request = chain.request();
                LogHelper.i(LogHelper.TAG_NETWORK, "Отправка запроса: " + request.url());
                long startTime = System.currentTimeMillis();
                
                Response response = chain.proceed(request);
                long endTime = System.currentTimeMillis();
                
                String responseInfo = String.format(
                    "Получен ответ от %s за %d мс: %d %s",
                    request.url(),
                    endTime - startTime,
                    response.code(),
                    response.message()
                );
                
                if (response.isSuccessful()) {
                    LogHelper.i(LogHelper.TAG_NETWORK, responseInfo);
                } else {
                    LogHelper.e(LogHelper.TAG_NETWORK, responseInfo);
                }
                
                return response;
            })
            .connectTimeout(30, TimeUnit.SECONDS)
            .readTimeout(30, TimeUnit.SECONDS)
            .writeTimeout(30, TimeUnit.SECONDS)
            .build();
        
        // Создаем кастомную конфигурацию Gson с нашим десериализатором
        Gson gson = new GsonBuilder()
            .registerTypeAdapter(ServersResponse.class, new ServersResponse.ServersResponseDeserializer())
            .create();
        
        // Создаем и возвращаем Retrofit
        Retrofit retrofit = new Retrofit.Builder()
            .baseUrl(baseUrl)
            .client(client)
            .addConverterFactory(GsonConverterFactory.create(gson))
            .build();
            
        return retrofit.create(Interface.class);
    }
}
