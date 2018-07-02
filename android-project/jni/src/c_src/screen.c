#include <cbc.h>
// public globals
#include <screen.h>
// private globals
static SDL_Window* (screen_window) = NULL;

static SDL_Renderer* (screen_renderer) = NULL;

static SDL_Texture* (screen_background) = NULL;

//











int screen_width = 0;
int screen_height = 0;
char* screen_window_title = NULL;
unsigned screen_options = 0;
const char* screen_SCREEN_TITLE = "Minefield Madness!";


SDL_Rect info;

void screen_init(){

	

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);

	SDL_DisplayMode dm;
	SDL_GetCurrentDisplayMode(0, &dm);

	info.x = 0;
	info.y = 0;
	info.w = dm.w;
	info.h = dm.h;

	screen_width = common_FLOOR_WIDTH*DIM_X;
	screen_height = common_FLOOR_HEIGHT*DIM_Y;
	
	screen_window_title = screen_SCREEN_TITLE;
	screen_options = SDL_WINDOW_OPENGL|SDL_WINDOW_FULLSCREEN_DESKTOP;
	
	screen_window = SDL_CreateWindow(screen_window_title, 0, 0, screen_width, screen_height, screen_options);
	screen_renderer = SDL_CreateRenderer(screen_window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	if (screen_window == NULL or screen_renderer == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create(SDL_GetError())));
	}

	screen_background = SDL_CreateTexture(screen_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, screen_width, screen_height);
	SDL_SetRenderTarget(screen_renderer, screen_background);
	SDL_SetRenderDrawBlendMode(screen_renderer, SDL_BLENDMODE_BLEND);


}

void screen_flip(){

	SDL_SetRenderTarget(screen_renderer, NULL);
	SDL_RenderCopy(screen_renderer, screen_background, NULL, &info);
	SDL_RenderPresent(screen_renderer);
	SDL_SetRenderTarget(screen_renderer, screen_background);


}

void screen_clear(){
	SDL_SetRenderDrawColor(screen_renderer, 0, 0, 0, 0);
	SDL_RenderClear(screen_renderer);


}

SDL_Renderer* screen_getRenderer(){
	return screen_renderer;


}

SDL_Window* screen_getWindow(){
	return screen_window;

}

