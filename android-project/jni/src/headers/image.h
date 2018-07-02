#ifndef IMAGE_H
#define IMAGE_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// screen imports
#include <screen.h>
//
// public globals

#include "config.h"
typedef struct image_Image_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct image_Image_struct* self);
	void* (* __getvtable__)(struct image_Image_struct* self, class_id id);
	int (* __cmp__)(struct image_Image_struct* self, struct image_Image_struct* other);
	struct image_Image_struct* (* __operate__)(struct image_Image_struct* self, struct image_Image_struct* other);
	void* (* __str__)(struct image_Image_struct* self);
	SDL_Texture* (img_39);
	cbcstd_String path_687;
	int (w_856);
	int (h_856);
	void (* loadTexture)(struct image_Image_struct* self);
	void (* drawClippedScaled)(struct image_Image_struct* self, int x, int y, int w, int h, SDL_Rect* src_rect);
	void (* drawClipped)(struct image_Image_struct* self, int x, int y, SDL_Rect* src_rect);
	void (* drawScaled)(struct image_Image_struct* self, int x, int y, int w, int h);
	void (* draw)(struct image_Image_struct* self, int x, int y);
	int (* getWidth)(struct image_Image_struct* self);
	int (* getHeight)(struct image_Image_struct* self);
	void (* reloadTexture)(struct image_Image_struct* self);
} image_Image_struct;
typedef image_Image_struct* image_Image;
extern const class_id image_Image__classid__;
extern image_Image image_Image_create(const char* path);
extern void image_Image_init(image_Image self, const char* path);
extern void image_Image_initsystem(image_Image self);
extern void image_Image_inituser(image_Image self, const char* path);
extern void image_Image_loadTexture(image_Image self);
extern void image_Image_drawClippedScaled(image_Image self, int x, int y, int w, int h, SDL_Rect* src_rect);
extern void image_Image_drawClipped(image_Image self, int x, int y, SDL_Rect* src_rect);
extern void image_Image_drawScaled(image_Image self, int x, int y, int w, int h);
extern void image_Image_draw(image_Image self, int x, int y);
extern int image_Image_getWidth(image_Image self);
extern int image_Image_getHeight(image_Image self);
extern void image_Image_reloadTexture(image_Image self);
extern void image_Image_enduser(image_Image self);
extern void image_Image_end(image_Image self);


extern void image_init();

#ifdef __cplusplus
};
#endif


#endif//
