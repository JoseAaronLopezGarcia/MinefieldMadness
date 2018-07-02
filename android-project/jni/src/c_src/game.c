#include <cbc.h>
// public globals
#include <game.h>
// private globals
static bool _game_noResume();

//






































bool game_quit = false;
bool game_can_exit = false;









game_GameState game_state = game_MENU;
cbcstd_Semaphore game_draw_sema = NULL;
map_MapObject game_winner = NULL;







game_Score game_score = {0};
long game_total_score = 0;
volatile int game_debugging = 10;

void game_init(){
	game_draw_sema = cbcstd_Semaphore_create(1);
	game_initializeMap();


}

void game_initializeMap(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){
			map_MapObject to_push = NULL;
			if (j==DIM_X-1){
				if (i == (DIM_Y/2)){
					to_push = floor_Floor_create(floor_EXIT_TYPE, i, j);
				}

				else{
					to_push = floor_Floor_create(floor_TABLE_TYPE, i, j);
				}

			}

			else{
			if (j==0){
				to_push = floor_Floor_create(floor_START_TYPE, i, j);
			}

			else{
				to_push = floor_Floor_create(floor_NORMAL_NO_MINE_TYPE, i, j);
			}

			}
			map_addBg(i, j, to_push);

		}}

	}}


}

void game_generateMap(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=1; for (; j<DIM_X-1; j++){
			floor_Floor tmp_cast_u4Wf = (floor_Floor)(map_getNode(i, j)->bg);
			floor_Floor f = tmp_cast_u4Wf;
			int type = 0;
			int r = 0;
			if ((r=rand()%100) and r < difficulty_getDifficultyLevel()->pmine){
				type = floor_NORMAL_MINE_TYPE;
			}

			else{
			if ((r=rand()%100) and r < difficulty_getDifficultyLevel()->pnograss){
				type = floor_DESERT_TYPE;
			}

			else{
			if ((r=rand()%100) and r < difficulty_getDifficultyLevel()->pblockage){
				r=rand()%2;
				type = floor_STONE_TYPE+r;
			}

			else{
				type = floor_NORMAL_NO_MINE_TYPE;
			}

			}}

			f->type_867 = type;

			f->floor_type_172 = rand()%common_MAX_FLOORS;

		}}

	}}


}

void game_insertCharacters(){
	character_safe_character = NULL;
	{int i=0; for (; i<difficulty_getDifficultyLevel()->nplayers; i++){
		map_insertObject(character_Character_create(), i, 0);

	}}


}

void game_reinsertCharacters(){
	int i=0;
	int n_characters = character_n_characters;
	character_n_characters = 0;
	
	int insert_to = 0;
	while (n_characters > 0){
		map_insertObject(character_Character_create(), insert_to, 0);
		insert_to++;
		if (insert_to >= DIM_Y-1){
			insert_to = 0;
		}

		n_characters--;
	
	}

	if (game_winner == NULL){
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("ERROR: trying to start next game when there's no winner")));
	
	}

	map_insertObject(game_winner, insert_to, 0);
	character_selected_character = NULL;
	character_safe_character = NULL;
	character_Character tmp_cast_IorM = (character_Character)(game_winner);

	tmp_cast_IorM->to_x_969 = -1;
	character_Character tmp_cast_V4Af = (character_Character)(game_winner);

	tmp_cast_V4Af->to_y_714 = -1;
	character_n_characters++;
	game_winner = NULL;


}

