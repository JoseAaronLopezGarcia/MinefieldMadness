#include <cbc.h>
// public globals
#include <main.h>
// private globals
//

























image_Image main_click_img = NULL;
sound_Sound main_click_sound = NULL;

bool main_click_anim = false;
float main_click_anim_state = 0.1f;
int main_click_x = 0;
int main_click_y = 0;

menu_Menu main_menus[7] = {NULL};










int main_cur_menu = main_MAIN_MENU;

void main_startMainMenu(){

	map_waitAnimEnd();


	game_draw_sema->wait(game_draw_sema);


	if (game_total_score > savedata_decrypted.high_scores[difficulty_diff_level]){

		savedata_decrypted.high_scores[difficulty_diff_level] = game_total_score;

		savedata_decrypted.resume_game = 0;
		savedata_save();

	}

	floor_Floor tmp_cast_mRlI = (floor_Floor)(map_getNode(DIM_Y-1, 0)->bg);
	floor_Floor pause_f = tmp_cast_mRlI;

	pause_f->type_867 = floor_START_TYPE;

	character_safe_character = NULL;
	character_n_characters = 0;
	map_emptyMap();
	main_cur_menu = main_MAIN_MENU;

	main_menus[main_cur_menu]->restart(main_menus[main_cur_menu]);
	game_state = game_MENU;
	

	game_draw_sema->release(game_draw_sema);


}

void main_continueGameBought(){

	game_draw_sema->wait(game_draw_sema);
	ads_fullfillReceipt();
	int n_characters = ads_getPack()->n_characters;
	int n_weapons = ads_getPack()->n_weapons;
	game_addNewCharacters(n_characters);
	game_addNewWeapons(n_weapons);

	game_draw_sema->release(game_draw_sema);
	main_resumeGame();


}

void main_buyPackError(){
	main_resumeGame();


}

void main_buyContinuePackCommon(int type){
	main_startNotificationMenu(main_IAP_WAIT);
	ads_buyContinuePack(type);
	#ifdef LINUX
	main_continueGameBought();
	#endif


}

void main_freeContinuePack(){
	ads_loadInterstitials();
	ads_showInterstitials();
	#ifdef LINUX
	main_interstitialOk();
	#endif


}

void main_buyRevealMines(){
	ads_buyRevealMines();
	#ifdef LINUX
	main_onBuyPackMines();
	#endif


}

void main_onBuyPackMines(){
	game_revealMines();
	main_resumeGame();


}

void main_interstitialOk(){
	ads_setPack(3);
	main_continueGameBought();


}

void main_buyContinuePack10(){
	main_buyContinuePackCommon(0);


}

void main_buyContinuePack15(){
	main_buyContinuePackCommon(1);


}

void main_buyContinuePack20(){
	main_buyContinuePackCommon(2);


}

void main_startNewGame(){
	game_startNextGame();


}

void main_copyScore(int menu_type){

	int high_score = savedata_decrypted.high_scores[difficulty_diff_level];
	switch (menu_type){
		case main_LOOSE_MENU:{
			memset(&(game_score), 0, sizeof(game_Score));
			sprintf(&(notification_loose_text[0][0]), notification_loose_format_text[0], game_total_score);
			sprintf(&(notification_loose_text[1][0]), notification_loose_format_text[1], high_score);
			break;
		}

		case main_WON_MENU:{
			game_calculateScore();

			sprintf(&(notification_won_text[0][0]), notification_won_format_text[0], game_score.characters);

			sprintf(&(notification_won_text[1][0]), notification_won_format_text[1], game_score.items);

			sprintf(&(notification_won_text[2][0]), notification_won_format_text[2], game_score.mines);

			sprintf(&(notification_won_text[3][0]), notification_won_format_text[3], game_score.total);
			sprintf(&(notification_won_text[4][0]), notification_won_format_text[4], game_total_score);
			sprintf(&(notification_won_text[5][0]), notification_won_format_text[5], high_score);
			break;

		}

	}


}

