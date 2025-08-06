package com.dmob.cr.gui.clientsettings;

import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CompoundButton;
import android.widget.SeekBar;
import androidx.appcompat.widget.SwitchCompat;
import androidx.fragment.app.Fragment;
import androidx.appcompat.widget.Toolbar;
import androidx.cardview.widget.CardView;

import com.nvidia.devtech.NvEventQueueActivity;
import java.io.Serializable;
import java.util.HashMap;
import com.dmob.cr.R;

public class DialogClientSettingsCommonFragment extends Fragment implements ISaveableFragment {
    public boolean bChangeAllowed = true;
    public NvEventQueueActivity mContext = null;
    private SeekBar.OnSeekBarChangeListener mListenerSeekBars;
    private HashMap<ViewGroup, Drawable> mOldDrawables;
    private ViewGroup mParentView = null;
    private View mRootView = null;
    private SwitchCompat mSwitchCutout;
    private SwitchCompat mSwitchFPSCounter;
    private SwitchCompat mHudLogo, mHudTime, mHudDialog;
    private SwitchCompat mSwitchKeyboard;
    private SwitchCompat mSwitchOutfit;
    private SwitchCompat mSwitchRadarrect;
    private SwitchCompat mSwitchSkyBox;

    public void save() {
    }

    public static DialogClientSettingsCommonFragment createInstance(String str) {
        return new DialogClientSettingsCommonFragment();
    }

    public void onCreate(Bundle bundle) {
        super.onCreate((Bundle) null);
    }

    public void onViewStateRestored(Bundle bundle) {
        super.onViewStateRestored((Bundle) null);
    }

    public void onSaveInstanceState(Bundle bundle) {
        bundle.putSerializable("android:support:fragments", (Serializable) null);
        super.onSaveInstanceState(bundle);
        bundle.putSerializable("android:support:fragments", (Serializable) null);
    }

