#ifndef MOUSE_H
#define MOUSE_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <config.h>
extern bool mouse_readButtons(SDL_Event* event, void* mouse);

extern void mouse_init();

#ifdef __cplusplus
};
#endif


#endif//
