#ifndef COMMON_H
#define COMMON_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
extern int common_FLOOR_WIDTH;

extern int common_FLOOR_HEIGHT;

extern const int common_MAX_FLOORS;

extern const char* common_RESOURCES;

extern const char* common_LOADING;

extern const char* common_CHARACTER;

extern const char* common_FLOOR;

extern const char* common_TABLE;

extern const char* common_START;

extern const char* common_STONE;

extern const char* common_LAKE;

extern const char* common_EXIT;

extern const char* common_PAUSE;

extern const char* common_NOMINE;

extern const char* common_MINE;

extern const char* common_TELEPORT;

extern const char* common_CLICK;

extern const char* common_MISSIL;

extern const char* common_MISSIL_SOUND;

extern const char* common_GRENADE;

extern const char* common_LAWNMOWER;

extern const char* common_TELEPORTER;

extern const char* common_MINEDETECTOR;

extern const char* common_LIFEUP;

extern const char* common_LASER;

extern const char* common_LASERBEAM;

extern const char* common_BEAM_SOUND;

extern const char* common_FLAMETHROWER;

extern const char* common_SELECTED;

extern const char* common_BOX;

extern const char* common_BUTTONS;

extern const char* common_COW;

extern const char* common_NAPALM;

extern const char* common_FIRE;

extern const char* common_MAGNET;

extern const char* common_SOUND_IMAGE;

extern const char* common_HELP;

extern const char* common_HELP_BOX;

extern const char* common_BGMUSIC;

extern const char* common_CLICK_SOUND;

extern const char* common_COW_SOUND;

extern const char* common_EXPLOSION_SOUND;

extern const char* common_MOTOR_SOUND;

extern const char* common_FONT;

extern const char* common_ANIM_FONT;

extern void common_init();

#ifdef __cplusplus
};
#endif


#endif//
