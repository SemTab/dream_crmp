package com.dmob.launcher.activity;

import android.app.Dialog;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import androidx.appcompat.app.AppCompatActivity;

import com.dmob.Settings;
import com.dmob.cr.R;

import org.ini4j.Wini;

import java.io.File;
import java.io.IOException;

public class SettingsActivity extends AppCompatActivity {
    public Button back;
    public Button brp_launcher_reinstall;
    public EditText nickname;
    public ImageView imageViewTelegram;
    public ImageView imageViewVK;
    public ImageView imageViewDiscord;
    private Dialog changeNickDialog;
    private RadioGroup radioGroupFileCheck;
    private RadioButton fileCheckOn;
    private RadioButton fileCheckOff;
    private RadioGroup.OnCheckedChangeListener fileCheckListener;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_settings);
		
		Animation animation = AnimationUtils.loadAnimation(this, R.anim.button_click);
        back = (Button) findViewById(R.id.brp_launcher_settings_back);
        brp_launcher_reinstall = (Button) findViewById(R.id.brp_launcher_reinstall);
        nickname = (EditText) findViewById(R.id.brp_launcher_settings_nick);
        imageViewTelegram = (ImageView) findViewById(R.id.imageViewTelegram);
        imageViewVK = (ImageView) findViewById(R.id.imageViewVK);
        
        // Инициализация переключателя проверки файлов
        radioGroupFileCheck = (RadioGroup) findViewById(R.id.radioGroupFileCheck);
        fileCheckOn = (RadioButton) findViewById(R.id.brp_launcher_file_check_on);
        fileCheckOff = (RadioButton) findViewById(R.id.brp_launcher_file_check_off);

        // Создаем слушатель для RadioGroup
        fileCheckListener = new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                boolean skipFileCheck = (checkedId == R.id.brp_launcher_file_check_off);
                
                try {
                    Wini ws = new Wini(new File(Settings.path_settings));
                    ws.put("client", Settings.SKIP_FILES_CHECK, skipFileCheck ? "1" : "0");
                    ws.store();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                
                // Обновляем стиль кнопок
                updateFileCheckButtonStyles(skipFileCheck);
            }
        };

        Load();
        
        // Отключаем непосредственное редактирование поля ника
        nickname.setFocusable(false);
        nickname.setClickable(true);
        
        // Открываем диалог смены ника при нажатии на поле
        nickname.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                showChangeNickDialog();
            }
        });

        back.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                //v.startAnimation(animation);
                startActivity(new Intent(getApplicationContext(), MainActivity.class));
                finish();
            }
        });

        brp_launcher_reinstall.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                v.startAnimation(animation);
                startActivity(new Intent(getApplicationContext(), PreLoadActivity.class));
                finish();
            }
        });

        imageViewTelegram.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                v.startAnimation(animation);
                Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(Settings.URL_TG));
                startActivity(browserIntent);
            }
        });
        imageViewVK.setOnClickListener(new OnClickListener() {
            public void onClick(View v) {
                v.startAnimation(animation);
                Intent browserIntent = new Intent(Intent.ACTION_VIEW, Uri.parse(Settings.URL_VK));
                startActivity(browserIntent);
            }
        });
        
        // Устанавливаем слушатель для RadioGroup
        radioGroupFileCheck.setOnCheckedChangeListener(fileCheckListener);
    }
    
    /**
     * Показывает диалог изменения ника
     */
    private void showChangeNickDialog() {
        changeNickDialog = new Dialog(this);
        changeNickDialog.requestWindowFeature(Window.FEATURE_NO_TITLE);
        changeNickDialog.setContentView(R.layout.item_change_nik);
        
        // Устанавливаем ширину диалога
        Window window = changeNickDialog.getWindow();
        if (window != null) {
            window.setLayout(WindowManager.LayoutParams.MATCH_PARENT, WindowManager.LayoutParams.WRAP_CONTENT);
        }
        
        // Находим элементы управления в диалоге
        final EditText dialogNickInput = changeNickDialog.findViewById(R.id.dialog_nick_input);
        Button dialogCancelButton = changeNickDialog.findViewById(R.id.dialog_nick_cancel);
        Button dialogSaveButton = changeNickDialog.findViewById(R.id.dialog_nick_save);
        
        // Устанавливаем текущий ник в поле ввода
        dialogNickInput.setText(nickname.getText());
        
        // Обработка кнопки Отмена
        dialogCancelButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                changeNickDialog.dismiss();
            }
        });
        
        // Обработка кнопки Сохранить
        dialogSaveButton.setOnClickListener(new OnClickListener() {
            @Override
            public void onClick(View v) {
                String newNick = dialogNickInput.getText().toString();
                if (!newNick.isEmpty()) {
                    // Устанавливаем новое значение в основное поле ника
                    nickname.setText(newNick);
                    
                    // Сохраняем новое значение в настройки
                    try {
                        Wini ws = new Wini(new File(Settings.path_settings));
                        ws.put("client", "name", newNick);
                        ws.store();
                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                    
                    // Закрываем диалог
                    changeNickDialog.dismiss();
                }
            }
        });
        
        changeNickDialog.show();
    }

    // Добавляем новый метод для обновления стилей кнопок
    private void updateFileCheckButtonStyles(boolean skipFileCheck) {
        if (skipFileCheck) {
            fileCheckOn.setBackgroundResource(R.color.darkButton);
            fileCheckOff.setBackgroundResource(R.color.colorAccent);
        } else {
            fileCheckOn.setBackgroundResource(R.color.colorAccent);
            fileCheckOff.setBackgroundResource(R.color.darkButton);
        }
    }

    private void Load() {
        try {
            Wini w = new Wini(new File(Settings.path_settings));
            nickname.setText(w.get("client", "name"));
            
            // Загружаем настройку проверки файлов
            String skipFileCheck = w.get("client", Settings.SKIP_FILES_CHECK);
            if (skipFileCheck == null) {
                skipFileCheck = "0"; // Значение по умолчанию
            }
            boolean isSkipFileCheck = "1".equals(skipFileCheck);
            
            // Устанавливаем состояние переключателя без вызова слушателя
            radioGroupFileCheck.setOnCheckedChangeListener(null);
            if (isSkipFileCheck) {
                fileCheckOff.setChecked(true);
            } else {
                fileCheckOn.setChecked(true);
            }
            
            // Обновляем стили кнопок
            updateFileCheckButtonStyles(isSkipFileCheck);
            
            // Восстанавливаем слушателя, если он уже создан
            if (fileCheckListener != null) {
                radioGroupFileCheck.setOnCheckedChangeListener(fileCheckListener);
            }
            
            w.store();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
} 