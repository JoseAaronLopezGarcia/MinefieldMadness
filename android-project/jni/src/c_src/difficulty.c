#include <cbc.h>
// public globals
#include <difficulty.h>
// private globals
//




























const char* difficulty_difficulty_levels[MAX_DIFFICULTY_LEVELS] = {"Very Easy", "Easy", "Normal", "Hard", "Extreme", "Impossible"};

difficulty_Difficulty difficulty_levels[MAX_DIFFICULTY_LEVELS] = {{6, 10, 60, 70, 40, 50, 50, 100},

	{5, 20, 50, 60, 30, 100, 70, 200},

	{3, 35, 45, 55, 20, 200, 100, 500},

	{2, 40, 30, 40, 10, 100, 500, 200},

	{1, 50, 20, 30, 05, 50, 1000, 100},

	{1, 70, 0, 0, 10, 2000, 5000, 50}};

int difficulty_diff_level = 0;


void difficulty_setDifficultyLevel(int level){
	if (level >= 0 and level < MAX_DIFFICULTY_LEVELS){
		difficulty_diff_level = level;

	}


}

void difficulty_lowerDifficulty(){
	if (difficulty_diff_level > 0){
		difficulty_diff_level--;

	}


}

void difficulty_raiseDifficulty(){
	if (difficulty_diff_level < MAX_DIFFICULTY_LEVELS-1){
		difficulty_diff_level++;

	}


}

difficulty_Difficulty* difficulty_getDifficultyLevel(){
	return &(difficulty_levels[difficulty_diff_level]);

}

void difficulty_init(){
	return;
}
