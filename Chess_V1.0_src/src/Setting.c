#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Board.h"
#include "Move.h"
#include "Setting.h"

void PrintMenu(){
	printf("\n\n***********************************\n");
	printf("    The Most Epicest Chess Game\n");
	printf("         Made By: Team TBD\n");
	printf("***********************************\n");
	printf("  1. Play   2. Settings   3. Exit\n");
}
void playMenu(){
	printf("\n\nPlease choose one of the following option below:\n");
	printf("1. Player vs Player	2. Player vs AI	   3. Go Back\n");
	}

void Settings(){
	printf("\n\nPlease choose one of the following settings to alter:\n");
	printf("1. Color    2. Difficulty    3. Go Back\n");
}

int pickColor(char colorChoice[6]){
	int BoW;
	if (strcmp(colorChoice, "White") == 0 || strcmp(colorChoice, "white") == 0){
		BoW = 1;
	}
	else if (strcmp(colorChoice, "Black") == 0 || strcmp(colorChoice, "black") == 0){
		BoW = 2;
        }
	else {
		BoW = 0;
	}
	return BoW;
}

int pickDifficulty(char diffChoice[12]){
	int diff;
	if (strcmp(diffChoice, "Beginner") == 0 || strcmp(diffChoice, "beginner") == 0){
                diff = 1;
        }
        else if (strcmp(diffChoice, "Intermediate") == 0 || strcmp(diffChoice, "intermediate") == 0){
                diff = 2;
        }
	else if (strcmp(diffChoice, "Expert") == 0 || strcmp(diffChoice, "expert") == 0){
		diff = 3;
	}
        else {
                diff = 0;
        }
	return diff;	
}
