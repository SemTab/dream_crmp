package com.dmob.launcher.adapter;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

/**
 * Класс для хранения элемента FAQ
 */
public class FaqInfo {
    @SerializedName("caption")
    @Expose
    public final String caption;
    
    @SerializedName("text")
    @Expose
    public final String text;
    
    public FaqInfo(String caption, String text) {
        this.caption = caption;
        this.text = text;
    }
    
    public String getCaption() {
        return caption;
    }
    
    public String getText() {
        return text;
    }
} 