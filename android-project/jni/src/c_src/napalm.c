#include <cbc.h>
// public globals
#include <napalm.h>
// private globals
const class_id napalm_Napalm__classid__ = 476737886576900744;
//






image_Image napalm_napalm_img = NULL;

void napalm_init(){
	napalm_napalm_img = image_Image_create(common_NAPALM);


}

napalm_Napalm napalm_Napalm_create(){
	napalm_Napalm self = (napalm_Napalm)cbcstd_alloc(sizeof(napalm_Napalm_struct));
	try{
		napalm_Napalm_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void napalm_Napalm_init(napalm_Napalm self){
	napalm_Napalm_initsystem(self);
	napalm_Napalm_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	napalm_Napalm_inituser(self);
}
void napalm_Napalm_initsystem(napalm_Napalm self){
	grenade_Grenade_initsystem((grenade_Grenade)self);
	const static class_id __classid__[8] = {
		476737886576900744L,
		56220438001416510L,
		5968600321633189670L,
		-877637167666370448L,
		4450938680730463789L,
		4450938680730463789L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(napalm_Napalm_struct);
	self->__getvtable__ = (void*)(&napalm_Napalm_getvtable);
	self->draw = &napalm_Napalm_draw;
	self->onClick = &napalm_Napalm_onClick;
	self->interact = &napalm_Napalm_interact;
	self->getInfo = &napalm_Napalm_getInfo;
	self->getHelpName = &napalm_Napalm_getHelpName;
	self->__end__ = &napalm_Napalm_end;
}
void napalm_Napalm_end(napalm_Napalm self){
	napalm_Napalm_enduser(self);
	napalm_Napalm_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void napalm_Napalm_init_map_MapObject(map_MapObject self, napalm_Napalm __self__){
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
cbcstd_Object napalm_Napalm_getvtable(napalm_Napalm self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void napalm_Napalm_decrefs(napalm_Napalm self){
}


void napalm_Napalm_inituser(napalm_Napalm self){
	grenade_Grenade_inituser((grenade_Grenade)self);
	character_Sprites tmp_foZ6_944 = self->sprites_11;

	tmp_foZ6_944->spritesheet_722 = napalm_napalm_img;
	{int i=0; for (; i<DIM_X-2; i++){

		self->grenades_1[i] = grenade_Grenade_create();

		grenade_Grenade tmp_cast_ZhJo = (grenade_Grenade)(self->grenades_1[i]);
		grenade_Grenade g = tmp_cast_ZhJo;
		character_Sprites tmp_9kKc_948 = g->sprites_11;

		tmp_9kKc_948->spritesheet_722 = napalm_napalm_img;

	}}


}

void napalm_Napalm_enduser(napalm_Napalm self){
		grenade_Grenade_enduser((grenade_Grenade)self);
	return;


}

void napalm_Napalm_draw(napalm_Napalm self){






	character_Sprites tmp_ktXE_956 = self->sprites_11;

	tmp_ktXE_956->draw(tmp_ktXE_956, self->x_405+self->x_offset_475,  self->y_782+self->y_offset_563,  self->width_945,  self->height_399);


}

void napalm_Napalm_onClick(napalm_Napalm self, int x, int y){

	if (self->x_405 < (DIM_X-1)*common_FLOOR_WIDTH){
		return;
	}


	if (self->clicked(self, x,  y)){

		int from_i = self->y_782/common_FLOOR_HEIGHT;

		int from_j = self->x_405/common_FLOOR_WIDTH;
		cbcstd_List objs = map_getNode(from_i, from_j)->objects;
		{int index=0; for (; index<DIM_X-2; index++){
			int to_i = rand()%DIM_Y;
			int to_j = index+1;

			grenade_Grenade tmp_cast_zHYe = (grenade_Grenade)(self->grenades_1[index]);
			grenade_Grenade g = tmp_cast_zHYe;


			g->x_405 = self->x_405;


			g->y_782 = self->y_782;

			g->findPath(g, (to_j*common_FLOOR_WIDTH)+(common_FLOOR_WIDTH/2),  (to_i*common_FLOOR_HEIGHT)+(common_FLOOR_HEIGHT/2));


			objs->push(objs, self->grenades_1[index]);
		}}


		self->x_405 = -1;

		self->y_782 = -1;
	}


}

void napalm_Napalm_interact(napalm_Napalm self){
	return;

}

char** napalm_Napalm_getInfo(napalm_Napalm self){
	static char* info[7] = {"A powerful but random weapon.","It can blow up anything,","but the problem is,","what will it blow up?","Select the weapon and watch","how it launches various attacks","at various places."};
	return info;


}

char* napalm_Napalm_getHelpName(napalm_Napalm self){
	return "Napalm";

}


