#ifndef PLAYGAME_H
#define PLAYGAME_H
#include "Board.h"
#include "Move.h"
#include "Setting.h"
#include "PlayGame.h"

void PlayGame(int pOption, int P1, int P2);
const char* PlayGameAI(Piece *board[12][12]);
int colorCheck(Piece *board[12][12], char input[10], int P1, int P2, int playerCount);
void promote(Piece *board[12][12], char input[10], int playerCount);
int kingCap(Piece *board[12][12], Color color);

#endif

