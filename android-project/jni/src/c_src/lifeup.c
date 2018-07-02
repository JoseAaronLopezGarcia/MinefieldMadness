#include <cbc.h>
// public globals
#include <lifeup.h>
// private globals
const class_id lifeup_Sprites__classid__ = -3829746775395780828;
const class_id lifeup_LifeUp__classid__ = -5871506333748401704;
//








image_Image lifeup_lifeup_img = NULL;

void lifeup_init(){
	lifeup_lifeup_img = image_Image_create(common_LIFEUP);


}

lifeup_Sprites lifeup_Sprites_create(){
	lifeup_Sprites self = (lifeup_Sprites)cbcstd_alloc(sizeof(lifeup_Sprites_struct));
	try{
		lifeup_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void lifeup_Sprites_init(lifeup_Sprites self){
	lifeup_Sprites_initsystem(self);
	lifeup_Sprites_inituser(self);
}
void lifeup_Sprites_initsystem(lifeup_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		-3829746775395780828L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(lifeup_Sprites_struct);
	self->_walk_443 = &lifeup_Sprites__walk_443;
	self->draw = &lifeup_Sprites_draw;
	self->__end__ = &lifeup_Sprites_end;
}
void lifeup_Sprites_enduser(lifeup_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void lifeup_Sprites_end(lifeup_Sprites self){
	lifeup_Sprites_enduser(self);
	lifeup_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void lifeup_Sprites_decrefs(lifeup_Sprites self){
}


void lifeup_Sprites_inituser(lifeup_Sprites self){

	self->spritesheet_722 = lifeup_lifeup_img;


}

void lifeup_Sprites__walk_443(lifeup_Sprites self){
	return;


}

void lifeup_Sprites_draw(lifeup_Sprites self, int x, int y, int w, int h){

	lifeup_lifeup_img->drawScaled(lifeup_lifeup_img, x,  y,  w,  h);

}


lifeup_LifeUp lifeup_LifeUp_create(){
	lifeup_LifeUp self = (lifeup_LifeUp)cbcstd_alloc(sizeof(lifeup_LifeUp_struct));
	try{
		lifeup_LifeUp_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void lifeup_LifeUp_init(lifeup_LifeUp self){
	lifeup_LifeUp_initsystem(self);
	lifeup_LifeUp_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	lifeup_LifeUp_inituser(self);
}
void lifeup_LifeUp_initsystem(lifeup_LifeUp self){
	teleporter_Teleporter_initsystem((teleporter_Teleporter)self);
	const static class_id __classid__[8] = {
		-5871506333748401704L,
		-5435808027858520778L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(lifeup_LifeUp_struct);
	self->__getvtable__ = (void*)(&lifeup_LifeUp_getvtable);
	self->_setMapNode_448 = &lifeup_LifeUp__setMapNode_448;
	self->_fillMapNodes_531 = &lifeup_LifeUp__fillMapNodes_531;
	self->_restoreMapNodes_185 = &lifeup_LifeUp__restoreMapNodes_185;
	self->_inRange_8 = &lifeup_LifeUp__inRange_8;
	self->getInfo = &lifeup_LifeUp_getInfo;
	self->_fillHelpRect_284 = &lifeup_LifeUp__fillHelpRect_284;
	self->getHelpName = &lifeup_LifeUp_getHelpName;
	self->__end__ = &lifeup_LifeUp_end;
}
void lifeup_LifeUp_enduser(lifeup_LifeUp self){
	teleporter_Teleporter_enduser((teleporter_Teleporter)self);
	return;
}
void lifeup_LifeUp_end(lifeup_LifeUp self){
	lifeup_LifeUp_enduser(self);
	lifeup_LifeUp_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void lifeup_LifeUp_init_map_MapObject(map_MapObject self, lifeup_LifeUp __self__){
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
cbcstd_Object lifeup_LifeUp_getvtable(lifeup_LifeUp self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void lifeup_LifeUp_decrefs(lifeup_LifeUp self){
}


void lifeup_LifeUp_inituser(lifeup_LifeUp self){
	teleporter_Teleporter_inituser((teleporter_Teleporter)self);

	teleporter_Sprites aux = self->sprites_11;

	self->sprites_11 = lifeup_Sprites_create();
	cbcstd_destroyObj((cbcstd_Object*)&(aux));

}

void lifeup_LifeUp__setMapNode_448(lifeup_LifeUp self, floor_Floor f){
	return;


}

void lifeup_LifeUp__fillMapNodes_531(lifeup_LifeUp self, int i, int j){

	self->available_nodes_669 = 0;

	character_characters_sema->wait(character_characters_sema);
	character_Character tmp_ce0r_869 = self->to_transport_606;

	tmp_ce0r_869->lives_836++;

	character_characters_sema->release(character_characters_sema);

	self->x_405 = -1;

	self->y_782 = -1;


}

void lifeup_LifeUp__restoreMapNodes_185(lifeup_LifeUp self){
	return;


}

bool lifeup_LifeUp__inRange_8(lifeup_LifeUp self, int x, int y){
	return false;

}

char** lifeup_LifeUp_getInfo(lifeup_LifeUp self){
	static char* info[7] = {"This makes your character","invulnerable to one mine.","Select the character you","wanna use it in and then,","select this item.","Although it gives life,","it doesn't have much itself."};
	return info;

}

void lifeup_LifeUp__fillHelpRect_284(lifeup_LifeUp self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* lifeup_LifeUp_getHelpName(lifeup_LifeUp self){
	return "Life-Up";

}


