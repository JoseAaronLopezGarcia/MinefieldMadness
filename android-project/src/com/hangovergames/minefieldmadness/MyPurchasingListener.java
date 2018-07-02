package com.hangovergames.minefieldmadness;

import java.util.List;

import com.amazon.device.iap.PurchasingService;
import com.amazon.device.iap.PurchasingListener;
import com.amazon.device.iap.model.*;

public class MyPurchasingListener implements PurchasingListener{
	MinefieldMadness ctx;
	
	public MyPurchasingListener(MinefieldMadness ctx){
		this.ctx = ctx;
	}
	
	@Override
	public void onUserDataResponse(final UserDataResponse response) {
		System.out.println("Minefield Madness IAP: reached onUserDataResponse");
		return;
	}
	@Override
	public void onProductDataResponse(final ProductDataResponse response) {
		System.out.println("Minefield Madness IAP: reached onProductDataResponse");
		return;
	}
	@Override
	public void onPurchaseUpdatesResponse(final PurchaseUpdatesResponse response) {
		System.out.println("Minefield Madness IAP: reached onPurchaseUpdatesResponse");
		final PurchaseUpdatesResponse.RequestStatus status = response.getRequestStatus();
		switch (status) {
			case SUCCESSFUL:
				List<Receipt> receipts = response.getReceipts();
				if (receipts.size() == 0){
					ctx.onBuyPackError();
					return;
				}
				ctx.receipt = receipts.remove(0);
				handleReceipt();
				break;
			case FAILED:
			case NOT_SUPPORTED:
				PurchasingService.getPurchaseUpdates(true);
				break;
		}
	}
	@Override
	public void onPurchaseResponse(final PurchaseResponse response) {
		System.out.println("Minefield Madness IAP: reached onPurchaseResponse");
		System.out.println("Minefield Madness IAP: MinefieldMadness.iap_status is "+MinefieldMadness.iap_status);
		final PurchaseResponse.RequestStatus status = response.getRequestStatus();
		switch (status){
			case SUCCESSFUL:
				ctx.receipt = response.getReceipt();
				handleReceipt();
				break;
			case ALREADY_PURCHASED:
			case INVALID_SKU:
			case FAILED:
			case NOT_SUPPORTED:
				ctx.onBuyPackError();
				break;
		}
		System.out.println("Minefield Madness IAP: MinefieldMadness.iap_status now is "+MinefieldMadness.iap_status);
	}
	private void handleReceipt(){
		if (ctx.receipt.isCanceled()){
			ctx.receipt = null;
			ctx.onBuyPackError();
			return;
		}
		String sku = ctx.receipt.getSku();
		ctx.onBuyPackOk(sku);
	}
};
