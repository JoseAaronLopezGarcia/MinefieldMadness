#include <cbc.h>
// public globals
#include <map.h>
// private globals
const class_id map_MapObject__classid__ = 4450938680730463789;
//






























map_MapNode objects[DIM_Y][DIM_X];
cbcstd_List map_removed_objects = NULL;

cbcstd_Semaphore map_map_mutex = NULL;
int map_last_x = -1;
int map_last_y = -1;

image_Image map_loading_img = NULL;
image_Image map_selected_img = NULL;
image_Image map_help_box = NULL;

void map_addBg(int i, int j, map_MapObject bg){
	if (i<0 or i>=DIM_Y or j < 0 or j >= DIM_X){
		return;
	}


	objects[i][j].bg = bg;


}

void map_cleanArea(int i, int j){
	if (j > 0 and j < DIM_X-1){

		map_MapObject bg = objects[i][j].bg;

		CBC_LOW_CAST(bg, map_MapObject)->cleanUp(bg);
	}


	cbcstd_List map_objects = objects[i][j].objects;

	while (map_objects->size(map_objects) > 0){

		cbcstd_Object o = map_objects->pop(map_objects);
		cbcstd_destroyObj((cbcstd_Object*)&(o));

	}


}

void map_emptyMap(){

	while (map_removed_objects->size(map_removed_objects) > 0){

		cbcstd_Object o = map_removed_objects->pop(map_removed_objects);
		cbcstd_destroyObj((cbcstd_Object*)&(o));

	}

	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){
			map_cleanArea(i, j);

		}}

	}}


}

void map_emptyMinefield(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X-1; j++){
			map_cleanArea(i, j);

		}}

	}}


}

void map_init(){
	
	map_loading_img = image_Image_create(common_LOADING);
	screen_clear();

	map_loading_img->draw(map_loading_img, 0,  0);
	screen_flip();

	

	map_map_mutex = cbcstd_Semaphore_create(1);
	
	map_selected_img = image_Image_create(common_SELECTED);
	map_help_box = image_Image_create(common_HELP_BOX);

	map_removed_objects = cbcstd_List_create();

	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){

			objects[i][j].objects = cbcstd_List_create();


		}}

	}}


}

void map_drawBackground(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){



			CBC_LOW_CAST(objects[i][j].bg, map_MapObject)->draw(objects[i][j].bg);

		}}

	}}


}

void map_draw(){

	map_map_mutex->wait(map_map_mutex);
	map_drawBackground();
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){

			cbcstd_List list = objects[i][j].objects;

			objects[i][j].objects = cbcstd_List_create();
			{map_MapObject x=NULL;CBC_FOREACH(list, x){
				int new_i, new_j;

				 CBC_LOW_CAST(x, map_MapObject)->updatePosition(x, &new_i,  &new_j);
				if (new_i < 0 or new_j < 0){

					map_removed_objects->push(map_removed_objects, x);
				}

				else{

					CBC_LOW_CAST(x, map_MapObject)->draw(x);


					objects[new_i][new_j].objects->enqueue(objects[new_i][new_j].objects, x);
					if (new_i != i or new_j != j){

						CBC_LOW_CAST(x, map_MapObject)->interact(x);
					}

				}

			}}

			cbcstd_destroyObj((cbcstd_Object*)&(list));
		}}

	}}


	map_map_mutex->release(map_map_mutex);


}

bool map_outOfBounds(int x, int y, int w, int h){
	return x < 0 or y < 0 or x+w > common_FLOOR_WIDTH*DIM_X or y+h > common_FLOOR_WIDTH*DIM_Y;


}

bool map_fullOutOfBounds(int x, int y){
	return map_outOfBounds(x, y, 0, 0);


}

bool map_inLimitNorth(int y, int h){
	return map_outOfBounds(1, y-1, 1, h);


}

bool map_inLimitSouth(int y, int h){
	return map_outOfBounds(1, y+1, 1, h);


}

