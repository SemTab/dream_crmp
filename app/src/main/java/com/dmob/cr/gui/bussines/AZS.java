package com.dmob.cr.gui.bussines;

import android.app.Activity;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.LayerDrawable;
import android.text.Editable;
import android.view.animation.AnimationUtils;
import android.view.inputmethod.EditorInfo;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;
import com.nvidia.devtech.CustomEditText;
import com.nvidia.devtech.NvEventQueueActivity;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Formatter;

public class AZS {

    private final Activity mActivity;
    private final ConstraintLayout mInputLayout;
    private final ArrayList<ImageView> mItems;
    private final CustomEditText fuelET;

    private int mFuel = 0;
    private int mMaxFuel = 0;
    private int mCurrentFuel = 0;
    private int mPrice = 0;
    private int mReleasePrice = 0;
    private int mPlayerBalance = 0;

    private final TextView mMaxFuelTV;
    private final TextView mDoFuelTV;
    private final TextView mPriceTV;
    private final Drawable[] mDrawables;

    public AZS(Activity activity) {
        this.mActivity = activity;
        this.mInputLayout = activity.findViewById(R.id.brp_azs_main);

        mDrawables = new Drawable[] {
                Utils.getRes(activity, R.drawable.ic_azs_ai92),
                Utils.getRes(activity, R.drawable.ic_azs_ai95),
                Utils.getRes(activity, R.drawable.ic_azs_ai98),
                Utils.getRes(activity, R.drawable.ic_azs_dt)
        };

        ImageView close = activity.findViewById(R.id.brp_azs_close);
        close.setOnClickListener(v -> hide());

        mMaxFuelTV = activity.findViewById(R.id.brp_azs_max_fuel);
        mDoFuelTV = activity.findViewById(R.id.brp_azs_do_fuel);
        mPriceTV = activity.findViewById(R.id.brp_azs_fuel_price);

        Button doFull = activity.findViewById(R.id.brp_azs_full_btn);
        Button startRefuel = activity.findViewById(R.id.brp_azs_start_btn);

        doFull.setOnClickListener(view -> {
            view.startAnimation(AnimationUtils.loadAnimation(this.mActivity, R.anim.btn_click));

            update(500);
        });

        startRefuel.setOnClickListener(view -> {
            view.startAnimation(AnimationUtils.loadAnimation(this.mActivity, R.anim.btn_click));
            hide();

            if (this.mPlayerBalance >= this.mReleasePrice)
                NvEventQueueActivity.getInstance().refuelTheCar(this.mFuel, this.mPrice);
            else {
                NvEventQueueActivity.getInstance().showNotification(0, "Недостаточно средств", 5, "", "");
            }
        });

        this.fuelET = activity.findViewById(R.id.brp_azs_fuel_et);
        this.fuelET.setOnEditorActionListener((textView, i, keyEvent) -> {
            if(i == EditorInfo.IME_ACTION_DONE || i == EditorInfo.IME_ACTION_NEXT)
            {
                Editable editableText = this.fuelET.getText();

                if(editableText != null)
                {
                    int fuel = Integer.parseInt(editableText.toString());

                    update(fuel);
                }
            }

            return false;
        });

        LinearLayout items1 = activity.findViewById(R.id.brp_azs_items_1);
        LinearLayout items2 = activity.findViewById(R.id.brp_azs_items_2);

        mItems = new ArrayList<>();
        for (int i = 0; i < items1.getChildCount(); i++)
            mItems.add((ImageView)items1.getChildAt(i));

        for (int i = 0; i < items2.getChildCount(); i++)
            mItems.add((ImageView)items2.getChildAt(i));

        Utils.HideLayout(this.mInputLayout, false);
    }

    public void show(int fuelId, int maxFuel, float currentFuel, int price, int balance) {
        Utils.ShowLayout(this.mInputLayout, true);

        this.mInputLayout.animate().translationX(500).setDuration(0).start();
        this.mInputLayout.animate().translationX(0).setDuration(500).start();

        this.mMaxFuel = maxFuel;
        this.mCurrentFuel = Integer.valueOf(Math.round(currentFuel));
        this.mPrice = price;

        this.mPlayerBalance = balance;

        this.mMaxFuelTV.setText(new Formatter().format("%d L", maxFuel).toString());
        // NvEventQueueActivity.getInstance().showNotification(0, new Formatter().format("fuelID: %d | maxFuel: %d | currentFuel: %d | price: %d | balance: %d", fuelId, maxFuel, mCurrentFuel, price, balance).toString(), 5, "", "");

        for (int i = 0; i < mItems.size(); i++) {
            ImageView item = mItems.get(i);

            if (i != fuelId) {
                Drawable incorrectFuelDrawable = Utils.getRes(this.mActivity, R.drawable.ic_azs_incorrect_fuel);
                Drawable currentFuelDrawable = mDrawables[i];

                LayerDrawable finalDrawable = new LayerDrawable(new Drawable[]{currentFuelDrawable, incorrectFuelDrawable});

                item.setImageDrawable(finalDrawable);
                item.setOnClickListener(null);
            } else
                item.setOnClickListener(view -> view.startAnimation(AnimationUtils.loadAnimation(this.mActivity, R.anim.btn_click)));
        }
    }

    public void hide() {
        Utils.HideLayout(this.mInputLayout, true);

        this.mDoFuelTV.setText("0 L");
        this.mMaxFuelTV.setText("0 L");
        this.mPriceTV.setText("0 RUB");

        this.fuelET.setText("");

        for (int i = 0; i < mItems.size(); i++) {
            ImageView item = mItems.get(i);

            if (i > 3)
                i = 3;

            item.setImageDrawable(this.mDrawables[i]);
        }

        this.mInputLayout.animate().translationX(-500).setDuration(500).start();
    }

    private void update(int fuel) {
        int maxFuel = this.mMaxFuel - this.mCurrentFuel;

        this.mFuel = fuel;

        if (this.mFuel > maxFuel) {
            this.mFuel = maxFuel;

            this.fuelET.setText(String.valueOf(this.mFuel));
        }

        this.mReleasePrice = this.mFuel * this.mPrice;

        this.mDoFuelTV.setText(new Formatter().format("%d L", this.mFuel).toString());
        this.mPriceTV.setText(new Formatter().format("%s RUB", new DecimalFormat("###,###,###").format(this.mReleasePrice)).toString());
        // NvEventQueueActivity.getInstance().showNotification(0, new Formatter().format("maxFuel: %d | currentFuel: %d | price: %d", maxFuel, mCurrentFuel, mReleasePrice).toString(), 5, "", "");
    }

    public ConstraintLayout getInputLayout() {
        return mInputLayout;
    }
}
