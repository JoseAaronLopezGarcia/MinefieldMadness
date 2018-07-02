#include <cbc.h>
// public globals
#include <savedata.h>
// private globals
const class_id savedata_InvalidSavedata__classid__ = -4255831576955454344;
//






const long savedata_XOR_VALUE = 0x52455441454843L;

char* savedata_save_path = NULL;
char* savedata_state_path = NULL;

savedata_InvalidSavedata savedata_InvalidSavedata_create(){
	savedata_InvalidSavedata self = (savedata_InvalidSavedata)cbcstd_alloc(sizeof(savedata_InvalidSavedata_struct));
	try{
		savedata_InvalidSavedata_init(self);
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
	}
	ccatch{
		cbcstd_destroy(&self);
		cthrow(cbcstd_getRaisedException());
	}finally{}etry;
	return self;
}
void savedata_InvalidSavedata_init(savedata_InvalidSavedata self){
	savedata_InvalidSavedata_initsystem(self);
	savedata_InvalidSavedata_inituser(self);
}
void savedata_InvalidSavedata_initsystem(savedata_InvalidSavedata self){
	cbcstd_Exception_initsystem((cbcstd_Exception)self);
	const static class_id __classid__[4] = {
		-4255831576955454344L,
		7143736340794888939L,
		-877637167666370448L,
		0
	};
	self->__type__ = (class_id*)__classid__;
	self->__size__ = sizeof(savedata_InvalidSavedata_struct);
	self->__end__ = &savedata_InvalidSavedata_end;
}
void savedata_InvalidSavedata_enduser(savedata_InvalidSavedata self){
	cbcstd_Exception_enduser((cbcstd_Exception)self);
	return;
}
void savedata_InvalidSavedata_end(savedata_InvalidSavedata self){
	savedata_InvalidSavedata_enduser(self);
	savedata_InvalidSavedata_decrefs(self);
	cbcstd_removeObjectLock(self);
	cbcstd_destroy(&self);
}
void savedata_InvalidSavedata_decrefs(savedata_InvalidSavedata self){
}

void savedata_InvalidSavedata_inituser(savedata_InvalidSavedata self){
	cbcstd_Exception_inituser((cbcstd_Exception)self, "Invalid savedata\n");

}


savedata_Savedata savedata_decrypted = {0};
savedata_Savedata savedata_encrypted = {0};

void savedata_xor(long* src, long* dest, unsigned count){
	{int i=0; for (; i<count; i++){
		dest[i] = src[i] ^ savedata_XOR_VALUE;

	}}


}

inline void savedata_encrypt(){
	savedata_xor((long*)&savedata_decrypted, (long*)&savedata_encrypted, (sizeof(savedata_Savedata)/sizeof(long)));


}

inline void savedata_decrypt(){
	savedata_xor((long*)&savedata_encrypted, (long*)&savedata_decrypted, (sizeof(savedata_Savedata)/sizeof(long)));


}

void savedata_save(){
	savedata_encrypt();
	cbcstd_File fp = cbcstd_File_create(savedata_save_path, "w");

	fp->write(fp, (void*)&savedata_encrypted,  1,  sizeof(savedata_Savedata));
	cbcstd_destroyObj((cbcstd_Object*)&(fp));


}

void savedata_load(){
	try{
		cbcstd_File fp = cbcstd_File_create(savedata_save_path, "r");

		if (fp->size_765 != sizeof(savedata_Savedata)){
			cthrow((cbcstd_Exception)(savedata_InvalidSavedata_create()));
		}


		fp->read(fp, (void*)&savedata_encrypted,  1,  sizeof(savedata_Savedata));
		cbcstd_destroyObj((cbcstd_Object*)&(fp));
		savedata_decrypt();
		{jmp_buf tmp_buf;cbcstd_obtainNextExceptionBuffer(&tmp_buf);}
		}
	ccatch{
		cbcstd_Exception sys_tmp_exc = cbcstd_getRaisedException();
		if(0){}
		cbc_catch(cbcstd_IOError){
			cbcstd_IOError tmp_cast_cFvm = (cbcstd_IOError)(sys_tmp_exc);
			cbcstd_IOError e = tmp_cast_cFvm;
			memset(&savedata_decrypted, 0, sizeof(savedata_Savedata));
		}
		cbc_catch(savedata_InvalidSavedata){
			savedata_InvalidSavedata tmp_cast_hzkl = (savedata_InvalidSavedata)(sys_tmp_exc);
			savedata_InvalidSavedata e = tmp_cast_hzkl;
			remove(savedata_save_path);
			memset(&savedata_decrypted, 0, sizeof(savedata_Savedata));
	
		}
		else{cthrow(sys_tmp_exc);}
		sys_tmp_exc->__end__(sys_tmp_exc);
	}
	finally{}etry;

}

