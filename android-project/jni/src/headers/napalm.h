#ifndef NAPALM_H
#define NAPALM_H


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
// map imports
#include <map.h>
//
// image imports
#include <image.h>
//
// grenade imports
#include <grenade.h>
//
// character imports
#include <character.h>
//
// public globals





extern image_Image napalm_napalm_img;

extern void napalm_init();

typedef struct napalm_Napalm_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct napalm_Napalm_struct* self);
	void* (* __getvtable__)(struct napalm_Napalm_struct* self, class_id id);
	int (* __cmp__)(struct napalm_Napalm_struct* self, struct napalm_Napalm_struct* other);
	struct napalm_Napalm_struct* (* __operate__)(struct napalm_Napalm_struct* self, struct napalm_Napalm_struct* other);
	void* (* __str__)(struct napalm_Napalm_struct* self);
	bool (selected_365);
	int x_405;
	int y_782;
	int to_x_969;
	int to_y_714;
	int (height_399);
	int (width_945);
	int x_offset_475;
	int y_offset_563;
	character_Sprites sprites_11;
	int (anim_state_x_214);
	int (anim_state_y_697);
	int anim_453;
	int (walk_speed_577);
	int (lives_836);
	bool avoid_pickup_32;
	cbcstd_List movements_662;
	cbcstd_Semaphore move_sema_518;
	void (* calcOffsets)(struct napalm_Napalm_struct* self);
	bool (* _isSelected_254)(struct napalm_Napalm_struct* self);
	void (* onClick)(struct napalm_Napalm_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct napalm_Napalm_struct* self, int x, int y);
	void (* _findPath_673)(struct napalm_Napalm_struct* self, int to_x, int to_y);
	bool (* clicked)(struct napalm_Napalm_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct napalm_Napalm_struct* self);
	void (* moveUp)(struct napalm_Napalm_struct* self);
	void (* moveDown)(struct napalm_Napalm_struct* self);
	void (* moveLeft)(struct napalm_Napalm_struct* self);
	void (* moveRight)(struct napalm_Napalm_struct* self);
	void (* _stop_925)(struct napalm_Napalm_struct* self);
	void (* draw)(struct napalm_Napalm_struct* self);
	bool (* addItem)(struct napalm_Napalm_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct napalm_Napalm_struct* self);
	void (* setCoordinates)(struct napalm_Napalm_struct* self, int i, int j);
	void (* updatePosition)(struct napalm_Napalm_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct napalm_Napalm_struct* self, long* info);
	void (* setInfoFromSave)(struct napalm_Napalm_struct* self, long* info);
	void (* cleanUp)(struct napalm_Napalm_struct* self);
	void (* waitAnimEnd)(struct napalm_Napalm_struct* self);
	char** (* getInfo)(struct napalm_Napalm_struct* self);
	void (* drawHelpSprite)(struct napalm_Napalm_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct napalm_Napalm_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct napalm_Napalm_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct napalm_Napalm_struct* self);
	int anim_x_953;
	int anim_y_550;
	bool animating_154;
	bool exploded_659;
	bool (* _animEnded_347)(struct napalm_Napalm_struct* self);
	void (* _animate_314)(struct napalm_Napalm_struct* self);
	void (* findPath)(struct napalm_Napalm_struct* self, int x, int y);
	bool (* _checkNode_197)(struct napalm_Napalm_struct* self, floor_Floor f);
	map_MapObject grenades_1[DIM_X-2];
	map_MapObject_struct __vtableiface0__;
} napalm_Napalm_struct;
typedef napalm_Napalm_struct* napalm_Napalm;
extern const class_id napalm_Napalm__classid__;
extern napalm_Napalm napalm_Napalm_create();
extern void napalm_Napalm_init(napalm_Napalm self);
extern void napalm_Napalm_initsystem(napalm_Napalm self);
extern void napalm_Napalm_inituser(napalm_Napalm self);
extern cbcstd_Object napalm_Napalm_getvtable(napalm_Napalm self, class_id id);
extern map_MapObject napalm_Napalm_create_map_MapObject();
extern void napalm_Napalm_init_map_MapObject(map_MapObject self, napalm_Napalm __self__);
extern void napalm_Napalm_draw(napalm_Napalm self);
extern void napalm_Napalm_onClick(napalm_Napalm self, int x, int y);
extern void napalm_Napalm_interact(napalm_Napalm self);
extern char** napalm_Napalm_getInfo(napalm_Napalm self);
extern char* napalm_Napalm_getHelpName(napalm_Napalm self);
extern void napalm_Napalm_enduser(napalm_Napalm self);
extern void napalm_Napalm_end(napalm_Napalm self);
extern void napalm_Napalm_end_map_MapObject(map_MapObject self);



#ifdef __cplusplus
};
#endif


#endif//
