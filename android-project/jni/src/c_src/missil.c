#include <cbc.h>
// public globals
#include <missil.h>
// private globals
const class_id missil_Sprites__classid__ = 1675738066899589914;
const class_id missil_Missil__classid__ = 4548907163716112332;
//








image_Image missil_missil_img = NULL;
sound_Sound (missil_sound);

const int missil_CHAR_WIDTH = 80;
const int missil_CHAR_HEIGHT = 80;

int missil_ANIM_STATES[3] = {0, 80, 160};

const int missil_LEFT_Y = 0;
const int missil_UP_Y = 80;
const int missil_RIGHT_Y = 160;
const int missil_DOWN_Y = 240;

missil_Sprites missil_Sprites_create(){
	missil_Sprites self = (missil_Sprites)cbcstd_alloc(sizeof(missil_Sprites_struct));
	try{
		missil_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void missil_Sprites_init(missil_Sprites self){
	missil_Sprites_initsystem(self);
	missil_Sprites_inituser(self);
}
void missil_Sprites_initsystem(missil_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		1675738066899589914L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(missil_Sprites_struct);
	self->draw = &missil_Sprites_draw;
	self->__end__ = &missil_Sprites_end;
}
void missil_Sprites_enduser(missil_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void missil_Sprites_end(missil_Sprites self){
	missil_Sprites_enduser(self);
	missil_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void missil_Sprites_decrefs(missil_Sprites self){
}


void missil_Sprites_inituser(missil_Sprites self){

	self->pos_987 = pathfinder_LEFT;

	self->rect_976.w = missil_CHAR_WIDTH;

	self->rect_976.h = missil_CHAR_HEIGHT;

	self->rect_976.y = missil_LEFT_Y;

	self->down_y_122 = missil_DOWN_Y;

	self->up_y_544 = missil_UP_Y;

	self->left_y_559 = missil_LEFT_Y;

	self->right_y_714 = missil_RIGHT_Y;

	self->max_anims_975 = 3;

	self->anim_states_811 = missil_ANIM_STATES;

	self->spritesheet_722 = missil_missil_img;

	self->default_skip_walk_269 = 5;

	self->_stopAnim_681(self);


}

void missil_Sprites_draw(missil_Sprites self, int x, int y, int w, int h){
	character_Sprites_draw((character_Sprites)self, x, y, missil_CHAR_WIDTH, missil_CHAR_HEIGHT);

}


missil_Missil missil_Missil_create(){
	missil_Missil self = (missil_Missil)cbcstd_alloc(sizeof(missil_Missil_struct));
	try{
		missil_Missil_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void missil_Missil_init(missil_Missil self){
	missil_Missil_initsystem(self);
	missil_Missil_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	missil_Missil_inituser(self);
}
void missil_Missil_initsystem(missil_Missil self){
	character_Character_initsystem((character_Character)self);
	const static class_id __classid__[6] = {
		4548907163716112332L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(missil_Missil_struct);
	self->__getvtable__ = (void*)(&missil_Missil_getvtable);
	self->_canGoThere_896 = &missil_Missil__canGoThere_896;
	self->_findPath_673 = &missil_Missil__findPath_673;
	self->interact = &missil_Missil_interact;
	self->_destroyMapNode_483 = &missil_Missil__destroyMapNode_483;
	self->_stop_925 = &missil_Missil__stop_925;
	self->hasColided = &missil_Missil_hasColided;
	self->onClick = &missil_Missil_onClick;
	self->getInfo = &missil_Missil_getInfo;
	self->_fillHelpRect_284 = &missil_Missil__fillHelpRect_284;
	self->getHelpName = &missil_Missil_getHelpName;
	self->__end__ = &missil_Missil_end;
}
void missil_Missil_enduser(missil_Missil self){
	character_Character_enduser((character_Character)self);
	return;
}
void missil_Missil_end(missil_Missil self){
	missil_Missil_enduser(self);
	missil_Missil_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void missil_Missil_init_map_MapObject(map_MapObject self, missil_Missil __self__){
	self->draw = (void*)(__self__->draw);
	self->onClick = (void*)(__self__->onClick);
	self->interact = (void*)(__self__->interact);
	self->setCoordinates = (void*)(__self__->setCoordinates);
	self->updatePosition = (void*)(__self__->updatePosition);
	self->cleanUp = (void*)(__self__->cleanUp);
	self->waitAnimEnd = (void*)(__self__->waitAnimEnd);
	self->getSaveInfo = (void*)(__self__->getSaveInfo);
	self->setInfoFromSave = (void*)(__self__->setInfoFromSave);
	self->getInfo = (void*)(__self__->getInfo);
	self->drawHelpSprite = (void*)(__self__->drawHelpSprite);
	self->getHelpName = (void*)(__self__->getHelpName);
}
cbcstd_Object missil_Missil_getvtable(missil_Missil self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void missil_Missil_decrefs(missil_Missil self){
}





void missil_Missil_inituser(missil_Missil self){

	self->sprites_11 = missil_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);

	self->width_945 = missil_CHAR_WIDTH;

	self->height_399 = missil_CHAR_HEIGHT;

	self->calcOffsets(self);

	self->to_i_106 = -1;

	self->to_j_841 = -1;

	self->walk_speed_577 = 10;

	self->_resetAnimState_866(self);


}

bool missil_Missil__canGoThere_896(missil_Missil self, int x, int y){
	return true;


}

void missil_Missil__findPath_673(missil_Missil self, int to_x, int to_y){


	if (self->avoid_pickup_32){
		return;

	}


	int from_i = self->y_782/common_FLOOR_HEIGHT;

	int from_j = self->x_405/common_FLOOR_WIDTH;
	int to_i = to_y/common_FLOOR_HEIGHT;
	int to_j = to_x/common_FLOOR_WIDTH;
	
	if (from_j == to_j or to_j == 0){
		return;
	
	}

	int max_i = 0;
	int max_j = 0;
	int move_i = pathfinder_NO_ANIM;
	int move_j = pathfinder_NO_ANIM;
	
	if (from_i < to_i){
		move_i = pathfinder_DOWN;
		max_i = to_i-from_i;
	}

	else{
		move_i = pathfinder_UP;
		max_i = from_i-to_i;
	
	}

	if (from_j < to_j){
		move_j = pathfinder_RIGHT;
		max_j = to_j-from_j;
	}

	else{
		move_j = pathfinder_LEFT;
		max_j = from_j-to_j;
	
	}

	{int j=0; for (; j<max_j; j++){
		cbcstd_List tmp_lveM_566 = self->movements_662;

		tmp_lveM_566->enqueue(tmp_lveM_566, cbcstd_Int_create(move_j));
	
	}}

	{int i=0; for (; i<=max_i; i++){
		cbcstd_List tmp_QrBK_568 = self->movements_662;

		tmp_QrBK_568->enqueue(tmp_QrBK_568, cbcstd_Int_create(move_i));
	
	}}

	cbcstd_List tmp_aJJL_570 = self->movements_662;

	if (tmp_aJJL_570->size(tmp_aJJL_570) > 0){

		self->to_i_106 = to_i;

		self->to_j_841 = to_j;

		self->to_x_969 = to_x;

		self->to_y_714 = to_y;
		character_Sprites tmp_7vTx_576 = self->sprites_11;

		tmp_7vTx_576->selected_580 = false;

		self->avoid_pickup_32 = true;

		missil_sound->play(missil_sound);

	}


}

void missil_Missil_interact(missil_Missil self){


	map_MapNode* node = map_getNode(self->y_782/common_FLOOR_HEIGHT, self->x_405/common_FLOOR_WIDTH);

	floor_Floor tmp_cast_pGoV = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_pGoV;

	int i = f->i_163;

	int j = f->j_639;

	if (self->hasColided(self)){

		self->_destroyMapNode_483(self, i,  j);

		self->_destroyMapNode_483(self, i-1,  j);

		self->_destroyMapNode_483(self, i+1,  j);

		self->_destroyMapNode_483(self, i,  j-1);

		self->_destroyMapNode_483(self, i,  j+1);

		self->_destroyMapNode_483(self, i-1,  j-1);

		self->_destroyMapNode_483(self, i-1,  j+1);

		self->_destroyMapNode_483(self, i+1,  j-1);

		self->_destroyMapNode_483(self, i+1,  j+1);

		self->x_405 = -1;

		self->y_782 = -1;

	}


}

void missil_Missil__destroyMapNode_483(missil_Missil self, int i, int j){
	if (i<0 or i>=DIM_Y or j<1 or j>=DIM_X-1){
		return;
	}

	map_MapNode* node = map_getNode(i, j);

	floor_Floor tmp_cast_rVCe = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_rVCe;

	f->type_867 = floor_NORMAL_NO_MINE_TYPE;

	f->startFireAnim(f);


}

void missil_Missil__stop_925(missil_Missil self){
	return;


}

bool missil_Missil_hasColided(missil_Missil self){
	cbcstd_List tmp_Jtp5_598 = self->movements_662;



	return self->to_i_106 >= 0 and self->to_j_841 >= 0 and tmp_Jtp5_598->size(tmp_Jtp5_598) == 0;

}

void missil_Missil_onClick(missil_Missil self, int x, int y){

	if (self->x_405/common_FLOOR_WIDTH < DIM_X-1){
		return;
	}

	character_Character_onClick((character_Character)self, x, y);

}

char** missil_Missil_getInfo(missil_Missil self){
	static char* info[7] = {"A very powerful guided missil.","It works similar to a grenade:","select the missil,","then select where to launch it.","Although the blast radius","of the missil is much bigger.","Insert phallic joke here."};
	return info;

}

void missil_Missil__fillHelpRect_284(missil_Missil self, SDL_Rect* rect){
	rect->w = missil_CHAR_WIDTH;
	rect->h = missil_CHAR_HEIGHT;
	rect->y = missil_LEFT_Y;
	rect->x = missil_ANIM_STATES[0];


}

char* missil_Missil_getHelpName(missil_Missil self){
	return "Missil";

}


void missil_init(){
	missil_missil_img = image_Image_create(common_MISSIL);
	missil_sound = sound_Sound_create(common_MISSIL_SOUND);

}

