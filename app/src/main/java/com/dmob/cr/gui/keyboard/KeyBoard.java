package com.dmob.cr.gui.keyboard;

import android.animation.AnimatorInflater;
import android.animation.AnimatorSet;
import android.annotation.SuppressLint;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.Resources;
import android.graphics.ColorFilter;
import android.graphics.Point;
import android.graphics.PorterDuff;
import android.graphics.Rect;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewPropertyAnimator;
import android.view.ViewTreeObserver;
import android.view.animation.DecelerateInterpolator;
import android.view.inputmethod.InputMethodManager;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.nvidia.devtech.CustomEditText;
import com.nvidia.devtech.NvEventQueueActivity;

import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Timer;
import java.util.TimerTask;

import com.dmob.cr.R;
import com.dmob.cr.gui.chatedgar.ChatManager;
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
public final class KeyBoard implements ViewTreeObserver.OnGlobalLayoutListener, View.OnClickListener {
    @SuppressLint("StaticFieldLeak")
    public static KeyBoard inst = null;
    public static int language = 1; //(1 - Русский / 2 - Англиский / 3 - Цифры / 4 - Символы / 5 - CMD)
    public static boolean isDialog = false;
    public static int caps = 2; //(1 - мал / 2 - биг / 3 - супер биг)
    public int keys_numbers;
    public int clickkeys;
    public int mess = -1;
    public ArrayList<String> messange = new ArrayList<>();
    public NvEventQueueActivity nvEventQueueActivity;
    public CustomEditText customEditText;
    public ViewGroup viewGroup;
    public static class keys {

        public int tag;
        public FrameLayout frameLayout;
        public ImageView c;
        public View view;
        public int f2261e;

        public interface a {
        }
    }
    public keys[] keys;
    public RecyclerView hint_recycler;
    public ImageView clear;
    public TextView hint_params;
    public LinearLayout layout_main, layout_keys, symbols_layout, layout_history, layout_input;
    public LinearLayout[] f2225s;
    //НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
    public FrameLayout key_hint, layout_keyboard, history_up, history_down, send_button;

    public KeyBoard(NvEventQueueActivity nvEventQueueActivity) {
        super();
        inst = this;
        this.nvEventQueueActivity = nvEventQueueActivity;
        keys = new keys[44];
        f2225s = new LinearLayout[4];
    }

    @Override
    public void onGlobalLayout() {

    }

    @Override
    public void onClick(View v) {
        int i10 = 0;
        if (v == history_up) {
            int i11 = mess + 1;
            mess = i11;
            if (i11 >= messange.size()) {
                mess--;
            }
            i10 = mess;
            if (i10 < 0) {
                return;
            }
        } else if (v == history_down) {
            int i12 = mess - 1;
            mess = i12;
            if (i12 < -1) {
                mess = -1;
            }
            i10 = mess;
            if (i10 < 0) {
                this.customEditText.setText("");
                history();
                return;
            }
        }
        customEditText.setText(messange.get(i10));
        customEditText.setSelection(customEditText.getText().length());
        history();
    }

    @SuppressLint("DiscouragedApi")
    public static View getIdRes(NvEventQueueActivity nvEventQueueActivity, Resources resources, String str, String str2, ViewGroup viewGroup) {
        return viewGroup.findViewById(resources.getIdentifier(str, str2, nvEventQueueActivity.getPackageName()));
    }

    public static String onePlusOne(String str, int i10) {
        return str + i10;
    }

    public static int upDateTag(String str) {
        Objects.requireNonNull(str, "Name is null");
        if (str.equals("SYMBOL")) {
            return 1;
        }
        if (str.equals("SHIFT")) {
            return 2;
        }
        if (str.equals("BACKSPACE")) {
            return 3;
        }
        if (str.equals("SPACE")) {
            return 4;
        }
        if (str.equals("ENTER")) {
            return 5;
        }
        if (str.equals("SWITCH_NUM")) {
            return 6;
        }
        if (str.equals("SWITCH_NUM2")) {
            return 7;
        }
        if (str.equals("SWITCH_CMD")) {
            return 8;
        }
        if (str.equals("SWITCH_LANG")) {
            return 9;
        }
        throw new IllegalArgumentException("No enum constant com.matreshka.core.ui.keyboard.KeyboardManager.ButtonType.".concat(str));
    }// писал EDGAR 3.0

    public static String sgetLaunguage(int i10) {
        if (i10 == 1) {
            return "RUS";
        }
        if (i10 == 2) {
            return "ENG";
        }
        if (i10 == 3) {
            return "NUM1";
        }
        if (i10 == 4) {
            return "NUM2";
        }
        if (i10 == 5) {
            return "CMD";
        }
        throw new IllegalArgumentException("TREW");
    }

    public static class clicabilel implements View.OnTouchListener {

        public final AnimatorSet animatorSet;
        public final AnimatorSet fanimatorSet1;

        public clicabilel(Context context, View view) {
            view.setClickable(true);
            this.animatorSet = (AnimatorSet) AnimatorInflater.loadAnimator(context, R.animator.reduce_size);
            this.fanimatorSet1 = (AnimatorSet) AnimatorInflater.loadAnimator(context, R.animator.regain_size);
        }

