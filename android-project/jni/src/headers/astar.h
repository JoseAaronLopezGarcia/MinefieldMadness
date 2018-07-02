#ifndef ASTAR_H
#define ASTAR_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
typedef struct astar_Node_struct{
	struct astar_Node_struct* (* getParent)(struct astar_Node_struct* self);
	void (* setParent)(struct astar_Node_struct* self, struct astar_Node_struct* parent);
	cbcstd_List (* getChildren)(struct astar_Node_struct* self);
	int (* getValue)(struct astar_Node_struct* self);
	void (* setValue)(struct astar_Node_struct* self, int value);
	int (* getDistance)(struct astar_Node_struct* self);
	void (* setDistance)(struct astar_Node_struct* self, int distance);
	int (* getDistanceFromParent)(struct astar_Node_struct* self);
	bool (* equals)(struct astar_Node_struct* self, struct astar_Node_struct* other);
} astar_Node_struct;
typedef astar_Node_struct* astar_Node;
extern const class_id astar_Node__classid__;
extern astar_Node astar_Node_getParent(astar_Node self);
extern void astar_Node_setParent(astar_Node self, astar_Node parent);
extern cbcstd_List astar_Node_getChildren(astar_Node self);
extern int astar_Node_getValue(astar_Node self);
extern void astar_Node_setValue(astar_Node self, int value);
extern int astar_Node_getDistance(astar_Node self);
extern void astar_Node_setDistance(astar_Node self, int distance);
extern int astar_Node_getDistanceFromParent(astar_Node self);
extern bool astar_Node_equals(astar_Node self, astar_Node other);
extern void astar_Node_enduser(astar_Node self);
extern void astar_Node_end(astar_Node self);

typedef struct astar_AlgoData{
	astar_Node root;
	astar_Node goal;
	int (*heuristicFunction)(struct astar_AlgoData* data, astar_Node node);
	cbcstd_Array path;
	cbcstd_List open_nodes;
	cbcstd_List closed_nodes;
} astar_AlgoData;
extern void astar_AlgoData_enduser(astar_AlgoData self);
extern void astar_AlgoData_end(astar_AlgoData self);

extern void astar_AStarAlgorithm(astar_AlgoData* data);

extern void astar_cleanUpData(astar_AlgoData* data, bool full_cleanup);



extern void astar_init();

#ifdef __cplusplus
};
#endif


#endif//
