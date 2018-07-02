#ifndef SOUND_H
#define SOUND_H


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
#include <SDL2/SDL_mixer.h>

typedef enum{
	sound_NOT_PLAYED,
	sound_PLAYING,
	sound_PAUSED,
};




typedef enum{
	sound_ALL_SOUND,
	sound_NO_MUSIC,
	sound_FULL_MUTE,
};




extern int sound_sound_state;

typedef struct sound_Music_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct sound_Music_struct* self);
	void* (* __getvtable__)(struct sound_Music_struct* self, class_id id);
	int (* __cmp__)(struct sound_Music_struct* self, struct sound_Music_struct* other);
	struct sound_Music_struct* (* __operate__)(struct sound_Music_struct* self, struct sound_Music_struct* other);
	void* (* __str__)(struct sound_Music_struct* self);
	void* sound_724;
	cbcstd_String path_10;
	int playing_277;
	void (* play)(struct sound_Music_struct* self);
	bool (* isPlaying)(struct sound_Music_struct* self);
	void (* stop)(struct sound_Music_struct* self);
} sound_Music_struct;
typedef sound_Music_struct* sound_Music;
extern const class_id sound_Music__classid__;
extern sound_Music sound_Music_create(const char* path);
extern void sound_Music_init(sound_Music self, const char* path);
extern void sound_Music_initsystem(sound_Music self);
extern void sound_Music_inituser(sound_Music self, const char* path);
extern void sound_Music_play(sound_Music self);
extern bool sound_Music_isPlaying(sound_Music self);
extern void sound_Music_stop(sound_Music self);
extern void sound_Music_enduser(sound_Music self);
extern void sound_Music_end(sound_Music self);

typedef struct sound_Sound_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct sound_Sound_struct* self);
	void* (* __getvtable__)(struct sound_Sound_struct* self, class_id id);
	int (* __cmp__)(struct sound_Sound_struct* self, struct sound_Sound_struct* other);
	struct sound_Sound_struct* (* __operate__)(struct sound_Sound_struct* self, struct sound_Sound_struct* other);
	void* (* __str__)(struct sound_Sound_struct* self);
	void* sound_724;
	cbcstd_String path_10;
	int playing_277;
	void (* play)(struct sound_Sound_struct* self);
	bool (* isPlaying)(struct sound_Sound_struct* self);
	void (* stop)(struct sound_Sound_struct* self);
} sound_Sound_struct;
typedef sound_Sound_struct* sound_Sound;
extern const class_id sound_Sound__classid__;
extern sound_Sound sound_Sound_create(const char* path);
extern void sound_Sound_init(sound_Sound self, const char* path);
extern void sound_Sound_initsystem(sound_Sound self);
extern void sound_Sound_inituser(sound_Sound self, const char* path);
extern void sound_Sound_play(sound_Sound self);
extern void sound_Sound_stop(sound_Sound self);
extern void sound_Sound_enduser(sound_Sound self);
extern void sound_Sound_end(sound_Sound self);

extern sound_Music sound_bg_music;

extern void sound_init();

extern void sound_playBackground();




#ifdef __cplusplus
};
#endif


#endif//
