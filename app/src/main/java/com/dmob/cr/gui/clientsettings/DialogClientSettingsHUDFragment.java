package com.dmob.cr.gui.clientsettings;

import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.SeekBar;
import androidx.fragment.app.Fragment;
import androidx.appcompat.widget.Toolbar;
import androidx.cardview.widget.CardView;

import com.nvidia.devtech.NvEventQueueActivity;
import java.util.HashMap;
import com.dmob.cr.R;

public class DialogClientSettingsHUDFragment extends Fragment implements ISaveableFragment {
    public boolean bChangeAllowed = true;
    public NvEventQueueActivity mContext = null;
    private SeekBar.OnSeekBarChangeListener mListenerSeekBars;
    private HashMap<ViewGroup, Drawable> mOldDrawables;
    public ViewGroup mParentView = null;
    private View mRootView = null;

    public void save() {
    }

    public static DialogClientSettingsHUDFragment createInstance(String str) {
        return new DialogClientSettingsHUDFragment();
    }

    public DialogClientSettingsHUDFragment setRoot(ViewGroup viewGroup) {
        this.mParentView = viewGroup;
        return this;
    }

    public View onCreateView(LayoutInflater layoutInflater, ViewGroup viewGroup, Bundle bundle) {
        this.mRootView = layoutInflater.inflate(R.layout.dialog_settings_hud, viewGroup, false);
        this.mContext = (NvEventQueueActivity) getActivity();
        
        // Настройка тулбара, если он есть
        Toolbar toolbar = mRootView.findViewById(R.id.toolbar);
        if (toolbar != null) {
            toolbar.setNavigationOnClickListener(v -> {
                if (getActivity() != null) {
                    getActivity().onBackPressed();
                }
            });
        }
        
        getValues();
        setSeekBarListeners();
        return this.mRootView;
    }

    public void makeAllElementsInvisible(ViewGroup viewGroup, View view, boolean z) {
        if (z) {
            HashMap<ViewGroup, Drawable> hashMap = new HashMap<>();
            this.mOldDrawables = hashMap;
            hashMap.put(viewGroup, viewGroup.getBackground());
        }
        
        if (viewGroup != null) {
            // Обрабатываем основные элементы с CardView особым образом
            for (int i = 0; i < viewGroup.getChildCount(); i++) {
                View childAt = viewGroup.getChildAt(i);
                if (childAt instanceof CardView) {
                    // Сохраняем текущую прозрачность CardView
                    CardView cardView = (CardView) childAt;
                    this.mOldDrawables.put(cardView, new ColorDrawable(cardView.getCardBackgroundColor().getDefaultColor()));
                    // Не скрываем полностью элементы интерфейса, а только немного затемняем их
                    cardView.setCardBackgroundColor(0x55000000);
                } else if (childAt instanceof ViewGroup) {
                    ViewGroup viewGroup2 = (ViewGroup) childAt;
                    if (childAt != view) {
                    makeAllElementsInvisible(viewGroup2, view, false);
                    this.mOldDrawables.put(viewGroup2, viewGroup2.getBackground());
                    }
                } else if (childAt != view) {
                    // Не скрываем полностью элементы, а делаем полупрозрачными
                    childAt.setAlpha(0.3f);
                }
            }
        }
    }

    public void makeAllElementsVisible(ViewGroup viewGroup, View view, boolean z) {
        if (z && this.mOldDrawables != null) {
            for (ViewGroup next : this.mOldDrawables.keySet()) {
                Drawable background = this.mOldDrawables.get(next);
                if (background != null) {
                    if (next instanceof CardView) {
                        CardView cardView = (CardView) next;
                        if (background instanceof ColorDrawable) {
                            cardView.setCardBackgroundColor(((ColorDrawable) background).getColor());
                        }
                    } else {
                        next.setBackground(background);
            }
        }
            }
        }
        
        if (viewGroup != null) {
            for (int i = 0; i < viewGroup.getChildCount(); i++) {
                View childAt = viewGroup.getChildAt(i);
                if (childAt instanceof ViewGroup) {
                    makeAllElementsVisible((ViewGroup) childAt, view, false);
                } else if (childAt != view) {
                    childAt.setAlpha(1.0f);
                }
            }
        }
    }

