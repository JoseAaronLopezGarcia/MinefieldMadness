#ifndef TIMER_H
#define TIMER_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
#include <SDL2/SDL.h>
typedef struct timer_Timer_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct timer_Timer_struct* self);
	void* (* __getvtable__)(struct timer_Timer_struct* self, class_id id);
	int (* __cmp__)(struct timer_Timer_struct* self, struct timer_Timer_struct* other);
	struct timer_Timer_struct* (* __operate__)(struct timer_Timer_struct* self, struct timer_Timer_struct* other);
	void* (* __str__)(struct timer_Timer_struct* self);
	uint32_t (mStartTicks_233);
	uint32_t (mPausedTicks_871);
	bool (mPaused_231);
	bool (mStarted_379);
	void (* start)(struct timer_Timer_struct* self);
	void (* stop)(struct timer_Timer_struct* self);
	void (* pause)(struct timer_Timer_struct* self);
	void (* unpause)(struct timer_Timer_struct* self);
	uint32_t (* getTicks)(struct timer_Timer_struct* self);
	bool (* isStarted)(struct timer_Timer_struct* self);
	bool (* isPaused)(struct timer_Timer_struct* self);
} timer_Timer_struct;
typedef timer_Timer_struct* timer_Timer;
extern const class_id timer_Timer__classid__;
extern timer_Timer timer_Timer_create();
extern void timer_Timer_init(timer_Timer self);
extern void timer_Timer_initsystem(timer_Timer self);
extern void timer_Timer_inituser(timer_Timer self);
extern void timer_Timer_start(timer_Timer self);
extern void timer_Timer_stop(timer_Timer self);
extern void timer_Timer_pause(timer_Timer self);
extern void timer_Timer_unpause(timer_Timer self);
extern uint32_t timer_Timer_getTicks(timer_Timer self);
extern bool timer_Timer_isStarted(timer_Timer self);
extern bool timer_Timer_isPaused(timer_Timer self);
extern void timer_Timer_enduser(timer_Timer self);
extern void timer_Timer_end(timer_Timer self);


extern void timer_init();

#ifdef __cplusplus
};
#endif


#endif//
