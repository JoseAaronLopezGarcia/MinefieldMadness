#include <cbc.h>
// public globals
#include <astar.h>
// private globals
const class_id astar_Node__classid__ = -7632195265922784466;
static bool _astar_visitedNode(cbcstd_List open_nodes, cbcstd_List closed_nodes, astar_Node cur_node);

static void _astar_generatePath(astar_AlgoData* data, astar_Node cur_node);

static astar_Node _astar_selectMinNode(cbcstd_List open_nodes);

static void _astar_expandNode(astar_AlgoData* data, cbcstd_List open_nodes, cbcstd_List closed_nodes, astar_Node next_node);

static bool _astar_checkData(astar_AlgoData* data);

//





















































	







	








void astar_AStarAlgorithm(astar_AlgoData* data){

	

	if (not _astar_checkData(data)){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("ERROR: incorrect data was fed to A* algorithm")));

	

	}


	data->path = NULL;


	CBC_LOW_CAST(data->root, astar_Node)->setDistance(data->root, 0);


	CBC_LOW_CAST(data->root, astar_Node)->setParent(data->root, NULL);




	CBC_LOW_CAST(data->root, astar_Node)->setValue(data->root, data->heuristicFunction(data, data->root));



	if (CBC_LOW_CAST(data->root, astar_Node)->getValue(data->root) == 0){


		data->path = cbcstd_Array_create(1);



		data->path->add(data->path, data->root);
		return;

	}


	data->open_nodes = cbcstd_List_create();


	data->closed_nodes = cbcstd_List_create();

	



	_astar_expandNode(data, data->open_nodes, data->closed_nodes, data->root);

	
	do{



		if (data->open_nodes->size(data->open_nodes) == 0){
			break;
		}


		astar_Node next_node = _astar_selectMinNode(data->open_nodes);
		if (next_node == NULL){

			break;
		}


		if (CBC_LOW_CAST(next_node, astar_Node)->getValue(next_node) == 0){

			_astar_generatePath(data, next_node);

			break;
		}



		_astar_expandNode(data, data->open_nodes, data->closed_nodes, next_node);

	}

	while (true);
	

	if (data->path == NULL){

		data->path = cbcstd_Array_create(1);




		data->path->add(data->path, data->root);
	
	

	}



	while (data->open_nodes->size(data->open_nodes) > 0){



		cbcstd_Object o = data->open_nodes->pop(data->open_nodes);



		if (not data->path->contains(data->path, o)){
			cbcstd_destroyObj((cbcstd_Object*)&(o));
	
		}

	}




	while (data->closed_nodes->size(data->closed_nodes) > 0){



		cbcstd_Object o = data->closed_nodes->pop(data->closed_nodes);



		if (not data->path->contains(data->path, o)){
			cbcstd_destroyObj((cbcstd_Object*)&(o));
			
		}

	}


	cbcstd_destroyObj((cbcstd_Object*)&(data->open_nodes));

	cbcstd_destroyObj((cbcstd_Object*)&(data->closed_nodes));






}

void astar_cleanUpData(astar_AlgoData* data, bool full_cleanup){

	if (data->path != NULL){


		while (data->path->size_871 > 0){


			cbcstd_Object o = data->path->remove(data->path, 0);


			if (o != data->goal and o != data->root){
				cbcstd_destroyObj((cbcstd_Object*)&(o));
			}

		}


		cbcstd_destroyObj((cbcstd_Object*)&(data->path));
	}

	if (full_cleanup){

		cbcstd_destroyObj((cbcstd_Object*)&(data->goal));

		cbcstd_destroyObj((cbcstd_Object*)&(data->root));




	}


}

static bool _astar_visitedNode(cbcstd_List open_nodes, cbcstd_List closed_nodes, astar_Node cur_node){
	{astar_Node n=NULL;CBC_FOREACH(open_nodes, n){

		if (CBC_LOW_CAST(n, astar_Node)->equals(n, cur_node)){
			return true;
		}

	}}

	{astar_Node n=NULL;CBC_FOREACH(closed_nodes, n){

		if (CBC_LOW_CAST(n, astar_Node)->equals(n, cur_node)){
			return true;
		}

	}}

	return false;





}

static void _astar_generatePath(astar_AlgoData* data, astar_Node cur_node){
	cbcstd_List aux = cbcstd_List_create();
	astar_Node n = cur_node;
	while (n != NULL){

		aux->push(aux, n);

		n = CBC_LOW_CAST(n, astar_Node)->getParent(n);
	}



	data->path = cbcstd_Array_create(aux->size(aux));
	{cbcstd_Object i=NULL;CBC_FOREACH(aux, i){



		data->path->add(data->path, i);
		
	}}

	cbcstd_destroyObj((cbcstd_Object*)&(aux));






}

static astar_Node _astar_selectMinNode(cbcstd_List open_nodes){
	size_t min = -1;
	astar_Node ret = NULL;
	{astar_Node n=NULL;CBC_FOREACH(open_nodes, n){


		if (CBC_LOW_CAST(n, astar_Node)->getValue(n)+CBC_LOW_CAST(n, astar_Node)->getDistance(n) < min){


			min = CBC_LOW_CAST(n, astar_Node)->getValue(n)+CBC_LOW_CAST(n, astar_Node)->getDistance(n);
			ret = n;
		}

	}}

	return ret;







}

static void _astar_expandNode(astar_AlgoData* data, cbcstd_List open_nodes, cbcstd_List closed_nodes, astar_Node next_node){

	closed_nodes->push(closed_nodes, next_node);

	open_nodes->removeObject(open_nodes, next_node);

	cbcstd_List children = CBC_LOW_CAST(next_node, astar_Node)->getChildren(next_node);

	if (children->size(children) == 0){
		cbcstd_destroyObj((cbcstd_Object*)&(children));
		return;
	}


	cbcstd_Array to_delete = cbcstd_Array_create(children->size(children));
	{astar_Node n=NULL;CBC_FOREACH(children, n){
		if (_astar_visitedNode(open_nodes, closed_nodes, n)){


			to_delete->add(to_delete, n);
			

			


			open_nodes->removeObject(open_nodes, n);

			closed_nodes->removeObject(closed_nodes, n);
			continue;
		

		}


		CBC_LOW_CAST(n, astar_Node)->setParent(n, next_node);


		CBC_LOW_CAST(n, astar_Node)->setValue(n, data->heuristicFunction(data, n));



		CBC_LOW_CAST(n, astar_Node)->setDistance(n, CBC_LOW_CAST(next_node, astar_Node)->getDistance(next_node)+CBC_LOW_CAST(n, astar_Node)->getDistanceFromParent(n));

		open_nodes->push(open_nodes, n);
	

	}}

	cbcstd_destroyObj((cbcstd_Object*)&(children));

	while (to_delete->size_871 > 0){

		cbcstd_Object o = to_delete->remove(to_delete, 0);
		cbcstd_destroyObj((cbcstd_Object*)&(o));
	}

	cbcstd_destroyObj((cbcstd_Object*)&(to_delete));





}

static bool _astar_checkData(astar_AlgoData* data){


	if (not isinstanceof(data->root, astar_Node) or not isinstanceof(data->root, astar_Node)){
		return false;

	

	}




	return data->root != NULL and data->goal != NULL and data->heuristicFunction != NULL;

}

void astar_init(){
	return;
}