    private void setSeekBarListeners() {
        this.mListenerSeekBars = new SeekBar.OnSeekBarChangeListener() {
            public void onProgressChanged(SeekBar seekBar, int i, boolean z) {
                if (DialogClientSettingsHUDFragment.this.bChangeAllowed) {
                    DialogClientSettingsHUDFragment.this.passValuesToNative();
                }
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                DialogClientSettingsHUDFragment dialogClientSettingsHUDFragment = DialogClientSettingsHUDFragment.this;
                dialogClientSettingsHUDFragment.makeAllElementsInvisible(dialogClientSettingsHUDFragment.mParentView, seekBar, true);
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                DialogClientSettingsHUDFragment dialogClientSettingsHUDFragment = DialogClientSettingsHUDFragment.this;
                dialogClientSettingsHUDFragment.makeAllElementsVisible(dialogClientSettingsHUDFragment.mParentView, seekBar, true);
                DialogClientSettingsHUDFragment.this.mContext.onSettingsWindowSave();
            }
        };
        for (int i = 0; i < 10; i++) {
            int identifier = this.mContext.getResources().getIdentifier("hud_element_pos_x_" + i, "id", this.mContext.getPackageName());
            int identifier2 = this.mContext.getResources().getIdentifier("hud_element_pos_y_" + i, "id", this.mContext.getPackageName());
            SeekBar seekBar = (SeekBar) this.mRootView.findViewById(identifier);
            SeekBar seekBar2 = (SeekBar) this.mRootView.findViewById(identifier2);
            if (seekBar != null) {
                seekBar.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
            if (seekBar2 != null) {
                seekBar2.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
        }
        for (int i2 = 0; i2 < 10; i2++) {
            int identifier3 = this.mContext.getResources().getIdentifier("hud_element_scale_x_" + i2, "id", this.mContext.getPackageName());
            int identifier4 = this.mContext.getResources().getIdentifier("hud_element_scale_y_" + i2, "id", this.mContext.getPackageName());
            SeekBar seekBar3 = (SeekBar) this.mRootView.findViewById(identifier3);
            SeekBar seekBar4 = (SeekBar) this.mRootView.findViewById(identifier4);
            if (seekBar3 != null) {
                seekBar3.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
            if (seekBar4 != null) {
                seekBar4.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
        }
        for (int i3 = 0; i3 < 3; i3++) {
            int identifier5 = this.mContext.getResources().getIdentifier("custom_widget_pos_x_" + i3, "id", this.mContext.getPackageName());
            int identifier6 = this.mContext.getResources().getIdentifier("custom_widget_pos_y_" + i3, "id", this.mContext.getPackageName());
            int identifier7 = this.mContext.getResources().getIdentifier("custom_widget_size_" + i3, "id", this.mContext.getPackageName());
            SeekBar seekBar5 = (SeekBar) this.mRootView.findViewById(identifier5);
            SeekBar seekBar6 = (SeekBar) this.mRootView.findViewById(identifier6);
            SeekBar seekBar7 = (SeekBar) this.mRootView.findViewById(identifier7);
            if (seekBar5 != null) {
                seekBar5.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
            if (seekBar6 != null) {
                seekBar6.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
            if (seekBar7 != null) {
                seekBar7.setOnSeekBarChangeListener(this.mListenerSeekBars);
            }
        }
    }

    public void getValues() {
        this.bChangeAllowed = false;
        for (int i = 0; i < 10; i++) {
            int identifier = this.mContext.getResources().getIdentifier("hud_element_pos_x_" + i, "id", this.mContext.getPackageName());
            int identifier2 = this.mContext.getResources().getIdentifier("hud_element_pos_y_" + i, "id", this.mContext.getPackageName());
            SeekBar seekBar = (SeekBar) this.mRootView.findViewById(identifier);
            SeekBar seekBar2 = (SeekBar) this.mRootView.findViewById(identifier2);
            int[] nativeHudElementPosition = this.mContext.getNativeHudElementPosition(i);
            if (nativeHudElementPosition[0] == -1) {
                nativeHudElementPosition[0] = 1;
            }
            if (nativeHudElementPosition[1] == -1) {
                nativeHudElementPosition[1] = 1;
            }
            if (seekBar != null) {
                seekBar.setProgress(nativeHudElementPosition[0]);
            }
            if (seekBar2 != null) {
                seekBar2.setProgress(nativeHudElementPosition[1]);
            }
        }
        for (int i2 = 0; i2 < 10; i2++) {
            int identifier3 = this.mContext.getResources().getIdentifier("hud_element_scale_x_" + i2, "id", this.mContext.getPackageName());
            int identifier4 = this.mContext.getResources().getIdentifier("hud_element_scale_y_" + i2, "id", this.mContext.getPackageName());
            SeekBar seekBar3 = (SeekBar) this.mRootView.findViewById(identifier3);
            SeekBar seekBar4 = (SeekBar) this.mRootView.findViewById(identifier4);
            int[] nativeHudElementScale = this.mContext.getNativeHudElementScale(i2);
            if (nativeHudElementScale[0] == -1) {
                nativeHudElementScale[0] = 1;
            }
            if (nativeHudElementScale[1] == -1) {
                nativeHudElementScale[1] = 1;
            }
            if (!(seekBar3 == null || seekBar3 == null || nativeHudElementScale[0] == -1)) {
                seekBar3.setProgress(nativeHudElementScale[0]);
            }
            if (!(seekBar4 == null || seekBar4 == null || nativeHudElementScale[1] == -1)) {
                seekBar4.setProgress(nativeHudElementScale[1]);
            }
        }
        for (int i3 = 0; i3 < 3; i3++) {
            int identifier5 = this.mContext.getResources().getIdentifier("custom_widget_pos_x_" + i3, "id", this.mContext.getPackageName());
            int identifier6 = this.mContext.getResources().getIdentifier("custom_widget_pos_y_" + i3, "id", this.mContext.getPackageName());
            int identifier7 = this.mContext.getResources().getIdentifier("custom_widget_size_" + i3, "id", this.mContext.getPackageName());
            SeekBar seekBar5 = (SeekBar) this.mRootView.findViewById(identifier5);
            SeekBar seekBar6 = (SeekBar) this.mRootView.findViewById(identifier6);
            SeekBar seekBar7 = (SeekBar) this.mRootView.findViewById(identifier7);
            int[] nativeWidgetPositionAndScale = this.mContext.getNativeWidgetPositionAndScale(i3);
            this.mContext.setNativeWidgetPositionAndScale(i3, nativeWidgetPositionAndScale[0], nativeWidgetPositionAndScale[1], nativeWidgetPositionAndScale[2]);
            if (!(nativeWidgetPositionAndScale[0] == -1 || nativeWidgetPositionAndScale[1] == -1 || nativeWidgetPositionAndScale[2] == -1 || seekBar5 == null || seekBar6 == null || seekBar7 == null)) {
                seekBar5.setProgress(nativeWidgetPositionAndScale[0]);
                seekBar6.setProgress(nativeWidgetPositionAndScale[1]);
                seekBar7.setProgress(nativeWidgetPositionAndScale[2]);
            }
        }
        this.bChangeAllowed = true;
    }

    public void passValuesToNative() {
        int i = 0;
        while (true) {
            int i2 = -1;
            if (i >= 10) {
                break;
            }
            int identifier = this.mContext.getResources().getIdentifier("hud_element_pos_x_" + i, "id", this.mContext.getPackageName());
            int identifier2 = this.mContext.getResources().getIdentifier("hud_element_pos_y_" + i, "id", this.mContext.getPackageName());
            SeekBar seekBar = (SeekBar) this.mRootView.findViewById(identifier);
            SeekBar seekBar2 = (SeekBar) this.mRootView.findViewById(identifier2);
            int progress = seekBar != null ? seekBar.getProgress() : -1;
            if (seekBar2 != null) {
                i2 = seekBar2.getProgress();
            }
            this.mContext.setNativeHudElementPosition(i, progress, i2);
            i++;
        }
        for (int i3 = 0; i3 < 10; i3++) {
            int identifier3 = this.mContext.getResources().getIdentifier("hud_element_scale_x_" + i3, "id", this.mContext.getPackageName());
            int identifier4 = this.mContext.getResources().getIdentifier("hud_element_scale_y_" + i3, "id", this.mContext.getPackageName());
            SeekBar seekBar3 = (SeekBar) this.mRootView.findViewById(identifier3);
            SeekBar seekBar4 = (SeekBar) this.mRootView.findViewById(identifier4);
            this.mContext.setNativeHudElementScale(i3, seekBar3 != null ? seekBar3.getProgress() : -1, seekBar4 != null ? seekBar4.getProgress() : -1);
        }
        for (int i4 = 0; i4 < 3; i4++) {
            int identifier5 = this.mContext.getResources().getIdentifier("custom_widget_pos_x_" + i4, "id", this.mContext.getPackageName());
            int identifier6 = this.mContext.getResources().getIdentifier("custom_widget_pos_y_" + i4, "id", this.mContext.getPackageName());
            int identifier7 = this.mContext.getResources().getIdentifier("custom_widget_size_" + i4, "id", this.mContext.getPackageName());
            SeekBar seekBar5 = (SeekBar) this.mRootView.findViewById(identifier5);
            SeekBar seekBar6 = (SeekBar) this.mRootView.findViewById(identifier6);
            SeekBar seekBar7 = (SeekBar) this.mRootView.findViewById(identifier7);
            if (!(seekBar5 == null || seekBar6 == null || seekBar7 == null)) {
                this.mContext.setNativeWidgetPositionAndScale(i4, seekBar5.getProgress(), seekBar6.getProgress(), seekBar7.getProgress());
            }
        }
    }
}
