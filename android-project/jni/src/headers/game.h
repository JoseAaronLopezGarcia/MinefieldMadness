#ifndef GAME_H
#define GAME_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// common imports
#include <common.h>
//
// map imports
#include <map.h>
//
// floor imports
#include <floor.h>
//
// character imports
#include <character.h>
//
// missil imports
#include <missil.h>
//
// grenade imports
#include <grenade.h>
//
// lawnmower imports
#include <lawnmower.h>
//
// sound imports
#include <sound.h>
//
// difficulty imports
#include <difficulty.h>
//
// font imports
#include <font.h>
//
// teleporter imports
#include <teleporter.h>
//
// minedetector imports
#include <minedetector.h>
//
// flamethrower imports
#include <flamethrower.h>
//
// lifeup imports
#include <lifeup.h>
//
// cow imports
#include <cow.h>
//
// napalm imports
#include <napalm.h>
//
// magnet imports
#include <magnet.h>
//
// laser imports
#include <laser.h>
//
// image imports
#include <image.h>
//
// savedata imports
#include <savedata.h>
//
// ads imports
#include <ads.h>
//
// public globals
#include "config.h"





















typedef enum{
	game_MISSIL,
	game_GRENADE,
	game_LAWNMOWER,
	game_TELEPORTER,
	game_MINEDETECTOR,
	game_LIFEUP,
	game_FLAMETHROWER,
	game_COW,
	game_NAPALM,
	game_MAGNET,
	game_LASER,
};












extern bool game_quit;

extern bool game_can_exit;

typedef enum game_GameState{
	game_MENU,
	game_GAME,
	game_HELP,
	game_ADS,
	game_WAIT_ADS,
	game_CONTINUE_GAME,
} game_GameState;







extern game_GameState game_state;

extern cbcstd_Semaphore game_draw_sema;

extern map_MapObject game_winner;

typedef struct game_Score{
	int characters;
	int mines;
	int items;
	long total;
} game_Score;
extern void game_Score_enduser(game_Score self);
extern void game_Score_end(game_Score self);

extern game_Score game_score;

extern long game_total_score;

extern volatile int game_debugging;

extern void game_init();

extern void game_initializeMap();

extern void game_generateMap();

extern void game_insertCharacters();

extern void game_reinsertCharacters();

extern cbcstd_Object game_getNewItem(int r);

extern cbcstd_Object game_createRandomObject();

extern void game_insertDefaultItems();

extern void game_insertRandomItems();

extern void game_insertAllItems();

extern void game_calculateScore();

extern void game_doAds();

extern void game_startGame();

extern void game_startNextGame();

extern void game_startGameVeryEasy();

extern void game_startGameEasy();

extern void game_startGameNormal();

extern void game_startGameHard();

extern void game_startGameExtreme();

extern void game_startGameImpossible();

extern int game_classIdToItemId(class_id id);

extern void game_parseGameStatus(savedata_ItemStatus* status);

extern void game_resumeGame();

extern void game_addNewCharacters(int n_characters);

extern void game_addNewWeapons(int n_weapons);

extern void game_save();

extern void game_revealMines();

extern void game_debugMines(int x, int y);



#ifdef __cplusplus
};
#endif


#endif//