        @Override
        @SuppressLint({"ClickableViewAccessibility"})
        public final boolean onTouch(View view, MotionEvent motionEvent) {
            AnimatorSet animatorSet;
            int action = motionEvent.getAction() & 255;
            if (action == 0) {
                if (this.fanimatorSet1.isRunning()) {
                    this.fanimatorSet1.end();
                }
                this.animatorSet.setTarget(view);
                animatorSet = this.animatorSet;
            } else if (action != 1 && action != 3) {
                return false;
            } else {
                if (this.animatorSet.isRunning()) {
                    this.animatorSet.end();
                }
                this.fanimatorSet1.setTarget(view);
                animatorSet = this.fanimatorSet1;
            }
            animatorSet.start();
            return false;
        }
    }// писал EDGAR 3.0

    public boolean vGrop() {
        return viewGroup != null;
    }// писал EDGAR 3.0

    public ViewPropertyAnimator animOpenKeyBoard() {
        this.viewGroup.setVisibility(View.VISIBLE);
        this.viewGroup.clearAnimation();
        this.viewGroup.setAlpha(0.0f);
        this.viewGroup.post(new AnimOpenKeyBoard());
        Log.i("edgar", "Anim Open KeyBoard");
        return this.viewGroup.animate().setDuration(300L);
    }

    public class AnimOpenKeyBoard implements Runnable {
        public AnimOpenKeyBoard() {
        }

        @Override // java.lang.Runnable
        public final void run() {//viewGroup
            KeyBoard g0Var = KeyBoard.this;
            g0Var.viewGroup.setTranslationY(g0Var.layout_main.getHeight());
            KeyBoard.this.viewGroup.animate().setDuration(300L).alpha(1.0f - (r() / 100.0f)).translationY(0.0f).setInterpolator(new DecelerateInterpolator()).start();
        }
    }

    @SuppressLint("ClickableViewAccessibility")
    public void OpenKeyBoard(CustomEditText customEditTextOne) {
        if (vGrop()) {
            D(2);
            this.customEditText.a(new a());
            if (customEditTextOne == null) {
                isDialog = false;
                isChatClose = false;
                customEditTextOne = (CustomEditText) viewGroup.findViewById(R.id.input);
                customEditTextOne.setText("");
                Log.i("edgar", "chat ==" + customEditTextOne);
            } else {
                this.customEditText = customEditTextOne;
                isDialog = true;
                Log.i("edgar", "dialogtext  ==" + customEditTextOne);
            }
            u();
            animOpenKeyBoard().start();
            return;
        }
        viewGroup = (ViewGroup) ((LayoutInflater) NvEventQueueActivity.getInstance().getSystemService(Context.LAYOUT_INFLATER_SERVICE)).inflate(R.layout.keyboard, (ViewGroup) null);
        NvEventQueueActivity.getInstance().getFrontUILayout().addView(viewGroup, -1, -1);
        if (customEditTextOne == null) {
            isDialog = false;
            isChatClose = false;
            Log.i("edgar", "chat");
        } else/* if (customEditTextOne != null)*/ {
            this.customEditText = customEditTextOne;
            isDialog = true;
            Log.i("edgar", "diakog" + customEditTextOne);
        }
        layout_main = (LinearLayout) viewGroup.findViewById(R.id.layout_main);
        layout_keyboard = (FrameLayout) viewGroup.findViewById(R.id.layout_keyboard);
        layout_keys = (LinearLayout) viewGroup.findViewById(R.id.layout_keys);
        symbols_layout = (LinearLayout) viewGroup.findViewById(R.id.symbols_layout);
        key_hint = (FrameLayout) viewGroup.findViewById(R.id.key_hint);
        for (int i10 = 0; i10 < 44; i10++) {
            keys[] kVarArr = keys;
            kVarArr[i10] = new keys();
            keys kVar = kVarArr[i10];
            ViewGroup viewGroup = this.viewGroup;
            kVar.frameLayout = (FrameLayout) getIdRes(nvEventQueueActivity, nvEventQueueActivity.getResources(), onePlusOne("key_", i10), "id", viewGroup);
            keys[] kVarArr2 = this.keys;
            kVarArr2[i10].tag = upDateTag(((String) kVarArr2[i10].frameLayout.getTag()).toUpperCase());
            keys[] kVarArr3 = this.keys;
            kVarArr3[i10].c = (ImageView) kVarArr3[i10].frameLayout.getChildAt(0);
            if (keys[i10].frameLayout.getChildCount() > 1) {
                keys[] kVarArr4 = this.keys;
                kVarArr4[i10].view = kVarArr4[i10].frameLayout.getChildAt(1);
            }
            keys[i10].f2261e = (keys_numbers = i10);
        }
        for (int i11 = 0; i11 < 4; i11++) {
            LinearLayout[] linearLayoutArr = this.f2225s;
            linearLayoutArr[i11] = (LinearLayout) getIdRes(this.nvEventQueueActivity, this.nvEventQueueActivity.getResources(), onePlusOne("row_", i11), "id", viewGroup);
        }
        this.layout_keys.setClickable(true);
        this.layout_keys.setOnTouchListener(new onClickKeys()); //TODO сделать надо
        this.layout_history = (LinearLayout) viewGroup.findViewById(R.id.layout_history);
        this.history_up = (FrameLayout) viewGroup.findViewById(R.id.history_up);
        this.history_down = (FrameLayout) viewGroup.findViewById(R.id.history_down);
        this.layout_input = (LinearLayout) viewGroup.findViewById(R.id.layout_input);
        customEditTextOne = (CustomEditText) viewGroup.findViewById(R.id.input);
        this.clear = (ImageView) viewGroup.findViewById(R.id.clear);
        this.send_button = (FrameLayout) viewGroup.findViewById(R.id.send_button);
        this.hint_recycler = (RecyclerView) viewGroup.findViewById(R.id.hint_recycler);
        this.hint_params = (TextView) viewGroup.findViewById(R.id.hint_params);
        this.history_up.setAlpha(0.0f);
        this.history_down.setAlpha(0.0f);
        customEditTextOne.setText("");
        FrameLayout frameLayout = this.history_up;
        frameLayout.setOnTouchListener(new clicabilel(this.nvEventQueueActivity, frameLayout));
        FrameLayout frameLayout2 = this.history_down;
        frameLayout2.setOnTouchListener(new clicabilel(this.nvEventQueueActivity, frameLayout2));
        ImageView imageView = this.clear;
        imageView.setOnClickListener(v -> {
            customEditText.setText("");
            customEditText.setSelection(customEditText.length());
            if(isDialog) {
                q();
            }else {
                x();
            }
        });
        imageView.setOnTouchListener(new clicabilel(this.nvEventQueueActivity, imageView));
        FrameLayout frameLayout3 = this.send_button;
        frameLayout3.setOnTouchListener(new clicabilel(this.nvEventQueueActivity, frameLayout3));
        RecyclerView.ItemAnimator wVar = (RecyclerView.ItemAnimator) this.hint_recycler.getItemAnimator();
        if (wVar != null) {
            this.hint_recycler.setItemAnimator(wVar);
        }
        this.hint_recycler.setLayoutManager(new LinearLayoutManager(viewGroup.getContext(), RecyclerView.HORIZONTAL, false));
        this.key_hint.setVisibility(View.GONE);
        this.hint_recycler.setVisibility(View.GONE);
        this.hint_params.setVisibility(View.GONE);
        this.send_button.setVisibility(View.GONE);
        D(2);
        u();
        animOpenKeyBoard().start();
    }

