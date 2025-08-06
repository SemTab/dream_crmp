package com.dmob.cr.gui.dialogs;

import android.app.Activity;
import android.content.Context;
import android.content.res.Configuration;
import android.text.Editable;
import android.text.method.PasswordTransformationMethod;
import android.view.KeyEvent;
import android.view.View;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.FrameLayout;
import android.widget.ScrollView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.LinearLayoutManager;


import com.nvidia.devtech.CustomEditText;
import com.nvidia.devtech.NvEventQueueActivity;
import com.dmob.cr.R;
import com.dmob.cr.gui.util.CustomRecyclerView;
import com.dmob.cr.gui.util.Utils;

import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Timer;
import java.util.TimerTask;

public class Dialog {

    private static final int DIALOG_STYLE_MSGBOX = 0;
    private static final int DIALOG_STYLE_INPUT = 1;
    private static final int DIALOG_STYLE_LIST = 2;
    private static final int DIALOG_STYLE_PASSWORD = 3;
    private static final int DIALOG_STYLE_TABLIST = 4;
    private static final int DIALOG_STYLE_TABLIST_HEADER = 5;

    private static final int DIALOG_LEFT_BTN_ID = 1;
    private static final int DIALOG_RIGHT_BTN_ID = 0;

    private final ConstraintLayout mMainLayout;

    private final ConstraintLayout mInputLayout;
    private final ConstraintLayout mListLayout;

    private final ScrollView mMsgBoxLayout;

    private final TextView mCaption;
    private final TextView mContent;

    private final ConstraintLayout mLeftBtn;
    private final ConstraintLayout mRightBtn;

    private final CustomEditText mInput;

    private final CustomRecyclerView mCustomRecyclerView;

    private int mCurrentDialogId = -1;
    private int mCurrentDialogTypeId = -1;
    private int mCurrentListItem = -1;

    private String mCurrentInputText = "";

    private ArrayList<String> mRowsList;
    private final ArrayList<TextView> mHeadersList;

    public Dialog(Activity activity) {
        this.mMainLayout = activity.findViewById(R.id.sd_dialog_main);

        this.mCaption = activity.findViewById(R.id.sd_dialog_caption);
        this.mContent = activity.findViewById(R.id.sd_dialog_text);

        this.mLeftBtn = activity.findViewById(R.id.sd_button_positive);
        this.mRightBtn = activity.findViewById(R.id.sd_button_negative);

        this.mInputLayout = activity.findViewById(R.id.sd_dialog_input_layout);
        this.mListLayout = activity.findViewById(R.id.sd_dialog_list_layout);

        this.mMsgBoxLayout = activity.findViewById(R.id.sd_dialog_text_layout);

        this.mInput = activity.findViewById(R.id.sd_dialog_input);

        this.mCustomRecyclerView = activity.findViewById(R.id.sd_dialog_list_recycler);

        this.mLeftBtn.setOnClickListener(view -> sendDialogResponse(DIALOG_LEFT_BTN_ID));
        this.mRightBtn.setOnClickListener(view -> sendDialogResponse(DIALOG_RIGHT_BTN_ID));

        this.mRowsList = new ArrayList<>();
        this.mHeadersList = new ArrayList<>();

        ConstraintLayout mHeadersLayout = activity.findViewById(R.id.sd_dialog_tablist_row);
        for (int i = 0; i < mHeadersLayout.getChildCount(); i++)
            this.mHeadersList.add((TextView) mHeadersLayout.getChildAt(i));

        this.mInput.setOnEditorActionListener((textView, i, keyEvent) -> {
            if(i == EditorInfo.IME_ACTION_DONE || i == EditorInfo.IME_ACTION_NEXT)
            {
                Editable editableText = this.mInput.getText();

                if(editableText != null)
                    this.mCurrentInputText = editableText.toString();
            }

            return false;
        });

        this.mInput.setOnClickListener(view -> {
            this.mInput.requestFocus();

            InputMethodManager imm = (InputMethodManager) NvEventQueueActivity.getInstance().getSystemService(Context.INPUT_METHOD_SERVICE);
            imm.showSoftInput(this.mInput, InputMethodManager.SHOW_IMPLICIT);
        });

        //Timer myTimer;
        //myTimer = new Timer();

        //myTimer.schedule(new TimerTask() {
        //    public void run() {
        //        mContent.setVisibility(View.VISIBLE);
        //    }
        //}, 0, 1000);

        Utils.HideLayout(this.mMainLayout, false);
    }

