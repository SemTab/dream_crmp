package com.dmob.cr.gui.chatedgar;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.os.Handler;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.animation.DecelerateInterpolator;
import android.view.animation.ScaleAnimation;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;
import java.io.UnsupportedEncodingException;

import com.dmob.launcher.other.Lists;
import com.dmob.cr.R;
import com.dmob.cr.gui.keyboard.KeyBoard;
import com.dmob.cr.gui.util.CustomRecyclerView;
import com.dmob.cr.gui.util.Utils;
import com.nvidia.devtech.NvEventQueueActivity;
public class ChatManager {
    public Activity aactivity;
    private static ChatManager instance;
    public static int statusChat = 1;
    public FrameLayout chat;
    public CustomRecyclerView msg_messages;
    public ArrayList<String> msglist = new ArrayList<>();
    public ChatAdapter chatAdapter;
    public ImageView msg_box;
    public static boolean isChat = false;

    public native void sendChatMessages(byte[] messages);
    
    // Метод для конвертации текста из UTF-8 в windows-1251 для совместимости с нативным кодом
    private byte[] convertToWindows1251(byte[] utf8Data) {
        try {
            String utf8String = new String(utf8Data, "UTF-8");
            return utf8String.getBytes("windows-1251");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
            return utf8Data; // Возвращаем исходные данные в случае ошибки
        }
    }
    
    // Переопределение метода для работы с UTF-8
    public void sendChatMessagesUTF8(byte[] messages) {
        // Проверяем на специальные команды перед отправкой
        try {
            String text = new String(messages, "UTF-8");
            
            // Обработка специальных команд
            if (text.startsWith("/boombox") || 
                text.startsWith("/hudeditor") || 
                text.startsWith("/debug") || 
                text.startsWith("/dl") || 
                text.startsWith("/tab")) {
                
                // Отправляем команду напрямую в нативный код через NvEventQueueActivity
                // Это обходит стандартную обработку чата и отправляет команду напрямую в игру
                ((NvEventQueueActivity)aactivity).sendChatMessage(convertToWindows1251(messages));
                
                // Закрываем чат после отправки команды
                if (isChat) {
                    ChatClose();
                }
                return;
            }
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        
        // Если это не специальная команда, отправляем как обычное сообщение
        sendChatMessages(convertToWindows1251(messages));
        
        // Закрываем чат после отправки сообщения
        if (isChat) {
            ChatClose();
        }
    }
    
    public ChatManager(Activity activity){
        aactivity = activity;
        instance = this;
        chat = aactivity.findViewById(R.id.chat);
        msg_messages = aactivity.findViewById(R.id.msg_messages);
        msg_box = aactivity.findViewById(R.id.msg_box);

        msg_messages.setHasFixedSize(true);
        LinearLayoutManager layoutManager = new LinearLayoutManager(aactivity, LinearLayoutManager.VERTICAL, false);
        msg_messages.setLayoutManager(layoutManager);

        msglist = Lists.msglist;
        chatAdapter = new ChatAdapter(aactivity, msglist);
        msg_messages.setAdapter(chatAdapter);
        msg_messages.setVerticalScrollBarEnabled(false);
        msg_messages.setEnableScrolling(false);
        msg_box.setAlpha(0.0f);

        Utils.ShowLayout(chat, false);
    }

    public final void ChatOpen(){
        // Показываем чат
        Utils.ShowLayout(chat, true);
        
        msg_messages.setVerticalScrollBarEnabled(false); // Отключаем скроллбар, чтобы не мешал клавиатуре
        msg_messages.setEnableScrolling(true);
        if(statusChat == 3) {
            msg_messages.animate().alpha(1.0f).setDuration(500).setInterpolator(new android.view.animation.DecelerateInterpolator()).start();
        }
        msg_box.animate().alpha(1.0f).setDuration(500).setInterpolator(new android.view.animation.DecelerateInterpolator()).start();
        msg_box.clearAnimation();
        
        // Проверяем, что клавиатура инициализирована перед вызовом
        if (KeyBoard.getKeyBoard() != null) {
        KeyBoard.getKeyBoard().OpenKeyBoard(null);
        Log.i("keyboard", "Signal Open KeyBoard");
        } else {
            Log.e("edgar", "KeyBoard is not initialized!");
        }
        
        isChat = true;
    }

    public final void ChatClose() {
        msg_messages.setVerticalScrollBarEnabled(false);
        msg_messages.setEnableScrolling(false);
        if(statusChat == 3) {
            msg_messages.animate().alpha(0.0f).setDuration(500).setInterpolator(new android.view.animation.AccelerateInterpolator()).start();
        }
        msg_box.animate().alpha(0.0f).setDuration(500).setInterpolator(new android.view.animation.AccelerateInterpolator()).start();
        msg_box.clearAnimation();
        
        // Проверяем, что клавиатура инициализирована перед вызовом
        if (KeyBoard.getKeyBoard() != null) {
        KeyBoard.getKeyBoard().q();
        Log.i("edgar", "Signal Close KeyBoard");
        } else {
            Log.e("edgar", "KeyBoard is not initialized!");
        }
        
        isChat = false;
        
        // Скрываем фон чата с небольшой задержкой для завершения анимации
        new Handler().postDelayed(() -> Utils.ShowLayout(chat, false), 500);
    }

    public void setChatStatys(int i){
        if(i == 1){
            msg_messages.animate().alpha(1.0f).setDuration(300).start();
            statusChat = i;
        } else if(i == 3){
            msg_messages.animate().alpha(0.0f).setDuration(300).start();
            statusChat = i;
        }
    }

    public static ChatManager getChatManager(){
        return instance;
    }

    /**
     * Метод для исправления текста с неправильной кодировкой
     * @param text Текст, который может содержать неправильную кодировку
     * @return Исправленный текст с правильной кодировкой
     */
    private String fixEncoding(String text) {
        // Проверяем, содержит ли текст символы, которые могут указывать на проблемы с кодировкой
        if (text == null || text.isEmpty()) {
            return text;
        }

        // Символы, которые обычно указывают на проблемы с кодировкой
        boolean hasEncodingIssue = text.contains("Ð") || 
                                  text.contains("Ñ") || 
                                  text.contains("Â") ||
                                  text.contains("â") ||
                                  text.contains("ð");

        if (hasEncodingIssue) {
            try {
                // Пробуем разные комбинации кодировок
                // Вариант 1: если текст был закодирован в windows-1251, но прочитан как UTF-8
                byte[] bytes = text.getBytes("UTF-8");
                String attempt1 = new String(bytes, "windows-1251");
                
                // Вариант 2: если текст был закодирован в UTF-8, но прочитан как windows-1251
                byte[] bytes2 = text.getBytes("windows-1251");
                String attempt2 = new String(bytes2, "UTF-8");
                
                // Вариант 3: если текст был закодирован в ISO-8859-1, но прочитан как UTF-8
                byte[] bytes3 = text.getBytes("UTF-8");
                String attempt3 = new String(bytes3, "ISO-8859-1");
                
                // Выбираем вариант, который выглядит наиболее корректно
                // Простая эвристика: русский текст обычно содержит символы в определенном диапазоне кодов
                if (containsRussianChars(attempt1)) {
                    return attempt1;
                } else if (containsRussianChars(attempt2)) {
                    return attempt2;
                } else if (containsRussianChars(attempt3)) {
                    return attempt3;
                }
                
                // Если ни один из вариантов не выглядит правильным, возвращаем исходный текст
                return text;
            } catch (UnsupportedEncodingException e) {
                e.printStackTrace();
                return text; // В случае ошибки возвращаем исходный текст
            }
        }
        
        return text; // Если нет признаков проблем с кодировкой, возвращаем исходный текст
    }
    
    /**
     * Проверяет, содержит ли текст русские символы
     * @param text Текст для проверки
     * @return true, если текст содержит русские символы
     */
    private boolean containsRussianChars(String text) {
        if (text == null || text.isEmpty()) {
            return false;
        }
        
        // Проверяем, содержит ли строка символы из русского алфавита
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            // Русские буквы находятся в диапазоне Unicode от '\u0410' до '\u044F'
            if ((c >= '\u0410' && c <= '\u044F') || c == '\u0401' || c == '\u0451') {
                return true;
            }
        }
        return false;
    }

