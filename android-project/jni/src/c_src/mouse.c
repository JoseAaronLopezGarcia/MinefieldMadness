#include <cbc.h>
// public globals
#include <mouse.h>
// private globals
//




bool mouse_readButtons(SDL_Event* event, void* mouse){
	

	if (event->type == SDL_MOUSEBUTTONDOWN){
		memcpy(mouse, &(event->button), sizeof(SDL_MouseButtonEvent));
		return true;
	}

	memset(mouse, 0, sizeof(SDL_MouseButtonEvent));
	return false;











}

void mouse_init(){
	return;
}
