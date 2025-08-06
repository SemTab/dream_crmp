package com.dmob.launcher.adapter;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.ValueAnimator;
import android.app.Activity;
import android.graphics.Color;
import android.graphics.Typeface;
import android.os.Handler;
import android.os.Looper;
import android.text.Html;
import android.text.SpannableString;
import android.text.TextUtils;
import android.text.method.LinkMovementMethod;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.LinearInterpolator;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.core.content.res.ResourcesCompat;
import androidx.recyclerview.widget.RecyclerView;

import com.dmob.cr.R;

import java.util.ArrayList;

public class FaqAdapter extends RecyclerView.Adapter<RecyclerView.ViewHolder> {
    /* access modifiers changed from: private */
    public final Activity mContext;
    private ArrayList<FaqInfo> mList;
    /* access modifiers changed from: private */
    public ViewHolder mOpenedViewHolder = null;

    public final class ViewHolder extends RecyclerView.ViewHolder {
        public ValueAnimator mAnimator = null;
        public final ImageView mArrow;
        public final TextView mCaption;
        public float mCurPercent = 0.0f;
        public CharSequence mFormattedText;
        public final Handler mHandler = new Handler(Looper.getMainLooper());
        public boolean mIsOpen = false;
        public final TextView mText;
        /* access modifiers changed from: private */
        public final View mView;

        public ViewHolder(View view) {
            super(view);
            this.mView = view;
            this.mCaption = (TextView) view.findViewById(R.id.faq_item_caption);
            this.mArrow = (ImageView) view.findViewById(R.id.faq_item_arrow);
            this.mText = (TextView) view.findViewById(R.id.faq_item_text);
        }
    }

    public FaqAdapter(Activity activity) {
        this.mContext = activity;
    }

    public void setFaqList(ArrayList<FaqInfo> arrayList) {
        this.mList = new ArrayList<>(arrayList);
        notifyDataSetChanged();
    }