    public void history() {
        if (mess + 1 >= messange.size()) {
            history_up.clearAnimation();
            history_up.animate().alpha(0.0f).setDuration(300L).start();
            history_up.setOnClickListener(null);
            history_up.setClickable(false);
        } else {
            history_up.clearAnimation();// писал EDGAR 3.0
            history_up.animate().alpha(1.0f).setDuration(300L).start();
            history_up.setOnClickListener(this);
        }
        if (mess < 0) {
            history_down.clearAnimation();
            history_down.animate().alpha(0.0f).setDuration(300L).start();
            history_down.setOnClickListener(null);
            history_down.setClickable(false);
        } else {
            history_down.clearAnimation();
            history_down.animate().alpha(1.0f).setDuration(300L).start();
            history_down.setOnClickListener(this);
        }
        if(isDialog){
            layout_history.setVisibility(View.GONE);
        }else {
            layout_history.setVisibility(View.VISIBLE);
        }
    }
    /*
    SYMBOL - 1
    SHIFT - 2
    BACKSPACE - 3
    SPACE - 4
    ENTER - 5
    SWITCH_NUM - 6
    SWITCH_NUM2 - 7
    SWITCH_CMD - 8
    SWITCH_LANG - 9
    Я топ потому что я
    3 0
    by EDGAR 3.0
    */

    public void f() {
        if (!vGrop()) {
            return;
        }
        ViewPropertyAnimator m9 = m();
        m9.start();
    }

    public class onClickKeys implements View.OnTouchListener {

        public onClickKeys() {
        }

        boolean click;

