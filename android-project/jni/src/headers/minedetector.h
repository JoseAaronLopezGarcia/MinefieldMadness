#ifndef MINEDETECTOR_H
#define MINEDETECTOR_H


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
// public globals






extern image_Image minedetector_minedetector_img;

extern void minedetector_init();

typedef struct minedetector_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct minedetector_Sprites_struct* self);
	void* (* __getvtable__)(struct minedetector_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct minedetector_Sprites_struct* self, struct minedetector_Sprites_struct* other);
	struct minedetector_Sprites_struct* (* __operate__)(struct minedetector_Sprites_struct* self, struct minedetector_Sprites_struct* other);
	void* (* __str__)(struct minedetector_Sprites_struct* self);
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
	bool (* clicked)(struct minedetector_Sprites_struct* self);
	void (* animStart)(struct minedetector_Sprites_struct* self, int pos);
	void (* animEnd)(struct minedetector_Sprites_struct* self);
	void (* _stopAnim_681)(struct minedetector_Sprites_struct* self);
	void (* _walk_443)(struct minedetector_Sprites_struct* self);
	void (* draw)(struct minedetector_Sprites_struct* self, int x, int y, int w, int h);
} minedetector_Sprites_struct;
typedef minedetector_Sprites_struct* minedetector_Sprites;
extern const class_id minedetector_Sprites__classid__;
extern minedetector_Sprites minedetector_Sprites_create();
extern void minedetector_Sprites_init(minedetector_Sprites self);
extern void minedetector_Sprites_initsystem(minedetector_Sprites self);
extern void minedetector_Sprites_inituser(minedetector_Sprites self);
extern void minedetector_Sprites__walk_443(minedetector_Sprites self);
extern void minedetector_Sprites_draw(minedetector_Sprites self, int x, int y, int w, int h);
extern void minedetector_Sprites_enduser(minedetector_Sprites self);
extern void minedetector_Sprites_end(minedetector_Sprites self);

typedef struct minedetector_MineDetector_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct minedetector_MineDetector_struct* self);
	void* (* __getvtable__)(struct minedetector_MineDetector_struct* self, class_id id);
	int (* __cmp__)(struct minedetector_MineDetector_struct* self, struct minedetector_MineDetector_struct* other);
	struct minedetector_MineDetector_struct* (* __operate__)(struct minedetector_MineDetector_struct* self, struct minedetector_MineDetector_struct* other);
	void* (* __str__)(struct minedetector_MineDetector_struct* self);
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
	void (* calcOffsets)(struct minedetector_MineDetector_struct* self);
	bool (* _isSelected_254)(struct minedetector_MineDetector_struct* self);
	void (* onClick)(struct minedetector_MineDetector_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct minedetector_MineDetector_struct* self, int x, int y);
	void (* _findPath_673)(struct minedetector_MineDetector_struct* self, int to_x, int to_y);
	bool (* clicked)(struct minedetector_MineDetector_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct minedetector_MineDetector_struct* self);
	void (* moveUp)(struct minedetector_MineDetector_struct* self);
	void (* moveDown)(struct minedetector_MineDetector_struct* self);
	void (* moveLeft)(struct minedetector_MineDetector_struct* self);
	void (* moveRight)(struct minedetector_MineDetector_struct* self);
	void (* _stop_925)(struct minedetector_MineDetector_struct* self);
	void (* draw)(struct minedetector_MineDetector_struct* self);
	bool (* addItem)(struct minedetector_MineDetector_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct minedetector_MineDetector_struct* self);
	void (* setCoordinates)(struct minedetector_MineDetector_struct* self, int i, int j);
	void (* updatePosition)(struct minedetector_MineDetector_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct minedetector_MineDetector_struct* self, long* info);
	void (* setInfoFromSave)(struct minedetector_MineDetector_struct* self, long* info);
	void (* cleanUp)(struct minedetector_MineDetector_struct* self);
	void (* waitAnimEnd)(struct minedetector_MineDetector_struct* self);
	char** (* getInfo)(struct minedetector_MineDetector_struct* self);
	void (* drawHelpSprite)(struct minedetector_MineDetector_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct minedetector_MineDetector_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct minedetector_MineDetector_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct minedetector_MineDetector_struct* self);
	character_Character (to_transport_606);
	teleporter_MapNode_Data map_nodes_713[24];
	int (available_nodes_669);
	void (* _fillMapNodes_531)(struct minedetector_MineDetector_struct* self, int i, int j);
	void (* _setMapNode_448)(struct minedetector_MineDetector_struct* self, floor_Floor f);
	void (* _restoreMapNodes_185)(struct minedetector_MineDetector_struct* self);
	void (* restoreMap)(struct minedetector_MineDetector_struct* self);
	bool (* _inRange_8)(struct minedetector_MineDetector_struct* self, int x, int y);
	map_MapObject_struct __vtableiface0__;
} minedetector_MineDetector_struct;
typedef minedetector_MineDetector_struct* minedetector_MineDetector;
extern const class_id minedetector_MineDetector__classid__;
extern minedetector_MineDetector minedetector_MineDetector_create();
extern void minedetector_MineDetector_init(minedetector_MineDetector self);
extern void minedetector_MineDetector_initsystem(minedetector_MineDetector self);
extern void minedetector_MineDetector_inituser(minedetector_MineDetector self);
extern cbcstd_Object minedetector_MineDetector_getvtable(minedetector_MineDetector self, class_id id);
extern map_MapObject minedetector_MineDetector_create_map_MapObject();
extern void minedetector_MineDetector_init_map_MapObject(map_MapObject self, minedetector_MineDetector __self__);
extern void minedetector_MineDetector__setMapNode_448(minedetector_MineDetector self, floor_Floor f);
extern void minedetector_MineDetector__fillMapNodes_531(minedetector_MineDetector self, int i, int j);
extern void minedetector_MineDetector__restoreMapNodes_185(minedetector_MineDetector self);
extern bool minedetector_MineDetector__inRange_8(minedetector_MineDetector self, int x, int y);
extern char** minedetector_MineDetector_getInfo(minedetector_MineDetector self);
extern void minedetector_MineDetector__fillHelpRect_284(minedetector_MineDetector self, SDL_Rect* rect);
extern char* minedetector_MineDetector_getHelpName(minedetector_MineDetector self);
extern void minedetector_MineDetector_enduser(minedetector_MineDetector self);
extern void minedetector_MineDetector_end(minedetector_MineDetector self);
extern void minedetector_MineDetector_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
