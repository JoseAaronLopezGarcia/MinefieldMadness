package com.hangovergames.minefieldmadness;

import java.util.List;
import java.util.ArrayList;
import org.json.JSONException;
import org.json.JSONObject;

import org.libsdl.app.SDLActivity;
import android.os.*;
import android.content.Intent;
import android.app.PendingIntent;
import android.app.Activity;
import android.content.Context;
import android.widget.RelativeLayout;
import android.widget.LinearLayout;
import android.view.View;
import android.view.KeyEvent;
import android.widget.Button;
import android.widget.TextView;

import com.google.android.gms.ads.*;
import com.startapp.android.publish.*;
import com.startapp.android.publish.banner.*;

import com.amazon.device.ads.AdRegistration;
import com.startapp.android.publish.*;
import com.startapp.android.publish.banner.*;

// IAP
import com.amazon.device.iap.PurchasingService;
import com.amazon.device.iap.PurchasingListener;
import com.amazon.device.iap.model.*;
import android.content.ServiceConnection;
import android.os.Bundle;

import java.util.Timer;
import java.util.TimerTask;

/**
 * A sample wrapper class that just calls SDLActivity 
 */ 
   
public class MinefieldMadness extends SDLActivity {

	public enum IAPType{GOOGLE_IAP, AMAZON_IAP, NO_IAP};
	public enum IAPStatus{IAP_INACTIVE, IAP_PENDING};

	private class AmazonInterstitial extends com.amazon.device.ads.InterstitialAd{
		AmazonInterstitial(Activity ctx){
			super(ctx);
		}
	}
	
	private class AmazonBanner extends com.amazon.device.ads.AdLayout{
		AmazonBanner(Activity ctx){
			super(ctx);
		}
	}

	public static native void onQuit();
	public static native void save();
	public static native void resumeGame();
	public static native void onNativeBuyPack10();
	public static native void onNativeBuyPack15();
	public static native void onNativeBuyPack20();
	public static native void onNativeBuyPackMines();
	public static native void onNativeBuyPackError();
	public static native void onNativeInterstitialLoaded();
	public static native void onNativeInterstitialNotLoaded();
	public static native void onNativeInterstitialOk();
	public static native void onNativeInterstitialError();
	
	public final String skus[] = {
			"com.hangovergames.minefieldmadness.ExtraCharacter10Weapons",
			"com.hangovergames.minefieldmadness.3ExtraCharacters10Weapons",
			"com.hangovergames.minefieldmadness.5ExtraCharacters20Weapons",
			"com.hangovergames.minefieldmadness.revealmine"
	};
	
	// adMob ads
	private InterstitialAd interstitial = null;
	private InterstitialAd interstitialVideo = null;
	private static boolean interstitialLoaded = false;
	private AdView adView = null;
	private AdRequest adRequestBanner = null;
	private AdRequest adRequestInterstitial = null;
	private AdRequest adRequestInterstitialVideo = null;
	
	// Amazon ads
	private AmazonBanner amazonBanner = null;
	private AmazonInterstitial amazonInterstitial = null;
	private static boolean amazonInterstitialLoaded = false;
	
	// StartApp ads
	private TextView bannerText = null;
	private Banner startAppBanner = null;
	private StartAppAd startAppInterstitial = new StartAppAd(this);
	private boolean startAppInterstitialLoaded = false;
	private AdEventListener startAppInterstitialListener = new AdEventListener() {
		@Override public void onReceiveAd(Ad ad) {
			startAppInterstitialLoaded = true;
		}
		@Override public void onFailedToReceiveAd(Ad ad) {
			startAppInterstitialLoaded = false;
			startAppInterstitial.loadAd(this);
		}
	};
	private AdDisplayListener startAppDisplayListener = new AdDisplayListener(){
		@Override
		public void adHidden(Ad ad) {
			startAppInterstitialLoaded = false;
			startAppInterstitial.loadAd(startAppInterstitialListener);
			iap_status = IAPStatus.IAP_INACTIVE;
			MinefieldMadness.resumeGame();
		}

		@Override
		public void adDisplayed(Ad ad) {
		}

		@Override
		public void adClicked(Ad ad) {
			startAppInterstitialLoaded = false;
			MinefieldMadness.resumeGame();
			MinefieldMadness.save();
		}
	};
	
