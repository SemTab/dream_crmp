package com.dmob.launcher.activity;

import android.os.Bundle;
import android.view.View;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.ProgressBar;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.dmob.Settings;
import com.dmob.cr.R;

public class DonateWebViewActivity extends AppCompatActivity {

    private WebView webView;
    private ProgressBar progressBar;
    private Button backButton;
    private TextView titleTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_webview_donate);

        // Инициализация UI элементов
        webView = findViewById(R.id.webview_donate);
        progressBar = findViewById(R.id.webview_progress);
        backButton = findViewById(R.id.webview_back_btn);
        titleTextView = findViewById(R.id.webview_title);

        // Настройка заголовка
        titleTextView.setText("Пополнение счета");

        // Настройка кнопки назад
        backButton.setOnClickListener(view -> finish());

        // Настройка WebView
        webView.getSettings().setJavaScriptEnabled(true);
        webView.getSettings().setDomStorageEnabled(true);
        webView.getSettings().setBuiltInZoomControls(true);
        webView.getSettings().setDisplayZoomControls(false);

        webView.setWebChromeClient(new WebChromeClient() {
            @Override
            public void onProgressChanged(WebView view, int newProgress) {
                progressBar.setProgress(newProgress);
                if (newProgress == 100) {
                    progressBar.setVisibility(View.GONE);
                } else {
                    progressBar.setVisibility(View.VISIBLE);
                }
            }
        });

        webView.setWebViewClient(new WebViewClient() {
            @Override
            public boolean shouldOverrideUrlLoading(WebView view, String url) {
                view.loadUrl(url);
                return true;
            }
        });

        // Загрузка URL доната
        webView.loadUrl(Settings.URL_DONATE);
    }

    @Override
    public void onBackPressed() {
        if (webView.canGoBack()) {
            webView.goBack();
        } else {
            super.onBackPressed();
        }
    }
} 