    public void AddChatMessage(String msg){
        // Исправляем возможные проблемы с кодировкой
        String fixedMsg = fixEncoding(msg);
        chatAdapter.addItem(fixedMsg);
    }

    public class ChatAdapter extends RecyclerView.Adapter<ChatAdapter.ChatViewHolder> {
        Context context;
        // писал код EDGAR 3.0
        // https://tapy.me/edgar
        ArrayList<String> chat_message;


        public ChatAdapter(Context context, ArrayList<String> chat_message){
            this.context = context;
            this.chat_message = chat_message;
        }

        @NonNull
        @Override
        public ChatViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View v = LayoutInflater.from(context).inflate(R.layout.chat_message, parent, false);
            return new ChatViewHolder(v);
        }

        @Override
        public void onBindViewHolder(@NonNull ChatViewHolder holder, int position) {
            String pon = String.valueOf(chat_message.get(position));
            int index = pon.indexOf("{");
            if(index == - 1) {
                holder.msg_driver.setBackgroundColor(Color.parseColor("#ffffff"));
            }else {
                // Проверяем длину строки для безопасной обработки индексов
                if (index + 7 <= pon.length()) {
                String firstEightChars = pon.substring(index + 1, index + 7);
                    try {
                holder.msg_driver.setBackgroundColor(Color.parseColor("#" + firstEightChars));
                    } catch (IllegalArgumentException e) {
                        // Если формат цвета некорректный, используем белый цвет
                        Log.e("ChatEncoding", "Invalid color format: " + firstEightChars, e);
                        holder.msg_driver.setBackgroundColor(Color.parseColor("#ffffff"));
                    }
                } else {
                    holder.msg_driver.setBackgroundColor(Color.parseColor("#ffffff"));
                }
                index = -1;
            }
            
            if(pon.isEmpty()) {
                holder.msg_driver.setVisibility(View.GONE);
            } else {
                holder.msg_driver.setVisibility(View.VISIBLE);
            }
            
            // Применяем преобразование цветов текста с учетом возможных проблем с кодировкой
            holder.msg.setText(Utils.transfromColors(pon));
            
            // Анимация появления сообщения
            Animation fadeIn = new ScaleAnimation(
                0.8f, 1.0f, // От 80% до 100% по X
                0.8f, 1.0f, // От 80% до 100% по Y
                Animation.RELATIVE_TO_SELF, 0.0f,
                Animation.RELATIVE_TO_SELF, 0.0f
            );
            fadeIn.setDuration(300);
            fadeIn.setInterpolator(new DecelerateInterpolator());
            
            // Применяем анимацию к корневому элементу
            holder.itemView.startAnimation(fadeIn);
        }

