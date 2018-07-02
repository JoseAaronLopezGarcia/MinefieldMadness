#ifndef COW_H
#define COW_H


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
// character imports
#include <character.h>
//
// image imports
#include <image.h>
//
// sound imports
#include <sound.h>
//
// pathfinder imports
#include <pathfinder.h>
//
// public globals







extern image_Image cow_cow_img;

extern const int cow_CHAR_WIDTH;

extern const int cow_CHAR_HEIGHT;

extern int cow_ANIM_STATES[3];

extern const int cow_LEFT_Y;

extern const int cow_UP_Y;

extern const int cow_RIGHT_Y;

extern const int cow_DOWN_Y;

typedef struct cow_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cow_Sprites_struct* self);
	void* (* __getvtable__)(struct cow_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct cow_Sprites_struct* self, struct cow_Sprites_struct* other);
	struct cow_Sprites_struct* (* __operate__)(struct cow_Sprites_struct* self, struct cow_Sprites_struct* other);
	void* (* __str__)(struct cow_Sprites_struct* self);
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
	bool (* clicked)(struct cow_Sprites_struct* self);
	void (* animStart)(struct cow_Sprites_struct* self, int pos);
	void (* animEnd)(struct cow_Sprites_struct* self);
	void (* _stopAnim_681)(struct cow_Sprites_struct* self);
	void (* _walk_443)(struct cow_Sprites_struct* self);
	void (* draw)(struct cow_Sprites_struct* self, int x, int y, int w, int h);
} cow_Sprites_struct;
typedef cow_Sprites_struct* cow_Sprites;
extern const class_id cow_Sprites__classid__;
extern cow_Sprites cow_Sprites_create();
extern void cow_Sprites_init(cow_Sprites self);
extern void cow_Sprites_initsystem(cow_Sprites self);
extern void cow_Sprites_inituser(cow_Sprites self);
extern void cow_Sprites_draw(cow_Sprites self, int x, int y, int w, int h);
extern void cow_Sprites_enduser(cow_Sprites self);
extern void cow_Sprites_end(cow_Sprites self);

typedef struct cow_Cow_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct cow_Cow_struct* self);
	void* (* __getvtable__)(struct cow_Cow_struct* self, class_id id);
	int (* __cmp__)(struct cow_Cow_struct* self, struct cow_Cow_struct* other);
	struct cow_Cow_struct* (* __operate__)(struct cow_Cow_struct* self, struct cow_Cow_struct* other);
	void* (* __str__)(struct cow_Cow_struct* self);
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
	void (* calcOffsets)(struct cow_Cow_struct* self);
	bool (* _isSelected_254)(struct cow_Cow_struct* self);
	void (* onClick)(struct cow_Cow_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct cow_Cow_struct* self, int x, int y);
	void (* _findPath_673)(struct cow_Cow_struct* self, int to_x, int to_y);
	bool (* clicked)(struct cow_Cow_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct cow_Cow_struct* self);
	void (* moveUp)(struct cow_Cow_struct* self);
	void (* moveDown)(struct cow_Cow_struct* self);
	void (* moveLeft)(struct cow_Cow_struct* self);
	void (* moveRight)(struct cow_Cow_struct* self);
	void (* _stop_925)(struct cow_Cow_struct* self);
	void (* draw)(struct cow_Cow_struct* self);
	bool (* addItem)(struct cow_Cow_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct cow_Cow_struct* self);
	void (* setCoordinates)(struct cow_Cow_struct* self, int i, int j);
	void (* updatePosition)(struct cow_Cow_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct cow_Cow_struct* self, long* info);
	void (* setInfoFromSave)(struct cow_Cow_struct* self, long* info);
	void (* cleanUp)(struct cow_Cow_struct* self);
	void (* waitAnimEnd)(struct cow_Cow_struct* self);
	char** (* getInfo)(struct cow_Cow_struct* self);
	void (* drawHelpSprite)(struct cow_Cow_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct cow_Cow_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct cow_Cow_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct cow_Cow_struct* self);
	int (to_i_285);
	int (to_j_253);
	int (eaten_710);
	bool (is_item_619);
	void (* _eat_626)(struct cow_Cow_struct* self, int i, int j);
	bool (* hasColided)(struct cow_Cow_struct* self);
	map_MapObject_struct __vtableiface0__;
} cow_Cow_struct;
typedef cow_Cow_struct* cow_Cow;
extern const class_id cow_Cow__classid__;
extern cow_Cow cow_Cow_create();
extern void cow_Cow_init(cow_Cow self);
extern void cow_Cow_initsystem(cow_Cow self);
extern void cow_Cow_inituser(cow_Cow self);
extern cbcstd_Object cow_Cow_getvtable(cow_Cow self, class_id id);
extern map_MapObject cow_Cow_create_map_MapObject();
extern void cow_Cow_init_map_MapObject(map_MapObject self, cow_Cow __self__);
extern void cow_Cow_interact(cow_Cow self);
extern void cow_Cow__eat_626(cow_Cow self, int i, int j);
extern bool cow_Cow_hasColided(cow_Cow self);
extern void cow_Cow_onClick(cow_Cow self, int x, int y);
extern void cow_Cow__findPath_673(cow_Cow self, int to_x, int to_y);
extern char** cow_Cow_getInfo(cow_Cow self);
extern void cow_Cow__fillHelpRect_284(cow_Cow self, SDL_Rect* rect);
extern char* cow_Cow_getHelpName(cow_Cow self);
extern void cow_Cow_getSaveInfo(cow_Cow self, long* info);
extern void cow_Cow_setInfoFromSave(cow_Cow self, long* info);
extern void cow_Cow_enduser(cow_Cow self);
extern void cow_Cow_end(cow_Cow self);
extern void cow_Cow_end_map_MapObject(map_MapObject self);

extern void cow_init();




#ifdef __cplusplus
};
#endif


#endif//