	// Others
	private Button bt = null;
	private LinearLayout lLayout = null;
	private RelativeLayout rLayout = null;
	private static boolean continue_game = false;
	
	// keep track of ads and IAP
	public static final IAPType iap_type = IAPType.AMAZON_IAP;
	public static IAPStatus iap_status = IAPStatus.IAP_INACTIVE;
	public static Receipt receipt = null;
	public static MyServiceConnection mServiceConn = null;
	public static JSONObject google_jo = null;
	private int google_test_type = -1;
	
	@Override
	protected void initAds(){
		StartAppSDK.init(this, "103563727", "203545262", false);
		AdRegistration.setAppKey("5c1bd279d4624de28fed6e9715ff8bad");
	}
	
	public void onBuyPackOk(String sku){
		iap_status = IAPStatus.IAP_INACTIVE;
		if (sku.compareTo(skus[0]) == 0)
			MinefieldMadness.onNativeBuyPack10();
		else if (sku.compareTo(skus[1]) == 0)
			MinefieldMadness.onNativeBuyPack15();
		else if (sku.compareTo(skus[2]) == 0)
			MinefieldMadness.onNativeBuyPack20();
		else if (sku.compareTo(skus[3]) == 0)
			MinefieldMadness.onNativeBuyPackMines();
		else if (sku.compareTo("android.test.purchased") == 0){
			switch (google_test_type){
			case 0: MinefieldMadness.onNativeBuyPack10(); break;
			case 1: MinefieldMadness.onNativeBuyPack15(); break;
			case 2: MinefieldMadness.onNativeBuyPack20(); break;
			case 3: MinefieldMadness.onNativeBuyPackMines(); break;
			default: MinefieldMadness.onNativeBuyPack10(); break;
			}
		}
		else
			MinefieldMadness.onNativeBuyPackError();
	}
	
	public void onBuyPackError(){
		System.out.println("Minefield Madness IAP: calling onNativeBuyPackError");
		iap_status = IAPStatus.IAP_INACTIVE;
		MinefieldMadness.onNativeBuyPackError();
	}
	
	public void onInterstitialOk(){
		iap_status = IAPStatus.IAP_INACTIVE;
		onNativeInterstitialOk();
	}
	
	public void onInterstitialError(){
		iap_status = IAPStatus.IAP_INACTIVE;
		onNativeInterstitialError();
	}
	
	@Override
	protected void initIAP(){
		if (iap_type == IAPType.AMAZON_IAP)
			initIAPAmazon();
		else if (iap_type == IAPType.GOOGLE_IAP)
			initIAPGoogle();
	}
	
	private void initIAPGoogle(){
		mServiceConn = new MyServiceConnection();
		Intent serviceIntent = new Intent("com.android.vending.billing.InAppBillingService.BIND");
		serviceIntent.setPackage("com.android.vending");
		bindService(serviceIntent, mServiceConn, Context.BIND_AUTO_CREATE);
	}
	
	private void initIAPAmazon(){
		PurchasingService.registerListener(this.getApplicationContext(), new MyPurchasingListener(this));
	}
	
	@Override
	protected void checkPacks(){
		if (iap_type == IAPType.AMAZON_IAP)
			checkPacksAmazon();
		else if (iap_type == IAPType.GOOGLE_IAP)
			checkPacksGoogle();
		else
			onBuyPackError();
	}
	
