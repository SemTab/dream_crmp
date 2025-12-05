package com.dmob.launcher.activity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.dmob.cr.R;
import com.dmob.launcher.adapter.FaqAdapter;
import com.dmob.launcher.adapter.FaqInfo;
import com.dmob.launcher.network.Interface;
import com.dmob.launcher.network.Lists;
import com.dmob.launcher.utils.Utils;

import java.util.ArrayList;
import java.util.List;

import es.dmoral.toasty.Toasty;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;

public class FaqActivity extends AppCompatActivity {

    private RecyclerView mRecyclerView;
    private FaqAdapter mAdapter;
    private ArrayList<FaqInfo> mFaqList = new ArrayList<>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_faq);

        // Инициализация UI элементов
        TextView titleTextView = findViewById(R.id.faq_title);
        Button backButton = findViewById(R.id.faq_back_btn);
        mRecyclerView = findViewById(R.id.faq_recycler);

        // Настройка заголовка
        titleTextView.setText("Часто задаваемые вопросы");

        // Настройка кнопки назад
        backButton.setOnClickListener(view -> {
            // Просто закрываем активити вместо запуска новой
            finish();
        });

        // Настройка RecyclerView
        mRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        mAdapter = new FaqAdapter(this);
        mRecyclerView.setAdapter(mAdapter);

        // Проверяем, есть ли предзагруженные данные
        if (Lists.flist != null && !Lists.flist.isEmpty()) {
            // Используем предзагруженные данные FAQ
            mFaqList.clear();
            mFaqList.addAll(Lists.flist);
            mAdapter.setFaqList(mFaqList);
            Log.i("BR-RP", "Использованы предзагруженные FAQ данные: " + mFaqList.size() + " элементов");
        } else {
            // Если нет предзагруженных данных, загружаем с сервера
            loadFaqDataFromServer();
        }
    }

    private void loadFaqDataFromServer() {
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("http://a1199406.xsph.ru/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();
                
        Interface apiInterface = retrofit.create(Interface.class);
        Call<List<FaqInfo>> call = apiInterface.getFaq();
        
        call.enqueue(new Callback<List<FaqInfo>>() {
            @Override
            public void onResponse(Call<List<FaqInfo>> call, Response<List<FaqInfo>> response) {
                if (response.isSuccessful() && response.body() != null) {
                    List<FaqInfo> faqInfoList = response.body();
                    mFaqList.clear();
                    mFaqList.addAll(faqInfoList);
                    mAdapter.setFaqList(mFaqList);
                    Log.i("BR-RP", "FAQ загружены с сервера: " + mFaqList.size() + " элементов");
                    
                    // Сохраняем загруженные данные для дальнейшего использования
                    Lists.flist.clear();
                    Lists.flist.addAll(faqInfoList);
                } else {
                    // Если загрузка не удалась, показываем сообщение об ошибке
                    Toasty.error(getApplicationContext(), "Не удалось загрузить FAQ", Toast.LENGTH_SHORT, true).show();
                }
            }

            @Override
            public void onFailure(Call<List<FaqInfo>> call, Throwable t) {
                // В случае ошибки сети показываем сообщение
                Toasty.error(getApplicationContext(), "Ошибка соединения с сервером", Toast.LENGTH_SHORT, true).show();
                Log.e("BR-RP", "Ошибка загрузки FAQ: " + t.getMessage());
            }
        });
    }
    
    @Override
    public void onBackPressed() {
        // Просто закрываем активити при нажатии кнопки назад
        finish();
    }
} 