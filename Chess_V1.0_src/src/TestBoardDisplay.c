#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "PlayGame.h"
#include "Board.h"
#include "Move.h"

int main(void)
{
	Piece *board[12][12];
	generateBoard(board);
	printBoard(board);
	return 0;
}
