#include <cbc.h>
// public globals
#include <floor.h>
// private globals
const class_id floor_Floor__classid__ = -6720146995513795818;
//








char* floor_terrain_name[11] = {
	"Grass terrain",
	"Grass terrain",
	"Mine spot",
	"Safe spot",
	"Rocky terrain",
	"Lake",
	"Item holder",
	"Start spot",
	"Exit",
	"Teleport location",
	"Pause"
};
char* floor_terrain_help[11][7] = {
	{
		"Normal grass-filed terrain.",
		"In this type of",
		"terrain there might",
		"or might not be any mines.",
		"Be extra careful when",
		"stepping here.",
		""
	},
	{
		"Normal grass-filed terrain.",
		"In this type of",
		"terrain there might",
		"or might not be any mines.",
		"Be extra careful when",
		"stepping here.",
		""
	},
	{
		"A grass terrain where there has",
		"been revealed to be a mine.",
		"It is obvious you",
		"can't step here.",
		"Use weapons to destroy it",
		"or items to avoid it.",
		""
	},
	{
		"A terrain that has",
		"been destroyed.",
		"The result is that",
		"there's no mine here",
		"so it is always safe to",
		"step into one of these.",
		""
	},
	{
		"A terrain being blocked",
		"by huge stones.",
		"You cannot pass through",
		"it in any way, your only",
		"options are to remove it",
		"or to find an alternate path.",
		""
	},
	{
		"A deep and dangerous lake.",
		"You can't go through it in any way,",
		"unless you blow it up somehow.",
		"It is rumored to have alligators",
		"in them, but it is not confirmed,",
		"yet. No attack has happened so far",
		"but keep your eyes peeled anyways."
	},
	{
		"This is where weapons and",
		"items are stored.",
		"Click on it to select/use the",
		"item being hold in there.",
		"It can hold as many items as",
		"you can as long as",
		"they are of the same type.",
	},
	{
		"This is where your",
		"characters start.",
		"It is an obviously safe spot.",
		"It cannot be blow up and",
		"weapons or items are out of",
		"bounds for this place.",
		""
	},
	{
		"This is the exit spot.",
		"You have to take one",
		"of your characters",
		"to this place safely",
		"to win the stage.",
		"",
		""
	},
	{
		"An area of the map marked",
		"by the teleporter.",
		"This is one of the",
		"possible places where",
		"you can teleport your",
		"character to.",
		"Not affiliated to Aperture Science in any way."
	},
	{
		"This is the pause button.",
		"You should know that already,",
		"otherwise, how the hell did",
		"you get to the help screen?",
		"This help message shouldn't",
		"be shown anyways.",
		"sudo make me a sandwitch"
	}
};

const int floor_FIRE_HEIGHT = 108;
const int floor_FIRE_WIDTH = 64;

const int floor_MAX_FIRE_ANIMS = 14;

int floor_fire_offset_x = 0;
int floor_fire_offset_y = 0;

image_Image terrain_img[11];
image_Image floor_fire_img = NULL;
image_Image* floor_floor_img = NULL;
sound_Sound floor_explosion_sound = NULL;














