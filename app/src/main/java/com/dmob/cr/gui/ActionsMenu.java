package com.dmob.cr.gui;

import android.content.Context;
import android.view.MotionEvent;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageButton;
import android.widget.Toast;

import androidx.cardview.widget.CardView;
import androidx.constraintlayout.widget.ConstraintLayout;

import com.dmob.cr.R;
import com.nvidia.devtech.NvEventQueueActivity;

import java.io.UnsupportedEncodingException;

/**
 * Меню быстрых действий, которое отображается поверх игры без приостановки геймплея
 */
public class ActionsMenu {

    private static final String TAG = "ActionsMenu";
    
    // Статический экземпляр для использования в приложении
    private static ActionsMenu instance;
    
    private Context context;
    private View actionsMenuView;
    private CardView cardNavigator, cardMenu;
    private CardView cardInventory, cardAnimations, cardDonate, cardCars;
    private CardView cardHideChat, cardShowChat; // Новые кнопки для управления чатом
    private ImageButton buttonClose;
    private Animation buttonClickAnimation;
    private Animation buttonReleaseAnimation;
    
    /**
     * Конструктор
     */
    public ActionsMenu(Context context) {
        this.context = context;
        initUI();
    }
    
    /**
     * Показать меню действий
     */
    public void show() {
        if (actionsMenuView != null) {
            actionsMenuView.setVisibility(View.VISIBLE);
            
            // Анимация появления
            actionsMenuView.startAnimation(AnimationUtils.loadAnimation(context, R.anim.fade_in));
        }
    }
    
    /**
     * Скрыть меню действий
     */
    public void hide() {
        if (actionsMenuView != null) {
            // Анимация исчезновения
            Animation fadeOut = AnimationUtils.loadAnimation(context, R.anim.fade_out);
            fadeOut.setAnimationListener(new Animation.AnimationListener() {
                @Override
                public void onAnimationStart(Animation animation) {}
                
                @Override
                public void onAnimationEnd(Animation animation) {
                    actionsMenuView.setVisibility(View.GONE);
                }
                
                @Override
                public void onAnimationRepeat(Animation animation) {}
            });
            
            actionsMenuView.startAnimation(fadeOut);
        }
    }
    
