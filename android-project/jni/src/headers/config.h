#ifndef CONFIG_H
#define CONFIG_H

#define DIM_X 11
#define DIM_Y 7
#define MAX_EXTRA_INFO 4

//#define ANDROID 1
#define LINUX 1

#ifdef LINUX or defined WINDOWS
#define PC 1
#endif

#ifdef ANDROID
#include <android/log.h>
#define  LOG_TAG "Minefield Madness!"
#define  logprint(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
#define printf logprint
#endif

#ifdef PC
#define logprint(...) printf(__VA_ARGS__)
#endif

#endif
