#include <cbc.h>
// public globals
#include <cow.h>
// private globals
const class_id cow_Sprites__classid__ = -5678672767979443775;
const class_id cow_Cow__classid__ = 4132566991573581426;
//









image_Image cow_cow_img = NULL;

const int cow_CHAR_WIDTH = 64;
const int cow_CHAR_HEIGHT = 64;

int cow_ANIM_STATES[3] = {0, 64, 128};

const int cow_LEFT_Y = 64;
const int cow_UP_Y = 192;
const int cow_RIGHT_Y = 128;
const int cow_DOWN_Y = 0;

sound_Sound (moo);

cow_Sprites cow_Sprites_create(){
	cow_Sprites self = (cow_Sprites)cbcstd_alloc(sizeof(cow_Sprites_struct));
	try{
		cow_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cow_Sprites_init(cow_Sprites self){
	cow_Sprites_initsystem(self);
	cow_Sprites_inituser(self);
}
void cow_Sprites_initsystem(cow_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		-5678672767979443775L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cow_Sprites_struct);
	self->draw = &cow_Sprites_draw;
	self->__end__ = &cow_Sprites_end;
}
void cow_Sprites_enduser(cow_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void cow_Sprites_end(cow_Sprites self){
	cow_Sprites_enduser(self);
	cow_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cow_Sprites_decrefs(cow_Sprites self){
}


void cow_Sprites_inituser(cow_Sprites self){

	self->pos_987 = pathfinder_LEFT;

	self->rect_976.w = cow_CHAR_WIDTH;

	self->rect_976.h = cow_CHAR_HEIGHT;

	self->rect_976.y = cow_LEFT_Y;

	self->down_y_122 = cow_DOWN_Y;

	self->up_y_544 = cow_UP_Y;

	self->left_y_559 = cow_LEFT_Y;

	self->right_y_714 = cow_RIGHT_Y;

	self->max_anims_975 = 3;

	self->anim_states_811 = cow_ANIM_STATES;

	self->spritesheet_722 = cow_cow_img;

	self->default_anim_623 = 0;

	self->default_skip_walk_269 = 10;

	self->_stopAnim_681(self);


}

void cow_Sprites_draw(cow_Sprites self, int x, int y, int w, int h){
	character_Sprites_draw((character_Sprites)self, x, y, cow_CHAR_WIDTH, cow_CHAR_HEIGHT);

}


cow_Cow cow_Cow_create(){
	cow_Cow self = (cow_Cow)cbcstd_alloc(sizeof(cow_Cow_struct));
	try{
		cow_Cow_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void cow_Cow_init(cow_Cow self){
	cow_Cow_initsystem(self);
	cow_Cow_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	cow_Cow_inituser(self);
}
void cow_Cow_initsystem(cow_Cow self){
	character_Character_initsystem((character_Character)self);
	const static class_id __classid__[6] = {
		4132566991573581426L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(cow_Cow_struct);
	self->__getvtable__ = (void*)(&cow_Cow_getvtable);
	self->interact = &cow_Cow_interact;
	self->_eat_626 = &cow_Cow__eat_626;
	self->hasColided = &cow_Cow_hasColided;
	self->onClick = &cow_Cow_onClick;
	self->_findPath_673 = &cow_Cow__findPath_673;
	self->getInfo = &cow_Cow_getInfo;
	self->_fillHelpRect_284 = &cow_Cow__fillHelpRect_284;
	self->getHelpName = &cow_Cow_getHelpName;
	self->getSaveInfo = &cow_Cow_getSaveInfo;
	self->setInfoFromSave = &cow_Cow_setInfoFromSave;
	self->__end__ = &cow_Cow_end;
}
void cow_Cow_enduser(cow_Cow self){
	character_Character_enduser((character_Character)self);
	return;
}
void cow_Cow_end(cow_Cow self){
	cow_Cow_enduser(self);
	cow_Cow_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void cow_Cow_init_map_MapObject(map_MapObject self, cow_Cow __self__){
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
cbcstd_Object cow_Cow_getvtable(cow_Cow self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void cow_Cow_decrefs(cow_Cow self){
}







void cow_Cow_inituser(cow_Cow self){

	self->sprites_11 = cow_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);

	self->width_945 = cow_CHAR_WIDTH;

	self->height_399 = cow_CHAR_HEIGHT;

	self->calcOffsets(self);

	self->to_i_285 = -1;

	self->to_j_253 = -1;

	self->to_x_969 = -1;

	self->to_y_714 = -1;

	self->walk_speed_577 = 300;

	self->is_item_619 = true;

	self->walk_speed_577 = 1;

	self->_resetAnimState_866(self);


}

void cow_Cow_interact(cow_Cow self){


	map_MapNode* node = map_getNode(self->y_782/common_FLOOR_HEIGHT, self->x_405/common_FLOOR_WIDTH);

	floor_Floor tmp_cast_LyG9 = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_LyG9;

	int i = f->i_163;

	int j = f->j_639;

	if (self->hasColided(self)){

		self->_eat_626(self, i,  j);

		self->eaten_710++;

		self->to_i_285 = -1;

		self->to_j_253 = -1;

		if (self->eaten_710 > 5){

			self->x_405 = -1;

			self->y_782 = -1;

		}

	}


}

void cow_Cow__eat_626(cow_Cow self, int i, int j){
	if (i<0 or i>=DIM_Y or j<1 or j>=DIM_X-1){
		return;
	}

	map_MapNode* node = map_getNode(i, j);

	floor_Floor tmp_cast_ybaL = (floor_Floor)(node->bg);
	floor_Floor f = tmp_cast_ybaL;
	int tmp_UWjf_916 = f->type_867;
	switch (tmp_UWjf_916){
		case floor_MINE_VISIBLE_TYPE:{
		}

		case floor_NORMAL_NO_MINE_TYPE:{

			f->type_867 = floor_DESERT_TYPE;
			break;
		}

		case floor_NORMAL_MINE_TYPE:{

			f->type_867 = floor_MINE_VISIBLE_TYPE;
			break;
		}

		default: break;

	}


}

bool cow_Cow_hasColided(cow_Cow self){

	cbcstd_List tmp_HKZR_920 = self->movements_662;



	return self->to_i_285 >= 0 and self->to_j_253 >= 0 and tmp_HKZR_920->size(tmp_HKZR_920) == 0 and self->anim_453 == pathfinder_NO_ANIM;

}

void cow_Cow_onClick(cow_Cow self, int x, int y){
	if (x/common_FLOOR_WIDTH == DIM_X-1 and y/common_FLOOR_HEIGHT == DIM_Y/2){
		return;
	}


	if (self->x_405/common_FLOOR_WIDTH == DIM_X-1){

		self->is_item_619 = true;
	}


	if (self->is_item_619){

		if (self->x_405/common_FLOOR_WIDTH < DIM_X-1){
			return;
		}


		character_selection_sema->wait(character_selection_sema);
		int i = (y/common_FLOOR_HEIGHT);
		int j = (x/common_FLOOR_WIDTH);
		if (character_selected_character == self and pathfinder_canGoThere(i, j)){

			self->x_405 = j * common_FLOOR_WIDTH;

			self->y_782 = i * common_FLOOR_HEIGHT;

			self->is_item_619 = false;

			self->avoid_pickup_32 = true;

			character_selection_sema->release(character_selection_sema);
			return;
		}

		else{
			character_Sprites tmp_Pwyr_934 = self->sprites_11;

			if (tmp_Pwyr_934->clicked(tmp_Pwyr_934)){
				character_Sprites tmp_RqWu_936 = self->sprites_11;

				tmp_RqWu_936->selected_580 = false;
			}

		}


		character_selection_sema->release(character_selection_sema);
	}

	character_Character_onClick((character_Character)self, x, y);

}

void cow_Cow__findPath_673(cow_Cow self, int to_x, int to_y){

	self->to_i_285 = to_y/common_FLOOR_HEIGHT;

	self->to_j_253 = to_x/common_FLOOR_WIDTH;

	moo->play(moo);
	character_Character__findPath_673((character_Character)self, to_x, to_y);

}

char** cow_Cow_getInfo(cow_Cow self){
	static char* info[7] = {"A creature who's only goal in","life is to eat (until it gets bored).","Once placed on the map, it can","be controlled like a character.","The cow will eat wherever you tell it to,","if there's a mine there, it'll be revealed,","otherwise, it'll become a safe spot."};
	return info;

}

void cow_Cow__fillHelpRect_284(cow_Cow self, SDL_Rect* rect){
	rect->w = cow_CHAR_WIDTH;
	rect->h = cow_CHAR_HEIGHT;
	rect->y = cow_LEFT_Y;
	rect->x = cow_ANIM_STATES[0];
	

}

char* cow_Cow_getHelpName(cow_Cow self){
	return "Cow";


}

void cow_Cow_getSaveInfo(cow_Cow self, long* info){
	character_Character_getSaveInfo((character_Character)self, info);

	info[3] = self->is_item_619;


}

void cow_Cow_setInfoFromSave(cow_Cow self, long* info){
	character_Character_setInfoFromSave((character_Character)self, info);

	self->is_item_619 = info[3];

}


void cow_init(){
	cow_cow_img = image_Image_create(common_COW);
	moo = sound_Sound_create(common_COW_SOUND);

}

