package com.dmob.launcher.utils;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.util.Log;
import android.view.View;

import com.dmob.Settings;

import java.text.DecimalFormat;
import java.io.File;
import java.util.LinkedList;
import java.util.List;

public class Utils {
	public static final long GB = 1073741824;
    public static final long KB = 1024;
    public static final long MB = 1048576;


    // ------------------------------------------------
    public static int DOWNLOAD_GAME = 0;
    public static  int DOWNLOAD_APK = 1;
    public static int DOWNLOAD_UPDATE = 2;
    static int DownloadType = -1;

    public static int getDownloadType() {
        return DownloadType;
    }
    public static int setDownloadType(int value)
    {
        return DownloadType = value;
    }
    public static Boolean getReverserFinal() {
        return true;
    }

    public static boolean isGameInstalled() {
        File anim = new File(Settings.path_cache + "anim/");
        File audio = new File(Settings.path_cache + "audio/");
        File data = new File(Settings.path_cache + "data/");
        File models = new File(Settings.path_cache + "models/");
        File texdb = new File(Settings.path_cache + "texdb/");
        File samp = new File(Settings.path_cache + "SAMP/", "settings.ini");

        return anim.exists()
                && audio.exists()
                && data.exists()
                && models.exists()
                && texdb.exists()
                && samp.exists();
    }

	public static void delete(File file) {
        if (file.exists()) {
            if (file.isDirectory()) {
                for (File f : file.listFiles()) {
                    delete(f);
                }
            }
            file.delete();
        }
    }

    public static void ShowView(View view, boolean isAnim) {
        if (view == null) {
            return;
        }
        view.setVisibility(View.VISIBLE);
        if (isAnim) {
            fadeIn(view);
        } else {
            view.setAlpha(1.0f);
        }
    }

    public static void HideView(View view, boolean isAnim) {
        if (view == null) {
            return;
        }
        if (!isAnim) {
            view.setAlpha(0.0f);
            view.setVisibility(View.GONE);
            return;
        }
        fadeOut(view);
    }

    private static void fadeIn(View view) {
        if (view == null) {
            return;
        }
        view.animate().setDuration(1000L).setListener(null).alpha(1.0f);
    }

    private static void fadeOut(final View view) {
        if (view == null) {
            return;
        }
        view.animate().setDuration(1000L).setListener(new AnimatorListenerAdapter() {
            @Override
            public void onAnimationEnd(Animator animation) {
                view.setVisibility(View.GONE);
                super.onAnimationEnd(animation);
            }
        }).alpha(0.0f);
    }

    public static long getFileSize(File file) {
        File[] listFiles;
        if (file == null || !file.exists()) {
            return 0L;
        }
        if (!file.isDirectory()) {
            return file.length();
        }
        List<File> dirs = new LinkedList<>();
        dirs.add(file);
        long result = 0;
        while (!dirs.isEmpty()) {
            File dir = dirs.remove(0);
            if (dir.exists() && (listFiles = dir.listFiles()) != null && listFiles.length != 0) {
                for (File child : listFiles) {
                    result += child.length();
                    if (child.isDirectory()) {
                        dirs.add(child);
                    }
                }
            }
        }
        return result;
    }

    public static String bytesIntoHumanReadable(long value) {
        long[] dividers = {1073741824, 1048576, 1024, 1};
        String[] units = {"GB", "MB", "KB", "B"};
        if (value < 1) {
            Log.i("BR-RP", "Invalid file size: " + value);
            value = 0;
        }
        for (int i = 0; i < dividers.length; i++) {
            long divider = dividers[i];
            if (value >= divider) {
                String result = format(value, divider, units[i]);
                return result;
            }
        }
        return null;
    }

    private static String format(long value, long divider, String unit) {
        double result = value;
        if (divider > 1) {
            result /= divider;
        }
        return new DecimalFormat("#,##0.#").format(result) + " " + unit;
    }
}