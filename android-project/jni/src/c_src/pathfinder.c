#include <cbc.h>
// public globals
#include <pathfinder.h>
// private globals
const class_id pathfinder_Node__classid__ = 235195128258300631;
//












pathfinder_Node pathfinder_Node_create(int i, int j){
	pathfinder_Node self = (pathfinder_Node)cbcstd_alloc(sizeof(pathfinder_Node_struct));
	try{
		pathfinder_Node_init(self, i, j);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void pathfinder_Node_init(pathfinder_Node self, int i, int j){
	pathfinder_Node_initsystem(self);
	pathfinder_Node_init_astar_Node((astar_Node)(&(self->__vtableiface0__)), self);
	pathfinder_Node_inituser(self, i, j);
}
void pathfinder_Node_initsystem(pathfinder_Node self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[4] = {
		235195128258300631L,
		-877637167666370448L,
		-7632195265922784466L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(pathfinder_Node_struct);
	self->__getvtable__ = (void*)(&pathfinder_Node_getvtable);
	self->getParent = &pathfinder_Node_getParent;
	self->setParent = &pathfinder_Node_setParent;
	self->getChildren = &pathfinder_Node_getChildren;
	self->getValue = &pathfinder_Node_getValue;
	self->setValue = &pathfinder_Node_setValue;
	self->getDistance = &pathfinder_Node_getDistance;
	self->setDistance = &pathfinder_Node_setDistance;
	self->getDistanceFromParent = &pathfinder_Node_getDistanceFromParent;
	self->equals = &pathfinder_Node_equals;
	self->__end__ = &pathfinder_Node_end;
}
void pathfinder_Node_enduser(pathfinder_Node self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void pathfinder_Node_end(pathfinder_Node self){
	pathfinder_Node_enduser(self);
	pathfinder_Node_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void pathfinder_Node_init_astar_Node(astar_Node self, pathfinder_Node __self__){
	self->getParent = (void*)(__self__->getParent);
	self->setParent = (void*)(__self__->setParent);
	self->getChildren = (void*)(__self__->getChildren);
	self->getValue = (void*)(__self__->getValue);
	self->setValue = (void*)(__self__->setValue);
	self->getDistance = (void*)(__self__->getDistance);
	self->setDistance = (void*)(__self__->setDistance);
	self->getDistanceFromParent = (void*)(__self__->getDistanceFromParent);
	self->equals = (void*)(__self__->equals);
}
cbcstd_Object pathfinder_Node_getvtable(pathfinder_Node self, class_id id){
	switch (id){
	case -7632195265922784466:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void pathfinder_Node_decrefs(pathfinder_Node self){
}







	
void pathfinder_Node_inituser(pathfinder_Node self, int i, int j){

	self->i_708 = i;

	self->j_906 = j;


}

pathfinder_Node pathfinder_Node_getParent(pathfinder_Node self){

	return self->parent_169;


}

void pathfinder_Node_setParent(pathfinder_Node self, astar_Node parent){
	if (parent == NULL){

		self->move_422 = pathfinder_NO_ANIM;
		return;
	}

	pathfinder_Node tmp_cast_oYOr = (pathfinder_Node)(parent);
	pathfinder_Node p = tmp_cast_oYOr;

	self->parent_169 = p;


	if (self->i_708 < p->i_708){

		self->move_422 = pathfinder_UP;
	}

	else{


	if (self->i_708 > p->i_708){

		self->move_422 = pathfinder_DOWN;
	}

	else{


	if (self->j_906 < p->j_906){

		self->move_422 = pathfinder_LEFT;
	}

	else{


	if (self->j_906 > p->j_906){

		self->move_422 = pathfinder_RIGHT;
	}

	else{

		self->move_422 = pathfinder_NO_ANIM;

	}

	}}}

}

cbcstd_List pathfinder_Node_getChildren(pathfinder_Node self){
	cbcstd_List ret = cbcstd_List_create();


	if (pathfinder_canGoThere(self->i_708, self->j_906-1)){



		ret->push(ret, pathfinder_Node_create(self->i_708, self->j_906-1));
	}



	if (pathfinder_canGoThere(self->i_708, self->j_906+1)){



		ret->push(ret, pathfinder_Node_create(self->i_708, self->j_906+1));
	}



	if (pathfinder_canGoThere(self->i_708-1, self->j_906)){



		ret->push(ret, pathfinder_Node_create(self->i_708-1, self->j_906));
	}



	if (pathfinder_canGoThere(self->i_708+1, self->j_906)){



		ret->push(ret, pathfinder_Node_create(self->i_708+1, self->j_906));
	}

	return ret;


}

int pathfinder_Node_getValue(pathfinder_Node self){

	return self->value_118;


}

void pathfinder_Node_setValue(pathfinder_Node self, int value){

	self->value_118 = value;


}

int pathfinder_Node_getDistance(pathfinder_Node self){

	return self->distance_969;


}

void pathfinder_Node_setDistance(pathfinder_Node self, int distance){

	self->distance_969 = distance;


}

int pathfinder_Node_getDistanceFromParent(pathfinder_Node self){
	return 1;


}

bool pathfinder_Node_equals(pathfinder_Node self, astar_Node other){
	pathfinder_Node tmp_cast_hhJV = (pathfinder_Node)(other);
	pathfinder_Node n = tmp_cast_hhJV;




	return self->i_708 == n->i_708 and self->j_906 == n->j_906;

}


int pathfinder_heuristicFunction(astar_AlgoData* data, astar_Node node){
	pathfinder_Node tmp_cast_I03D = (pathfinder_Node)(node);
	pathfinder_Node n = tmp_cast_I03D;

	pathfinder_Node tmp_cast_18Tl = (pathfinder_Node)(data->goal);
	pathfinder_Node end = tmp_cast_18Tl;
	int ret = 5;
	




	if (n->i_708 == end->i_708 and n->j_906 == end->j_906){
		return 0;
	
	}



	floor_Floor f = map_getNode(n->i_708, n->j_906)->bg;
	
	int tmp_wWVH_270 = f->type_867;
	switch (tmp_wWVH_270){
		case floor_START_TYPE:{
		}

		case floor_EXIT_TYPE:{
		}

		case floor_DESERT_TYPE:{
			ret = 0;
			break;
	
		}

	}



	if (n->i_708 < end->i_708){


		ret += end->i_708-n->i_708;
	}

	else{


		ret += n->i_708-end->i_708;
	}



	if (n->j_906 < end->j_906){


		ret += end->j_906-n->j_906;
	}

	else{


		ret += n->j_906-end->j_906;
	
	}

	return ret;


}

bool pathfinder_canGoThere(int i, int j){
	map_MapNode* objs = map_getNode(i, j);
	if (objs == NULL){
		return false;
	
	}


	cbcstd_List l = objs->objects;

	map_MapObject mo = objs->bg;
	floor_Floor tmp_cast_mvpC = (floor_Floor)(mo);
	floor_Floor f = tmp_cast_mvpC;
	int tmp_ciQN_283 = f->type_867;
	switch (tmp_ciQN_283){
		case floor_STONE_TYPE:{
		}

		case floor_TABLE_TYPE:{
		}

		case floor_LAKE_TYPE:{
		}

		case floor_PAUSE_TYPE:{
			return false;
		}

		default:{
			return true;

		}

	}


}

void pathfinder_findPath(int src_x, int src_y, int dst_x, int dst_y, cbcstd_List movements){

	if (not pathfinder_canGoThere(dst_y/common_FLOOR_HEIGHT, dst_x/common_FLOOR_WIDTH)){
		return;

	}

	astar_AlgoData data;

	data.root = pathfinder_Node_create(src_y/common_FLOOR_HEIGHT, src_x/common_FLOOR_WIDTH);

	data.goal = pathfinder_Node_create(dst_y/common_FLOOR_HEIGHT, dst_x/common_FLOOR_WIDTH);

	data.heuristicFunction = &pathfinder_heuristicFunction;
	
	astar_AStarAlgorithm(&data);
	

	if (data.path != NULL){

		cbcstd_Array tmp_cast_Ig1B = (cbcstd_Array)(data.path);
		{pathfinder_Node n=NULL;CBC_FOREACH(tmp_cast_Ig1B, n){


			movements->enqueue(movements, cbcstd_Int_create(n->move_422));
		}}

	}


	movements->enqueue(movements, cbcstd_Int_create(pathfinder_NO_ANIM));
	
	astar_cleanUpData(&data, true);

}

void pathfinder_init(){
	return;
}
