#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Board.h"

int x;
int y;

int newRank;
char newFile;

int invalidInput = 1;


Piece* generatePiece(Type type, Color color, char id[], int idNum, int y, int x, int firstMove)
{
    Piece *piece = (Piece*)malloc(sizeof(Piece));
    piece -> type =  type;
    piece -> color = color;
    //strncat(id, &cCharColor, 1);
    strcpy(piece -> id, id);
    piece -> firstMove = firstMove;
    piece -> x = x;
    piece -> idNum = idNum;
    piece -> y = y;
    return piece;
}

Color userColor()
{
    char uCharColor;
    int invalidInput = 1;
    while (invalidInput)
    {
        printf("\nPICK A COLOR FOR YOUR PIECES");
        printf("\nInput  B for Black and W for White: ");
        scanf("%c", &uCharColor);
        // printf("%c", uCharColor);
        if (uCharColor == 'B')
        {
            invalidInput = 0;
            return BLACK;
        }
        else if (uCharColor == 'W')
        {
            invalidInput = 0;
            return WHITE;
        }
        else
        {
            printf("\nInvalid input.. try again");
        }
    }
    return RED;
}

void generateBoard(Piece *board[12][12])
{
    // printf("works");
    //printf("%s", uCharColor);
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            board[i][j] = NULL;
            // INVALID STRUCTS
            if (i < 2 || i > 9 || j < 2 || j > 9)
                board[i][j] = generatePiece(INVALID, RED, "X ", 16, i, j, 0);

            else if (i == 2)
            {
                if (j == 2)
                    board[i][j] = generatePiece(ROOK, BLACK, "r", 0, i, j, 1);
                //strncat(board[i][j] -> id, &cCharColor, 1);
                //printf("%d", board[i][j] -> x);
                if (j == 3)
                    board[i][j] = generatePiece(KNIGHT, BLACK, "k", 1, i, j, 0);
                if (j == 4)
                    board[i][j] = generatePiece(BISHOP, BLACK, "b", 2, i, j, 0);
                if (j == 5)
                    board[i][j] = generatePiece(QUEEN, BLACK, "Q", 3, i, j, 0);
                if (j == 6)
                    board[i][j] = generatePiece(KING, BLACK, "K", 4, i, j, 1);
                if (j == 7)
                    board[i][j] = generatePiece(BISHOP, BLACK, "b", 5, i, j, 0);
                if (j == 8)
                    board[i][j] = generatePiece(KNIGHT, BLACK, "k", 6, i, j, 0);
                if (j == 9)
                    board[i][j] = generatePiece(ROOK, BLACK, "r", 7, i, j, 1);

            }
            else if (i == 3)
            {
                board[i][j] = generatePiece(PAWN, BLACK, "p", j + 6, i, j, 1);
                board[i][j] -> id[2] = j + 47;
            }
            else if (i == 8)
            {
                board[i][j] = generatePiece(PAWN, WHITE, "p", 16, i, j, 1);
                board[i][j] -> id[2] = j + 47;
            }
            else if (i == 9)
            {
                if (j == 2)
                    board[i][j] = generatePiece(ROOK, WHITE, "r", 16, i, j, 1);
                if (j == 3)
                    board[i][j] = generatePiece(KNIGHT, WHITE, "k", 16, i, j, 0);
                if (j == 4)
                   board[i][j] = generatePiece(BISHOP, WHITE, "b", 16, i, j, 0);
                if (j == 5)
                    board[i][j] = generatePiece(QUEEN, WHITE, "Q", 16, i, j, 0);
                if (j == 6)
                    board[i][j] = generatePiece(KING, WHITE, "K", 16, i, j, 1);
                if (j == 7)
                    board[i][j] = generatePiece(BISHOP, WHITE, "b", 16, i, j, 0);
                if (j == 8)
                    board[i][j] = generatePiece(KNIGHT, WHITE, "k", 16, i, j, 0);
                if (j == 9)
                    board[i][j] = generatePiece(ROOK, WHITE, "r", 16, i, j, 1);
            }
        }
    }
}
/*
void printBoard(Piece *board[12][12])
{
    //Color userColor =  userColor();
    // PRINTS BOARD SANS INVALID STRUCT BUFFER (INVALID ROWS & COLUMNS: 0, 1, 10, 11)
    for (int i = 2; i < 10; i++)
    {
        printf("%d ",  10 - i);              // PRINTS RANK
        for (int j = 2; j < 10; j++)
        {
            // BOARD POSITION IS EMPTY
            if (board[i][j] == NULL)
                printf(" -  ");
            // BOARD CONTAINS STRUCT
            else
            {
                printf("%s", board[i][j]->id);
                if (board[i][j] -> color == BLACK)
                    printf("\x1b[34;1mB \x1b[0m ");
                if (board[i][j] -> color  == WHITE)
                    printf("\x1b[33mW \x1b[0m ");
            }
            // END OF ROW, NEW LINE FOR NEXT ROW
            if (j == 9)
                printf("\n");
        }
    }
    printf ("   A   B   C   D   E   F   G   H \n\n");    // PRINTS FILE
}
*/