        @SuppressLint("SetTextI18n")
        public final void clikcKeys(MotionEvent motionEvent) {
            int findPointerIndex;
            KeyBoard g0Var = KeyBoard.this;
            Objects.requireNonNull(g0Var);
            int i10 = 0;
            while (true) {
                if (i10 >= 44) {
                    break;
                }
                keys[] kVarArr = keys;
                if (kVarArr[i10].frameLayout != null && kVarArr[i10].frameLayout.getVisibility() == View.VISIBLE) {
                    int[] iArr = new int[2];
                    keys[i10].frameLayout.getLocationOnScreen(iArr);
                    int i11 = iArr[0];
                    int i12 = iArr[1];
                    int pointerCount = motionEvent.getPointerCount() - 1;
                    int x9 = (int) (motionEvent.getX(pointerCount) + (motionEvent.getRawX() - motionEvent.getX()));
                    int y = (int) (motionEvent.getY(pointerCount) + (motionEvent.getRawY() - motionEvent.getY()));
                    if ((motionEvent.getActionMasked() == 1 || motionEvent.getActionMasked() == 6 || motionEvent.getActionMasked() == 3) && (findPointerIndex = motionEvent.findPointerIndex(motionEvent.getPointerId(motionEvent.getActionIndex()))) != -1) {
                        x9 = (int) (motionEvent.getX(findPointerIndex) + (motionEvent.getRawX() - motionEvent.getX()));
                        y = (int) (motionEvent.getY(findPointerIndex) + (motionEvent.getRawY() - motionEvent.getY()));
                    }
                    if (x9 >= i11 && x9 <= g0Var.keys[i10].frameLayout.getWidth() + i11 && y >= i12 && y <= g0Var.keys[i10].frameLayout.getHeight() + i12) {
                        clickkeys = i10;
                        /*
                            SYMBOL - 1
                            SHIFT - 2
                            BACKSPACE - 3
                            SPACE - 4
                            ENTER - 5
                            SWITCH_NUM - 6
                            SWITCH_NUM2 - 7
                            SWITCH_CMD - 8
                            SWITCH_LANG - 9
                         */
                        if (keys[clickkeys].tag == 1) {
                            int[] iAArr = new int[2];
                            keys[clickkeys].frameLayout.getLocationInWindow(iAArr);
                            key_hint.setVisibility(View.GONE);
                            String edgar = ((TextView) keys[clickkeys].view).getText().toString();
                            String pon = customEditText.getText().toString();
                            if (yderwal) {
                                yderwal = false;
                                timer.cancel();
                                String edgardop = Yderhwanie(clickkeys);
                                System.out.println(edgardop);
                                if (edgardop == null) {
                                    customEditText.setText(pon + edgar);
                                } else {
                                    customEditText.setText(pon + edgardop);
                                }
                            } else {
                                customEditText.setText(pon + edgar);
                                timer.cancel();
                            }
                            if (caps == 2) {
                                D(1);
                            }
                            customEditText.setSelection(customEditText.getText().length());
                        } else if (keys[clickkeys].tag == 2) {
                            if (click) {
                                // Двойное касание распознано
                                if(caps == 1){
                                    D(3);
                                }
                                click = false;
                            } else {
                                if (caps == 2 || caps == 3) {
                                    D(1);
                                } else if(caps == 1) {
                                    D(2);
                                }
                            }
                            break;
                        }else if (keys[clickkeys].tag == 4) {
                            String pizda = customEditText.getText().toString();
                            String rezylt = pizda + " ";
                            customEditText.setText(rezylt);
                            customEditText.setSelection(customEditText.getText().length());
                            ((ImageView) ((FrameLayout) keys[clickkeys].frameLayout).getChildAt(0)).setColorFilter(null);
                            Log.e("edgar", "click spase");
                            break;
                        }else if (keys[clickkeys].tag == 5) {
                            if(isDialog) {
                                q();
                                break;
                            }else {
                                x();
                                break;
                            }
                        }else if (keys[clickkeys].tag == 6) {
                            SetLanguage(3);
                            break;
                        }else if (keys[clickkeys].tag == 7) {
                            SetLanguage(4);
                            break;
                        }else if (keys[clickkeys].tag == 9) {
                            if(language == 1) {
                                language = language + 1;
                                SetLanguage(language);
                                break;
                            }else if(language == 2){
                                language = language - 1;
                                SetLanguage(language);
                                break;
                            }
                        }
                        break;
                    }
                }// писал EDGAR 3.0
                i10++;
            }
//НА ОБНОВУ ТОЛЬКО РЕЛИЗ BY EDGAR 3.0
        }
        public final String Yderhwanie(int i) { //удержание действие / код написал by EDGAR 3.0
            if (keys[i].tag == 1) {
                if (((TextView) keys[i].view).getText().equals("е")) {
                    return "ё";
                }
                if (((TextView) keys[i].view).getText().equals("Е")) {
                    return "Ё";
                }
                if (((TextView) keys[i].view).getText().equals("ь")) {
                    return "ъ";
                }
                if (((TextView) keys[i].view).getText().equals("Ь")) {
                    return "Ъ";
                }
                return null;
            }
            return null;
        }

        private static final long DOUBLE_TAP_TIME_DELTA = 300;
        private long lastTapTime = 0;
        Timer timer;
        private boolean namp = false;

        @SuppressLint("ClickableViewAccessibility")
        @Override // android.view.View.OnTouchListener
        public final boolean onTouch(View view, MotionEvent motionEvent) {
            //anim(motionEvent);
            if (MotionEvent.ACTION_DOWN == motionEvent.getAction()) {
                namp = true;
                anim(motionEvent);
                timer = new Timer();
                timer.schedule(new TimerTask() {
                    @Override
                    public void run() {
                        yderwal = true;
                    }
                },300L);
            }
            if (MotionEvent.ACTION_UP == motionEvent.getAction()) {
                namp = false;
                long currentTime = System.currentTimeMillis();
                if (currentTime - lastTapTime < DOUBLE_TAP_TIME_DELTA) {
                    // Двойное касание распознано
                    click = true;
                    clikcKeys(motionEvent);
                    return true;
                } else {
                    clikcKeys(motionEvent);
                }
                lastTapTime = currentTime;
                timer.cancel();
            }
            return true;
        }

