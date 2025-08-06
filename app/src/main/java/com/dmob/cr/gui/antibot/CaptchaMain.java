package com.dmob.cr.gui.antibot;

import android.app.Activity;
import android.widget.Button;
import android.widget.Toast;

import androidx.constraintlayout.widget.ConstraintLayout;

import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;
import com.nvidia.devtech.CustomEditText;
import com.nvidia.devtech.NvEventQueueActivity;

public class CaptchaMain {
    private final ConstraintLayout mInputLayout;

    public CaptchaMain(Activity activity) {
        mInputLayout = activity.findViewById(R.id.brp_captcha_main);

        Captcha captcha = activity.findViewById(R.id.brp_captcha_main_view);
        Button completeButton = activity.findViewById(R.id.brp_captcha_complete_btn);
        CustomEditText code = activity.findViewById(R.id.brp_captcha_code_et);

        completeButton.setOnClickListener(view -> {
            if (code.getText().toString().equals(captcha.getCode())) {
                Utils.HideLayout(this.mInputLayout, true);
                NvEventQueueActivity.getInstance().hideCaptcha();
            } else NvEventQueueActivity.getInstance().showNotification(0, "Код введен не верно", 5, "", "");
        });

        Utils.HideLayout(this.mInputLayout, false);
    }

    public ConstraintLayout getInputLayout() {
        return mInputLayout;
    }
}
