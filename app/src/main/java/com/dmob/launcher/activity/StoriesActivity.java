package com.dmob.launcher.activity;

import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.bumptech.glide.Glide;
import com.dmob.cr.R;
import com.dmob.launcher.model.News;

import java.util.ArrayList;

public class StoriesActivity extends AppCompatActivity {

    private ImageView mBackground;
    private TextView mDescription;
    private Button mMoreBtn;
    private int currentPosition = 0;
    
    // Массив новостей
    private ArrayList<News> newsList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_stories);

        // Получаем данные из Intent
        currentPosition = getIntent().getIntExtra("current_position", 0);
        newsList = (ArrayList<News>) getIntent().getSerializableExtra("news_list");

        this.mBackground = findViewById(R.id.brp_launcher_stories_bg);
        this.mDescription = findViewById(R.id.brp_launcher_stories_description);
        this.mMoreBtn = findViewById(R.id.brp_launcher_stories_more_btn);

        this.mMoreBtn.setOnClickListener(view1 -> {
            // Открываем ссылку, если она есть
            News currentNews = newsList.get(currentPosition);
            String link = currentNews.getLink();
            if (link != null && !link.isEmpty()) {
                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse(link)));
            }
        });

        View skipBtn = findViewById(R.id.brp_launcher_stories_skip);
        View reverseBtn = findViewById(R.id.brp_launcher_stories_reverse);
        Button closeBtn = findViewById(R.id.brp_launcher_stories_close_btn);

        skipBtn.setOnClickListener(view1 -> {
            if (currentPosition < newsList.size() - 1) {
                currentPosition++;
                updateStories();
            } else {
                startActivity(new Intent(getApplicationContext(), MainActivity.class));
                finish();
            }
        });
        
        reverseBtn.setOnClickListener(view1 -> {
            if (currentPosition > 0) {
                currentPosition--;
                updateStories();
            }
        });

        closeBtn.setOnClickListener(view1 -> {
            startActivity(new Intent(getApplicationContext(), MainActivity.class));
            finish();
        });

        updateStories();
    }

    private void updateStories() {
        News currentNews = newsList.get(currentPosition);
        
        // Используем изображение из кэша для первой новости
        if (currentPosition == getIntent().getIntExtra("current_position", 0) && StoriesImageCache.bitmap != null) {
            this.mBackground.setImageBitmap(StoriesImageCache.bitmap);
        } else {
            // Для остальных новостей загружаем изображение через Glide
            Glide.with(this)
                .load(currentNews.getImageUrl())
                .into(this.mBackground);
        }
        
        this.mDescription.setText(currentNews.getTitle());

        // Если есть кнопка, то показываем её
        String buttonText = currentNews.getButton();
        if (buttonText != null && !buttonText.isEmpty()) {
            this.mMoreBtn.setVisibility(View.VISIBLE);
            this.mMoreBtn.setText(buttonText);
        } else {
            this.mMoreBtn.setVisibility(View.GONE);
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        // Очищаем кэш изображения при закрытии активити
        StoriesImageCache.bitmap = null;
    }

    @Override
    public void onBackPressed() {
        startActivity(new Intent(getApplicationContext(), MainActivity.class));
        finish();
    }
}