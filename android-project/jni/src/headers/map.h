#ifndef MAP_H
#define MAP_H


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
// difficulty imports
#include <difficulty.h>
//
// screen imports
#include <screen.h>
//
// public globals
#include "SDL2/SDL.h"
#include <time.h>
#include "config.h"






typedef struct map_MapObject_struct{
	void (* draw)(struct map_MapObject_struct* self);
	void (* onClick)(struct map_MapObject_struct* self, int x, int y);
	void (* interact)(struct map_MapObject_struct* self);
	void (* setCoordinates)(struct map_MapObject_struct* self, int i, int j);
	void (* updatePosition)(struct map_MapObject_struct* self, int* i, int* j);
	void (* cleanUp)(struct map_MapObject_struct* self);
	void (* waitAnimEnd)(struct map_MapObject_struct* self);
	void (* getSaveInfo)(struct map_MapObject_struct* self, long* info);
	void (* setInfoFromSave)(struct map_MapObject_struct* self, long* info);
	char** (* getInfo)(struct map_MapObject_struct* self);
	void (* drawHelpSprite)(struct map_MapObject_struct* self, int x, int y);
	char* (* getHelpName)(struct map_MapObject_struct* self);
} map_MapObject_struct;
typedef map_MapObject_struct* map_MapObject;
extern const class_id map_MapObject__classid__;
extern void map_MapObject_draw(map_MapObject self);
extern void map_MapObject_onClick(map_MapObject self, int x, int y);
extern void map_MapObject_interact(map_MapObject self);
extern void map_MapObject_setCoordinates(map_MapObject self, int i, int j);
extern void map_MapObject_updatePosition(map_MapObject self, int* i, int* j);
extern void map_MapObject_cleanUp(map_MapObject self);
extern void map_MapObject_waitAnimEnd(map_MapObject self);
extern void map_MapObject_getSaveInfo(map_MapObject self, long* info);
extern void map_MapObject_setInfoFromSave(map_MapObject self, long* info);
extern char** map_MapObject_getInfo(map_MapObject self);
extern void map_MapObject_drawHelpSprite(map_MapObject self, int x, int y);
extern char* map_MapObject_getHelpName(map_MapObject self);
extern void map_MapObject_enduser(map_MapObject self);
extern void map_MapObject_end(map_MapObject self);

typedef struct map_MapNode{
	cbcstd_List objects;
	map_MapObject bg;
} map_MapNode;
extern void map_MapNode_enduser(map_MapNode self);
extern void map_MapNode_end(map_MapNode self);

extern cbcstd_List map_removed_objects;

extern cbcstd_Semaphore map_map_mutex;

extern int map_last_x;

extern int map_last_y;

extern image_Image map_loading_img;

extern image_Image map_selected_img;

extern image_Image map_help_box;

extern void map_addBg(int i, int j, map_MapObject bg);

extern void map_cleanArea(int i, int j);

extern void map_emptyMap();

extern void map_emptyMinefield();

extern void map_init();

extern void map_drawBackground();

extern void map_draw();

extern bool map_outOfBounds(int x, int y, int w, int h);

extern bool map_fullOutOfBounds(int x, int y);

extern bool map_inLimitNorth(int y, int h);

extern bool map_inLimitSouth(int y, int h);

extern bool map_inLimitEast(int x, int w);

extern bool map_inLimitWest(int x, int w);

extern void map_insertObject(cbcstd_Object o, int i, int j);

extern void map_removeObject(cbcstd_Object o, int i, int j);

extern map_MapNode* map_getNode(int i, int j);

extern map_MapNode* map_getNorthNode(int i, int j);

extern map_MapNode* map_getSouthNode(int i, int j);

extern map_MapNode* map_getEastNode(int i, int j);

extern map_MapNode* map_getWestNode(int i, int j);

extern bool map_clickedOn(int x, int y, int w, int h);

extern bool map_clickedAround(int x, int y);

extern void map_onClick(int x, int y);

extern void map_destroyMap();

extern void map_waitAnimEnd();




#ifdef __cplusplus
};
#endif


#endif//
