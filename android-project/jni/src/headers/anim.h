#ifndef ANIM_H
#define ANIM_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// font imports
#include <font.h>
//
// map imports
#include <map.h>
//
// common imports
#include <common.h>
//
// public globals
#include <math.h>



typedef struct anim_AnimatedText_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct anim_AnimatedText_struct* self);
	void* (* __getvtable__)(struct anim_AnimatedText_struct* self, class_id id);
	int (* __cmp__)(struct anim_AnimatedText_struct* self, struct anim_AnimatedText_struct* other);
	struct anim_AnimatedText_struct* (* __operate__)(struct anim_AnimatedText_struct* self, struct anim_AnimatedText_struct* other);
	void* (* __str__)(struct anim_AnimatedText_struct* self);
	float step_274;
	float amplitude_402;
	float slope_449;
	float angle_557;
	int offx_3;
	int offy_400;
	int width_105;
	int text_len_550;
	font_Font* fonts_830;
	char* text_393;
	bool rendered_164;
	void (* draw)(struct anim_AnimatedText_struct* self);
	void (* render)(struct anim_AnimatedText_struct* self, int i);
} anim_AnimatedText_struct;
typedef anim_AnimatedText_struct* anim_AnimatedText;
extern const class_id anim_AnimatedText__classid__;
extern anim_AnimatedText anim_AnimatedText_create(char* text);
extern void anim_AnimatedText_init(anim_AnimatedText self, char* text);
extern void anim_AnimatedText_initsystem(anim_AnimatedText self);
extern void anim_AnimatedText_inituser(anim_AnimatedText self, char* text);
extern void anim_AnimatedText_draw(anim_AnimatedText self);
extern void anim_AnimatedText_render(anim_AnimatedText self, int i);
extern void anim_AnimatedText_enduser(anim_AnimatedText self);
extern void anim_AnimatedText_end(anim_AnimatedText self);

extern void anim_init();



#ifdef __cplusplus
};
#endif


#endif//
