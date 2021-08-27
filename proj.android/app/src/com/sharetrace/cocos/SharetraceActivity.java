package com.sharetrace.cocos;

import android.content.Intent;
import android.os.Bundle;

import org.cocos2dx.lib.Cocos2dxActivity;

import cn.net.shoot.sharetracesdk.ShareTrace;

public class SharetraceActivity extends Cocos2dxActivity {

    WakeUpCallback wakeUpCallback = new WakeUpCallback();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        ShareTrace.init(getApplication());
        ShareTrace.getWakeUpTrace(getIntent(), wakeUpCallback);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        ShareTrace.getWakeUpTrace(intent, wakeUpCallback);
    }
}
