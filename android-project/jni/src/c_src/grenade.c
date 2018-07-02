#include <cbc.h>
// public globals
#include <grenade.h>
// private globals
const class_id grenade_Sprites__classid__ = 25701639516098614;
const class_id grenade_Grenade__classid__ = 56220438001416510;
//






image_Image grenade_grenade_img = NULL;

const int grenade_CHAR_WIDTH = 80;
const int grenade_CHAR_HEIGHT = 80;

int grenade_ANIM_STATES[4] = {0, 80, 160, 240};

const int grenade_LEFT_Y = 0;
const int grenade_UP_Y = 0;
const int grenade_RIGHT_Y = 0;
const int grenade_DOWN_Y = 0;

void grenade_init(){
	grenade_grenade_img = image_Image_create(common_GRENADE);


}

grenade_Sprites grenade_Sprites_create(){
	grenade_Sprites self = (grenade_Sprites)cbcstd_alloc(sizeof(grenade_Sprites_struct));
	try{
		grenade_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void grenade_Sprites_init(grenade_Sprites self){
	grenade_Sprites_initsystem(self);
	grenade_Sprites_inituser(self);
}
void grenade_Sprites_initsystem(grenade_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		25701639516098614L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(grenade_Sprites_struct);
	self->draw = &grenade_Sprites_draw;
	self->__end__ = &grenade_Sprites_end;
}
void grenade_Sprites_enduser(grenade_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void grenade_Sprites_end(grenade_Sprites self){
	grenade_Sprites_enduser(self);
	grenade_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void grenade_Sprites_decrefs(grenade_Sprites self){
}


void grenade_Sprites_inituser(grenade_Sprites self){

	self->rect_976.w = grenade_CHAR_WIDTH;

	self->rect_976.h = grenade_CHAR_HEIGHT;

	self->rect_976.y = grenade_LEFT_Y;

	self->down_y_122 = grenade_DOWN_Y;

	self->up_y_544 = grenade_UP_Y;

	self->left_y_559 = grenade_LEFT_Y;

	self->right_y_714 = grenade_RIGHT_Y;

	self->max_anims_975 = 4;

	self->anim_states_811 = grenade_ANIM_STATES;

	self->spritesheet_722 = grenade_grenade_img;

	self->default_skip_walk_269 = 2;

	self->_stopAnim_681(self);


}

void grenade_Sprites_draw(grenade_Sprites self, int x, int y, int w, int h){
	character_Sprites_draw((character_Sprites)self, x, y, grenade_CHAR_WIDTH, grenade_CHAR_HEIGHT);

}


grenade_Grenade grenade_Grenade_create(){
	grenade_Grenade self = (grenade_Grenade)cbcstd_alloc(sizeof(grenade_Grenade_struct));
	try{
		grenade_Grenade_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void grenade_Grenade_init(grenade_Grenade self){
	grenade_Grenade_initsystem(self);
	grenade_Grenade_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	grenade_Grenade_inituser(self);
}
void grenade_Grenade_initsystem(grenade_Grenade self){
	character_Character_initsystem((character_Character)self);
	const static class_id __classid__[6] = {
		56220438001416510L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(grenade_Grenade_struct);
	self->__getvtable__ = (void*)(&grenade_Grenade_getvtable);
	self->draw = &grenade_Grenade_draw;
	self->_animEnded_347 = &grenade_Grenade__animEnded_347;
	self->_animate_314 = &grenade_Grenade__animate_314;
	self->_canGoThere_896 = &grenade_Grenade__canGoThere_896;
	self->_findPath_673 = &grenade_Grenade__findPath_673;
	self->findPath = &grenade_Grenade_findPath;
	self->interact = &grenade_Grenade_interact;
	self->_checkNode_197 = &grenade_Grenade__checkNode_197;
	self->onClick = &grenade_Grenade_onClick;
	self->getInfo = &grenade_Grenade_getInfo;
	self->_fillHelpRect_284 = &grenade_Grenade__fillHelpRect_284;
	self->getHelpName = &grenade_Grenade_getHelpName;
	self->__end__ = &grenade_Grenade_end;
}
void grenade_Grenade_enduser(grenade_Grenade self){
	character_Character_enduser((character_Character)self);
	return;
}
void grenade_Grenade_end(grenade_Grenade self){
	grenade_Grenade_enduser(self);
	grenade_Grenade_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void grenade_Grenade_init_map_MapObject(map_MapObject self, grenade_Grenade __self__){
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
cbcstd_Object grenade_Grenade_getvtable(grenade_Grenade self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void grenade_Grenade_decrefs(grenade_Grenade self){
}





	
void grenade_Grenade_inituser(grenade_Grenade self){

	self->sprites_11 = grenade_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);

	self->width_945 = grenade_CHAR_WIDTH;

	self->height_399 = grenade_CHAR_HEIGHT;

	self->calcOffsets(self);

	self->to_x_969 = -1;

	self->to_y_714 = -1;

	self->walk_speed_577 = 3;

	self->_resetAnimState_866(self);

}

void grenade_Grenade_draw(grenade_Grenade self){

	if (not self->animating_154){






		character_Sprites tmp_wvim_632 = self->sprites_11;

		tmp_wvim_632->draw(tmp_wvim_632, self->x_405+self->x_offset_475,  self->y_782+self->y_offset_563,  self->width_945,  self->height_399);
	}

	else{
		character_Sprites tmp_UTTx_634 = self->sprites_11;

		if (tmp_UTTx_634->clicked(tmp_UTTx_634)){
			character_Sprites tmp_j8QU_636 = self->sprites_11;

			tmp_j8QU_636->selected_580 = false;
		}





		character_Sprites tmp_r8i6_642 = self->sprites_11;

		tmp_r8i6_642->draw(tmp_r8i6_642, self->anim_x_953,  self->anim_y_550,  self->width_945,  self->height_399);

		self->_animate_314(self);
	}


}

bool grenade_Grenade__animEnded_347(grenade_Grenade self){


	bool check1 = self->anim_x_953/common_FLOOR_WIDTH == self->to_x_969/common_FLOOR_WIDTH;


	bool check2 = self->anim_y_550/common_FLOOR_HEIGHT == self->to_y_714/common_FLOOR_HEIGHT;
	return check1 and check2;

}

void grenade_Grenade__animate_314(grenade_Grenade self){

	if (self->_animEnded_347(self)){


		self->x_405 = (self->anim_x_953/common_FLOOR_WIDTH)*common_FLOOR_WIDTH;


		self->y_782 = (self->anim_y_550/common_FLOOR_HEIGHT)*common_FLOOR_HEIGHT;

		self->animating_154 = false;
	}



	if (self->anim_x_953 > self->to_x_969){

		self->anim_x_953-=10;
	}

	else{


		self->anim_x_953 = self->to_x_969;
	}




	if (self->anim_x_953 > ((self->to_x_969+self->x_405)/2)){

			self->anim_y_550-=2;
	}

	else{

		int ratio1 = self->to_y_714;


		int ratio2 = self->anim_x_953 - self->to_x_969;
		int speed = -1;
		if (ratio2 > 0){
			speed = (int)((int)ratio1/(int)ratio2);
		}



		if (self->anim_y_550+speed > self->to_y_714 or speed < 0){


			self->anim_y_550 = self->to_y_714;
		}

		else{


		if (self->anim_y_550 < self->to_y_714 and speed > 0){

			self->anim_y_550+=speed;
		}

		}
	}


}

bool grenade_Grenade__canGoThere_896(grenade_Grenade self, int x, int y){
	return true;

}

void grenade_Grenade__findPath_673(grenade_Grenade self, int to_x, int to_y){

	if (self->animating_154){
		return;
	}


	int from_j = self->x_405/common_FLOOR_WIDTH;
	int to_j = to_x/common_FLOOR_WIDTH;
	if (from_j == to_j or to_j == 0){
		character_Sprites tmp_AEMD_676 = self->sprites_11;

		tmp_AEMD_676->selected_580 = false;
		return;
	
	}



	self->to_x_969 = to_x-self->x_offset_475;


	self->to_y_714 = to_y-self->y_offset_563;



	self->anim_x_953 = self->x_405+self->x_offset_475;



	self->anim_y_550 = self->y_782+self->y_offset_563;

	self->animating_154 = true;
	character_Sprites tmp_cIap_689 = self->sprites_11;

	tmp_cIap_689->animStart(tmp_cIap_689, 0);

	self->avoid_pickup_32 = true;


}

void grenade_Grenade_findPath(grenade_Grenade self, int x, int y){

	self->_findPath_673(self, x,  y);

}

void grenade_Grenade_interact(grenade_Grenade self){


	map_MapNode* node = map_getNode(self->y_782/common_FLOOR_HEIGHT, self->x_405/common_FLOOR_WIDTH);

	floor_Floor tmp_cast_HN9Q = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_HN9Q;




	if (self->to_x_969 >= 0 and self->to_y_714 >= 0 and not self->animating_154 and not self->exploded_659){

		if (not self->_checkNode_197(self, f)){
			return;
		}


		f->type_867 = floor_NORMAL_NO_MINE_TYPE;

		f->startFireAnim(f);

		self->x_405 = -1;

		self->y_782 = -1;

		self->exploded_659 = true;

	}


}

bool grenade_Grenade__checkNode_197(grenade_Grenade self, floor_Floor f){

	int i = f->i_163;

	int j = f->j_639;

	bool check1 = j == self->to_x_969/common_FLOOR_WIDTH;

	bool check2 = i == self->to_y_714/common_FLOOR_HEIGHT;
	return check1 and check2;

}

void grenade_Grenade_onClick(grenade_Grenade self, int x, int y){

	if (self->x_405/common_FLOOR_WIDTH < DIM_X-1){
		return;
	}

	character_Character_onClick((character_Character)self, x, y);

}

char** grenade_Grenade_getInfo(grenade_Grenade self){
	static char* info[7] = {"Standard military grenade.","It can blow up a small","portion of any terrain.","Select it, and then select","where to throw it.","",""};
	return info;

}

void grenade_Grenade__fillHelpRect_284(grenade_Grenade self, SDL_Rect* rect){
	rect->w = grenade_CHAR_WIDTH;
	rect->h = grenade_CHAR_HEIGHT;
	rect->y = 0;
	rect->x = 0;
	

}

char* grenade_Grenade_getHelpName(grenade_Grenade self){
	return "Grenade";

}


