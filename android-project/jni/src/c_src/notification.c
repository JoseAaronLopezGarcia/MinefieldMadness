#include <cbc.h>
// public globals
#include <notification.h>
// private globals
const class_id notification_FakeButton__classid__ = -8510171112188141736;
const class_id notification_Button__classid__ = -5023131452191327025;
const class_id notification_IAPFakeButton__classid__ = 7927467762645151307;
const class_id notification_IAPButton__classid__ = -7877009322508308960;
const class_id notification_Menu__classid__ = 2734011580813432524;
const class_id notification_IAPMenu__classid__ = -2484826889200747909;
//

















const char* notification_button_text[3] = {"Next Level","Main Menu","Continue?"};

const char* notification_iap_text[11] = {"Show mines: show this level's mines for $0.99","Free: watch an ad and get a free character","Pack 1: 1 character and 10 items","Pack 2: 3 characters and 15 items","Pack 3: 5 characters and 20 items","Show mines","Watch Ad","Pack 1: $0.99","Pack 2: $1.29","Pack 3: $1.49","Cancel"};

const char* notification_animation_text[4] = {"YOU WON!","YOU LOOSE!","Continue?","Please Wait"};

const char* notification_iap_animation_text[2] = {"Available Purchases","Continue?"};

const char* notification_won_format_text[6] = {"Number of saved characters:    %d","Number of unused items:        %d","Number of hidden mines:        %d","Level Score:                   %ld","Total Score:                   %ld","High Score:                    %ld"};

char notification_won_text[6][128] = {0};

const char* notification_loose_format_text[2] = {"Your total score:             %ld","Highest score:                %ld"};

char notification_loose_text[2][128] = {0};

const char* notification_wait_text[3] = {"Your transaction is being processed","If you encounter problems, you can","safely exit the game and come back."};

