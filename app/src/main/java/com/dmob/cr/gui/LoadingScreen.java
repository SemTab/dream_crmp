package com.dmob.cr.gui;

import android.app.Activity;
import android.media.MediaPlayer;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageButton;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.nvidia.devtech.NvEventQueueActivity;
import com.dmob.cr.gui.util.Damp;
import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class LoadingScreen {
    public Activity activity;
    public Animation animation;
    public ConstraintLayout main_layout;
    public TextView status1;
    private Button repeat;
    private TextView factsTextView;
    private List<String> gameFactsList;
    private Random random;
    private MediaPlayer mediaPlayer;
    private Timer factsTimer;
    private TimerTask factsTimerTask;
    private int currentFactIndex = 0;
    private ImageButton factsPrevButton;
    private ImageButton factsNextButton;
    private Animation factsInAnimation;
    private Animation factsOutAnimation;
    private boolean isFactAnimationRunning = false;

    public LoadingScreen(Activity aactivity) {
        activity = aactivity;
        Animation animation = AnimationUtils.loadAnimation(aactivity, R.anim.button_click);
        random = new Random();

        main_layout = aactivity.findViewById(R.id.bloading_screen);
        main_layout.setVisibility(View.GONE);

        status1 = aactivity.findViewById(R.id.textView2);
        repeat = aactivity.findViewById(R.id.button);
        factsTextView = aactivity.findViewById(R.id.facts_text);
        
        // Инициализируем кнопки навигации по фактам
        factsPrevButton = aactivity.findViewById(R.id.facts_prev_button);
        factsNextButton = aactivity.findViewById(R.id.facts_next_button);
        
        // Загружаем анимации
        factsInAnimation = AnimationUtils.loadAnimation(aactivity, R.anim.facts_in);
        factsOutAnimation = AnimationUtils.loadAnimation(aactivity, R.anim.facts_out);
        
        // Настраиваем слушатели анимации
        factsOutAnimation.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {
                isFactAnimationRunning = true;
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                // Показываем новый факт с анимацией входа
                factsTextView.setText(gameFactsList.get(currentFactIndex));
                factsTextView.startAnimation(factsInAnimation);
            }

            @Override
            public void onAnimationRepeat(Animation animation) {
            }
        });
        
        factsInAnimation.setAnimationListener(new Animation.AnimationListener() {
            @Override
            public void onAnimationStart(Animation animation) {
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                isFactAnimationRunning = false;
            }

            @Override
            public void onAnimationRepeat(Animation animation) {
            }
        });
        
        // Настраиваем обработчики нажатий на кнопки
        factsPrevButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!isFactAnimationRunning && gameFactsList != null && !gameFactsList.isEmpty()) {
                    showPreviousFact();
                }
            }
        });
        
        factsNextButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (!isFactAnimationRunning && gameFactsList != null && !gameFactsList.isEmpty()) {
                    showNextFact();
                }
            }
        });

        initGameFacts();

        repeat.setText("Retry");
        repeat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                view.startAnimation(animation);
                showServerSelector();
            }
        });
    }
    
    private void initGameFacts() {
        gameFactsList = new ArrayList<>();
        gameFactsList.add("Первым проектом в CRMP Mobile стал URMP.");
        gameFactsList.add("Проект Dream Mobile появился в 2023 году после закрытия Draim Mobile. Однако вскоре разработка была приостановлена. В 2024 году команда приняла решение возродить идею, и с этого момента начался активный этап создания нового проекта.");
        gameFactsList.add("Владелец проекта - SemTab");
        gameFactsList.add("Кто это читает?");
        gameFactsList.add("Реверсить нужно не игру, а свои мозги");
        gameFactsList.add("В игре более 100 транспортных средств");
        gameFactsList.add("Разработка проекта заняла более года");
        gameFactsList.add("Карта игрового мира составляет более 6 квадратных километров");
    }

    private void showRandomFact() {
        if (gameFactsList != null && !gameFactsList.isEmpty()) {
            int randomIndex = random.nextInt(gameFactsList.size());
            currentFactIndex = randomIndex;
            factsTextView.setText(gameFactsList.get(randomIndex));
        }
    }
    
    private void showPreviousFact() {
        if (gameFactsList != null && !gameFactsList.isEmpty()) {
            // Начинаем анимацию выхода текущего факта
            factsTextView.startAnimation(factsOutAnimation);
            
            // Уменьшаем индекс и проверяем границы
            currentFactIndex--;
            if (currentFactIndex < 0) {
                currentFactIndex = gameFactsList.size() - 1;
            }
        }
    }
    
    private void showNextFact() {
        if (gameFactsList != null && !gameFactsList.isEmpty()) {
            // Начинаем анимацию выхода текущего факта
            factsTextView.startAnimation(factsOutAnimation);
            
            // Увеличиваем индекс и проверяем границы
            currentFactIndex++;
            if (currentFactIndex >= gameFactsList.size()) {
                currentFactIndex = 0;
            }
        }
    }
    
    private void startFactsRotation() {
        stopFactsRotation(); // Остановка предыдущего таймера, если он был запущен
        
        factsTimer = new Timer();
        factsTimerTask = new TimerTask() {
            @Override
            public void run() {
                // Так как таймер работает не в UI потоке,
                // нужно выполнить обновление UI в основном потоке
                activity.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        if (!isFactAnimationRunning) {
                            showNextFact();
                        }
                    }
                });
            }
        };
        
        // Показываем первый факт сразу
        showRandomFact();
        // Запускаем таймер для смены фактов каждые 5 секунд (5000 мс)
        factsTimer.schedule(factsTimerTask, 5000, 5000);
    }
    
    private void stopFactsRotation() {
        if (factsTimer != null) {
            factsTimer.cancel();
            factsTimer = null;
        }
        
        if (factsTimerTask != null) {
            factsTimerTask.cancel();
            factsTimerTask = null;
        }
    }
    
    private void startBackgroundMusic() {
        try {
            stopBackgroundMusic(); // Остановка предыдущей музыки, если она играет
            
            mediaPlayer = MediaPlayer.create(activity, R.raw.loading);
            mediaPlayer.setLooping(true);
            mediaPlayer.setVolume(0.5f, 0.5f);
            mediaPlayer.start();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    private void stopBackgroundMusic() {
        if (mediaPlayer != null) {
            try {
                if (mediaPlayer.isPlaying()) {
                    mediaPlayer.stop();
                }
                mediaPlayer.release();
                mediaPlayer = null;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    private void showServerSelector() {
        NvEventQueueActivity.getInstance().showIngameServerSelector();
    }

    public void UpdateScreen(int status)
    {
     /**
	 CONNECTING, 0
	 CONNECTED, 1
	 SERVER_CLOSED_CONNECTION, 2
	 LOADED, 3
	 LOADING, 4
	 BANNED, 5
	 CONNECTION_LOST, 6
	 CONNECTION_ATTEMPT_FAILED, 7
     FULL_SERVER, 8
     INVALID_PASSWORD 9
     */

        if(status == 0) {
            status1.setText("Подключение к серверу...");
        } else if(status == 1) {
            status1.setText("Вход в игру...");
            HideLoading();
        } else if(status == 2) {
            status1.setText("Потеряно соединение с сервером...");
        } else if(status == 3) {
            status1.setText("Загрузка завершена...");
        } else if(status == 4) {
            ShowLoading();
            status1.setText("Загрузка игры...");
        } else if(status == 5) {
            status1.setText("Вы были заблокированы сервером");
            repeat.setVisibility(View.VISIBLE);
        } else if(status == 6) {
            status1.setText("Потеряно соединение с сервером...");
        } else if(status == 7) {
            status1.setText("Попытка подключения неудачна");
        } else if(status == 8) {
            status1.setText("Сервер полон");
        } else if(status == 9) {
            status1.setText("Неверный пароль подключения к серверу");
            repeat.setVisibility(View.VISIBLE);
        } else HideLoading();
    }

    public void ShowLoading() {
        Utils.ShowLayout(main_layout, true);
        startFactsRotation();
        startBackgroundMusic();
    }

    public void HideLoading() {
        Utils.HideLayout(main_layout, true);
        stopFactsRotation();
        stopBackgroundMusic();
    }
    
    // Вызываем при уничтожении Activity
    public void onDestroy() {
        stopFactsRotation();
        stopBackgroundMusic();
    }
}
