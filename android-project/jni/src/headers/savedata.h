#ifndef SAVEDATA_H
#define SAVEDATA_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// difficulty imports
#include <difficulty.h>
//
// map imports
#include <map.h>
//
// floor imports
#include <floor.h>
//
// public globals
#include <config.h>



extern const long savedata_XOR_VALUE;

extern char* savedata_save_path;

extern char* savedata_state_path;

typedef struct savedata_InvalidSavedata_struct{
	class_id* __type__;
	size_t __size__;
	size_t __refs__;
	void* __lock__;
	void (* __end__)(struct savedata_InvalidSavedata_struct* self);
	void* (* __getvtable__)(struct savedata_InvalidSavedata_struct* self, class_id id);
	int (* __cmp__)(struct savedata_InvalidSavedata_struct* self, struct savedata_InvalidSavedata_struct* other);
	struct savedata_InvalidSavedata_struct* (* __operate__)(struct savedata_InvalidSavedata_struct* self, struct savedata_InvalidSavedata_struct* other);
	void* (* __str__)(struct savedata_InvalidSavedata_struct* self);
	cbcstd_String description_787;
} savedata_InvalidSavedata_struct;
typedef savedata_InvalidSavedata_struct* savedata_InvalidSavedata;
extern const class_id savedata_InvalidSavedata__classid__;
extern savedata_InvalidSavedata savedata_InvalidSavedata_create();
extern void savedata_InvalidSavedata_init(savedata_InvalidSavedata self);
extern void savedata_InvalidSavedata_initsystem(savedata_InvalidSavedata self);
extern void savedata_InvalidSavedata_inituser(savedata_InvalidSavedata self);
extern void savedata_InvalidSavedata_enduser(savedata_InvalidSavedata self);
extern void savedata_InvalidSavedata_end(savedata_InvalidSavedata self);

typedef struct savedata_Savedata{
	long high_scores[MAX_DIFFICULTY_LEVELS];
	long sound_state;
	long resume_game;
	long total_score;
	long difficulty_level;
	long map_floors[DIM_Y][DIM_X];
	long map_extra[DIM_Y][DIM_X][MAX_EXTRA_INFO];
} savedata_Savedata;
extern void savedata_Savedata_enduser(savedata_Savedata self);
extern void savedata_Savedata_end(savedata_Savedata self);

typedef struct savedata_ItemStatus{
	long item;
	long i;
	long j;
	long extra[MAX_EXTRA_INFO];
} savedata_ItemStatus;
extern void savedata_ItemStatus_enduser(savedata_ItemStatus self);
extern void savedata_ItemStatus_end(savedata_ItemStatus self);

extern savedata_Savedata savedata_decrypted;

extern savedata_Savedata savedata_encrypted;

extern void savedata_xor(long* src, long* dest, unsigned count);

extern inline void savedata_encrypt();

extern inline void savedata_decrypt();

extern void savedata_save();

extern void savedata_load();

extern void savedata_saveGameStatus();

extern int savedata_loadGameStatus(savedata_ItemStatus** status);

extern void savedata_determineSaveFile();

extern void savedata_init();





#ifdef __cplusplus
};
#endif


#endif//