	private void checkPacksGoogle(){
		Bundle ownedItems = null;
		try{
			ownedItems = mServiceConn.mService.getPurchases(3, getPackageName(), "inapp", null);
		}
		catch (Exception e){
			onBuyPackError();
			return;
		}
		ArrayList<String>  purchaseDataList = ownedItems.getStringArrayList("INAPP_PURCHASE_DATA_LIST");
		
		if (purchaseDataList.size() == 0){
			onBuyPackError();
			return;
		}
		
		String purchaseData = purchaseDataList.remove(0);
		try{
			google_jo = new JSONObject(purchaseData);
			String sku = google_jo.getString("productId");
			onBuyPackOk(sku);
		}
		catch (Exception e){
			onBuyPackError();
		}
	}
	
	private void checkPacksAmazon(){
		PurchasingService.getPurchaseUpdates(true);
	}
	
	@Override
	protected void buyCharactersAndWeapons(int type){
		iap_status = IAPStatus.IAP_PENDING;
		if (type >= skus.length){
			onBuyPackError();
			return;
		}
		
		google_test_type = type;
		
		String sku = skus[type];
		
		if (iap_type == IAPType.AMAZON_IAP)
			buyCharactersAndWeaponsAmazon(sku);
		else if (iap_type == IAPType.GOOGLE_IAP)
			buyCharactersAndWeaponsGoogle(sku);
		else
			onBuyPackError();
	}
	
	private void buyCharactersAndWeaponsGoogle(String sku){
		sku = "android.test.purchased";
		try{
			final String devPayload = "mC3KunYsS7uTsdLyJukXKGlLmMS1NCMtkD49wSeE";
			Bundle buyIntentBundle = mServiceConn.mService.getBuyIntent(3, getPackageName(), sku, "inapp", devPayload);
			if (buyIntentBundle.getInt("RESPONSE_CODE") == 0){
				PendingIntent pendingIntent = buyIntentBundle.getParcelable("BUY_INTENT");
				startIntentSenderForResult(pendingIntent.getIntentSender(), 1001, new Intent(),
					Integer.valueOf(0), Integer.valueOf(0), Integer.valueOf(0));
			}
			else {
				onBuyPackError();
			}
		}
		catch (Exception e){
			e.printStackTrace();
			onBuyPackError();
		}
	}
	
	private void buyCharactersAndWeaponsAmazon(String sku){	
		RequestId requestId = PurchasingService.purchase(sku);
	}
	
	@Override
	protected void fullfillIAP(){
		if (iap_type == IAPType.AMAZON_IAP)
			fullfillIAPAmazon();
		else if (iap_type == IAPType.GOOGLE_IAP)
			fullfillIAPGoogle();
	}
	
	private void fullfillIAPGoogle(){
		if (google_jo == null)
			return;
		try{
			mServiceConn.mService.consumePurchase(3, getPackageName(), google_jo.getString("purchaseToken"));
		}
		catch (Exception e){}
		google_jo = null;
	}
	
	private void fullfillIAPAmazon(){
		if (receipt == null)
			return;
		PurchasingService.notifyFulfillment(receipt.getReceiptId(), FulfillmentResult.FULFILLED);
		receipt = null;
	}
	
	@Override
	public void showInterstitials(){
		
		runOnUiThread(new Runnable(){
			@Override public void run(){
				if (interstitialVideo != null && interstitialVideo.isLoaded()){
					iap_status = IAPStatus.IAP_PENDING;
					interstitialVideo.show();
				}
			}
		});
	}
	
	@Override
	protected void displayAds(){
		runOnUiThread(new Runnable() {
			@Override
			public void run() {
				if (interstitial != null && interstitialLoaded){
					iap_status = IAPStatus.IAP_PENDING;
					interstitial.show();
					
				}
				else if (amazonInterstitial != null && amazonInterstitialLoaded){
					iap_status = IAPStatus.IAP_PENDING;
					amazonInterstitial.showAd();
				}
				else if (startAppInterstitialLoaded){
					iap_status = IAPStatus.IAP_PENDING;
					startAppInterstitial.showAd(startAppDisplayListener);
				}
				else{
		  			startAppBanner.showBanner();
					adView.setVisibility(View.VISIBLE);
					amazonBanner.setVisibility(View.VISIBLE);
					bannerText.setVisibility(View.VISIBLE);
		  			bt.setVisibility(View.VISIBLE);
				}
			}
		});
	}
	
