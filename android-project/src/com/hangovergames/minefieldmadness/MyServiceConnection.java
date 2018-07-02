package com.hangovergames.minefieldmadness;

import android.content.ServiceConnection;
import android.os.IBinder;
import android.content.ComponentName;
import com.android.vending.billing.*;

class MyServiceConnection implements ServiceConnection{

	public IInAppBillingService mService = null;

	@Override
	public void onServiceDisconnected(ComponentName name){
		mService = null;
	}

	@Override
	public void onServiceConnected(ComponentName name, IBinder service){
		mService = IInAppBillingService.Stub.asInterface(service);
	}
};
