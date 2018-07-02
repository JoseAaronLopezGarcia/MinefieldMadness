#ifndef MAGNET_H
#define MAGNET_H


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
// character imports
#include <character.h>
//
// teleporter imports
#include <teleporter.h>
//
// image imports
#include <image.h>
//
// common imports
#include <common.h>
//
// character imports
#include <character.h>
//
// public globals







extern image_Image magnet_magnet_img;

extern void magnet_init();

typedef struct magnet_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct magnet_Sprites_struct* self);
	void* (* __getvtable__)(struct magnet_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct magnet_Sprites_struct* self, struct magnet_Sprites_struct* other);
	struct magnet_Sprites_struct* (* __operate__)(struct magnet_Sprites_struct* self, struct magnet_Sprites_struct* other);
	void* (* __str__)(struct magnet_Sprites_struct* self);
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
	bool (* clicked)(struct magnet_Sprites_struct* self);
	void (* animStart)(struct magnet_Sprites_struct* self, int pos);
	void (* animEnd)(struct magnet_Sprites_struct* self);
	void (* _stopAnim_681)(struct magnet_Sprites_struct* self);
	void (* _walk_443)(struct magnet_Sprites_struct* self);
	void (* draw)(struct magnet_Sprites_struct* self, int x, int y, int w, int h);
} magnet_Sprites_struct;
typedef magnet_Sprites_struct* magnet_Sprites;
extern const class_id magnet_Sprites__classid__;
extern magnet_Sprites magnet_Sprites_create();
extern void magnet_Sprites_init(magnet_Sprites self);
extern void magnet_Sprites_initsystem(magnet_Sprites self);
extern void magnet_Sprites_inituser(magnet_Sprites self);
extern void magnet_Sprites__walk_443(magnet_Sprites self);
extern void magnet_Sprites_draw(magnet_Sprites self, int x, int y, int w, int h);
extern void magnet_Sprites_enduser(magnet_Sprites self);
extern void magnet_Sprites_end(magnet_Sprites self);

typedef struct magnet_Magnet_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct magnet_Magnet_struct* self);
	void* (* __getvtable__)(struct magnet_Magnet_struct* self, class_id id);
	int (* __cmp__)(struct magnet_Magnet_struct* self, struct magnet_Magnet_struct* other);
	struct magnet_Magnet_struct* (* __operate__)(struct magnet_Magnet_struct* self, struct magnet_Magnet_struct* other);
	void* (* __str__)(struct magnet_Magnet_struct* self);
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
	void (* calcOffsets)(struct magnet_Magnet_struct* self);
	bool (* _isSelected_254)(struct magnet_Magnet_struct* self);
	void (* onClick)(struct magnet_Magnet_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct magnet_Magnet_struct* self, int x, int y);
	void (* _findPath_673)(struct magnet_Magnet_struct* self, int to_x, int to_y);
	bool (* clicked)(struct magnet_Magnet_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct magnet_Magnet_struct* self);
	void (* moveUp)(struct magnet_Magnet_struct* self);
	void (* moveDown)(struct magnet_Magnet_struct* self);
	void (* moveLeft)(struct magnet_Magnet_struct* self);
	void (* moveRight)(struct magnet_Magnet_struct* self);
	void (* _stop_925)(struct magnet_Magnet_struct* self);
	void (* draw)(struct magnet_Magnet_struct* self);
	bool (* addItem)(struct magnet_Magnet_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct magnet_Magnet_struct* self);
	void (* setCoordinates)(struct magnet_Magnet_struct* self, int i, int j);
	void (* updatePosition)(struct magnet_Magnet_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct magnet_Magnet_struct* self, long* info);
	void (* setInfoFromSave)(struct magnet_Magnet_struct* self, long* info);
	void (* cleanUp)(struct magnet_Magnet_struct* self);
	void (* waitAnimEnd)(struct magnet_Magnet_struct* self);
	char** (* getInfo)(struct magnet_Magnet_struct* self);
	void (* drawHelpSprite)(struct magnet_Magnet_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct magnet_Magnet_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct magnet_Magnet_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct magnet_Magnet_struct* self);
	character_Character (to_transport_606);
	teleporter_MapNode_Data map_nodes_713[24];
	int (available_nodes_669);
	void (* _fillMapNodes_531)(struct magnet_Magnet_struct* self, int i, int j);
	void (* _setMapNode_448)(struct magnet_Magnet_struct* self, floor_Floor f);
	void (* _restoreMapNodes_185)(struct magnet_Magnet_struct* self);
	void (* restoreMap)(struct magnet_Magnet_struct* self);
	bool (* _inRange_8)(struct magnet_Magnet_struct* self, int x, int y);
	bool used_254;
	map_MapObject_struct __vtableiface0__;
} magnet_Magnet_struct;
typedef magnet_Magnet_struct* magnet_Magnet;
extern const class_id magnet_Magnet__classid__;
extern magnet_Magnet magnet_Magnet_create();
extern void magnet_Magnet_init(magnet_Magnet self);
extern void magnet_Magnet_initsystem(magnet_Magnet self);
extern void magnet_Magnet_inituser(magnet_Magnet self);
extern cbcstd_Object magnet_Magnet_getvtable(magnet_Magnet self, class_id id);
extern map_MapObject magnet_Magnet_create_map_MapObject();
extern void magnet_Magnet_init_map_MapObject(map_MapObject self, magnet_Magnet __self__);
extern void magnet_Magnet_draw(magnet_Magnet self);
extern void magnet_Magnet_onClick(magnet_Magnet self, int x, int y);
extern void magnet_Magnet__findPath_673(magnet_Magnet self, int to_x, int to_y);
extern void magnet_Magnet__setMapNode_448(magnet_Magnet self, floor_Floor f);
extern void magnet_Magnet__fillMapNodes_531(magnet_Magnet self, int i, int j);
extern void magnet_Magnet__restoreMapNodes_185(magnet_Magnet self);
extern bool magnet_Magnet__inRange_8(magnet_Magnet self, int x, int y);
extern char** magnet_Magnet_getInfo(magnet_Magnet self);
extern void magnet_Magnet__fillHelpRect_284(magnet_Magnet self, SDL_Rect* rect);
extern char* magnet_Magnet_getHelpName(magnet_Magnet self);
extern void magnet_Magnet_enduser(magnet_Magnet self);
extern void magnet_Magnet_end(magnet_Magnet self);
extern void magnet_Magnet_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
