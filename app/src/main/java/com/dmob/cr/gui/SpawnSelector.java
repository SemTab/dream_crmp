package com.dmob.cr.gui;

import android.app.Activity;
import android.graphics.drawable.Drawable;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.view.animation.AnimationUtils;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;
import com.nvidia.devtech.NvEventQueueActivity;

import java.util.ArrayList;
import java.lang.ref.WeakReference;

public class SpawnSelector {

    private static final String TAG = "SpawnSelector";
    private final WeakReference<Activity> mActivityRef;
    private final ConstraintLayout mInputLayout;

    private final ArrayList<ConstraintLayout> mItems;
    private final Handler mHandler;

    Drawable[] DRAWABLES;

    String[] TITLES = new String[]{
            "Место выхода", "Ваш дом", "Вокзал", "Организация"
    };

    String[] DESCRIPTIONS = new String[]{
            "Появиться на том месте, \nгде вы были перед выходом",
            "Появиться в вашем купленном\nили арендованном доме",
            "Появиться на вокзале",
            "Появиться в здании \nорганизации"
    };

    public SpawnSelector(Activity activity) {
        this.mActivityRef = new WeakReference<>(activity);
        this.mInputLayout = activity.findViewById(R.id.brp_ss_main);
        this.mHandler = new Handler();

        LinearLayout itemsLL = activity.findViewById(R.id.brp_ss_items);

        DRAWABLES = new Drawable[]{
                Utils.getRes(activity, R.drawable.ic_clock), Utils.getRes(activity, R.drawable.ic_home),
                Utils.getRes(activity, R.drawable.ic_train), Utils.getRes(activity, R.drawable.ic_fraction)
        };

        this.mItems = new ArrayList<>();
        for (int i = 0; i < itemsLL.getChildCount(); i++)
        {
            ConstraintLayout item = (ConstraintLayout) itemsLL.getChildAt(i);

            TextView title = item.findViewById(R.id.brp_ss_item_title);
            TextView desc = item.findViewById(R.id.brp_ss_item_desc);

            ImageView img = item.findViewById(R.id.brp_ss_item_icon);

            title.setText(TITLES[i]);
            desc.setText(DESCRIPTIONS[i]);

            img.setImageDrawable(DRAWABLES[i]);

            mItems.add(item);
        }

        Utils.HideLayout(this.mInputLayout, false);
    }

    public void show(boolean isHouse, boolean isFraction) {
        Activity activity = mActivityRef.get();
        if (activity == null || activity.isFinishing()) {
            Log.e(TAG, "Activity is null or finishing, cannot show SpawnSelector");
            return;
        }

        for (int i = 0; i < this.mItems.size(); i++)
        {
            ConstraintLayout item = this.mItems.get(i);

            TextView title = item.findViewById(R.id.brp_ss_item_not_fount_text);
            View bg = item.findViewById(R.id.brp_ss_item_not_found_bg);

            Button btn = item.findViewById(R.id.brp_ss_item_btn);

            int visibility = View.GONE;
            View.OnClickListener clickListener = selectSpawn(i);

            item.animate().alpha(0.0f).setDuration(0).translationYBy(500).start();
            item.animate().alpha(1.0f).setDuration(500).setStartDelay(400 * i).translationY(0).start();

            if (i == 1) {
                visibility = !isHouse ? View.VISIBLE : View.GONE;
                clickListener = !isHouse ? null : selectSpawn(i);

                title.setText(!isHouse ? "У вас нет\nдома" : "");
            } else if (i == 3){
                visibility = !isFraction ? View.VISIBLE : View.GONE;
                clickListener = !isFraction ? null : selectSpawn(i);

                title.setText(!isFraction ? "Вы не состоите\nв организации" : "");
            }

            title.setVisibility(visibility);
            bg.setVisibility(visibility);

            btn.setOnClickListener(clickListener);
        }

        Utils.ShowLayout(this.mInputLayout, true);
    }

    public void hide() {
        Activity activity = mActivityRef.get();
        if (activity == null || activity.isFinishing()) {
            Log.e(TAG, "Activity is null or finishing, cannot hide SpawnSelector");
            return;
        }

        for (int i = 0; i < this.mItems.size(); i++) {
            ConstraintLayout item = this.mItems.get(i);

            item.animate().alpha(1.0f).setDuration(500).setStartDelay(400 * i).translationYBy(500).start();
        }

        Utils.HideLayout(this.mInputLayout, true);
    }

    private View.OnClickListener selectSpawn(int id) {
        return v -> {
            Activity activity = mActivityRef.get();
            if (activity == null || activity.isFinishing()) {
                Log.e(TAG, "Activity is null or finishing, cannot select spawn");
                return;
            }

            try {
                v.startAnimation(AnimationUtils.loadAnimation(activity, R.anim.btn_click));

                // Скрываем интерфейс перед вызовом нативного метода
            hide();
                
                // Добавляем задержку перед вызовом нативного метода
                mHandler.postDelayed(() -> {
                    try {
                        NvEventQueueActivity instance = NvEventQueueActivity.getInstance();
                        if (instance != null) {
                            instance.spawnPlayer(id);
                        } else {
                            Log.e(TAG, "NvEventQueueActivity instance is null");
                        }
                    } catch (Exception e) {
                        Log.e(TAG, "Error calling spawnPlayer: " + e.getMessage());
                        if (activity != null && !activity.isFinishing()) {
                            Toast.makeText(activity, "Ошибка при выборе места появления", Toast.LENGTH_SHORT).show();
                        }
                    }
                }, 300);
            } catch (Exception e) {
                Log.e(TAG, "Error in selectSpawn: " + e.getMessage());
            }
        };
    }

    public ConstraintLayout getInputLayout() {
        return mInputLayout;
    }
}