void main_startNotificationMenu(int menu_type){

	map_waitAnimEnd();


	game_draw_sema->wait(game_draw_sema);

	floor_Floor tmp_cast_PblQ = (floor_Floor)(map_getNode(DIM_Y-1, 0)->bg);
	floor_Floor pause_f = tmp_cast_PblQ;

	pause_f->type_867 = floor_START_TYPE;

	main_copyScore(menu_type);

	main_cur_menu = menu_type;

	main_menus[main_cur_menu]->restart(main_menus[main_cur_menu]);
	game_state = game_MENU;
	

	game_draw_sema->release(game_draw_sema);


}

void main_startContinueMenu(){
	main_startNotificationMenu(main_CONTINUE_MENU);


}

void main_startLooseMenu(){
	main_startNotificationMenu(main_LOOSE_MENU);


}

void main_startIAPMenu(){
	main_startNotificationMenu(main_IAP_MENU);


}

void main_startPauseMenu(){
	main_startNotificationMenu(main_PAUSE_MENU);


}

void main_resumeGame(){

	game_draw_sema->wait(game_draw_sema);
	
	floor_Floor tmp_cast_oTmP = (floor_Floor)(map_getNode(DIM_Y-1, 0)->bg);
	floor_Floor pause_f = tmp_cast_oTmP;

	pause_f->type_867 = floor_PAUSE_TYPE;

	game_state = game_GAME;
	

	game_draw_sema->release(game_draw_sema);


}

void main_loadHelp(){

	game_draw_sema->wait(game_draw_sema);
	
	floor_Floor tmp_cast_VdCW = (floor_Floor)(map_getNode(DIM_Y-1, 0)->bg);
	floor_Floor pause_f = tmp_cast_VdCW;

	pause_f->type_867 = floor_START_TYPE;

	game_state = game_HELP;
	

	game_draw_sema->release(game_draw_sema);


}

void main_onExit(){

	game_draw_sema->wait(game_draw_sema);
	
	if (game_state == game_HELP){

		game_draw_sema->release(game_draw_sema);
		main_resumeGame();

		game_draw_sema->wait(game_draw_sema);
	}

	if (game_state == game_GAME){
		game_save();
	}

	else{
		switch (main_cur_menu){
			case main_IAP_WAIT:{
				game_save();

				savedata_decrypted.resume_game = 2;
				savedata_save();
				break;
			}

			case main_LOOSE_MENU:{
			}

			case main_IAP_MENU:{
			}

			case main_CONTINUE_MENU:{
			}

			case main_PAUSE_MENU:{
				game_save();
				break;
			}

			case main_WON_MENU:{

				game_draw_sema->release(game_draw_sema);
				game_startNextGame();
				main_resumeGame();

				game_draw_sema->wait(game_draw_sema);
				game_save();
				break;
			}

			default:{
				remove(savedata_state_path);

				savedata_decrypted.resume_game = 0;
				savedata_save();
				break;
			}

		}

	}

	game_quit = true;

	game_draw_sema->release(game_draw_sema);


}

void main_draw(){

	game_draw_sema->wait(game_draw_sema);
	screen_clear();
	
	switch (game_state){
		case game_MENU:{

			main_menus[main_cur_menu]->draw(main_menus[main_cur_menu]);
			break;
		}

		case game_GAME:{
			map_draw();
			break;
		}

		case game_HELP:{
			help_draw();
			break;
		}

		case game_ADS:{
			game_state = game_WAIT_ADS;
			ads_showAds();
			ads_loadAds();
			map_draw();
			break;
		}

		case game_WAIT_ADS:{
		}

		case game_CONTINUE_GAME:{
			break;
		}

		default:{
			cthrow((cbcstd_Exception)(cbcstd_SystemExit_create("Game state not implemented yet or invalid\n")));
			break;

		}

	}

	if (main_click_anim){

		int w = main_click_img->getWidth(main_click_img)*main_click_anim_state;

		int h = main_click_img->getHeight(main_click_img)*main_click_anim_state;
		int x = main_click_x - w/2;
		int y = main_click_y - h/2;

		main_click_img->drawScaled(main_click_img, x,  y,  w,  h);
		main_click_anim_state += 0.1f;
		if (main_click_anim_state > 1.f){
			main_click_anim = false;

		}

	}

	screen_flip();

	game_draw_sema->release(game_draw_sema);


}

