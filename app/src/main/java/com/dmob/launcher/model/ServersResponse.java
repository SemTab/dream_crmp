package com.dmob.launcher.model;

import com.dmob.launcher.utils.LogHelper;
import com.google.gson.JsonArray;
import com.google.gson.JsonDeserializationContext;
import com.google.gson.JsonDeserializer;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParseException;
import com.google.gson.annotations.SerializedName;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * Wrapper class to handle different formats of servers response
 * Can handle both array and object formats
 */
public class ServersResponse {
    
    private List<Servers> serversList = new ArrayList<>();
    
    public List<Servers> getServersList() {
        return serversList;
    }
    
    /**
     * Custom deserializer for ServersResponse that can handle both array and object formats
     */
    public static class ServersResponseDeserializer implements JsonDeserializer<ServersResponse> {
        @Override
        public ServersResponse deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) 
                throws JsonParseException {
            
            ServersResponse response = new ServersResponse();
            List<Servers> serversList = new ArrayList<>();
            
            try {
                if (json.isJsonArray()) {
                    // Handle array format [{"ip":"...","port":...}]
                    JsonArray jsonArray = json.getAsJsonArray();
                    Type listType = new TypeToken<List<Servers>>(){}.getType();
                    serversList = context.deserialize(jsonArray, listType);
                } 
                else if (json.isJsonObject()) {
                    JsonObject jsonObject = json.getAsJsonObject();
                    
                    // Проверяем наличие поля "servers" - это новый формат { "servers": [...] }
                    if (jsonObject.has("servers") && jsonObject.get("servers").isJsonArray()) {
                        JsonArray serversArray = jsonObject.getAsJsonArray("servers");
                        Type listType = new TypeToken<List<Servers>>(){}.getType();
                        serversList = context.deserialize(serversArray, listType);
                    }
                    // Проверяем, есть ли в объекте поле "ip" - признак того, что это одиночный объект сервера
                    else if (jsonObject.has("ip") && jsonObject.has("port") && jsonObject.has("name")) {
                        // Это одиночный объект сервера, не коллекция
                        Servers server = context.deserialize(jsonObject, Servers.class);
                        if (server != null) {
                            serversList.add(server);
                        }
                    } else {
                        // Handle object format {"server1":{"ip":"...","port":...}}
                        for (Map.Entry<String, JsonElement> entry : jsonObject.entrySet()) {
                            String key = entry.getKey();
                            JsonElement serverElement = entry.getValue();
                            if (serverElement.isJsonObject()) {
                                Servers server = context.deserialize(serverElement, Servers.class);
                                if (server != null) {
                                    serversList.add(server);
                                }
                            }
                            else if (serverElement.isJsonArray()) {
                                // Handle case where values are arrays [hash, size]
                                // This is for the special case in your API, can be customized based on actual data
                            }
                        }
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            
            response.serversList = serversList;
            return response;
        }
    }
} 