#include <cbc.h>
// public globals
#include <character.h>
// private globals
const class_id character_Sprites__classid__ = -5848076223921087973;
const class_id character_Character__classid__ = 5968600321633189670;
//











const int character_DOWN_Y = 0;
const int character_UP_Y = 118;
const int character_LEFT_Y = 237;
const int character_RIGHT_Y = 355;



int character_ANIM_STATES[3] = {0, 73, 146};

const int character_CHAR_WIDTH = 48;
const int character_CHAR_HEIGHT = 105;

const int character_MAX_POS = 4;
const int character_MAX_WALK_ANIM = 2;
const int character_WALK_SPEED = 3;

image_Image sprites;
void* character_selected_character = NULL;
cbcstd_Semaphore character_selection_sema = NULL;
int character_n_characters = 0;
void* character_safe_character = NULL;
cbcstd_Semaphore character_characters_sema = NULL;

void character_init(){
	character_selection_sema = cbcstd_Semaphore_create(1);
	character_characters_sema = cbcstd_Semaphore_create(1);
	sprites = image_Image_create(common_CHARACTER);


}

void character_reinit(){
	character_n_characters = 0;
	character_safe_character = NULL;
	character_selected_character = NULL;


}

character_Sprites character_Sprites_create(){
	character_Sprites self = (character_Sprites)cbcstd_alloc(sizeof(character_Sprites_struct));
	try{
		character_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void character_Sprites_init(character_Sprites self){
	character_Sprites_initsystem(self);
	character_Sprites_inituser(self);
}
void character_Sprites_initsystem(character_Sprites self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(character_Sprites_struct);
	self->clicked = &character_Sprites_clicked;
	self->animStart = &character_Sprites_animStart;
	self->animEnd = &character_Sprites_animEnd;
	self->_stopAnim_681 = &character_Sprites__stopAnim_681;
	self->_walk_443 = &character_Sprites__walk_443;
	self->draw = &character_Sprites_draw;
	self->__end__ = &character_Sprites_end;
}
void character_Sprites_enduser(character_Sprites self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void character_Sprites_end(character_Sprites self){
	character_Sprites_enduser(self);
	character_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void character_Sprites_decrefs(character_Sprites self){
}

















	
void character_Sprites_inituser(character_Sprites self){

	self->pos_987 = pathfinder_DOWN;

	self->rect_976.w = character_CHAR_WIDTH;

	self->rect_976.h = character_CHAR_HEIGHT;

	self->rect_976.y = character_DOWN_Y;

	self->down_y_122 = character_DOWN_Y;

	self->up_y_544 = character_UP_Y;

	self->left_y_559 = character_LEFT_Y;

	self->right_y_714 = character_RIGHT_Y;

	self->max_anims_975 = 3;

	self->anim_states_811 = character_ANIM_STATES;

	self->spritesheet_722 = sprites;

	self->default_anim_623 = 1;

	self->last_anim_124 = 1;

	self->default_skip_walk_269 = 7;

	self->_stopAnim_681(self);


}

bool character_Sprites_clicked(character_Sprites self){

	return self->selected_580;


}

void character_Sprites_animStart(character_Sprites self, int pos){

	self->animating_559 = true;

	self->pos_987 = pos;


	self->walk_anim_287 = self->last_anim_124;


}

void character_Sprites_animEnd(character_Sprites self){

	self->animating_559 = false;


}

void character_Sprites__stopAnim_681(character_Sprites self){


	self->last_anim_124 = self->walk_anim_287;


	self->walk_anim_287 = self->default_anim_623;



	self->rect_976.x = self->anim_states_811[self->walk_anim_287];


}

void character_Sprites__walk_443(character_Sprites self){

	if (not self->skip_walk_829){



		if (self->walk_anim_287 < self->max_anims_975-1) self->walk_anim_287++;

		else self->walk_anim_287 = 0;
		int tmp_We28_320 = self->pos_987;
		switch (tmp_We28_320){
			case pathfinder_UP:{


				self->rect_976.y = self->up_y_544;
				break;
			}

			case pathfinder_DOWN:{


				self->rect_976.y = self->down_y_122;
				break;
			}

			case pathfinder_LEFT:{


				self->rect_976.y = self->left_y_559;
				break;
			}

			case pathfinder_RIGHT:{


				self->rect_976.y = self->right_y_714;
				break;
			}

			default: break;
		}



		self->skip_walk_829 = self->default_skip_walk_269;



		self->rect_976.x = self->anim_states_811[self->walk_anim_287];
	}

	else{

		self->skip_walk_829--;

	}


}

void character_Sprites_draw(character_Sprites self, int x, int y, int w, int h){

	if (self->animating_559){

		self->_walk_443(self);
	}

	else{

		self->_stopAnim_681(self);
	}


	if (self->selected_580){

		map_selected_img->drawScaled(map_selected_img, x-5,  y-5,  w+10,  h+10);
	}


	image_Image tmp_gvSB_341 = self->spritesheet_722;

	tmp_gvSB_341->drawClippedScaled(tmp_gvSB_341, x,  y,  w,  h,  &(self->rect_976));

}


character_Character character_Character_create(){
	character_Character self = (character_Character)cbcstd_alloc(sizeof(character_Character_struct));
	try{
		character_Character_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void character_Character_init(character_Character self){
	character_Character_initsystem(self);
	character_Character_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	character_Character_inituser(self);
}
void character_Character_initsystem(character_Character self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[4] = {
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(character_Character_struct);
	self->__getvtable__ = (void*)(&character_Character_getvtable);
	self->calcOffsets = &character_Character_calcOffsets;
	self->_isSelected_254 = &character_Character__isSelected_254;
	self->onClick = &character_Character_onClick;
	self->_canGoThere_896 = &character_Character__canGoThere_896;
	self->_findPath_673 = &character_Character__findPath_673;
	self->clicked = &character_Character_clicked;
	self->_resetAnimState_866 = &character_Character__resetAnimState_866;
	self->moveUp = &character_Character_moveUp;
	self->moveDown = &character_Character_moveDown;
	self->moveLeft = &character_Character_moveLeft;
	self->moveRight = &character_Character_moveRight;
	self->_stop_925 = &character_Character__stop_925;
	self->draw = &character_Character_draw;
	self->addItem = &character_Character_addItem;
	self->interact = &character_Character_interact;
	self->setCoordinates = &character_Character_setCoordinates;
	self->updatePosition = &character_Character_updatePosition;
	self->getSaveInfo = &character_Character_getSaveInfo;
	self->setInfoFromSave = &character_Character_setInfoFromSave;
	self->cleanUp = &character_Character_cleanUp;
	self->waitAnimEnd = &character_Character_waitAnimEnd;
	self->getInfo = &character_Character_getInfo;
	self->drawHelpSprite = &character_Character_drawHelpSprite;
	self->_fillHelpRect_284 = &character_Character__fillHelpRect_284;
	self->_drawHelpSprite_463 = &character_Character__drawHelpSprite_463;
	self->getHelpName = &character_Character_getHelpName;
	self->__end__ = &character_Character_end;
}
void character_Character_enduser(character_Character self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void character_Character_end(character_Character self){
	character_Character_enduser(self);
	character_Character_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void character_Character_init_map_MapObject(map_MapObject self, character_Character __self__){
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
cbcstd_Object character_Character_getvtable(character_Character self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void character_Character_decrefs(character_Character self){
}




















	
void character_Character_inituser(character_Character self){

	self->sprites_11 = character_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);

	self->to_x_969 = -1;

	self->to_y_714 = -1;

	self->width_945 = common_FLOOR_WIDTH/4 + 10;

	self->height_399 = common_FLOOR_HEIGHT-30;

	self->calcOffsets(self);

	self->walk_speed_577 = character_WALK_SPEED;

	self->_resetAnimState_866(self);
	character_n_characters++;

}

void character_Character_calcOffsets(character_Character self){


	self->x_offset_475 = (common_FLOOR_WIDTH-self->width_945)/2;


	self->y_offset_563 = (common_FLOOR_HEIGHT-self->height_399)/2;

}

bool character_Character__isSelected_254(character_Character self){

	character_selection_sema->wait(character_selection_sema);
	bool ret = character_selected_character == self;

	character_selection_sema->release(character_selection_sema);
	return ret;

}

void character_Character_onClick(character_Character self, int x, int y){

	if (self->clicked(self, x,  y)){

		character_selection_sema->wait(character_selection_sema);
		if (character_selected_character != self){
			character_selected_character = self;
			character_Sprites tmp_JKVE_361 = self->sprites_11;

			tmp_JKVE_361->selected_580 = true;
		}

		else{
			character_selected_character = NULL;
			character_Sprites tmp_kjvS_363 = self->sprites_11;

			tmp_kjvS_363->selected_580 = false;
		}


		character_selection_sema->release(character_selection_sema);
		return;
	}


	character_Sprites tmp_RXqN_367 = self->sprites_11;

	tmp_RXqN_367->selected_580 = self->_isSelected_254(self);

	character_Sprites tmp_Bzvw_370 = self->sprites_11;

	if (tmp_Bzvw_370->selected_580 and self->_canGoThere_896(self, x,  y)){
		cbcstd_Semaphore tmp_q54L_372 = self->move_sema_518;

		tmp_q54L_372->wait(tmp_q54L_372);
		character_Sprites tmp_mxEk_374 = self->sprites_11;

		if (tmp_mxEk_374->clicked(tmp_mxEk_374)){

			cbcstd_List tmp_Ot6t_377 = self->movements_662;

			if (tmp_Ot6t_377->size(tmp_Ot6t_377) == 0 and self->anim_453 == pathfinder_NO_ANIM){

				self->_findPath_673(self, x,  y);
			}

			else{
				if (istypeof(self, character_Character)){
					cbcstd_List tmp_89MS_380 = self->movements_662;

					tmp_89MS_380->clear(tmp_89MS_380);
				}

			}

		}

		cbcstd_Semaphore tmp_ghQG_382 = self->move_sema_518;

		tmp_ghQG_382->release(tmp_ghQG_382);

	}


}

bool character_Character__canGoThere_896(character_Character self, int x, int y){
	return pathfinder_canGoThere(y/common_FLOOR_HEIGHT, x/common_FLOOR_WIDTH);


}

void character_Character__findPath_673(character_Character self, int to_x, int to_y){

	self->to_x_969 = to_x;

	self->to_y_714 = to_y;



	pathfinder_findPath(self->x_405, self->y_782, to_x, to_y, self->movements_662);
	cbcstd_List tmp_RHfh_389 = self->movements_662;

	if (tmp_RHfh_389->size(tmp_RHfh_389) == 0){
		character_Sprites tmp_NZIC_391 = self->sprites_11;

		tmp_NZIC_391->selected_580 = false;

		character_selection_sema->wait(character_selection_sema);
		if (character_selected_character == self){
			map_MapNode* node = map_getNode(to_y/common_FLOOR_HEIGHT, to_x/common_FLOOR_WIDTH);
			if (node != NULL){

				floor_Floor tmp_cast_aztS = (floor_Floor)(node->bg);
				floor_Floor f = tmp_cast_aztS;

				if (f->type_867 != floor_TABLE_TYPE){
					character_selected_character = NULL;
				}

			}

		}


		character_selection_sema->release(character_selection_sema);

	}


}

bool character_Character_clicked(character_Character self, int x, int y){




	return map_clickedAround(self->x_405+self->x_offset_475, self->y_782+self->y_offset_563);


}

void character_Character__resetAnimState_866(character_Character self){

	self->anim_state_x_214 = 0;

	self->anim_state_y_697 = 0;

	self->anim_453 = pathfinder_NO_ANIM;
	character_Sprites tmp_1gNz_403 = self->sprites_11;

	tmp_1gNz_403->animEnd(tmp_1gNz_403);


}

void character_Character_moveUp(character_Character self){

	if (self->anim_453 == pathfinder_NO_ANIM){

		self->_resetAnimState_866(self);
		character_Sprites tmp_TiMR_407 = self->sprites_11;

		tmp_TiMR_407->animStart(tmp_TiMR_407, pathfinder_UP);

		self->anim_453 = pathfinder_UP;

	}


}

void character_Character_moveDown(character_Character self){

	if (self->anim_453 == pathfinder_NO_ANIM){

		self->_resetAnimState_866(self);
		character_Sprites tmp_Prr5_412 = self->sprites_11;

		tmp_Prr5_412->animStart(tmp_Prr5_412, pathfinder_DOWN);

		self->anim_453 = pathfinder_DOWN;

	}


}

void character_Character_moveLeft(character_Character self){

	if (self->anim_453 == pathfinder_NO_ANIM){

		self->_resetAnimState_866(self);
		character_Sprites tmp_6OhQ_417 = self->sprites_11;

		tmp_6OhQ_417->animStart(tmp_6OhQ_417, pathfinder_LEFT);

		self->anim_453 = pathfinder_LEFT;

	}


}

void character_Character_moveRight(character_Character self){

	if (self->anim_453 == pathfinder_NO_ANIM){

		self->_resetAnimState_866(self);
		character_Sprites tmp_yyV9_422 = self->sprites_11;

		tmp_yyV9_422->animStart(tmp_yyV9_422, pathfinder_RIGHT);

		self->anim_453 = pathfinder_RIGHT;

	}


}

void character_Character__stop_925(character_Character self){
	

	character_selection_sema->wait(character_selection_sema);
	character_Sprites tmp_FUI0_426 = self->sprites_11;

	if (character_selected_character != self and tmp_FUI0_426->clicked(tmp_FUI0_426) or character_safe_character != NULL){
		character_Sprites tmp_2T2Q_428 = self->sprites_11;

		tmp_2T2Q_428->selected_580 = false;
		cbcstd_Semaphore tmp_itGF_430 = self->move_sema_518;

		tmp_itGF_430->wait(tmp_itGF_430);
		cbcstd_List tmp_sWBR_432 = self->movements_662;

		if (tmp_sWBR_432->size(tmp_sWBR_432) > 0){
			cbcstd_List tmp_oUMm_434 = self->movements_662;

			tmp_oUMm_434->clear(tmp_oUMm_434);

			self->_resetAnimState_866(self);
		}

		cbcstd_Semaphore tmp_cgay_437 = self->move_sema_518;

		tmp_cgay_437->release(tmp_cgay_437);
	}


	character_selection_sema->release(character_selection_sema);


}

void character_Character_draw(character_Character self){



	int x = self->x_405+self->anim_state_x_214+self->x_offset_475;



	int y = self->y_782+self->anim_state_y_697+self->y_offset_563;


	character_Sprites tmp_fbvj_448 = self->sprites_11;

	tmp_fbvj_448->draw(tmp_fbvj_448, x,  y,  self->width_945,  self->height_399);

	self->_stop_925(self);
	int tmp_4efG_451 = self->anim_453;
	switch (tmp_4efG_451){
		case pathfinder_LEFT:{

			if (self->anim_state_x_214 > -common_FLOOR_WIDTH){


				self->anim_state_x_214 -= self->walk_speed_577;
			}

			else{

				self->x_405 -= common_FLOOR_WIDTH;

				self->_resetAnimState_866(self);
			}

			break;
		}

		case pathfinder_RIGHT:{

			if (self->anim_state_x_214 < common_FLOOR_WIDTH){


				self->anim_state_x_214 += self->walk_speed_577;
			}

			else{

				self->x_405 += common_FLOOR_WIDTH;

				self->_resetAnimState_866(self);
			}

			break;
		}

		case pathfinder_UP:{

			if (self->anim_state_y_697 > -common_FLOOR_HEIGHT){


				self->anim_state_y_697 -= self->walk_speed_577;
			}

			else{

				self->y_782 -= common_FLOOR_HEIGHT;

				self->_resetAnimState_866(self);
			}

			break;
		}

		case pathfinder_DOWN:{

			if (self->anim_state_y_697 < common_FLOOR_HEIGHT){


				self->anim_state_y_697 += self->walk_speed_577;
			}

			else{

				self->y_782 += common_FLOOR_HEIGHT;

				self->_resetAnimState_866(self);
			}

			break;
		}

		default:{
			cbcstd_Semaphore tmp_ShH3_472 = self->move_sema_518;

			tmp_ShH3_472->wait(tmp_ShH3_472);
			cbcstd_List tmp_jFR1_474 = self->movements_662;

			if (tmp_jFR1_474->size(tmp_jFR1_474) > 0){
				cbcstd_List tmp_0FyQ_476 = self->movements_662;;

				cbcstd_Int tmp_cast_JOJm = (cbcstd_Int)(tmp_0FyQ_476->pop(tmp_0FyQ_476));
				cbcstd_Int moveObject = tmp_cast_JOJm;

				int move = moveObject->value_527;
				cbcstd_destroyObj((cbcstd_Object*)&(moveObject));
				switch (move){

					case pathfinder_UP: self->moveUp(self);
					 break;

					case pathfinder_DOWN: self->moveDown(self);
					 break;

					case pathfinder_LEFT: self->moveLeft(self);
					 break;

					case pathfinder_RIGHT: self->moveRight(self);
					 break;

					default: self->_resetAnimState_866(self);
					 break;
				}

			}

			else{

				self->to_x_969 = -1;

				self->to_y_714 = -1;
			}

			cbcstd_Semaphore tmp_EG8W_486 = self->move_sema_518;

			tmp_EG8W_486->release(tmp_EG8W_486);
			break;
		}

	}


}

bool character_Character_addItem(character_Character self, cbcstd_List source_list, map_MapObject o){
	int j = DIM_X-1;
	int new_i = -1;
	cbcstd_List dest_list = source_list;
	character_Character tmp_cast_2IOH = (character_Character)(o);
	character_Character c = tmp_cast_2IOH;

	if (istypeof(c, character_Character) or c == self or c->avoid_pickup_32){

		dest_list->push(dest_list, o);
		return false;
	}

	{int i=0; for (; i<DIM_Y; i++){
		if (i == DIM_Y/2){
			continue;
		}

		map_MapNode* node = map_getNode(i, j);

		cbcstd_List to_push = node->objects;

		if (to_push->size(to_push) == 0){
			if (new_i < 0){
				dest_list = to_push;
				new_i = i;
			}

			continue;
		}


		map_MapObject tmp_cast_Tj5u = (map_MapObject)(to_push->pop(to_push));
		map_MapObject mo = tmp_cast_Tj5u;

		to_push->push(to_push, mo);
		character_Character tmp_cast_XBLF = (character_Character)(mo);
		character_Character c1 = tmp_cast_XBLF;
		if (classid(c1) == classid(c)){
			new_i = i;
			dest_list = to_push;
			break;
		}

	}}

	if (new_i >= 0 and dest_list != NULL){

		CBC_LOW_CAST(o, map_MapObject)->setCoordinates(o, new_i,  j);

		dest_list->push(dest_list, o);
		return true;
	}


	dest_list->push(dest_list, o);
	return false;

}

void character_Character_interact(character_Character self){


	map_MapNode* node = map_getNode(self->y_782/common_FLOOR_HEIGHT, self->x_405/common_FLOOR_WIDTH);
	if (node == NULL){
		return;
	}


	map_MapObject mo = node->bg;
	floor_Floor tmp_cast_nVN2 = (floor_Floor)(mo);
	floor_Floor f = tmp_cast_nVN2;

	int type = f->type_867;

	cbcstd_List to_push = node->objects;

	node->objects = cbcstd_List_create();
	{map_MapObject o=NULL;CBC_FOREACH(to_push, o){
		if (o == self){
			continue;
		}



		self->addItem(self, node->objects,  o);
	}}



	node->objects->enqueue(node->objects, self);
	cbcstd_destroyObj((cbcstd_Object*)&(to_push));
	switch (type){
		case floor_NORMAL_MINE_TYPE:{
		}

		case floor_MINE_VISIBLE_TYPE:{

			if (self->lives_836 == 0){

				self->x_405 = -1;

				self->y_782 = -1;

				character_characters_sema->wait(character_characters_sema);
				character_n_characters--;

				character_characters_sema->release(character_characters_sema);
			}

			else{

				self->lives_836--;
			}


			f->startFireAnim(f);
			return;
			break;
		}

		case floor_NORMAL_NO_MINE_TYPE:{
		}

		case floor_DESERT_TYPE:{
		}

		case floor_START_TYPE:{
			break;
		}

		case floor_TABLE_TYPE:{
		}

		case floor_STONE_TYPE:{
		}

		case floor_LAKE_TYPE:{
			cthrow((cbcstd_Exception)(cbcstd_SystemError_create("There was an error: the character is in an uncontrolled area\n")));
			break;
		}

		case floor_EXIT_TYPE:{
			if (character_safe_character == NULL){

				self->x_405 = -1;

				self->y_782 = -1;

				character_characters_sema->wait(character_characters_sema);
				character_n_characters--;
				character_safe_character = self;

				character_characters_sema->release(character_characters_sema);
				return;
			}

			break;
		}

		default:{
			cthrow((cbcstd_Exception)(cbcstd_SystemError_create("ERROR: The character is in an unknown terrain type")));
			break;

		}

	}


}

void character_Character_setCoordinates(character_Character self, int i, int j){

	self->x_405 = j*common_FLOOR_WIDTH;

	self->y_782 = i*common_FLOOR_HEIGHT;


}

void character_Character_updatePosition(character_Character self, int* i, int* j){


	if (self->y_782 < 0 or self->x_405 < 0){
		(*i) = -1;
		(*j) = -1;
	}

	else{

		(*i) = self->y_782/common_FLOOR_HEIGHT;

		(*j) = self->x_405/common_FLOOR_WIDTH;
	}


}

void character_Character_getSaveInfo(character_Character self, long* info){

	info[0] = self->lives_836;

	info[1] = self->to_x_969;

	info[2] = self->to_y_714;


}

void character_Character_setInfoFromSave(character_Character self, long* info){

	self->lives_836 = info[0];

	self->to_x_969 = info[1];

	self->to_y_714 = info[2];


	if (self->to_x_969 >= 0 and self->to_y_714 >= 0){



		self->_findPath_673(self, self->to_x_969,  self->to_y_714);

	}


}

void character_Character_cleanUp(character_Character self){
	return;


}

void character_Character_waitAnimEnd(character_Character self){

	while (self->anim_453 != pathfinder_NO_ANIM){
		SDL_Delay(0);

	}


}

char** character_Character_getInfo(character_Character self){
	static char* info[7] = {"This is your character.","Your goal is to take one of","these characters to the exit.","If you loose all your characters,","the game is over.","Click on a character to select it,","then click on where you want it to move."};
	return info;

}

void character_Character_drawHelpSprite(character_Character self, int x, int y){
	SDL_Rect rect;

	self->_fillHelpRect_284(self, &rect);

	self->_drawHelpSprite_463(self, x,  y,  &rect);


}

void character_Character__fillHelpRect_284(character_Character self, SDL_Rect* rect){
	rect->w = character_CHAR_WIDTH;
	rect->h = character_CHAR_HEIGHT;
	rect->y = character_DOWN_Y;
	rect->x = character_ANIM_STATES[1];


}

void character_Character__drawHelpSprite_463(character_Character self, int x, int y, SDL_Rect* rect){

	map_help_box->draw(map_help_box, x,  y);




	character_Sprites tmp_VcB4_537 = self->sprites_11;
	image_Image tmp_E1Za_538 = tmp_VcB4_537->spritesheet_722;

	tmp_E1Za_538->drawClippedScaled(tmp_E1Za_538, x+self->x_offset_475,  y+self->y_offset_563,  self->width_945,  self->height_399,  rect);


}

char* character_Character_getHelpName(character_Character self){
	return "Character";

}