        public final void anim(MotionEvent motionEvent) {
            int findPointerIndex;
            int i10 = 0;
            while (true) {
                if (i10 >= 44) {
                    break;
                }
                keys[] kVarArr = keys;
                if (kVarArr[i10].frameLayout != null && kVarArr[i10].frameLayout.getVisibility() == View.VISIBLE) {
                    int[] iArr = new int[2];
                    keys[i10].frameLayout.getLocationOnScreen(iArr);
                    int i11 = iArr[0];
                    int i12 = iArr[1];
                    int pointerCount = motionEvent.getPointerCount() - 1;
                    int x9 = (int) (motionEvent.getX(pointerCount) + (motionEvent.getRawX() - motionEvent.getX()));
                    int y = (int) (motionEvent.getY(pointerCount) + (motionEvent.getRawY() - motionEvent.getY()));
                    if ((motionEvent.getActionMasked() == 1 || motionEvent.getActionMasked() == 6 || motionEvent.getActionMasked() == 3) && (findPointerIndex = motionEvent.findPointerIndex(motionEvent.getPointerId(motionEvent.getActionIndex()))) != -1) {
                        x9 = (int) (motionEvent.getX(findPointerIndex) + (motionEvent.getRawX() - motionEvent.getX()));
                        y = (int) (motionEvent.getY(findPointerIndex) + (motionEvent.getRawY() - motionEvent.getY()));
                    }
                    if (x9 >= i11 && x9 <= keys[i10].frameLayout.getWidth() + i11 && y >= i12 && y <= keys[i10].frameLayout.getHeight() + i12) {
                        clickkeys = i10;
                        /*
                            SYMBOL - 1
                            SHIFT - 2
                            BACKSPACE - 3
                            SPACE - 4
                            ENTER - 5
                            SWITCH_NUM - 6
                            SWITCH_NUM2 - 7
                            SWITCH_CMD - 8
                            SWITCH_LANG - 9
                         */
                        if (keys[clickkeys].tag == 1) {
                            int[] iAArr = new int[2];
                            keys[clickkeys].frameLayout.getLocationInWindow(iAArr);
                            Rect rect = new Rect(iAArr[0], iAArr[1], keys[clickkeys].frameLayout.getWidth(), keys[clickkeys].frameLayout.getHeight());
                            FrameLayout.LayoutParams layoutParams = (FrameLayout.LayoutParams) key_hint.getLayoutParams();
                            int i16 = rect.left;
                            int i13 = rect.right;
                            layoutParams.leftMargin = i16;
                            int i14 = rect.top;
                            int i15 = rect.bottom;
                            layoutParams.topMargin = i14 - (i15);
                            layoutParams.width = i13;
                            layoutParams.height = i15 * 2;
                            key_hint.setLayoutParams(layoutParams);
                            FrameLayout.LayoutParams layoutParams2 = (FrameLayout.LayoutParams) ((FrameLayout) key_hint.getChildAt(1)).getLayoutParams();
                            layoutParams2.height = rect.bottom;
                            ((FrameLayout) key_hint.getChildAt(1)).setLayoutParams(layoutParams2);
                            ((ImageView) key_hint.getChildAt(0)).setColorFilter(-10990239, PorterDuff.Mode.SRC_IN);
                            ((ImageView) key_hint.getChildAt(0)).setVisibility(View.VISIBLE);
                            ((ImageView) ((FrameLayout) key_hint.getChildAt(1)).getChildAt(0)).setColorFilter(-10990239, PorterDuff.Mode.SRC_IN);
                            ((TextView) ((FrameLayout) key_hint.getChildAt(1)).getChildAt(1)).setText(((TextView) keys[clickkeys].view).getText());
                            new Handler(Looper.getMainLooper()).postDelayed(new Bykba(), 400L);
                            key_hint.setVisibility(View.VISIBLE);

                        }else if (keys[clickkeys].tag == 3) {
                            new Handler(Looper.getMainLooper()).postDelayed(new backspace(), 150L);
                            Log.e("edgar", "click bakcspase");
                        }else if (keys[clickkeys].tag == 4) {
                            ColorFilter start = ((ImageView) ((FrameLayout) keys[clickkeys].frameLayout).getChildAt(0)).getColorFilter();
                            System.out.println(start);//null
                            Log.e("edgar", "color = " + start);
                            ((ImageView) ((FrameLayout) keys[clickkeys].frameLayout).getChildAt(0)).setColorFilter(-10990239, PorterDuff.Mode.SRC_IN);
                        }
                        break;
                    }
                }
                i10++;
            }
        }

        public class backspace implements Runnable {
            public backspace() {
            }

            @Override // java.lang.Runnable
            public final void run() {
                int cursorPosition = customEditText.getSelectionStart();
                if (cursorPosition > 0) {
                    customEditText.setText(customEditText.getText().delete(cursorPosition - 1, cursorPosition));
                    customEditText.setSelection(cursorPosition-1);
                }
                if(namp){
                    new Handler((Looper.getMainLooper())).postDelayed(this, 5L);
                }
            }
        }

        public boolean yderwal = false;
        public class Bykba implements Runnable {
            public Bykba() {
            }

            @Override // java.lang.Runnable
            public final void run() {
                String a10;
                if ((a10 = Yderhwanie(clickkeys)) == null) {
                    return;
                }
                ((ImageView) ((FrameLayout) key_hint.getChildAt(1)).getChildAt(0)).setColorFilter(-7700589, PorterDuff.Mode.SRC_IN);
                ((TextView) ((FrameLayout) key_hint.getChildAt(1)).getChildAt(1)).setText(a10);

            }
        }
    }

    public class a implements View.OnFocusChangeListener {

            public class RunnableC0028a implements Runnable {

                public final View f2231a;

                public final View.OnFocusChangeListener f2232b;

                public RunnableC0028a(View view, View.OnFocusChangeListener onFocusChangeListener) {
                    this.f2231a = view;
                    this.f2232b = onFocusChangeListener;
                }