void* main_drawThread(void* unused){
	
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
	
	main_click_img = image_Image_create(common_CLICK);
	
	

	timer_Timer capTimer = timer_Timer_create();
	
	

	

	
	while (not game_quit){

		capTimer->start(capTimer);
		
		main_draw();
		

		int frameTicks = capTimer->getTicks(capTimer);
		if (frameTicks < SCREEN_TICKS_PER_FRAME){
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
	
	

		}

	}

	cbcstd_destroyObj((cbcstd_Object*)&(capTimer));
	cbcstd_destroyObj((cbcstd_Object*)&(main_click_img));
	
	return NULL;


}

void main_keyboardMovement(SDL_keysym keys){
	switch (keys.sym){
		case SDLK_RETURN:{
			main_onExit();
			break;
		}

		case SDLK_SPACE:{

			sound_bg_music->play(sound_bg_music);
			break;
		}

		default: break;

	}


}

void* main_controlThread(void* unused){
	int ignore = 0;
	int oldX = -1;
	int oldY = -1;
	
	main_click_sound = sound_Sound_create(common_CLICK_SOUND);
	
	SDL_Event* discard = CBC_NEW(SDL_Event, 1);
	while (SDL_PollEvent(discard)) {};
	cbcstd_destroy(&(discard));
	
	while (not game_quit){
	
		SDL_Delay(1);
		
		if (game_state == game_GAME){
			bool loose = false;
			bool won = false;

			character_characters_sema->wait(character_characters_sema);
			loose = character_n_characters == 0 and character_safe_character == NULL;
			won = character_safe_character != NULL;

			character_characters_sema->release(character_characters_sema);
			if (loose or won){
				map_waitAnimEnd();
				if (loose){
					main_startNotificationMenu(main_LOOSE_MENU);
				}

				if (won){
					main_startNotificationMenu(main_WON_MENU);
			
				}

			}

		}

		SDL_Event event;
		SDL_keysym keys;
		
		

		SDL_MouseButtonEvent mouse_event;






		SDL_PollEvent(&event);
		if (keyboard_readKeyDown(&event, &keys)){
			main_keyboardMovement(keys);
		}

		if (mouse_readButtons(&event, &mouse_event)){
		
			SDL_DisplayMode dm;
			SDL_GetCurrentDisplayMode(0, &dm);
			
			float w_ratio = (float)screen_width/(float)dm.w;
			float h_ratio = (float)screen_height/(float)dm.h;
		
			mouse_event.x *= w_ratio;
			mouse_event.y *= h_ratio;
		
			if (mouse_event.x == oldX and mouse_event.y == oldY){
				continue;
			}

			else{
				oldX = mouse_event.x;
				oldY = mouse_event.y;
			
			}

			#ifdef PC
			if (mouse_event.button != SDL_BUTTON_LEFT){
				continue;
			}

			#endif
				

			main_click_sound->play(main_click_sound);
			main_click_anim = true;
			main_click_anim_state = 0.1f;
			main_click_x = mouse_event.x;
			main_click_y = mouse_event.y;
			map_last_x = main_click_x;
			map_last_y = main_click_y;
			switch (game_state){
				case game_MENU:{

					main_menus[main_cur_menu]->onClick(main_menus[main_cur_menu], main_click_x,  main_click_y);
					break;
				}

				case game_GAME:{
					if (main_click_y/common_FLOOR_HEIGHT == DIM_Y-1 and main_click_x/common_FLOOR_WIDTH == 0){
						main_startPauseMenu();
					}

					else{
						game_debugMines(main_click_x, main_click_y);
						map_onClick(main_click_x, main_click_y);
					}

					break;
				}

				case game_HELP:{
					if (main_click_y/common_FLOOR_HEIGHT == DIM_Y-1 and main_click_x/common_FLOOR_WIDTH == 0){
						main_resumeGame();
					}

					else{
						help_onClick(main_click_x, main_click_y);
					}

					break;
				}

				case game_ADS:{
				}

				case game_CONTINUE_GAME:{
					break;
				}

				default:{
					cthrow((cbcstd_Exception)(cbcstd_SystemExit_create("Game state not implemented yet or invalid\n")));
					break;
				}

			}

		}

	}

	return NULL;


}

