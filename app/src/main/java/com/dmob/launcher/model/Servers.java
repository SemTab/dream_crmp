package com.dmob.launcher.model;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

public class Servers {

	@SerializedName("ip")
	@Expose
	private String ip;

	@SerializedName("port")
	@Expose
	private int port;

	@SerializedName("x2")
	@Expose
	private Boolean x2;

	@SerializedName("name")
	@Expose
	private String name;

	@SerializedName("online")
	@Expose
	private int online;

	@SerializedName("maxOnline")
	@Expose
	private int maxonline;

	@SerializedName("maintenance")
	@Expose
	private Boolean maintenance = false;
	
	@SerializedName("maintenance_text")
	@Expose
	private String maintenanceText = "Технические работы";
	
	@SerializedName("server_type")
	@Expose
	private String serverType = "";
	
	@SerializedName("server_name_color")
	@Expose
	private String serverNameColor = "#FFFFFF";
	
	@SerializedName("server_background_color")
	@Expose
	private String serverBackgroundColor = "#44484E";

	public Servers(String ip, int port, Boolean x2, String name, int online, int maxonline) {
		this.ip = ip;
		this.port = port;
		this.x2 = x2;
		this.name = name;
		this.online = online;
		this.maxonline = maxonline;
	}
	
	public Servers(String ip, int port, Boolean x2, String name, int online, int maxonline, 
				   Boolean maintenance, String maintenanceText, String serverType, 
				   String serverNameColor, String serverBackgroundColor) {
		this.ip = ip;
		this.port = port;
		this.x2 = x2;
		this.name = name;
		this.online = online;
		this.maxonline = maxonline;
		this.maintenance = maintenance;
		this.maintenanceText = maintenanceText;
		this.serverType = serverType;
		this.serverNameColor = serverNameColor;
		this.serverBackgroundColor = serverBackgroundColor;
	}
	 
	public String getname() {
		return name;
	}

	public String getIP() {
		return ip;
	}

	public int getPORT(){
		return port;
	}

    public Boolean getx2() {
		 return x2;
	}
	
	public int getOnline(){
		return online;
	}

	public int getmaxOnline(){
		return maxonline;
	}
	
	public Boolean getMaintenance() {
		return maintenance;
	}
	
	public String getMaintenanceText() {
		return maintenanceText;
	}
	
	public String getServerType() {
		return serverType;
	}
	
	public String getServerNameColor() {
		return serverNameColor;
	}
	
	public String getServerBackgroundColor() {
		return serverBackgroundColor;
	}
}