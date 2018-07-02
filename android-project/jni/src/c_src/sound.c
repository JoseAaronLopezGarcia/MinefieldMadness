#include <cbc.h>
// public globals
#include <sound.h>
// private globals
const class_id sound_Music__classid__ = -7327451892370711894;
const class_id sound_Sound__classid__ = -4064380341282401698;
//














int sound_sound_state = sound_ALL_SOUND;

sound_Music sound_Music_create(const char* path){
	sound_Music self = (sound_Music)cbcstd_alloc(sizeof(sound_Music_struct));
	try{
		sound_Music_init(self, path);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void sound_Music_init(sound_Music self, const char* path){
	sound_Music_initsystem(self);
	sound_Music_inituser(self, path);
}
void sound_Music_initsystem(sound_Music self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-7327451892370711894L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(sound_Music_struct);
	self->play = &sound_Music_play;
	self->isPlaying = &sound_Music_isPlaying;
	self->stop = &sound_Music_stop;
	self->__end__ = &sound_Music_end;
}
void sound_Music_end(sound_Music self){
	sound_Music_enduser(self);
	sound_Music_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void sound_Music_decrefs(sound_Music self){
}




	
void sound_Music_inituser(sound_Music self, const char* path){

	self->path_10 = cbcstd_String_create(path);

	self->sound_724 = (void*)Mix_LoadMUS(path);

	if (self->sound_724 == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(Mix_GetError())));
	}


	self->playing_277 = sound_NOT_PLAYED;


}

void sound_Music_play(sound_Music self){
	if (sound_sound_state != sound_ALL_SOUND){
		return;
	}

	int tmp_mHTr_50 = self->playing_277;
	switch (tmp_mHTr_50){
		case sound_NOT_PLAYED:{

			Mix_FadeInMusic((Mix_Music*)(self->sound_724), -1, 2000);

			self->playing_277 = sound_PLAYING;
			break;
		}

		case sound_PLAYING:{
			Mix_PauseMusic();

			self->playing_277 = sound_PAUSED;
			break;
		}

		case sound_PAUSED:{
			Mix_ResumeMusic();

			self->playing_277 = sound_PLAYING;
			break;
		}

		default:{
			break;

		}

	}


}

bool sound_Music_isPlaying(sound_Music self){

	return self->playing_277 == sound_PLAYING;


}

void sound_Music_stop(sound_Music self){
	Mix_HaltMusic();


}

void sound_Music_enduser(sound_Music self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	Mix_FreeMusic(self->sound_724);

}


sound_Sound sound_Sound_create(const char* path){
	sound_Sound self = (sound_Sound)cbcstd_alloc(sizeof(sound_Sound_struct));
	try{
		sound_Sound_init(self, path);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void sound_Sound_init(sound_Sound self, const char* path){
	sound_Sound_initsystem(self);
	sound_Sound_inituser(self, path);
}
void sound_Sound_initsystem(sound_Sound self){
	sound_Music_initsystem((sound_Music)self);
	const static class_id __classid__[4] = {
		-4064380341282401698L,
		-7327451892370711894L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(sound_Sound_struct);
	self->play = &sound_Sound_play;
	self->stop = &sound_Sound_stop;
	self->__end__ = &sound_Sound_end;
}
void sound_Sound_enduser(sound_Sound self){
	sound_Music_enduser((sound_Music)self);
	return;
}
void sound_Sound_end(sound_Sound self){
	sound_Sound_enduser(self);
	sound_Sound_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void sound_Sound_decrefs(sound_Sound self){
}

	
void sound_Sound_inituser(sound_Sound self, const char* path){

	self->path_10 = cbcstd_String_create(path);

	self->sound_724 = (void*)Mix_LoadWAV(path);

	self->playing_277 = sound_NOT_PLAYED;


}

void sound_Sound_play(sound_Sound self){
	if (sound_sound_state == sound_FULL_MUTE){
		return;
	}


	Mix_PlayChannel(-1, (Mix_Chunk*)self->sound_724, 0);


}

void sound_Sound_stop(sound_Sound self){
	pass;


}


sound_Music sound_bg_music = NULL;

void sound_init(){
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(Mix_GetError())));
	
	}

	sound_bg_music = sound_Music_create(common_BGMUSIC);


}

void sound_playBackground(){

	sound_bg_music->play(sound_bg_music);

}

