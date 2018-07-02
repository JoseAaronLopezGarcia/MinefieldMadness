#ifndef FONT_H
#define FONT_H


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
// image imports
#include <image.h>
//
// screen imports
#include <screen.h>
//
// public globals
#include <SDL2/SDL_ttf.h>



typedef enum{
	font_SIZE_SMALL,
	font_SIZE_NORMAL,
	font_SIZE_MEDIUM,
	font_SIZE_LARGE,
	font_SIZE_HUGE,
};






extern const SDL_Color font_WHITE;

extern const SDL_Color font_BLACK;

extern const SDL_Color font_YELLOW;

extern const SDL_Color font_RED;

extern const int font_font_sizes[5];

extern TTF_Font* font_fonts[5];

typedef struct font_Font_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct font_Font_struct* self);
	void* (* __getvtable__)(struct font_Font_struct* self, class_id id);
	int (* __cmp__)(struct font_Font_struct* self, struct font_Font_struct* other);
	struct font_Font_struct* (* __operate__)(struct font_Font_struct* self, struct font_Font_struct* other);
	void* (* __str__)(struct font_Font_struct* self);
	SDL_Texture* (img_39);
	cbcstd_String path_687;
	int (w_856);
	int (h_856);
	void (* loadTexture)(struct font_Font_struct* self);
	void (* drawClippedScaled)(struct font_Font_struct* self, int x, int y, int w, int h, SDL_Rect* src_rect);
	void (* drawClipped)(struct font_Font_struct* self, int x, int y, SDL_Rect* src_rect);
	void (* drawScaled)(struct font_Font_struct* self, int x, int y, int w, int h);
	void (* draw)(struct font_Font_struct* self, int x, int y);
	int (* getWidth)(struct font_Font_struct* self);
	int (* getHeight)(struct font_Font_struct* self);
	void (* reloadTexture)(struct font_Font_struct* self);
	int size_664;
	void (* render)(struct font_Font_struct* self, const char* text, SDL_Color color, TTF_Font* src_font);
	void (* print)(struct font_Font_struct* self, const char* text, int x, int y, SDL_Color color);
} font_Font_struct;
typedef font_Font_struct* font_Font;
extern const class_id font_Font__classid__;
extern font_Font font_Font_create(int size);
extern void font_Font_init(font_Font self, int size);
extern void font_Font_initsystem(font_Font self);
extern void font_Font_inituser(font_Font self, int size);
extern void font_Font_render(font_Font self, const char* text, SDL_Color color, TTF_Font* src_font);
extern void font_Font_print(font_Font self, const char* text, int x, int y, SDL_Color color);
extern void font_Font_enduser(font_Font self);
extern void font_Font_end(font_Font self);

extern font_Font font_small_font;

extern font_Font font_medium_font;

extern font_Font font_large_font;

extern void font_init();



#ifdef __cplusplus
};
#endif


#endif//
