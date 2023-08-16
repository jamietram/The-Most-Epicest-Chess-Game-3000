#ifndef AI_H
#define AI_H

#include "Move.h"
#include "Board.h"

Piece* chooseRandPiece(Piece* board[12][12]);
int* higherValueCapture(Piece* movingPiece, Piece* board[12][12], int* capture);
int* generateAIMove(Piece* movingPiece, Piece *board[12][12]);
char* AIinput (Piece* movingPiece, int locationArray[2]);
void changeAIColor(Piece *board[12][12]);


#endif
