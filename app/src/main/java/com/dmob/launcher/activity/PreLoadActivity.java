package com.dmob.launcher.activity;

import android.animation.AnimatorInflater;
import android.animation.AnimatorSet;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;
import com.dmob.cr.R;

public class PreLoadActivity extends AppCompatActivity {
    public Button play;
    public Button faqButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pre_load);
		
        // Анимация для эффекта свечения логотипа
        View logoGlowPreLoad = findViewById(R.id.logoGlowPreLoad);
        AnimatorSet pulseAnimation = (AnimatorSet) AnimatorInflater.loadAnimator(this, R.anim.logo_pulse);
        pulseAnimation.setTarget(logoGlowPreLoad);
        pulseAnimation.start();
        
		Animation animation = AnimationUtils.loadAnimation(this, R.anim.button_click);
        play = (Button) findViewById(R.id.brp_launcher_pre_load_download);

        play.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                v.startAnimation(animation);
                startActivity(new Intent(getApplicationContext(), LoaderActivity.class));
                finish();
            }
        });
        
        // Добавляем кнопку FAQ
        faqButton = findViewById(R.id.brp_launcher_pre_load_faq);
        if (faqButton != null) {
            faqButton.setOnClickListener(new OnClickListener() {
                public void onClick(View v) {
                    v.startAnimation(animation);
                    startActivity(new Intent(getApplicationContext(), FaqActivity.class));
                }
            });
        }
    }
} 