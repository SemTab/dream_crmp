package com.dmob.cr.gui.hud;

import android.app.Activity;
import android.os.Handler;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.CompoundButton;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.ToggleButton;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.nvidia.devtech.NvEventQueueActivity;
import com.dmob.cr.gui.util.Damp;
import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;

import java.text.DecimalFormat;
import java.text.SimpleDateFormat;
import java.text.DecimalFormatSymbols;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;

public class Hud {
    public Activity activity;

    public Animation animation, hideanim, showanim;
    public androidx.constraintlayout.widget.ConstraintLayout hud_layout, hud_online, brp_hud_date, brp_hud_time, brp_hud_level;
    public LinearLayout hud_ammo_layout, brp_hud_logo;

    public ProgressBar hud_health, hud_hunger, hud_armour;

    public TextView hud_health_t, hud_hunger_t, hud_armour_t, hud_money;
    public TextView hud_time, hud_date, hud_online_text, hud_ammo, hud_ammoinclip, hud_level;

    public ArrayList<ImageView> hud_wanted;
    public ImageView hud_weapon, hud_x2;
    
    public View hud_seat;
    public View hud_alt, hud_y, hud_n, hud_h, hud_ctrl, hud_g;
    public ToggleButton hud_sr;
    
    public static Boolean hud_hide_data_time = false;
    public static Boolean hud_b_sr = false;
    public static Boolean hud_hide_logo = false;
    public static Boolean bt_is_ctrl = false;
    
    private int playerLevel = 1;
    private long currentDisplayedMoney = 0; // Текущее отображаемое количество денег
    private long lastMoneyValue = 0; // Последнее значение денег для корректного расчета
    private Timer moneyAnimationTimer; // Таймер для анимации денег
    private boolean isMoneyAnimationRunning = false; // Флаг запущенной анимации
    private static final long MAX_MONEY_VALUE = 999_999_999_999L; // Максимальное значение денег
    private boolean useShortMoneyFormat = true; // Флаг для формата отображения денег