cbcstd_Object game_getNewItem(int r){
	cbcstd_Object o = NULL;
	switch (r){
		case game_MISSIL:{
			cbcstd_Object tmp_new_5mcf = (cbcstd_Object)(missil_Missil_create());
			cbcstd_Object tmp_cast_E8ia = (cbcstd_Object)(tmp_new_5mcf);
			o = tmp_cast_E8ia;
			break;
		}

		case game_GRENADE:{
			cbcstd_Object tmp_new_LVds = (cbcstd_Object)(grenade_Grenade_create());
			cbcstd_Object tmp_cast_Uawi = (cbcstd_Object)(tmp_new_LVds);
			o = tmp_cast_Uawi;
			break;
		}

		case game_LAWNMOWER:{
			cbcstd_Object tmp_new_qJbc = (cbcstd_Object)(lawnmower_LawnMower_create());
			cbcstd_Object tmp_cast_WTTe = (cbcstd_Object)(tmp_new_qJbc);
			o = tmp_cast_WTTe;
			break;
		}

		case game_TELEPORTER:{
			cbcstd_Object tmp_new_N2sU = (cbcstd_Object)(teleporter_Teleporter_create());
			cbcstd_Object tmp_cast_Avv3 = (cbcstd_Object)(tmp_new_N2sU);
			o = tmp_cast_Avv3;
			break;
		}

		case game_MINEDETECTOR:{
			cbcstd_Object tmp_new_3BkI = (cbcstd_Object)(minedetector_MineDetector_create());
			cbcstd_Object tmp_cast_OZ5k = (cbcstd_Object)(tmp_new_3BkI);
			o = tmp_cast_OZ5k;
			break;
		}

		case game_LIFEUP:{
			cbcstd_Object tmp_new_4PzS = (cbcstd_Object)(lifeup_LifeUp_create());
			cbcstd_Object tmp_cast_EBdi = (cbcstd_Object)(tmp_new_4PzS);
			o = tmp_cast_EBdi;
			break;
		}

		case game_FLAMETHROWER:{
			cbcstd_Object tmp_new_dBng = (cbcstd_Object)(flamethrower_FlameThrower_create());
			cbcstd_Object tmp_cast_1Rjw = (cbcstd_Object)(tmp_new_dBng);
			o = tmp_cast_1Rjw;
			break;
		}

		case game_COW:{
			cbcstd_Object tmp_new_4VV6 = (cbcstd_Object)(cow_Cow_create());
			cbcstd_Object tmp_cast_Ev9I = (cbcstd_Object)(tmp_new_4VV6);
			o = tmp_cast_Ev9I;
			break;
		}

		case game_NAPALM:{
			cbcstd_Object tmp_new_F3ac = (cbcstd_Object)(napalm_Napalm_create());
			cbcstd_Object tmp_cast_SDHx = (cbcstd_Object)(tmp_new_F3ac);
			o = tmp_cast_SDHx;
			break;
		}

		case game_LASER:{
			cbcstd_Object tmp_new_Wwrs = (cbcstd_Object)(laser_Laser_create());
			cbcstd_Object tmp_cast_1ZlO = (cbcstd_Object)(tmp_new_Wwrs);
			o = tmp_cast_1ZlO;
			break;
		}

		case game_MAGNET:{
			cbcstd_Object tmp_new_eVHh = (cbcstd_Object)(magnet_Magnet_create());
			cbcstd_Object tmp_cast_0SPK = (cbcstd_Object)(tmp_new_eVHh);
			o = tmp_cast_0SPK;
			break;
		}

		default:{
			cthrow((cbcstd_Exception)(cbcstd_SystemError_create("ERROR: invalid object id")));
			break;
		}

	}

	return o;


}

cbcstd_Object game_createRandomObject(){
	int r = rand()%11;
	return game_getNewItem(r);


}

void game_insertDefaultItems(){
	map_insertObject(grenade_Grenade_create(), 0, DIM_X-1);
	map_insertObject(lawnmower_LawnMower_create(), 1, DIM_X-1);
	map_insertObject(magnet_Magnet_create(), 2, DIM_X-1);
	

	



}

void game_insertRandomItems(){
	srand(time(NULL));
	{int i=0; for (; i<DIM_Y; i++){
		{int j=1; for (; j<DIM_X-1; j++){
			map_MapNode* node = map_getNode(i, j);

			floor_Floor tmp_cast_Nsz9 = (floor_Floor)(node->bg);
			floor_Floor f = tmp_cast_Nsz9;


			if (f->type_867 == floor_STONE_TYPE or f->type_867 == floor_LAKE_TYPE){
				continue;
			}

			int r = rand()%100;
			if (r < difficulty_getDifficultyLevel()->pitem){
				cbcstd_Object o = game_createRandomObject();
				map_insertObject(o, i, j);

			}

		}}

	}}


}

void game_insertAllItems(){
	game_insertDefaultItems();
	game_insertRandomItems();


}

void game_calculateScore(){







	memset(&game_score, 0, sizeof(game_Score));

	game_score.characters = 1;
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X-1; j++){
			map_MapNode* node = map_getNode(i, j);

			floor_Floor tmp_cast_8Cr2 = (floor_Floor)(node->bg);
			floor_Floor f = tmp_cast_8Cr2;

			cbcstd_List objects = node->objects;

			if (f->type_867 == floor_NORMAL_MINE_TYPE){

				game_score.mines++;
			}

			{map_MapObject mo=NULL;CBC_FOREACH(objects, mo){
				cbcstd_Object tmp_cast_tkCa = (cbcstd_Object)(mo);
				cbcstd_Object o = tmp_cast_tkCa;
				if (istypeof(o, character_Character)){

					game_score.characters++;
				}

			}}

		}}

	}}

	{int i=0; for (; i<DIM_Y; i++){
		map_MapNode* node = map_getNode(i, DIM_X-1);



		game_score.items += node->objects->size(node->objects);
	
	}}



	game_score.total += game_score.items * difficulty_getDifficultyLevel()->s_items;


	game_score.total += game_score.characters * difficulty_getDifficultyLevel()->s_chars;


	game_score.total += game_score.mines * difficulty_getDifficultyLevel()->s_mines;

	game_total_score += game_score.total;
	

	if (game_total_score > savedata_decrypted.high_scores[difficulty_diff_level]){

		savedata_decrypted.high_scores[difficulty_diff_level] = game_total_score;
		savedata_save();
	
	}

	return;


}

