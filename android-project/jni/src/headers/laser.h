#ifndef LASER_H
#define LASER_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// character imports
#include <character.h>
//
// image imports
#include <image.h>
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
// common imports
#include <common.h>
//
// sound imports
#include <sound.h>
//
// public globals







extern image_Image laser_laser_img;

extern image_Image laser_laserbeam_img;

extern void laser_init();

typedef struct laser_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct laser_Sprites_struct* self);
	void* (* __getvtable__)(struct laser_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct laser_Sprites_struct* self, struct laser_Sprites_struct* other);
	struct laser_Sprites_struct* (* __operate__)(struct laser_Sprites_struct* self, struct laser_Sprites_struct* other);
	void* (* __str__)(struct laser_Sprites_struct* self);
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
	bool (* clicked)(struct laser_Sprites_struct* self);
	void (* animStart)(struct laser_Sprites_struct* self, int pos);
	void (* animEnd)(struct laser_Sprites_struct* self);
	void (* _stopAnim_681)(struct laser_Sprites_struct* self);
	void (* _walk_443)(struct laser_Sprites_struct* self);
	void (* draw)(struct laser_Sprites_struct* self, int x, int y, int w, int h);
} laser_Sprites_struct;
typedef laser_Sprites_struct* laser_Sprites;
extern const class_id laser_Sprites__classid__;
extern laser_Sprites laser_Sprites_create();
extern void laser_Sprites_init(laser_Sprites self);
extern void laser_Sprites_initsystem(laser_Sprites self);
extern void laser_Sprites_inituser(laser_Sprites self);
extern void laser_Sprites__walk_443(laser_Sprites self);
extern void laser_Sprites_animStart(laser_Sprites self, int pos);
extern void laser_Sprites_draw(laser_Sprites self, int x, int y, int w, int h);
extern void laser_Sprites_enduser(laser_Sprites self);
extern void laser_Sprites_end(laser_Sprites self);

typedef struct laser_Laser_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct laser_Laser_struct* self);
	void* (* __getvtable__)(struct laser_Laser_struct* self, class_id id);
	int (* __cmp__)(struct laser_Laser_struct* self, struct laser_Laser_struct* other);
	struct laser_Laser_struct* (* __operate__)(struct laser_Laser_struct* self, struct laser_Laser_struct* other);
	void* (* __str__)(struct laser_Laser_struct* self);
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
	void (* calcOffsets)(struct laser_Laser_struct* self);
	bool (* _isSelected_254)(struct laser_Laser_struct* self);
	void (* onClick)(struct laser_Laser_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct laser_Laser_struct* self, int x, int y);
	void (* _findPath_673)(struct laser_Laser_struct* self, int to_x, int to_y);
	bool (* clicked)(struct laser_Laser_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct laser_Laser_struct* self);
	void (* moveUp)(struct laser_Laser_struct* self);
	void (* moveDown)(struct laser_Laser_struct* self);
	void (* moveLeft)(struct laser_Laser_struct* self);
	void (* moveRight)(struct laser_Laser_struct* self);
	void (* _stop_925)(struct laser_Laser_struct* self);
	void (* draw)(struct laser_Laser_struct* self);
	bool (* addItem)(struct laser_Laser_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct laser_Laser_struct* self);
	void (* setCoordinates)(struct laser_Laser_struct* self, int i, int j);
	void (* updatePosition)(struct laser_Laser_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct laser_Laser_struct* self, long* info);
	void (* setInfoFromSave)(struct laser_Laser_struct* self, long* info);
	void (* cleanUp)(struct laser_Laser_struct* self);
	void (* waitAnimEnd)(struct laser_Laser_struct* self);
	char** (* getInfo)(struct laser_Laser_struct* self);
	void (* drawHelpSprite)(struct laser_Laser_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct laser_Laser_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct laser_Laser_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct laser_Laser_struct* self);
	map_MapObject_struct __vtableiface0__;
} laser_Laser_struct;
typedef laser_Laser_struct* laser_Laser;
extern const class_id laser_Laser__classid__;
extern laser_Laser laser_Laser_create();
extern void laser_Laser_init(laser_Laser self);
extern void laser_Laser_initsystem(laser_Laser self);
extern void laser_Laser_inituser(laser_Laser self);
extern cbcstd_Object laser_Laser_getvtable(laser_Laser self, class_id id);
extern map_MapObject laser_Laser_create_map_MapObject();
extern void laser_Laser_init_map_MapObject(map_MapObject self, laser_Laser __self__);
extern void laser_Laser_onClick(laser_Laser self, int x, int y);
extern void laser_Laser_draw(laser_Laser self);
extern void laser_Laser__findPath_673(laser_Laser self, int to_x, int to_y);
extern void laser_Laser__stop_925(laser_Laser self);
extern void laser_Laser_interact(laser_Laser self);
extern char** laser_Laser_getInfo(laser_Laser self);
extern void laser_Laser__fillHelpRect_284(laser_Laser self, SDL_Rect* rect);
extern char* laser_Laser_getHelpName(laser_Laser self);
extern void laser_Laser_enduser(laser_Laser self);
extern void laser_Laser_end(laser_Laser self);
extern void laser_Laser_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
