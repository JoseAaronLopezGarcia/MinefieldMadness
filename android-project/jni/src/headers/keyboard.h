#ifndef KEYBOARD_H
#define KEYBOARD_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <config.h>
#define SDL_keysym SDL_Keysym
extern bool keyboard_readKeyDown(SDL_Event* event, SDL_keysym* keys);

extern bool keyboard_readKeyUp(SDL_Event* event, SDL_keysym* keys);

extern void keyboard_init();

#ifdef __cplusplus
};
#endif


#endif//
