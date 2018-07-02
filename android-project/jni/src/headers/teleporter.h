#ifndef TELEPORTER_H
#define TELEPORTER_H


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
// character imports
#include <character.h>
//
// map imports
#include <map.h>
//
// floor imports
#include <floor.h>
//
// pathfinder imports
#include <pathfinder.h>
//
// public globals






extern image_Image teleporter_teleporter_img;

extern void teleporter_init();

typedef struct teleporter_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct teleporter_Sprites_struct* self);
	void* (* __getvtable__)(struct teleporter_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct teleporter_Sprites_struct* self, struct teleporter_Sprites_struct* other);
	struct teleporter_Sprites_struct* (* __operate__)(struct teleporter_Sprites_struct* self, struct teleporter_Sprites_struct* other);
	void* (* __str__)(struct teleporter_Sprites_struct* self);
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
	bool (* clicked)(struct teleporter_Sprites_struct* self);
	void (* animStart)(struct teleporter_Sprites_struct* self, int pos);
	void (* animEnd)(struct teleporter_Sprites_struct* self);
	void (* _stopAnim_681)(struct teleporter_Sprites_struct* self);
	void (* _walk_443)(struct teleporter_Sprites_struct* self);
	void (* draw)(struct teleporter_Sprites_struct* self, int x, int y, int w, int h);
} teleporter_Sprites_struct;
typedef teleporter_Sprites_struct* teleporter_Sprites;
extern const class_id teleporter_Sprites__classid__;
extern teleporter_Sprites teleporter_Sprites_create();
extern void teleporter_Sprites_init(teleporter_Sprites self);
extern void teleporter_Sprites_initsystem(teleporter_Sprites self);
extern void teleporter_Sprites_inituser(teleporter_Sprites self);
extern void teleporter_Sprites__walk_443(teleporter_Sprites self);
extern void teleporter_Sprites_draw(teleporter_Sprites self, int x, int y, int w, int h);
extern void teleporter_Sprites_enduser(teleporter_Sprites self);
extern void teleporter_Sprites_end(teleporter_Sprites self);

typedef struct teleporter_MapNode_Data{
	int i;
	int j;
	floor_TerrainType type;
} teleporter_MapNode_Data;
extern void teleporter_MapNode_Data_enduser(teleporter_MapNode_Data self);
extern void teleporter_MapNode_Data_end(teleporter_MapNode_Data self);

typedef struct teleporter_Teleporter_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct teleporter_Teleporter_struct* self);
	void* (* __getvtable__)(struct teleporter_Teleporter_struct* self, class_id id);
	int (* __cmp__)(struct teleporter_Teleporter_struct* self, struct teleporter_Teleporter_struct* other);
	struct teleporter_Teleporter_struct* (* __operate__)(struct teleporter_Teleporter_struct* self, struct teleporter_Teleporter_struct* other);
	void* (* __str__)(struct teleporter_Teleporter_struct* self);
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
	void (* calcOffsets)(struct teleporter_Teleporter_struct* self);
	bool (* _isSelected_254)(struct teleporter_Teleporter_struct* self);
	void (* onClick)(struct teleporter_Teleporter_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct teleporter_Teleporter_struct* self, int x, int y);
	void (* _findPath_673)(struct teleporter_Teleporter_struct* self, int to_x, int to_y);
	bool (* clicked)(struct teleporter_Teleporter_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct teleporter_Teleporter_struct* self);
	void (* moveUp)(struct teleporter_Teleporter_struct* self);
	void (* moveDown)(struct teleporter_Teleporter_struct* self);
	void (* moveLeft)(struct teleporter_Teleporter_struct* self);
	void (* moveRight)(struct teleporter_Teleporter_struct* self);
	void (* _stop_925)(struct teleporter_Teleporter_struct* self);
	void (* draw)(struct teleporter_Teleporter_struct* self);
	bool (* addItem)(struct teleporter_Teleporter_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct teleporter_Teleporter_struct* self);
	void (* setCoordinates)(struct teleporter_Teleporter_struct* self, int i, int j);
	void (* updatePosition)(struct teleporter_Teleporter_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct teleporter_Teleporter_struct* self, long* info);
	void (* setInfoFromSave)(struct teleporter_Teleporter_struct* self, long* info);
	void (* cleanUp)(struct teleporter_Teleporter_struct* self);
	void (* waitAnimEnd)(struct teleporter_Teleporter_struct* self);
	char** (* getInfo)(struct teleporter_Teleporter_struct* self);
	void (* drawHelpSprite)(struct teleporter_Teleporter_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct teleporter_Teleporter_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct teleporter_Teleporter_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct teleporter_Teleporter_struct* self);
	character_Character (to_transport_606);
	teleporter_MapNode_Data map_nodes_713[24];
	int (available_nodes_669);
	void (* _fillMapNodes_531)(struct teleporter_Teleporter_struct* self, int i, int j);
	void (* _setMapNode_448)(struct teleporter_Teleporter_struct* self, floor_Floor f);
	void (* _restoreMapNodes_185)(struct teleporter_Teleporter_struct* self);
	void (* restoreMap)(struct teleporter_Teleporter_struct* self);
	bool (* _inRange_8)(struct teleporter_Teleporter_struct* self, int x, int y);
	map_MapObject_struct __vtableiface0__;
} teleporter_Teleporter_struct;
typedef teleporter_Teleporter_struct* teleporter_Teleporter;
extern const class_id teleporter_Teleporter__classid__;
extern teleporter_Teleporter teleporter_Teleporter_create();
extern void teleporter_Teleporter_init(teleporter_Teleporter self);
extern void teleporter_Teleporter_initsystem(teleporter_Teleporter self);
extern void teleporter_Teleporter_inituser(teleporter_Teleporter self);
extern cbcstd_Object teleporter_Teleporter_getvtable(teleporter_Teleporter self, class_id id);
extern map_MapObject teleporter_Teleporter_create_map_MapObject();
extern void teleporter_Teleporter_init_map_MapObject(map_MapObject self, teleporter_Teleporter __self__);
extern void teleporter_Teleporter_draw(teleporter_Teleporter self);
extern void teleporter_Teleporter_onClick(teleporter_Teleporter self, int x, int y);
extern void teleporter_Teleporter__fillMapNodes_531(teleporter_Teleporter self, int i, int j);
extern void teleporter_Teleporter__setMapNode_448(teleporter_Teleporter self, floor_Floor f);
extern void teleporter_Teleporter__restoreMapNodes_185(teleporter_Teleporter self);
extern void teleporter_Teleporter_restoreMap(teleporter_Teleporter self);
extern bool teleporter_Teleporter__inRange_8(teleporter_Teleporter self, int x, int y);
extern void teleporter_Teleporter_interact(teleporter_Teleporter self);
extern char** teleporter_Teleporter_getInfo(teleporter_Teleporter self);
extern void teleporter_Teleporter__fillHelpRect_284(teleporter_Teleporter self, SDL_Rect* rect);
extern char* teleporter_Teleporter_getHelpName(teleporter_Teleporter self);
extern void teleporter_Teleporter_enduser(teleporter_Teleporter self);
extern void teleporter_Teleporter_end(teleporter_Teleporter self);
extern void teleporter_Teleporter_end_map_MapObject(map_MapObject self);





#ifdef __cplusplus
};
#endif


#endif//
