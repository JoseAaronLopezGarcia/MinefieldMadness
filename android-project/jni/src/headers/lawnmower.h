#ifndef LAWNMOWER_H
#define LAWNMOWER_H


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
// sound imports
#include <sound.h>
//
// character imports
#include <character.h>
//
// pathfinder imports
#include <pathfinder.h>
//
// public globals







extern image_Image lawnmower_lawnmower_img;

extern sound_Sound lawnmower_motor;

extern const int lawnmower_CHAR_WIDTH;

extern const int lawnmower_CHAR_HEIGHT;

extern int lawnmower_ANIM_STATES[4];

extern const int lawnmower_LEFT_Y;

extern const int lawnmower_UP_Y;

extern const int lawnmower_RIGHT_Y;

extern const int lawnmower_DOWN_Y;

extern void lawnmower_init();

typedef struct lawnmower_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct lawnmower_Sprites_struct* self);
	void* (* __getvtable__)(struct lawnmower_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct lawnmower_Sprites_struct* self, struct lawnmower_Sprites_struct* other);
	struct lawnmower_Sprites_struct* (* __operate__)(struct lawnmower_Sprites_struct* self, struct lawnmower_Sprites_struct* other);
	void* (* __str__)(struct lawnmower_Sprites_struct* self);
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
	bool (* clicked)(struct lawnmower_Sprites_struct* self);
	void (* animStart)(struct lawnmower_Sprites_struct* self, int pos);
	void (* animEnd)(struct lawnmower_Sprites_struct* self);
	void (* _stopAnim_681)(struct lawnmower_Sprites_struct* self);
	void (* _walk_443)(struct lawnmower_Sprites_struct* self);
	void (* draw)(struct lawnmower_Sprites_struct* self, int x, int y, int w, int h);
} lawnmower_Sprites_struct;
typedef lawnmower_Sprites_struct* lawnmower_Sprites;
extern const class_id lawnmower_Sprites__classid__;
extern lawnmower_Sprites lawnmower_Sprites_create();
extern void lawnmower_Sprites_init(lawnmower_Sprites self);
extern void lawnmower_Sprites_initsystem(lawnmower_Sprites self);
extern void lawnmower_Sprites_inituser(lawnmower_Sprites self);
extern void lawnmower_Sprites_draw(lawnmower_Sprites self, int x, int y, int w, int h);
extern void lawnmower_Sprites_enduser(lawnmower_Sprites self);
extern void lawnmower_Sprites_end(lawnmower_Sprites self);

typedef struct lawnmower_LawnMower_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct lawnmower_LawnMower_struct* self);
	void* (* __getvtable__)(struct lawnmower_LawnMower_struct* self, class_id id);
	int (* __cmp__)(struct lawnmower_LawnMower_struct* self, struct lawnmower_LawnMower_struct* other);
	struct lawnmower_LawnMower_struct* (* __operate__)(struct lawnmower_LawnMower_struct* self, struct lawnmower_LawnMower_struct* other);
	void* (* __str__)(struct lawnmower_LawnMower_struct* self);
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
	void (* calcOffsets)(struct lawnmower_LawnMower_struct* self);
	bool (* _isSelected_254)(struct lawnmower_LawnMower_struct* self);
	void (* onClick)(struct lawnmower_LawnMower_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct lawnmower_LawnMower_struct* self, int x, int y);
	void (* _findPath_673)(struct lawnmower_LawnMower_struct* self, int to_x, int to_y);
	bool (* clicked)(struct lawnmower_LawnMower_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct lawnmower_LawnMower_struct* self);
	void (* moveUp)(struct lawnmower_LawnMower_struct* self);
	void (* moveDown)(struct lawnmower_LawnMower_struct* self);
	void (* moveLeft)(struct lawnmower_LawnMower_struct* self);
	void (* moveRight)(struct lawnmower_LawnMower_struct* self);
	void (* _stop_925)(struct lawnmower_LawnMower_struct* self);
	void (* draw)(struct lawnmower_LawnMower_struct* self);
	bool (* addItem)(struct lawnmower_LawnMower_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct lawnmower_LawnMower_struct* self);
	void (* setCoordinates)(struct lawnmower_LawnMower_struct* self, int i, int j);
	void (* updatePosition)(struct lawnmower_LawnMower_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct lawnmower_LawnMower_struct* self, long* info);
	void (* setInfoFromSave)(struct lawnmower_LawnMower_struct* self, long* info);
	void (* cleanUp)(struct lawnmower_LawnMower_struct* self);
	void (* waitAnimEnd)(struct lawnmower_LawnMower_struct* self);
	char** (* getInfo)(struct lawnmower_LawnMower_struct* self);
	void (* drawHelpSprite)(struct lawnmower_LawnMower_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct lawnmower_LawnMower_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct lawnmower_LawnMower_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct lawnmower_LawnMower_struct* self);
	int (to_i_386);
	int (to_j_12);
	void (* _destroyMapNode_226)(struct lawnmower_LawnMower_struct* self, int i, int j);
	map_MapObject_struct __vtableiface0__;
} lawnmower_LawnMower_struct;
typedef lawnmower_LawnMower_struct* lawnmower_LawnMower;
extern const class_id lawnmower_LawnMower__classid__;
extern lawnmower_LawnMower lawnmower_LawnMower_create();
extern void lawnmower_LawnMower_init(lawnmower_LawnMower self);
extern void lawnmower_LawnMower_initsystem(lawnmower_LawnMower self);
extern void lawnmower_LawnMower_inituser(lawnmower_LawnMower self);
extern cbcstd_Object lawnmower_LawnMower_getvtable(lawnmower_LawnMower self, class_id id);
extern map_MapObject lawnmower_LawnMower_create_map_MapObject();
extern void lawnmower_LawnMower_init_map_MapObject(map_MapObject self, lawnmower_LawnMower __self__);
extern void lawnmower_LawnMower__findPath_673(lawnmower_LawnMower self, int to_x, int to_y);
extern void lawnmower_LawnMower_interact(lawnmower_LawnMower self);
extern void lawnmower_LawnMower__stop_925(lawnmower_LawnMower self);
extern void lawnmower_LawnMower__destroyMapNode_226(lawnmower_LawnMower self, int i, int j);
extern void lawnmower_LawnMower_onClick(lawnmower_LawnMower self, int x, int y);
extern char** lawnmower_LawnMower_getInfo(lawnmower_LawnMower self);
extern void lawnmower_LawnMower__fillHelpRect_284(lawnmower_LawnMower self, SDL_Rect* rect);
extern char* lawnmower_LawnMower_getHelpName(lawnmower_LawnMower self);
extern void lawnmower_LawnMower_enduser(lawnmower_LawnMower self);
extern void lawnmower_LawnMower_end(lawnmower_LawnMower self);
extern void lawnmower_LawnMower_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
