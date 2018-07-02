#ifndef HELP_H
#define HELP_H


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
// notification imports
#include <notification.h>
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
// map imports
#include <map.h>
//
// public globals








typedef enum help_HelpState{
	help_HELP,
	help_MENU,
} help_HelpState;



extern help_HelpState help_state;

extern image_Image help_help_img;

typedef struct help_ImageButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct help_ImageButton_struct* self);
	void* (* __getvtable__)(struct help_ImageButton_struct* self, class_id id);
	int (* __cmp__)(struct help_ImageButton_struct* self, struct help_ImageButton_struct* other);
	struct help_ImageButton_struct* (* __operate__)(struct help_ImageButton_struct* self, struct help_ImageButton_struct* other);
	void* (* __str__)(struct help_ImageButton_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct help_ImageButton_struct* self, int difficulty_level);
	void (* onClick)(struct help_ImageButton_struct* self, int x, int y);
	void (* draw)(struct help_ImageButton_struct* self);
	bool (* clicked)(struct help_ImageButton_struct* self, int x, int y);
	char* to_show_184;
	bool reload_609;
	void (* reloadText)(struct help_ImageButton_struct* self);
	map_MapObject mo_204;
} help_ImageButton_struct;
typedef help_ImageButton_struct* help_ImageButton;
extern const class_id help_ImageButton__classid__;
extern help_ImageButton help_ImageButton_create(map_MapObject mo, int base_x, int base_y, int base_h);
extern void help_ImageButton_init(help_ImageButton self, map_MapObject mo, int base_x, int base_y, int base_h);
extern void help_ImageButton_initsystem(help_ImageButton self);
extern void help_ImageButton_inituser(help_ImageButton self, map_MapObject mo, int base_x, int base_y, int base_h);
extern void help_ImageButton_draw(help_ImageButton self);
extern void help_ImageButton_enduser(help_ImageButton self);
extern void help_ImageButton_end(help_ImageButton self);

typedef struct help_Button_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct help_Button_struct* self);
	void* (* __getvtable__)(struct help_Button_struct* self, class_id id);
	int (* __cmp__)(struct help_Button_struct* self, struct help_Button_struct* other);
	struct help_Button_struct* (* __operate__)(struct help_Button_struct* self, struct help_Button_struct* other);
	void* (* __str__)(struct help_Button_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct help_Button_struct* self, int difficulty_level);
	void (* onClick)(struct help_Button_struct* self, int x, int y);
	void (* draw)(struct help_Button_struct* self);
	bool (* clicked)(struct help_Button_struct* self, int x, int y);
	void (* setExec)(struct help_Button_struct* self, void* to_exec);
	bool rendered_504;
} help_Button_struct;
typedef help_Button_struct* help_Button;
extern const class_id help_Button__classid__;
extern help_Button help_Button_create(int base_x, int base_y, int base_h);
extern void help_Button_init(help_Button self, int base_x, int base_y, int base_h);
extern void help_Button_initsystem(help_Button self);
extern void help_Button_inituser(help_Button self, int base_x, int base_y, int base_h);
extern void help_Button_draw(help_Button self);
extern void help_Button_onClick(help_Button self, int x, int y);
extern void help_Button_enduser(help_Button self);
extern void help_Button_end(help_Button self);

typedef struct help_FakeSoundButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct help_FakeSoundButton_struct* self);
	void* (* __getvtable__)(struct help_FakeSoundButton_struct* self, class_id id);
	int (* __cmp__)(struct help_FakeSoundButton_struct* self, struct help_FakeSoundButton_struct* other);
	struct help_FakeSoundButton_struct* (* __operate__)(struct help_FakeSoundButton_struct* self, struct help_FakeSoundButton_struct* other);
	void* (* __str__)(struct help_FakeSoundButton_struct* self);
	SDL_Rect rect_843;
	int x_375;
	int y_568;
	void (* draw)(struct help_FakeSoundButton_struct* self);
	void (* onClick)(struct help_FakeSoundButton_struct* self, int x, int y);
	bool (* clicked)(struct help_FakeSoundButton_struct* self, int x, int y);
} help_FakeSoundButton_struct;
typedef help_FakeSoundButton_struct* help_FakeSoundButton;
extern const class_id help_FakeSoundButton__classid__;
extern help_FakeSoundButton help_FakeSoundButton_create();
extern void help_FakeSoundButton_init(help_FakeSoundButton self);
extern void help_FakeSoundButton_initsystem(help_FakeSoundButton self);
extern void help_FakeSoundButton_inituser(help_FakeSoundButton self);
extern void help_FakeSoundButton_draw(help_FakeSoundButton self);
extern void help_FakeSoundButton_onClick(help_FakeSoundButton self, int x, int y);
extern void help_FakeSoundButton_enduser(help_FakeSoundButton self);
extern void help_FakeSoundButton_end(help_FakeSoundButton self);

