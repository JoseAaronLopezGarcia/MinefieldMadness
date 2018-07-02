#ifndef NOTIFICATION_H
#define NOTIFICATION_H


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
// ads imports
#include <ads.h>
//
// public globals







typedef enum{
	notification_WON,
	notification_LOOSE,
	notification_WAIT,
};




typedef enum{
	notification_IAP,
	notification_CONTINUE,
};



extern const char* notification_button_text[3];

extern const char* notification_iap_text[11];

extern const char* notification_animation_text[4];

extern const char* notification_iap_animation_text[2];

extern const char* notification_won_format_text[6];

extern char notification_won_text[6][128];

extern const char* notification_loose_format_text[2];

extern char notification_loose_text[2][128];

extern const char* notification_wait_text[3];

typedef struct notification_FakeButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct notification_FakeButton_struct* self);
	void* (* __getvtable__)(struct notification_FakeButton_struct* self, class_id id);
	int (* __cmp__)(struct notification_FakeButton_struct* self, struct notification_FakeButton_struct* other);
	struct notification_FakeButton_struct* (* __operate__)(struct notification_FakeButton_struct* self, struct notification_FakeButton_struct* other);
	void* (* __str__)(struct notification_FakeButton_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct notification_FakeButton_struct* self, int difficulty_level);
	void (* onClick)(struct notification_FakeButton_struct* self, int x, int y);
	void (* draw)(struct notification_FakeButton_struct* self);
	bool (* clicked)(struct notification_FakeButton_struct* self, int x, int y);
	char* to_show_184;
	bool reload_609;
	void (* reloadText)(struct notification_FakeButton_struct* self);
} notification_FakeButton_struct;
typedef notification_FakeButton_struct* notification_FakeButton;
extern const class_id notification_FakeButton__classid__;
extern notification_FakeButton notification_FakeButton_create(const char* text, int base_x, int base_y, int base_h);
extern void notification_FakeButton_init(notification_FakeButton self, const char* text, int base_x, int base_y, int base_h);
extern void notification_FakeButton_initsystem(notification_FakeButton self);
extern void notification_FakeButton_inituser(notification_FakeButton self, const char* text, int base_x, int base_y, int base_h);
extern void notification_FakeButton__loadText_217(notification_FakeButton self, int difficulty_level);
extern void notification_FakeButton_reloadText(notification_FakeButton self);
extern void notification_FakeButton_onClick(notification_FakeButton self, int x, int y);
extern void notification_FakeButton_draw(notification_FakeButton self);
extern void notification_FakeButton_enduser(notification_FakeButton self);
extern void notification_FakeButton_end(notification_FakeButton self);

typedef struct notification_Button_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct notification_Button_struct* self);
	void* (* __getvtable__)(struct notification_Button_struct* self, class_id id);
	int (* __cmp__)(struct notification_Button_struct* self, struct notification_Button_struct* other);
	struct notification_Button_struct* (* __operate__)(struct notification_Button_struct* self, struct notification_Button_struct* other);
	void* (* __str__)(struct notification_Button_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct notification_Button_struct* self, int difficulty_level);
	void (* onClick)(struct notification_Button_struct* self, int x, int y);
	void (* draw)(struct notification_Button_struct* self);
	bool (* clicked)(struct notification_Button_struct* self, int x, int y);
	void (* setExec)(struct notification_Button_struct* self, void* to_exec);
} notification_Button_struct;
typedef notification_Button_struct* notification_Button;
extern const class_id notification_Button__classid__;
extern notification_Button notification_Button_create(char* text, int base_x, int base_y, int base_h);
extern void notification_Button_init(notification_Button self, char* text, int base_x, int base_y, int base_h);
extern void notification_Button_initsystem(notification_Button self);
extern void notification_Button_inituser(notification_Button self, char* text, int base_x, int base_y, int base_h);
extern void notification_Button__loadText_217(notification_Button self, int difficulty_level);
extern void notification_Button_setExec(notification_Button self, void* to_exec);
extern void notification_Button_enduser(notification_Button self);
extern void notification_Button_end(notification_Button self);

