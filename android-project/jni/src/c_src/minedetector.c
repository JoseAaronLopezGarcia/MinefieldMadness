#include <cbc.h>
// public globals
#include <minedetector.h>
// private globals
const class_id minedetector_Sprites__classid__ = -871579217172657780;
const class_id minedetector_MineDetector__classid__ = 7104975154427083824;
//







image_Image minedetector_minedetector_img = NULL;

void minedetector_init(){
	minedetector_minedetector_img = image_Image_create(common_MINEDETECTOR);


}

minedetector_Sprites minedetector_Sprites_create(){
	minedetector_Sprites self = (minedetector_Sprites)cbcstd_alloc(sizeof(minedetector_Sprites_struct));
	try{
		minedetector_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void minedetector_Sprites_init(minedetector_Sprites self){
	minedetector_Sprites_initsystem(self);
	minedetector_Sprites_inituser(self);
}
void minedetector_Sprites_initsystem(minedetector_Sprites self){
	character_Sprites_initsystem((character_Sprites)self);
	const static class_id __classid__[4] = {
		-871579217172657780L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(minedetector_Sprites_struct);
	self->_walk_443 = &minedetector_Sprites__walk_443;
	self->draw = &minedetector_Sprites_draw;
	self->__end__ = &minedetector_Sprites_end;
}
void minedetector_Sprites_enduser(minedetector_Sprites self){
	character_Sprites_enduser((character_Sprites)self);
	return;
}
void minedetector_Sprites_end(minedetector_Sprites self){
	minedetector_Sprites_enduser(self);
	minedetector_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void minedetector_Sprites_decrefs(minedetector_Sprites self){
}


void minedetector_Sprites_inituser(minedetector_Sprites self){

	self->spritesheet_722 = minedetector_minedetector_img;


}

void minedetector_Sprites__walk_443(minedetector_Sprites self){
	return;


}

void minedetector_Sprites_draw(minedetector_Sprites self, int x, int y, int w, int h){

	minedetector_minedetector_img->drawScaled(minedetector_minedetector_img, x,  y,  w,  h);

}


minedetector_MineDetector minedetector_MineDetector_create(){
	minedetector_MineDetector self = (minedetector_MineDetector)cbcstd_alloc(sizeof(minedetector_MineDetector_struct));
	try{
		minedetector_MineDetector_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void minedetector_MineDetector_init(minedetector_MineDetector self){
	minedetector_MineDetector_initsystem(self);
	minedetector_MineDetector_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	minedetector_MineDetector_inituser(self);
}
void minedetector_MineDetector_initsystem(minedetector_MineDetector self){
	teleporter_Teleporter_initsystem((teleporter_Teleporter)self);
	const static class_id __classid__[8] = {
		7104975154427083824L,
		-5435808027858520778L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(minedetector_MineDetector_struct);
	self->__getvtable__ = (void*)(&minedetector_MineDetector_getvtable);
	self->_setMapNode_448 = &minedetector_MineDetector__setMapNode_448;
	self->_fillMapNodes_531 = &minedetector_MineDetector__fillMapNodes_531;
	self->_restoreMapNodes_185 = &minedetector_MineDetector__restoreMapNodes_185;
	self->_inRange_8 = &minedetector_MineDetector__inRange_8;
	self->getInfo = &minedetector_MineDetector_getInfo;
	self->_fillHelpRect_284 = &minedetector_MineDetector__fillHelpRect_284;
	self->getHelpName = &minedetector_MineDetector_getHelpName;
	self->__end__ = &minedetector_MineDetector_end;
}
void minedetector_MineDetector_enduser(minedetector_MineDetector self){
	teleporter_Teleporter_enduser((teleporter_Teleporter)self);
	return;
}
void minedetector_MineDetector_end(minedetector_MineDetector self){
	minedetector_MineDetector_enduser(self);
	minedetector_MineDetector_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void minedetector_MineDetector_init_map_MapObject(map_MapObject self, minedetector_MineDetector __self__){
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
cbcstd_Object minedetector_MineDetector_getvtable(minedetector_MineDetector self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void minedetector_MineDetector_decrefs(minedetector_MineDetector self){
}


void minedetector_MineDetector_inituser(minedetector_MineDetector self){
	teleporter_Teleporter_inituser((teleporter_Teleporter)self);

	teleporter_Sprites aux = self->sprites_11;

	self->sprites_11 = minedetector_Sprites_create();
	cbcstd_destroyObj((cbcstd_Object*)&(aux));

}

void minedetector_MineDetector__setMapNode_448(minedetector_MineDetector self, floor_Floor f){

	if (f->type_867 == floor_NORMAL_MINE_TYPE){

		f->type_867 = floor_MINE_VISIBLE_TYPE;

	}


}

void minedetector_MineDetector__fillMapNodes_531(minedetector_MineDetector self, int i, int j){
	teleporter_Teleporter__fillMapNodes_531((teleporter_Teleporter)self, i, j);

	self->available_nodes_669 = 0;

	self->to_transport_606 = NULL;

	self->x_405 = -1;

	self->y_782 = -1;


}

void minedetector_MineDetector__restoreMapNodes_185(minedetector_MineDetector self){
	return;


}

bool minedetector_MineDetector__inRange_8(minedetector_MineDetector self, int x, int y){
	return false;

}

char** minedetector_MineDetector_getInfo(minedetector_MineDetector self){
	static char* info[7] = {"A radar-like mine detector.","It'll make surrounding mines show up.","Select the character you want","to use the item with","and then use the item.","The item's battery runs out","as soon as you use it."};
	return info;

}

void minedetector_MineDetector__fillHelpRect_284(minedetector_MineDetector self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* minedetector_MineDetector_getHelpName(minedetector_MineDetector self){
	return "Mine Detector";

}