typedef struct help_FakeButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct help_FakeButton_struct* self);
	void* (* __getvtable__)(struct help_FakeButton_struct* self, class_id id);
	int (* __cmp__)(struct help_FakeButton_struct* self, struct help_FakeButton_struct* other);
	struct help_FakeButton_struct* (* __operate__)(struct help_FakeButton_struct* self, struct help_FakeButton_struct* other);
	void* (* __str__)(struct help_FakeButton_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct help_FakeButton_struct* self, int difficulty_level);
	void (* onClick)(struct help_FakeButton_struct* self, int x, int y);
	void (* draw)(struct help_FakeButton_struct* self);
	bool (* clicked)(struct help_FakeButton_struct* self, int x, int y);
	char* to_show_184;
	bool reload_609;
	void (* reloadText)(struct help_FakeButton_struct* self);
	bool rendered_622;
} help_FakeButton_struct;
typedef help_FakeButton_struct* help_FakeButton;
extern const class_id help_FakeButton__classid__;
extern help_FakeButton help_FakeButton_create(const char* text, int base_x, int base_y, int base_h);
extern void help_FakeButton_init(help_FakeButton self, const char* text, int base_x, int base_y, int base_h);
extern void help_FakeButton_initsystem(help_FakeButton self);
extern void help_FakeButton_inituser(help_FakeButton self, const char* text, int base_x, int base_y, int base_h);
extern void help_FakeButton__loadText_217(help_FakeButton self, int difficulty_level);
extern void help_FakeButton_draw(help_FakeButton self);
extern void help_FakeButton_enduser(help_FakeButton self);
extern void help_FakeButton_end(help_FakeButton self);

typedef struct help_Menu_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct help_Menu_struct* self);
	void* (* __getvtable__)(struct help_Menu_struct* self, class_id id);
	int (* __cmp__)(struct help_Menu_struct* self, struct help_Menu_struct* other);
	struct help_Menu_struct* (* __operate__)(struct help_Menu_struct* self, struct help_Menu_struct* other);
	void* (* __str__)(struct help_Menu_struct* self);
	int x_495;
	int y_233;
	int max_buttons_251;
	menu_Button* buttons_99;
	menu_SoundButton button_sound_227;
	anim_AnimatedText animation_768;
	void (* _setMaxButtons_414)(struct help_Menu_struct* self);
	void (* _initButtons_6)(struct help_Menu_struct* self);
	menu_Button (* _createButton_136)(struct help_Menu_struct* self, int i, int base_x, int base_y, int base_h);
	void (* _initAnimation_116)(struct help_Menu_struct* self);
	void (* draw)(struct help_Menu_struct* self);
	void (* onClick)(struct help_Menu_struct* self, int x, int y);
	void (* restart)(struct help_Menu_struct* self);
	int type_750;
	void* to_exec_733;
	void* to_exec2_426;
	map_MapObject mo_878;
} help_Menu_struct;
typedef help_Menu_struct* help_Menu;
extern const class_id help_Menu__classid__;
extern help_Menu help_Menu_create(map_MapObject mo);
extern void help_Menu_init(help_Menu self, map_MapObject mo);
extern void help_Menu_initsystem(help_Menu self);
extern void help_Menu_inituser(help_Menu self, map_MapObject mo);
extern void help_Menu__setMaxButtons_414(help_Menu self);
extern menu_Button help_Menu__createButton_136(help_Menu self, int i, int base_x, int base_y, int base_h);
extern void help_Menu__initAnimation_116(help_Menu self);
extern void help_Menu_restart(help_Menu self);
extern void help_Menu_draw(help_Menu self);
extern void help_Menu_enduser(help_Menu self);
extern void help_Menu_end(help_Menu self);

extern help_Menu help_cur_menu;

extern void help_loadHelp();

extern void help_loadMenu(int x, int y);

extern void help_onClick(int x, int y);

extern void help_draw();

extern void help_init();







#ifdef __cplusplus
};
#endif


#endif//
