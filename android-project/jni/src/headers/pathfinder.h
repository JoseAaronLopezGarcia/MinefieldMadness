#ifndef PATHFINDER_H
#define PATHFINDER_H


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
// astar imports
#include <astar.h>
//
// common imports
#include <common.h>
//
// public globals




typedef enum{
	pathfinder_DOWN,
	pathfinder_UP,
	pathfinder_LEFT,
	pathfinder_RIGHT,
	pathfinder_NO_ANIM,
};






typedef struct pathfinder_Node_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct pathfinder_Node_struct* self);
	void* (* __getvtable__)(struct pathfinder_Node_struct* self, class_id id);
	int (* __cmp__)(struct pathfinder_Node_struct* self, struct pathfinder_Node_struct* other);
	struct pathfinder_Node_struct* (* __operate__)(struct pathfinder_Node_struct* self, struct pathfinder_Node_struct* other);
	void* (* __str__)(struct pathfinder_Node_struct* self);
	int i_708;
	int j_906;
	int value_118;
	int distance_969;
	struct pathfinder_Node_struct* parent_169;
	int move_422;
	struct pathfinder_Node_struct* (* getParent)(struct pathfinder_Node_struct* self);
	void (* setParent)(struct pathfinder_Node_struct* self, astar_Node parent);
	cbcstd_List (* getChildren)(struct pathfinder_Node_struct* self);
	int (* getValue)(struct pathfinder_Node_struct* self);
	void (* setValue)(struct pathfinder_Node_struct* self, int value);
	int (* getDistance)(struct pathfinder_Node_struct* self);
	void (* setDistance)(struct pathfinder_Node_struct* self, int distance);
	int (* getDistanceFromParent)(struct pathfinder_Node_struct* self);
	bool (* equals)(struct pathfinder_Node_struct* self, astar_Node other);
	astar_Node_struct __vtableiface0__;
} pathfinder_Node_struct;
typedef pathfinder_Node_struct* pathfinder_Node;
extern const class_id pathfinder_Node__classid__;
extern pathfinder_Node pathfinder_Node_create(int i, int j);
extern void pathfinder_Node_init(pathfinder_Node self, int i, int j);
extern void pathfinder_Node_initsystem(pathfinder_Node self);
extern void pathfinder_Node_inituser(pathfinder_Node self, int i, int j);
extern cbcstd_Object pathfinder_Node_getvtable(pathfinder_Node self, class_id id);
extern astar_Node pathfinder_Node_create_astar_Node(int i, int j);
extern void pathfinder_Node_init_astar_Node(astar_Node self, pathfinder_Node __self__);
extern pathfinder_Node pathfinder_Node_getParent(pathfinder_Node self);
extern void pathfinder_Node_setParent(pathfinder_Node self, astar_Node parent);
extern cbcstd_List pathfinder_Node_getChildren(pathfinder_Node self);
extern int pathfinder_Node_getValue(pathfinder_Node self);
extern void pathfinder_Node_setValue(pathfinder_Node self, int value);
extern int pathfinder_Node_getDistance(pathfinder_Node self);
extern void pathfinder_Node_setDistance(pathfinder_Node self, int distance);
extern int pathfinder_Node_getDistanceFromParent(pathfinder_Node self);
extern bool pathfinder_Node_equals(pathfinder_Node self, astar_Node other);
extern void pathfinder_Node_enduser(pathfinder_Node self);
extern void pathfinder_Node_end(pathfinder_Node self);
extern void pathfinder_Node_end_astar_Node(astar_Node self);

extern int pathfinder_heuristicFunction(astar_AlgoData* data, astar_Node node);

extern bool pathfinder_canGoThere(int i, int j);

extern void pathfinder_findPath(int src_x, int src_y, int dst_x, int dst_y, cbcstd_List movements);


extern void pathfinder_init();

#ifdef __cplusplus
};
#endif


#endif//
