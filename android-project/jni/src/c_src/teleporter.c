#include <cbc.h>
// public globals
#include <teleporter.h>
// private globals
const class_id teleporter_Sprites__classid__ = 714678348714115981;
const class_id teleporter_Teleporter__classid__ = -5435808027858520778;
//







image_Image teleporter_teleporter_img = NULL;

void teleporter_init(){
	teleporter_teleporter_img = image_Image_create(common_TELEPORTER);


}

teleporter_Sprites teleporter_Sprites_create(){
	teleporter_Sprites self = (teleporter_Sprites)cbcstd_alloc(sizeof(teleporter_Sprites_struct));
	try{
		teleporter_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void teleporter_Sprites_init(teleporter_Sprites self){
	teleporter_Sprites_initsystem(self);
	teleporter_Sprites_inituser(self);
}
void teleporter_Sprites_initsystem(teleporter_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		714678348714115981L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(teleporter_Sprites_struct);
	self->_walk_443 = &teleporter_Sprites__walk_443;
	self->draw = &teleporter_Sprites_draw;
	self->__end__ = &teleporter_Sprites_end;
}
void teleporter_Sprites_enduser(teleporter_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void teleporter_Sprites_end(teleporter_Sprites self){
	teleporter_Sprites_enduser(self);
	teleporter_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void teleporter_Sprites_decrefs(teleporter_Sprites self){
}


void teleporter_Sprites_inituser(teleporter_Sprites self){

	self->spritesheet_722 = teleporter_teleporter_img;


}

void teleporter_Sprites__walk_443(teleporter_Sprites self){
	return;


}

void teleporter_Sprites_draw(teleporter_Sprites self, int x, int y, int w, int h){

	teleporter_teleporter_img->drawScaled(teleporter_teleporter_img, x,  y,  w,  h);

}


teleporter_Teleporter teleporter_Teleporter_create(){
	teleporter_Teleporter self = (teleporter_Teleporter)cbcstd_alloc(sizeof(teleporter_Teleporter_struct));
	try{
		teleporter_Teleporter_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void teleporter_Teleporter_init(teleporter_Teleporter self){
	teleporter_Teleporter_initsystem(self);
	teleporter_Teleporter_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	teleporter_Teleporter_inituser(self);
}
void teleporter_Teleporter_initsystem(teleporter_Teleporter self){
	character_Character_initsystem((character_Character)self);
	const static class_id __classid__[6] = {
		-5435808027858520778L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(teleporter_Teleporter_struct);
	self->__getvtable__ = (void*)(&teleporter_Teleporter_getvtable);
	self->draw = &teleporter_Teleporter_draw;
	self->onClick = &teleporter_Teleporter_onClick;
	self->_fillMapNodes_531 = &teleporter_Teleporter__fillMapNodes_531;
	self->_setMapNode_448 = &teleporter_Teleporter__setMapNode_448;
	self->_restoreMapNodes_185 = &teleporter_Teleporter__restoreMapNodes_185;
	self->restoreMap = &teleporter_Teleporter_restoreMap;
	self->_inRange_8 = &teleporter_Teleporter__inRange_8;
	self->interact = &teleporter_Teleporter_interact;
	self->getInfo = &teleporter_Teleporter_getInfo;
	self->_fillHelpRect_284 = &teleporter_Teleporter__fillHelpRect_284;
	self->getHelpName = &teleporter_Teleporter_getHelpName;
	self->__end__ = &teleporter_Teleporter_end;
}
void teleporter_Teleporter_enduser(teleporter_Teleporter self){
	character_Character_enduser((character_Character)self);
	return;
}
void teleporter_Teleporter_end(teleporter_Teleporter self){
	teleporter_Teleporter_enduser(self);
	teleporter_Teleporter_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void teleporter_Teleporter_init_map_MapObject(map_MapObject self, teleporter_Teleporter __self__){
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
cbcstd_Object teleporter_Teleporter_getvtable(teleporter_Teleporter self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void teleporter_Teleporter_decrefs(teleporter_Teleporter self){
}





void teleporter_Teleporter_inituser(teleporter_Teleporter self){

	self->sprites_11 = teleporter_Sprites_create();

	self->movements_662 = cbcstd_List_create();

	self->move_sema_518 = cbcstd_Semaphore_create(1);


	self->width_945 = teleporter_teleporter_img->getWidth(teleporter_teleporter_img);


	self->height_399 = teleporter_teleporter_img->getHeight(teleporter_teleporter_img);

	self->calcOffsets(self);

	self->walk_speed_577 = 5;

	self->_resetAnimState_866(self);


}

void teleporter_Teleporter_draw(teleporter_Teleporter self){






	character_Sprites tmp_SFql_793 = self->sprites_11;

	tmp_SFql_793->draw(tmp_SFql_793, self->x_405+self->x_offset_475,  self->y_782+self->y_offset_563,  self->width_945,  self->height_399);


}

void teleporter_Teleporter_onClick(teleporter_Teleporter self, int x, int y){

	if (self->x_405/common_FLOOR_WIDTH < DIM_X-1){
		return;
	}


	if (self->clicked(self, x,  y)){

		if (self->to_transport_606 == NULL){

			character_selection_sema->wait(character_selection_sema);
			if (character_selected_character == NULL or character_selected_character == self){
				character_selected_character = NULL;

				character_selection_sema->release(character_selection_sema);
				return;
			}

			character_Character to_transport = character_selected_character;
			cbcstd_List tmp_jS3z_800 = to_transport->movements_662;


			if (to_transport->anim_453 != pathfinder_NO_ANIM or tmp_jS3z_800->size(tmp_jS3z_800) > 0){

				character_selection_sema->release(character_selection_sema);
				return;
			}

			if (classid(to_transport) != character_Character__classid__){

				character_selection_sema->release(character_selection_sema);
				return;
			}


			self->to_transport_606 = to_transport;
			int i, j;
			character_Character tmp_v5Rv_806 = self->to_transport_606;

			tmp_v5Rv_806->updatePosition(tmp_v5Rv_806, &i,  &j);

			self->_fillMapNodes_531(self, i,  j);
			character_selected_character = self;

			character_selection_sema->release(character_selection_sema);
		}

		else{

			self->to_transport_606 = NULL;

			self->_restoreMapNodes_185(self);
		}

	}

	else{

		character_selection_sema->wait(character_selection_sema);
		if (character_selected_character == self){

			if (self->_inRange_8(self, x,  y)){
				character_Character tmp_kbo1_814 = self->to_transport_606;

				tmp_kbo1_814->setCoordinates(tmp_kbo1_814, y/common_FLOOR_HEIGHT,  x/common_FLOOR_WIDTH);

				self->x_405 = -1;

				self->y_782 = -1;
			}


			self->to_transport_606 = NULL;

			self->_restoreMapNodes_185(self);
			character_selected_character = NULL;
		}

		else{

			if (self->to_transport_606 != NULL){

				self->to_transport_606 = NULL;

				self->_restoreMapNodes_185(self);
			}

		}


		character_selection_sema->release(character_selection_sema);

	}


}

void teleporter_Teleporter__fillMapNodes_531(teleporter_Teleporter self, int i, int j){
	teleporter_MapNode_Data to_check[24] = {{i+1, j, 0}, {i-1, j, 0}, {i, j-1, 0}, {i, j+1, 0},{i+2, j, 0}, {i-2, j, 0}, {i, j-2, 0}, {i, j+2, 0},{i+2, j+2, 0}, {i+2, j-2, 0}, {i-2, j+2, 0}, {i-2, j-2, 0},{i+2, j+1, 0}, {i+2, j-1, 0}, {i-2, j+1, 0}, {i-2, j-1, 0},{i+1, j+2, 0}, {i+1, j-2, 0}, {i-1, j+2, 0}, {i-1, j-2, 0},{i+1, j+1, 0}, {i+1, j-1, 0}, {i-1, j+1, 0}, {i-1, j-1, 0}};
	
	{int x = 0; for (; x < 24; x++){

		int i = to_check[x].i;

		int j = to_check[x].j;
		if (i < 0 or j < 1){
			continue;
		}

		if (i >= DIM_Y or j >= DIM_X-1){
			continue;
		}

		map_MapNode* node = map_getNode(i, j);

		floor_Floor tmp_cast_sQ9J = (floor_Floor)(node->bg);
		floor_Floor f = tmp_cast_sQ9J;
		


		if (f->type_867 == floor_STONE_TYPE or f->type_867 == floor_LAKE_TYPE){
			continue;
		}

		teleporter_MapNode_Data* to_write = &(self->map_nodes_713[self->available_nodes_669]);

		to_write->i = i;

		to_write->j = j;


		to_write->type = f->type_867;

		self->available_nodes_669++;

		floor_Floor tmp_cast_WL1a = (floor_Floor)(node->bg);

		self->_setMapNode_448(self, tmp_cast_WL1a);

	}}


}

void teleporter_Teleporter__setMapNode_448(teleporter_Teleporter self, floor_Floor f){

	f->type_867 = floor_TELEPORT_TYPE;


}

void teleporter_Teleporter__restoreMapNodes_185(teleporter_Teleporter self){

	{int x=0; for (; x<self->available_nodes_669; x++){
		int i = self->map_nodes_713[x].i;
		int j = self->map_nodes_713[x].j;
		floor_TerrainType type = self->map_nodes_713[x].type;
		floor_Floor tmp_cast_Po34 = (floor_Floor)(map_getNode(i, j)->bg);
		floor_Floor f = tmp_cast_Po34;

		f->type_867 = type;
	}}


	self->available_nodes_669 = 0;


}

void teleporter_Teleporter_restoreMap(teleporter_Teleporter self){

	if (self->available_nodes_669){

		self->_restoreMapNodes_185(self);

	}


}

bool teleporter_Teleporter__inRange_8(teleporter_Teleporter self, int x, int y){
	int i = y/common_FLOOR_HEIGHT;
	int j = x/common_FLOOR_WIDTH;

	{int x=0; for (; x<self->available_nodes_669; x++){
		if (self->map_nodes_713[x].i == i and self->map_nodes_713[x].j == j){
			return true;
		}

	}}

	return false;


}

void teleporter_Teleporter_interact(teleporter_Teleporter self){
	return;

}

char** teleporter_Teleporter_getInfo(teleporter_Teleporter self){
	static char* info[7] = {"Straight out of a sci-fi movie.","As the name implies","the teleporter will","automatically move the","selected character","to a spot nearby that","you choose."};
	return info;

}

void teleporter_Teleporter__fillHelpRect_284(teleporter_Teleporter self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* teleporter_Teleporter_getHelpName(teleporter_Teleporter self){
	return "Teleporter";

}


