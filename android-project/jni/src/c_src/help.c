#include <cbc.h>
// public globals
#include <help.h>
// private globals
const class_id help_ImageButton__classid__ = -3835933058066929033;
const class_id help_Button__classid__ = -4279168608943011253;
const class_id help_FakeSoundButton__classid__ = 703841599691997068;
const class_id help_FakeButton__classid__ = 5321303997963006700;
const class_id help_Menu__classid__ = 3357850780993164304;
//














help_HelpState help_state = help_HELP;
image_Image help_help_img = NULL;
void (*to_exec);

help_ImageButton help_ImageButton_create(map_MapObject mo, int base_x, int base_y, int base_h){
	help_ImageButton self = (help_ImageButton)cbcstd_alloc(sizeof(help_ImageButton_struct));
	try{
		help_ImageButton_init(self, mo, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void help_ImageButton_init(help_ImageButton self, map_MapObject mo, int base_x, int base_y, int base_h){
	help_ImageButton_initsystem(self);
	help_ImageButton_inituser(self, mo, base_x, base_y, base_h);
}
void help_ImageButton_initsystem(help_ImageButton self){
	notification_FakeButton_initsystem((notification_FakeButton)self);
	const static class_id __classid__[5] = {
		-3835933058066929033L,
		-8510171112188141736L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(help_ImageButton_struct);
	self->draw = &help_ImageButton_draw;
	self->__end__ = &help_ImageButton_end;
}
void help_ImageButton_enduser(help_ImageButton self){
	notification_FakeButton_enduser((notification_FakeButton)self);
	return;
}
void help_ImageButton_end(help_ImageButton self){
	help_ImageButton_enduser(self);
	help_ImageButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void help_ImageButton_decrefs(help_ImageButton self){
}


void help_ImageButton_inituser(help_ImageButton self, map_MapObject mo, int base_x, int base_y, int base_h){
	notification_FakeButton_inituser((notification_FakeButton)self, "useless", base_x, base_y, base_h);

	self->mo_204 = mo;


}

void help_ImageButton_draw(help_ImageButton self){


	map_MapObject tmp_lRfw_1283 = self->mo_204;

	CBC_LOW_CAST(tmp_lRfw_1283, map_MapObject)->drawHelpSprite(tmp_lRfw_1283, self->x_64,  self->y_752);

}


help_Button help_Button_create(int base_x, int base_y, int base_h){
	help_Button self = (help_Button)cbcstd_alloc(sizeof(help_Button_struct));
	try{
		help_Button_init(self, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void help_Button_init(help_Button self, int base_x, int base_y, int base_h){
	help_Button_initsystem(self);
	help_Button_inituser(self, base_x, base_y, base_h);
}
void help_Button_initsystem(help_Button self){
	notification_Button_initsystem((notification_Button)self);
	const static class_id __classid__[5] = {
		-4279168608943011253L,
		-5023131452191327025L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(help_Button_struct);
	self->draw = &help_Button_draw;
	self->onClick = &help_Button_onClick;
	self->__end__ = &help_Button_end;
}
void help_Button_enduser(help_Button self){
	notification_Button_enduser((notification_Button)self);
	return;
}
void help_Button_end(help_Button self){
	help_Button_enduser(self);
	help_Button_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void help_Button_decrefs(help_Button self){
}


void help_Button_inituser(help_Button self, int base_x, int base_y, int base_h){

	self->text_522 = font_Font_create(font_SIZE_LARGE);
	font_Font tmp_Zgfn_1286 = self->text_522;

	tmp_Zgfn_1286->render(tmp_Zgfn_1286, "OK",  font_WHITE, NULL);

	self->rendered_504 = false;
	menu_Button_inituser((menu_Button)self, -1, base_x, base_y, base_h);

	self->to_exec_876 = to_exec;


}

void help_Button_draw(help_Button self){

	if (not self->rendered_504){
		font_Font tmp_ncfI_1291 = self->text_522;

		tmp_ncfI_1291->render(tmp_ncfI_1291, "OK",  font_WHITE, NULL);

		self->rendered_504 = true;
	}

	menu_Button_draw((menu_Button)self);


}

void help_Button_onClick(help_Button self, int x, int y){

	self->to_exec_876 = to_exec;
	menu_Button_onClick((menu_Button)self, x, y);

}


help_FakeSoundButton help_FakeSoundButton_create(){
	help_FakeSoundButton self = (help_FakeSoundButton)cbcstd_alloc(sizeof(help_FakeSoundButton_struct));
	try{
		help_FakeSoundButton_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void help_FakeSoundButton_init(help_FakeSoundButton self){
	help_FakeSoundButton_initsystem(self);
	help_FakeSoundButton_inituser(self);
}
void help_FakeSoundButton_initsystem(help_FakeSoundButton self){
	menu_SoundButton_initsystem((menu_SoundButton)self);
	const static class_id __classid__[4] = {
		703841599691997068L,
		7311562203001515453L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(help_FakeSoundButton_struct);
	self->draw = &help_FakeSoundButton_draw;
	self->onClick = &help_FakeSoundButton_onClick;
	self->__end__ = &help_FakeSoundButton_end;
}
void help_FakeSoundButton_enduser(help_FakeSoundButton self){
	menu_SoundButton_enduser((menu_SoundButton)self);
	return;
}
void help_FakeSoundButton_end(help_FakeSoundButton self){
	help_FakeSoundButton_enduser(self);
	help_FakeSoundButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void help_FakeSoundButton_decrefs(help_FakeSoundButton self){
}

void help_FakeSoundButton_inituser(help_FakeSoundButton self){
	return;


}

void help_FakeSoundButton_draw(help_FakeSoundButton self){
	return;


}

void help_FakeSoundButton_onClick(help_FakeSoundButton self, int x, int y){
	return;

}


help_FakeSoundButton sound_button;

help_FakeButton help_FakeButton_create(const char* text, int base_x, int base_y, int base_h){
	help_FakeButton self = (help_FakeButton)cbcstd_alloc(sizeof(help_FakeButton_struct));
	try{
		help_FakeButton_init(self, text, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void help_FakeButton_init(help_FakeButton self, const char* text, int base_x, int base_y, int base_h){
	help_FakeButton_initsystem(self);
	help_FakeButton_inituser(self, text, base_x, base_y, base_h);
}
void help_FakeButton_initsystem(help_FakeButton self){
	notification_FakeButton_initsystem((notification_FakeButton)self);
	const static class_id __classid__[5] = {
		5321303997963006700L,
		-8510171112188141736L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(help_FakeButton_struct);
	self->_loadText_217 = &help_FakeButton__loadText_217;
	self->draw = &help_FakeButton_draw;
	self->__end__ = &help_FakeButton_end;
}
void help_FakeButton_enduser(help_FakeButton self){
	notification_FakeButton_enduser((notification_FakeButton)self);
	return;
}
void help_FakeButton_end(help_FakeButton self){
	help_FakeButton_enduser(self);
	help_FakeButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void help_FakeButton_decrefs(help_FakeButton self){
}


void help_FakeButton_inituser(help_FakeButton self, const char* text, int base_x, int base_y, int base_h){

	self->rendered_622 = false;
	notification_FakeButton_inituser((notification_FakeButton)self, text, base_x, base_y, base_h);


}

void help_FakeButton__loadText_217(help_FakeButton self, int difficulty_level){

	self->text_522 = font_Font_create(font_SIZE_MEDIUM);

	font_Font tmp_jPS6_1298 = self->text_522;

	tmp_jPS6_1298->render(tmp_jPS6_1298, self->to_show_184,  font_WHITE, NULL);


}

void help_FakeButton_draw(help_FakeButton self){

	if (not self->rendered_622){

		font_Font tmp_Pxha_1302 = self->text_522;

		tmp_Pxha_1302->render(tmp_Pxha_1302, self->to_show_184,  font_WHITE, NULL);

		self->rendered_622 = true;
	}

	notification_FakeButton_draw((notification_FakeButton)self);

}


help_Menu help_Menu_create(map_MapObject mo){
	help_Menu self = (help_Menu)cbcstd_alloc(sizeof(help_Menu_struct));
	try{
		help_Menu_init(self, mo);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void help_Menu_init(help_Menu self, map_MapObject mo){
	help_Menu_initsystem(self);
	help_Menu_inituser(self, mo);
}
void help_Menu_initsystem(help_Menu self){
	notification_Menu_initsystem((notification_Menu)self);
	const static class_id __classid__[5] = {
		3357850780993164304L,
		2734011580813432524L,
		-3765202318984487348L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(help_Menu_struct);
	self->_setMaxButtons_414 = &help_Menu__setMaxButtons_414;
	self->_createButton_136 = &help_Menu__createButton_136;
	self->_initAnimation_116 = &help_Menu__initAnimation_116;
	self->restart = &help_Menu_restart;
	self->draw = &help_Menu_draw;
	self->__end__ = &help_Menu_end;
}
void help_Menu_enduser(help_Menu self){
	notification_Menu_enduser((notification_Menu)self);
	return;
}
void help_Menu_end(help_Menu self){
	help_Menu_enduser(self);
	help_Menu_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void help_Menu_decrefs(help_Menu self){
}


void help_Menu_inituser(help_Menu self, map_MapObject mo){

	self->mo_878 = mo;
	notification_Menu_inituser((notification_Menu)self, 0, to_exec, NULL);

	self->button_sound_227 = sound_button;


}

void help_Menu__setMaxButtons_414(help_Menu self){

	self->max_buttons_251 = 9;

}

menu_Button help_Menu__createButton_136(help_Menu self, int i, int base_x, int base_y, int base_h){
	if (i == 0){
		cbcstd_Object tmp_new_pXWx = (cbcstd_Object)( help_FakeButton_create(" ", base_x, base_y, base_h));
		menu_Button tmp_cast_rQSm = (menu_Button)(tmp_new_pXWx);
		return tmp_cast_rQSm;
	}

	else{

	if (i < self->max_buttons_251-1){
		map_MapObject tmp_jTCc_1309 = self->mo_878;

		char** info = CBC_LOW_CAST(tmp_jTCc_1309, map_MapObject)->getInfo(tmp_jTCc_1309);
		char* text = info[i-1];
		if (text[0] == 0){
			text = " ";
		}

		cbcstd_Object tmp_new_2N30 = (cbcstd_Object)( help_FakeButton_create(text, base_x, base_y, base_h));
		menu_Button tmp_cast_3XXj = (menu_Button)(tmp_new_2N30);
		return tmp_cast_3XXj;
	}

	}
	help_Button ret = help_Button_create(base_x, base_y, base_h);
	menu_Button tmp_cast_4VhQ = (menu_Button)(ret);
	return tmp_cast_4VhQ;

}

void help_Menu__initAnimation_116(help_Menu self){
	map_MapObject tmp_ayWO_1311 = self->mo_878;


	self->animation_768 = anim_AnimatedText_create(CBC_LOW_CAST(tmp_ayWO_1311, map_MapObject)->getHelpName(tmp_ayWO_1311));


}

void help_Menu_restart(help_Menu self){
	menu_Menu_restart((menu_Menu)self);


}

void help_Menu_draw(help_Menu self){
	menu_Menu_draw((menu_Menu)self);


	map_MapObject tmp_LnVx_1316 = self->mo_878;

	CBC_LOW_CAST(tmp_LnVx_1316, map_MapObject)->drawHelpSprite(tmp_LnVx_1316, self->x_495,  self->y_233);

}


help_Menu help_cur_menu = NULL;

void help_loadHelp(){
	help_state = help_HELP;


}

void help_loadMenu(int x, int y){
	

	game_draw_sema->wait(game_draw_sema);
	
	help_state = help_HELP;
	
	if (help_cur_menu != NULL){
		cbcstd_destroyObj((cbcstd_Object*)&(help_cur_menu));
		help_cur_menu = NULL;
	
	}

	int i = y/common_FLOOR_HEIGHT;
	int j = x/common_FLOOR_WIDTH;
	map_MapNode* node = map_getNode(i, j);

	cbcstd_List objects = node->objects;

	map_MapObject to_show = node->bg;

	if (objects->size(objects) > 0){

		to_show = objects->getLast(objects);
	
	}

	help_cur_menu = help_Menu_create(to_show);

	help_cur_menu->restart(help_cur_menu);
	help_state = help_MENU;

	game_draw_sema->release(game_draw_sema);


}

void help_onClick(int x, int y){
	switch (help_state){
		case help_MENU:{

			help_cur_menu->onClick(help_cur_menu, x,  y);
			break;
		}

		case help_HELP:{
			help_loadMenu(x, y);
			break;
		}

		default:{
			break;

		}

	}


}

void help_draw(){
	map_draw();

	help_help_img->draw(help_help_img, 0,  (DIM_Y-1)*common_FLOOR_HEIGHT);
	if (help_state == help_MENU){

		help_cur_menu->draw(help_cur_menu);

	}


}

void help_init(){
	help_help_img = image_Image_create(common_HELP);
	sound_button = help_FakeSoundButton_create();
	to_exec = &help_loadHelp;

}