notification_FakeButton notification_FakeButton_create(const char* text, int base_x, int base_y, int base_h){
	notification_FakeButton self = (notification_FakeButton)cbcstd_alloc(sizeof(notification_FakeButton_struct));
	try{
		notification_FakeButton_init(self, text, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void notification_FakeButton_init(notification_FakeButton self, const char* text, int base_x, int base_y, int base_h){
	notification_FakeButton_initsystem(self);
	notification_FakeButton_inituser(self, text, base_x, base_y, base_h);
}
void notification_FakeButton_initsystem(notification_FakeButton self){
	menu_Button_initsystem((menu_Button)self);
	const static class_id __classid__[4] = {
		-8510171112188141736L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(notification_FakeButton_struct);
	self->_loadText_217 = &notification_FakeButton__loadText_217;
	self->reloadText = &notification_FakeButton_reloadText;
	self->onClick = &notification_FakeButton_onClick;
	self->draw = &notification_FakeButton_draw;
	self->__end__ = &notification_FakeButton_end;
}
void notification_FakeButton_enduser(notification_FakeButton self){
	menu_Button_enduser((menu_Button)self);
	return;
}
void notification_FakeButton_end(notification_FakeButton self){
	notification_FakeButton_enduser(self);
	notification_FakeButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void notification_FakeButton_decrefs(notification_FakeButton self){
}



void notification_FakeButton_inituser(notification_FakeButton self, const char* text, int base_x, int base_y, int base_h){

	self->to_show_184 = text;
	menu_Button_inituser((menu_Button)self, -1, base_x, base_y, base_h);

	self->to_exec_876 = NULL;


}

void notification_FakeButton__loadText_217(notification_FakeButton self, int difficulty_level){

	self->text_522 = font_Font_create(font_SIZE_MEDIUM);

	font_Font tmp_dpM3_1214 = self->text_522;

	tmp_dpM3_1214->render(tmp_dpM3_1214, self->to_show_184,  font_WHITE, NULL);


}

void notification_FakeButton_reloadText(notification_FakeButton self){

	self->reload_609 = true;


}

void notification_FakeButton_onClick(notification_FakeButton self, int x, int y){
	return;


}

void notification_FakeButton_draw(notification_FakeButton self){

	if (self->reload_609){

		font_Font tmp_xdY1_1219 = self->text_522;

		tmp_xdY1_1219->render(tmp_xdY1_1219, self->to_show_184,  font_WHITE, NULL);

		self->reload_609 = false;
	}



	font_Font tmp_uY7O_1224 = self->text_522;

	tmp_uY7O_1224->draw(tmp_uY7O_1224, self->font_x_343,  self->font_y_812);

}


notification_Button notification_Button_create(char* text, int base_x, int base_y, int base_h){
	notification_Button self = (notification_Button)cbcstd_alloc(sizeof(notification_Button_struct));
	try{
		notification_Button_init(self, text, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void notification_Button_init(notification_Button self, char* text, int base_x, int base_y, int base_h){
	notification_Button_initsystem(self);
	notification_Button_inituser(self, text, base_x, base_y, base_h);
}
void notification_Button_initsystem(notification_Button self){
	menu_Button_initsystem((menu_Button)self);
	const static class_id __classid__[4] = {
		-5023131452191327025L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(notification_Button_struct);
	self->_loadText_217 = &notification_Button__loadText_217;
	self->setExec = &notification_Button_setExec;
	self->__end__ = &notification_Button_end;
}
void notification_Button_enduser(notification_Button self){
	menu_Button_enduser((menu_Button)self);
	return;
}
void notification_Button_end(notification_Button self){
	notification_Button_enduser(self);
	notification_Button_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void notification_Button_decrefs(notification_Button self){
}

void notification_Button_inituser(notification_Button self, char* text, int base_x, int base_y, int base_h){

	self->text_522 = font_Font_create(font_SIZE_LARGE);
	font_Font tmp_8F0L_1227 = self->text_522;

	tmp_8F0L_1227->render(tmp_8F0L_1227, text,  font_WHITE, NULL);
	menu_Button_inituser((menu_Button)self, -1, base_x, base_y, base_h);

	self->to_exec_876 = NULL;


}

void notification_Button__loadText_217(notification_Button self, int difficulty_level){
	return;


}

void notification_Button_setExec(notification_Button self, void* to_exec){

	self->to_exec_876 = to_exec;

}


notification_IAPFakeButton notification_IAPFakeButton_create(int i, int base_x, int base_y, int base_h){
	notification_IAPFakeButton self = (notification_IAPFakeButton)cbcstd_alloc(sizeof(notification_IAPFakeButton_struct));
	try{
		notification_IAPFakeButton_init(self, i, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void notification_IAPFakeButton_init(notification_IAPFakeButton self, int i, int base_x, int base_y, int base_h){
	notification_IAPFakeButton_initsystem(self);
	notification_IAPFakeButton_inituser(self, i, base_x, base_y, base_h);
}
void notification_IAPFakeButton_initsystem(notification_IAPFakeButton self){
	notification_FakeButton_initsystem((notification_FakeButton)self);
	const static class_id __classid__[5] = {
		7927467762645151307L,
		-8510171112188141736L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(notification_IAPFakeButton_struct);
	self->draw = &notification_IAPFakeButton_draw;
	self->__end__ = &notification_IAPFakeButton_end;
}
void notification_IAPFakeButton_enduser(notification_IAPFakeButton self){
	notification_FakeButton_enduser((notification_FakeButton)self);
	return;
}
void notification_IAPFakeButton_end(notification_IAPFakeButton self){
	notification_IAPFakeButton_enduser(self);
	notification_IAPFakeButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void notification_IAPFakeButton_decrefs(notification_IAPFakeButton self){
}


void notification_IAPFakeButton_inituser(notification_IAPFakeButton self, int i, int base_x, int base_y, int base_h){

	self->i_774 = i;
	notification_FakeButton_inituser((notification_FakeButton)self, notification_iap_text[i], base_x, base_y, base_h);


}

void notification_IAPFakeButton_draw(notification_IAPFakeButton self){


	if ((self->i_774==1 or self->i_774==6) and not ads_interstitial){
		return;
	}

	notification_FakeButton_draw((notification_FakeButton)self);

}


notification_IAPButton notification_IAPButton_create(int i, int base_x, int base_y, int base_h){
	notification_IAPButton self = (notification_IAPButton)cbcstd_alloc(sizeof(notification_IAPButton_struct));
	try{
		notification_IAPButton_init(self, i, base_x, base_y, base_h);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void notification_IAPButton_init(notification_IAPButton self, int i, int base_x, int base_y, int base_h){
	notification_IAPButton_initsystem(self);
	notification_IAPButton_inituser(self, i, base_x, base_y, base_h);
}
void notification_IAPButton_initsystem(notification_IAPButton self){
	notification_Button_initsystem((notification_Button)self);
	const static class_id __classid__[5] = {
		-7877009322508308960L,
		-5023131452191327025L,
		3556920588130727727L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(notification_IAPButton_struct);
	self->draw = &notification_IAPButton_draw;
	self->onClick = &notification_IAPButton_onClick;
	self->__end__ = &notification_IAPButton_end;
}
void notification_IAPButton_enduser(notification_IAPButton self){
	notification_Button_enduser((notification_Button)self);
	return;
}
void notification_IAPButton_end(notification_IAPButton self){
	notification_IAPButton_enduser(self);
	notification_IAPButton_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void notification_IAPButton_decrefs(notification_IAPButton self){
}


void notification_IAPButton_inituser(notification_IAPButton self, int i, int base_x, int base_y, int base_h){

	self->i_702 = i;
	notification_Button_inituser((notification_Button)self, notification_iap_text[i], base_x, base_y, base_h);


}

void notification_IAPButton_draw(notification_IAPButton self){


	if ((self->i_702==1 or self->i_702==6) and not ads_interstitial){
		return;
	}

	menu_Button_draw((menu_Button)self);


}

void notification_IAPButton_onClick(notification_IAPButton self, int x, int y){


	if ((self->i_702==1 or self->i_702==6) and not ads_interstitial){
		return;
	}

	menu_Button_onClick((menu_Button)self, x, y);

}


notification_Menu notification_Menu_create(int type, void* to_exec, void* to_exec2){
	notification_Menu self = (notification_Menu)cbcstd_alloc(sizeof(notification_Menu_struct));
	try{
		notification_Menu_init(self, type, to_exec, to_exec2);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void notification_Menu_init(notification_Menu self, int type, void* to_exec, void* to_exec2){
	notification_Menu_initsystem(self);
	notification_Menu_inituser(self, type, to_exec, to_exec2);
}
void notification_Menu_initsystem(notification_Menu self){
	menu_Menu_initsystem((menu_Menu)self);
	const static class_id __classid__[4] = {
		2734011580813432524L,
		-3765202318984487348L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(notification_Menu_struct);
	self->_setMaxButtons_414 = &notification_Menu__setMaxButtons_414;
	self->_createButton_136 = &notification_Menu__createButton_136;
	self->_initAnimation_116 = &notification_Menu__initAnimation_116;
	self->restart = &notification_Menu_restart;
	self->__end__ = &notification_Menu_end;
}
void notification_Menu_enduser(notification_Menu self){
	menu_Menu_enduser((menu_Menu)self);
	return;
}
void notification_Menu_end(notification_Menu self){
	notification_Menu_enduser(self);
	notification_Menu_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void notification_Menu_decrefs(notification_Menu self){
}






void notification_Menu_inituser(notification_Menu self, int type, void* to_exec, void* to_exec2){

	self->type_750 = type;

	self->to_exec_733 = to_exec;

	self->to_exec2_426 = to_exec2;
	menu_Menu_inituser((menu_Menu)self);


}

void notification_Menu__setMaxButtons_414(notification_Menu self){
	static int max_buttons[4] = {7, 4, 3};


	self->max_buttons_251 = max_buttons[self->type_750];


}

menu_Button notification_Menu__createButton_136(notification_Menu self, int i, int base_x, int base_y, int base_h){

	if (self->type_750 == notification_WAIT){
		cbcstd_Object tmp_new_PjBd = (cbcstd_Object)(notification_FakeButton_create(notification_wait_text[i], base_x, base_y, base_h));
		menu_Button tmp_cast_MFt9 = (menu_Button)(tmp_new_PjBd);
		return tmp_cast_MFt9;
	}

	else{


	if (i < self->max_buttons_251-(self->type_750+1)){

		char* text = (self->type_750 == notification_WON)? notification_won_text[i] : notification_loose_text[i];
		cbcstd_Object tmp_new_gGZN = (cbcstd_Object)( notification_FakeButton_create(text, base_x, base_y, base_h));
		menu_Button tmp_cast_jLyW = (menu_Button)(tmp_new_gGZN);
		return tmp_cast_jLyW;
	}

	else{


	if (i == self->max_buttons_251-1 and self->type_750 == notification_LOOSE){
		notification_Button ret = notification_Button_create(notification_button_text[2], base_x, base_y, base_h);


		ret->setExec(ret, self->to_exec2_426);
		return ret;
	}

	}}

	notification_Button ret = notification_Button_create(notification_button_text[self->type_750], base_x, base_y, base_h);


	ret->setExec(ret, self->to_exec_733);
	menu_Button tmp_cast_DNvF = (menu_Button)(ret);
	return tmp_cast_DNvF;


}

void notification_Menu__initAnimation_116(notification_Menu self){


	self->animation_768 = anim_AnimatedText_create(notification_animation_text[self->type_750]);


}

void notification_Menu_restart(notification_Menu self){
	menu_Menu_restart((menu_Menu)self);
	

	{int i=0; for (; i<self->max_buttons_251; i++){

		if (istypeof(self->buttons_99[i], notification_FakeButton)){

			notification_FakeButton button = self->buttons_99[i];

			button->reloadText(button);
		}

	}}


}


notification_IAPMenu notification_IAPMenu_create(int type, void* to_exec){
	notification_IAPMenu self = (notification_IAPMenu)cbcstd_alloc(sizeof(notification_IAPMenu_struct));
	try{
		notification_IAPMenu_init(self, type, to_exec);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void notification_IAPMenu_init(notification_IAPMenu self, int type, void* to_exec){
	notification_IAPMenu_initsystem(self);
	notification_IAPMenu_inituser(self, type, to_exec);
}
void notification_IAPMenu_initsystem(notification_IAPMenu self){
	notification_Menu_initsystem((notification_Menu)self);
	const static class_id __classid__[5] = {
		-2484826889200747909L,
		2734011580813432524L,
		-3765202318984487348L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(notification_IAPMenu_struct);
	self->_setMaxButtons_414 = &notification_IAPMenu__setMaxButtons_414;
	self->_createButton_136 = &notification_IAPMenu__createButton_136;
	self->_initAnimation_116 = &notification_IAPMenu__initAnimation_116;
	self->__end__ = &notification_IAPMenu_end;
}
void notification_IAPMenu_enduser(notification_IAPMenu self){
	notification_Menu_enduser((notification_Menu)self);
	return;
}
void notification_IAPMenu_end(notification_IAPMenu self){
	notification_IAPMenu_enduser(self);
	notification_IAPMenu_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void notification_IAPMenu_decrefs(notification_IAPMenu self){
}

void notification_IAPMenu_inituser(notification_IAPMenu self, int type, void* to_exec){

	self->type_750 = type;

	self->to_exec_733 = to_exec;

	self->to_exec2_426 = NULL;
	menu_Menu_inituser((menu_Menu)self);


}

void notification_IAPMenu__setMaxButtons_414(notification_IAPMenu self){

	self->max_buttons_251 = 11;


}

menu_Button notification_IAPMenu__createButton_136(notification_IAPMenu self, int i, int base_x, int base_y, int base_h){
	
	

	if ((i==0 or i==5) and self->type_750 == notification_CONTINUE){
		cbcstd_Object tmp_new_FVcp = (cbcstd_Object)(notification_FakeButton_create(" ", base_x, base_y, base_h));
		menu_Button tmp_cast_zsCh = (menu_Button)(tmp_new_FVcp);
		return tmp_cast_zsCh;
	}

	if (i < 5){
		cbcstd_Object tmp_new_Wkt7 = (cbcstd_Object)( notification_IAPFakeButton_create(i, base_x, base_y, base_h));
		menu_Button tmp_cast_OeVV = (menu_Button)(tmp_new_Wkt7);
		return tmp_cast_OeVV;
	}


	void** to_exec = (void**)(self->to_exec_733);
	notification_Button ret = notification_IAPButton_create(i, base_x, base_y, base_h);

	ret->setExec(ret, to_exec[i-5]);
	menu_Button tmp_cast_xRMJ = (menu_Button)(ret);
	return tmp_cast_xRMJ;


}

void notification_IAPMenu__initAnimation_116(notification_IAPMenu self){


	self->animation_768 = anim_AnimatedText_create(notification_iap_animation_text[self->type_750]);

}


void notification_init(){
	return;
}
