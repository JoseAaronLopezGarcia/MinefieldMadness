#ifndef FLAMETHROWER_H
#define FLAMETHROWER_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// map imports
#include <map.h>
//
// floor imports
#include <floor.h>
//
// teleporter imports
#include <teleporter.h>
//
// character imports
#include <character.h>
//
// image imports
#include <image.h>
//
// common imports
#include <common.h>
//
// public globals






extern image_Image flamethrower_flamethrower_img;

extern void flamethrower_init();

typedef struct flamethrower_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct flamethrower_Sprites_struct* self);
	void* (* __getvtable__)(struct flamethrower_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct flamethrower_Sprites_struct* self, struct flamethrower_Sprites_struct* other);
	struct flamethrower_Sprites_struct* (* __operate__)(struct flamethrower_Sprites_struct* self, struct flamethrower_Sprites_struct* other);
	void* (* __str__)(struct flamethrower_Sprites_struct* self);
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
	bool (* clicked)(struct flamethrower_Sprites_struct* self);
	void (* animStart)(struct flamethrower_Sprites_struct* self, int pos);
	void (* animEnd)(struct flamethrower_Sprites_struct* self);
	void (* _stopAnim_681)(struct flamethrower_Sprites_struct* self);
	void (* _walk_443)(struct flamethrower_Sprites_struct* self);
	void (* draw)(struct flamethrower_Sprites_struct* self, int x, int y, int w, int h);
} flamethrower_Sprites_struct;
typedef flamethrower_Sprites_struct* flamethrower_Sprites;
extern const class_id flamethrower_Sprites__classid__;
extern flamethrower_Sprites flamethrower_Sprites_create();
extern void flamethrower_Sprites_init(flamethrower_Sprites self);
extern void flamethrower_Sprites_initsystem(flamethrower_Sprites self);
extern void flamethrower_Sprites_inituser(flamethrower_Sprites self);
extern void flamethrower_Sprites__walk_443(flamethrower_Sprites self);
extern void flamethrower_Sprites_draw(flamethrower_Sprites self, int x, int y, int w, int h);
extern void flamethrower_Sprites_enduser(flamethrower_Sprites self);
extern void flamethrower_Sprites_end(flamethrower_Sprites self);

typedef struct flamethrower_FlameThrowerNode{
	int i;
	int j;
} flamethrower_FlameThrowerNode;
extern void flamethrower_FlameThrowerNode_enduser(flamethrower_FlameThrowerNode self);
extern void flamethrower_FlameThrowerNode_end(flamethrower_FlameThrowerNode self);

typedef struct flamethrower_FlameThrower_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct flamethrower_FlameThrower_struct* self);
	void* (* __getvtable__)(struct flamethrower_FlameThrower_struct* self, class_id id);
	int (* __cmp__)(struct flamethrower_FlameThrower_struct* self, struct flamethrower_FlameThrower_struct* other);
	struct flamethrower_FlameThrower_struct* (* __operate__)(struct flamethrower_FlameThrower_struct* self, struct flamethrower_FlameThrower_struct* other);
	void* (* __str__)(struct flamethrower_FlameThrower_struct* self);
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
	void (* calcOffsets)(struct flamethrower_FlameThrower_struct* self);
	bool (* _isSelected_254)(struct flamethrower_FlameThrower_struct* self);
	void (* onClick)(struct flamethrower_FlameThrower_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct flamethrower_FlameThrower_struct* self, int x, int y);
	void (* _findPath_673)(struct flamethrower_FlameThrower_struct* self, int to_x, int to_y);
	bool (* clicked)(struct flamethrower_FlameThrower_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct flamethrower_FlameThrower_struct* self);
	void (* moveUp)(struct flamethrower_FlameThrower_struct* self);
	void (* moveDown)(struct flamethrower_FlameThrower_struct* self);
	void (* moveLeft)(struct flamethrower_FlameThrower_struct* self);
	void (* moveRight)(struct flamethrower_FlameThrower_struct* self);
	void (* _stop_925)(struct flamethrower_FlameThrower_struct* self);
	void (* draw)(struct flamethrower_FlameThrower_struct* self);
	bool (* addItem)(struct flamethrower_FlameThrower_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct flamethrower_FlameThrower_struct* self);
	void (* setCoordinates)(struct flamethrower_FlameThrower_struct* self, int i, int j);
	void (* updatePosition)(struct flamethrower_FlameThrower_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct flamethrower_FlameThrower_struct* self, long* info);
	void (* setInfoFromSave)(struct flamethrower_FlameThrower_struct* self, long* info);
	void (* cleanUp)(struct flamethrower_FlameThrower_struct* self);
	void (* waitAnimEnd)(struct flamethrower_FlameThrower_struct* self);
	char** (* getInfo)(struct flamethrower_FlameThrower_struct* self);
	void (* drawHelpSprite)(struct flamethrower_FlameThrower_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct flamethrower_FlameThrower_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct flamethrower_FlameThrower_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct flamethrower_FlameThrower_struct* self);
	character_Character (to_transport_606);
	teleporter_MapNode_Data map_nodes_713[24];
	int (available_nodes_669);
	void (* _fillMapNodes_531)(struct flamethrower_FlameThrower_struct* self, int i, int j);
	void (* _setMapNode_448)(struct flamethrower_FlameThrower_struct* self, floor_Floor f);
	void (* _restoreMapNodes_185)(struct flamethrower_FlameThrower_struct* self);
	void (* restoreMap)(struct flamethrower_FlameThrower_struct* self);
	bool (* _inRange_8)(struct flamethrower_FlameThrower_struct* self, int x, int y);
	map_MapObject_struct __vtableiface0__;
} flamethrower_FlameThrower_struct;
typedef flamethrower_FlameThrower_struct* flamethrower_FlameThrower;
extern const class_id flamethrower_FlameThrower__classid__;
extern flamethrower_FlameThrower flamethrower_FlameThrower_create();
extern void flamethrower_FlameThrower_init(flamethrower_FlameThrower self);
extern void flamethrower_FlameThrower_initsystem(flamethrower_FlameThrower self);
extern void flamethrower_FlameThrower_inituser(flamethrower_FlameThrower self);
extern cbcstd_Object flamethrower_FlameThrower_getvtable(flamethrower_FlameThrower self, class_id id);
extern map_MapObject flamethrower_FlameThrower_create_map_MapObject();
extern void flamethrower_FlameThrower_init_map_MapObject(map_MapObject self, flamethrower_FlameThrower __self__);
extern void flamethrower_FlameThrower__setMapNode_448(flamethrower_FlameThrower self, floor_Floor f);
extern void flamethrower_FlameThrower__fillMapNodes_531(flamethrower_FlameThrower self, int i, int j);
extern void flamethrower_FlameThrower__restoreMapNodes_185(flamethrower_FlameThrower self);
extern bool flamethrower_FlameThrower__inRange_8(flamethrower_FlameThrower self, int x, int y);
extern char** flamethrower_FlameThrower_getInfo(flamethrower_FlameThrower self);
extern void flamethrower_FlameThrower__fillHelpRect_284(flamethrower_FlameThrower self, SDL_Rect* rect);
extern char* flamethrower_FlameThrower_getHelpName(flamethrower_FlameThrower self);
extern void flamethrower_FlameThrower_enduser(flamethrower_FlameThrower self);
extern void flamethrower_FlameThrower_end(flamethrower_FlameThrower self);
extern void flamethrower_FlameThrower_end_map_MapObject(map_MapObject self);





#ifdef __cplusplus
};
#endif


#endif//
