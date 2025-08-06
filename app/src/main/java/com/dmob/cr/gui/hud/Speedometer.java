package com.dmob.cr.gui.hud;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.widget.*;

import com.dmob.cr.gui.SpeedometerMenu;
import com.nvidia.devtech.NvEventQueueActivity;
import com.dmob.cr.gui.util.Damp;
import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;
import com.triggertrap.seekarc.SeekArc;
import java.util.Formatter;

public class Speedometer {
    public Activity activity;
    public ImageView mBelt, mEngine, mLight, mLock, mSpeedArrow;
    public TextView mCarHP, mFuel, mSpeed, mMileage;
    public SeekArc mFuelLine, mSpeedLine, mCarHPLine;
    public RelativeLayout mInputLayout;
    ImageView speed_bg;
    SpeedometerMenu mSpeedometerMenu;

    public Speedometer(Activity activity){
        RelativeLayout relativeLayout = activity.findViewById(R.id.speedometer);
        mInputLayout = relativeLayout;
        mSpeed = activity.findViewById(R.id.speed_text);
        mFuel = activity.findViewById(R.id.speed_fuel_text);
        speed_bg = activity.findViewById(R.id.speed_bg);
        mCarHP = activity.findViewById(R.id.speed_car_hp_text);
        mMileage = activity.findViewById(R.id.speed_mileage_text);
        mSpeedLine = activity.findViewById(R.id.speed_line);
        mFuelLine = activity.findViewById(R.id.speed_fuel_line);
        mCarHPLine = activity.findViewById(R.id.speed_car_hp_line);
        mEngine = activity.findViewById(R.id.speed_engine_ico);
        mLight = activity.findViewById(R.id.speed_light_ico);
        mBelt = activity.findViewById(R.id.speed_belt_ico);
        mLock = activity.findViewById(R.id.speed_lock_ico);
        mSpeedArrow = activity.findViewById(R.id.speed_arrow);
        mSpeedometerMenu = new SpeedometerMenu(activity);


        speed_bg.setOnClickListener(v -> {
            mSpeedometerMenu.show();
        });


        Utils.HideLayout(relativeLayout, false);
    }

    @SuppressLint("SetTextI18n")
    public void UpdateSpeedInfo(int speed, int fuel, int hp, int mileage, int engine, int light, int belt, int lock){
        float rot = (float) (((((double) speed) * 0.938d) - 0.0341796875d)-122);
        if (rot > 121.8f) {
            rot = 121.8f;
        }

        if (fuel > 100) {
            fuel = 100;
        } else if(fuel < 0) {
            fuel = 0;
        }

        if (hp > 100) {
            hp = 100;
        } else if(hp < 0) {
            hp = 0;
        }

        //сеттеры
        mSpeedArrow.setRotation(rot);
        mFuel.setText(new Formatter().format("%d л", Integer.valueOf(fuel)).toString());
        mMileage.setText(new Formatter().format("%06d", Integer.valueOf(mileage)).toString());
        mCarHP.setText(new Formatter().format("%d %s", Integer.valueOf(hp), " ").toString());
        mSpeed.setText(String.valueOf(speed));
        mSpeedLine.setProgress(speed);
        mCarHPLine.setProgress(hp);
        mFuelLine.setProgress(fuel);
        mEngine.setBackgroundResource(engine == 1 ? R.drawable.ico_engine_on : R.drawable.ico_engine_off);
        mLight.setBackgroundResource(light == 1 ? R.drawable.ico_lights_on : R.drawable.ico_lights_off);
        mBelt.setBackgroundResource(belt == 1 ? R.drawable.ico_seatbelt_on : R.drawable.ico_seatbelt_off);
        mLock.setBackgroundResource(lock == 1 ? R.drawable.ico_lock_on : R.drawable.ico_lock_off);
        mSpeedometerMenu.setLight(light);
        mSpeedometerMenu.setEngine(engine);
        mSpeedometerMenu.setLock(lock);
    }

    public void ShowSpeed() {
        Utils.ShowLayout(mInputLayout, false);
        // Damp.setCTRL(true);
        // NvEventQueueActivity.getInstance().showHudButtonVeh();
    }

    public void HideSpeed() {
        Utils.HideLayout(mInputLayout, false);
        // Damp.setCTRL(false);
        // NvEventQueueActivity.getInstance().hideHudButtonVeh();
    }
}