package com.dmob.launcher.activity;

import android.Manifest;
import android.app.Activity;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.os.Build;

import android.provider.Settings;

import android.widget.*;

import androidx.annotation.RequiresApi;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;

import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.view.View.OnClickListener;
import android.view.View;
import android.view.animation.AnimationUtils;
import android.view.animation.Animation;

import com.dmob.launcher.adapter.NewsAdapter;
import com.dmob.launcher.adapter.ServersAdapter;
import com.dmob.launcher.model.News;
import com.dmob.launcher.model.Servers;
import com.dmob.launcher.network.Lists;
import com.dmob.launcher.utils.GetStoragePermission;
import com.dmob.launcher.utils.Utils;
import com.dmob.cr.BuildConfig;
import com.dmob.cr.gui.util.Damp;
import com.dmob.cr.R;
import com.dmob.cr.core.GTASA;
import com.google.firebase.analytics.FirebaseAnalytics;
import com.google.firebase.messaging.FirebaseMessaging;

import java.util.*;

import es.dmoral.toasty.Toasty;
import com.dmob.launcher.utils.LogHelper;
import com.dmob.launcher.Preferences;

public class MainActivity extends AppCompatActivity {
    public TextView donate;
    public Button play;
    public Button settings;

    private static final int PERMISSION_STORAGE = 101;

    RecyclerView recyclerNews;
    NewsAdapter newsAdapter;
    ArrayList<News> nlist;

    RecyclerView recyclerServers;
    ServersAdapter serversAdapter;
    ArrayList<Servers> slist;
    Activity activity;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        activity = this;
		
		Animation animation = AnimationUtils.loadAnimation(this, R.anim.btn_click);
        donate = (TextView) findViewById(R.id.brp_launcher_donate);
        play = (Button) findViewById(R.id.brp_launcher_play);
        settings = (Button) findViewById(R.id.brp_launcher_settings_btn);
        recyclerServers = findViewById(R.id.rvServers);
        recyclerNews = findViewById(R.id.rvNews);
        
        // Добавляем кнопку для FAQ
        Button faqButton = findViewById(R.id.brp_launcher_faq_btn);
        if (faqButton != null) {
            faqButton.setOnClickListener(view -> {
                startActivity(new Intent(this, FaqActivity.class));
            });
        }
        
        // Добавляем кнопку для доната
        Button donateButton = findViewById(R.id.brp_launcher_donate_btn);
        if (donateButton != null) {
            donateButton.setOnClickListener(view -> {
                view.startAnimation(animation);
                startActivity(new Intent(MainActivity.this, DonateWebViewActivity.class));
            });
        }

        new CountDownTimer(100, 1) {
            public void onTick(long l) {

            }
            public void onFinish() {
                // Инициализируем списки сначала, так как Damp.isCorrupted может быть false по умолчанию
                recyclerServers.setHasFixedSize(true);
                LinearLayoutManager layoutManagerr = new LinearLayoutManager(getApplicationContext(), LinearLayoutManager.HORIZONTAL, false);
                recyclerServers.setLayoutManager(layoutManagerr);
                
                recyclerNews.setHasFixedSize(true);
                LinearLayoutManager layoutManager = new LinearLayoutManager(getApplicationContext(), LinearLayoutManager.HORIZONTAL, false);
                recyclerNews.setLayoutManager(layoutManager);
                
                // Явно устанавливаем видимость
                    recyclerServers.setVisibility(View.VISIBLE);
                    recyclerNews.setVisibility(View.VISIBLE);

                // Проверяем, получены ли списки и не повреждены ли данные
                if(Lists.slist != null && Lists.slist.size() > 0) {
                    slist = Lists.slist;
                    serversAdapter = new ServersAdapter(getApplicationContext(), slist);
                    recyclerServers.setAdapter(serversAdapter);
                    LogHelper.d("MainActivity", "Список серверов загружен успешно: " + slist.size() + " серверов");
                } else {
                    LogHelper.e("MainActivity", "Список серверов пуст или не инициализирован");
                    recyclerServers.setVisibility(View.GONE);
                    Toasty.warning(getApplicationContext(), "Не удалось загрузить список серверов", Toast.LENGTH_SHORT, true).show();
                }
                
                if(Lists.nlist != null && Lists.nlist.size() > 0) {
                    nlist = Lists.nlist;
                    newsAdapter = new NewsAdapter(MainActivity.this, nlist);
                    recyclerNews.setAdapter(newsAdapter);

                    // Обработчик клика по новостям
                    newsAdapter.setOnItemClickListener(position -> {
                        // Получаем выбранную новость
                        final News selectedStory = nlist.get(position);
                        
                        // Загружаем изображение и запускаем активити
                        com.bumptech.glide.Glide.with(MainActivity.this)
                            .asBitmap()
                            .load(selectedStory.getImageUrl())
                            .into(new com.bumptech.glide.request.target.SimpleTarget<android.graphics.Bitmap>() {
                                @Override
                                public void onResourceReady(android.graphics.Bitmap resource, com.bumptech.glide.request.transition.Transition<? super android.graphics.Bitmap> transition) {
                                    // Создаем статический временный класс для хранения изображения
                                    StoriesImageCache.bitmap = resource;
                                    
                                    // Запускаем активити с историей
                                    Intent intent = new Intent(MainActivity.this, StoriesActivity.class);
                                    intent.putExtra("current_position", position);
                                    intent.putExtra("news_list", nlist);
                                    startActivity(intent);
                                }
                            });
                    });
                    LogHelper.d("MainActivity", "Список новостей загружен успешно: " + nlist.size() + " новостей");
                } else {
                    LogHelper.e("MainActivity", "Список новостей пуст или не инициализирован");
                    recyclerNews.setVisibility(View.GONE);
                    Toasty.warning(getApplicationContext(), "Не удалось загрузить новости", Toast.LENGTH_SHORT, true).show();
                }
            }
        }.start();