void game_doAds(){
	#ifdef ANDROID
	game_state = game_ADS;
	while (game_state != game_CONTINUE_GAME){
		SDL_Delay(0);
	}

	#endif


}

void game_startGame(){

	game_draw_sema->wait(game_draw_sema);
	game_winner = NULL;
	game_total_score = 0;
	floor_Floor tmp_cast_C5sf = (floor_Floor)(map_getNode(DIM_Y-1, 0)->bg);
	floor_Floor pause_f = tmp_cast_C5sf;

	pause_f->type_867 = floor_PAUSE_TYPE;
	game_generateMap();
	game_insertCharacters();
	game_insertAllItems();
	game_state = game_GAME;
	game_debugging = 0;

	game_draw_sema->release(game_draw_sema);


}

void game_startNextGame(){
	game_doAds();

	game_draw_sema->wait(game_draw_sema);
	cbcstd_List aux = map_removed_objects;
	map_removed_objects = cbcstd_List_create();
	{map_MapObject mo=NULL;CBC_FOREACH(aux, mo){
		character_Character tmp_cast_SyKg = (character_Character)(mo);
		if (character_safe_character == tmp_cast_SyKg){
			game_winner = mo;
		}

		else{

			map_removed_objects->push(map_removed_objects, mo);
		}

	}}

	cbcstd_destroyObj((cbcstd_Object*)&(aux));
	
	map_emptyMinefield();
	
	game_generateMap();
	game_reinsertCharacters();
	game_insertRandomItems();
	game_state = game_GAME;
	
	floor_Floor tmp_cast_MVqh = (floor_Floor)(map_getNode(DIM_Y-1, 0)->bg);
	floor_Floor pause_f = tmp_cast_MVqh;

	pause_f->type_867 = floor_PAUSE_TYPE;
	
	character_safe_character = NULL;
	

	game_draw_sema->release(game_draw_sema);


}

void game_startGameVeryEasy(){
	difficulty_diff_level = difficulty_VERY_EASY;
	game_startGame();


}

void game_startGameEasy(){
	difficulty_diff_level = difficulty_EASY;
	game_startGame();


}

void game_startGameNormal(){
	difficulty_diff_level = difficulty_NORMAL;
	game_startGame();


}

void game_startGameHard(){
	difficulty_diff_level = difficulty_HARD;
	game_startGame();


}

void game_startGameExtreme(){
	difficulty_diff_level = difficulty_EXTREME;
	game_startGame();


}

void game_startGameImpossible(){
	difficulty_diff_level = difficulty_IMPOSSIBLE;
	game_startGame();


}

int game_classIdToItemId(class_id id){
	if (isidof(id, missil_Missil)){
		return game_MISSIL;
	}

	else{
	if (isidof(id, grenade_Grenade)){
		return game_GRENADE;
	}

	else{
	if (isidof(id, lawnmower_LawnMower)){
		return game_LAWNMOWER;
	}

	else{
	if (isidof(id, teleporter_Teleporter)){
		return game_TELEPORTER;
	}

	else{
	if (isidof(id, minedetector_MineDetector)){
		return game_MINEDETECTOR;
	}

	else{
	if (isidof(id, lifeup_LifeUp)){
		return game_LIFEUP;
	}

	else{
	if (isidof(id, flamethrower_FlameThrower)){
		return game_FLAMETHROWER;
	}

	else{
	if (isidof(id, cow_Cow)){
		return game_COW;
	}

	else{
	if (isidof(id, napalm_Napalm)){
		return game_NAPALM;
	}

	else{
	if (isidof(id, magnet_Magnet)){
		return game_MAGNET;
	}

	else{
	if (isidof(id, laser_Laser)){
		return game_LASER;
	}

	else{
		cthrow((cbcstd_Exception)(cbcstd_SystemError_create("ERROR: cannot convert class id to item id")));

	}

	}}}}}}}}}}

}

void game_parseGameStatus(savedata_ItemStatus* status){
	map_MapObject o = NULL;

	if (isidof(status->item, character_Character)){
		o = character_Character_create();
	}

	else{

		o = game_getNewItem(game_classIdToItemId(status->item));
	}



	map_insertObject(o, status->i, status->j);


	CBC_LOW_CAST(o, map_MapObject)->setInfoFromSave(o, &(status->extra[0]));


}