floor_Floor floor_Floor_create(int type, int i, int j){
	floor_Floor self = (floor_Floor)cbcstd_alloc(sizeof(floor_Floor_struct));
	try{
		floor_Floor_init(self, type, i, j);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void floor_Floor_init(floor_Floor self, int type, int i, int j){
	floor_Floor_initsystem(self);
	floor_Floor_init_map_MapObject((map_MapObject)(&(self->__vtableiface0__)), self);
	floor_Floor_inituser(self, type, i, j);
}
void floor_Floor_initsystem(floor_Floor self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[4] = {
		-6720146995513795818L,
		-877637167666370448L,
		4450938680730463789L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(floor_Floor_struct);
	self->__getvtable__ = (void*)(&floor_Floor_getvtable);
	self->_checkItemText_549 = &floor_Floor__checkItemText_549;
	self->draw = &floor_Floor_draw;
	self->startFireAnim = &floor_Floor_startFireAnim;
	self->onClick = &floor_Floor_onClick;
	self->interact = &floor_Floor_interact;
	self->cleanUp = &floor_Floor_cleanUp;
	self->waitAnimEnd = &floor_Floor_waitAnimEnd;
	self->setCoordinates = &floor_Floor_setCoordinates;
	self->updatePosition = &floor_Floor_updatePosition;
	self->getSaveInfo = &floor_Floor_getSaveInfo;
	self->setInfoFromSave = &floor_Floor_setInfoFromSave;
	self->getInfo = &floor_Floor_getInfo;
	self->drawHelpSprite = &floor_Floor_drawHelpSprite;
	self->getHelpName = &floor_Floor_getHelpName;
	self->__end__ = &floor_Floor_end;
}
void floor_Floor_enduser(floor_Floor self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void floor_Floor_end(floor_Floor self){
	floor_Floor_enduser(self);
	floor_Floor_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void floor_Floor_init_map_MapObject(map_MapObject self, floor_Floor __self__){
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
cbcstd_Object floor_Floor_getvtable(floor_Floor self, class_id id){
	switch (id){
	case 4450938680730463789:
		return (cbcstd_Object)(&(self->__vtableiface0__));
	default:
		cthrow((cbcstd_Exception)cbcstd_CastExceptionError_create(self->__type__[0], id));
	}
}
void floor_Floor_decrefs(floor_Floor self){
}










	
void floor_Floor_inituser(floor_Floor self, int type, int i, int j){
	if (type >= 11){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("ERROR: Unknown terrain type")));
	}


	self->type_867 = type;

	self->i_163 = i;

	self->j_639 = j;

	self->fireAnim_68 = -1;

	self->fireDelay_141 = 3;

	self->floor_type_172 = 0;

	self->items_649 = -1;

	self->item_text_504 = NULL;

}

void floor_Floor__checkItemText_549(floor_Floor self){

	if (self->item_text_504 == NULL){

		if (self->type_867 == floor_TABLE_TYPE){

			self->item_text_504 = font_Font_create(font_SIZE_MEDIUM);
		}

		else{
			return;
		}

	}



	map_MapNode* node = map_getNode(self->i_163, self->j_639);


	int n_items = node->objects->size(node->objects);

	if (n_items != self->items_649){

		self->items_649 = n_items;
		cbcstd_Int tmpInt = cbcstd_Int_create(n_items);

		cbcstd_String tmpStr = tmpInt->__str__(tmpInt);
		font_Font tmp_UkAQ_106 = self->item_text_504;


		tmp_UkAQ_106->render(tmp_UkAQ_106, tmpStr->c_str(tmpStr),  font_RED, NULL);
		cbcstd_destroyObj((cbcstd_Object*)&(tmpInt));
		cbcstd_destroyObj((cbcstd_Object*)&(tmpStr));
	}


}

void floor_Floor_draw(floor_Floor self){

	self->_checkItemText_549(self);

	int x = self->j_639*common_FLOOR_WIDTH;

	int y = self->i_163*common_FLOOR_HEIGHT;


	floor_floor_img[self->floor_type_172]->draw(floor_floor_img[self->floor_type_172], x,  y);
	int tmp_0w8X_114 = self->type_867;
	switch (tmp_0w8X_114){
		case floor_NORMAL_NO_MINE_TYPE:{
		}

		case floor_NORMAL_MINE_TYPE:{
			break;
		}

		default:{



			terrain_img[self->type_867]->draw(terrain_img[self->type_867], x,  y);
			break;
		}

	}



	if (self->item_text_504 != NULL and self->items_649 != 0){
		font_Font tmp_JCFl_120 = self->item_text_504;

		tmp_JCFl_120->draw(tmp_JCFl_120, x,  y);
	}


	if (self->fireAnim_68 >= 0){

		SDL_Rect src_rect = {self->fireAnim_68*floor_FIRE_WIDTH, 0, floor_FIRE_WIDTH, floor_FIRE_HEIGHT};
		int fire_x = x+floor_fire_offset_x;
		int fire_y = y+floor_fire_offset_y;

		floor_fire_img->drawClippedScaled(floor_fire_img, fire_x,  fire_y,  floor_FIRE_WIDTH,  floor_FIRE_HEIGHT,  &src_rect);

		if (self->fireDelay_141){

			self->fireDelay_141--;
		}

		else{

			self->fireAnim_68++;

			self->fireDelay_141 = 3;
		}


		if (self->fireAnim_68 == floor_MAX_FIRE_ANIMS/2){
			int tmp_RmT9_130 = self->type_867;
			switch (tmp_RmT9_130){
				case floor_NORMAL_NO_MINE_TYPE:{
				}

				case floor_NORMAL_MINE_TYPE:{
				}

				case floor_MINE_VISIBLE_TYPE:{

					self->type_867 = floor_DESERT_TYPE;
					break;
				}

				default: break;
			}

		}


		if (self->fireAnim_68 >= floor_MAX_FIRE_ANIMS){

			self->fireAnim_68 = -1;

		}

	}


}

void floor_Floor_startFireAnim(floor_Floor self){

	floor_explosion_sound->play(floor_explosion_sound);

	self->fireAnim_68 = 0;

}

void floor_Floor_onClick(floor_Floor self, int x, int y){
	return;


}

void floor_Floor_interact(floor_Floor self){
	return;


}

void floor_Floor_cleanUp(floor_Floor self){

	self->type_867 = floor_NORMAL_NO_MINE_TYPE;

	self->floor_type_172 = 0;


}

void floor_Floor_waitAnimEnd(floor_Floor self){

	while (self->fireAnim_68 != -1){
		SDL_Delay(100);

	}


}

void floor_Floor_setCoordinates(floor_Floor self, int i, int j){

	self->i_163 = i;

	self->j_639 = j;


}

void floor_Floor_updatePosition(floor_Floor self, int* i, int* j){

	*i = self->i_163;

	*j = self->j_639;

}

void floor_Floor_getSaveInfo(floor_Floor self, long* info){

	info[0] = (long)(self->fireAnim_68);
	

	info[1] = (long)(self->floor_type_172);
	

}

void floor_Floor_setInfoFromSave(floor_Floor self, long* info){

	self->fireAnim_68 = (int)(info[0]);
	

	self->floor_type_172 = (int)(info[1]);


}

char** floor_Floor_getInfo(floor_Floor self){

	return floor_terrain_help[self->type_867];

}

void floor_Floor_drawHelpSprite(floor_Floor self, int x, int y){

	map_help_box->draw(map_help_box, x,  y);
	x += 5;
	y += 5;
	int w = common_FLOOR_WIDTH-10;
	int h = common_FLOOR_HEIGHT-10;


	floor_floor_img[self->floor_type_172]->drawScaled(floor_floor_img[self->floor_type_172], x,  y,  w,  h);
	int tmp_vR7n_151 = self->type_867;
	switch (tmp_vR7n_151){
		case floor_NORMAL_NO_MINE_TYPE:{
		}

		case floor_NORMAL_MINE_TYPE:{
			break;
		}

		default:{



			terrain_img[self->type_867]->drawScaled(terrain_img[self->type_867], x,  y,  w,  h);
			break;
					
		}

	}


}

char* floor_Floor_getHelpName(floor_Floor self){

	return floor_terrain_name[self->type_867];

}


void floor_init(){

	floor_fire_offset_x = (common_FLOOR_WIDTH-floor_FIRE_WIDTH)/2;
	floor_fire_offset_y = (common_FLOOR_HEIGHT-floor_FIRE_HEIGHT)/2;

	terrain_img[floor_NORMAL_NO_MINE_TYPE] = NULL;
	terrain_img[floor_NORMAL_MINE_TYPE] = NULL;
	terrain_img[floor_TABLE_TYPE] = image_Image_create(common_TABLE);
	terrain_img[floor_EXIT_TYPE] = image_Image_create(common_EXIT);
	terrain_img[floor_START_TYPE] = image_Image_create(common_START);
	terrain_img[floor_TELEPORT_TYPE] = image_Image_create(common_TELEPORT);
	terrain_img[floor_STONE_TYPE] = image_Image_create(common_STONE);
	terrain_img[floor_LAKE_TYPE] = image_Image_create(common_LAKE);
	terrain_img[floor_DESERT_TYPE] = image_Image_create(common_NOMINE);
	terrain_img[floor_MINE_VISIBLE_TYPE] = image_Image_create(common_MINE);
	terrain_img[floor_PAUSE_TYPE] = image_Image_create(common_PAUSE);
	
	floor_floor_img = CBC_NEW(image_Image, common_MAX_FLOORS);
	
	char* floor_path = strdup(common_FLOOR);
	{int i=0; for (; i<common_MAX_FLOORS; i++){
		floor_path[strlen(common_RESOURCES)+5] = '0'+i;
		floor_floor_img[i] = image_Image_create(floor_path);
	}}

	cbcstd_destroy(&(floor_path));
	
	floor_fire_img = image_Image_create(common_FIRE);
	
	floor_explosion_sound = sound_Sound_create(common_EXPLOSION_SOUND);

}