        @Override
        public int getItemCount() {
            return chat_message.size();
        }

        public class ChatViewHolder extends RecyclerView.ViewHolder {

            public TextView msg;
            public View msg_driver;

            public ChatViewHolder(View itemView) {
                super(itemView);
                msg = itemView.findViewById(R.id.msg_text);
                msg_driver = itemView.findViewById(R.id.msg_divider);
                msg.setOnClickListener(new View.OnClickListener() {
                    @Override
                    public void onClick(View view) {
                        // Проверяем, инициализирована ли клавиатура
                        if (KeyBoard.getKeyBoard() == null) {
                            // Если клавиатура не инициализирована, просто меняем состояние чата
                            if (!isChat) {
                                msg_messages.setVerticalScrollBarEnabled(true);
                                msg_messages.setEnableScrolling(true);
                                if(statusChat == 3) {
                                    msg_messages.animate().alpha(1.0f).setDuration(500).setInterpolator(new android.view.animation.DecelerateInterpolator()).start();
                                }
                                msg_box.animate().alpha(1.0f).setDuration(500).setInterpolator(new android.view.animation.DecelerateInterpolator()).start();
                                msg_box.clearAnimation();
                                isChat = true;
                            } else {
                                msg_messages.setVerticalScrollBarEnabled(false);
                                msg_messages.setEnableScrolling(false);
                                if(statusChat == 3) {
                                    msg_messages.animate().alpha(0.0f).setDuration(500).setInterpolator(new android.view.animation.AccelerateInterpolator()).start();
                                }
                                msg_box.animate().alpha(0.0f).setDuration(500).setInterpolator(new android.view.animation.AccelerateInterpolator()).start();
                                msg_box.clearAnimation();
                                isChat = false;
                                
                                // Скрываем фон чата с небольшой задержкой для завершения анимации
                                new Handler().postDelayed(() -> Utils.ShowLayout(chat, false), 500);
                            }
                            Log.e("edgar", "KeyBoard is not initialized when clicking on chat message!");
                        } else {
                            // Если клавиатура инициализирована, используем стандартные методы
                            if (!isChat) {
                            ChatOpen();
                            isChat = true;
                        } else {
                            ChatClose();
                            isChat = false;
                            }
                        }
                    }
                });
            }
        }

        public void addItem(String item) {
            aactivity.runOnUiThread(() -> {
                // Проверяем, не дублируется ли сообщение
                if (this.chat_message.size() > 0) {
                    String lastMessage = this.chat_message.get(this.chat_message.size() - 1);
                    // Если последнее сообщение совпадает с новым, не добавляем его
                    if (lastMessage.equals(item)) {
                        return;
                    }
                }
                
                if(this.chat_message.size() > 40){
                    this.chat_message.remove(0);
                    notifyItemRemoved(0);
                }
                
                // Удаляем лишние пробелы
                String cleanItem = item.trim();
                
                // Удаляем префиксы - и * в начале сообщения, если они есть
                if (cleanItem.startsWith("-") || cleanItem.startsWith("*")) {
                    cleanItem = cleanItem.substring(1).trim();
                }
                
                // Логирование для отладки кодировки
                Log.d("ChatEncoding", "Adding message: " + cleanItem);
                
                // Добавляем в список и обновляем UI
                this.chat_message.add(cleanItem);
                notifyItemInserted(this.chat_message.size() - 1);
                
                // Плавная прокрутка к последнему сообщению
                msg_messages.smoothScrollToPosition(this.chat_message.size() - 1);
            });
        }

        public void scrollItem() {
            // Плавная прокрутка к последнему сообщению
            msg_messages.smoothScrollToPosition(this.chat_message.size() - 1);
        }

    }
}
