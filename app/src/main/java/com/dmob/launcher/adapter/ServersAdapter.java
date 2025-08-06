package com.dmob.launcher.adapter;

import android.view.LayoutInflater;
import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.*;
import android.graphics.Color;

import androidx.recyclerview.widget.RecyclerView;
import androidx.annotation.NonNull;
import androidx.constraintlayout.widget.ConstraintLayout;

import com.dmob.cr.gui.util.Damp;
import com.dmob.cr.R;
import com.dmob.launcher.model.Servers;
import java.util.ArrayList;

public class ServersAdapter extends RecyclerView.Adapter<ServersAdapter.ServersViewHolder> {
	Context context;
	
	ArrayList<Servers> slist;
	
	public ServersAdapter(Context context, ArrayList<Servers> slist){
		 this.context = context;
		 this.slist = slist; 
	}
	
	@NonNull
	@Override
    public ServersViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(context).inflate(R.layout.servers_layout_new, parent, false);
		return new ServersViewHolder(v); 
    }

    @Override
    public void onBindViewHolder(@NonNull ServersViewHolder holder, int position) {
        Servers servers = slist.get(position);
        Damp.setIP(servers.getIP());
        Damp.setPort(servers.getPORT());
        
        // Установка цвета фона сервера
        try {
            holder.serverBackground.setBackgroundColor(Color.parseColor(servers.getServerBackgroundColor()));
        } catch (Exception e) {
            // Если ошибка парсинга, используем цвет по умолчанию
            holder.serverBackground.setBackgroundColor(Color.parseColor("#44484E"));
        }
        
        // Установка цвета текста названия сервера
        try {
            holder.serverText.setTextColor(Color.parseColor(servers.getServerNameColor()));
        } catch (Exception e) {
            // Если ошибка парсинга, используем цвет по умолчанию
            holder.serverText.setTextColor(Color.WHITE);
        }
        
        // Установка режима x2
        if(servers.getx2() == false) {
            holder.x2.setVisibility(View.INVISIBLE);
            holder.a.setVisibility(View.INVISIBLE);
            Damp.setX2(false);
        } else {
            holder.x2.setVisibility(View.VISIBLE);
            holder.a.setVisibility(View.VISIBLE);
            Damp.setX2(true);
        }
        
        // Отображение статуса технических работ
        if(servers.getMaintenance()) {
            holder.maintenance.setVisibility(View.VISIBLE);
            holder.maintenance.setText(servers.getMaintenanceText());
            
            // При технических работах онлайн показывать как 0
            holder.onlineText.setText("0");
            holder.maxOnlineText.setText("/" + Integer.toString(servers.getmaxOnline()));
        } else {
            holder.maintenance.setVisibility(View.GONE);
        holder.onlineText.setText(Integer.toString(servers.getOnline()));
        holder.maxOnlineText.setText("/" + Integer.toString(servers.getmaxOnline()));
        }
        
        // Отображение типа сервера (тестовый и т.д.)
        if(!servers.getServerType().isEmpty()) {
            holder.serverType.setText(servers.getServerType());
            holder.serverType.setVisibility(View.VISIBLE);
        } else {
            holder.serverType.setVisibility(View.GONE);
        }
        
        holder.serverText.setText(servers.getname());
    }

    @Override
    public int getItemCount() {
        return slist.size();
    }

    public static class ServersViewHolder extends RecyclerView.ViewHolder {

        public TextView onlineText;
        public TextView serverText;
        public TextView maxOnlineText;
        public TextView x2;
        public TextView a;
        public TextView maintenance;
        public TextView serverType;
        public ConstraintLayout serverBackground;
	    
        public ServersViewHolder(View itemView) {
            super(itemView);
            
            serverBackground = itemView.findViewById(R.id.server_background);
		    x2 = itemView.findViewById(R.id.brp_launcher_server_double);
            a = itemView.findViewById(R.id.brp_launcher_server_shipping);
            serverText = itemView.findViewById(R.id.brp_launcher_server_title);
            onlineText = itemView.findViewById(R.id.brp_launcher_server_online);
            maxOnlineText = itemView.findViewById(R.id.textView5);
            maintenance = itemView.findViewById(R.id.brp_launcher_server_maintenance);
            serverType = itemView.findViewById(R.id.brp_launcher_server_type);
        }
    }
}