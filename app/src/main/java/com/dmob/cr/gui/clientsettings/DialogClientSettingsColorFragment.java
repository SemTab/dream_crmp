package com.dmob.cr.gui.clientsettings;

import android.content.DialogInterface;
import android.graphics.Color;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import com.dmob.cr.R;
import androidx.appcompat.widget.AppCompatButton;
import androidx.fragment.app.Fragment;

import com.nvidia.devtech.NvEventQueueActivity;
import com.skydoves.colorpickerview.ColorEnvelope;
import com.skydoves.colorpickerview.ColorPickerDialog;
import com.skydoves.colorpickerview.listeners.ColorEnvelopeListener;
import com.skydoves.colorpickerview.listeners.ColorPickerViewListener;

public class DialogClientSettingsColorFragment extends Fragment implements ISaveableFragment {
    private AppCompatButton mButtonAmmoColor;
    private AppCompatButton mButtonArmorColor;
    private AppCompatButton mButtonArmorTextColor;
    private AppCompatButton mButtonHPColor;
    private AppCompatButton mButtonHpTextColor;
    private AppCompatButton mButtonMoneyColor;
    private AppCompatButton mButtonRadarColor;
    private AppCompatButton mButtonWantedColor;
    public NvEventQueueActivity mContext = null;

    public void save() {
    }

    public static DialogClientSettingsColorFragment createInstance(String str) {
        return new DialogClientSettingsColorFragment();
    }

    public View onCreateView(LayoutInflater layoutInflater, ViewGroup viewGroup, Bundle bundle) {
        this.mContext = (NvEventQueueActivity) getActivity();
        View inflate = layoutInflater.inflate(R.layout.dialog_settings_color, viewGroup, false);
        this.mButtonHPColor = (AppCompatButton) inflate.findViewById(R.id.button_color_hp);
        this.mButtonArmorColor = (AppCompatButton) inflate.findViewById(R.id.button_color_armour);
        this.mButtonMoneyColor = (AppCompatButton) inflate.findViewById(R.id.button_color_money);
        this.mButtonWantedColor = (AppCompatButton) inflate.findViewById(R.id.button_color_wanted);
        this.mButtonHpTextColor = (AppCompatButton) inflate.findViewById(R.id.button_color_hp_text);
        this.mButtonArmorTextColor = (AppCompatButton) inflate.findViewById(R.id.button_color_armour_text);
        this.mButtonRadarColor = (AppCompatButton) inflate.findViewById(R.id.button_color_radar);
        this.mButtonAmmoColor = (AppCompatButton) inflate.findViewById(R.id.button_color_ammos);
        getValues();
        this.mButtonRadarColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color6").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(6, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonAmmoColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color9").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(9, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonHPColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color0").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(0, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonArmorColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color1").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(1, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonMoneyColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color2").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(2, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonWantedColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color3").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(3, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonHpTextColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color4").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(4, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(2);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        this.mButtonArmorTextColor.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                ColorPickerDialog.Builder bottomSpace = new ColorPickerDialog.Builder(DialogClientSettingsColorFragment.this.mContext).setPreferenceName("color5").setPositiveButton((CharSequence) "Применить", (ColorPickerViewListener) new ColorEnvelopeListener() {
                    public void onColorSelected(ColorEnvelope colorEnvelope, boolean z) {
                        int[] argb = colorEnvelope.getArgb();
                        DialogClientSettingsColorFragment.this.mContext.setNativeHudElementColor(5, argb[0], argb[1], argb[2], argb[3]);
                        DialogClientSettingsColorFragment.this.getValues();
                    }
                }).setNegativeButton((CharSequence) "Закрыть", (DialogInterface.OnClickListener) new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialogInterface, int i) {
                        dialogInterface.dismiss();
                    }
                }).attachAlphaSlideBar(true).attachBrightnessSlideBar(true).setBottomSpace(0);
                FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) bottomSpace.getColorPickerView().getLayoutParams();
                layoutParams.height = (int) (((float) layoutParams.height) * 0.25f);
                layoutParams.width = (int) (((float) layoutParams.width) * 0.25f);
                layoutParams.topMargin = 10;
                layoutParams.bottomMargin = 0;
                bottomSpace.getColorPickerView().setLayoutParams(layoutParams);
                bottomSpace.show();
            }
        });
        return inflate;
    }

    public void getValues() {
        this.mButtonHPColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(0)));
        this.mButtonArmorColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(1)));
        this.mButtonMoneyColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(2)));
        this.mButtonWantedColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(3)));
        this.mButtonHpTextColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(4)));
        this.mButtonArmorTextColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(5)));
        this.mButtonRadarColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(6)));
        this.mButtonAmmoColor.setBackgroundColor(Color.parseColor(this.mContext.getHudElementColor(9)));
    }
}
