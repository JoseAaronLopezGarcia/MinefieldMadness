#include <cbc.h>
// public globals
#include <laser.h>
// private globals
const class_id laser_Sprites__classid__ = -4201673146102414989;
const class_id laser_Laser__classid__ = -4484401674479260050;
//








image_Image laser_laser_img = NULL;
image_Image laser_laserbeam_img = NULL;

sound_Sound (beam_sound);

void laser_init(){
	laser_laser_img = image_Image_create(common_LASER);
	laser_laserbeam_img = image_Image_create(common_LASERBEAM);
	beam_sound = sound_Sound_create(common_BEAM_SOUND);


}

laser_Sprites laser_Sprites_create(){
	laser_Sprites self = (laser_Sprites)cbcstd_alloc(sizeof(laser_Sprites_struct));
	try{
		laser_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void laser_Sprites_init(laser_Sprites self){
	laser_Sprites_initsystem(self);
	laser_Sprites_inituser(self);
}
void laser_Sprites_initsystem(laser_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		-4201673146102414989L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(laser_Sprites_struct);
	self->_walk_443 = &laser_Sprites__walk_443;
	self->animStart = &laser_Sprites_animStart;
	self->draw = &laser_Sprites_draw;
	self->__end__ = &laser_Sprites_end;
}
void laser_Sprites_enduser(laser_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void laser_Sprites_end(laser_Sprites self){
	laser_Sprites_enduser(self);
	laser_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void laser_Sprites_decrefs(laser_Sprites self){
}


void laser_Sprites_inituser(laser_Sprites self){

	self->spritesheet_722 = laser_laser_img;


}

void laser_Sprites__walk_443(laser_Sprites self){
	return;


}

void laser_Sprites_animStart(laser_Sprites self, int pos){

	self->spritesheet_722 = laser_laserbeam_img;


}

void laser_Sprites_draw(laser_Sprites self, int x, int y, int w, int h){
	image_Image tmp_kHsR_1002 = self->spritesheet_722;

	tmp_kHsR_1002->drawScaled(tmp_kHsR_1002, x,  y,  w,  h);

}


laser_Laser laser_Laser_create(){
	laser_Laser self = (laser_Laser)cbcstd_alloc(sizeof(laser_Laser_struct));
	try{
		laser_Laser_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void laser_Laser_init(laser_Laser self){
	laser_Laser_initsystem(self);
	laser_Laser_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	laser_Laser_inituser(self);
}
void laser_Laser_initsystem(laser_Laser self){
	character_Character_initsystem((character_Character)self);
	const static class_id __classid__[6] = {
		-4484401674479260050L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(laser_Laser_struct);
	self->__getvtable__ = (void*)(&laser_Laser_getvtable);
	self->onClick = &laser_Laser_onClick;
	self->draw = &laser_Laser_draw;
	self->_findPath_673 = &laser_Laser__findPath_673;
	self->_stop_925 = &laser_Laser__stop_925;
	self->interact = &laser_Laser_interact;
	self->getInfo = &laser_Laser_getInfo;
	self->_fillHelpRect_284 = &laser_Laser__fillHelpRect_284;
	self->getHelpName = &laser_Laser_getHelpName;
	self->__end__ = &laser_Laser_end;
}
void laser_Laser_enduser(laser_Laser self){
	character_Character_enduser((character_Character)self);
	return;
}
void laser_Laser_end(laser_Laser self){
	laser_Laser_enduser(self);
	laser_Laser_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void laser_Laser_init_map_MapObject(map_MapObject self, laser_Laser __self__){
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
cbcstd_Object laser_Laser_getvtable(laser_Laser self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void laser_Laser_decrefs(laser_Laser self){
}


void laser_Laser_inituser(laser_Laser self){

	self->sprites_11 = laser_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);


	self->width_945 = laser_laser_img->getWidth(laser_laser_img);


	self->height_399 = laser_laser_img->getHeight(laser_laser_img);

	self->calcOffsets(self);

	self->walk_speed_577 = 20;

	self->_resetAnimState_866(self);


}

void laser_Laser_onClick(laser_Laser self, int x, int y){

	if (self->x_405/common_FLOOR_WIDTH < DIM_X-1){
		return;
	}


	if (self->clicked(self, x,  y)){

		character_selection_sema->wait(character_selection_sema);
		if (character_selected_character != NULL){
			character_Character tmp_cast_YjBg = (character_Character)(character_selected_character);


			self->_findPath_673(self, x,  tmp_cast_YjBg->y_782);
		}


		character_selection_sema->release(character_selection_sema);

	}


}

void laser_Laser_draw(laser_Laser self){
	cbcstd_List tmp_aMIw_1020 = self->movements_662;

	character_Sprites tmp_dXab_1022 = self->sprites_11;

	if (tmp_dXab_1022->spritesheet_722 == laser_laserbeam_img and tmp_aMIw_1020->size(tmp_aMIw_1020) == 0){

		self->x_405 = -1;

		self->y_782 = -1;
		return;
	}

	character_Character_draw((character_Character)self);


}

void laser_Laser__findPath_673(laser_Laser self, int to_x, int to_y){
	if (character_selected_character == NULL){
		return;
	}

	if (not istypeof(character_selected_character, character_Character)){
		return;
	}

	int i = to_y/common_FLOOR_HEIGHT;
	int to_j = to_x/common_FLOOR_WIDTH;
	character_Character tmp_cast_jUmC = (character_Character)(character_selected_character);

	int from_j = tmp_cast_jUmC->x_405/common_FLOOR_WIDTH;
	if (from_j >= DIM_X-1){
		return;
	}


	self->to_x_969 = to_x;

	self->to_y_714 = to_y;
	character_Character tmp_cast_VtqU = (character_Character)(character_selected_character);


	self->x_405 = tmp_cast_VtqU->x_405;
	character_Character tmp_cast_4Ahg = (character_Character)(character_selected_character);


	self->y_782 = tmp_cast_4Ahg->y_782;
	{int j=from_j; for (; j<to_j; j++){
		map_MapNode* node = map_getNode(i, j);

		floor_Floor tmp_cast_InRN = (floor_Floor)(node->bg);
		floor_Floor f = tmp_cast_InRN;
		bool stop = false;
		int tmp_N32b_1033 = f->type_867;
		switch (tmp_N32b_1033){
			case floor_STONE_TYPE:{
			}

			case floor_TABLE_TYPE:{
			}

			case floor_LAKE_TYPE:{
			}

			case floor_PAUSE_TYPE:{
				stop = true;
				break;
			}

			default:{
				break;
			}

		}

		if (stop){
			break;
		}

		cbcstd_List tmp_N4Oo_1034 = self->movements_662;

		tmp_N4Oo_1034->enqueue(tmp_N4Oo_1034, cbcstd_Int_create(pathfinder_RIGHT));
	}}

	character_Sprites tmp_qbnF_1036 = self->sprites_11;

	tmp_qbnF_1036->animStart(tmp_qbnF_1036, 0);

	beam_sound->play(beam_sound);


}

void laser_Laser__stop_925(laser_Laser self){
	return;


}

void laser_Laser_interact(laser_Laser self){


	map_MapNode* node = map_getNode(self->y_782/common_FLOOR_HEIGHT, self->x_405/common_FLOOR_WIDTH);
	if (node == NULL){
		return;
	}


	map_MapObject mo = node->bg;
	floor_Floor tmp_cast_fvKR = (floor_Floor)(mo);
	floor_Floor f = tmp_cast_fvKR;
	int tmp_4egD_1041 = f->type_867;
	switch (tmp_4egD_1041){
		case floor_NORMAL_MINE_TYPE:{

			f->type_867 = floor_MINE_VISIBLE_TYPE;
			break;
		}

		case floor_MINE_VISIBLE_TYPE:{

			f->startFireAnim(f);
		}

		default:{
			break;

		}

	}


}

char** laser_Laser_getInfo(laser_Laser self){
	static char* info[7] = {"A powerful laser.","It can detect all mines ahead of","the currently selected character.","It will also destroy visible mines.","It cannot however go through","stones, lakes or other blockades.",""};
	return info;

}

void laser_Laser__fillHelpRect_284(laser_Laser self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* laser_Laser_getHelpName(laser_Laser self){
	return "Laser";

}


