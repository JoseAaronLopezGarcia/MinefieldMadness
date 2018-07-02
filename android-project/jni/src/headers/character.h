#ifndef CHARACTER_H
#define CHARACTER_H


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





extern const int character_DOWN_Y;

extern const int character_UP_Y;

extern const int character_LEFT_Y;

extern const int character_RIGHT_Y;

extern int character_ANIM_STATES[3];

extern const int character_CHAR_WIDTH;

extern const int character_CHAR_HEIGHT;

extern const int character_MAX_POS;

extern const int character_MAX_WALK_ANIM;

extern const int character_WALK_SPEED;

extern void* character_selected_character;

extern cbcstd_Semaphore character_selection_sema;

extern int character_n_characters;

extern void* character_safe_character;

extern cbcstd_Semaphore character_characters_sema;

extern void character_init();

extern void character_reinit();

typedef struct character_Sprites_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct character_Sprites_struct* self);
	void* (* __getvtable__)(struct character_Sprites_struct* self, class_id id);
	int (* __cmp__)(struct character_Sprites_struct* self, struct character_Sprites_struct* other);
	struct character_Sprites_struct* (* __operate__)(struct character_Sprites_struct* self, struct character_Sprites_struct* other);
	void* (* __str__)(struct character_Sprites_struct* self);
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
	bool (* clicked)(struct character_Sprites_struct* self);
	void (* animStart)(struct character_Sprites_struct* self, int pos);
	void (* animEnd)(struct character_Sprites_struct* self);
	void (* _stopAnim_681)(struct character_Sprites_struct* self);
	void (* _walk_443)(struct character_Sprites_struct* self);
	void (* draw)(struct character_Sprites_struct* self, int x, int y, int w, int h);
} character_Sprites_struct;
typedef character_Sprites_struct* character_Sprites;
extern const class_id character_Sprites__classid__;
extern character_Sprites character_Sprites_create();
extern void character_Sprites_init(character_Sprites self);
extern void character_Sprites_initsystem(character_Sprites self);
extern void character_Sprites_inituser(character_Sprites self);
extern bool character_Sprites_clicked(character_Sprites self);
extern void character_Sprites_animStart(character_Sprites self, int pos);
extern void character_Sprites_animEnd(character_Sprites self);
extern void character_Sprites__stopAnim_681(character_Sprites self);
extern void character_Sprites__walk_443(character_Sprites self);
extern void character_Sprites_draw(character_Sprites self, int x, int y, int w, int h);
extern void character_Sprites_enduser(character_Sprites self);
extern void character_Sprites_end(character_Sprites self);

typedef struct character_Character_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct character_Character_struct* self);
	void* (* __getvtable__)(struct character_Character_struct* self, class_id id);
	int (* __cmp__)(struct character_Character_struct* self, struct character_Character_struct* other);
	struct character_Character_struct* (* __operate__)(struct character_Character_struct* self, struct character_Character_struct* other);
	void* (* __str__)(struct character_Character_struct* self);
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
	void (* calcOffsets)(struct character_Character_struct* self);
	bool (* _isSelected_254)(struct character_Character_struct* self);
	void (* onClick)(struct character_Character_struct* self, int x, int y);
	bool (* _canGoThere_896)(struct character_Character_struct* self, int x, int y);
	void (* _findPath_673)(struct character_Character_struct* self, int to_x, int to_y);
	bool (* clicked)(struct character_Character_struct* self, int x, int y);
	void (* _resetAnimState_866)(struct character_Character_struct* self);
	void (* moveUp)(struct character_Character_struct* self);
	void (* moveDown)(struct character_Character_struct* self);
	void (* moveLeft)(struct character_Character_struct* self);
	void (* moveRight)(struct character_Character_struct* self);
	void (* _stop_925)(struct character_Character_struct* self);
	void (* draw)(struct character_Character_struct* self);
	bool (* addItem)(struct character_Character_struct* self, cbcstd_List source_list, map_MapObject o);
	void (* interact)(struct character_Character_struct* self);
	void (* setCoordinates)(struct character_Character_struct* self, int i, int j);
	void (* updatePosition)(struct character_Character_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct character_Character_struct* self, long* info);
	void (* setInfoFromSave)(struct character_Character_struct* self, long* info);
	void (* cleanUp)(struct character_Character_struct* self);
	void (* waitAnimEnd)(struct character_Character_struct* self);
	char** (* getInfo)(struct character_Character_struct* self);
	void (* drawHelpSprite)(struct character_Character_struct* self, int x, int y);
	void (* _fillHelpRect_284)(struct character_Character_struct* self, SDL_Rect* rect);
	void (* _drawHelpSprite_463)(struct character_Character_struct* self, int x, int y, SDL_Rect* rect);
	char* (* getHelpName)(struct character_Character_struct* self);
	map_MapObject_struct __vtableiface0__;
} character_Character_struct;
typedef character_Character_struct* character_Character;
extern const class_id character_Character__classid__;
extern character_Character character_Character_create();
extern void character_Character_init(character_Character self);
extern void character_Character_initsystem(character_Character self);
extern void character_Character_inituser(character_Character self);
extern cbcstd_Object character_Character_getvtable(character_Character self, class_id id);
extern map_MapObject character_Character_create_map_MapObject();
extern void character_Character_init_map_MapObject(map_MapObject self, character_Character __self__);
extern void character_Character_calcOffsets(character_Character self);
extern bool character_Character__isSelected_254(character_Character self);
extern void character_Character_onClick(character_Character self, int x, int y);
extern bool character_Character__canGoThere_896(character_Character self, int x, int y);
extern void character_Character__findPath_673(character_Character self, int to_x, int to_y);
extern bool character_Character_clicked(character_Character self, int x, int y);
extern void character_Character__resetAnimState_866(character_Character self);
extern void character_Character_moveUp(character_Character self);
extern void character_Character_moveDown(character_Character self);
extern void character_Character_moveLeft(character_Character self);
extern void character_Character_moveRight(character_Character self);
extern void character_Character__stop_925(character_Character self);
extern void character_Character_draw(character_Character self);
extern bool character_Character_addItem(character_Character self, cbcstd_List source_list, map_MapObject o);
extern void character_Character_interact(character_Character self);
extern void character_Character_setCoordinates(character_Character self, int i, int j);
extern void character_Character_updatePosition(character_Character self, int* i, int* j);
extern void character_Character_getSaveInfo(character_Character self, long* info);
extern void character_Character_setInfoFromSave(character_Character self, long* info);
extern void character_Character_cleanUp(character_Character self);
extern void character_Character_waitAnimEnd(character_Character self);
extern char** character_Character_getInfo(character_Character self);
extern void character_Character_drawHelpSprite(character_Character self, int x, int y);
extern void character_Character__fillHelpRect_284(character_Character self, SDL_Rect* rect);
extern void character_Character__drawHelpSprite_463(character_Character self, int x, int y, SDL_Rect* rect);
extern char* character_Character_getHelpName(character_Character self);
extern void character_Character_enduser(character_Character self);
extern void character_Character_end(character_Character self);
extern void character_Character_end_map_MapObject(map_MapObject self);




#ifdef __cplusplus
};
#endif


#endif//
