#include <cbc.h>
// public globals
#include <ads.h>
// private globals
//
#ifdef ADNROID

extern void SDL_android_loadAds();
extern void SDL_android_showAds();
extern void SDL_android_loadInterstitials();
extern void SDL_android_showInterstitials();
extern void SDL_android_showBannerAds();
extern void SDL_android_hideBannerAds();
extern void SDL_android_IAP_buyContinuePack(int type);
extern void SDL_android_fullfillReceipt();
extern void SDL_android_IAP_checkContinuePack();
extern void SDL_android_IAP_buyRevealMines();
#endif















bool ads_interstitial = false;

void ads_loadAds(){
	#ifdef ANDROID
	SDL_android_loadAds();
	#endif


}

void ads_showAds(){
	#ifdef ANDROID
	SDL_android_showAds();
	#endif


}

void ads_loadInterstitials(){
	#ifdef ANDROID
	SDL_android_loadInterstitials();
	#endif


}

void ads_showInterstitials(){
	#ifdef ANDROID
	SDL_android_showInterstitials();
	#endif



}

static int bought_pack = -1;





static ads_ContinuePack _packs[4+1] = {{0, 0},{1, 10},{3, 15},{5, 20},{1, 0}};

static ads_ContinuePack* packs = &(_packs[1]);

ads_ContinuePack* ads_getPack(){
	return &(packs[bought_pack]);


}

void ads_setPack(int type){
	if (type < 0 or type > 4){
		bought_pack = -1;
	}

	else{
		bought_pack = type;

	}


}

void ads_buyContinuePack(int type){
	ads_setPack(type);
	#ifdef ANDROID
	SDL_android_IAP_buyContinuePack(type);
	#else
	return;
	#endif


}

void ads_buyRevealMines(){
	#ifdef ANDROID
	SDL_android_IAP_buyRevealMines();
	#else
	return;
	#endif


}

void ads_checkContinuePack(){
	#ifdef ANDROID
	SDL_android_IAP_checkContinuePack();
	#else
	return;
	#endif


}

void ads_fullfillReceipt(){
	#ifdef ANDROID
	SDL_android_fullfillReceipt();
	#else
	return;
	#endif

}

void ads_init(){
	return;
}
