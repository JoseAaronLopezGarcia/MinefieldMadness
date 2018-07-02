#ifndef SCREEN_H
#define SCREEN_H


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
// public globals
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <math.h>
#include <config.h>

extern int screen_width;

extern int screen_height;

extern char* screen_window_title;

extern unsigned screen_options;

extern const char* screen_SCREEN_TITLE;

extern void screen_init();

extern void screen_flip();

extern void screen_clear();

extern SDL_Renderer* screen_getRenderer();

extern SDL_Window* screen_getWindow();


#ifdef __cplusplus
};
#endif


#endif//
