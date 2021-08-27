package com.sharetrace.cocos;

import android.util.Log;

import cn.net.shoot.sharetracesdk.AppData;
import cn.net.shoot.sharetracesdk.ShareTraceInstallListener;

public class InstallCallback implements ShareTraceInstallListener {

    private static final String TAG = "ShareTrace";

    native void install(AppData appData);

    @Override
    public void onInstall(AppData appData) {
        if (appData == null) {
            appData = new AppData();
            appData.setParamsData("");
            appData.setChannel("");
        }
        install(appData);
    }

    @Override
    public void onError(int code, String msg) {
        Log.d(TAG, "InstallCallback failed, code: " + code + ", msg: " + msg);
        AppData appData = new AppData();
        appData.setParamsData("");
        appData.setChannel("");
        install(appData);
    }
}
