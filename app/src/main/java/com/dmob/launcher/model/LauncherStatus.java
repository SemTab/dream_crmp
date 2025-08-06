package com.dmob.launcher.model;

import com.google.gson.annotations.SerializedName;

/**
 * Модель, представляющая статус лаунчера
 */
public class LauncherStatus {
    
    @SerializedName("enabled")
    private boolean enabled;
    
    @SerializedName("message")
    private String message;
    
    /**
     * Конструктор
     *
     * @param enabled статус лаунчера (true - включен, false - отключен)
     * @param message сообщение о причине отключения
     */
    public LauncherStatus(boolean enabled, String message) {
        this.enabled = enabled;
        this.message = message;
    }
    
    /**
     * Проверяет, включен ли лаунчер
     *
     * @return true если лаунчер включен, false если отключен
     */
    public boolean isEnabled() {
        return enabled;
    }
    
    /**
     * Получает сообщение о причине отключения лаунчера
     *
     * @return сообщение с причиной отключения
     */
    public String getMessage() {
        return message;
    }
} 