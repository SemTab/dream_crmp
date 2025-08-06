package com.dmob.cr.gui.antibot;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.util.AttributeSet;
import android.view.View;

import androidx.annotation.Nullable;

import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;

import java.util.Random;

public class Captcha extends View {

    private Paint mTextPaint;
    private Paint mLinePaint;
    private String mCode;

    public Captcha(Context context) {
        super(context);

        init(context);
    }

    public Captcha(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);

        init(context);
    }

    public Captcha(Context context, @Nullable AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);

        init(context);
    }

    public Captcha(Context context, @Nullable AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);

        init(context);
    }

    private void init(Context context) {
        this.mTextPaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        this.mTextPaint.setColor(0xFFFFFFFF);
        this.mTextPaint.setTextSize(context.getResources().getDimensionPixelSize(R.dimen._20sdp));
        
        this.mLinePaint = new Paint(Paint.ANTI_ALIAS_FLAG);
        this.mLinePaint.setColor(0x80FFFFFF);
        this.mLinePaint.setStrokeWidth(2f);
    }

    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);

        this.mCode = Utils.randomString(6);

        int posX = (int) ((canvas.getWidth() - mTextPaint.getTextSize() * 6) / 2);
        int posY = (int) ((canvas.getHeight() + mTextPaint.getTextSize()) / 2);
        
        Random random = new Random();
        
        for (int i = 0; i < 10; i++) {
            int startX = random.nextInt(canvas.getWidth());
            int startY = random.nextInt(canvas.getHeight());
            int endX = random.nextInt(canvas.getWidth());
            int endY = random.nextInt(canvas.getHeight());
            
            canvas.drawLine(startX, startY, endX, endY, mLinePaint);
        }

        for (int i = 0; i < this.mCode.length(); i++) {
            float rotation = -15 + random.nextInt(30);
            
            canvas.save();
            
            canvas.rotate(rotation, posX, posY);
            
            canvas.drawText(String.valueOf(this.mCode.charAt(i)), posX, posY, mTextPaint);
            
            canvas.restore();
            
            posX += mTextPaint.getTextSize() + random.nextInt(15);
            posY += random.nextInt(15) + random.nextInt(25) * -1;
        }
    }

    public String getCode() {
        return this.mCode;
    }
}