	@Override
	protected void loadBanners(){
		
		lLayout = new LinearLayout(this);
		rLayout = new RelativeLayout(this);
		
		lLayout.setOrientation(LinearLayout.VERTICAL);
		
		bannerText = new TextView(this);
		bannerText.setText("Advertising");
		RelativeLayout.LayoutParams textParams = new RelativeLayout.LayoutParams(
			RelativeLayout.LayoutParams.FILL_PARENT,
			RelativeLayout.LayoutParams.FILL_PARENT);
		textParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
		textParams.addRule(RelativeLayout.ABOVE, lLayout.getId());
		bannerText.setVisibility(View.INVISIBLE);
		
		bt = new Button(this);
		bt.setText("Close");
		RelativeLayout.LayoutParams buttonParameters = new RelativeLayout.LayoutParams(
			RelativeLayout.LayoutParams.WRAP_CONTENT,
			RelativeLayout.LayoutParams.WRAP_CONTENT);
		buttonParameters.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
		buttonParameters.addRule(RelativeLayout.ABOVE, lLayout.getId());
		
		bt.setOnClickListener(new View.OnClickListener() {
		   	public void onClick(View v) {
		   		runOnUiThread(new Runnable() {
					@Override
					public void run() {
						startAppBanner.clearAnimation();
						startAppBanner.hideBanner();
						adView.loadAd(adRequestBanner);
			  			adView.setVisibility(View.INVISIBLE);
			  			amazonBanner.loadAd(new com.amazon.device.ads.AdTargetingOptions());
			  			amazonBanner.setVisibility(View.INVISIBLE);
			  			
			  			bt.clearAnimation();
						bt.setVisibility(View.INVISIBLE);
						bannerText.setVisibility(View.INVISIBLE);
						
						MinefieldMadness.resumeGame();
					}
				});
			}
		});
		bt.setVisibility(View.INVISIBLE);
		
		startAppBanner = new Banner(this);
		startAppBanner.hideBanner();
		lLayout.addView(startAppBanner);

		adView = new AdView(this);
		adView.setAdUnitId("ca-app-pub-1542759953440943/6074152910");
		adView.setAdSize(AdSize.BANNER);
		adRequestBanner = new AdRequest.Builder().build();
		adView.setVisibility(View.INVISIBLE);
		lLayout.addView(adView);
		adView.loadAd(adRequestBanner);
		
		amazonBanner = new AmazonBanner(this);
		amazonBanner.setVisibility(View.INVISIBLE);
		lLayout.addView(amazonBanner);
		amazonBanner.loadAd(new com.amazon.device.ads.AdTargetingOptions());
		
		RelativeLayout.LayoutParams lLayoutParams = new RelativeLayout.LayoutParams(
			RelativeLayout.LayoutParams.MATCH_PARENT,
			RelativeLayout.LayoutParams.WRAP_CONTENT);
		lLayoutParams.addRule(RelativeLayout.CENTER_HORIZONTAL);
		lLayoutParams.addRule(RelativeLayout.ALIGN_PARENT_BOTTOM);
		
		mLayout.addView(rLayout, new LinearLayout.LayoutParams(LinearLayout.LayoutParams.FILL_PARENT, LinearLayout.LayoutParams.FILL_PARENT));
		rLayout.addView(lLayout, lLayoutParams);
		rLayout.addView(bannerText, textParams);
		rLayout.addView(bt, buttonParameters);
	}
	
