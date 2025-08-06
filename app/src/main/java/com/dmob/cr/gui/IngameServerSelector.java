package com.dmob.cr.gui;

import android.app.Activity;
import android.view.View;

import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.dmob.cr.R;
import com.dmob.cr.gui.util.Damp;
import com.dmob.launcher.model.Servers;
import com.dmob.launcher.network.Lists;
import com.nvidia.devtech.NvEventQueueActivity;

public class IngameServerSelector implements IngameServerAdapter.OnServerClickListener {

    private Activity activity;
    private View selectorView;
    private RecyclerView serversRecyclerView;
    private IngameServerAdapter serverAdapter;

    public IngameServerSelector(Activity activity) {
        this.activity = activity;
        init();
    }

    private void init() {
        // Инициализация представления
        selectorView = activity.findViewById(R.id.ingame_server_selector);
        
        // Инициализация RecyclerView
        serversRecyclerView = selectorView.findViewById(R.id.ingame_servers_recycler);
        serversRecyclerView.setLayoutManager(new LinearLayoutManager(activity));
        
        // Создание адаптера
        serverAdapter = new IngameServerAdapter(Lists.slist, this);
        serversRecyclerView.setAdapter(serverAdapter);
        
        // При инициализации окно выбора сервера скрыто
        selectorView.setVisibility(View.GONE);
    }

    /**
     * Показать экран выбора сервера
     */
    public void show() {
        selectorView.setVisibility(View.VISIBLE);
    }

    /**
     * Скрыть экран выбора сервера
     */
    public void hide() {
        selectorView.setVisibility(View.GONE);
    }

    /**
     * Обновить список серверов
     */
    public void updateServers() {
        if (serverAdapter != null) {
            serverAdapter.notifyDataSetChanged();
        }
    }

    /**
     * Обработчик выбора сервера
     */
    @Override
    public void onServerClick(Servers server) {
        // Устанавливаем выбранный IP и порт
        Damp.setIP(server.getIP());
        Damp.setPort(server.getPORT());
        Damp.setX2(server.getx2());
        
        // Сообщаем системе, что сервер выбран
        NvEventQueueActivity.getInstance().sendServerSelected(
            server.getIP(),
            server.getPORT(),
            server.getx2() ? 1 : 0
        );
        
        // Скрываем селектор
        hide();
    }
    
    /**
     * Встроить в активность
     */
    public static void showServerSelector(Activity activity) {
        IngameServerSelector selector = new IngameServerSelector(activity);
        selector.show();
    }
} 