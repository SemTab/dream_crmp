package com.dmob.launcher.adapter;

import android.content.Context;
import android.view.MotionEvent;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;

import com.dmob.cr.R;

public class ButtonAnimator implements View.OnTouchListener {
    private final Context mContext;
    private final View mView;

    public ButtonAnimator(Context context, View view) {
        this.mContext = context;
        this.mView = view;
    }

    @Override
    public boolean onTouch(View view, MotionEvent motionEvent) {
        switch (motionEvent.getAction()) {
            case MotionEvent.ACTION_DOWN:
                Animation animDown = AnimationUtils.loadAnimation(this.mContext, R.anim.btn_click);
                this.mView.startAnimation(animDown);
                break;
            case MotionEvent.ACTION_UP:
            case MotionEvent.ACTION_CANCEL:
                Animation animUp = AnimationUtils.loadAnimation(this.mContext, R.anim.btn_release);
                this.mView.startAnimation(animUp);
                break;
        }
        return false;
    }
} 