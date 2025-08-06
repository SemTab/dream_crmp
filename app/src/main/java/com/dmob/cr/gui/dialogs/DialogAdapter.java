package com.dmob.cr.gui.dialogs;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;


import com.dmob.cr.R;
import com.dmob.cr.gui.util.Utils;

import java.util.ArrayList;

public class DialogAdapter extends RecyclerView.Adapter {

    private OnClickListener mOnClickListener;
    private OnDoubleClickListener mOnDoubleClickListener;

    private final ArrayList<String> mFieldTexts;
    private final ArrayList<TextView> mFieldHeaders;
    private final ArrayList<ArrayList<TextView>> mFields;

    private int mCurrentSelectedPosition = 0;
    private View mCurrentSelectedView;

    public interface OnClickListener {
        void onClick(int i, String str);
    }

    public interface OnDoubleClickListener {
        void onDoubleClick();
    }

    public DialogAdapter(ArrayList<String> fields, ArrayList<TextView> fieldHeaders) {
        this.mFieldTexts = fields;
        this.mFieldHeaders = fieldHeaders;

        this.mFields = new ArrayList<>();
    }

    @NonNull
    @Override
    public RecyclerView.ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        return new ViewHolder(LayoutInflater.from(parent.getContext()).inflate(R.layout.sd_dialog_item, parent, false));
    }

    @Override
    public void onBindViewHolder(@NonNull RecyclerView.ViewHolder holder, int position) {
        this.onBindViewHolder((ViewHolder) holder, position);
    }

    public void onBindViewHolder(@NonNull final ViewHolder holder, int position) {
        String[] headers = this.mFieldTexts.get(position).split("\t");

        ArrayList<TextView> fields = new ArrayList<>();

        for (int i = 0; i < headers.length; i++) {
            TextView field = holder.mFields.get(i);

            field.setText(Utils.transfromColors(headers[i].replace("\\t", "")));
            field.setVisibility(View.VISIBLE);

            fields.add(field);
        }

        this.mFields.add(fields);

        if (this.mCurrentSelectedPosition == position) {
            this.mCurrentSelectedView = holder.itemView;
            holder.itemView.setBackgroundResource(R.drawable.dialog_first_btn_bg);

            this.mOnClickListener.onClick(position, holder.mFields.get(0).getText().toString());
        } else {
            holder.itemView.setBackground(null);
        }

        holder.getView().setOnClickListener(view -> {
            if (this.mCurrentSelectedPosition != position) {
                if (this.mCurrentSelectedView != null) {
                    this.mCurrentSelectedView.setBackground(null);
                }

                this.mCurrentSelectedPosition = position;
                this.mCurrentSelectedView = holder.itemView;

                holder.itemView.setBackgroundResource(R.drawable.dialog_first_btn_bg);

                this.mOnClickListener.onClick(position, holder.mFields.get(0).getText().toString());
            } else if (this.mOnDoubleClickListener != null)
                this.mOnDoubleClickListener.onDoubleClick();
        });
    }

    public void updateSizes() {
        int[] max = new int[4];

        for (int i = 0; i < this.mFields.size(); i++) {
            for (int j = 0; j < this.mFields.get(i).size(); j++) {
                int width = this.mFields.get(i).get(j).getWidth();

                if (max[j] < width)
                    max[j] = width;
            }
        }

        for (int i = 0; i < max.length; i++) {
            int headerWidth = this.mFieldHeaders.get(i).getWidth();

            Log.i("DIALOG", max[i] + "\t" + this.mFieldHeaders.get(i).getText() + " " + headerWidth);

            if (max[i] < headerWidth)
                max[i] = headerWidth;
        }

        for (int i = 0; i < this.mFields.size(); i++) {
            for (int j = 0; j < this.mFields.get(i).size(); j++)
                this.mFields.get(i).get(j).setWidth(max[j]);
        }

        for (int i = 0; i < this.mFieldHeaders.size(); i++)
            this.mFieldHeaders.get(i).setWidth(max[i]);
    }

    public void setOnClickListener(OnClickListener onClickListener) {
        this.mOnClickListener = onClickListener;
    }

    public void setOnDoubleClickListener(OnDoubleClickListener onDoubleClickListener) {
        this.mOnDoubleClickListener = onDoubleClickListener;
    }

    public ArrayList<ArrayList<TextView>> getFields() {
        return mFields;
    }

    @Override
    public int getItemCount() {
        return this.mFieldTexts.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {

        public ArrayList<TextView> mFields;
        private final View mView;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);

            this.mView = itemView;

            ConstraintLayout field = itemView.findViewById(R.id.sd_dialog_item_row);
            this.mFields = new ArrayList<>();

            this.mFields.add(field.findViewById(R.id.dialog_field1));
            this.mFields.add(field.findViewById(R.id.dialog_field2));
            this.mFields.add(field.findViewById(R.id.dialog_field3));
            this.mFields.add(field.findViewById(R.id.dialog_field4));
        }

        public View getView() {
            return mView;
        }
    }
}