void savedata_saveGameStatus(){
	cbcstd_List item_status = cbcstd_List_create();

	savedata_decrypted.resume_game = 1;
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){
			map_MapNode* node = map_getNode(i, j);

			floor_Floor tmp_cast_ky5W = (floor_Floor)(node->bg);
			floor_Floor f = tmp_cast_ky5W;


			savedata_decrypted.map_floors[i][j] = (long)(f->type_867);


			f->getSaveInfo(f, &(savedata_decrypted.map_extra[i][j][0]));

			cbcstd_List objects = node->objects;
			{map_MapObject mo=NULL;CBC_FOREACH(objects, mo){
				cbcstd_Object tmp_cast_gx75 = (cbcstd_Object)(mo);
				cbcstd_Object o = tmp_cast_gx75;
				savedata_ItemStatus* is = CBC_NEW(savedata_ItemStatus, 1);

				is->item = classid(o);

				is->i = i;

				is->j = j;


				CBC_LOW_CAST(mo, map_MapObject)->getSaveInfo(mo, &(is->extra[0]));

				item_status->push(item_status, is);
	
			}}

		}}

	}}


	savedata_ItemStatus* src = CBC_NEW(savedata_ItemStatus, item_status->size(item_status));

	savedata_ItemStatus* dst = CBC_NEW(savedata_ItemStatus, item_status->size(item_status));
	
	int i = 0;
	{savedata_ItemStatus* is=NULL;CBC_FOREACH(item_status, is){
		memcpy(&(src[i]), is, sizeof(savedata_ItemStatus));
		i++;
	
	}}

	savedata_xor((long*)src, (long*)dst, i*(sizeof(savedata_ItemStatus)/sizeof(long)));
	
	cbcstd_File fp = cbcstd_File_create(savedata_state_path, "w");


	fp->write(fp, dst,  1,  item_status->size(item_status)*sizeof(savedata_ItemStatus));
	
	cbcstd_destroyObj((cbcstd_Object*)&(fp));
	cbcstd_destroy(&(src));
	cbcstd_destroy(&(dst));
	cbcstd_destroyObj((cbcstd_Object*)&(item_status));
	
	savedata_save();


}

int savedata_loadGameStatus(savedata_ItemStatus** status){
	cbcstd_File fp = cbcstd_File_create(savedata_state_path, "r");
	(*status) = NULL;
	int cont = 0;
	
	{int i=0; for (; i<DIM_Y; i++){
		{int j=0; for (; j<DIM_X; j++){
			map_MapNode* node = map_getNode(i, j);

			floor_Floor tmp_cast_g19G = (floor_Floor)(node->bg);
			floor_Floor f = tmp_cast_g19G;
			if (i == DIM_Y-1 and j == 0){

				f->type_867 = floor_PAUSE_TYPE;
			}

			else{
				



				f->type_867 = (int)(savedata_decrypted.map_floors[i][j]);
			}



			f->setInfoFromSave(f, savedata_decrypted.map_extra[i][j]);
	
		}}

	}}


	cont = fp->size_765/sizeof(savedata_ItemStatus);

	savedata_ItemStatus* src = (savedata_ItemStatus*) CBC_NEW(uint8_t, fp->size_765);

	(*status) = (savedata_ItemStatus*) CBC_NEW(uint8_t, fp->size_765);

	fp->readAll(fp, src);

	savedata_xor(src, (*status), fp->size_765/sizeof(long));
	cbcstd_destroyObj((cbcstd_Object*)&(fp));
	return cont;


}

void savedata_determineSaveFile(){
	const char* file_name = "config.bin";
	const char* state_name = "gamestate.bin";
	char* _save_path = SDL_GetPrefPath("Hangover Games", "Minefield Madness!");
	savedata_save_path = CBC_NEW(char, strlen(_save_path)+strlen(file_name)+1);
	savedata_state_path = CBC_NEW(char, strlen(_save_path)+strlen(state_name)+1);
	strcpy(savedata_save_path, _save_path);
	strcat(savedata_save_path, file_name);
	strcpy(savedata_state_path, _save_path);
	strcat(savedata_state_path, state_name);
	SDL_free(_save_path);


}

void savedata_init(){
	savedata_determineSaveFile();
	savedata_load();
	return;

}

