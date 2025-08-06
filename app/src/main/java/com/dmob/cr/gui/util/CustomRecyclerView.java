package com.dmob.cr.gui.util;

import android.annotation.SuppressLint;
import android.content.Context;
import android.util.AttributeSet;
import android.view.MotionEvent;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.recyclerview.widget.RecyclerView;

public class CustomRecyclerView extends RecyclerView {
    private boolean mEnableScrolling = true;

    public CustomRecyclerView(@NonNull Context context) {
        super(context);
    }

    public CustomRecyclerView(@NonNull Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    public CustomRecyclerView(@NonNull Context context, @Nullable AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
    }

    @Override
    public boolean onInterceptTouchEvent(MotionEvent motionEvent) {
        if (isEnableScrolling())
            return super.onInterceptTouchEvent(motionEvent);

        return false;
    }

    @SuppressLint("ClickableViewAccessibility")
    @Override
    public boolean onTouchEvent(MotionEvent motionEvent) {
        if (isEnableScrolling())
            return super.onTouchEvent(motionEvent);

        return false;
    }

    public int getScrollForRecycler() {
        return computeVerticalScrollOffset();
    }

    public boolean isEnableScrolling() {
        return this.mEnableScrolling;
    }

    public void setEnableScrolling(boolean z) {
        this.mEnableScrolling = z;
    }
}
