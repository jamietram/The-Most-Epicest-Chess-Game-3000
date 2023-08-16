#ifndef SETTING_H
#define SETTING_H
#include "Board.h"
#include "Move.h"

void PrintMenu();
void playMenu();
void Settings();
int pickColor(char colorChoice[6]);
int pickDifficulty(char diffChoice[12]);

#endif