int main_main(){
	
	srand(time(NULL));
	
	static void* pause_exec[MAX_PAUSE_BUTTONS] = {&main_resumeGame, &main_startMainMenu, &main_loadHelp, &main_startIAPMenu};
	static void* continue_execs[6] = {NULL, &main_freeContinuePack, &main_buyContinuePack10,&main_buyContinuePack15, &main_buyContinuePack20, &main_startLooseMenu};
	static void* iap_execs[6] = {main_buyRevealMines, &main_freeContinuePack, &main_buyContinuePack10,&main_buyContinuePack15, &main_buyContinuePack20, &main_startPauseMenu};
	
	main_copyScore(main_WON_MENU);
	main_copyScore(main_LOOSE_MENU);
	main_menus[0] = menu_Menu_create();
	main_menus[1] = notification_Menu_create(notification_WON,  &(game_startNextGame),  NULL);
	main_menus[2] = notification_Menu_create(notification_LOOSE,  &(main_startMainMenu),  &(main_startContinueMenu));
	main_menus[3] = pause_Menu_create(pause_exec);
	main_menus[4] = notification_IAPMenu_create(notification_CONTINUE, continue_execs);
	main_menus[5] = notification_Menu_create(notification_WAIT,  NULL,  NULL);
	main_menus[6] = notification_IAPMenu_create(notification_IAP, iap_execs);

	try{
		game_resumeGame();

		if (savedata_decrypted.resume_game == 2){
			main_startNotificationMenu(main_IAP_WAIT);
			ads_checkContinuePack();
		}

		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
		}
	ccatch{
		cbcstd_Exception sys_tmp_exc = cbcstd_getRaisedException();
		if(0){}
		cbc_catch(cbcstd_Exception){
			cbcstd_Exception tmp_cast_oIGm = (cbcstd_Exception)(sys_tmp_exc);
			cbcstd_Exception e = tmp_cast_oIGm;
			remove(savedata_state_path);
			map_emptyMap();
	
		}
		else{cthrow(sys_tmp_exc);}
		sys_tmp_exc->__end__(sys_tmp_exc);
	}
	finally{}etry;
	cbcstd_Thread controller = cbcstd_Thread_create(&main_controlThread, NULL);
	

	controller->run(controller);


	sound_sound_state = savedata_decrypted.sound_state;
	sound_playBackground();
	
	game_can_exit = true;
	main_drawThread(NULL);
	

	controller->waitThreadEnd(controller, 0);
	
	cbcstd_destroyObj((cbcstd_Object*)&(controller));
	
	map_emptyMap();
	
	map_destroyMap();
	
	

	Mix_Quit();
	IMG_Quit();
	SDL_Quit();

	exit(0);

	return 0;

}

void main_init(){
	return;
}

void cbcinit(int argc, char** argv){
	cbcstd_gcSetState(0);
	cbcstd_setArguments(argc, argv);
	cbcstd_init();
	difficulty_init();
	common_init();
	screen_init();
	image_init();
	font_init();
	sound_init();
	map_init();
	floor_init();
	savedata_init();
	keyboard_init();
	mouse_init();
	astar_init();
	pathfinder_init();
	character_init();
	missil_init();
	grenade_init();
	lawnmower_init();
	teleporter_init();
	minedetector_init();
	flamethrower_init();
	lifeup_init();
	cow_init();
	napalm_init();
	magnet_init();
	laser_init();
	ads_init();
	game_init();
	anim_init();
	menu_init();
	notification_init();
	pause_init();
	help_init();
	timer_init();
	main_init();

}

int main(int argc, char** argv){

	cbcinit(argc, argv);
	return main_main();
}
