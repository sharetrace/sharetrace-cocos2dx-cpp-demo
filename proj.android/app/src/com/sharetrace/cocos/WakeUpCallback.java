package com.sharetrace.cocos;

import cn.net.shoot.sharetracesdk.AppData;
import cn.net.shoot.sharetracesdk.ShareTraceWakeUpListener;

public class WakeUpCallback implements ShareTraceWakeUpListener {

    native void wakeup(AppData appData);

    @Override
    public void onWakeUp(AppData appData) {
        wakeup(appData);
    }
}
