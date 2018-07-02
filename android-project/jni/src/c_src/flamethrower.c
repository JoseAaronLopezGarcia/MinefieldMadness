#include <cbc.h>
// public globals
#include <flamethrower.h>
// private globals
const class_id flamethrower_Sprites__classid__ = 3184612125756354789;
const class_id flamethrower_FlameThrower__classid__ = 1591778740519405730;
//







image_Image flamethrower_flamethrower_img = NULL;

void flamethrower_init(){
	flamethrower_flamethrower_img = image_Image_create(common_FLAMETHROWER);


}

flamethrower_Sprites flamethrower_Sprites_create(){
	flamethrower_Sprites self = (flamethrower_Sprites)cbcstd_alloc(sizeof(flamethrower_Sprites_struct));
	try{
		flamethrower_Sprites_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void flamethrower_Sprites_init(flamethrower_Sprites self){
	flamethrower_Sprites_initsystem(self);
	flamethrower_Sprites_inituser(self);
}
void flamethrower_Sprites_initsystem(flamethrower_Sprites self){
	teleporter_Sprites_initsystem((teleporter_Sprites)self);
	const static class_id __classid__[5] = {
		3184612125756354789L,
		714678348714115981L,
		-5848076223921087973L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(flamethrower_Sprites_struct);
	self->_walk_443 = &flamethrower_Sprites__walk_443;
	self->draw = &flamethrower_Sprites_draw;
	self->__end__ = &flamethrower_Sprites_end;
}
void flamethrower_Sprites_enduser(flamethrower_Sprites self){
	teleporter_Sprites_enduser((teleporter_Sprites)self);
	return;
}
void flamethrower_Sprites_end(flamethrower_Sprites self){
	flamethrower_Sprites_enduser(self);
	flamethrower_Sprites_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void flamethrower_Sprites_decrefs(flamethrower_Sprites self){
}


void flamethrower_Sprites_inituser(flamethrower_Sprites self){

	self->spritesheet_722 = flamethrower_flamethrower_img;


}

void flamethrower_Sprites__walk_443(flamethrower_Sprites self){
	return;


}

void flamethrower_Sprites_draw(flamethrower_Sprites self, int x, int y, int w, int h){

	flamethrower_flamethrower_img->drawScaled(flamethrower_flamethrower_img, x,  y,  w,  h);

}


flamethrower_FlameThrower flamethrower_FlameThrower_create(){
	flamethrower_FlameThrower self = (flamethrower_FlameThrower)cbcstd_alloc(sizeof(flamethrower_FlameThrower_struct));
	try{
		flamethrower_FlameThrower_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void flamethrower_FlameThrower_init(flamethrower_FlameThrower self){
	flamethrower_FlameThrower_initsystem(self);
	flamethrower_FlameThrower_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	flamethrower_FlameThrower_inituser(self);
}
void flamethrower_FlameThrower_initsystem(flamethrower_FlameThrower self){
	teleporter_Teleporter_initsystem((teleporter_Teleporter)self);
	const static class_id __classid__[8] = {
		1591778740519405730L,
		-5435808027858520778L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(flamethrower_FlameThrower_struct);
	self->__getvtable__ = (void*)(&flamethrower_FlameThrower_getvtable);
	self->_setMapNode_448 = &flamethrower_FlameThrower__setMapNode_448;
	self->_fillMapNodes_531 = &flamethrower_FlameThrower__fillMapNodes_531;
	self->_restoreMapNodes_185 = &flamethrower_FlameThrower__restoreMapNodes_185;
	self->_inRange_8 = &flamethrower_FlameThrower__inRange_8;
	self->getInfo = &flamethrower_FlameThrower_getInfo;
	self->_fillHelpRect_284 = &flamethrower_FlameThrower__fillHelpRect_284;
	self->getHelpName = &flamethrower_FlameThrower_getHelpName;
	self->__end__ = &flamethrower_FlameThrower_end;
}
void flamethrower_FlameThrower_enduser(flamethrower_FlameThrower self){
	teleporter_Teleporter_enduser((teleporter_Teleporter)self);
	return;
}
void flamethrower_FlameThrower_end(flamethrower_FlameThrower self){
	flamethrower_FlameThrower_enduser(self);
	flamethrower_FlameThrower_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void flamethrower_FlameThrower_init_map_MapObject(map_MapObject self, flamethrower_FlameThrower __self__){
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
cbcstd_Object flamethrower_FlameThrower_getvtable(flamethrower_FlameThrower self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void flamethrower_FlameThrower_decrefs(flamethrower_FlameThrower self){
}


void flamethrower_FlameThrower_inituser(flamethrower_FlameThrower self){
	teleporter_Teleporter_inituser((teleporter_Teleporter)self);

	teleporter_Sprites aux = self->sprites_11;

	self->sprites_11 = flamethrower_Sprites_create();
	cbcstd_destroyObj((cbcstd_Object*)&(aux));

}

void flamethrower_FlameThrower__setMapNode_448(flamethrower_FlameThrower self, floor_Floor f){
	return;


}

void flamethrower_FlameThrower__fillMapNodes_531(flamethrower_FlameThrower self, int i, int j){
	flamethrower_FlameThrowerNode nodes[4] = {{i, j+1}, {i, j+2}, {i-1, j+2}, {i+1, j+2}};
	{int x=0; for (; x<4; x++){




		if (nodes[x].i<0 or nodes[x].i>=DIM_Y or nodes[x].j<1 or nodes[x].j>=DIM_X-1){
			continue;
		}



		floor_Floor tmp_cast_jRwl = (floor_Floor)(map_getNode(nodes[x].i, nodes[x].j)->bg);
		floor_Floor f = tmp_cast_jRwl;

		f->startFireAnim(f);
	}}


	self->available_nodes_669 = 0;

	self->x_405 = -1;

	self->y_782 = -1;


}

void flamethrower_FlameThrower__restoreMapNodes_185(flamethrower_FlameThrower self){
	return;


}

bool flamethrower_FlameThrower__inRange_8(flamethrower_FlameThrower self, int x, int y){
	return false;

}

char** flamethrower_FlameThrower_getInfo(flamethrower_FlameThrower self){
	static char* info[7] = {"Classic weapon used to","burn through grass.","Select the character you","want to use it with","and then select it to use it.","It'll burn through the ground","ahead of the selected player."};
	return info;

}

void flamethrower_FlameThrower__fillHelpRect_284(flamethrower_FlameThrower self, SDL_Rect* rect){

	rect->w = self->width_945;

	rect->h = self->height_399;
	rect->y = 0;
	rect->x = 0;


}

char* flamethrower_FlameThrower_getHelpName(flamethrower_FlameThrower self){
	return "Flamethrower";

}


