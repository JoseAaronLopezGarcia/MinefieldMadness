#ifndef DIFFICULTY_H
#define DIFFICULTY_H


#ifdef __cplusplus
extern "C"{
#endif

#include <cbc.h>
// cbcstd imports
#include <cbcstd.h>
//
// public globals
#define MAX_DIFFICULTY_LEVELS 6
typedef struct difficulty_Difficulty{
	int nplayers;
	int pmine;
	int pnograss;
	int pblockage;
	int pitem;
	int s_chars;
	int s_items;
	int s_mines;
} difficulty_Difficulty;
extern void difficulty_Difficulty_enduser(difficulty_Difficulty self);
extern void difficulty_Difficulty_end(difficulty_Difficulty self);

typedef enum{
	difficulty_VERY_EASY,
	difficulty_EASY,
	difficulty_NORMAL,
	difficulty_HARD,
	difficulty_EXTREME,
	difficulty_IMPOSSIBLE,
};







extern const char* difficulty_difficulty_levels[MAX_DIFFICULTY_LEVELS];

extern difficulty_Difficulty difficulty_levels[MAX_DIFFICULTY_LEVELS];

extern int difficulty_diff_level;

extern void difficulty_setDifficultyLevel(int level);

extern void difficulty_lowerDifficulty();

extern void difficulty_raiseDifficulty();

extern difficulty_Difficulty* difficulty_getDifficultyLevel();


extern void difficulty_init();

#ifdef __cplusplus
};
#endif


#endif//
