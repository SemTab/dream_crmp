package com.dmob.cr.gui;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;

import android.app.Activity;

import android.graphics.Color;
import android.graphics.Typeface;
import android.graphics.drawable.Drawable;

import android.text.Editable;
import android.text.Html;
import android.text.TextWatcher;

import android.view.View;
import android.view.ViewAnimationUtils;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.view.inputmethod.EditorInfo;

import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.core.content.res.ResourcesCompat;

import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;
import com.nvidia.devtech.CustomEditText;
import com.nvidia.devtech.NvEventQueueActivity;

import java.text.DecimalFormat;
import java.util.ArrayList;

public class Numbers {

    private final Activity mActivity;

    private final ConstraintLayout mInputLayout;
    private final ConstraintLayout mNumbersMain;

    private int mCurrentCountryId = 0;
    private int mBalance = 0;

    private final ArrayList<ConstraintLayout> mCountries;

    private final Drawable mItemBackgroundWithStroke;
    private final Drawable mItemBackgroundWithStrokeExclusive;
    private final Drawable mItemBackgroundWithoutStroke;

    private boolean mIsExclusive = false;

    private final CustomEditText mNumber;
    private final CustomEditText mRegion;

    private final TextView mExampleNumber;
    private final TextView mDigitsNumber;

    private final TextView mPrices1;
    private final TextView mResultPrice;

    private String mLastRuNumber = "";
    private String mLastRuRegion = "";

    private String mLastUaNumber = "";

    private String mLastByNumber = "";

    private String mLastKzNumber = "";
    private String mLastKzRegion = "";

    private String mLastExNumber = "";
    private String mLastExRegion = "";