void printBoard(Piece *board[12][12]) {

    //top
    printf("  _____A__________B__________C__________D__________E__________F__________G__________H_____\n");


    //printf("%d ",  10 - i);              // PRINTS RANK on call 3
    for (int i = 2; i < 10; i++) {
        printf("  ");
        for (int k = 1; k < 6; k = k + 1) {
            for (int j = 2; j < 10; j++) {
                switch (k) {
                case 1:
                    case1(board[i][j]);
                    break;
                case 2:
                    case2(board[i][j]);
                    break;
                case 3:
                    case3(board[i][j]);
                    break;
                case 4:
                    case4(board[i][j]);
                    break;
                case 5:
                    case5(board[i][j]);
                    break;
                default:
                    break;
                }
            }
            if (k == 3)
                printf("|\n%d ", 10 - i);
            else
                printf("|\n  ");
        }
        if (i != 9)
            printf("----------------------------------------------------------------------------------------\n");
    }
    //bottom
    printf("  _____A__________B__________C__________D__________E__________F__________G__________H_____\n");
}

void case1(Piece *movingPiece) {
    char empty[20] = "|          ";
    char pawn1[20] = "|    @@    ";
    char rook1[20] = "| @@@@@@@@ ";
    char knight1[20] = "|  |\\_     ";
    char bishop1[20] = "|    @@    ";
    char queen1[20] = "| %\\ /\\ /% ";
    char king1[20] = "|    ++    ";


    if (movingPiece == NULL)
        printf("%s", empty); //empty square
    else {
        Type pieceType = movingPiece -> type;
        switch (pieceType) {
        case PAWN:
            printf("%s", pawn1);
            break;
        case QUEEN:
            printf("%s", queen1);
            break;
        case KNIGHT:
            printf("%s", knight1);
            break;
        case BISHOP:
            printf("%s", bishop1);
            break;
        case ROOK:
            printf("%s", rook1);
            break;
        case KING:
            printf("%s", king1);
            break;
        default:
            printf("no cigar");
        }
    }
}
void case2(Piece *movingPiece) {
    char empty[20] = "|          ";

    char pawn2[20] = "|   @";//pawn id here
    char pawn22[20] = "@   ";

    char rook2[20] = "| @++++++@ ";
    char knight2[20] = "|   / .\\_  ";
    char bishop2[20] = "|   /  \\   ";
    char queen2[20] = "| % %  % % ";
    char king2[20] = "|  @+  +@  ";

    if (movingPiece == NULL)
        printf("%s", empty); //empty square
    else {
        Type pieceType = movingPiece -> type;
        switch (pieceType) {
        case PAWN:
            printf("%s", pawn2);
            printf("%s", movingPiece->id);
            if (movingPiece -> color == BLACK)
                printf("\x1b[34;1mB\x1b[0m");
            if (movingPiece -> color  == WHITE)
                printf("\x1b[33mW\x1b[0m");
            printf("%s", pawn22);
            break;
        case QUEEN:
            printf("%s", queen2);
            break;
        case KNIGHT:
            printf("%s", knight2);
            break;
        case BISHOP:
            printf("%s", bishop2);
            break;
        case ROOK:
            printf("%s", rook2);
            break;
        case KING:
            printf("%s", king2);
            break;
        default:
            printf("no cigar");
        }
    }
}
void case3(Piece *movingPiece) {
    char empty[20] = "|          ";
    char pawn3[20] = "|  @@@@@@  ";

    char rook3[20] = "|  @ ";
    char rook35[20] = " @  ";

    char knight3[20] = "|  | ";
    char knight35[20] = "__) ";


    char bishop3[20] = "|   @";
    char bishop35[20] = "@   ";

    char queen3[20] = "| @  @@  @ ";
    char king3[20] = "| @  @@  @ ";

    if (movingPiece == NULL)
        printf("%s", empty); //empty square
    else {
        Type pieceType = movingPiece -> type;
        switch (pieceType) {
        case PAWN:
            printf("%s", pawn3);
            break;
        case QUEEN:
            printf("%s", queen3);
            break;
        case KNIGHT:
            printf("%s", knight3);
            printf("%s", movingPiece->id);
            if (movingPiece -> color == BLACK)
                printf("\x1b[34;1mB\x1b[0m");
            if (movingPiece -> color  == WHITE)
                printf("\x1b[33mW\x1b[0m");
            printf("%s", knight35);
            break;
        case BISHOP:
            printf("%s", bishop3);
            printf("%s", movingPiece->id);
            if (movingPiece -> color == BLACK)
                printf("\x1b[34;1mB\x1b[0m");
            if (movingPiece -> color  == WHITE)
                printf("\x1b[33mW\x1b[0m");
            printf("%s", bishop35);
            break;
        case ROOK:
            printf("%s", rook3);
            printf("%s", movingPiece->id);
            if (movingPiece -> color == BLACK)
                printf("\x1b[34;1mB\x1b[0m");
            if (movingPiece -> color  == WHITE)
                printf("\x1b[33mW\x1b[0m");
            printf("%s", rook35);
            break;
        case KING:
            printf("%s", king3);
            break;
        default:
            printf("no cigar");
        }
    }
}
void case4(Piece *movingPiece) {
    char empty[20] = "|          ";
    char pawn4[20] = "|   @  @   ";
    char rook4[20] = "| @++++++@ ";
    char knight4[20] = "|  | = \\   ";
    char bishop4[20] = "|  =@@@@=  ";

    char queen4[20] = "|  @ ";
    char queen45[20] = " @  ";


    char king4[20] = "|  @ ";
    char king45[20] = " @  ";

    if (movingPiece == NULL)
        printf("%s", empty); //empty square
    else {
        Type pieceType = movingPiece -> type;
        switch (pieceType) {
        case PAWN:
            printf("%s", pawn4);
            break;
        case QUEEN:
            printf("%s", queen4);
            printf("%s", movingPiece->id);
            if (movingPiece -> color == BLACK)
                printf("\x1b[34;1mB\x1b[0m");
            if (movingPiece -> color  == WHITE)
                printf("\x1b[33mW\x1b[0m");
            printf("%s", queen45);
            break;
        case KNIGHT:
            printf("%s", knight4);
            break;
        case BISHOP:
            printf("%s", bishop4);
            break;
        case ROOK:
            printf("%s", rook4);
            break;
        case KING:
            printf("%s", king4);
            printf("%s", movingPiece->id);
            if (movingPiece -> color == BLACK)
                printf("\x1b[34;1mB\x1b[0m");
            if (movingPiece -> color  == WHITE)
                printf("\x1b[33mW\x1b[0m");
            printf("%s", king45);
            break;
        default:
            printf("no cigar");
        }
    }
}

void case5(Piece *movingPiece) {
    char empty[20] = "|          ";
    char pawn5[20] = "|  @@@@@@  ";
    char rook5[20] = "| @++++++@ ";
    char knight5[20] = "| [______] ";
    char bishop5[20] = "| %%%%%%%% ";
    char queen5[20] = "| %@@@@@@% ";
    char king5[20] = "|  @@@@@@  ";


    if (movingPiece == NULL)
        printf("%s", empty); //empty square
    else {
        Type pieceType = movingPiece -> type;
        switch (pieceType) {
        case PAWN:
            printf("%s", pawn5);
            break;
        case QUEEN:
            printf("%s", queen5);
            break;
        case KNIGHT:
            printf("%s", knight5);
            break;
        case BISHOP:
            printf("%s", bishop5);
            break;
        case ROOK:
            printf("%s", rook5);
            break;
        case KING:
            printf("%s", king5);
            break;
        default:
            printf("no cigar");
        }
    }
}