    public Hud(Activity aactivity) {
        activity = aactivity;

        Animation animation = AnimationUtils.loadAnimation(aactivity, R.anim.button_click);
        Animation hideanim = AnimationUtils.loadAnimation(aactivity, R.anim.popup_hide_notification);
        Animation showanim = AnimationUtils.loadAnimation(aactivity, R.anim.popup_show_notification);

        hud_layout = aactivity.findViewById(R.id.bhud_main);
        hud_layout.setVisibility(View.GONE);
        hud_online = aactivity.findViewById(R.id.brp_hud_online);

        brp_hud_logo = aactivity.findViewById(R.id.brp_hud_logo);
        brp_hud_time = aactivity.findViewById(R.id.brp_hud_time);
        brp_hud_date = aactivity.findViewById(R.id.brp_hud_date);
        brp_hud_level = aactivity.findViewById(R.id.brp_hud_level);

        hud_x2 = aactivity.findViewById(R.id.imageView);
        if(Damp.GetX2Status() == true){
            hud_x2.setVisibility(View.VISIBLE);
        } else {
            hud_x2.setVisibility(View.GONE);
        }

        hud_health = aactivity.findViewById(R.id.hud_health_pb);
        hud_hunger = aactivity.findViewById(R.id.hud_eat_pb);
        hud_armour = aactivity.findViewById(R.id.hud_armour_pb);

        hud_health_t = aactivity.findViewById(R.id.hud_health_text);
        hud_hunger_t = aactivity.findViewById(R.id.hud_eat_text);
        hud_armour_t = aactivity.findViewById(R.id.hud_armour_text);

        hud_money = aactivity.findViewById(R.id.hud_balance_text);
        hud_money.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                useShortMoneyFormat = !useShortMoneyFormat;
                updateMoneyDisplay(lastMoneyValue);
            }
        });

        hud_weapon = aactivity.findViewById(R.id.hud_fist_icon);
        hud_ammo = aactivity.findViewById(R.id.hud_max_ammo_text);
        hud_ammoinclip = aactivity.findViewById(R.id.hud_ammo_text);
        hud_ammo_layout = aactivity.findViewById(R.id.hud_ammo_layout);

        hud_time = aactivity.findViewById(R.id.hud_time_text);
        hud_date = aactivity.findViewById(R.id.hud_date_text);
        hud_online_text = aactivity.findViewById(R.id.hud_online_text);
        hud_level = aactivity.findViewById(R.id.hud_level_text);

        hud_wanted = new ArrayList<>();
        hud_wanted.add(activity.findViewById(R.id.hud_star_1));
        hud_wanted.add(activity.findViewById(R.id.hud_star_2));
        hud_wanted.add(activity.findViewById(R.id.hud_star_3));
        hud_wanted.add(activity.findViewById(R.id.hud_star_4));
        hud_wanted.add(activity.findViewById(R.id.hud_star_5));
        
        hud_sr = aactivity.findViewById(R.id.toggleButton);

        hud_seat = aactivity.findViewById(R.id.imageView2);
        hud_seat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                NvEventQueueActivity.getInstance().sendG();
            }
        });
        
        hud_y = aactivity.findViewById(R.id.imageView6);
        hud_y.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                hideAllButt();
                
                // Отправляем событие Y немедленно
                NvEventQueueActivity.getInstance().sendY();
                
                // Добавляем повторный вызов через небольшую задержку для надежности
                new Handler().postDelayed(() -> {
                    NvEventQueueActivity.getInstance().sendY();
                }, 100);
            }
        });

        hud_n = aactivity.findViewById(R.id.imageView8);
        hud_n.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                hideAllButt();
                
                // Отправляем событие N немедленно
                NvEventQueueActivity.getInstance().sendN();
                
                // Добавляем повторный вызов через небольшую задержку для надежности
                new Handler().postDelayed(() -> {
                    NvEventQueueActivity.getInstance().sendN();
                }, 100);
            }
        });

        hud_h = aactivity.findViewById(R.id.imageView9);
        hud_h.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                hideAllButt();
                
                // Отправляем событие H немедленно
                NvEventQueueActivity.getInstance().sendH();
                
                // Добавляем повторный вызов через небольшую задержку для надежности
                new Handler().postDelayed(() -> {
                    NvEventQueueActivity.getInstance().sendH();
                }, 100);
            }
        });

        hud_alt = aactivity.findViewById(R.id.imageView4);
        hud_alt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);

                // Отправляем событие ALT немедленно
                // Если нужна кнопка CTRL, используем соответствующую логику
                if(bt_is_ctrl == false) {
                    // Сразу вызываем нативный метод и ставим флаг
                    NvEventQueueActivity.getInstance().sendALT();
                    
                    // Добавляем повторный вызов через небольшую задержку для надежности
                    new Handler().postDelayed(() -> {
                        NvEventQueueActivity.getInstance().sendALT();
                    }, 100);
                } else {
                    // Для CTRL сразу вызываем нативный метод
                    NvEventQueueActivity.getInstance().sendCTRL();
                    
                    // Добавляем повторный вызов через небольшую задержку для надежности
                    new Handler().postDelayed(() -> {
                        NvEventQueueActivity.getInstance().sendCTRL();
                    }, 100);
                }
            }
        });
        
        hud_ctrl = aactivity.findViewById(R.id.imageView5);
        hud_ctrl.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                
                // Отправляем событие CTRL немедленно
                NvEventQueueActivity.getInstance().sendCTRL();
                
                // Добавляем повторный вызов через небольшую задержку для надежности
                new Handler().postDelayed(() -> {
                    NvEventQueueActivity.getInstance().sendCTRL();
                }, 100);
            }
        });
        
        hud_g = aactivity.findViewById(R.id.imageView7);
        hud_g.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                
                // Отправляем событие G немедленно
                NvEventQueueActivity.getInstance().sendG();
                
                // Добавляем повторный вызов через небольшую задержку для надежности
                new Handler().postDelayed(() -> {
                    NvEventQueueActivity.getInstance().sendG();
                }, 100);
            }
        });

        // Инициализация кнопки меню действий
        View actionsButton = aactivity.findViewById(R.id.actionsMenuButton);
        actionsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                NvEventQueueActivity.getInstance().showActionsMenu();
            }
        });

        hud_online.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                openTab();
            }
        });
    }

    public void UpdateHudInfo(int health, int armour, int hunger, int weaponid, int ammo, int ammoinclip, int playerid, int money, int wanted, int level)
    {
        hud_health.setProgress(health);
        hud_armour.setProgress(armour);
        hud_health_t.setText(Integer.toString(health));
        hud_armour_t.setText(Integer.toString(armour));

        // fix random eat progress
        if(hunger > 100) {
            hud_hunger.setProgress(100);
            hud_hunger_t.setText("100");
        } else if(hunger < 0) {
            hud_hunger.setProgress(0);
            hud_hunger_t.setText("0");
        } else {
            hud_hunger.setProgress(hunger);
            hud_hunger_t.setText(Integer.toString(hunger));
        }

        // fix 0/0 showing
        if(weaponid == 0) {
            hud_ammo_layout.setVisibility(View.INVISIBLE);

            hud_ammo.setText("/0");
            hud_ammoinclip.setText("0");
        } else {
            hud_ammo_layout.setVisibility(View.VISIBLE);

            hud_ammoinclip.setText(String.valueOf(ammoinclip));
            hud_ammo.setText("/" + String.valueOf(ammo - ammoinclip));
        }

        // Обновление отображения онлайна с правильным склонением
        String onlineText = String.format("%d", playerid);
        hud_online_text.setText(onlineText);
        
        // Обновляем текст максимального количества игроков
        TextView maxPlayersText = activity.findViewById(R.id.hud_online_max);
        if (maxPlayersText != null) {
            maxPlayersText.setText("/1000");
        }

        // Обработка денег - используем простой подход как в примере Brilliant
        if (money != currentDisplayedMoney) {
            // Преобразуем int в long с учетом возможных отрицательных значений
            long moneyLong = money < 0 ? ((long)money & 0xFFFFFFFFL) : (long)money;
            
            // Обновляем отображение денег
            updateMoneyDisplay(moneyLong);
            currentDisplayedMoney = money;
        }

        int id = activity.getResources().getIdentifier(new Formatter().format("weapon_%d", Integer.valueOf(weaponid)).toString(), "drawable", activity.getPackageName());
        hud_weapon.setImageResource(id);

        hud_weapon.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                NvEventQueueActivity.getInstance().onWeaponChanged();
            }
        });
        if(wanted > 5) wanted = 5;
        for (int i2 = 0; i2 < wanted; i2++) {
            hud_wanted.get(i2).setBackgroundResource(R.drawable.ic_y_star);
        }
        
        // Обновляем время с секундами
        hud_time.setText(new SimpleDateFormat("HH:mm:ss").format(Calendar.getInstance().getTime()));
        hud_date.setText(new SimpleDateFormat("dd.MM.yyyy").format(Calendar.getInstance().getTime()));
        
        // Устанавливаем уровень
        this.playerLevel = level;
        hud_level.setText("Lvl " + level);
    }
    
    /**
     * Запускает анимацию изменения денег
     * @param startValue начальная сумма
     * @param endValue конечная сумма
     */
    private void startMoneyAnimation(long startValue, long endValue) {
        // Устанавливаем флаг запущенной анимации
        isMoneyAnimationRunning = true;
        
        // Проверка на ограничения значений
        if (startValue < 0) startValue = 0;
        if (endValue < 0) endValue = 0;
        if (startValue > MAX_MONEY_VALUE) startValue = MAX_MONEY_VALUE;
        if (endValue > MAX_MONEY_VALUE) endValue = MAX_MONEY_VALUE;
        
        // Сохраняем корректные значения для расчета
        final long realStartValue = startValue;
        final long realEndValue = endValue;
        
        // Определяем шаг изменения и скорость в зависимости от разницы
        final long difference = realEndValue - realStartValue;
        final int animationDuration = 3000; // Увеличиваем длительность анимации до 3 сек
        final int updateInterval = 50; // Интервал обновления (50 мс)
        
        // Рассчитываем количество шагов и шаг изменения
        final int steps = animationDuration / updateInterval;
        final double stepValue = (double) difference / steps;
        
        // Запускаем анимацию на таймере
        moneyAnimationTimer = new Timer();
        moneyAnimationTimer.scheduleAtFixedRate(new TimerTask() {
            private int step = 0;
            private long currentValue = realStartValue;
            
            @Override
            public void run() {
                if (step >= steps) {
                    // Анимация завершена
                    activity.runOnUiThread(() -> {
                        lastMoneyValue = realEndValue;
                        updateMoneyDisplay(realEndValue);
                    });
                    stopMoneyAnimation();
                    return;
                }
                
                // Увеличиваем текущее значение на шаг
                step++;
                currentValue = realStartValue + Math.round(stepValue * step);
                
                // Проверка на ограничения
                if (currentValue < 0) currentValue = 0;
                if (currentValue > MAX_MONEY_VALUE) currentValue = MAX_MONEY_VALUE;
                
                // Обновляем UI в главном потоке
                final long finalCurrentValue = currentValue;
                activity.runOnUiThread(() -> {
                    updateMoneyDisplay(finalCurrentValue);
                });
            }
        }, 0, updateInterval);
    }
    
    /**
     * Останавливает текущую анимацию изменения денег
     */
    private void stopMoneyAnimation() {
        if (moneyAnimationTimer != null) {
            moneyAnimationTimer.cancel();
            moneyAnimationTimer = null;
            isMoneyAnimationRunning = false;
        }
    }
    
    /**
     * Обновляет отображение денег с разделителями
     */
    private void updateMoneyDisplay(long value) {
        // Используем простой и надежный подход с DecimalFormat
        if (value > 999999999) {
            value = 999999999; // Ограничиваем максимальное значение для безопасности
        }
        
        String formattedValue = new DecimalFormat("###,###,###").format(value);
        hud_money.setText(formattedValue);
    }
    
    public void setPlayerLevel(int level) {
        this.playerLevel = level;
        if (hud_level != null) {
            hud_level.setText("Lvl " + level);
        }
    }

    private void openTab()
    {
        Timer t = new Timer();
        t.schedule(new TimerTask(){
            @Override
            public void run() {
                NvEventQueueActivity.getInstance().showTab();
            }
        }, 200L);
    }
    
    public void showAllButt()
    {
        // Показываем все кнопки в обеих секциях
        LinearLayout topButtonsLayout = activity.findViewById(R.id.top_buttons_layout);
        LinearLayout bottomButtonsLayout = activity.findViewById(R.id.bottom_buttons_layout);
        
        Utils.ShowLayout(topButtonsLayout, true);
        Utils.ShowLayout(bottomButtonsLayout, true);
        Utils.ShowLayout(hud_y, true);
        Utils.ShowLayout(hud_n, true);
        Utils.ShowLayout(hud_h, true);
        Utils.ShowLayout(hud_ctrl, true);
        Utils.ShowLayout(hud_g, true);
    }

    public void hideAllButt()
    {
        hud_sr.setChecked(false);
        
        // Скрываем все кнопки в обеих секциях
        LinearLayout topButtonsLayout = activity.findViewById(R.id.top_buttons_layout);
        LinearLayout bottomButtonsLayout = activity.findViewById(R.id.bottom_buttons_layout);
        
        Utils.HideLayout(topButtonsLayout, true);
        Utils.HideLayout(bottomButtonsLayout, true);
        Utils.HideLayout(hud_y, true);
        Utils.HideLayout(hud_n, true);
        Utils.HideLayout(hud_h, true);
        Utils.HideLayout(hud_ctrl, true);
        Utils.HideLayout(hud_g, true);
    }

    public void ShowHud() {
        HideVehButtonG();
        hideAllButt();
        hud_sr.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if (buttonView.isChecked()) {
                    hud_b_sr = true;
                    showAllButt();
                } else {
                    hideAllButt();
                    hud_b_sr = false;
                }
            }
        });
        Utils.ShowLayout(hud_layout, true);
    }
    
