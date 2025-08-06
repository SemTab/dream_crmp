package com.dmob.cr.gui;

import android.app.Activity;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.*;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.dmob.launcher.model.Servers;
import com.dmob.launcher.network.Lists;
import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;

import java.util.ArrayList;

public class Welcome {
    public Activity activity;
    public Animation animation;

    public ConstraintLayout constraintLayout;
    public Button mPlay;

    public TextView mTitle;
    public TextView mDescription;
    ArrayList<Servers> servers;

    public Welcome(Activity aactivity){
        constraintLayout = aactivity.findViewById(R.id.brp_welcome_main);
        animation = AnimationUtils.loadAnimation(aactivity, R.anim.button_click);
        servers = Lists.slist;

        mTitle = aactivity.findViewById(R.id.brp_welcome_title);
        mDescription = aactivity.findViewById(R.id.brp_welcome_desc);

        mPlay = aactivity.findViewById(R.id.brp_welcome_btn);
        mPlay.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                hide(view);
            }
        });

        mTitle.animate().setDuration(0).translationXBy(-2000.0f).start();
        mDescription.animate().setDuration(0).translationXBy(-2000.0f).start();
        mPlay.animate().setDuration(0).translationXBy(-2000.0f).start();

        Utils.HideLayout(constraintLayout, false);

    }

    public void show(boolean isRegister) {
        Utils.ShowLayout(constraintLayout, true);
        mTitle.setText("ДОБРО ПОЖАЛОВАТЬ НА " + servers.get(0).getname());
        /*if (isRegister) {
            mTitle.setText("Добро пожаловать\nНА BRILLIANT MOBILE");
        } else {
            mTitle.setText("С возвращением\nНА BRILLIANT MOBILE");
        }*/
        mTitle.animate().setDuration(1500).translationXBy(2000.0f).start();
        mDescription.animate().setDuration(1500).setStartDelay(250).translationXBy(2000.0f).start();
        mPlay.animate().setDuration(1500).setStartDelay(500).translationXBy(2000.0f).start();
    }

    public void hide(View v) {
        Utils.HideLayout(constraintLayout, true);
        v.startAnimation(animation);
        mPlay.animate().setDuration(1500).translationXBy(-2000.0f).start();
        mDescription.animate().setDuration(1500).setStartDelay(250).translationXBy(-2000.0f).start();
        mTitle.animate().setDuration(1500).setStartDelay(500).translationXBy(-2000.0f).start();
    }
}