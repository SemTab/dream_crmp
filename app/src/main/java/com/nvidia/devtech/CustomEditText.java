package com.nvidia.devtech;

import android.annotation.SuppressLint;
import android.content.Context;
import android.util.AttributeSet;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;

import java.util.ArrayList;
import java.util.List;

@SuppressLint("AppCompatCustomView")
public class CustomEditText extends EditText {
    private Context mContext = null;
    
    // Добавляем список слушателей фокуса
    public List<View.OnFocusChangeListener> c = new ArrayList<>();
    
    // Добавляем интерфейс слушателя нажатия кнопки Back
    public interface c {
    }

    public CustomEditText(Context context, AttributeSet attrs) {
        super(context, attrs);
        mContext = context;
    }

    // Переименовываем метод для совместимости
    public void SetBackListener(Context context) {
        mContext = context;
    }
    
    // Добавляем метод для установки слушателя нажатия кнопки Back
    public void setOnBackListener(c listener) {
        // Реализация метода
    }
    
    // Добавляем метод a для совместимости с KeyBoard
    public void a(View.OnFocusChangeListener listener) {
        if (listener != null) {
            c.add(listener);
        }
    }

    @Override
    public boolean onKeyPreIme(int keyCode, KeyEvent event) {
        if (keyCode == KeyEvent.KEYCODE_BACK) {
            ((NvEventQueueActivity)mContext).onEventBackPressed();
            return true;
        }
        return false;
    }
}
