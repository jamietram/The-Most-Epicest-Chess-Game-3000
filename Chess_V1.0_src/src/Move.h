#ifndef MOVE_H
#define MOVE_H
#include "Board.h"

int rankToInt(char rank);

int fileToInt(char file);

int isKingInCheck(Piece *movingPiece, Piece *board[12][12]);

int validMove(Piece *movingPiece, Piece *finalPiece, Piece *board[12][12], int ix, int iy,int fx,int fy);

int move(Piece *board[12][12], char input[10]);


#endif
