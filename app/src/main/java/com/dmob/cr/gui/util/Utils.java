package com.dmob.cr.gui.util;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.PorterDuff;
import android.graphics.PorterDuffColorFilter;
import android.graphics.drawable.Drawable;
import android.os.AsyncTask;
import android.text.Html;
import android.text.Layout;
import android.text.Spanned;
import android.text.StaticLayout;
import android.text.TextPaint;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.DrawableRes;
import androidx.core.content.ContextCompat;
import com.nvidia.devtech.NvEventQueueActivity;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.security.SecureRandom;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.regex.Pattern;

public class Utils {

    static final String AB = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    static SecureRandom rnd = new SecureRandom();

    public static void ShowLayout(View view, boolean isAnim) {
        if (view == null)
            return;

        view.setVisibility(View.VISIBLE);

        if(isAnim)
            fadeIn(view);
        else view.setAlpha(1);
    }

    public static void HideLayout(View view, boolean isAnim) {
        if (view == null)
            return;

        if (isAnim) fadeOut(view);
        else {
            view.setAlpha(0);
            view.setVisibility(View.GONE);
        }
    }

    private static void fadeIn(View view) {
        if (view == null)
            return;

        view.animate().setDuration(500)
                .setListener(new AnimatorListenerAdapter() {
                    @Override
                    public void onAnimationEnd(Animator animation) {
                        super.onAnimationEnd(animation);
                    }
                })
                .alpha(1);
    }

    private static void fadeOut(View view) {
        if (view == null)
            return;

        view.animate().setDuration(500)
                .setListener(new AnimatorListenerAdapter() {
                    @Override
                    public void onAnimationEnd(Animator animation) {
                        view.setVisibility(View.GONE);

                        super.onAnimationEnd(animation);
                    }
                })
                .alpha(0);
    }

    public static Drawable getRes(Activity activity, @DrawableRes int id) {
        return ContextCompat.getDrawable(activity.getApplicationContext(), id);
    }

    public static Spanned transfromColors(String str) {
        int i;
        LinkedList linkedList = new LinkedList();
        int i2 = 0;
        String str2 = str;
        int i3 = 0;
        for (int i4 = 0; i4 < str2.length(); i4++) {
            if (str2.charAt(i4) == '{' && (i = i4 + 7) < str2.length() && str2.charAt(i) == '}') {
                StringBuilder sb = new StringBuilder();
                sb.append("" + "#");
                int i5 = i4 + 1;
                sb.append(str2.substring(i5, i));
                linkedList.addLast(sb.toString());
                str2 = str2.substring(0, i5) + "repl" + i3 + str2.substring(i);
                i3++;
            }
        }
        for (Object o : linkedList) {
            String str3 = (String) o;
            if (i2 == 0) {
                String quote = Pattern.quote("" + "{repl" + i2 + "}");
                StringBuilder sb2 = new StringBuilder();
                sb2.append("<font color='");
                sb2.append(str3);
                sb2.append("'>");
                str2 = str2.replaceAll(quote, sb2.toString());
            } else {
                String quote2 = Pattern.quote("" + "{repl" + i2 + "}");
                StringBuilder sb3 = new StringBuilder();
                sb3.append("</font><font color='");
                sb3.append(str3);
                sb3.append("'>");
                str2 = str2.replaceAll(quote2, sb3.toString());
            }
            i2++;
        }
        if (linkedList.size() >= 1) {
            str2 = str2 + "</font>";
        }
        return Html.fromHtml(str2.replaceAll(Pattern.quote("\n"), "<br>"));
    }

    public static String randomString(int len){
        StringBuilder sb = new StringBuilder(len);

        for(int i = 0; i < len; i++)
            sb.append(AB.charAt(rnd.nextInt(AB.length())));

        return sb.toString();
    }

    public static String randomString(int len, String chars){
        StringBuilder sb = new StringBuilder(len);

        for(int i = 0; i < len; i++)
            sb.append(chars.charAt(rnd.nextInt(chars.length())));

        return sb.toString();
    }