    public void show(int dialogId, int dialogTypeId, String caption, String content, String leftBtnText, String rightBtnText) {
        clearDialogData();

        this.mCurrentDialogId = dialogId;
        this.mCurrentDialogTypeId = dialogTypeId;

        switch (dialogTypeId) {
            case DIALOG_STYLE_MSGBOX:
                this.mInputLayout.setVisibility(View.GONE);
                this.mListLayout.setVisibility(View.GONE);

                this.mMsgBoxLayout.setVisibility(View.VISIBLE);
                break;
            case DIALOG_STYLE_PASSWORD:
                this.mInput.setTransformationMethod(new PasswordTransformationMethod());

                this.mInputLayout.setVisibility(View.VISIBLE);
                this.mMsgBoxLayout.setVisibility(View.VISIBLE);

                this.mListLayout.setVisibility(View.GONE);
            case DIALOG_STYLE_INPUT:
                this.mInputLayout.setVisibility(View.VISIBLE);
                this.mMsgBoxLayout.setVisibility(View.VISIBLE);

                this.mListLayout.setVisibility(View.GONE);
                break;
            case DIALOG_STYLE_LIST:
            case DIALOG_STYLE_TABLIST:
            case DIALOG_STYLE_TABLIST_HEADER:
                this.mInputLayout.setVisibility(View.GONE);
                this.mMsgBoxLayout.setVisibility(View.GONE);

                this.mListLayout.setVisibility(View.VISIBLE);

                loadTabList(content);

                this.mRowsList = Utils.fixFieldsForDialog(this.mRowsList);
                DialogAdapter adapter = new DialogAdapter(this.mRowsList, this.mHeadersList);

                adapter.setOnClickListener((i, str) -> {
                    if(NvEventQueueActivity.getInstance().getCaptcha())
                        return;

                    this.mCurrentListItem = i;
                    this.mCurrentInputText = str;
                });

                adapter.setOnDoubleClickListener(() -> sendDialogResponse(DIALOG_LEFT_BTN_ID));

                this.mCustomRecyclerView.setLayoutManager(new LinearLayoutManager(NvEventQueueActivity.getInstance()));
                this.mCustomRecyclerView.setAdapter(adapter);

                if (dialogTypeId != DIALOG_STYLE_LIST)
                    this.mCustomRecyclerView.post(adapter::updateSizes);

                break;
        }

        this.mCaption.setText(Utils.transfromColors(caption));
        this.mContent.setText(Utils.transfromColors(content));

        TextView leftBtnTV = (TextView) this.mLeftBtn.getChildAt(0);
        TextView rightBtnTV = (TextView) this.mRightBtn.getChildAt(0);

        leftBtnTV.setText(Utils.transfromColors(leftBtnText));
        rightBtnTV.setText(Utils.transfromColors(rightBtnText));

        if (rightBtnText.equals(""))
            this.mRightBtn.setVisibility(View.GONE);
        else this.mRightBtn.setVisibility(View.VISIBLE);

        Utils.ShowLayout(this.mMainLayout, true);
    }

    public void hideWithoutReset() {
        Utils.HideLayout(this.mMainLayout, false);
    }

    public void showWithOldContent() {
        Utils.ShowLayout(this.mMainLayout, false);
    }

    public void sendDialogResponse(int btnId) {
        if(NvEventQueueActivity.getInstance().getCaptcha())
            return;

        if (!this.mCurrentInputText.equals(this.mInput.getText().toString()))
            this.mCurrentInputText = this.mInput.getText().toString();

        InputMethodManager imm = (InputMethodManager) NvEventQueueActivity.getInstance().getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(this.mInput.getWindowToken(), 0);

        try {
            NvEventQueueActivity.getInstance().sendDialogResponse(btnId, this.mCurrentDialogId, this.mCurrentListItem, this.mCurrentInputText.getBytes("windows-1251"));
            Utils.HideLayout(this.mMainLayout, true);
        }
        catch (UnsupportedEncodingException e){
            e.printStackTrace();
        }
    }

    private void loadTabList(String content) {
        String[] strings = content.split("\n");

        for (int i = 0; i < strings.length; i++) {
            if (this.mCurrentDialogTypeId == DIALOG_STYLE_TABLIST_HEADER && i == 0) {
                String[] headers = strings[i].split("\t");

                for (int j = 0; j < headers.length; j++)
                {
                    this.mHeadersList.get(j).setText(Utils.transfromColors(headers[j]));
                    this.mHeadersList.get(j).setVisibility(View.VISIBLE);
                }
            } else {
                this.mRowsList.add(strings[i]);
            }
        }
    }

    private void clearDialogData() {
        this.mInput.setTransformationMethod(null);
        this.mInput.setText("");

        this.mCurrentDialogId = -1;
        this.mCurrentDialogTypeId = -1;
        this.mCurrentListItem = -1;

        this.mRowsList.clear();

        for (int i = 0; i < this.mHeadersList.size(); i++)
            this.mHeadersList.get(i).setVisibility(View.GONE);
    }

    public void onHeightChanged(int height) {
        FrameLayout.LayoutParams params = (FrameLayout.LayoutParams) mMainLayout.getLayoutParams();
        params.setMargins(0, 0 , 0, height);

        mMainLayout.setLayoutParams(params);
    }

    public boolean isActive() {
        return this.mMainLayout.getVisibility() == View.VISIBLE;
    }
}
