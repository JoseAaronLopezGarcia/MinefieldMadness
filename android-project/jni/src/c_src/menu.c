#include <cbc.h>
// public globals
#include <menu.h>
// private globals
const class_id menu_Button__classid__ = 3556920588130727727;
const class_id menu_SoundButton__classid__ = 7311562203001515453;
const class_id menu_Menu__classid__ = -3765202318984487348;
//










image_Image menu_box_img = NULL;
image_Image menu_button_img = NULL;
image_Image menu_sound_img = NULL;

bool clicked;

const SDL_Rect menu_button_normal = {10, 10,  400, 60};
const SDL_Rect menu_button_pressed = {10, 130, 400, 60};
const int menu_box_w = (900 - 100);
const int menu_box_h = (700 - 60);
const int menu_sound_w = 80;

SDL_Rect* button_rect[2];

menu_Button menu_Button_create(int difficulty_level, int base_x, int base_y, int base_h){
	menu_Button self = (menu_Button)cbcstd_alloc(sizeof(menu_Button_struct));
	try{
		menu_Button_init(self, difficulty_level, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void menu_Button_init(menu_Button self, int difficulty_level, int base_x, int base_y, int base_h){
	menu_Button_initsystem(self);
	menu_Button_inituser(self, difficulty_level, base_x, base_y, base_h);
}
void menu_Button_initsystem(menu_Button self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(menu_Button_struct);
	self->_loadText_217 = &menu_Button__loadText_217;
	self->onClick = &menu_Button_onClick;
	self->draw = &menu_Button_draw;
	self->clicked = &menu_Button_clicked;
	self->__end__ = &menu_Button_end;
}
void menu_Button_end(menu_Button self){
	menu_Button_enduser(self);
	menu_Button_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void menu_Button_decrefs(menu_Button self){
}








	
void menu_Button_inituser(menu_Button self, int difficulty_level, int base_x, int base_y, int base_h){
	int base_w = menu_box_w;

	self->_loadText_217(self, difficulty_level);

	self->x_64 = base_x + ((base_w-button_rect[0]->w)/2);

	self->y_752 = base_y + ((base_h-button_rect[0]->h)/2);
	font_Font tmp_Dlza_1127 = self->text_522;




	self->font_x_343 = self->x_64 + ((button_rect[self->pressed_646]->w-tmp_Dlza_1127->getWidth(tmp_Dlza_1127))/2);
	font_Font tmp_7Hix_1132 = self->text_522;




	self->font_y_812 = self->y_752 + ((button_rect[self->pressed_646]->h-tmp_7Hix_1132->getHeight(tmp_7Hix_1132))/2);
	static void* execs[MAX_DIFFICULTY_LEVELS] ={&(game_startGameVeryEasy), &(game_startGameEasy), &(game_startGameNormal),&(game_startGameHard), &(game_startGameExtreme), &(game_startGameImpossible)};

	self->to_exec_876 = execs[difficulty_level];

	self->pressed_646 = false;

}

void menu_Button__loadText_217(menu_Button self, int difficulty_level){

	self->text_522 = font_Font_create(font_SIZE_LARGE);
	font_Font tmp_Lw0N_1140 = self->text_522;

	tmp_Lw0N_1140->render(tmp_Lw0N_1140, difficulty_difficulty_levels[difficulty_level],  font_WHITE, NULL);

}

void menu_Button_onClick(menu_Button self, int x, int y){

	if (self->pressed_646){
		return;
	}



	if (self->clicked(self, x,  y) and self->to_exec_876 != NULL){

		self->pressed_646 = true;
		clicked = true;
		SDL_Delay(500);

		self->to_exec_876();

	}


}

void menu_Button_draw(menu_Button self){






	menu_button_img->drawClippedScaled(menu_button_img, self->x_64,  self->y_752,  button_rect[self->pressed_646]->w,  button_rect[self->pressed_646]->h,  button_rect[self->pressed_646]);


	font_Font tmp_01Ho_1155 = self->text_522;

	tmp_01Ho_1155->draw(tmp_01Ho_1155, self->font_x_343,  self->font_y_812);
	

}

bool menu_Button_clicked(menu_Button self, int x, int y){


	return map_clickedOn(self->x_64, self->y_752, button_rect[0]->w, button_rect[0]->h);

}

void menu_Button_enduser(menu_Button self){
		cbcstd_Object_enduser((cbcstd_Object)self);

	cbcstd_destroyObj((cbcstd_Object*)&(self->text_522));

}


menu_SoundButton menu_SoundButton_create(){
	menu_SoundButton self = (menu_SoundButton)cbcstd_alloc(sizeof(menu_SoundButton_struct));
	try{
		menu_SoundButton_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void menu_SoundButton_init(menu_SoundButton self){
	menu_SoundButton_initsystem(self);
	menu_SoundButton_inituser(self);
}
void menu_SoundButton_initsystem(menu_SoundButton self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		7311562203001515453L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(menu_SoundButton_struct);
	self->draw = &menu_SoundButton_draw;
	self->onClick = &menu_SoundButton_onClick;
	self->clicked = &menu_SoundButton_clicked;
	self->__end__ = &menu_SoundButton_end;
}
void menu_SoundButton_enduser(menu_SoundButton self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void menu_SoundButton_end(menu_SoundButton self){
	menu_SoundButton_enduser(self);
	menu_SoundButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void menu_SoundButton_decrefs(menu_SoundButton self){
}




	
void menu_SoundButton_inituser(menu_SoundButton self){

	self->rect_843.x = 0;

	self->rect_843.y = 0;

	self->rect_843.w = menu_sound_w;

	self->rect_843.h = menu_sound_w;

	self->x_375 = (common_FLOOR_WIDTH-menu_sound_w)/2;

	self->y_568 = ((common_FLOOR_HEIGHT-menu_sound_w)/2)+((DIM_Y-1)*common_FLOOR_HEIGHT);

}

void menu_SoundButton_draw(menu_SoundButton self){

	self->rect_843.x = sound_sound_state * menu_sound_w;




	menu_sound_img->drawClippedScaled(menu_sound_img, self->x_375,  self->y_568,  menu_sound_w,  menu_sound_w,  &(self->rect_843));


}

void menu_SoundButton_onClick(menu_SoundButton self, int x, int y){

	if (self->clicked(self, x,  y)){
		switch (sound_sound_state){
			case sound_ALL_SOUND:{

				sound_bg_music->play(sound_bg_music);
				sound_sound_state = sound_NO_MUSIC;
				break;
			}

			case sound_NO_MUSIC:{
				sound_sound_state = sound_FULL_MUTE;
				break;
			}

			case sound_FULL_MUTE:{
				sound_sound_state = sound_ALL_SOUND;

				sound_bg_music->play(sound_bg_music);
				break;
			}

			default:{
				break;
			}

		}


		savedata_decrypted.sound_state = sound_sound_state;

	}


}

bool menu_SoundButton_clicked(menu_SoundButton self, int x, int y){


	return map_clickedOn(self->x_375, self->y_568, menu_sound_w, menu_sound_w);

}


menu_SoundButton menu_sound_button = NULL;

menu_Menu menu_Menu_create(){
	menu_Menu self = (menu_Menu)cbcstd_alloc(sizeof(menu_Menu_struct));
	try{
		menu_Menu_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void menu_Menu_init(menu_Menu self){
	menu_Menu_initsystem(self);
	menu_Menu_inituser(self);
}
void menu_Menu_initsystem(menu_Menu self){
	cbcstd_Object_initsystem((cbcstd_Object)self);
	const static class_id __classid__[3] = {
		-3765202318984487348L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(menu_Menu_struct);
	self->_setMaxButtons_414 = &menu_Menu__setMaxButtons_414;
	self->_initButtons_6 = &menu_Menu__initButtons_6;
	self->_createButton_136 = &menu_Menu__createButton_136;
	self->_initAnimation_116 = &menu_Menu__initAnimation_116;
	self->draw = &menu_Menu_draw;
	self->onClick = &menu_Menu_onClick;
	self->restart = &menu_Menu_restart;
	self->__end__ = &menu_Menu_end;
}
void menu_Menu_enduser(menu_Menu self){
	cbcstd_Object_enduser((cbcstd_Object)self);
	return;
}
void menu_Menu_end(menu_Menu self){
	menu_Menu_enduser(self);
	menu_Menu_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void menu_Menu_decrefs(menu_Menu self){
}









void menu_Menu_inituser(menu_Menu self){

	self->x_495 = ((common_FLOOR_WIDTH*DIM_X)-menu_box_w)/2;

	self->y_233 = ((common_FLOOR_HEIGHT*(DIM_Y-1))-menu_box_h)/2 + common_FLOOR_HEIGHT;

	self->_setMaxButtons_414(self);

	self->_initButtons_6(self);

	self->_initAnimation_116(self);


}

void menu_Menu__setMaxButtons_414(menu_Menu self){

	self->max_buttons_251 = MAX_DIFFICULTY_LEVELS;


}

void menu_Menu__initButtons_6(menu_Menu self){

	int base_height = menu_box_h/self->max_buttons_251;


	self->buttons_99 = CBC_NEW(menu_Button, self->max_buttons_251);

	{int i=0; for (; i<self->max_buttons_251; i++){




		self->buttons_99[i] = self->_createButton_136(self, i,  self->x_495,  self->y_233 + i*base_height,  base_height);
	}}


	self->button_sound_227 = menu_sound_button;


}

menu_Button menu_Menu__createButton_136(menu_Menu self, int i, int base_x, int base_y, int base_h){
	return menu_Button_create(i, base_x, base_y, base_h);


}

void menu_Menu__initAnimation_116(menu_Menu self){

	self->animation_768 = anim_AnimatedText_create("Minefield Madness!");


}

void menu_Menu_draw(menu_Menu self){
	map_draw();



	menu_box_img->drawScaled(menu_box_img, self->x_495,  self->y_233,  menu_box_w,  menu_box_h);

	{int i=0; for (; i<self->max_buttons_251; i++){
		menu_Button tmp_BsFZ_1196 = self->buttons_99[i];

		tmp_BsFZ_1196->draw(tmp_BsFZ_1196);
	}}

	menu_SoundButton tmp_ZYMq_1198 = self->button_sound_227;

	tmp_ZYMq_1198->draw(tmp_ZYMq_1198);
	anim_AnimatedText tmp_ZgEU_1200 = self->animation_768;

	tmp_ZgEU_1200->draw(tmp_ZgEU_1200);


}

void menu_Menu_onClick(menu_Menu self, int x, int y){
	if (clicked){
		return;
	}


	{int i=0; for (; i<self->max_buttons_251; i++){
		menu_Button tmp_q8zW_1203 = self->buttons_99[i];

		tmp_q8zW_1203->onClick(tmp_q8zW_1203, x,  y);
	}}

	menu_SoundButton tmp_gGkg_1205 = self->button_sound_227;

	tmp_gGkg_1205->onClick(tmp_gGkg_1205, x,  y);


}

void menu_Menu_restart(menu_Menu self){
	clicked = false;

	{int i=0; for (; i<self->max_buttons_251; i++){
		menu_Button tmp_eKKE_1208 = self->buttons_99[i];

		tmp_eKKE_1208->pressed_646 = false;
	}}


}


void menu_init(){
	clicked = false;
	button_rect[0] = &menu_button_normal;
	button_rect[1] = &menu_button_pressed;
	menu_box_img = image_Image_create(common_BOX);
	menu_sound_img = image_Image_create(common_SOUND_IMAGE);
	menu_button_img = image_Image_create(common_BUTTONS);
	menu_sound_button = menu_SoundButton_create();

}