    public static Drawable changeDrawableColor(int icon, int newColor) {
        Drawable drawable = ContextCompat.getDrawable(NvEventQueueActivity.getInstance().getApplicationContext(), icon).mutate();
        drawable.setColorFilter(new PorterDuffColorFilter(newColor, PorterDuff.Mode.SRC_IN));

        return drawable;
    }

    public static class LoadImage extends AsyncTask<String, Void, Bitmap> {
        private static ImageView mImageView;

        public LoadImage(ImageView imageView) {
            mImageView = imageView;
        }

        @Override
        protected Bitmap doInBackground(String... strings) {
            Bitmap bitmap = null;
            try {
                InputStream inputStream = new URL(strings[0]).openStream();
                bitmap = BitmapFactory.decodeStream(inputStream);
            } catch (IOException e) {
                e.printStackTrace();
            }
            return bitmap;
        }

        @Override
        protected void onPostExecute(Bitmap bitmap) {
            mImageView.setImageBitmap(bitmap);
        }
    }

    public static void disableEditText(EditText editText) {
        editText.setFocusable(false);
        editText.setEnabled(false);
        editText.setCursorVisible(false);
    }

    public static void enableEditText(EditText editText) {
        editText.setFocusable(true);
        editText.setFocusableInTouchMode(true);
        editText.setEnabled(true);
        editText.setCursorVisible(true);
    }

    public static ArrayList<String> fixFieldsForDialog(ArrayList<String> fields) {
        ArrayList<String> newList = new ArrayList<>();
        int max = 0;
        for (int i = 0; i < fields.size(); i++) {
            int len = fields.get(i).split("\t").length;
            if (len > max) {
                max = len;
            }
        }
        for (int i2 = 0; i2 < fields.size(); i2++) {
            StringBuilder field = new StringBuilder(fields.get(i2));
            for (int len2 = fields.get(i2).split("\t").length; len2 != max; len2++) {
                field.append("\\t ");
            }
            newList.add(field.toString());
        }
        return newList;
    }

    public static int getTextLength(TextView textView) {
        TextPaint textPaint = new TextPaint();
        textPaint.setTextSize(textView.getTextSize());
        textPaint.setTypeface(textView.getTypeface());
        return (int) textPaint.measureText(textView.getText().toString());
    }

    public static void makeAllViewsVisible(ViewGroup viewGroup) {
        viewGroup.setVisibility(View.VISIBLE);
        for (int i = 0; i < viewGroup.getChildCount(); i++) {
            if (viewGroup.getChildAt(i) instanceof ViewGroup) {
                makeAllViewsVisible((ViewGroup) viewGroup.getChildAt(i));
            } else {
                viewGroup.getChildAt(i).setVisibility(View.VISIBLE);
            }
        }
    }

    public static void changeTextViewWidth(TextView textView) {
        textView.post(new Runnable() {
            @Override
            public void run() {
                TextPaint textPaint = new TextPaint();
                textPaint.setTextSize(textView.getTextSize());
                textPaint.setTypeface(textView.getTypeface());
                textPaint.measureText(textView.getText().toString());
                StaticLayout staticLayout = new StaticLayout(textView.getText(), textPaint, 10000, Layout.Alignment.ALIGN_NORMAL, 1.0f, 0.0f, false);
                int lineCount = staticLayout.getLineCount();
                float lineWidth = staticLayout.getLineWidth(0);
                for (int i = 0; i < lineCount; i++) {
                    if (staticLayout.getLineWidth(i) >= lineWidth) {
                        lineWidth = staticLayout.getLineWidth(i) + 5.0f;
                    }
                }
                ViewGroup.LayoutParams layoutParams = textView.getLayoutParams();
                layoutParams.width = (int) lineWidth;
                textView.setLayoutParams(layoutParams);
            }
        });
    }
}
