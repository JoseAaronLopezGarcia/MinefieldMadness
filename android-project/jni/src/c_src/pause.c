#include <cbc.h>
// public globals
#include <pause.h>
// private globals
const class_id pause_Button__classid__ = -6739051546842466783;
const class_id pause_Menu__classid__ = -5797831296999794398;
//














const char* pause_button_text[MAX_PAUSE_BUTTONS] = {"Resume","Main Menu","Help","Store"};

const char* pause_animation_text = "PAUSE";

pause_Button pause_Button_create(int type, int base_x, int base_y, int base_h){
	pause_Button self = (pause_Button)cbcstd_alloc(sizeof(pause_Button_struct));
	try{
		pause_Button_init(self, type, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void pause_Button_init(pause_Button self, int type, int base_x, int base_y, int base_h){
	pause_Button_initsystem(self);
	pause_Button_inituser(self, type, base_x, base_y, base_h);
}
void pause_Button_initsystem(pause_Button self){
	menu_Button_initsystem((menu_Button)self);
	const static class_id __classid__[4] = {
		-6739051546842466783L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(pause_Button_struct);
	self->_loadText_217 = &pause_Button__loadText_217;
	self->setExec = &pause_Button_setExec;
	self->__end__ = &pause_Button_end;
}
void pause_Button_enduser(pause_Button self){
	menu_Button_enduser((menu_Button)self);
	return;
}
void pause_Button_end(pause_Button self){
	pause_Button_enduser(self);
	pause_Button_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void pause_Button_decrefs(pause_Button self){
}

void pause_Button_inituser(pause_Button self, int type, int base_x, int base_y, int base_h){

	self->text_522 = font_Font_create(font_SIZE_LARGE);
	font_Font tmp_xWka_1271 = self->text_522;

	tmp_xWka_1271->render(tmp_xWka_1271, pause_button_text[type],  font_WHITE, NULL);
	menu_Button_inituser((menu_Button)self, -1, base_x, base_y, base_h);

	self->to_exec_876 = NULL;


}

void pause_Button__loadText_217(pause_Button self, int difficulty_level){
	return;


}

void pause_Button_setExec(pause_Button self, void* to_exec){

	self->to_exec_876 = to_exec;

}


pause_Menu pause_Menu_create(void** to_exec){
	pause_Menu self = (pause_Menu)cbcstd_alloc(sizeof(pause_Menu_struct));
	try{
		pause_Menu_init(self, to_exec);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void pause_Menu_init(pause_Menu self, void** to_exec){
	pause_Menu_initsystem(self);
	pause_Menu_inituser(self, to_exec);
}
void pause_Menu_initsystem(pause_Menu self){
	menu_Menu_initsystem((menu_Menu)self);
	const static class_id __classid__[4] = {
		-5797831296999794398L,
		-3765202318984487348L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(pause_Menu_struct);
	self->_setMaxButtons_414 = &pause_Menu__setMaxButtons_414;
	self->_createButton_136 = &pause_Menu__createButton_136;
	self->_initAnimation_116 = &pause_Menu__initAnimation_116;
	self->restart = &pause_Menu_restart;
	self->__end__ = &pause_Menu_end;
}
void pause_Menu_enduser(pause_Menu self){
	menu_Menu_enduser((menu_Menu)self);
	return;
}
void pause_Menu_end(pause_Menu self){
	pause_Menu_enduser(self);
	pause_Menu_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void pause_Menu_decrefs(pause_Menu self){
}


void pause_Menu_inituser(pause_Menu self, void** to_exec){
	{int i=0; for (; i<MAX_PAUSE_BUTTONS; i++){

		self->to_exec_301[i] = to_exec[i];
	}}

	menu_Menu_inituser((menu_Menu)self);


}

void pause_Menu__setMaxButtons_414(pause_Menu self){

	self->max_buttons_251 = MAX_PAUSE_BUTTONS;


}

menu_Button pause_Menu__createButton_136(pause_Menu self, int i, int base_x, int base_y, int base_h){
	pause_Button ret = pause_Button_create(i, base_x, base_y, base_h);


	ret->setExec(ret, self->to_exec_301[i]);
	menu_Button tmp_cast_m9ug = (menu_Button)(ret);
	return tmp_cast_m9ug;


}

void pause_Menu__initAnimation_116(pause_Menu self){

	self->animation_768 = anim_AnimatedText_create(pause_animation_text);


}

void pause_Menu_restart(pause_Menu self){
	savedata_saveGameStatus();
	menu_Menu_restart((menu_Menu)self);

}


void pause_init(){
	return;
}
