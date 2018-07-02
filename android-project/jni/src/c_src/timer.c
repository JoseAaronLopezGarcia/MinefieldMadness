#include <cbc.h>
// public globals
#include <timer.h>
// private globals
const class_id timer_Timer__classid__ = -2501797311058027870;
//


timer_Timer timer_Timer_create(){
	timer_Timer self = (timer_Timer)cbcstd_alloc(sizeof(timer_Timer_struct));
	try{
		timer_Timer_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void timer_Timer_init(timer_Timer self){
	timer_Timer_initsystem(self);
	timer_Timer_inituser(self);
}
void timer_Timer_initsystem(timer_Timer self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-2501797311058027870L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(timer_Timer_struct);
	self->start = &timer_Timer_start;
	self->stop = &timer_Timer_stop;
	self->pause = &timer_Timer_pause;
	self->unpause = &timer_Timer_unpause;
	self->getTicks = &timer_Timer_getTicks;
	self->isStarted = &timer_Timer_isStarted;
	self->isPaused = &timer_Timer_isPaused;
	self->__end__ = &timer_Timer_end;
}
void timer_Timer_enduser(timer_Timer self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void timer_Timer_end(timer_Timer self){
	timer_Timer_enduser(self);
	timer_Timer_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void timer_Timer_decrefs(timer_Timer self){
}


	



	



	




void timer_Timer_inituser(timer_Timer self){
	

	self->mStartTicks_233 = 0;

	self->mPausedTicks_871 = 0;

	self->mPaused_231 = false;

	self->mStarted_379 = false;

}

void timer_Timer_start(timer_Timer self){
	

	self->mStarted_379 = true;
	

	self->mPaused_231 = false;
	

	self->mStartTicks_233 = SDL_GetTicks();

	self->mPausedTicks_871 = 0;
	

}

void timer_Timer_stop(timer_Timer self){
	

	self->mStarted_379 = false;
	

	self->mPaused_231 = false;
	

	self->mStartTicks_233 = 0;

	self->mPausedTicks_871 = 0;

}

void timer_Timer_pause(timer_Timer self){


	if (self->mStarted_379 and not self->mPaused_231){
		

		self->mPaused_231 = true;
		


		self->mPausedTicks_871 = SDL_GetTicks() - self->mStartTicks_233;

		self->mStartTicks_233 = 0;
	}


}

void timer_Timer_unpause(timer_Timer self){


	if (self->mStarted_379 and self->mPaused_231){
		

		self->mPaused_231 = false;
		


		self->mStartTicks_233 = SDL_GetTicks() - self->mPausedTicks_871;
		

		self->mPausedTicks_871 = 0;
	}


}

uint32_t timer_Timer_getTicks(timer_Timer self){
	
	uint32_t time = 0;
	

	if (self->mStarted_379){
		

		if (self->mPaused_231){
			

			time = self->mPausedTicks_871;
		}

		else{
			

			time = SDL_GetTicks() - self->mStartTicks_233;
		}

	}

	return time;

}

bool timer_Timer_isStarted(timer_Timer self){

	return self->mStarted_379;

}

bool timer_Timer_isPaused(timer_Timer self){


	return self->mPaused_231 && self->mStarted_379;

}


void timer_init(){
	return;
}