static bool _game_noResume(){
	cbcstd_String cmp = cbcstd_String_create("--no-resume");
	cbcstd_Array tmp_cast_jn6r = (cbcstd_Array)(cbcstd_args);
	{cbcstd_String s=NULL;CBC_FOREACH(tmp_cast_jn6r, s){

		if (s->__cmp__(s, cmp) == 0){
			cbcstd_destroyObj((cbcstd_Object*)&(cmp));
			return true;
		}

	}}

	cbcstd_destroyObj((cbcstd_Object*)&(cmp));
	return false;


}

void game_resumeGame(){

	if (savedata_decrypted.resume_game == 0){
		return;
	}

	else{
	if (_game_noResume()){
		return;
	}

	}

	game_total_score = savedata_decrypted.total_score;

	difficulty_diff_level = savedata_decrypted.difficulty_level;
	savedata_ItemStatus* status = NULL;
	int cont = savedata_loadGameStatus(&status);
	
	{int i=0; for (; i<cont; i++){
		game_parseGameStatus(&(status[i]));
	
	}}

	game_state = game_GAME;


}

void game_addNewCharacters(int n_characters){
	character_selected_character = NULL;
	{int i=0; for (; i<n_characters; i++){
		map_MapObject mo = character_Character_create();
		map_insertObject(mo, i, 0);
	}}


	while (map_removed_objects->size(map_removed_objects) > 0){

		cbcstd_Object o = map_removed_objects->pop(map_removed_objects);
		cbcstd_destroyObj((cbcstd_Object*)&(o));

	}


}

void game_addNewWeapons(int n_weapons){
	if (n_weapons <= 0){
		return;
	}

	bool insert[11];
	{int i=0; for (; i<11; i++){
		insert[i] = true;
	}}

	{int i=0; for (; i<DIM_Y; i++){
		if (i == DIM_Y/2){
			continue;
		}

		map_MapNode* n = map_getNode(i, DIM_X-1);


		if (n->objects->size(n->objects) == 0){
			continue;
		}



		cbcstd_Object o = n->objects->get(n->objects, 0);
		int id = game_classIdToItemId(classid(o));
		map_insertObject(game_getNewItem(id), i, DIM_X-1);
		insert[id] = false;
		n_weapons--;
		if (n_weapons <= 0){
			return;
		
		}

	}}

	{int i=0; for (; i<DIM_Y; i++){
		if (i == DIM_Y/2){
			continue;
		}

		map_MapNode* n = map_getNode(i, DIM_X-1);


		if (n->objects->size(n->objects) == 0){
			{int x = 0; for (; x<11; x++){
				if (insert[x]){
					map_insertObject(game_getNewItem(x), i, DIM_X-1);
					insert[x] = false;
					n_weapons--;
					if (n_weapons <= 0){
						return;
					}

					break;
				}

			}}

		}

	}}

	if (n_weapons > 0){
		game_addNewWeapons(n_weapons);
	}

	return;


}

void game_save(){
	{int i=0; for (; i<DIM_Y; i++){
		map_MapNode* node = map_getNode(i, DIM_X-1);

		cbcstd_List objects = node->objects;
		{map_MapObject mo=NULL;CBC_FOREACH(objects, mo){
			character_Character tmp_cast_geyn = (character_Character)(mo);
			character_Character c = tmp_cast_geyn;
			if (isinstanceof(c, teleporter_Teleporter)){
				teleporter_Teleporter tmp_cast_qRyL = (teleporter_Teleporter)(c);

				tmp_cast_qRyL->restoreMap(tmp_cast_qRyL);
			}

		}}

	}}


	savedata_decrypted.total_score = game_total_score;

	savedata_decrypted.difficulty_level = difficulty_diff_level;
	savedata_saveGameStatus();


}

void game_revealMines(){
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){
			floor_Floor tmp_cast_vUOx = (floor_Floor)(map_getNode(i, j)->bg);
			floor_Floor f = tmp_cast_vUOx;

			if (f->type_867 == floor_NORMAL_MINE_TYPE){

				f->type_867 = floor_MINE_VISIBLE_TYPE;

			}

		}}

	}}


}

void game_debugMines(int x, int y){
	#ifdef DEBUG
	if (game_debugging > 10){
		return;
	}

	if (x/common_FLOOR_WIDTH == DIM_X-1 and y/common_FLOOR_HEIGHT == DIM_Y/2){
		game_debugging++;
		if (game_debugging == 10){
			game_revealMines();
		}

	}

	else{
		game_debugging = 0;
	}

	#else
	return;
	#endif

}

