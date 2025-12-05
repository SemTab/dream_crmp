package com.dmob.launcher.utils;

import android.app.AlertDialog;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Button;

import com.dmob.cr.R;

public class StorageWarningDialog {
    
    public interface OnDialogActionListener {
        void onCancel();
        void onClearCache();
    }
    
    public static void show(Context context, long requiredSpace, long availableSpace, OnDialogActionListener listener) {
        try {
            AlertDialog.Builder builder = new AlertDialog.Builder(context, android.R.style.Theme_Material_Dialog);
            
            // Создаем custom view для dialog
            LayoutInflater inflater = LayoutInflater.from(context);
            View dialogView = inflater.inflate(R.layout.dialog_storage_warning, null);
            
            // Находим элементы в layout
            TextView requiredText = dialogView.findViewById(R.id.storage_warning_required);
            TextView availableText = dialogView.findViewById(R.id.storage_warning_available);
            Button cancelButton = dialogView.findViewById(R.id.storage_warning_cancel);
            Button clearButton = dialogView.findViewById(R.id.storage_warning_clear);
            
            // Устанавливаем текст
            if (requiredText != null) {
                requiredText.setText(StorageUtils.formatBytes(requiredSpace));
            }
            
            if (availableText != null) {
                availableText.setText(StorageUtils.formatBytes(availableSpace));
            }
            
            long spaceToFree = requiredSpace - availableSpace;
            TextView spaceToFreeText = dialogView.findViewById(R.id.storage_warning_to_free);
            if (spaceToFreeText != null) {
                spaceToFreeText.setText(StorageUtils.formatBytes(spaceToFree));
            }
            
            builder.setView(dialogView);
            builder.setCancelable(false);
            
            AlertDialog dialog = builder.create();
            
            // Устанавливаем размер и позицию dialog
            if (dialog.getWindow() != null) {
                dialog.getWindow().setBackgroundDrawableResource(android.R.color.transparent);
            }
            
            // Обработчики кнопок
            if (cancelButton != null) {
                cancelButton.setOnClickListener(v -> {
                    dialog.dismiss();
                    if (listener != null) {
                        listener.onCancel();
                    }
                });
            }
            
            if (clearButton != null) {
                clearButton.setOnClickListener(v -> {
                    dialog.dismiss();
                    if (listener != null) {
                        listener.onClearCache();
                    }
                });
            }
            
            dialog.show();
            
        } catch (Exception e) {
            LogHelper.e(LogHelper.TAG_MAIN, "Error showing storage warning dialog: " + e.getMessage(), e);
        }
    }
}
