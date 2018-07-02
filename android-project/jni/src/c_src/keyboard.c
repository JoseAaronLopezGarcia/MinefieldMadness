#include <cbc.h>
// public globals
#include <keyboard.h>
// private globals
static bool _keyboard_read(SDL_Event* event, SDL_keysym* keys, int type);

//






static bool _keyboard_read(SDL_Event* event, SDL_keysym* keys, int type){
	#if defined PC
	if (event->type == type){
		memcpy(keys, &(event->key.keysym), sizeof(SDL_keysym));
		return true;
	}

	#endif
	memset(keys, 0, sizeof(SDL_keysym));
	return false;


}

bool keyboard_readKeyDown(SDL_Event* event, SDL_keysym* keys){
	return _keyboard_read(event, keys, SDL_KEYDOWN);


}

bool keyboard_readKeyUp(SDL_Event* event, SDL_keysym* keys){
	return _keyboard_read(event, keys, SDL_KEYUP);

}

void keyboard_init(){
	return;
}
