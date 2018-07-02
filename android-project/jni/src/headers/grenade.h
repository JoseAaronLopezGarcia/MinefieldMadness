#ifndef GRENADE_H
#define GRENADE_H


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
// floor imports
#include <floor.h>
//
// image imports
#include <image.h>
//
// character imports
#include <character.h>
//
// public globals





extern image_Image grenade_grenade_img;

extern const int grenade_CHAR_WIDTH;

extern const int grenade_CHAR_HEIGHT;

extern int grenade_ANIM_STATES[4];

extern const int grenade_LEFT_Y;

extern const int grenade_UP_Y;

extern const int grenade_RIGHT_Y;

extern const int grenade_DOWN_Y;

extern void grenade_init();

typedef struct grenade_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct grenade_Sprites_struct* self);
	void* (* __getvtable__)(struct grenade_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct grenade_Sprites_struct* self, struct grenade_Sprites_struct* other);
	struct grenade_Sprites_struct* (* __operate__)(struct grenade_Sprites_struct* self, struct grenade_Sprites_struct* other);
	void* (* __str__)(struct grenade_Sprites_struct* self);
	bool animating_559;
	bool selected_580;
	int pos_987;
	int skip_walk_829;
	int walk_anim_287;
	int down_y_122;
	int up_y_544;
	int left_y_559;
	int right_y_714;
	int max_anims_975;
	int default_anim_623;
	int default_skip_walk_269;
	int last_anim_124;
	int* anim_states_811;
	image_Image spritesheet_722;
	SDL_Rect rect_976;
	bool (* clicked)(struct grenade_Sprites_struct* self);
	void (* animStart)(struct grenade_Sprites_struct* self, int pos);
	void (* animEnd)(struct grenade_Sprites_struct* self);
	void (* _stopAnim_681)(struct grenade_Sprites_struct* self);
	void (* _walk_443)(struct grenade_Sprites_struct* self);
	void (* draw)(struct grenade_Sprites_struct* self, int x, int y, int w, int h);
} grenade_Sprites_struct;
typedef grenade_Sprites_struct* grenade_Sprites;
extern const class_id grenade_Sprites__classid__;
extern grenade_Sprites grenade_Sprites_create();
extern void grenade_Sprites_init(grenade_Sprites self);
extern void grenade_Sprites_initsystem(grenade_Sprites self);
extern void grenade_Sprites_inituser(grenade_Sprites self);
extern void grenade_Sprites_draw(grenade_Sprites self, int x, int y, int w, int h);
extern void grenade_Sprites_enduser(grenade_Sprites self);
extern void grenade_Sprites_end(grenade_Sprites self);

typedef struct grenade_Grenade_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct grenade_Grenade_struct* self);
	void* (* __getvtable__)(struct grenade_Grenade_struct* self, class_id id);
	int (* __cmp__)(struct grenade_Grenade_struct* self, struct grenade_Grenade_struct* other);
	struct grenade_Grenade_struct* (* __operate__)(struct grenade_Grenade_struct* self, struct grenade_Grenade_struct* other);
	void* (* __str__)(struct grenade_Grenade_struct* self);
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
	void (* calcOffsets)(struct grenade_Grenade_struct* self);
	bool (* _isSelected_254)(struct grenade_Grenade_struct* self);
	void (* onClick)(struct grenade_Grenade_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct grenade_Grenade_struct* self, int x, int y);
	void (* _findPath_673)(struct grenade_Grenade_struct* self, int to_x, int to_y);
	bool (* clicked)(struct grenade_Grenade_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct grenade_Grenade_struct* self);
	void (* moveUp)(struct grenade_Grenade_struct* self);
	void (* moveDown)(struct grenade_Grenade_struct* self);
	void (* moveLeft)(struct grenade_Grenade_struct* self);
	void (* moveRight)(struct grenade_Grenade_struct* self);
	void (* _stop_925)(struct grenade_Grenade_struct* self);
	void (* draw)(struct grenade_Grenade_struct* self);
	bool (* addItem)(struct grenade_Grenade_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct grenade_Grenade_struct* self);
	void (* setCoordinates)(struct grenade_Grenade_struct* self, int i, int j);
	void (* updatePosition)(struct grenade_Grenade_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct grenade_Grenade_struct* self, long* info);
	void (* setInfoFromSave)(struct grenade_Grenade_struct* self, long* info);
	void (* cleanUp)(struct grenade_Grenade_struct* self);
	void (* waitAnimEnd)(struct grenade_Grenade_struct* self);
	char** (* getInfo)(struct grenade_Grenade_struct* self);
	void (* drawHelpSprite)(struct grenade_Grenade_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct grenade_Grenade_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct grenade_Grenade_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct grenade_Grenade_struct* self);
	int anim_x_953;
	int anim_y_550;
	bool animating_154;
	bool exploded_659;
	bool (* _animEnded_347)(struct grenade_Grenade_struct* self);
	void (* _animate_314)(struct grenade_Grenade_struct* self);
	void (* findPath)(struct grenade_Grenade_struct* self, int x, int y);
	bool (* _checkNode_197)(struct grenade_Grenade_struct* self, floor_Floor f);
	map_MapObject_struct __vtableiface0__;
} grenade_Grenade_struct;
typedef grenade_Grenade_struct* grenade_Grenade;
extern const class_id grenade_Grenade__classid__;
extern grenade_Grenade grenade_Grenade_create();
extern void grenade_Grenade_init(grenade_Grenade self);
extern void grenade_Grenade_initsystem(grenade_Grenade self);
extern void grenade_Grenade_inituser(grenade_Grenade self);
extern cbcstd_Object grenade_Grenade_getvtable(grenade_Grenade self, class_id id);
extern map_MapObject grenade_Grenade_create_map_MapObject();
extern void grenade_Grenade_init_map_MapObject(map_MapObject self, grenade_Grenade __self__);
extern void grenade_Grenade_draw(grenade_Grenade self);
extern bool grenade_Grenade__animEnded_347(grenade_Grenade self);
extern void grenade_Grenade__animate_314(grenade_Grenade self);
extern bool grenade_Grenade__canGoThere_896(grenade_Grenade self, int x, int y);
extern void grenade_Grenade__findPath_673(grenade_Grenade self, int to_x, int to_y);
extern void grenade_Grenade_findPath(grenade_Grenade self, int x, int y);
extern void grenade_Grenade_interact(grenade_Grenade self);
extern bool grenade_Grenade__checkNode_197(grenade_Grenade self, floor_Floor f);
extern void grenade_Grenade_onClick(grenade_Grenade self, int x, int y);
extern char** grenade_Grenade_getInfo(grenade_Grenade self);
extern void grenade_Grenade__fillHelpRect_284(grenade_Grenade self, SDL_Rect* rect);
extern char* grenade_Grenade_getHelpName(grenade_Grenade self);
extern void grenade_Grenade_enduser(grenade_Grenade self);
extern void grenade_Grenade_end(grenade_Grenade self);
extern void grenade_Grenade_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
