/*
	SDL_android_main.c, placed in the public domain by Sam Lantinga  3/13/14
*/
#define __ANDROID__ 1

#ifdef __ANDROID__

/* Include the SDL main definition header */
#include <SDL2/SDL_main.h>
#include <SDL2/SDL_mixer.h>
#include <game.h> // import game
#include <config.h>

/*******************************************************************************
				 Functions called by JNI
*******************************************************************************/
#include <jni.h>

/* Called before SDL_main() to initialize JNI bindings in SDL library */
extern void SDL_Android_Init(JNIEnv* env, jclass cls);


static jmethodID activity_loadAds;
static jmethodID activity_showAds;
static jmethodID activity_loadInterstitials;
static jmethodID activity_showInterstitials;
static jmethodID activity_continue10;
static jmethodID activity_continue15;
static jmethodID activity_continue20;
static jmethodID activity_revealmines;
static jmethodID activity_checkcontinue;
static jmethodID activity_fullfill;
static jclass clazz;
static JavaVM* j_vm;

/* Start up the SDL app */
int Java_org_libsdl_app_SDLActivity_nativeInit(JNIEnv* env, jclass cls, jobject array)
{

	logprint("Reached nativeInit\n");
	int status;
	
	logprint("Obtaining clazz\n");
	(*env)->GetJavaVM(env, &j_vm);
	
	clazz = (jclass)((*env)->NewGlobalRef(env, cls));
	
	logprint("obtaining ad and IAP methods\n");
	activity_loadAds = (*env)->GetStaticMethodID(env, clazz, "loadAds","()V");
	activity_showAds = (*env)->GetStaticMethodID(env, clazz, "showAds","()V");
	
	activity_loadInterstitials = (*env)->GetStaticMethodID(env, clazz, "loadInterstitialAds","()V");
	activity_showInterstitials = (*env)->GetStaticMethodID(env, clazz, "showInterstitialAds","()V");
	
	activity_continue10 = (*env)->GetStaticMethodID(env, clazz, "buyExtraCharacter10Weapons","()V");
	activity_continue15 = (*env)->GetStaticMethodID(env, clazz, "buyExtra3Characters15Weapons","()V");
	activity_continue20 = (*env)->GetStaticMethodID(env, clazz, "buyExtra5Characters20Weapons","()V");
	activity_revealmines = (*env)->GetStaticMethodID(env, clazz, "buyRevealMines","()V");
	activity_checkcontinue = (*env)->GetStaticMethodID(env, clazz, "checkContinuePack","()V");
	activity_fullfill = (*env)->GetStaticMethodID(env, clazz, "fullfillReceipt","()V");
	
	logprint("clazz: %zx, loadAds: %zx, showAds: %zx\n", clazz, activity_loadAds, activity_showAds);

	/* This interface could expand with ABI negotiation, callbacks, etc. */
	logprint("SDL_Android_Init()\n");
	SDL_Android_Init(env, cls);

	logprint("SDL_SetMainReady()\n");
	SDL_SetMainReady();

	/* Run the application. */
	logprint("Calling main function\n");
	status = main(0, NULL);
	
	/* Do not issue an exit or the whole application will terminate instead of just the SDL thread */
	/* exit(status); */

	return status;
}

void Java_org_libsdl_app_SDLActivity_MixPauseMusic(JNIEnv* env, jclass cls){
	Mix_PauseMusic();
}

void Java_org_libsdl_app_SDLActivity_MixResumeMusic(JNIEnv* env, jclass cls){
	Mix_ResumeMusic();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_save(JNIEnv* env, jclass cls){
	if (!game_can_exit) return;
	main_onExit(); // call CbC's main.onExit()
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onQuit(JNIEnv* env, jclass cls){
	if (!game_can_exit) return;
	exit(0);
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeBuyPack10(JNIEnv* env, jclass cls){
	ads_setPack(0);
	main_continueGameBought();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeBuyPack15(JNIEnv* env, jclass cls){
	ads_setPack(1);
	main_continueGameBought();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeBuyPack20(JNIEnv* env, jclass cls){
	ads_setPack(2);
	main_continueGameBought();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeBuyPackMines(JNIEnv* env, jclass cls){
	ads_setPack(-1);
	main_onBuyPackMines();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeBuyPackError(JNIEnv* env, jclass cls){
	main_buyPackError();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeInterstitialOk(JNIEnv* env, jclass cls){
	main_interstitialOk();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeInterstitialError(JNIEnv* env, jclass cls){
	main_startLooseMenu();
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeInterstitialLoaded(JNIEnv* env, jclass cls){
	ads_interstitial = true;
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_onNativeInterstitialNotLoaded(JNIEnv* env, jclass cls){
	ads_interstitial = false;
}

void Java_com_hangovergames_minefieldmadness_MinefieldMadness_resumeGame(JNIEnv* env, jclass cls){
	game_state = game_CONTINUE_GAME; // game.state = game.CONTINUE_GAME
}

void callStaticVoidMethod(jmethodID method) {
	JNIEnv* g_env;
	
	bool detach_thread = false;
	
	int getEnvStat = (*j_vm)->GetEnv(j_vm, (void**)&g_env, JNI_VERSION_1_6);
	
	if (getEnvStat == JNI_EDETACHED){
		(*j_vm)->AttachCurrentThread(j_vm, (void**)&g_env, NULL);
		detach_thread = true;
	}

	(*g_env)->CallStaticVoidMethod(g_env, clazz, method);

    if (detach_thread)
	    (*j_vm)->DetachCurrentThread(j_vm);
}

void SDL_android_loadAds(){
	callStaticVoidMethod(activity_loadAds);
}

void SDL_android_showAds(){
    callStaticVoidMethod(activity_showAds);
}

void SDL_android_loadInterstitials(){
	callStaticVoidMethod(activity_loadInterstitials);
}

void SDL_android_showInterstitials(){
	callStaticVoidMethod(activity_showInterstitials);
}

void SDL_android_IAP_buyContinuePack(int type){
	switch (type){
		case 0:
			callStaticVoidMethod(activity_continue10);
			break;
		case 1:
			callStaticVoidMethod(activity_continue15);
			break;
		case 2:
			callStaticVoidMethod(activity_continue20);
			break;
	}
}

void SDL_android_IAP_buyRevealMines(){
	callStaticVoidMethod(activity_revealmines);
}

void SDL_android_IAP_checkContinuePack(){
	callStaticVoidMethod(activity_checkcontinue);
}

void SDL_android_fullfillReceipt(){
	callStaticVoidMethod(activity_fullfill);
}

#endif /* __ANDROID__ */

/* vi: set ts=4 sw=4 expandtab: */