//    public void ShowVehButton() {
//        ((ImageView)hud_alt).setImageResource(R.drawable.b_ctrl);
//        bt_is_ctrl = true;
//    }
//
//    public void HideVehButton() {
//        bt_is_ctrl = false;
//        ((ImageView)hud_alt).setImageResource(R.drawable.b_alt);
//    }

    public void ShowTabButton() {
        ShowHud();
        Utils.ShowLayout(hud_online, true);
    }

    public void HideTabButton() {
        HideHud();
        Utils.HideLayout(hud_online, true);
    }

    public void ShowVehButtonG() {
        hud_seat.setVisibility(View.VISIBLE);
    }

    public void HideVehButtonG() {
        hud_seat.setVisibility(View.GONE);
    }

    public void ShowLogo(boolean isShow) {
        if(isShow == true) {
            hud_hide_logo = false;
            Utils.ShowLayout(hud_x2, true);
            Utils.ShowLayout(hud_online, true);
            Utils.ShowLayout(brp_hud_logo, true);
        } else HideLogo();
    }

    public void ShowTimeData() {
        hud_hide_data_time = true;
        Utils.ShowLayout(brp_hud_date, true);
        Utils.ShowLayout(brp_hud_time, true);
        Utils.ShowLayout(brp_hud_level, true);
    }

    public void HideTimeData() {
        hud_hide_data_time = false;
        Utils.HideLayout(brp_hud_date, true);
        Utils.HideLayout(brp_hud_time, true);
        Utils.HideLayout(brp_hud_level, true);
    }

    public void HideLogo() {
        hud_hide_logo = false;
        Utils.HideLayout(hud_x2, true);
        Utils.HideLayout(hud_online, true);
        Utils.HideLayout(brp_hud_logo, true);
    }

    public void HideHud() {
        // При скрытии HUD останавливаем все анимации
        stopMoneyAnimation();
        Utils.HideLayout(hud_layout, true);
    }

    public void UpdatePlayerCount(int currentPlayers, int maxPlayers) {
        if (hud_online_text != null) {
            hud_online_text.setText(Integer.toString(currentPlayers));
        }
        
        TextView maxPlayersText = activity.findViewById(R.id.hud_online_max);
        if (maxPlayersText != null) {
            maxPlayersText.setText("/1000");
        }
    }
}
