package com.dmob.cr.gui;

import android.app.Activity;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.nvidia.devtech.NvEventQueueActivity;
import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;

import java.io.UnsupportedEncodingException;

public class SpeedometerMenu {
    private final ConstraintLayout mInputLayout;
    public static ImageView sp_engine_icon;
    private Button sp_close_button;
    public static ImageView sp_lock_icon;
    public static ImageView sp_stroboscope_icon;
    public static ImageView sp_neon_icon;
    public static ImageView sp_light_icon;
    public static ImageView sp_parking_icon;
    public static TextView sp_lock_text_view;
    public static LinearLayout sp_engine_container;
    public static LinearLayout sp_lock_container;
    public static LinearLayout sp_neon_container;
    public static LinearLayout sp_parking_container;
    public static LinearLayout sp_stroboscope_container;
    public static LinearLayout sp_light_container;
    private Activity mactivity;

    public SpeedometerMenu(Activity activity) {
        this.mInputLayout = activity.findViewById(R.id.speedometerMenu);
        this.mactivity = activity;

        // Инициализация кнопки закрытия
        this.sp_close_button = activity.findViewById(R.id.sp_close_button);
        sp_close_button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                closedMenu();
            }
        });

        // Инициализация контейнера двигателя
        this.sp_engine_icon = activity.findViewById(R.id.sp_engine_icon);
        this.sp_engine_container = activity.findViewById(R.id.sp_engine_container);
        sp_engine_container.setClickable(true);
        sp_engine_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    NvEventQueueActivity.getInstance().sendClick("/en".getBytes("windows-1251"));
                } catch (UnsupportedEncodingException e) {
                    throw new RuntimeException(e);
                }
                closedMenu();
            }
        });

        // Инициализация контейнера замков
        this.sp_lock_icon = activity.findViewById(R.id.sp_lock_icon);
        this.sp_lock_text_view = activity.findViewById(R.id.sp_lock_text_view);
        this.sp_lock_container = activity.findViewById(R.id.sp_lock_container);
        sp_lock_container.setClickable(true);
        sp_lock_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    NvEventQueueActivity.getInstance().sendClick("/lock".getBytes("windows-1251"));
                } catch (UnsupportedEncodingException e) {
                    throw new RuntimeException(e);
                }
                closedMenu();
            }
        });

        // Инициализация контейнера неона
        this.sp_neon_icon = activity.findViewById(R.id.sp_neon_icon);
        this.sp_neon_container = activity.findViewById(R.id.sp_neon_container);
        sp_neon_container.setClickable(true);
        sp_neon_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    NvEventQueueActivity.getInstance().sendClick("/neon".getBytes("windows-1251"));
                } catch (UnsupportedEncodingException e) {
                    throw new RuntimeException(e);
                }
                closedMenu();
            }
        });

        // Инициализация контейнера парковки
        this.sp_parking_icon = activity.findViewById(R.id.sp_parking_icon);
        this.sp_parking_container = activity.findViewById(R.id.sp_parking_container);
        sp_parking_container.setClickable(true);
        sp_parking_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    NvEventQueueActivity.getInstance().sendClick("/park".getBytes("windows-1251"));
                } catch (UnsupportedEncodingException e) {
                    throw new RuntimeException(e);
                }
                closedMenu();
            }
        });

        // Инициализация контейнера фар
        this.sp_light_icon = activity.findViewById(R.id.sp_light_icon);
        this.sp_light_container = activity.findViewById(R.id.sp_light_container);
        sp_light_container.setClickable(true);
        sp_light_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    NvEventQueueActivity.getInstance().sendClick("/llight".getBytes("windows-1251"));
                } catch (UnsupportedEncodingException e) {
                    throw new RuntimeException(e);
                }
                closedMenu();
            }
        });

        // Инициализация контейнера стробоскопа
        this.sp_stroboscope_icon = activity.findViewById(R.id.sp_stroboscope_icon);
        this.sp_stroboscope_container = activity.findViewById(R.id.sp_stroboscope_container);
        sp_stroboscope_container.setClickable(true);
        sp_stroboscope_container.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    NvEventQueueActivity.getInstance().sendClick("/strobs".getBytes("windows-1251"));
                } catch (UnsupportedEncodingException e) {
                    throw new RuntimeException(e);
                }
                closedMenu();
            }
        });

        Utils.HideLayout(mInputLayout, false);
    }

    public void setEngine(int state) {
        if (state == 1) {
        //    sp_engine_icon.setImageResource(R.drawable.sp_engine_icon_on);
            sp_engine_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        } else {
            sp_engine_icon.setImageResource(R.drawable.sp_engine_icon);
            sp_engine_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        }
    }

    public void setLock(int state) {
        if (state == 1) {
        //    sp_lock_icon.setImageResource(R.drawable.sp_lock_icon_on);
            sp_lock_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        } else {
            sp_lock_icon.setImageResource(R.drawable.sp_lock_icon);
            sp_lock_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        }
    }

    public void setLight(int state) {
        if (state == 1) {
        //    sp_light_icon.setImageResource(R.drawable.sp_light_icon_on);
            sp_light_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        } else {
            sp_light_icon.setImageResource(R.drawable.sp_light_icon);
            sp_light_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        }
    }

    public void setParking(int state) {
        if (state == 1) {
            sp_parking_icon.setImageResource(R.drawable.sp_parking_icon_on);
            sp_parking_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        } else {
        //    sp_parking_icon.setImageResource(R.drawable.sp_parking_icon);
            sp_parking_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        }
    }

    public void setStrob(int state) {
        sp_stroboscope_container.setVisibility(View.VISIBLE);
        if (state == 1) {
        //    sp_stroboscope_icon.setImageResource(R.drawable.sp_stroboscope_icon);
            sp_stroboscope_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        } else if (state == 2) {
       //     sp_stroboscope_icon.setImageResource(R.drawable.sp_stroboscope_icon_off);
            sp_stroboscope_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        } else {
            sp_stroboscope_icon.setImageResource(R.drawable.sp_stroboscope_icon_grey);
            sp_stroboscope_icon.setColorFilter(mactivity.getResources().getColor(android.R.color.white));
        }
    }

    public static void setNeon(int state) {
        sp_neon_container.setVisibility(View.VISIBLE);
        if (state == 0) {
            sp_neon_icon.setImageResource(R.drawable.sp_neon_icon_grey);
        } else if (state == 1) {
        //    sp_neon_icon.setImageResource(R.drawable.sp_neon_icon);
        } else if (state == 2) {
        //    sp_neon_icon.setImageResource(R.drawable.sp_neon_icon_off);
        }
    }

    public void show() {
        Utils.ShowLayout(mInputLayout, true);
    }

    public void closedMenu() {
        Utils.HideLayout(mInputLayout, true);
    }

    public ConstraintLayout getInputLayout() {
        return this.mInputLayout;
    }
}
