#ifndef MENU_H
#define MENU_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// map imports
#include <map.h>
//
// common imports
#include <common.h>
//
// image imports
#include <image.h>
//
// font imports
#include <font.h>
//
// game imports
#include <game.h>
//
// anim imports
#include <anim.h>
//
// sound imports
#include <sound.h>
//
// difficulty imports
#include <difficulty.h>
//
// savedata imports
#include <savedata.h>
//
// public globals









extern image_Image menu_box_img;

extern image_Image menu_button_img;

extern image_Image menu_sound_img;

extern const SDL_Rect menu_button_normal;

extern const SDL_Rect menu_button_pressed;

extern const int menu_box_w;

extern const int menu_box_h;

extern const int menu_sound_w;

typedef struct menu_Button_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct menu_Button_struct* self);
	void* (* __getvtable__)(struct menu_Button_struct* self, class_id id);
	int (* __cmp__)(struct menu_Button_struct* self, struct menu_Button_struct* other);
	struct menu_Button_struct* (* __operate__)(struct menu_Button_struct* self, struct menu_Button_struct* other);
	void* (* __str__)(struct menu_Button_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct menu_Button_struct* self, int difficulty_level);
	void (* onClick)(struct menu_Button_struct* self, int x, int y);
	void (* draw)(struct menu_Button_struct* self);
	bool (* clicked)(struct menu_Button_struct* self, int x, int y);
} menu_Button_struct;
typedef menu_Button_struct* menu_Button;
extern const class_id menu_Button__classid__;
extern menu_Button menu_Button_create(int difficulty_level, int base_x, int base_y, int base_h);
extern void menu_Button_init(menu_Button self, int difficulty_level, int base_x, int base_y, int base_h);
extern void menu_Button_initsystem(menu_Button self);
extern void menu_Button_inituser(menu_Button self, int difficulty_level, int base_x, int base_y, int base_h);
extern void menu_Button__loadText_217(menu_Button self, int difficulty_level);
extern void menu_Button_onClick(menu_Button self, int x, int y);
extern void menu_Button_draw(menu_Button self);
extern bool menu_Button_clicked(menu_Button self, int x, int y);
extern void menu_Button_enduser(menu_Button self);
extern void menu_Button_end(menu_Button self);

typedef struct menu_SoundButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct menu_SoundButton_struct* self);
	void* (* __getvtable__)(struct menu_SoundButton_struct* self, class_id id);
	int (* __cmp__)(struct menu_SoundButton_struct* self, struct menu_SoundButton_struct* other);
	struct menu_SoundButton_struct* (* __operate__)(struct menu_SoundButton_struct* self, struct menu_SoundButton_struct* other);
	void* (* __str__)(struct menu_SoundButton_struct* self);
	SDL_Rect rect_843;
	int x_375;
	int y_568;
	void (* draw)(struct menu_SoundButton_struct* self);
	void (* onClick)(struct menu_SoundButton_struct* self, int x, int y);
	bool (* clicked)(struct menu_SoundButton_struct* self, int x, int y);
} menu_SoundButton_struct;
typedef menu_SoundButton_struct* menu_SoundButton;
extern const class_id menu_SoundButton__classid__;
extern menu_SoundButton menu_SoundButton_create();
extern void menu_SoundButton_init(menu_SoundButton self);
extern void menu_SoundButton_initsystem(menu_SoundButton self);
extern void menu_SoundButton_inituser(menu_SoundButton self);
extern void menu_SoundButton_draw(menu_SoundButton self);
extern void menu_SoundButton_onClick(menu_SoundButton self, int x, int y);
extern bool menu_SoundButton_clicked(menu_SoundButton self, int x, int y);
extern void menu_SoundButton_enduser(menu_SoundButton self);
extern void menu_SoundButton_end(menu_SoundButton self);

extern menu_SoundButton menu_sound_button;

typedef struct menu_Menu_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct menu_Menu_struct* self);
	void* (* __getvtable__)(struct menu_Menu_struct* self, class_id id);
	int (* __cmp__)(struct menu_Menu_struct* self, struct menu_Menu_struct* other);
	struct menu_Menu_struct* (* __operate__)(struct menu_Menu_struct* self, struct menu_Menu_struct* other);
	void* (* __str__)(struct menu_Menu_struct* self);
	int x_495;
	int y_233;
	int max_buttons_251;
	menu_Button* buttons_99;
	menu_SoundButton button_sound_227;
	anim_AnimatedText animation_768;
	void (* _setMaxButtons_414)(struct menu_Menu_struct* self);
	void (* _initButtons_6)(struct menu_Menu_struct* self);
	menu_Button (* _createButton_136)(struct menu_Menu_struct* self, int i, int base_x, int base_y, int base_h);
	void (* _initAnimation_116)(struct menu_Menu_struct* self);
	void (* draw)(struct menu_Menu_struct* self);
	void (* onClick)(struct menu_Menu_struct* self, int x, int y);
	void (* restart)(struct menu_Menu_struct* self);
} menu_Menu_struct;
typedef menu_Menu_struct* menu_Menu;
extern const class_id menu_Menu__classid__;
extern menu_Menu menu_Menu_create();
extern void menu_Menu_init(menu_Menu self);
extern void menu_Menu_initsystem(menu_Menu self);
extern void menu_Menu_inituser(menu_Menu self);
extern void menu_Menu__setMaxButtons_414(menu_Menu self);
extern void menu_Menu__initButtons_6(menu_Menu self);
extern menu_Button menu_Menu__createButton_136(menu_Menu self, int i, int base_x, int base_y, int base_h);
extern void menu_Menu__initAnimation_116(menu_Menu self);
extern void menu_Menu_draw(menu_Menu self);
extern void menu_Menu_onClick(menu_Menu self, int x, int y);
extern void menu_Menu_restart(menu_Menu self);
extern void menu_Menu_enduser(menu_Menu self);
extern void menu_Menu_end(menu_Menu self);

extern void menu_init();





#ifdef __cplusplus
};
#endif


#endif//