    char[] mAllowedHighBy = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '-'};

    char[] mAllowedHigh = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', 'Y', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' '};
    char[] mAllowedHighChars = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X'};

    char[] mAllowedLower = {'A', 'B', 'C', 'E', 'H', 'K', 'M', 'O', 'P', 'T', 'X', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    public Numbers(Activity activity) {
        this.mActivity = activity;

        this.mInputLayout = activity.findViewById(R.id.brp_numbers_main);
        this.mNumbersMain = activity.findViewById(R.id.brp_numbers_number_bg);

        this.mItemBackgroundWithStroke = Utils.getRes(activity, R.drawable.numbers_country_item_bg);
        this.mItemBackgroundWithStrokeExclusive = Utils.getRes(activity, R.drawable.numbers_country_item_exclusive_bg);
        this.mItemBackgroundWithoutStroke = Utils.getRes(activity, R.drawable.numbers_country_item_bg_without_stroke);

        this.mNumber = activity.findViewById(R.id.brp_numbers_number);
        this.mRegion = activity.findViewById(R.id.brp_numbers_region);

        this.mPrices1 = activity.findViewById(R.id.brp_numbers_prices_1);

        this.mResultPrice = activity.findViewById(R.id.brp_numbers_result_price);
        // this.mResultPrice.setAnimationListener(hTextView -> {});

        this.mCountries = new ArrayList<>();

        Animation animation = AnimationUtils.loadAnimation(activity, R.anim.btn_click);

        Drawable[] countryDrawables = new Drawable[]{
                Utils.getRes(activity, R.drawable.ic_russia),
                Utils.getRes(activity, R.drawable.ic_ukraine),
                Utils.getRes(activity, R.drawable.ic_belarus),
                Utils.getRes(activity, R.drawable.ic_kazakhstan)
        };

        String[] countryNames = new String[]{
                "RU", "UA", "BY", "KZ"
        };

        LinearLayout countries = activity.findViewById(R.id.brp_numbers_countries);

        ImageView newBackground = activity.findViewById(R.id.brp_numbers_main_new_bg);
        ImageView background = activity.findViewById(R.id.brp_numbers_main_bg);
        
        newBackground.setVisibility(View.INVISIBLE);
        background.setVisibility(View.INVISIBLE);

        this.mExampleNumber = activity.findViewById(R.id.brp_numbers_example_number);
        this.mDigitsNumber = activity.findViewById(R.id.brp_numbers_digits);

        TextView repeatButton = activity.findViewById(R.id.brp_numbers_repeat_btn);
        repeatButton.setOnClickListener(view -> {
            view.startAnimation(animation);

           if (this.mBalance < 2000)
                NvEventQueueActivity.getInstance().showNotification(0, "У вас не достаточно денег для генерации номера", 5, "", "");
           //else
           //     NvEventQueueActivity.getInstance().sendCheckGenerateNumber();
        });

        TextView buyButton = activity.findViewById(R.id.brp_numbers_buy_btn);
        buyButton.setOnClickListener(view -> {
            view.startAnimation(animation);

            if (!isValidNumber(this.mNumber.getText().toString()))
                Toast.makeText(NvEventQueueActivity.getInstance().getApplicationContext(), "Сгенерируйте номер", Toast.LENGTH_SHORT).show();
            else if (this.mBalance < 5000)
                Toast.makeText(NvEventQueueActivity.getInstance().getApplicationContext(), "У вас не достаточно денег для покупки номера", Toast.LENGTH_SHORT).show();
            // ПЕРЕПИСАТЬ!
            else if (!isRegCorrect(this.mRegion.getText().toString()))
                Toast.makeText(NvEventQueueActivity.getInstance().getApplicationContext(), "Сгенерируйте регион", Toast.LENGTH_LONG).show();
            else
                NvEventQueueActivity.getInstance().sendCheckNumber(this.mIsExclusive ? 1 : 0, this.mNumber.getText().toString(), this.mRegion.getText().toString());
        });

        TextView exitButton = activity.findViewById(R.id.brp_numbers_exit_btn);
        exitButton.setOnClickListener(view -> {
            view.startAnimation(animation);

            hide();
        });

        Button exclusiveButton = activity.findViewById(R.id.brp_numbers_exclusive_btn);
        exclusiveButton.setOnClickListener(view -> {
            view.startAnimation(animation);

            Drawable exampleBackground;
            Drawable mainBackground;

            Drawable exclusiveButtonBackground;
            Drawable buyButtonBackground;

            if (this.mIsExclusive) {
                exampleBackground = Utils.getRes(activity, R.drawable.shape_numbers);
            //    mainBackground = Utils.getRes(activity, R.drawable.numbers_bg);

                exclusiveButtonBackground = Utils.getRes(activity, R.drawable.ic_exclusive_numbers_btn);
                buyButtonBackground = Utils.getRes(activity, R.drawable.ic_numbers_buy_btn);
            } else {
                exampleBackground = Utils.getRes(activity, R.drawable.shape_numbers_exclusive);
             //   mainBackground = Utils.getRes(activity, R.drawable.numbers_exclusive_bg);

                exclusiveButtonBackground = Utils.getRes(activity, R.drawable.ic_change_numbers_btn);
                buyButtonBackground = Utils.getRes(activity, R.drawable.ic_numbers_buy_exclusive_btn);
            }

            this.mIsExclusive = !this.mIsExclusive;

            if (this.mIsExclusive) {
                Utils.enableEditText(this.mNumber);
                Utils.enableEditText(this.mRegion);
            } else {
                Utils.disableEditText(this.mNumber);
                Utils.disableEditText(this.mRegion);
            }

            updateCountry();

            // -- Animation
            if (this.mIsExclusive) {
                background.setBackgroundColor(0xFF212529);
                newBackground.setBackgroundColor(0xFF1A1D21);
            } else {
                background.setBackgroundColor(0xFF1A1D21);
                newBackground.setBackgroundColor(0xFF212529);
            }

            int finalRadius = Math.max(background.getWidth(), background.getHeight());

            Animator anim = ViewAnimationUtils.createCircularReveal(background, background.getRight(), background.getTop(), finalRadius, 0);
            anim.addListener(new AnimatorListenerAdapter() {
                @Override
                public void onAnimationEnd(Animator animation) {
                    super.onAnimationEnd(animation);

                    background.setBackgroundColor(Color.TRANSPARENT);

                    mExampleNumber.setBackground(exampleBackground);
                    mDigitsNumber.setBackground(exampleBackground);

                    exclusiveButton.setBackground(exclusiveButtonBackground);
                    buyButton.setBackground(buyButtonBackground);
                }
            });
            anim.start();
        });

        for (int i = 0; i < countries.getChildCount(); i++) {
            ConstraintLayout child = (ConstraintLayout) countries.getChildAt(i);

            TextView countryName = child.findViewById(R.id.brp_numbers_country_item_country);
            ImageView countryDrawable = child.findViewById(R.id.brp_numbers_country_item_drawable);

            countryName.setText(countryNames[i]);
            countryDrawable.setImageDrawable(countryDrawables[i]);

            int finalI = i;

            child.setOnClickListener(view -> {
                this.mCurrentCountryId = finalI;

                updateCountry();
            });

            this.mCountries.add(child);
        }

        this.mNumber.addTextChangedListener(new TextWatcher() {
            boolean resetChanges = false;

            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
                char[] cArr = mAllowedLower;

                if (mCurrentCountryId == 1)
                    cArr = mAllowedHigh;

                if (mCurrentCountryId == 2)
                    cArr = mAllowedHighBy;

                this.resetChanges = !isValidNumberText(charSequence.toString(), cArr);
            }

            @Override
            public void afterTextChanged(Editable editable) {
                if (this.resetChanges && mIsExclusive) {
                    mNumber.setText(editable.toString().substring(0, editable.toString().length() - 1));

                    NvEventQueueActivity.getInstance().showNotification(0, "Вы используете некорректные символы", 5, "", "");
                }
            }
        });

        this.mNumber.setOnEditorActionListener((textView, action, keyEvent) -> {
            if(action == EditorInfo.IME_ACTION_DONE || action == EditorInfo.IME_ACTION_NEXT)
            {
                Editable editableText = mNumber.getText();

                if(editableText != null)
                {
                    if (this.mIsExclusive)
                        this.mResultPrice.setText(Html.fromHtml(new DecimalFormat("<font color='#FFDA44'>₽ ###,###</font>").format(1000 + (editableText.length() - 3) * 250)));
                }
            }

            return false;
        });

        Utils.disableEditText(this.mNumber);
        Utils.disableEditText(this.mRegion);

        Utils.HideLayout(this.mInputLayout, false);

        updateCountry();
    }

    public void show(int balance) {
        // FIZ?? FIX???
        if(mInputLayout.getVisibility() == View.VISIBLE)
            return;

        this.mBalance = balance;

        Utils.ShowLayout(this.mInputLayout, true);
    }

    public void hide() {
        Utils.HideLayout(this.mInputLayout, true);
    }

    public void generateNumber(boolean status) {
        if (!status) {
            NvEventQueueActivity.getInstance().showNotification(0, "У вас не достаточно денег для генерации номера", 5, "", "");
            return;
        }

        String resultNum = "";
        String resultRegion = "";

        switch (this.mCurrentCountryId) {
            case 0:
                resultNum += Utils.randomString(1, new String(mAllowedHighChars));
                resultNum += new DecimalFormat("000").format(1 + (int) (Math.random() * 999));
                resultNum += Utils.randomString(2, new String(mAllowedHighChars));

                resultNum = resultNum.toLowerCase();

                resultRegion = String.valueOf(1 + (int) (Math.random() * 999));

                if (!this.mIsExclusive) {
                    this.mLastRuNumber = resultNum;
                    this.mLastRuRegion = resultRegion;
                }
                break;
            case 1:
                resultNum += Utils.randomString(2, new String(mAllowedHighChars)) + " ";
                resultNum += new DecimalFormat("0000").format(1 + (int) (Math.random() * 9999)) + " ";
                resultNum += Utils.randomString(2, new String(mAllowedHighChars));

                if (!this.mIsExclusive)
                    this.mLastUaNumber = resultNum;
                break;
            case 2:
                resultNum += new DecimalFormat("0000").format(1 + (int) (Math.random() * 9999)) + " ";
                resultNum += Utils.randomString(2, new String(mAllowedHighChars)) + "-";
                resultNum += (int) (Math.random() * 7);

                if (!this.mIsExclusive)
                    this.mLastByNumber = resultNum;
                break;
            case 3:
                resultNum += new DecimalFormat("000").format(1 + (int) (Math.random() * 999));
                resultNum += Utils.randomString(3, new String(mAllowedHighChars));

                resultNum = resultNum.toLowerCase();

                resultRegion = new DecimalFormat("00").format(1 + (int) (Math.random() * 16));

                if (!this.mIsExclusive) {
                    this.mLastKzNumber = resultNum;
                    this.mLastKzRegion = resultRegion;
                }
                break;
        }

        /*if (this.mIsExclusive) {
            resultNum = Utils.randomString(3 + (int) (Math.random() * 5), new String(mAllowedLower));

            if (this.mCurrentCountryId == 1 || this.mCurrentCountryId == 2)
                resultNum = resultNum.toUpperCase();

            this.mLastExNumber = resultNum;
            this.mLastExRegion = resultRegion;

            this.mResultPrice.setText(Html.fromHtml(new DecimalFormat("<font color='#FFDA44'>₽ ###,###</font>").format(1000 + (resultNum.length() - 3) * 250)));
        } else */this.mResultPrice.setText(Html.fromHtml("<font color='#6BFF73'>₽ 5,000</font>"));

        this.mNumber.setText(resultNum);
        this.mRegion.setText(resultRegion);

        // ПЕРЕПИСАТЬ!
        NvEventQueueActivity.getInstance().sendGenerateNumber();
    }

    public void buyNumber(boolean status) {
        if (!status) {
            NvEventQueueActivity.getInstance().showNotification(0, "!!! У вас не достаточно денег для генерации номера", 5, "", "");
            return;
        }

        // ПЕРЕПИСАТЬ!
        NvEventQueueActivity.getInstance().sendBuyNumber(this.mIsExclusive ? 1 : 0, this.mNumber.getText().toString(), this.mRegion.getText().toString());

        hide();
    }

    private void updateCountry() {
        for (int i = 0; i < this.mCountries.size(); i++) {
            ConstraintLayout country = this.mCountries.get(i);
            View countryBg = country.findViewById(R.id.brp_numbers_country_item_bg);

            if (i == this.mCurrentCountryId) {
                country.animate().setDuration(250).translationY(NvEventQueueActivity.getInstance().getResources().getDimensionPixelSize(R.dimen._minus15sdp)).start();
                countryBg.setBackground(this.mIsExclusive ? this.mItemBackgroundWithStrokeExclusive : this.mItemBackgroundWithStroke);
            } else {
                country.animate().setDuration(250).translationY(0).start();
                countryBg.setBackground(this.mItemBackgroundWithoutStroke);
            }
        }

        ViewGroup.MarginLayoutParams numberParams = (ViewGroup.MarginLayoutParams)this.mNumber.getLayoutParams();
        ViewGroup.MarginLayoutParams regionParams = (ViewGroup.MarginLayoutParams)this.mRegion.getLayoutParams();

        Drawable background = Utils.getRes(this.mActivity, R.drawable.ic_numbers_ru_num);

        int _55sdp = this.mActivity.getResources().getDimensionPixelSize(R.dimen._55sdp);
        int _65sdp = this.mActivity.getResources().getDimensionPixelSize(R.dimen._65sdp);

        Typeface typeface = ResourcesCompat.getFont(this.mActivity.getApplicationContext(), R.font.plate);

        switch (this.mCurrentCountryId) {
            case 0: // -- RU
                numberParams.width = this.mActivity.getResources().getDimensionPixelSize(R.dimen._190sdp);
                numberParams.leftMargin = 0;
                numberParams.topMargin = 0;

                regionParams.width = this.mActivity.getResources().getDimensionPixelSize(R.dimen._100sdp);
                regionParams.height = this.mActivity.getResources().getDimensionPixelSize(R.dimen._50sdp);

                this.mNumber.setText(this.mLastRuNumber);
                this.mNumber.setHint("x777am");
                this.mNumber.setTextSize(this.mActivity.getResources().getDimensionPixelSize(R.dimen._20sdp));

                this.mRegion.setText(this.mLastRuRegion);
                this.mRegion.setHint("777");
                this.mRegion.setTextSize(this.mActivity.getResources().getDimensionPixelSize(R.dimen._12sdp));
                this.mRegion.setVisibility(View.VISIBLE);

                this.mExampleNumber.setText(R.string.example_ru_num);
                this.mDigitsNumber.setText("a b c e h k m o p t x y");
                break;
            case 1: // -- UA
                numberParams.width = this.mActivity.getResources().getDimensionPixelSize(R.dimen._220sdp);
                numberParams.leftMargin = _65sdp;
                numberParams.topMargin = this.mActivity.getResources().getDimensionPixelSize(R.dimen._10sdp);

                this.mNumber.setText(this.mLastUaNumber);
                this.mNumber.setHint("AA 7777 AA");
                this.mNumber.setTextSize(this.mActivity.getResources().getDimensionPixelSize(R.dimen._15sdp));

                this.mRegion.setVisibility(View.GONE);

                typeface = ResourcesCompat.getFont(this.mActivity.getApplicationContext(), R.font.ua_font);

                background = Utils.getRes(this.mActivity, R.drawable.ic_numbers_ua_num);

                this.mExampleNumber.setText(R.string.example_ua_num);
                this.mDigitsNumber.setText("A B C E H K M O P T X Y");
                break;
            case 2: // -- BY
                numberParams.width = this.mActivity.getResources().getDimensionPixelSize(R.dimen._230sdp);
                numberParams.leftMargin = _55sdp;
                numberParams.topMargin = this.mActivity.getResources().getDimensionPixelSize(R.dimen._10sdp);

                this.mNumber.setText(this.mLastByNumber);
                this.mNumber.setHint("1234 AB-7");
                this.mNumber.setTextSize(this.mActivity.getResources().getDimensionPixelSize(R.dimen._15sdp));

                this.mRegion.setVisibility(View.GONE);

                typeface = ResourcesCompat.getFont(this.mActivity.getApplicationContext(), R.font.ua_font);

                background = Utils.getRes(this.mActivity, R.drawable.ic_numbers_bl_num);

                this.mExampleNumber.setText(R.string.example_by_num);
                this.mDigitsNumber.setText("A B C E H K M O P T X Y");
                break;
            case 3: // -- KZ
                numberParams.width = this.mActivity.getResources().getDimensionPixelSize(R.dimen._150sdp);
                numberParams.leftMargin = _55sdp;
                numberParams.topMargin = 0;

                regionParams.width = this.mActivity.getResources().getDimensionPixelSize(R.dimen._85sdp);
                regionParams.height = this.mActivity.getResources().getDimensionPixelSize(R.dimen._70sdp);

                this.mNumber.setText(this.mLastKzNumber);
                this.mNumber.setHint("444epa");
                this.mNumber.setTextSize(this.mActivity.getResources().getDimensionPixelSize(R.dimen._20sdp));

                this.mRegion.setText(this.mLastKzRegion);
                this.mRegion.setHint("77");
                this.mRegion.setTextSize(this.mActivity.getResources().getDimensionPixelSize(R.dimen._20sdp));
                this.mRegion.setVisibility(View.VISIBLE);

                background = Utils.getRes(this.mActivity, R.drawable.ic_numbers_kz_num);

                this.mExampleNumber.setText(R.string.example_kz_num);
                this.mDigitsNumber.setText("A B C E H K M O P T X Y");
                break;
        }

        this.mNumber.setTypeface(typeface);

        this.mNumber.setLayoutParams(numberParams);
        this.mRegion.setLayoutParams(regionParams);

        this.mNumbersMain.setBackground(background);

        int price = 0;

        if (this.mIsExclusive) {
            if (mNumber.getText().length() > 0)
                price = 1000 + (mNumber.getText().length() - 3) * 250;

            this.mExampleNumber.setText("от 3х до 7 любых букв/цифр");

            this.mNumber.setText(this.mLastExNumber);
            this.mRegion.setText(this.mLastExRegion);

            this.mPrices1.setText(Html.fromHtml("Номерные знаки\t\t\t\t <font color='#FFDA44'>₽ 1,000</font>"));
            this.mResultPrice.setText(Html.fromHtml(new DecimalFormat("<font color='#FFDA44'>₽ ###,###</font>").format(price)));
        } else {
            if (mNumber.getText().length() > 0)
                price = 5000;

            this.mPrices1.setText(Html.fromHtml("Номерные знаки\t\t\t\t <font color='#6BFF73'>₽ 5,000</font>"));
            this.mResultPrice.setText(Html.fromHtml(new DecimalFormat("<font color='#6BFF73'>₽ ###,###</font>").format(price)));
        }
    }

    private boolean isValidNumberText(String str, char[] cArr) {
        for (int i = 0; i < str.length(); i++) {
            boolean z = false;

            for (char c : cArr) {
                if (str.charAt(i) == c) {
                    z = true;
                    break;
                }
            }

            if (!z)
                return false;
        }

        return true;
    }

    private boolean isValidNumber(String str) {
        switch (this.mCurrentCountryId) {
            case 0: return str.length() == 6 && !Character.isDigit(str.charAt(0)) && Character.isDigit(str.charAt(1)) && Character.isDigit(str.charAt(2)) && Character.isDigit(str.charAt(3)) && !Character.isDigit(str.charAt(4)) && !Character.isDigit(str.charAt(5));
            case 1: return str.length() == 10 && !Character.isDigit(str.charAt(0)) && !Character.isDigit(str.charAt(1)) && str.charAt(2) == ' ' && Character.isDigit(str.charAt(3)) && Character.isDigit(str.charAt(4)) && Character.isDigit(str.charAt(5)) && Character.isDigit(str.charAt(6)) && str.charAt(7) == ' ' && !Character.isDigit(str.charAt(8)) && !Character.isDigit(str.charAt(9));
            case 2: return str.length() == 9 && Character.isDigit(str.charAt(8)) && str.charAt(7) == '-' && Character.isDigit(str.charAt(0)) && Character.isDigit(str.charAt(1)) && Character.isDigit(str.charAt(2)) && Character.isDigit(str.charAt(3)) && str.charAt(4) == ' ' && !Character.isDigit(str.charAt(5)) && !Character.isDigit(str.charAt(6));
            case 3: return str.length() == 6 && Character.isDigit(str.charAt(0)) && Character.isDigit(str.charAt(1)) && Character.isDigit(str.charAt(2)) && !Character.isDigit(str.charAt(3)) && !Character.isDigit(str.charAt(4)) && !Character.isDigit(str.charAt(5));
        }

        return false;
    }

    private boolean isRegCorrect(String str) {
        if (this.mCurrentCountryId == 0 || this.mCurrentCountryId == 3)
            return str.length() != 0;

        return true;
    }
}
