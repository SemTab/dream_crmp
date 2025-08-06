package com.dmob.cr.gui;

import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;
import androidx.recyclerview.widget.RecyclerView;

import com.dmob.cr.R;
import com.dmob.launcher.model.Servers;
import com.dmob.launcher.network.Lists;

import java.util.ArrayList;

public class IngameServerAdapter extends RecyclerView.Adapter<IngameServerAdapter.ServerViewHolder> {

    private ArrayList<Servers> servers;
    private OnServerClickListener listener;

    public interface OnServerClickListener {
        void onServerClick(Servers server);
    }

    public IngameServerAdapter(ArrayList<Servers> servers, OnServerClickListener listener) {
        this.servers = servers;
        this.listener = listener;
    }

    @NonNull
    @Override
    public ServerViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.ingame_server_item, parent, false);
        return new ServerViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ServerViewHolder holder, int position) {
        Servers server = servers.get(position);
        
        // Название сервера
        holder.serverName.setText(server.getname());
        
        // Статус сервера вместо IP
        holder.serverStatus.setText("Онлайн сервер");
        
        // Онлайн
        if (server.getMaintenance()) {
            holder.serverOnline.setText("0");
        } else {
            holder.serverOnline.setText(String.valueOf(server.getOnline()));
        }
        
        // Макс. онлайн
        holder.serverMax.setText("/" + server.getmaxOnline());
        
        // Тип сервера (если есть)
        if (!server.getServerType().isEmpty()) {
            holder.serverType.setText(server.getServerType());
            holder.serverType.setVisibility(View.VISIBLE);
        } else {
            holder.serverType.setVisibility(View.GONE);
        }
        
        // Режим X2
        if (server.getx2()) {
            holder.serverX2.setVisibility(View.VISIBLE);
        } else {
            holder.serverX2.setVisibility(View.GONE);
        }
        
        // Технические работы
        if (server.getMaintenance()) {
            holder.serverMaintenance.setText(server.getMaintenanceText());
            holder.serverMaintenance.setVisibility(View.VISIBLE);
        } else {
            holder.serverMaintenance.setVisibility(View.GONE);
        }
        
        // Цвет фона (если указан)
        try {
            holder.serverBackground.setBackgroundColor(Color.parseColor(server.getServerBackgroundColor()));
        } catch (Exception e) {
            // Используем цвет по умолчанию
            holder.serverBackground.setBackgroundColor(Color.parseColor("#2A2E33"));
        }
        
        // Цвет текста (если указан)
        try {
            holder.serverName.setTextColor(Color.parseColor(server.getServerNameColor()));
        } catch (Exception e) {
            // Используем цвет по умолчанию
            holder.serverName.setTextColor(Color.WHITE);
        }
        
        // Обработка нажатия
        holder.itemView.setOnClickListener(v -> {
            if (listener != null && !server.getMaintenance()) {
                listener.onServerClick(server);
            }
        });
        
        // Делаем сервер с тех. работами неактивным
        holder.itemView.setEnabled(!server.getMaintenance());
        holder.itemView.setAlpha(server.getMaintenance() ? 0.7f : 1.0f);
    }

    @Override
    public int getItemCount() {
        return servers.size();
    }

    static class ServerViewHolder extends RecyclerView.ViewHolder {
        TextView serverName;
        TextView serverStatus;
        TextView serverOnline;
        TextView serverMax;
        TextView serverType;
        TextView serverX2;
        TextView serverMaintenance;
        ImageView serverIcon;
        ConstraintLayout serverBackground;

        public ServerViewHolder(@NonNull View itemView) {
            super(itemView);
            serverName = itemView.findViewById(R.id.ingame_server_name);
            serverStatus = itemView.findViewById(R.id.ingame_server_status);
            serverOnline = itemView.findViewById(R.id.ingame_server_online);
            serverMax = itemView.findViewById(R.id.ingame_server_max);
            serverType = itemView.findViewById(R.id.ingame_server_type);
            serverX2 = itemView.findViewById(R.id.ingame_server_x2);
            serverMaintenance = itemView.findViewById(R.id.ingame_server_maintenance);
            serverIcon = itemView.findViewById(R.id.ingame_server_icon);
            serverBackground = itemView.findViewById(R.id.ingame_server_background);
        }
    }
} 