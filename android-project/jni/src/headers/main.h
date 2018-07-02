#ifndef MAIN_H
#define MAIN_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// savedata imports
#include <savedata.h>
//
// map imports
#include <map.h>
//
// floor imports
#include <floor.h>
//
// screen imports
#include <screen.h>
//
// keyboard imports
#include <keyboard.h>
//
// mouse imports
#include <mouse.h>
//
// image imports
#include <image.h>
//
// sound imports
#include <sound.h>
//
// character imports
#include <character.h>
//
// menu imports
#include <menu.h>
//
// notification imports
#include <notification.h>
//
// pause imports
#include <pause.h>
//
// common imports
#include <common.h>
//
// game imports
#include <game.h>
//
// difficulty imports
#include <difficulty.h>
//
// help imports
#include <help.h>
//
// timer imports
#include <timer.h>
//
// ads imports
#include <ads.h>
//
// public globals
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <time.h>


















#include "config.h"
extern image_Image main_click_img;

extern sound_Sound main_click_sound;

extern bool main_click_anim;

extern float main_click_anim_state;

extern int main_click_x;

extern int main_click_y;

extern menu_Menu main_menus[7];

typedef enum{
	main_MAIN_MENU,
	main_WON_MENU,
	main_LOOSE_MENU,
	main_PAUSE_MENU,
	main_CONTINUE_MENU,
	main_IAP_WAIT,
	main_IAP_MENU,
};








extern int main_cur_menu;

extern void main_startMainMenu();

extern void main_continueGameBought();

extern void main_buyPackError();

extern void main_buyContinuePackCommon(int type);

extern void main_freeContinuePack();

extern void main_buyRevealMines();

extern void main_onBuyPackMines();

extern void main_interstitialOk();

extern void main_buyContinuePack10();

extern void main_buyContinuePack15();

extern void main_buyContinuePack20();

extern void main_startNewGame();

extern void main_copyScore(int menu_type);

extern void main_startNotificationMenu(int menu_type);

extern void main_startContinueMenu();

extern void main_startLooseMenu();

extern void main_startIAPMenu();

extern void main_startPauseMenu();

extern void main_resumeGame();

extern void main_loadHelp();

extern void main_onExit();

extern void main_draw();

extern void* main_drawThread(void* unused);

extern void main_keyboardMovement(SDL_keysym keys);

extern void* main_controlThread(void* unused);

extern int main_main();

extern void main_init();

#ifdef __cplusplus
};
#endif


#endif//
