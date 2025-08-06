package com.dmob.launcher.model;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

import java.io.Serializable;

public class News implements Serializable {

	@SerializedName("imageUrl")
	@Expose
	private String image;

	@SerializedName("title")
	@Expose
	private String title;
	
	@SerializedName("button")
	@Expose
	private String button;
	
	@SerializedName("link")
	@Expose
	private String link;

	public News (String image, String title) {
		this.image = image;
		this.title = title;
	}
	
	public News (String image, String title, String button, String link) {
		this.image = image;
		this.title = title;
		this.button = button;
		this.link = link;
	}

	public String getImageUrl() {
		return image;
	}

	public String getTitle() {
		return title;
	}
	
	public String getButton() {
		return button;
	}
	
	public String getLink() {
		return link;
	}

}