    /**
     * Инициализация UI элементов
     */
    private void initUI() {
        // Получаем View меню из активности
        actionsMenuView = ((android.app.Activity)context).findViewById(R.id.actions_menu_container);
        if (actionsMenuView == null) {
            return;
        }
        
        // Инициализация анимаций для кнопок
        buttonClickAnimation = AnimationUtils.loadAnimation(context, R.anim.btn_click);
        buttonReleaseAnimation = AnimationUtils.loadAnimation(context, R.anim.btn_release);
        
        // Находим все элементы управления
        buttonClose = actionsMenuView.findViewById(R.id.buttonClose);
        cardNavigator = actionsMenuView.findViewById(R.id.cardNavigator);
        cardMenu = actionsMenuView.findViewById(R.id.cardMenu);
        cardInventory = actionsMenuView.findViewById(R.id.cardInventory);
        cardAnimations = actionsMenuView.findViewById(R.id.cardAnimations);
        cardDonate = actionsMenuView.findViewById(R.id.cardDonate);
        cardCars = actionsMenuView.findViewById(R.id.cardCars);
        cardHideChat = actionsMenuView.findViewById(R.id.cardHideChat); // Новая кнопка скрыть чат
        cardShowChat = actionsMenuView.findViewById(R.id.cardShowChat); // Новая кнопка показать чат
        
        // Настраиваем слушатель нажатий для фона (закрытие при нажатии вне элементов)
        actionsMenuView.setOnClickListener(v -> hide());
        
        // Предотвращаем закрытие при нажатии на элементы внутри меню
        View topBar = actionsMenuView.findViewById(R.id.topBar);
        topBar.setOnClickListener(v -> {
            // Ничего не делаем, просто перехватываем клик
        });
        
        View gridActions = actionsMenuView.findViewById(R.id.gridActions);
        gridActions.setOnClickListener(v -> {
            // Ничего не делаем, просто перехватываем клик
        });
        
        // Настраиваем слушатели нажатий для кнопки закрытия
        buttonClose.setOnTouchListener(new View.OnTouchListener() {
            private float startX, startY;
            private boolean isClickValid = true;
            private static final float CLICK_ACTION_THRESHOLD = 10;
            
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        startX = event.getX();
                        startY = event.getY();
                        isClickValid = true;
                        v.startAnimation(buttonClickAnimation);
                        return true;
                        
                    case MotionEvent.ACTION_MOVE:
                        if (isClickValid && (Math.abs(event.getX() - startX) > CLICK_ACTION_THRESHOLD || 
                                            Math.abs(event.getY() - startY) > CLICK_ACTION_THRESHOLD)) {
                            // Пользователь передвинул палец слишком далеко, это не клик
                            isClickValid = false;
                            v.clearAnimation();
                        }
                        return true;
                        
                    case MotionEvent.ACTION_UP:
                        if (isClickValid) {
                            v.startAnimation(buttonReleaseAnimation);
                            hide();
                        }
                        return true;
                        
                    case MotionEvent.ACTION_CANCEL:
                        isClickValid = false;
                        v.clearAnimation();
                        return true;
                }
                return false;
            }
        });
        
        // Настраиваем слушатели нажатий для всех карточек меню
        setupCardTouchListener(cardNavigator, "/gps");
        setupCardTouchListener(cardMenu, "/mm");
        setupCardTouchListener(cardInventory, "/inv");
        setupCardTouchListener(cardAnimations, "/anim");
        setupCardTouchListener(cardDonate, "/donate");
        setupCardTouchListener(cardCars, "/car");
        
        // Настраиваем слушатели для кнопок управления чатом
        setupChatCardTouchListener(cardHideChat, false); // Скрыть чат
        setupChatCardTouchListener(cardShowChat, true);  // Показать чат
    }
    
    /**
     * Настраивает обработчик нажатий для карточки с анимацией
     * @param card карточка
     * @param command команда для выполнения
     */
    private void setupCardTouchListener(CardView card, final String command) {
        card.setOnTouchListener(new View.OnTouchListener() {
            private float startX, startY;
            private boolean isClickValid = true;
            private static final float CLICK_ACTION_THRESHOLD = 10;
            
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        startX = event.getX();
                        startY = event.getY();
                        isClickValid = true;
                        v.startAnimation(buttonClickAnimation);
                        return true;
                        
                    case MotionEvent.ACTION_MOVE:
                        if (isClickValid && (Math.abs(event.getX() - startX) > CLICK_ACTION_THRESHOLD || 
                                            Math.abs(event.getY() - startY) > CLICK_ACTION_THRESHOLD)) {
                            // Пользователь передвинул палец слишком далеко, это не клик
                            isClickValid = false;
                            v.clearAnimation();
                        }
                        return true;
                        
                    case MotionEvent.ACTION_UP:
                        if (isClickValid) {
                            v.startAnimation(buttonReleaseAnimation);
                            executeCommand(command);
                        }
                        return true;
                        
                    case MotionEvent.ACTION_CANCEL:
                        isClickValid = false;
                        v.clearAnimation();
                        return true;
                }
                return false;
            }
        });
    }
    
    /**
     * Настраивает обработчик нажатий для карточки управления чатом
     * @param card карточка
     * @param showChat true - показать чат, false - скрыть чат
     */
    private void setupChatCardTouchListener(CardView card, final boolean showChat) {
        card.setOnTouchListener(new View.OnTouchListener() {
            private float startX, startY;
            private boolean isClickValid = true;
            private static final float CLICK_ACTION_THRESHOLD = 10;
            
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                switch (event.getAction()) {
                    case MotionEvent.ACTION_DOWN:
                        startX = event.getX();
                        startY = event.getY();
                        isClickValid = true;
                        v.startAnimation(buttonClickAnimation);
                        return true;
                        
                    case MotionEvent.ACTION_MOVE:
                        if (isClickValid && (Math.abs(event.getX() - startX) > CLICK_ACTION_THRESHOLD || 
                                            Math.abs(event.getY() - startY) > CLICK_ACTION_THRESHOLD)) {
                            // Пользователь передвинул палец слишком далеко, это не клик
                            isClickValid = false;
                            v.clearAnimation();
                        }
                        return true;
                        
                    case MotionEvent.ACTION_UP:
                        if (isClickValid) {
                            v.startAnimation(buttonReleaseAnimation);
                            toggleChat(showChat);
                        }
                        return true;
                        
                    case MotionEvent.ACTION_CANCEL:
                        isClickValid = false;
                        v.clearAnimation();
                        return true;
                }
                return false;
            }
        });
    }
    
    /**
     * Метод для управления отображением чата
     * @param show true - показать чат, false - скрыть чат
     */
    private void toggleChat(boolean show) {
        NvEventQueueActivity nvInstance = NvEventQueueActivity.getInstance();
        if (nvInstance != null) {
            if (show) {
                nvInstance.showChat();
                Toast.makeText(context, "Чат отображен", Toast.LENGTH_SHORT).show();
            } else {
                nvInstance.hideChat();
                Toast.makeText(context, "Чат скрыт", Toast.LENGTH_SHORT).show();
            }
        }
        
        // Скрываем меню после выбора действия
        hide();
    }
    
    /**
     * Метод для выполнения игровой команды
     * Здесь будет реализована логика отправки команды в игру
     * @param command команда для выполнения
     */
    private void executeCommand(String command) {
        try {
            // Отправляем команду в игру через NvEventQueueActivity
            NvEventQueueActivity nvInstance = NvEventQueueActivity.getInstance();
            if (nvInstance != null) {
                nvInstance.sendClick(command.getBytes("windows-1251"));
                Toast.makeText(context, "Выполнение команды: " + command, Toast.LENGTH_SHORT).show();
            }
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
            Toast.makeText(context, "Ошибка при выполнении команды: " + e.getMessage(), Toast.LENGTH_SHORT).show();
        }
        
        // Скрываем меню после выбора действия
        hide();
    }
    
    /**
     * Статический метод для показа меню действий из любого места в игре
     */
    public static void showActionsMenu(Context context) {
        if (instance == null) {
            instance = new ActionsMenu(context);
        } else {
            // Обновляем контекст если нужно
            instance.context = context;
        }
        instance.show();
    }
    
    /**
     * Статический метод для скрытия меню действий
     */
    public static void hideActionsMenu() {
        if (instance != null) {
            instance.hide();
        }
    }
} 