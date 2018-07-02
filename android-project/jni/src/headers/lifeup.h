#ifndef LIFEUP_H
#define LIFEUP_H


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






extern image_Image lifeup_lifeup_img;

extern void lifeup_init();

typedef struct lifeup_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct lifeup_Sprites_struct* self);
	void* (* __getvtable__)(struct lifeup_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct lifeup_Sprites_struct* self, struct lifeup_Sprites_struct* other);
	struct lifeup_Sprites_struct* (* __operate__)(struct lifeup_Sprites_struct* self, struct lifeup_Sprites_struct* other);
	void* (* __str__)(struct lifeup_Sprites_struct* self);
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
	bool (* clicked)(struct lifeup_Sprites_struct* self);
	void (* animStart)(struct lifeup_Sprites_struct* self, int pos);
	void (* animEnd)(struct lifeup_Sprites_struct* self);
	void (* _stopAnim_681)(struct lifeup_Sprites_struct* self);
	void (* _walk_443)(struct lifeup_Sprites_struct* self);
	void (* draw)(struct lifeup_Sprites_struct* self, int x, int y, int w, int h);
} lifeup_Sprites_struct;
typedef lifeup_Sprites_struct* lifeup_Sprites;
extern const class_id lifeup_Sprites__classid__;
extern lifeup_Sprites lifeup_Sprites_create();
extern void lifeup_Sprites_init(lifeup_Sprites self);
extern void lifeup_Sprites_initsystem(lifeup_Sprites self);
extern void lifeup_Sprites_inituser(lifeup_Sprites self);
extern void lifeup_Sprites__walk_443(lifeup_Sprites self);
extern void lifeup_Sprites_draw(lifeup_Sprites self, int x, int y, int w, int h);
extern void lifeup_Sprites_enduser(lifeup_Sprites self);
extern void lifeup_Sprites_end(lifeup_Sprites self);

typedef struct lifeup_LifeUp_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct lifeup_LifeUp_struct* self);
	void* (* __getvtable__)(struct lifeup_LifeUp_struct* self, class_id id);
	int (* __cmp__)(struct lifeup_LifeUp_struct* self, struct lifeup_LifeUp_struct* other);
	struct lifeup_LifeUp_struct* (* __operate__)(struct lifeup_LifeUp_struct* self, struct lifeup_LifeUp_struct* other);
	void* (* __str__)(struct lifeup_LifeUp_struct* self);
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
	void (* calcOffsets)(struct lifeup_LifeUp_struct* self);
	bool (* _isSelected_254)(struct lifeup_LifeUp_struct* self);
	void (* onClick)(struct lifeup_LifeUp_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct lifeup_LifeUp_struct* self, int x, int y);
	void (* _findPath_673)(struct lifeup_LifeUp_struct* self, int to_x, int to_y);
	bool (* clicked)(struct lifeup_LifeUp_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct lifeup_LifeUp_struct* self);
	void (* moveUp)(struct lifeup_LifeUp_struct* self);
	void (* moveDown)(struct lifeup_LifeUp_struct* self);
	void (* moveLeft)(struct lifeup_LifeUp_struct* self);
	void (* moveRight)(struct lifeup_LifeUp_struct* self);
	void (* _stop_925)(struct lifeup_LifeUp_struct* self);
	void (* draw)(struct lifeup_LifeUp_struct* self);
	bool (* addItem)(struct lifeup_LifeUp_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct lifeup_LifeUp_struct* self);
	void (* setCoordinates)(struct lifeup_LifeUp_struct* self, int i, int j);
	void (* updatePosition)(struct lifeup_LifeUp_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct lifeup_LifeUp_struct* self, long* info);
	void (* setInfoFromSave)(struct lifeup_LifeUp_struct* self, long* info);
	void (* cleanUp)(struct lifeup_LifeUp_struct* self);
	void (* waitAnimEnd)(struct lifeup_LifeUp_struct* self);
	char** (* getInfo)(struct lifeup_LifeUp_struct* self);
	void (* drawHelpSprite)(struct lifeup_LifeUp_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct lifeup_LifeUp_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct lifeup_LifeUp_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct lifeup_LifeUp_struct* self);
	character_Character (to_transport_606);
	teleporter_MapNode_Data map_nodes_713[24];
	int (available_nodes_669);
	void (* _fillMapNodes_531)(struct lifeup_LifeUp_struct* self, int i, int j);
	void (* _setMapNode_448)(struct lifeup_LifeUp_struct* self, floor_Floor f);
	void (* _restoreMapNodes_185)(struct lifeup_LifeUp_struct* self);
	void (* restoreMap)(struct lifeup_LifeUp_struct* self);
	bool (* _inRange_8)(struct lifeup_LifeUp_struct* self, int x, int y);
	map_MapObject_struct __vtableiface0__;
} lifeup_LifeUp_struct;
typedef lifeup_LifeUp_struct* lifeup_LifeUp;
extern const class_id lifeup_LifeUp__classid__;
extern lifeup_LifeUp lifeup_LifeUp_create();
extern void lifeup_LifeUp_init(lifeup_LifeUp self);
extern void lifeup_LifeUp_initsystem(lifeup_LifeUp self);
extern void lifeup_LifeUp_inituser(lifeup_LifeUp self);
extern cbcstd_Object lifeup_LifeUp_getvtable(lifeup_LifeUp self, class_id id);
extern map_MapObject lifeup_LifeUp_create_map_MapObject();
extern void lifeup_LifeUp_init_map_MapObject(map_MapObject self, lifeup_LifeUp __self__);
extern void lifeup_LifeUp__setMapNode_448(lifeup_LifeUp self, floor_Floor f);
extern void lifeup_LifeUp__fillMapNodes_531(lifeup_LifeUp self, int i, int j);
extern void lifeup_LifeUp__restoreMapNodes_185(lifeup_LifeUp self);
extern bool lifeup_LifeUp__inRange_8(lifeup_LifeUp self, int x, int y);
extern char** lifeup_LifeUp_getInfo(lifeup_LifeUp self);
extern void lifeup_LifeUp__fillHelpRect_284(lifeup_LifeUp self, SDL_Rect* rect);
extern char* lifeup_LifeUp_getHelpName(lifeup_LifeUp self);
extern void lifeup_LifeUp_enduser(lifeup_LifeUp self);
extern void lifeup_LifeUp_end(lifeup_LifeUp self);
extern void lifeup_LifeUp_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
