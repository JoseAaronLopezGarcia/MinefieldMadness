#ifndef MISSIL_H
#define MISSIL_H


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
// pathfinder imports
#include <pathfinder.h>
//
// sound imports
#include <sound.h>
//
// public globals







extern image_Image missil_missil_img;

extern const int missil_CHAR_WIDTH;

extern const int missil_CHAR_HEIGHT;

extern int missil_ANIM_STATES[3];

extern const int missil_LEFT_Y;

extern const int missil_UP_Y;

extern const int missil_RIGHT_Y;

extern const int missil_DOWN_Y;

typedef struct missil_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct missil_Sprites_struct* self);
	void* (* __getvtable__)(struct missil_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct missil_Sprites_struct* self, struct missil_Sprites_struct* other);
	struct missil_Sprites_struct* (* __operate__)(struct missil_Sprites_struct* self, struct missil_Sprites_struct* other);
	void* (* __str__)(struct missil_Sprites_struct* self);
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
	bool (* clicked)(struct missil_Sprites_struct* self);
	void (* animStart)(struct missil_Sprites_struct* self, int pos);
	void (* animEnd)(struct missil_Sprites_struct* self);
	void (* _stopAnim_681)(struct missil_Sprites_struct* self);
	void (* _walk_443)(struct missil_Sprites_struct* self);
	void (* draw)(struct missil_Sprites_struct* self, int x, int y, int w, int h);
} missil_Sprites_struct;
typedef missil_Sprites_struct* missil_Sprites;
extern const class_id missil_Sprites__classid__;
extern missil_Sprites missil_Sprites_create();
extern void missil_Sprites_init(missil_Sprites self);
extern void missil_Sprites_initsystem(missil_Sprites self);
extern void missil_Sprites_inituser(missil_Sprites self);
extern void missil_Sprites_draw(missil_Sprites self, int x, int y, int w, int h);
extern void missil_Sprites_enduser(missil_Sprites self);
extern void missil_Sprites_end(missil_Sprites self);

typedef struct missil_Missil_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct missil_Missil_struct* self);
	void* (* __getvtable__)(struct missil_Missil_struct* self, class_id id);
	int (* __cmp__)(struct missil_Missil_struct* self, struct missil_Missil_struct* other);
	struct missil_Missil_struct* (* __operate__)(struct missil_Missil_struct* self, struct missil_Missil_struct* other);
	void* (* __str__)(struct missil_Missil_struct* self);
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
	void (* calcOffsets)(struct missil_Missil_struct* self);
	bool (* _isSelected_254)(struct missil_Missil_struct* self);
	void (* onClick)(struct missil_Missil_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct missil_Missil_struct* self, int x, int y);
	void (* _findPath_673)(struct missil_Missil_struct* self, int to_x, int to_y);
	bool (* clicked)(struct missil_Missil_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct missil_Missil_struct* self);
	void (* moveUp)(struct missil_Missil_struct* self);
	void (* moveDown)(struct missil_Missil_struct* self);
	void (* moveLeft)(struct missil_Missil_struct* self);
	void (* moveRight)(struct missil_Missil_struct* self);
	void (* _stop_925)(struct missil_Missil_struct* self);
	void (* draw)(struct missil_Missil_struct* self);
	bool (* addItem)(struct missil_Missil_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct missil_Missil_struct* self);
	void (* setCoordinates)(struct missil_Missil_struct* self, int i, int j);
	void (* updatePosition)(struct missil_Missil_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct missil_Missil_struct* self, long* info);
	void (* setInfoFromSave)(struct missil_Missil_struct* self, long* info);
	void (* cleanUp)(struct missil_Missil_struct* self);
	void (* waitAnimEnd)(struct missil_Missil_struct* self);
	char** (* getInfo)(struct missil_Missil_struct* self);
	void (* drawHelpSprite)(struct missil_Missil_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct missil_Missil_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct missil_Missil_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct missil_Missil_struct* self);
	int (to_i_106);
	int (to_j_841);
	void (* _destroyMapNode_483)(struct missil_Missil_struct* self, int i, int j);
	bool (* hasColided)(struct missil_Missil_struct* self);
	map_MapObject_struct __vtableiface0__;
} missil_Missil_struct;
typedef missil_Missil_struct* missil_Missil;
extern const class_id missil_Missil__classid__;
extern missil_Missil missil_Missil_create();
extern void missil_Missil_init(missil_Missil self);
extern void missil_Missil_initsystem(missil_Missil self);
extern void missil_Missil_inituser(missil_Missil self);
extern cbcstd_Object missil_Missil_getvtable(missil_Missil self, class_id id);
extern map_MapObject missil_Missil_create_map_MapObject();
extern void missil_Missil_init_map_MapObject(map_MapObject self, missil_Missil __self__);
extern bool missil_Missil__canGoThere_896(missil_Missil self, int x, int y);
extern void missil_Missil__findPath_673(missil_Missil self, int to_x, int to_y);
extern void missil_Missil_interact(missil_Missil self);
extern void missil_Missil__destroyMapNode_483(missil_Missil self, int i, int j);
extern void missil_Missil__stop_925(missil_Missil self);
extern bool missil_Missil_hasColided(missil_Missil self);
extern void missil_Missil_onClick(missil_Missil self, int x, int y);
extern char** missil_Missil_getInfo(missil_Missil self);
extern void missil_Missil__fillHelpRect_284(missil_Missil self, SDL_Rect* rect);
extern char* missil_Missil_getHelpName(missil_Missil self);
extern void missil_Missil_enduser(missil_Missil self);
extern void missil_Missil_end(missil_Missil self);
extern void missil_Missil_end_map_MapObject(map_MapObject self);

extern void missil_init();




#ifdef __cplusplus
};
#endif


#endif//