		settings.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                onClickSettings();
            }
        });

        play.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                startTimer();
            }
        });

        FirebaseMessaging.getInstance().subscribeToTopic("all");
        
        // Получаем и логируем FCM токен
//        FirebaseMessaging.getInstance().getToken()
//            .addOnCompleteListener(task -> {
//                if (!task.isSuccessful()) {
//                    LogHelper.e(LogHelper.TAG_MAIN, "Fetching FCM registration token failed", task.getException());
//                    return;
//                }
//
//                // Get new FCM registration token
//                String token = task.getResult();
//                
//                // Сохраняем токен в настройках
//                Preferences.putString(getApplicationContext(), Preferences.USER_FCM_KEY, token);
//                
//                // Логируем токен
//                LogHelper.i(LogHelper.TAG_MAIN, "FCM Token: " + token);
//            });
        
        // Обработчик для текстовой ссылки доната (если она будет отображаться)
        donate.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                v.startAnimation(animation);
                // Открываем WebView активити вместо браузера
                startActivity(new Intent(MainActivity.this, DonateWebViewActivity.class));
            }
        });
    }

    @RequiresApi(api = Build.VERSION_CODES.R)
    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode != 1000) {
            if (checkSelfPermission(Manifest.permission.RECORD_AUDIO) == PackageManager.PERMISSION_DENIED ) {
                requestPermissions(new String[]{Manifest.permission.RECORD_AUDIO}, 1000);
            }
            if (!GetStoragePermission.ISPermission(this)) {
                GetStoragePermission.requestPermission(MainActivity.this, PERMISSION_STORAGE);
            }
        }
    }
	
	@RequiresApi(api = Build.VERSION_CODES.M)
    public void onClickPlay() {
        if (checkSelfPermission(Manifest.permission.RECORD_AUDIO) == PackageManager.PERMISSION_DENIED ) {
            requestPermissions(new String[]{Manifest.permission.RECORD_AUDIO}, 1000);
            return;
        }
        if (!GetStoragePermission.ISPermission(this)) {
            GetStoragePermission.requestPermission(MainActivity.this, PERMISSION_STORAGE);
            return;
        }

        if(Utils.isGameInstalled())
            startActivity(new Intent(getApplicationContext(), LoaderActivity.class));
        else
            startActivity(new Intent(getApplicationContext(), PreLoadActivity.class));
        finish();
    }

    public void onClickSettings() {
        startActivity(new Intent(getApplicationContext(), SettingsActivity.class));
        finish();
    }
	
	private void startTimer() {
        Timer t = new Timer();
        t.schedule(new TimerTask() {
            @RequiresApi(api = Build.VERSION_CODES.M)
            @Override
            public void run() {
                onClickPlay();
            }
        }, 150L);
    }
	
	public void onDestroy() {
        super.onDestroy();
    }

    public void onRestart() {
        super.onRestart();
    }

    // Вспомогательный метод для открытия ссылок
    private void openUrl(String url) {
        Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
        startActivity(browserIntent);
    }
} 