    public RecyclerView.ViewHolder onCreateViewHolder(ViewGroup viewGroup, int i) {
        return new ViewHolder(LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.faq_item, viewGroup, false));
    }

    public void onBindViewHolder(RecyclerView.ViewHolder viewHolder, int i) {
        onBindViewHolder((ViewHolder) viewHolder, i);
    }

    public void onBindViewHolder(final ViewHolder viewHolder, int i) {
        viewHolder.mCaption.setTypeface(ResourcesCompat.getFont(this.mContext, R.font.gotham_pro_regular));
        viewHolder.mArrow.setRotation(0.0f);
        viewHolder.mText.setVisibility(View.VISIBLE);
        viewHolder.mText.setMaxHeight(0);
        viewHolder.mText.setScrollY(0);
        if (viewHolder.mAnimator != null) {
            viewHolder.mAnimator.removeAllListeners();
            viewHolder.mAnimator.removeAllUpdateListeners();
            viewHolder.mAnimator.cancel();
        }
        viewHolder.mIsOpen = false;
        viewHolder.mCurPercent = 0.0f;
        FaqInfo faqInfo = this.mList.get(i);
        viewHolder.mCaption.setText(faqInfo.caption);
        SpannableString spannableString = new SpannableString(faqInfo.caption + "\n\n");
        spannableString.setSpan(new CustomTypefaceSpan(ResourcesCompat.getFont(this.mContext, R.font.gotham_pro_medium)), 0, spannableString.length(), 33);
        viewHolder.mFormattedText = TextUtils.concat(new CharSequence[]{spannableString, Html.fromHtml(faqInfo.text)});
        viewHolder.mText.setText(viewHolder.mFormattedText);
        viewHolder.mText.setMovementMethod(LinkMovementMethod.getInstance());
        viewHolder.mText.setLinkTextColor(Color.GRAY);
        viewHolder.mText.setHighlightColor(0);
        viewHolder.mView.setOnTouchListener(new ButtonAnimator(this.mContext, viewHolder.mView));
        viewHolder.mView.setOnClickListener(new View.OnClickListener() {
            public void onClick(View view) {
                if (FaqAdapter.this.mOpenedViewHolder != null && FaqAdapter.this.mOpenedViewHolder.mIsOpen) {
                    FaqAdapter.this.mOpenedViewHolder.mCaption.setTypeface(ResourcesCompat.getFont(FaqAdapter.this.mContext, R.font.gotham_pro_regular));
                    if (FaqAdapter.this.mOpenedViewHolder.mAnimator != null) {
                        FaqAdapter.this.mOpenedViewHolder.mAnimator.removeAllListeners();
                        FaqAdapter.this.mOpenedViewHolder.mAnimator.removeAllUpdateListeners();
                        FaqAdapter.this.mOpenedViewHolder.mAnimator.cancel();
                    }
                    FaqAdapter.this.mOpenedViewHolder.mAnimator = ValueAnimator.ofFloat(new float[]{FaqAdapter.this.mOpenedViewHolder.mCurPercent, 0.0f});
                    final ViewHolder access$100 = FaqAdapter.this.mOpenedViewHolder;
                    FaqAdapter.this.mOpenedViewHolder.mAnimator.addUpdateListener(new ValueAnimator.AnimatorUpdateListener() {
                        public void onAnimationUpdate(ValueAnimator valueAnimator) {
                            access$100.mCurPercent = ((Float) valueAnimator.getAnimatedValue()).floatValue();
                            access$100.mArrow.setRotation(access$100.mCurPercent * -180.0f);
                            access$100.mText.setMaxHeight((int) (access$100.mCurPercent * ((float) FaqAdapter.this.getTextHeight(access$100.mFormattedText, (float) FaqAdapter.this.mContext.getResources().getDimensionPixelSize(R.dimen._10sdp), access$100.mView.getWidth(), ResourcesCompat.getFont(FaqAdapter.this.mContext, R.font.gotham_pro_regular)))));
                            access$100.mText.setScrollY(0);
                        }
                    });
                    FaqAdapter.this.mOpenedViewHolder.mAnimator.addListener(new AnimatorListenerAdapter() {
                        public void onAnimationEnd(Animator animator) {
                            super.onAnimationEnd(animator);
                            access$100.mCurPercent = 0.0f;
                            access$100.mAnimator.cancel();
                            access$100.mAnimator = null;
                        }
                    });
                    FaqAdapter.this.mOpenedViewHolder.mAnimator.setInterpolator(new LinearInterpolator());
                    FaqAdapter.this.mOpenedViewHolder.mAnimator.setDuration((long) (FaqAdapter.this.mOpenedViewHolder.mCurPercent * 400.0f));
                    FaqAdapter.this.mOpenedViewHolder.mAnimator.start();
                    FaqAdapter.this.mOpenedViewHolder.mIsOpen = false;
                    if (FaqAdapter.this.mOpenedViewHolder == viewHolder) {
                        ViewHolder unused = FaqAdapter.this.mOpenedViewHolder = null;
                        return;
                    }
                    ViewHolder unused2 = FaqAdapter.this.mOpenedViewHolder = null;
                }
                ViewHolder unused3 = FaqAdapter.this.mOpenedViewHolder = viewHolder;
                viewHolder.mCaption.setTypeface(ResourcesCompat.getFont(FaqAdapter.this.mContext, R.font.gotham_pro_medium));
                if (viewHolder.mAnimator != null) {
                    viewHolder.mAnimator.removeAllListeners();
                    viewHolder.mAnimator.removeAllUpdateListeners();
                    viewHolder.mAnimator.cancel();
                }
                viewHolder.mAnimator = ValueAnimator.ofFloat(new float[]{viewHolder.mCurPercent, 1.0f});
                viewHolder.mAnimator.addUpdateListener(new ValueAnimator.AnimatorUpdateListener() {
                    public void onAnimationUpdate(ValueAnimator valueAnimator) {
                        viewHolder.mCurPercent = ((Float) valueAnimator.getAnimatedValue()).floatValue();
                        viewHolder.mArrow.setRotation(viewHolder.mCurPercent * -180.0f);
                        viewHolder.mText.setMaxHeight((int) (viewHolder.mCurPercent * ((float) FaqAdapter.this.getTextHeight(viewHolder.mFormattedText, (float) FaqAdapter.this.mContext.getResources().getDimensionPixelSize(R.dimen._10sdp), viewHolder.mView.getWidth(), ResourcesCompat.getFont(FaqAdapter.this.mContext, R.font.gotham_pro_regular)))));
                        viewHolder.mText.setScrollY(0);
                    }
                });
                viewHolder.mAnimator.addListener(new AnimatorListenerAdapter() {
                    public void onAnimationEnd(Animator animator) {
                        super.onAnimationEnd(animator);
                        viewHolder.mCurPercent = 1.0f;
                        viewHolder.mAnimator.cancel();
                        viewHolder.mAnimator = null;
                    }
                });
                viewHolder.mAnimator.setInterpolator(new LinearInterpolator());
                viewHolder.mAnimator.setDuration((long) ((1.0f - viewHolder.mCurPercent) * 400.0f));
                viewHolder.mAnimator.start();
                viewHolder.mIsOpen = true;
            }
        });
    }

    /* access modifiers changed from: package-private */
    public int getTextHeight(CharSequence charSequence, float f, int i, Typeface typeface) {
        TextView textView = new TextView(this.mContext);
        textView.setPadding(this.mContext.getResources().getDimensionPixelSize(R.dimen._18sdp), this.mContext.getResources().getDimensionPixelSize(R.dimen._12sdp), this.mContext.getResources().getDimensionPixelSize(R.dimen._18sdp), this.mContext.getResources().getDimensionPixelSize(R.dimen._12sdp));
        textView.setTypeface(typeface);
        textView.setText(charSequence, TextView.BufferType.SPANNABLE);
        textView.setTextSize(0, f);
        textView.measure(View.MeasureSpec.makeMeasureSpec(i, View.MeasureSpec.AT_MOST), View.MeasureSpec.makeMeasureSpec(0, View.MeasureSpec.UNSPECIFIED));
        return textView.getMeasuredHeight();
    }

    public int getItemCount() {
        return this.mList.size();
    }
}

