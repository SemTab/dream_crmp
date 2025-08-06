package com.dmob.cr.gui.util;

public class Damp {

    public static Boolean isCorrupted = false;

    public static int CurrentDialogId = 0;
    public static int ListitemToSend = 0;
    public static String weiktonIP = "127.0.0.1";
    public static int weiktonPORT = 7777;
    public static int cacheStatus = 0;

    public static int playerID = 0;
    public static String nickname = "";
    public static String password_login = "";

    public static Boolean X2 = false;
    public static Boolean ctrl = false;

    public static void setAll(int iCurrentDialogId, int iListitemToSend){
        setCurrentDialogId(iCurrentDialogId);
        setListitemToSend(iListitemToSend);
    }

    public static int GetCurrentDialogId() { return CurrentDialogId; }
    public static int setCurrentDialogId(int nCurrentDialogId) {
        return CurrentDialogId = nCurrentDialogId;
    }

    public static int GetListitemToSend() { return ListitemToSend; }
    public static int setListitemToSend(int nListitemToSend) {
        return ListitemToSend = nListitemToSend;
    }

    public static String getNick(){ return nickname; }
    public static String setNick(String string){
        return nickname = string;
    }

    public static String getPassword(){ return password_login; }
    public static String setPassword(String string){
        return password_login = string;
    }

    public static int GetID() { return playerID; }
    public static int setUID(int id) {
        return playerID = id;
    }

    public static int GetGameType() { return cacheStatus; }
    public static int setGameType(int id) {
        return cacheStatus = id;
    }

    public static boolean GetX2Status() { return X2; }
    public static boolean setX2(boolean tf) {
        return X2 = tf;
    }

    public static boolean getCTRLStatus() { return ctrl; }
    public static boolean setCTRL(boolean tfF) {
        return ctrl = tfF;
    }

    public static String getW_IP(){ return weiktonIP; }
    public static String setIP(String stringIP){
        return weiktonIP = stringIP;
    }

    public static int getW_Port() { return weiktonPORT; }
    public static int setPort(int s_port) {
        return weiktonPORT = s_port;
    }
}
