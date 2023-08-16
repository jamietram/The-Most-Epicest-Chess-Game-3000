#ifndef BOARD_H
#define BOARD_H

typedef enum { PAWN, ROOK, BISHOP, KNIGHT, QUEEN, KING, INVALID, EMPTY} Type;
typedef enum { BLACK, WHITE, GREY, RED} Color;

typedef struct {
	Type type;
	Color color;
	char id[5];
	int x;
	int y;
	int idNum;
	int firstMove;
} Piece;

Color uColor;
Color cColor;


Piece* generatePiece(Type type, Color color, char id[], int idNum, int y, int x, int firstMove);

Color userColor();

void generateBoard(Piece *board[12][12]);

void printBoard(Piece *board[12][12]);


void case1(Piece *movingPiece);
void case2(Piece *movingPiece);
void case3(Piece *movingPiece);
void case4(Piece *movingPiece);
void case5(Piece *movingPiece);

#endif


