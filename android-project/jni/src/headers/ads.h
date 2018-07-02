#ifndef ADS_H
#define ADS_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
extern bool ads_interstitial;

extern void ads_loadAds();

extern void ads_showAds();

extern void ads_loadInterstitials();

extern void ads_showInterstitials();

typedef struct ads_ContinuePack{
	int n_characters;
	int n_weapons;
} ads_ContinuePack;
extern void ads_ContinuePack_enduser(ads_ContinuePack self);
extern void ads_ContinuePack_end(ads_ContinuePack self);

extern ads_ContinuePack* ads_getPack();

extern void ads_setPack(int type);

extern void ads_buyContinuePack(int type);

extern void ads_buyRevealMines();

extern void ads_checkContinuePack();

extern void ads_fullfillReceipt();


extern void ads_init();

#ifdef __cplusplus
};
#endif


#endif//
