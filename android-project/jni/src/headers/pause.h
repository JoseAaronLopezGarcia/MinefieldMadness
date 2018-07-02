#ifndef PAUSE_H
#define PAUSE_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// menu imports
#include <menu.h>
//
// anim imports
#include <anim.h>
//
// font imports
#include <font.h>
//
// common imports
#include <common.h>
//
// image imports
#include <image.h>
//
// game imports
#include <game.h>
//
// savedata imports
#include <savedata.h>
//
// public globals







#define MAX_PAUSE_BUTTONS 4
typedef enum{
	pause_RESUME,
	pause_QUIT,
};



extern const char* pause_button_text[MAX_PAUSE_BUTTONS];

extern const char* pause_animation_text;

typedef struct pause_Button_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct pause_Button_struct* self);
	void* (* __getvtable__)(struct pause_Button_struct* self, class_id id);
	int (* __cmp__)(struct pause_Button_struct* self, struct pause_Button_struct* other);
	struct pause_Button_struct* (* __operate__)(struct pause_Button_struct* self, struct pause_Button_struct* other);
	void* (* __str__)(struct pause_Button_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct pause_Button_struct* self, int difficulty_level);
	void (* onClick)(struct pause_Button_struct* self, int x, int y);
	void (* draw)(struct pause_Button_struct* self);
	bool (* clicked)(struct pause_Button_struct* self, int x, int y);
	void (* setExec)(struct pause_Button_struct* self, void* to_exec);
} pause_Button_struct;
typedef pause_Button_struct* pause_Button;
extern const class_id pause_Button__classid__;
extern pause_Button pause_Button_create(int type, int base_x, int base_y, int base_h);
extern void pause_Button_init(pause_Button self, int type, int base_x, int base_y, int base_h);
extern void pause_Button_initsystem(pause_Button self);
extern void pause_Button_inituser(pause_Button self, int type, int base_x, int base_y, int base_h);
extern void pause_Button__loadText_217(pause_Button self, int difficulty_level);
extern void pause_Button_setExec(pause_Button self, void* to_exec);
extern void pause_Button_enduser(pause_Button self);
extern void pause_Button_end(pause_Button self);

typedef struct pause_Menu_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct pause_Menu_struct* self);
	void* (* __getvtable__)(struct pause_Menu_struct* self, class_id id);
	int (* __cmp__)(struct pause_Menu_struct* self, struct pause_Menu_struct* other);
	struct pause_Menu_struct* (* __operate__)(struct pause_Menu_struct* self, struct pause_Menu_struct* other);
	void* (* __str__)(struct pause_Menu_struct* self);
	int x_495;
	int y_233;
	int max_buttons_251;
	menu_Button* buttons_99;
	menu_SoundButton button_sound_227;
	anim_AnimatedText animation_768;
	void (* _setMaxButtons_414)(struct pause_Menu_struct* self);
	void (* _initButtons_6)(struct pause_Menu_struct* self);
	menu_Button (* _createButton_136)(struct pause_Menu_struct* self, int i, int base_x, int base_y, int base_h);
	void (* _initAnimation_116)(struct pause_Menu_struct* self);
	void (* draw)(struct pause_Menu_struct* self);
	void (* onClick)(struct pause_Menu_struct* self, int x, int y);
	void (* restart)(struct pause_Menu_struct* self);
	void* to_exec_301[MAX_PAUSE_BUTTONS];
} pause_Menu_struct;
typedef pause_Menu_struct* pause_Menu;
extern const class_id pause_Menu__classid__;
extern pause_Menu pause_Menu_create(void** to_exec);
extern void pause_Menu_init(pause_Menu self, void** to_exec);
extern void pause_Menu_initsystem(pause_Menu self);
extern void pause_Menu_inituser(pause_Menu self, void** to_exec);
extern void pause_Menu__setMaxButtons_414(pause_Menu self);
extern menu_Button pause_Menu__createButton_136(pause_Menu self, int i, int base_x, int base_y, int base_h);
extern void pause_Menu__initAnimation_116(pause_Menu self);
extern void pause_Menu_restart(pause_Menu self);
extern void pause_Menu_enduser(pause_Menu self);
extern void pause_Menu_end(pause_Menu self);



extern void pause_init();

#ifdef __cplusplus
};
#endif


#endif//