bool map_inLimitEast(int x, int w){
	return map_outOfBounds(x+1, 1, w, 1);


}

bool map_inLimitWest(int x, int w){
	return map_outOfBounds(x-1, 1, w, 1);


}

void map_insertObject(cbcstd_Object o, int i, int j){

	map_map_mutex->wait(map_map_mutex);
	map_MapObject tmp_cast_qBWa = (map_MapObject)(o);
	map_MapObject obj = tmp_cast_qBWa;

	CBC_LOW_CAST(obj, map_MapObject)->setCoordinates(obj, i,  j);


	objects[i][j].objects->push(objects[i][j].objects, o);

	map_map_mutex->release(map_map_mutex);


}

void map_removeObject(cbcstd_Object o, int i, int j){

	map_map_mutex->wait(map_map_mutex);
	cbcstd_List aux = cbcstd_List_create();

	cbcstd_List objs = objects[i][j].objects;
	{cbcstd_Object item=NULL;CBC_FOREACH(objs, item){
		if (item != o){

			aux->enqueue(aux, item);
		}

	}}


	cbcstd_destroyObj((cbcstd_Object*)&(objects[i][j].objects));

	objects[i][j].objects = aux;

	map_map_mutex->release(map_map_mutex);


}

map_MapNode* map_getNode(int i, int j){
	if (i<0 or i>=DIM_Y or j < 0 or j >= DIM_X){
		return NULL;
	

	}

	map_MapNode* ret = &(objects[i][j]);
	

	return ret;


}

map_MapNode* map_getNorthNode(int i, int j){
	map_MapNode* ret = NULL;
	

	if (i>0){
		ret = &(objects[i-1][j]);
	

	}

	return ret;


}

map_MapNode* map_getSouthNode(int i, int j){
	map_MapNode* ret = NULL;
	

	if (i<DIM_Y-1){
		ret = &(objects[i+1][j]);
	

	}

	return ret;


}

map_MapNode* map_getEastNode(int i, int j){
	map_MapNode* ret = NULL;
	

	if (j<DIM_X-1){
		ret = &(objects[i][j+1]);
	

	}

	return ret;


}

map_MapNode* map_getWestNode(int i, int j){
	map_MapNode* ret = NULL;
	

	if (j>0){
		ret = &(objects[i][j-1]);
	

	}

	return ret;


}

bool map_clickedOn(int x, int y, int w, int h){
	if (map_last_x < 0 or map_last_y < 0){
		return false;
	}

	int top_x = x + w;
	int top_y = y + h;
	return x <= map_last_x and map_last_x <= top_x and y <= map_last_y and map_last_y <= top_y;


}

bool map_clickedAround(int x, int y){
	if (map_last_x < 0 or map_last_y < 0){
		return false;
	}

	int my_i = y/common_FLOOR_HEIGHT;
	int my_j = x/common_FLOOR_WIDTH;
	int other_i = map_last_y/common_FLOOR_HEIGHT;
	int other_j = map_last_x/common_FLOOR_WIDTH;
	return my_i == other_i and my_j == other_j;


}

void map_onClick(int x, int y){

	map_map_mutex->wait(map_map_mutex);
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){

			cbcstd_List objs = objects[i][j].objects;

			if (objs->size(objs) > 0){

				map_MapObject o = objs->getLast(objs);

				CBC_LOW_CAST(o, map_MapObject)->onClick(o, x,  y);
			}

		}}

	}}


	map_map_mutex->release(map_map_mutex);


}

void map_destroyMap(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){

			map_MapObject mo = objects[i][j].bg;
			cbcstd_destroyObj((cbcstd_Object*)&(mo));

		}}

	}}


}

void map_waitAnimEnd(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){

			map_MapObject mo = objects[i][j].bg;

			CBC_LOW_CAST(mo, map_MapObject)->waitAnimEnd(mo);
		}}

	}}


}

