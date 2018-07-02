#ifndef FLOOR_H
#define FLOOR_H


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
// font imports
#include <font.h>
//
// sound imports
#include <sound.h>
//
// map imports
#include <map.h>
//
// public globals





extern char* floor_terrain_name[11];

extern char* floor_terrain_help[11][7];

extern const int floor_FIRE_HEIGHT;

extern const int floor_FIRE_WIDTH;

extern const int floor_MAX_FIRE_ANIMS;

extern int floor_fire_offset_x;

extern int floor_fire_offset_y;

extern image_Image floor_fire_img;

extern image_Image* floor_floor_img;

extern sound_Sound floor_explosion_sound;

typedef enum floor_TerrainType{
	floor_NORMAL_NO_MINE_TYPE,
	floor_NORMAL_MINE_TYPE,
	floor_MINE_VISIBLE_TYPE,
	floor_DESERT_TYPE,
	floor_STONE_TYPE,
	floor_LAKE_TYPE,
	floor_TABLE_TYPE,
	floor_START_TYPE,
	floor_EXIT_TYPE,
	floor_TELEPORT_TYPE,
	floor_PAUSE_TYPE,
} floor_TerrainType;












typedef struct floor_Floor_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct floor_Floor_struct* self);
	void* (* __getvtable__)(struct floor_Floor_struct* self, class_id id);
	int (* __cmp__)(struct floor_Floor_struct* self, struct floor_Floor_struct* other);
	struct floor_Floor_struct* (* __operate__)(struct floor_Floor_struct* self, struct floor_Floor_struct* other);
	void* (* __str__)(struct floor_Floor_struct* self);
	int type_867;
	int i_163;
	int j_639;
	int fireAnim_68;
	int fireDelay_141;
	int floor_type_172;
	int items_649;
	font_Font item_text_504;
	void (* _checkItemText_549)(struct floor_Floor_struct* self);
	void (* draw)(struct floor_Floor_struct* self);
	void (* startFireAnim)(struct floor_Floor_struct* self);
	void (* onClick)(struct floor_Floor_struct* self, int x, int y);
	void (* interact)(struct floor_Floor_struct* self);
	void (* cleanUp)(struct floor_Floor_struct* self);
	void (* waitAnimEnd)(struct floor_Floor_struct* self);
	void (* setCoordinates)(struct floor_Floor_struct* self, int i, int j);
	void (* updatePosition)(struct floor_Floor_struct* self, int* i, int* j);
	void (* getSaveInfo)(struct floor_Floor_struct* self, long* info);
	void (* setInfoFromSave)(struct floor_Floor_struct* self, long* info);
	char** (* getInfo)(struct floor_Floor_struct* self);
	void (* drawHelpSprite)(struct floor_Floor_struct* self, int x, int y);
	char* (* getHelpName)(struct floor_Floor_struct* self);
	map_MapObject_struct __vtableiface0__;
} floor_Floor_struct;
typedef floor_Floor_struct* floor_Floor;
extern const class_id floor_Floor__classid__;
extern floor_Floor floor_Floor_create(int type, int i, int j);
extern void floor_Floor_init(floor_Floor self, int type, int i, int j);
extern void floor_Floor_initsystem(floor_Floor self);
extern void floor_Floor_inituser(floor_Floor self, int type, int i, int j);
extern cbcstd_Object floor_Floor_getvtable(floor_Floor self, class_id id);
extern map_MapObject floor_Floor_create_map_MapObject(int type, int i, int j);
extern void floor_Floor_init_map_MapObject(map_MapObject self, floor_Floor __self__);
extern void floor_Floor__checkItemText_549(floor_Floor self);
extern void floor_Floor_draw(floor_Floor self);
extern void floor_Floor_startFireAnim(floor_Floor self);
extern void floor_Floor_onClick(floor_Floor self, int x, int y);
extern void floor_Floor_interact(floor_Floor self);
extern void floor_Floor_cleanUp(floor_Floor self);
extern void floor_Floor_waitAnimEnd(floor_Floor self);
extern void floor_Floor_setCoordinates(floor_Floor self, int i, int j);
extern void floor_Floor_updatePosition(floor_Floor self, int* i, int* j);
extern void floor_Floor_getSaveInfo(floor_Floor self, long* info);
extern void floor_Floor_setInfoFromSave(floor_Floor self, long* info);
extern char** floor_Floor_getInfo(floor_Floor self);
extern void floor_Floor_drawHelpSprite(floor_Floor self, int x, int y);
extern char* floor_Floor_getHelpName(floor_Floor self);
extern void floor_Floor_enduser(floor_Floor self);
extern void floor_Floor_end(floor_Floor self);
extern void floor_Floor_end_map_MapObject(map_MapObject self);

extern void floor_init();



#ifdef __cplusplus
};
#endif


#endif//