                @Override // java.lang.Runnable
                public final void run() {
                    if (vGrop()) {
                        View view = this.f2231a;
                        if (view instanceof CustomEditText) {
                            if (((CustomEditText) view).c.contains(this.f2232b)) {
                                KeyBoard.this.q();
                            }
                        }
                    }
                }
            }

            public a() {
            }

            @Override // android.view.View.OnFocusChangeListener
            public final void onFocusChange(View view, boolean z6) {
                if (z6) {
                    return;
                }
                view.post(new KeyBoard.a.RunnableC0028a(view, this));
            }
        }

        public static class f implements CustomEditText.c {
            public f() {
            }
        }

        public void u() {
            if (!isDialog) {
                this.customEditText = (CustomEditText) viewGroup.findViewById(R.id.input);
                this.layout_input.setVisibility(View.VISIBLE);
                this.customEditText.setText(customEditText.getText());
                customEditText.requestFocus();
            } else {
                this.layout_input.setVisibility(View.GONE);
            }
            this.customEditText.setOnBackListener(new f());
            customEditText.c.add(new a());
            language = 1;
            SetLanguage(1);
            layout_main.getViewTreeObserver().addOnGlobalLayoutListener(this);
            //NvEventQueueActivity.getInstance().getHeightProvider().f9601b.add(this);
            this.layout_keyboard.setVisibility(View.VISIBLE);
            this.send_button.setVisibility(View.GONE);
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
                this.customEditText.setShowSoftInputOnFocus(false);
            }
            InputMethodManager inputMethodManager = (InputMethodManager) NvEventQueueActivity.getInstance().getSystemService(Context.INPUT_METHOD_SERVICE);
            if (inputMethodManager != null && this.nvEventQueueActivity.getCurrentFocus() != null) {
                inputMethodManager.hideSoftInputFromWindow(this.nvEventQueueActivity.getCurrentFocus().getWindowToken(), 0);
            }
            mess = -1;
            history();
            customEditText.setSelection(customEditText.getText().length());
            customEditText.setOnEditorActionListener(null);
        }

        public class h implements TextView.OnEditorActionListener {
            public h() {
            }

            @Override // android.widget.TextView.OnEditorActionListener
            public final boolean onEditorAction(TextView textView, int i10, KeyEvent keyEvent) {
                if (KeyBoard.this.vGrop()) {
                    if (i10 == 6 || i10 == 5) {
                        KeyBoard.this.x();
                    }
                    return false;
                }
                return false;
            }
        }

        public void w() {
            int i10 = caps;
            if (i10 != 2 && i10 != 1) {
                i10 = language;
            }
            SharedPreferences sharedPreferences = nvEventQueueActivity.getSharedPreferences("com.matreshkarp.game.keyboard", 0);
            if (sharedPreferences != null) {
                SharedPreferences.Editor edit = sharedPreferences.edit();
                edit.putString("lang", sgetLaunguage(i10));
                edit.apply();
            }
        }

        public void q() {

            if (vGrop()) {
                w();
                viewGroup.getViewTreeObserver().removeOnGlobalLayoutListener(this);
                //NvEventQueueActivity.getInstance().getHeightProvider().f9601b.remove(this);
                this.customEditText.setOnBackListener(null);
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
                    this.customEditText.setShowSoftInputOnFocus(false);
                }
                InputMethodManager inputMethodManager = (InputMethodManager) NvEventQueueActivity.getInstance().getSystemService(Context.INPUT_METHOD_SERVICE);
                if (inputMethodManager != null && nvEventQueueActivity.getCurrentFocus() != null) {
                    inputMethodManager.hideSoftInputFromWindow(nvEventQueueActivity.getCurrentFocus().getWindowToken(), 0);
                }
                this.customEditText.a(new a());
                this.customEditText.clearFocus();
                Log.i("edgar", "Q Close KeyBoard");
                f();
            }
        }



    public boolean isChatClose;

        public void x() {
            if (vGrop()) {
                w();
                if (messange.size() >= 20) {
                    messange.remove(0);
                }
                messange.add(0, customEditText.getText().toString());
                if(!isChatClose) {
                    sendMessage();
                    isChatClose = true;
                }
                this.viewGroup.getViewTreeObserver().removeOnGlobalLayoutListener(this);
                //NvEventQueueActivity.getInstance().getHeightProvider().f9601b.remove(this);

                this.customEditText.setOnBackListener(null);
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
                    this.customEditText.setShowSoftInputOnFocus(false);
                }
                InputMethodManager inputMethodManager = (InputMethodManager) NvEventQueueActivity.getInstance().getSystemService(Context.INPUT_METHOD_SERVICE);
                if (inputMethodManager != null && nvEventQueueActivity.getCurrentFocus() != null) {
                    inputMethodManager.hideSoftInputFromWindow(nvEventQueueActivity.getCurrentFocus().getWindowToken(), 0);
                }
                this.customEditText.a(new a());
                this.customEditText.clearFocus();
                Log.i("edgar", "X Close KeyBoard");
                f();
            }
        }


        public int r() {
            SharedPreferences sharedPreferences = this.nvEventQueueActivity.getSharedPreferences("com.matreshkarp.game.keyboard", 0);
            if (sharedPreferences == null || !sharedPreferences.contains("keyboardAlpha")) {
                return 0;
            }
            return sharedPreferences.getInt("keyboardAlpha", 0);
        }

        public ViewPropertyAnimator m() {
            this.viewGroup.setClickable(false);
            this.viewGroup.clearAnimation();
            this.viewGroup.setAlpha(1.0f - (r() / 100.0f));
            this.viewGroup.setTranslationY(0.0f);
            Log.i("edgar", "Anim Close KeyBoard");
            return this.viewGroup.animate().setDuration(300L).alpha(0.0f).translationY(this.layout_main.getHeight()).setInterpolator(new DecelerateInterpolator());
        }

        public void SetLanguage(int i10) {
            if (i10 == 5) {
            /*e0 e0Var = new e0(this.f10236a);
            this.y = e0Var;
            e0Var.f2198f = new h0(this);
            this.f2221o.setVisibility(8);
            this.y.l();*/
                return;
            }
        /*e0 e0Var2 = this.y;
        if (e0Var2 != null) {
            e0Var2.f();
            this.y = null;
            this.f2221o.setVisibility(0);
        }*/
            if (i10 == 1) {
                keys[10].frameLayout.setVisibility(View.VISIBLE);
                keys[20].frameLayout.setVisibility(View.VISIBLE);
                keys[21].frameLayout.setVisibility(View.VISIBLE);
                keys[32].frameLayout.setVisibility(View.VISIBLE);
                keys[33].frameLayout.setVisibility(View.VISIBLE);
                keys[22].frameLayout.setVisibility(View.VISIBLE);
                keys[23].frameLayout.setVisibility(View.GONE);
                keys[24].frameLayout.setVisibility(View.GONE);
                LinearLayout.LayoutParams layoutParams = (LinearLayout.LayoutParams) this.f2225s[1].getLayoutParams();
                layoutParams.leftMargin = 0;
                layoutParams.rightMargin = 0;
                this.f2225s[1].setLayoutParams(layoutParams);
                LinearLayout.LayoutParams layoutParams2 = (LinearLayout.LayoutParams) this.f2225s[2].getLayoutParams();
                layoutParams2.leftMargin = 0;
                layoutParams2.rightMargin = 0;
                this.f2225s[2].setLayoutParams(layoutParams2);
                int i12 = 0;
                for (int i13 = 0; i13 < 44; i13++) {
                    if (keys[i13].tag == 1 && keys[i13].frameLayout.getVisibility() == View.VISIBLE) {
                        if (i12 >= 31) {
                            break;
                        }
                        ((TextView) keys[i13].view).setText(String.valueOf("йцукенгшщзхфывапролджэячсмитьбю".charAt(i12)));
                        i12++;
                    }
                }
            } else if (i10 == 2) {
                keys[10].frameLayout.setVisibility(View.GONE);
                keys[20].frameLayout.setVisibility(View.GONE);
                keys[21].frameLayout.setVisibility(View.GONE);
                keys[32].frameLayout.setVisibility(View.GONE);
                keys[33].frameLayout.setVisibility(View.GONE);
                keys[22].frameLayout.setVisibility(View.VISIBLE);
                keys[23].frameLayout.setVisibility(View.GONE);
                keys[24].frameLayout.setVisibility(View.GONE);
                Point point = new Point();
                nvEventQueueActivity.getWindowManager().getDefaultDisplay().getSize(point);
                int dimensionPixelSize = point.x - (nvEventQueueActivity.getResources().getDimensionPixelSize(R.dimen._2sdp) * 2);
                //point.x = dimensionPixelSize;
                int i14 = dimensionPixelSize / 10;
                //point.x = i14;
                point.x = i14 / 2;
                LinearLayout.LayoutParams layoutParams3 = (LinearLayout.LayoutParams) this.f2225s[1].getLayoutParams();
                int i15 = point.x;
                layoutParams3.leftMargin = i15;
                layoutParams3.rightMargin = i15;
                this.f2225s[1].setLayoutParams(layoutParams3);
                LinearLayout.LayoutParams layoutParams4 = (LinearLayout.LayoutParams) this.f2225s[2].getLayoutParams();
                int i16 = point.x;
                layoutParams4.leftMargin = i16;
                layoutParams4.rightMargin = i16;
                this.f2225s[2].setLayoutParams(layoutParams4);
                int i17 = 0;
                for (int i18 = 0; i18 < 44; i18++) {
                    if (keys[i18].tag == 1 && keys[i18].frameLayout.getVisibility() == View.VISIBLE) {
                        if (i17 >= 26) {
                            break;
                        }
                        ((TextView) keys[i18].view).setText(String.valueOf("qwertyuiopasdfghjklzxcvbnm".charAt(i17)));
                        i17++;
                    }
                }
            } else if (i10 == 3) {
                keys[10].frameLayout.setVisibility(View.GONE);
                keys[20].frameLayout.setVisibility(View.VISIBLE);
                keys[21].frameLayout.setVisibility(View.GONE);
                keys[32].frameLayout.setVisibility(View.VISIBLE);
                keys[33].frameLayout.setVisibility(View.GONE);
                keys[22].frameLayout.setVisibility(View.GONE);
                keys[23].frameLayout.setVisibility(View.GONE);
                keys[24].frameLayout.setVisibility(View.VISIBLE);
                LinearLayout.LayoutParams layoutParams5 = (LinearLayout.LayoutParams) this.f2225s[1].getLayoutParams();
                layoutParams5.leftMargin = 0;
                layoutParams5.rightMargin = 0;
                this.f2225s[1].setLayoutParams(layoutParams5);
                LinearLayout.LayoutParams layoutParams6 = (LinearLayout.LayoutParams) this.f2225s[2].getLayoutParams();
                layoutParams6.leftMargin = 0;
                layoutParams6.rightMargin = 0;
                this.f2225s[2].setLayoutParams(layoutParams6);
                int i19 = 0;
                for (int i20 = 0; i20 < 44; i20++) {
                    if (keys[i20].tag == 1 && keys[i20].frameLayout.getVisibility() == View.VISIBLE) {
                        if (i19 >= 28) {
                            break;
                        }
                        ((TextView) keys[i20].view).setText(String.valueOf("1234567890@#₽_&-+()\\\"*:;!$%.".charAt(i19)));
                        i19++;
                    }
                }
            } else if (i10 == 4) {
                keys[10].frameLayout.setVisibility(View.GONE);
                keys[20].frameLayout.setVisibility(View.VISIBLE);
                keys[21].frameLayout.setVisibility(View.GONE);
                keys[32].frameLayout.setVisibility(View.VISIBLE);
                keys[33].frameLayout.setVisibility(View.GONE);
                keys[22].frameLayout.setVisibility(View.GONE);
                keys[23].frameLayout.setVisibility(View.VISIBLE);
                keys[24].frameLayout.setVisibility(View.GONE);
                LinearLayout.LayoutParams layoutParams7 = (LinearLayout.LayoutParams) this.f2225s[1].getLayoutParams();
                layoutParams7.leftMargin = 0;
                layoutParams7.rightMargin = 0;
                this.f2225s[1].setLayoutParams(layoutParams7);
                LinearLayout.LayoutParams layoutParams8 = (LinearLayout.LayoutParams) this.f2225s[2].getLayoutParams();
                layoutParams8.leftMargin = 0;
                layoutParams8.rightMargin = 0;
                this.f2225s[2].setLayoutParams(layoutParams8);
                int i21 = 0;
                for (int i22 = 0; i22 < 44; i22++) {
                    if (keys[i22].tag == 1 && keys[i22].frameLayout.getVisibility() == View.VISIBLE) {
                        if (i21 >= 29) {
                            break;
                        }
                        ((TextView) keys[i22].view).setText(String.valueOf("~`|•‰π÷×§ツ£€‘¢^°={}⋅≠©®™✓[]<>".charAt(i21)));
                        i21++;
                    }
                }
            }
            int i23 = 0;
            while (true) {
                System.out.println(i23);
                if (i23 >= 44) {
                    break;
                }
                if (keys[i23].tag == 9) {
                    TextView textView = (TextView) keys[i23].view;
                    textView.setText((language == 1) ? "eng" : "рус");
                    i23++;
                } else {
                    i23++;
                }
            }
            keys[36].frameLayout.setVisibility(View.GONE);
            keys[37].frameLayout.setVisibility(View.GONE);
            keys[43].frameLayout.setVisibility(View.VISIBLE);
            LinearLayout.LayoutParams layoutParams9 = (LinearLayout.LayoutParams) symbols_layout.getLayoutParams();
            layoutParams9.weight = 20.0f;
            symbols_layout.setLayoutParams(layoutParams9);
            int i25 = caps;
            D(i25);
        }

        public void D(int i10) {
            TextView textView;
            String upperCase;
            caps = i10;
            for (int i13 = 0; i13 < 44; i13++) {
                if (keys[i13].tag == 1) {
                    if (i10 != 2 && i10 != 3) {
                        textView = (TextView) keys[i13].view;
                        upperCase = ((TextView) keys[i13].view).getText().toString().toLowerCase();
                    } else {
                        textView = (TextView) keys[i13].view;
                        upperCase = ((TextView) keys[i13].view).getText().toString().toUpperCase();
                    }
                    textView.setText(upperCase);
                } else if (keys[i13].tag == 2) {
                    ((ImageView) keys[i13].view).setImageResource(i10 == 1 ? R.drawable.ic_shift_off : i10 == 2 ? R.drawable.ic_shift_single : R.drawable.ic_shift_always);
                }
            }
        }

        public static KeyBoard getKeyBoard() {
            return inst;
        }

    public void sendMessage() {
        if (customEditText != null && customEditText.getText().length() > 0) {
            String text = customEditText.getText().toString().trim();
            if (text.length() > 0) {
                try {
                    // Используем метод из ChatManager
                    ChatManager.getChatManager().sendChatMessagesUTF8(text.getBytes("UTF-8"));
                } catch (UnsupportedEncodingException e) {
                    e.printStackTrace();
                }
                
                // Добавляем в историю команд
                if (!messange.contains(text)) {
                    messange.add(0, text);
                }
                
                customEditText.getText().clear();
                mess = -1;
                history();
                
                // Устанавливаем флаг, что чат нужно закрыть
                isChatClose = true;
                
                // Закрываем клавиатуру
                q();
                
                // Сбрасываем флаг после закрытия
                new Handler(Looper.getMainLooper()).postDelayed(() -> {
                    isChatClose = false;
                }, 500);
            }
        }
    }
}
