package com.dmob.launcher.activity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.dmob.Settings;
import com.dmob.cr.R;

/**
 * Активность, отображаемая когда лаунчер отключен
 */
public class LauncherDisabledActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_launcher_disabled);
        
        // Получаем сообщение о причине отключения из Intent
        String disabledMessage = getIntent().getStringExtra("disabled_message");
        
        // Устанавливаем сообщение в TextView
        TextView messageTextView = findViewById(R.id.launcher_disabled_message);
        if (disabledMessage != null && !disabledMessage.isEmpty()) {
            messageTextView.setText(disabledMessage);
        }
        
        // Настраиваем кнопку выхода
        Button exitButton = findViewById(R.id.launcher_disabled_exit_button);
        exitButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
        
        // Настраиваем кнопки социальных сетей
        ImageView vkButton = findViewById(R.id.imageViewVK);
        ImageView telegramButton = findViewById(R.id.imageViewTelegram);
        
        vkButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openUrl(Settings.URL_VK);
            }
        });
        
        telegramButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                openUrl(Settings.URL_TG);
            }
        });
    }
    
    /**
     * Открывает URL в браузере
     */
    private void openUrl(String url) {
        Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
        startActivity(intent);
    }
    
    // Запрещаем возвращение назад по кнопке "Back"
    @Override
    public void onBackPressed() {
        // Не вызываем super.onBackPressed(), чтобы запретить возврат назад
        // Пользователь может только выйти по кнопке "Выйти"
    }
} 