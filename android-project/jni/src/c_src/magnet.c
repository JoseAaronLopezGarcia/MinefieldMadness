#include <cbc.h>
// public globals
#include <magnet.h>
// private globals
const class_id magnet_Sprites__classid__ = 2208387474408671075;
const class_id magnet_Magnet__classid__ = 7469854575603603174;
//








image_Image magnet_magnet_img = NULL;

void magnet_init(){
	magnet_magnet_img = image_Image_create(common_MAGNET);


}

magnet_Sprites magnet_Sprites_create(){
	magnet_Sprites self = (magnet_Sprites)cbcstd_alloc(sizeof(magnet_Sprites_struct));
	try{
		magnet_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void magnet_Sprites_init(magnet_Sprites self){
	magnet_Sprites_initsystem(self);
	magnet_Sprites_inituser(self);
}
void magnet_Sprites_initsystem(magnet_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		2208387474408671075L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(magnet_Sprites_struct);
	self->_walk_443 = &magnet_Sprites__walk_443;
	self->draw = &magnet_Sprites_draw;
	self->__end__ = &magnet_Sprites_end;
}
void magnet_Sprites_enduser(magnet_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void magnet_Sprites_end(magnet_Sprites self){
	magnet_Sprites_enduser(self);
	magnet_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void magnet_Sprites_decrefs(magnet_Sprites self){
}


void magnet_Sprites_inituser(magnet_Sprites self){

	self->spritesheet_722 = magnet_magnet_img;


}

void magnet_Sprites__walk_443(magnet_Sprites self){
	return;


}

void magnet_Sprites_draw(magnet_Sprites self, int x, int y, int w, int h){

	if (self->selected_580){

		map_selected_img->drawScaled(map_selected_img, x-5,  y-5,  w+10,  h+10);
	}


	magnet_magnet_img->drawScaled(magnet_magnet_img, x,  y,  w,  h);

}


magnet_Magnet magnet_Magnet_create(){
	magnet_Magnet self = (magnet_Magnet)cbcstd_alloc(sizeof(magnet_Magnet_struct));
	try{
		magnet_Magnet_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void magnet_Magnet_init(magnet_Magnet self){
	magnet_Magnet_initsystem(self);
	magnet_Magnet_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	magnet_Magnet_inituser(self);
}
void magnet_Magnet_initsystem(magnet_Magnet self){
	teleporter_Teleporter_initsystem((teleporter_Teleporter)self);
	const static class_id __classid__[8] = {
		7469854575603603174L,
		-5435808027858520778L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(magnet_Magnet_struct);
	self->__getvtable__ = (void*)(&magnet_Magnet_getvtable);
	self->draw = &magnet_Magnet_draw;
	self->onClick = &magnet_Magnet_onClick;
	self->_findPath_673 = &magnet_Magnet__findPath_673;
	self->_setMapNode_448 = &magnet_Magnet__setMapNode_448;
	self->_fillMapNodes_531 = &magnet_Magnet__fillMapNodes_531;
	self->_restoreMapNodes_185 = &magnet_Magnet__restoreMapNodes_185;
	self->_inRange_8 = &magnet_Magnet__inRange_8;
	self->getInfo = &magnet_Magnet_getInfo;
	self->_fillHelpRect_284 = &magnet_Magnet__fillHelpRect_284;
	self->getHelpName = &magnet_Magnet_getHelpName;
	self->__end__ = &magnet_Magnet_end;
}
void magnet_Magnet_enduser(magnet_Magnet self){
	teleporter_Teleporter_enduser((teleporter_Teleporter)self);
	return;
}
void magnet_Magnet_end(magnet_Magnet self){
	magnet_Magnet_enduser(self);
	magnet_Magnet_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void magnet_Magnet_init_map_MapObject(map_MapObject self, magnet_Magnet __self__){
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
cbcstd_Object magnet_Magnet_getvtable(magnet_Magnet self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void magnet_Magnet_decrefs(magnet_Magnet self){
}




void magnet_Magnet_inituser(magnet_Magnet self){
	teleporter_Teleporter_inituser((teleporter_Teleporter)self);

	teleporter_Sprites aux = self->sprites_11;

	self->sprites_11 = magnet_Sprites_create();
	cbcstd_destroyObj((cbcstd_Object*)&(aux));

	self->used_254 = false;

}

void magnet_Magnet_draw(magnet_Magnet self){


	self->used_254 = self->x_405 < (DIM_X-1)*common_FLOOR_WIDTH;
	character_Sprites tmp_GDX6_982 = self->sprites_11;


	if (self->used_254 and tmp_GDX6_982->clicked(tmp_GDX6_982)){
		character_Sprites tmp_zbUU_985 = self->sprites_11;

		tmp_zbUU_985->selected_580 = false;
	}

	teleporter_Teleporter_draw((teleporter_Teleporter)self);

}

void magnet_Magnet_onClick(magnet_Magnet self, int x, int y){

	if (not self->used_254){
		character_Character_onClick((character_Character)self, x, y);

	}


}

void magnet_Magnet__findPath_673(magnet_Magnet self, int to_x, int to_y){
	int i = to_y/common_FLOOR_HEIGHT;
	int j = to_x/common_FLOOR_WIDTH;
	
	if (j < 1 or j >= DIM_X-1){
		return;
	
	}


	self->x_405 = j * common_FLOOR_WIDTH;

	self->y_782 = i * common_FLOOR_HEIGHT;

	self->_fillMapNodes_531(self, i,  j);

	self->used_254 = true;
	floor_Floor tmp_cast_qmJX = (floor_Floor)(map_getNode(i, j)->bg);
	floor_Floor f = tmp_cast_qmJX;

	f->type_867 = floor_MINE_VISIBLE_TYPE;

}

void magnet_Magnet__setMapNode_448(magnet_Magnet self, floor_Floor f){
	int tmp_LdlZ_994 = f->type_867;
	switch (tmp_LdlZ_994){
		case floor_NORMAL_MINE_TYPE:{
		}

		case floor_MINE_VISIBLE_TYPE:{
		}

		case floor_NORMAL_NO_MINE_TYPE:{

			f->type_867 = floor_DESERT_TYPE;
			break;

		}

	}


}

void magnet_Magnet__fillMapNodes_531(magnet_Magnet self, int i, int j){
	teleporter_Teleporter__fillMapNodes_531((teleporter_Teleporter)self, i, j);

	self->available_nodes_669 = 0;

	self->to_transport_606 = NULL;


}

void magnet_Magnet__restoreMapNodes_185(magnet_Magnet self){
	return;


}

bool magnet_Magnet__inRange_8(magnet_Magnet self, int x, int y){
	return false;

}

char** magnet_Magnet_getInfo(magnet_Magnet self){
	static char* info[7] = {"A very powerful item created","by trollface himself.","Select (or steal) the magnet","and select where to place it.","The magnet will attract surounding mines.","You can pick the magnet up again,","but knowing that it'll be around mines."};
	return info;

}

void magnet_Magnet__fillHelpRect_284(magnet_Magnet self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* magnet_Magnet_getHelpName(magnet_Magnet self){
	return "Magnet";

}