typedef struct notification_IAPFakeButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct notification_IAPFakeButton_struct* self);
	void* (* __getvtable__)(struct notification_IAPFakeButton_struct* self, class_id id);
	int (* __cmp__)(struct notification_IAPFakeButton_struct* self, struct notification_IAPFakeButton_struct* other);
	struct notification_IAPFakeButton_struct* (* __operate__)(struct notification_IAPFakeButton_struct* self, struct notification_IAPFakeButton_struct* other);
	void* (* __str__)(struct notification_IAPFakeButton_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct notification_IAPFakeButton_struct* self, int difficulty_level);
	void (* onClick)(struct notification_IAPFakeButton_struct* self, int x, int y);
	void (* draw)(struct notification_IAPFakeButton_struct* self);
	bool (* clicked)(struct notification_IAPFakeButton_struct* self, int x, int y);
	char* to_show_184;
	bool reload_609;
	void (* reloadText)(struct notification_IAPFakeButton_struct* self);
	int i_774;
} notification_IAPFakeButton_struct;
typedef notification_IAPFakeButton_struct* notification_IAPFakeButton;
extern const class_id notification_IAPFakeButton__classid__;
extern notification_IAPFakeButton notification_IAPFakeButton_create(int i, int base_x, int base_y, int base_h);
extern void notification_IAPFakeButton_init(notification_IAPFakeButton self, int i, int base_x, int base_y, int base_h);
extern void notification_IAPFakeButton_initsystem(notification_IAPFakeButton self);
extern void notification_IAPFakeButton_inituser(notification_IAPFakeButton self, int i, int base_x, int base_y, int base_h);
extern void notification_IAPFakeButton_draw(notification_IAPFakeButton self);
extern void notification_IAPFakeButton_enduser(notification_IAPFakeButton self);
extern void notification_IAPFakeButton_end(notification_IAPFakeButton self);

typedef struct notification_IAPButton_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct notification_IAPButton_struct* self);
	void* (* __getvtable__)(struct notification_IAPButton_struct* self, class_id id);
	int (* __cmp__)(struct notification_IAPButton_struct* self, struct notification_IAPButton_struct* other);
	struct notification_IAPButton_struct* (* __operate__)(struct notification_IAPButton_struct* self, struct notification_IAPButton_struct* other);
	void* (* __str__)(struct notification_IAPButton_struct* self);
	int x_64;
	int y_752;
	bool pressed_646;
	void (* to_exec_876)();
	font_Font text_522;
	int font_x_343;
	int font_y_812;
	void (* _loadText_217)(struct notification_IAPButton_struct* self, int difficulty_level);
	void (* onClick)(struct notification_IAPButton_struct* self, int x, int y);
	void (* draw)(struct notification_IAPButton_struct* self);
	bool (* clicked)(struct notification_IAPButton_struct* self, int x, int y);
	void (* setExec)(struct notification_IAPButton_struct* self, void* to_exec);
	int i_702;
} notification_IAPButton_struct;
typedef notification_IAPButton_struct* notification_IAPButton;
extern const class_id notification_IAPButton__classid__;
extern notification_IAPButton notification_IAPButton_create(int i, int base_x, int base_y, int base_h);
extern void notification_IAPButton_init(notification_IAPButton self, int i, int base_x, int base_y, int base_h);
extern void notification_IAPButton_initsystem(notification_IAPButton self);
extern void notification_IAPButton_inituser(notification_IAPButton self, int i, int base_x, int base_y, int base_h);
extern void notification_IAPButton_draw(notification_IAPButton self);
extern void notification_IAPButton_onClick(notification_IAPButton self, int x, int y);
extern void notification_IAPButton_enduser(notification_IAPButton self);
extern void notification_IAPButton_end(notification_IAPButton self);