    public View onCreateView(LayoutInflater layoutInflater, ViewGroup viewGroup, Bundle bundle) {
        this.mContext = (NvEventQueueActivity) getActivity();
        View inflate = layoutInflater.inflate(R.layout.dialog_settings_common, viewGroup, false);
        this.mRootView = inflate;
        
        // Настройка тулбара, если он есть
        Toolbar toolbar = mRootView.findViewById(R.id.toolbar);
        if (toolbar != null) {
            toolbar.setNavigationOnClickListener(v -> {
                if (getActivity() != null) {
                    getActivity().onBackPressed();
                }
            });
        }
        
        this.mSwitchKeyboard = (SwitchCompat) inflate.findViewById(R.id.switch_android_keyboard);
        this.mSwitchCutout = (SwitchCompat) this.mRootView.findViewById(R.id.switch_cutout);
        this.mSwitchFPSCounter = (SwitchCompat) this.mRootView.findViewById(R.id.switch_fps_counter);
        this.mSwitchOutfit = (SwitchCompat) this.mRootView.findViewById(R.id.switch_outfit_weapons);
        this.mSwitchRadarrect = (SwitchCompat) this.mRootView.findViewById(R.id.switch_radar_rect);
        this.mSwitchSkyBox = (SwitchCompat) this.mRootView.findViewById(R.id.switch_skybox);
        this.mHudLogo = (SwitchCompat) this.mRootView.findViewById(R.id.switch_hud_logo);
        this.mHudTime = (SwitchCompat) this.mRootView.findViewById(R.id.switch_time);
        this.mHudDialog = (SwitchCompat) this.mRootView.findViewById(R.id.switch_dialogs);
        this.mHudDialog.setVisibility(View.GONE);
        getValues();
        setSeekBarListeners();
        this.mSwitchCutout.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.setNativeCutoutSettings(z);
                new NotificationDialogFragment().show(DialogClientSettingsCommonFragment.this.mContext.getSupportFragmentManager(), "missiles");
            }
        });
        //this.mHudDialog.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
        //    public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
        //        DialogClientSettingsCommonFragment.this.mContext.setNativeDialog(z);
        //    }
        //});
        this.mHudTime.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                if(z == true)
                {
                      DialogClientSettingsCommonFragment.this.mContext.showHudDT();
                } else DialogClientSettingsCommonFragment.this.mContext.hideHudDT();
            }
        });
        this.mSwitchSkyBox.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.setNativeSkyBox(z);
            }
        });
        this.mSwitchKeyboard.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.setNativeKeyboardSettings(z);
            }
        });
        this.mHudLogo.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.showHudLogo(z);
            }
        });
        this.mSwitchRadarrect.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.setNativeRadarrect(z);
            }
        });
        this.mSwitchOutfit.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.setNativeOutfitGunsSettings(z);
            }
        });
        this.mSwitchFPSCounter.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton compoundButton, boolean z) {
                DialogClientSettingsCommonFragment.this.mContext.setNativeFpsCounterSettings(z);
            }
        });
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
            public void onStartTrackingTouch(SeekBar seekBar) {
                if (mParentView != null) {
                    DialogClientSettingsCommonFragment.this.makeAllElementsInvisible(mParentView, seekBar, true);
                }
            }

            public void onProgressChanged(SeekBar seekBar, int i, boolean z) {
                if (DialogClientSettingsCommonFragment.this.bChangeAllowed) {
                    DialogClientSettingsCommonFragment.this.passValuesToNative();
                }
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                if (mParentView != null) {
                    DialogClientSettingsCommonFragment.this.makeAllElementsVisible(mParentView, seekBar, true);
                }
                DialogClientSettingsCommonFragment.this.mContext.onSettingsWindowSave();
            }
        };
        for (int i = 10; i < 15; i++) {
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
        for (int i2 = 10; i2 < 15; i2++) {
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
    }

    public void getValues() {
        if (this.mSwitchKeyboard != null) {
            this.mSwitchKeyboard.setChecked(this.mContext.getNativeKeyboardSettings());
        }
        if (this.mSwitchCutout != null) {
            this.mSwitchCutout.setChecked(this.mContext.getNativeCutoutSettings());
        }
        if (this.mSwitchFPSCounter != null) {
            this.mSwitchFPSCounter.setChecked(this.mContext.getNativeFpsCounterSettings());
        }
        if (this.mHudLogo != null) {
            this.mHudLogo.setChecked(true);
        }
        if (this.mHudTime != null) {
            this.mHudTime.setChecked(true);
        }
        if (this.mHudDialog != null) {
            this.mHudDialog.setChecked(true);
        }
        if (this.mSwitchOutfit != null) {
            this.mSwitchOutfit.setChecked(this.mContext.getNativeOutfitGunsSettings());
        }
        if (this.mSwitchRadarrect != null) {
            this.mSwitchRadarrect.setChecked(this.mContext.getNativeRadarrect());
        }
        if (this.mSwitchSkyBox != null) {
            this.mSwitchSkyBox.setChecked(this.mContext.getNativeSkyBox());
        }
        this.bChangeAllowed = false;
        for (int i = 10; i < 15; i++) {
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
        for (int i2 = 10; i2 < 15; i2++) {
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
            if (!(seekBar3 == null || nativeHudElementScale[0] == -1)) {
                seekBar3.setProgress(nativeHudElementScale[0]);
            }
            if (!(seekBar4 == null || nativeHudElementScale[1] == -1)) {
                seekBar4.setProgress(nativeHudElementScale[1]);
            }
        }
        this.bChangeAllowed = true;
    }

    public void passValuesToNative() {
        int i = 10;
        while (true) {
            int i2 = -1;
            if (i >= 15) {
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
        for (int i3 = 10; i3 < 15; i3++) {
            int identifier3 = this.mContext.getResources().getIdentifier("hud_element_scale_x_" + i3, "id", this.mContext.getPackageName());
            int identifier4 = this.mContext.getResources().getIdentifier("hud_element_scale_y_" + i3, "id", this.mContext.getPackageName());
            SeekBar seekBar3 = (SeekBar) this.mRootView.findViewById(identifier3);
            SeekBar seekBar4 = (SeekBar) this.mRootView.findViewById(identifier4);
            this.mContext.setNativeHudElementScale(i3, seekBar3 != null ? seekBar3.getProgress() : -1, seekBar4 != null ? seekBar4.getProgress() : -1);
        }
    }
}
