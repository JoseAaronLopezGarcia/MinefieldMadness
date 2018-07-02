#include <cbc.h>
// public globals
#include <lawnmower.h>
// private globals
const class_id lawnmower_Sprites__classid__ = -1072884999268182106;
const class_id lawnmower_LawnMower__classid__ = -761102030336206246;
//








image_Image lawnmower_lawnmower_img = NULL;
sound_Sound lawnmower_motor = NULL;

const int lawnmower_CHAR_WIDTH = 80;
const int lawnmower_CHAR_HEIGHT = 80;

int lawnmower_ANIM_STATES[4] = {0, 80, 160, 240};

const int lawnmower_LEFT_Y = 0;
const int lawnmower_UP_Y = 0;
const int lawnmower_RIGHT_Y = 0;
const int lawnmower_DOWN_Y = 0;

void lawnmower_init(){
	lawnmower_motor = sound_Sound_create(common_MOTOR_SOUND);
	lawnmower_lawnmower_img = image_Image_create(common_LAWNMOWER);


}

lawnmower_Sprites lawnmower_Sprites_create(){
	lawnmower_Sprites self = (lawnmower_Sprites)cbcstd_alloc(sizeof(lawnmower_Sprites_struct));
	try{
		lawnmower_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void lawnmower_Sprites_init(lawnmower_Sprites self){
	lawnmower_Sprites_initsystem(self);
	lawnmower_Sprites_inituser(self);
}
void lawnmower_Sprites_initsystem(lawnmower_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		-1072884999268182106L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(lawnmower_Sprites_struct);
	self->draw = &lawnmower_Sprites_draw;
	self->__end__ = &lawnmower_Sprites_end;
}
void lawnmower_Sprites_enduser(lawnmower_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void lawnmower_Sprites_end(lawnmower_Sprites self){
	lawnmower_Sprites_enduser(self);
	lawnmower_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void lawnmower_Sprites_decrefs(lawnmower_Sprites self){
}


void lawnmower_Sprites_inituser(lawnmower_Sprites self){

	self->rect_976.w = lawnmower_CHAR_WIDTH;

	self->rect_976.h = lawnmower_CHAR_HEIGHT;

	self->rect_976.y = lawnmower_LEFT_Y;

	self->down_y_122 = lawnmower_DOWN_Y;

	self->up_y_544 = lawnmower_UP_Y;

	self->left_y_559 = lawnmower_LEFT_Y;

	self->right_y_714 = lawnmower_RIGHT_Y;

	self->max_anims_975 = 4;

	self->anim_states_811 = lawnmower_ANIM_STATES;

	self->spritesheet_722 = lawnmower_lawnmower_img;

	self->default_skip_walk_269 = 2;

	self->_stopAnim_681(self);


}

void lawnmower_Sprites_draw(lawnmower_Sprites self, int x, int y, int w, int h){
	character_Sprites_draw((character_Sprites)self, x, y, lawnmower_CHAR_WIDTH, lawnmower_CHAR_HEIGHT);

}


lawnmower_LawnMower lawnmower_LawnMower_create(){
	lawnmower_LawnMower self = (lawnmower_LawnMower)cbcstd_alloc(sizeof(lawnmower_LawnMower_struct));
	try{
		lawnmower_LawnMower_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void lawnmower_LawnMower_init(lawnmower_LawnMower self){
	lawnmower_LawnMower_initsystem(self);
	lawnmower_LawnMower_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	lawnmower_LawnMower_inituser(self);
}
void lawnmower_LawnMower_initsystem(lawnmower_LawnMower self){
	character_Character_initsystem((character_Character)self);
	const static class_id __classid__[6] = {
		-761102030336206246L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(lawnmower_LawnMower_struct);
	self->__getvtable__ = (void*)(&lawnmower_LawnMower_getvtable);
	self->_findPath_673 = &lawnmower_LawnMower__findPath_673;
	self->interact = &lawnmower_LawnMower_interact;
	self->_stop_925 = &lawnmower_LawnMower__stop_925;
	self->_destroyMapNode_226 = &lawnmower_LawnMower__destroyMapNode_226;
	self->onClick = &lawnmower_LawnMower_onClick;
	self->getInfo = &lawnmower_LawnMower_getInfo;
	self->_fillHelpRect_284 = &lawnmower_LawnMower__fillHelpRect_284;
	self->getHelpName = &lawnmower_LawnMower_getHelpName;
	self->__end__ = &lawnmower_LawnMower_end;
}
void lawnmower_LawnMower_enduser(lawnmower_LawnMower self){
	character_Character_enduser((character_Character)self);
	return;
}
void lawnmower_LawnMower_end(lawnmower_LawnMower self){
	lawnmower_LawnMower_enduser(self);
	lawnmower_LawnMower_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void lawnmower_LawnMower_init_map_MapObject(map_MapObject self, lawnmower_LawnMower __self__){
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
cbcstd_Object lawnmower_LawnMower_getvtable(lawnmower_LawnMower self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void lawnmower_LawnMower_decrefs(lawnmower_LawnMower self){
}





void lawnmower_LawnMower_inituser(lawnmower_LawnMower self){

	self->sprites_11 = lawnmower_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);

	self->width_945 = lawnmower_CHAR_WIDTH;

	self->height_399 = lawnmower_CHAR_WIDTH;

	self->calcOffsets(self);

	self->to_i_386 = -1;

	self->to_j_12 = -1;

	self->walk_speed_577 = 10;

	self->_resetAnimState_866(self);


}

void lawnmower_LawnMower__findPath_673(lawnmower_LawnMower self, int to_x, int to_y){
	int to_i = to_y/common_FLOOR_HEIGHT;
	int to_j = to_x/common_FLOOR_WIDTH;
	
	if (to_j < 1 or to_j >= DIM_X-1){
		return;
	
	}


	self->x_405 = to_j*common_FLOOR_WIDTH;

	self->y_782 = to_i*common_FLOOR_HEIGHT;

	self->to_i_386 = to_i;

	self->to_j_12 = to_j;
	
	{int j=to_j+1; for (; j<to_j+4; j++){
		if (j>=DIM_X-1){
			cbcstd_List tmp_49T2_736 = self->movements_662;

			tmp_49T2_736->enqueue(tmp_49T2_736, cbcstd_Int_create(pathfinder_RIGHT));
			break;
		}

		map_MapObject obj = map_getNode(to_i, j)->bg;
		floor_Floor tmp_cast_h7wH = (floor_Floor)(obj);
		floor_Floor f = tmp_cast_h7wH;


		if (f->type_867 == floor_STONE_TYPE or f->type_867 == floor_LAKE_TYPE){
			cbcstd_List tmp_DUoS_741 = self->movements_662;

			tmp_DUoS_741->enqueue(tmp_DUoS_741, cbcstd_Int_create(pathfinder_RIGHT));
			break;
		}

		cbcstd_List tmp_qtMs_743 = self->movements_662;

		tmp_qtMs_743->enqueue(tmp_qtMs_743, cbcstd_Int_create(pathfinder_RIGHT));
	
	}}



	self->to_y_714 = self->y_782;
	cbcstd_List tmp_jWOM_747 = self->movements_662;



	self->to_x_969 = self->x_405 + (tmp_jWOM_747->size(tmp_jWOM_747)*common_FLOOR_WIDTH);
	
	cbcstd_List tmp_Rs9P_751 = self->movements_662;

	if (tmp_Rs9P_751->size(tmp_Rs9P_751) > 0){
		character_Sprites tmp_tXte_753 = self->sprites_11;

		tmp_tXte_753->selected_580 = false;
	
	}


	lawnmower_motor->play(lawnmower_motor);


}

void lawnmower_LawnMower_interact(lawnmower_LawnMower self){


	map_MapNode* node = map_getNode(self->y_782/common_FLOOR_HEIGHT, self->x_405/common_FLOOR_WIDTH);

	floor_Floor tmp_cast_ETD6 = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_ETD6;

	int i = f->i_163;

	int j = f->j_639;


	if (self->to_j_12 >= 0 and self->to_i_386 >= 0){
		cbcstd_List tmp_KaNi_762 = self->movements_662;


		if (self->anim_453 == pathfinder_NO_ANIM and tmp_KaNi_762->size(tmp_KaNi_762) == 0){

			self->x_405 = -1;

			self->y_782 = -1;
		}

		else{



			self->_destroyMapNode_226(self, self->to_i_386,  self->to_j_12);

			self->_destroyMapNode_226(self, i,  j);

		}

	}


}

void lawnmower_LawnMower__stop_925(lawnmower_LawnMower self){
	return;


}

void lawnmower_LawnMower__destroyMapNode_226(lawnmower_LawnMower self, int i, int j){
	if (i<0 or i>=DIM_Y or j<1 or j>=DIM_X-1){
		return;
	}

	map_MapNode* node = map_getNode(i, j);

	floor_Floor tmp_cast_x14w = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_x14w;

	f->type_867 = floor_DESERT_TYPE;


}

void lawnmower_LawnMower_onClick(lawnmower_LawnMower self, int x, int y){

	if (self->x_405/common_FLOOR_WIDTH < DIM_X-1){
		return;
	}

	character_Character_onClick((character_Character)self, x, y);

}

char** lawnmower_LawnMower_getInfo(lawnmower_LawnMower self){
	static char* info[7] = {"A typical lawnmower found","in many households.","It can cut through grass,","effectively becoming safe spots.","Select it and then select","where to start cutting,","but be aware, it'll run out of gas."};
	return info;

}

void lawnmower_LawnMower__fillHelpRect_284(lawnmower_LawnMower self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* lawnmower_LawnMower_getHelpName(lawnmower_LawnMower self){
	return "Lawnmower";

}