typedef struct notification_Menu_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct notification_Menu_struct* self);
	void* (* __getvtable__)(struct notification_Menu_struct* self, class_id id);
	int (* __cmp__)(struct notification_Menu_struct* self, struct notification_Menu_struct* other);
	struct notification_Menu_struct* (* __operate__)(struct notification_Menu_struct* self, struct notification_Menu_struct* other);
	void* (* __str__)(struct notification_Menu_struct* self);
	int x_495;
	int y_233;
	int max_buttons_251;
	menu_Button* buttons_99;
	menu_SoundButton button_sound_227;
	anim_AnimatedText animation_768;
	void (* _setMaxButtons_414)(struct notification_Menu_struct* self);
	void (* _initButtons_6)(struct notification_Menu_struct* self);
	menu_Button (* _createButton_136)(struct notification_Menu_struct* self, int i, int base_x, int base_y, int base_h);
	void (* _initAnimation_116)(struct notification_Menu_struct* self);
	void (* draw)(struct notification_Menu_struct* self);
	void (* onClick)(struct notification_Menu_struct* self, int x, int y);
	void (* restart)(struct notification_Menu_struct* self);
	int type_750;
	void* to_exec_733;
	void* to_exec2_426;
} notification_Menu_struct;
typedef notification_Menu_struct* notification_Menu;
extern const class_id notification_Menu__classid__;
extern notification_Menu notification_Menu_create(int type, void* to_exec, void* to_exec2);
extern void notification_Menu_init(notification_Menu self, int type, void* to_exec, void* to_exec2);
extern void notification_Menu_initsystem(notification_Menu self);
extern void notification_Menu_inituser(notification_Menu self, int type, void* to_exec, void* to_exec2);
extern void notification_Menu__setMaxButtons_414(notification_Menu self);
extern menu_Button notification_Menu__createButton_136(notification_Menu self, int i, int base_x, int base_y, int base_h);
extern void notification_Menu__initAnimation_116(notification_Menu self);
extern void notification_Menu_restart(notification_Menu self);
extern void notification_Menu_enduser(notification_Menu self);
extern void notification_Menu_end(notification_Menu self);

typedef struct notification_IAPMenu_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct notification_IAPMenu_struct* self);
	void* (* __getvtable__)(struct notification_IAPMenu_struct* self, class_id id);
	int (* __cmp__)(struct notification_IAPMenu_struct* self, struct notification_IAPMenu_struct* other);
	struct notification_IAPMenu_struct* (* __operate__)(struct notification_IAPMenu_struct* self, struct notification_IAPMenu_struct* other);
	void* (* __str__)(struct notification_IAPMenu_struct* self);
	int x_495;
	int y_233;
	int max_buttons_251;
	menu_Button* buttons_99;
	menu_SoundButton button_sound_227;
	anim_AnimatedText animation_768;
	void (* _setMaxButtons_414)(struct notification_IAPMenu_struct* self);
	void (* _initButtons_6)(struct notification_IAPMenu_struct* self);
	menu_Button (* _createButton_136)(struct notification_IAPMenu_struct* self, int i, int base_x, int base_y, int base_h);
	void (* _initAnimation_116)(struct notification_IAPMenu_struct* self);
	void (* draw)(struct notification_IAPMenu_struct* self);
	void (* onClick)(struct notification_IAPMenu_struct* self, int x, int y);
	void (* restart)(struct notification_IAPMenu_struct* self);
	int type_750;
	void* to_exec_733;
	void* to_exec2_426;
} notification_IAPMenu_struct;
typedef notification_IAPMenu_struct* notification_IAPMenu;
extern const class_id notification_IAPMenu__classid__;
extern notification_IAPMenu notification_IAPMenu_create(int type, void* to_exec);
extern void notification_IAPMenu_init(notification_IAPMenu self, int type, void* to_exec);
extern void notification_IAPMenu_initsystem(notification_IAPMenu self);
extern void notification_IAPMenu_inituser(notification_IAPMenu self, int type, void* to_exec);
extern void notification_IAPMenu__setMaxButtons_414(notification_IAPMenu self);
extern menu_Button notification_IAPMenu__createButton_136(notification_IAPMenu self, int i, int base_x, int base_y, int base_h);
extern void notification_IAPMenu__initAnimation_116(notification_IAPMenu self);
extern void notification_IAPMenu_enduser(notification_IAPMenu self);
extern void notification_IAPMenu_end(notification_IAPMenu self);







extern void notification_init();

#ifdef __cplusplus
};
#endif


#endif//