	@Override
	protected void loadInterstitials(){
		
		interstitial = null;
		amazonInterstitial = null;
		
		interstitial = new InterstitialAd(this);
		interstitialVideo = new InterstitialAd(this);
	
		interstitial.setAdUnitId("ca-app-pub-1542759953440943/3120686513");
		interstitialVideo.setAdUnitId("ca-app-pub-1542759953440943/1826922112");
	
	
		// test device: "9C940814854582806FABFA387906449E"
		adRequestInterstitial = new AdRequest.Builder().build();
		adRequestInterstitialVideo = new AdRequest.Builder().build();
	
		interstitial.setAdListener(new AdListener(){
			@Override public void onAdFailedToLoad(int errorCode){
				interstitial.loadAd(adRequestInterstitial);
			}
			@Override public void onAdClosed(){
				interstitialLoaded = false;
				interstitial.loadAd(adRequestInterstitial);
				MinefieldMadness.resumeGame();
			}
			@Override public void onAdLeftApplication(){
				interstitialLoaded = false;
				MinefieldMadness.resumeGame();
				MinefieldMadness.save();
			}
			@Override public void onAdLoaded(){
				interstitialLoaded = true;
			}
		});
		
		interstitialVideo.setAdListener(new AdListener(){
			@Override public void onAdFailedToLoad(int errorCode){
				interstitialVideo.loadAd(adRequestInterstitialVideo);
				onNativeInterstitialNotLoaded();
			}
			@Override public void onAdClosed(){
				interstitialVideo.loadAd(adRequestInterstitialVideo);
				onInterstitialOk();
				onNativeInterstitialNotLoaded();
			}
			@Override public void onAdLeftApplication(){
				onInterstitialOk();
				MinefieldMadness.save();
				onNativeInterstitialNotLoaded();
			}
			@Override public void onAdLoaded(){
				System.out.println("Minefield Madness Ads: loaded video interstitial");
				onNativeInterstitialLoaded();
			}
		});
	
		interstitial.loadAd(adRequestInterstitial);
		interstitialVideo.loadAd(adRequestInterstitialVideo);
			
		amazonInterstitial = new AmazonInterstitial(this);
		amazonInterstitial.setListener(new com.amazon.device.ads.AdListener(){
			@Override
			public void onAdFailedToLoad(com.amazon.device.ads.Ad ad, 
					com.amazon.device.ads.AdError error){
				amazonInterstitial.loadAd();
			}
			@Override
			public void onAdLoaded(com.amazon.device.ads.Ad ad,
					com.amazon.device.ads.AdProperties adProperties){
				amazonInterstitialLoaded=true;
			}
			@Override public void onAdDismissed(com.amazon.device.ads.Ad ad){
				amazonInterstitialLoaded = false;
				amazonInterstitial.loadAd();
				MinefieldMadness.resumeGame();
			}
			@Override public void onAdExpanded(com.amazon.device.ads.Ad ad){}
			@Override public void onAdCollapsed(com.amazon.device.ads.Ad ad){}
		});
		amazonInterstitial.loadAd();

		startAppInterstitial.loadAd(startAppInterstitialListener);
	}
	
	@Override
	protected void onPause(){
		if (iap_status == IAPStatus.IAP_INACTIVE){
			if (mServiceConn != null && mServiceConn.mService != null)
				unbindService(mServiceConn);
			MinefieldMadness.save();
			MinefieldMadness.onQuit();
		}
		super.onPause();
	}
	
	@Override
	protected void onStop(){
		if (mServiceConn != null && mServiceConn.mService != null)
			unbindService(mServiceConn);
		MinefieldMadness.save();
		MinefieldMadness.onQuit();
		super.onStop();
	}
	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) { 
		if (iap_type == IAPType.GOOGLE_IAP && requestCode == 1001) {			  
			int responseCode = data.getIntExtra("RESPONSE_CODE", 0);
			String purchaseData = data.getStringExtra("INAPP_PURCHASE_DATA");
			String dataSignature = data.getStringExtra("INAPP_DATA_SIGNATURE");
			  
			if (resultCode == RESULT_OK) {
				try {
					google_jo = new JSONObject(purchaseData);
					String sku = google_jo.getString("productId");
					onBuyPackOk(sku);
				 }
				 catch (Exception e) {
					 onBuyPackError();
				 }
			}
			else{
				onBuyPackError();
			}
		}
	}
}
