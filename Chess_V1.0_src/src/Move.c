#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "Board.h"
#include "Move.h"

int newRank;
char newFile;
int x;
int y;

int absval(int value) {
    if (value < 0)
        value = value * -1;
    return value;
}

int rankToInt(char rank)
{
    return (10 - (rank - 48));
}

int fileToInt(char file)//x
{
    if (file < 96)
        file = file + 32;
    int intFile = file - 95;

    return intFile;
}

int isKingInCheck(Piece *movingPiece, Piece *board[12][12]) {

    int check = 0;
    int kingx = 0;
    int kingy = 0;
    for (int i = 2; i < 10; i = i + 1) {
        for (int j = 2; j < 10; j = j + 1) {
            if (board[i][j] == NULL)
                continue;
            if ((board[i][j]->color == movingPiece->color) && (strcmp(board[i][j]->id, "K") == 0)) {
                kingx = j;
                kingy = i;
                printf("king x king y%d%d\n", kingx, kingy);
            }
        }
    }

    printf("king x king y%d%d\n", kingx, kingy);
    int topLimit = kingy - 2;
    int bottomLimit = 9 - kingy;
    int leftLimit = kingx - 2;
    int rightLimit = 9 - kingx;

    int upleftlimit;
    if (topLimit <= leftLimit)
        upleftlimit = topLimit;
    else
        upleftlimit = leftLimit;

    int uprightlimit;
    if (topLimit <= rightLimit)
        uprightlimit = topLimit;
    else
        uprightlimit = rightLimit;

    int downleftlmit;
    if (bottomLimit <= leftLimit)
        downleftlmit = bottomLimit;
    else
        downleftlmit = leftLimit;

    int downrightlimit;
    if (bottomLimit <= rightLimit)
        downrightlimit = bottomLimit;
    else
        downrightlimit = rightLimit;

    if (board[kingy][kingx]->color == BLACK) {
        //check all left
        // printf("blakc king check\n");
        for (int i = 1; i < (leftLimit + 1); i = i + 1) {
            if (board[kingy][kingx - i] == NULL)
                continue;
            if ((strcmp(board[kingy][kingx - i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy][kingx - i]->color == BLACK) {
                break;
            }
            if (board[kingy][kingx - i]->color == WHITE && ((strcmp(board[kingy][kingx - i]->id, "Q") == 0) || (strcmp(board[kingy][kingx - i]->id, "r") == 0))) {
                return check = 1;
            }
        }
        //check all right
        for (int i = 1; i < (rightLimit  + 1); i = i + 1) {
            if (board[kingy][kingx + i] == NULL)
                continue;
            if ((strcmp(board[kingy][kingx + i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy][kingx + i]->color == BLACK) {
                break;
            }
            if (board[kingy][kingx + i]->color == WHITE && ((strcmp(board[kingy][kingx + i]->id, "Q") == 0) || (strcmp(board[kingy][kingx + i]->id, "r") == 0))) {
                return check = 1;
            }
        }
        //check all up
        for (int i = 1; i < (topLimit  + 1); i = i + 1) {
            if (board[kingy - i][kingx] == NULL)
                continue;
            if ((strcmp(board[kingy - i][kingx]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy - i][kingx]->color == BLACK) {
                break;
            }
            if (board[kingy - i][kingx]->color == WHITE && ((strcmp(board[kingy - i][kingx]->id, "Q") == 0) || (strcmp(board[kingy - i][kingx]->id, "r") == 0))) {
                return check = 1;
            }
        }

        //check all down
        for (int i = 1; i < (bottomLimit  + 1); i = i + 1) {
            if (board[kingy + i][kingx] == NULL)
                continue;
            if ((strcmp(board[kingy + i][kingx]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy + i][kingx]->color == BLACK) {
                break;
            }
            if (board[kingy + i][kingx]->color == WHITE && ((strcmp(board[kingy + i][kingx]->id, "Q") == 0) || (strcmp(board[kingy + i][kingx]->id, "r") == 0))) {
                return check = 1;
            }
        }
        //upleft
        for (int i = 1; i < (upleftlimit  + 1); i = i + 1) {
            if (board[kingy - i][kingx - i] == NULL)
                continue;
            if ((strcmp(board[kingy - i][kingx - i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy - i][kingx - i]->color == BLACK) {
                break;
            }
            if (board[kingy - i][kingx - i]->color == WHITE && ((strcmp(board[kingy - i][kingx - i]->id, "Q") == 0) || (strcmp(board[kingy - i][kingx - i]->id, "b") == 0))) {
                return check = 1;
            }
        }
        //upright
        for (int i = 1; i < (uprightlimit  + 1); i = i + 1) {
            if (board[kingy - i][kingx + i] == NULL)
                continue;
            if ((strcmp(board[kingy - i][kingx + i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy - i][kingx + i]->color == BLACK) {
                break;
            }
            if (board[kingy - i][kingx + i]->color == WHITE && ((strcmp(board[kingy - i][kingx + i]->id, "Q") == 0) || (strcmp(board[kingy - i][kingx + i]->id, "b") == 0))) {
                return check = 1;
            }
        }
        //downleft
        for (int i = 1; i < (downleftlmit  + 1); i = i + 1) {
            if (board[kingy + i][kingx - i] == NULL)
                continue;
            if ((strcmp(board[kingy + i][kingx - i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy + i][kingx - i]->color == BLACK) {
                break;
            }
            if (board[kingy + i][kingx - i]->color == WHITE && ((strcmp(board[kingy + i][kingx - i]->id, "Q") == 0) || (strcmp(board[kingy + i][kingx - i]->id, "b") == 0) ||
                    (strcmp(board[kingy + i][kingx - i]->id, "p") == 0))) {
                return check = 1;
            }
        }
        //downright
        for (int i = 1; i < (downrightlimit  + 1); i = i + 1) {
            if (board[kingy + i][kingx + i] == NULL)
                continue;
            if ((strcmp(board[kingy + i][kingx + i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy + i][kingx + i]->color == BLACK) {
                break;
            }
            if (board[kingy + i][kingx + i]->color == WHITE && ((strcmp(board[kingy + i][kingx + i]->id, "Q") == 0) || (strcmp(board[kingy + i][kingx + i]->id, "b") == 0) ||
                    (strcmp(board[kingy + i][kingx + i]->id, "p") == 0))) {
                return check = 1;
            }
        }

        //kinght up
        if (board[kingy - 2][kingx + 1] == NULL || board[kingy - 2][kingx + 1]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy - 2][kingx + 1]->color == WHITE && (strcmp(board[kingy - 2][kingx + 1]->id, "k") == 0))) {
                return check = 1;
            }
        }
        if (board[kingy - 2][kingx - 1] == NULL || board[kingy - 2][kingx - 1]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy - 2][kingx - 1]->color == WHITE && (strcmp(board[kingy - 2][kingx - 1]->id, "k") == 0))) {
                return check = 1;
            }
        }
        //kinght down
        if (board[kingy + 2][kingx + 1] == NULL || board[kingy + 2][kingx + 1]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy + 2][kingx + 1]->color == WHITE && (strcmp(board[kingy + 2][kingx + 1]->id, "k") == 0))) {
                return check = 1;
            }
        }
        if (board[kingy + 2][kingx - 1] == NULL || board[kingy + 2][kingx - 1]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy + 2][kingx - 1]->color == WHITE && (strcmp(board[kingy + 2][kingx - 1]->id, "k") == 0))) {
                return check = 1;
            }
        }
        //kight right
        if (board[kingy + 1][kingx + 2] == NULL || board[kingy + 1][kingx + 2]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy + 1][kingx + 2]->color == WHITE && (strcmp(board[kingy + 1][kingx + 2]->id, "k") == 0))) {
                return check = 1;
            }
        }
        if (board[kingy - 1][kingx + 2] == NULL || board[kingy - 1][kingx + 2]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy - 1][kingx + 2]->color == WHITE && (strcmp(board[kingy - 1][kingx + 2]->id, "k") == 0))) {
                return check = 1;
            }
        }
        //knight left
        if (board[kingy + 1][kingx - 2] == NULL || board[kingy + 1][kingx - 2]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy + 1][kingx - 2]->color == WHITE && (strcmp(board[kingy + 1][kingx - 2]->id, "k") == 0))) {
                return check = 1;
            }
        }
        if (board[kingy - 1][kingx - 2] == NULL || board[kingy - 1][kingx - 2]->color == BLACK)
            check = 0;
        else {
            if ((board[kingy - 1][kingx - 2]->color == WHITE && (strcmp(board[kingy - 1][kingx - 2]->id, "k") == 0))) {
                return check = 1;
            }
        }

    }

    else if (board[kingy][kingx]->color == WHITE) {
        //check all left
        for (int i = 1; i < (leftLimit + 1); i = i + 1) {
            if (board[kingy][kingx - i] == NULL)
                continue;
            if ((strcmp(board[kingy][kingx - i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy][kingx - i]->color == WHITE) {
                break;
            }
            if (board[kingy][kingx - i] == BLACK && ((strcmp(board[kingy][kingx - i]->id, "Q") == 0) || (strcmp(board[kingy][kingx - i]->id, "r") == 0))) {
                return check = 1;
            }
        }
        //check all right
        for (int i = 1; i < (rightLimit  + 1); i = i + 1) {
            if (board[kingy][kingx + i] == NULL)
                continue;
            if ((strcmp(board[kingy][kingx + i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy][kingx + i]->color == WHITE) {
                break;
            }
            if (board[kingy][kingx + i] == BLACK && ((strcmp(board[kingy][kingx + i]->id, "Q") == 0) || (strcmp(board[kingy][kingx + i]->id, "r") == 0))) {
                return check = 1;
            }
        }
        //check all up
        for (int i = 1; i < (topLimit  + 1); i = i + 1) {
            if (board[kingy - i][kingx] == NULL)
                continue;
            if ((strcmp(board[kingy - i][kingx]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy - i][kingx]->color == WHITE) {
                break;
            }
            if (board[kingy - i][kingx]->color == BLACK && ((strcmp(board[kingy - i][kingx]->id, "Q") == 0) || (strcmp(board[kingy - i][kingx]->id, "r") == 0))) {
                return check = 1;
            }
        }

        //check all down
        for (int i = 1; i < (bottomLimit  + 1); i = i + 1) {
            if (board[kingy + i][kingx] == NULL)
                continue;
            if ((strcmp(board[kingy + i][kingx]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy + i][kingx]->color == WHITE) {
                break;
            }
            if (board[kingy + i][kingx]->color == BLACK && ((strcmp(board[kingy + i][kingx]->id, "Q") == 0) || (strcmp(board[kingy + i][kingx]->id, "r") == 0))) {
                return check = 1;
            }
        }
        //upleft
        for (int i = 1; i < (upleftlimit  + 1); i = i + 1) {
            if (board[kingy - i][kingx - i] == NULL)
                continue;
            if ((strcmp(board[kingy - i][kingx - i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy - i][kingx - i]->color == WHITE) {
                break;
            }
            if (board[kingy - i][kingx - i]->color == BLACK && ((strcmp(board[kingy - i][kingx - i]->id, "Q") == 0) || (strcmp(board[kingy - i][kingx - i]->id, "b") == 0) ||
                    strcmp(board[kingy - i][kingx - i]->id, "p"))) {
                return check = 1;
            }
        }
        //upright
        for (int i = 1; i < (uprightlimit  + 1); i = i + 1) {
            if (board[kingy - i][kingx + i] == NULL)
                continue;
            if ((strcmp(board[kingy - i][kingx + i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy - i][kingx + i]->color == WHITE) {
                break;
            }
            if (board[kingy - i][kingx + i]->color == BLACK && ((strcmp(board[kingy - i][kingx + i]->id, "Q") == 0) || (strcmp(board[kingy - i][kingx + i]->id, "b") == 0) ||
                    strcmp(board[kingy - i][kingx + i]->id, "p"))) {
                return check = 1;
            }
        }
        //downleft
        for (int i = 1; i < (downleftlmit  + 1); i = i + 1) {
            if (board[kingy + i][kingx - i] == NULL)
                continue;
            if ((strcmp(board[kingy + i][kingx - i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy + i][kingx - i]->color == WHITE) {
                break;
            }
            if (board[kingy + i][kingx - i]->color == BLACK && ((strcmp(board[kingy + i][kingx - i]->id, "Q") == 0) || (strcmp(board[kingy + i][kingx - i]->id, "b") == 0))) {
                return check = 1;
            }
        }
        //downright
        for (int i = 1; i < (downrightlimit  + 1); i = i + 1) {
            if (board[kingy + i][kingx + i] == NULL)
                continue;
            if ((strcmp(board[kingy + i][kingx + i]->id, "X ") == 0)) {
                break;
            }
            if (board[kingy + i][kingx + i]->color == WHITE) {
                break;
            }
            if (board[kingy + i][kingx + i]->color == BLACK && ((strcmp(board[kingy + i][kingx + i]->id, "Q") == 0) || (strcmp(board[kingy + i][kingx + i]->id, "b") == 0))) {
                return check = 1;
            }
        }
        //kinght up
        if (board[kingy - 2][kingx + 1] == NULL)
            check = 0;
        else {
            if ((board[kingy - 2][kingx + 1]->color == BLACK && (strcmp(board[kingy - 2][kingx + 1]->id, "k") == 0)))
                return check = 1;
        }
        if (board[kingy - 2][kingx - 1] == NULL)
            check = 0;
        else {
            if ((board[kingy - 2][kingx - 1]->color == BLACK && (strcmp(board[kingy - 2][kingx - 1]->id, "k") == 0)))
                return check = 1;
        }
        //kinght down
        if (board[kingy + 2][kingx + 1] == NULL)
            check = 0;
        else {
            if ((board[kingy + 2][kingx + 1]->color == BLACK && (strcmp(board[kingy + 2][kingx + 1]->id, "k") == 0)))
                return check = 1;
        }
        if (board[kingy + 2][kingx - 1] == NULL)
            check = 0;
        else {
            if ((board[kingy + 2][kingx - 1]->color == BLACK && (strcmp(board[kingy + 2][kingx - 1]->id, "k") == 0)))
                return check = 1;
        }
        //kight right
        if (board[kingy + 1][kingx + 2] == NULL)
            check = 0;
        else {
            if ((board[kingy + 1][kingx + 2]->color == BLACK && (strcmp(board[kingy + 1][kingx + 2]->id, "k") == 0)))
                return check = 1;
        }
        if (board[kingy - 1][kingx + 2] == NULL)
            check = 0;
        else {
            if ((board[kingy - 1][kingx + 2]->color == BLACK && (strcmp(board[kingy - 1][kingx + 2]->id, "k") == 0)))
                return check = 1;
        }
        //knight left
        if (board[kingy + 1][kingx - 2] == NULL)
            check = 0;
        else {
            if ((board[kingy + 1][kingx - 2]->color == BLACK && (strcmp(board[kingy + 1][kingx - 2]->id, "k") == 0)))
                return check = 1;
        }
        if (board[kingy - 1][kingx - 2] == NULL)
            check = 0;
        else {
            if ((board[kingy - 1][kingx - 2]->color == BLACK && (strcmp(board[kingy - 1][kingx - 2]->id, "k") == 0)))
                return check = 1;
        }
    }

    return check;
}

int validMove(Piece *movingPiece, Piece *finalPiece, Piece *board[12][12], int intialx, int intialy, int finalx, int finaly)
{
    int validMove = 0;
    int capture = 0;

    Type pieceType = movingPiece -> type;

    int IsKingInCheck = 0;
    IsKingInCheck = isKingInCheck(movingPiece, board);
    if (IsKingInCheck == 1)
        printf("King in check\n");

    if ((finaly == movingPiece -> y) && (finalx == movingPiece -> x))
    {
        printf("same spot, retry");
        return 0;
    }

    // VALID MOVE REGARDLESS OF TYPE
    // If the final position contains a piece
    if (finalPiece != NULL)
    {
        // NOT A VALID MOVE
        // If the final position contains a piece of the same color as moving piece
        if (finalPiece -> color == movingPiece -> color)
        {
            validMove = 0;
            printf("NOT A VALID MOVE! \n");
            printf("Cannot attack own piece \n");
            return validMove;
        }

        // If the final position is invalid
        // Note: Necessary for AI
        if (finalPiece -> type == INVALID)
        {
            validMove = 0;
            return validMove;
        }

        // ONLY CHECKING IF PIECE IS TRYING TO CAPTURE
        // Not of the same color, valid move still unknown but in capture mode
        else
            capture = 1;
    }

    // capture flag for en passant
    if (board[finaly][finalx] == NULL)
    {
        //en passant flag for moving white piece
        if (movingPiece -> type == PAWN && movingPiece -> color == WHITE)
        {
            // checks right and left of initial position to see if enpassant if available
            if (board[intialy][intialx - 1] != NULL && board[intialy][intialx - 1] -> firstMove == 2 && finalx - intialx == -1)
            {
                capture = 2; //flag for left hand capture
            }
            if (board[intialy][intialx + 1] != NULL && board[intialy][intialx + 1] -> firstMove == 2 && finalx - intialx == 1)
            {
                capture = 3; //flag for right hand capture
            }
        }

        //en passant flag for moving black piece
        if (movingPiece -> type == PAWN && movingPiece -> color == BLACK)
        {
            // checks right and left of initial position to see if enpassant if available
            if (board[intialy][intialx - 1] != NULL && board[intialy][intialx - 1] -> firstMove == 2 && finalx - intialx == -1)
            {
                capture = 2; //flag for left hand capture
            }
            if (board[intialy][intialx + 1] != NULL && board[intialy][intialx + 1] -> firstMove == 2 && finalx - intialx == 1)
            {
                capture = 3; //flag for right hand capture
            }
        }
    }


    printf("capture%d\n", capture);

    // VALID MOVE ACCORDING TO PIECE
    switch (pieceType) {
    case PAWN:;   // note to self x val doesnt matter look at y changes
        int temp = intialy - finaly;
        if (capture == 0) {
            if (movingPiece -> firstMove == 1)
            {
                if ((movingPiece -> color == BLACK && temp > 0) || (movingPiece -> color == WHITE && temp < 0)) {
                    return validMove = 0;
                }
                else
                    temp = absval(temp);

                if (((temp) == 2 ) || ((temp) == 1 ))
                {
                    if (temp == 2)
                        movingPiece -> firstMove = 2;
                    if (temp == 1)
                        movingPiece -> firstMove = 0;
                    validMove = 1;
                }
            }
            else if (movingPiece -> firstMove == 0  || movingPiece -> firstMove == 2)
            {
                temp = absval(temp);
                if ((temp) == 1)
                    validMove = 1;
                if (validMove)
                    movingPiece -> firstMove = 0;
            }
        }
        if (intialx - 1 == finalx || intialx + 1 == finalx) { //capture == true
            if (movingPiece -> color == BLACK && temp > 0)
            {
                return validMove = 0;
            }
            if (movingPiece -> color == BLACK && capture == 1) {
                //normal capture
                temp = absval(temp);
                if (temp == 1) {
                    validMove = 1;
                }
            }
            else if (movingPiece -> color == BLACK && (capture == 2 || capture == 3)) //enpassant capture left or right for black
            {
                temp = absval(temp);
                if (temp == 1)
                {
                    if (capture == 2)
                        board[intialy][intialx - 1] = NULL; //eats the piece to the left
                    if (capture == 3)
                        board[intialy][intialx + 1] = NULL; //eats the piece to the right
                    validMove = 1;
                }
            }

            if (movingPiece -> color == WHITE && temp < 0) {
                return validMove = 0;
            }
            if (movingPiece -> color == WHITE && capture == 1) {
                //normal capture
                temp = absval(temp);
                if (temp == 1) {
                    validMove = 1;
                }
            }
            else if (movingPiece -> color == WHITE && (capture == 2 || capture == 3)) //enpassant capture left or right for black
            {
                temp = absval(temp);
                if (temp == 1)
                {
                    if (capture == 2)
                        board[intialy][intialx - 1] = NULL; //eats the piece to the left
                    if (capture == 3)
                        board[intialy][intialx + 1] = NULL; //eats the piece to the right
                    validMove = 1;
                }
            }
        }
        break;
    case QUEEN:
        //moving y
        if (finalx == intialx) {
            validMove = 1;
            int temp = finaly - intialy;

            if (temp < 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy - i][intialx] != NULL)
                        validMove = 0;
                }
            }
            else if (temp > 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy + i][intialx] != NULL)
                        validMove = 0;
                }
            }
        }
        //moving x
        else if (finaly == intialy) {
            validMove = 1;
            int temp = finalx - intialx;

            if (temp < 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy ][intialx - i] != NULL)
                        validMove = 0;
                }
            }
            else if (temp > 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy][intialx + i] != NULL)
                        validMove = 0;
                }
            }
        }
        else if (finaly - intialy < 0 && finalx - intialx < 0) { // up left
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy - i][intialx - i] != NULL)
                    validMove = 0;
            }
        }
        else if (finaly - intialy < 0 && finalx - intialx > 0) { // up right
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy - i][intialx + i] != NULL)
                    validMove = 0;
            }
        }
        else if (finaly - intialy > 0 && finalx - intialx < 0) { // down left
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy + i][intialx - i] != NULL)
                    validMove = 0;
            }
        }
        else if (finaly - intialy > 0 && finalx - intialx > 0) { // down right
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy + i][intialx + i] != NULL)
                    validMove = 0;
            }
        }
        break;
    case KNIGHT:
        if (((finaly == intialy + 2) || (finaly == intialy - 2)) && ((finalx == intialx + 1) || (finalx == intialx - 1)))
        {
            validMove = 1;
        }
        else if (((finalx == intialx + 2) || (finalx == intialx - 2)) && ((finaly == intialy + 1) || (finaly == intialy - 1)))
        {
            validMove = 1;
        }
        else
        {
            validMove = 0;
        }
        break;
    case BISHOP:
        /*
        00 01 02
        10 11 12
        20 21 22
        */
        if (finaly - intialy < 0 && finalx - intialx < 0) { // up left
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy - i][intialx - i] != NULL)
                    validMove = 0;
            }
        }
        else if (finaly - intialy < 0 && finalx - intialx > 0) { // up right
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy - i][intialx + i] != NULL)
                    validMove = 0;
            }
        }
        else if (finaly - intialy > 0 && finalx - intialx < 0) { // down left
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy + i][intialx - i] != NULL)
                    validMove = 0;
            }
        }
        else if (finaly - intialy > 0 && finalx - intialx > 0) { // down right
            validMove = 1;
            int temp = absval(finaly - intialy);
            for (int i = 1; i < temp; i = i + 1) {
                if (board[intialy + i][intialx + i] != NULL)
                    validMove = 0;
            }
        }
        break;
    case ROOK:
        //moving y
        if (finalx == intialx) {
            validMove = 1;
            movingPiece -> firstMove = 0;
            int temp = finaly - intialy;

            if (temp < 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy - i][intialx] != NULL)
                        validMove = 0;
                }
            }
            else if (temp > 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy + i][intialx] != NULL)
                        validMove = 0;
                }
            }
        }
        //moving x
        else if (finaly == intialy) {
            validMove = 1;
            movingPiece -> firstMove = 0;
            int temp = finalx - intialx;

            if (temp < 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy ][intialx - i] != NULL)
                        validMove = 0;
                }
            }
            else if (temp > 0) {
                temp = absval(temp);
                for (int i = 1; i < temp; i = i + 1) {
                    if (board[intialy][intialx + i] != NULL)
                        validMove = 0;
                }
            }
        }
        break;
    case KING:
        if (movingPiece -> firstMove == 1) // check if first move
        {
            if (intialx - finalx == 2)//move 2 square left
            {
                if (movingPiece -> color == BLACK)
                {
                    if (board[intialy][intialx - 4] -> firstMove == 1) { //check if first move of left rook
                        printf("\nCastling\n");
                        move(board, "a8d8");
                        validMove = 1;
                    }
                }
                else if (movingPiece -> color == WHITE)
                {
                    if (board[intialy][intialx - 4] -> firstMove == 1) {
                        printf("\nCastling\n");
                        move(board, "a1d1");
                        validMove = 1;
                    }
                }
            }
            else if (finalx - intialx == 2)//move 2 square right
            {
                if (movingPiece -> color == BLACK)
                {
                    if (board[intialy][intialx + 3] -> firstMove == 1) { //check if first move of right rook
                        printf("\nCastling\n");
                        move(board, "h8f8");
                        validMove = 1;
                    }
                }
                else if (movingPiece -> color == WHITE)
                {
                    if (board[intialy][intialx + 3] -> firstMove == 1) {
                        printf("\nCastling\n");
                        move(board, "h1f1");
                        validMove = 1;
                    }
                }
            }
            else
            {
                validMove = 0;
            }
        }
        if ((movingPiece -> firstMove == 1) || (movingPiece -> firstMove != 1))//check if first move or not first move
        {
            if (((abs(finalx - intialx) == 1) || (abs(finaly - intialy) == 1)))//move 1 square
            {
                validMove = 1;
                movingPiece -> firstMove = 0; //after move 1 square update first move = 0
            }
        }
        else
        {
            validMove = 0;
        }
        break;

    default:
        printf("1NOT A VALID MOVE!\n");
        validMove = 0;
        break;
    }//case
    if (validMove == 0)
        printf("NOT A VALID MOVE!\n");
    printf("validmove%d\n", validMove);
    return validMove;
}

int move(Piece *board[12][12], char input[10])
{
    // CONVERTS BOARD'S RANK TO INTERNAL BOARD'S INT X POSITION
    int intialx = fileToInt(input[0]);
    int intialy = rankToInt(input[1]);

    int finalx = fileToInt(input[2]);
    int finaly = rankToInt(input[3]);
    printf("%d\n", intialx);
    printf("%d\n", intialy);
    printf("%d\n", finalx);
    printf("%d\n", finaly);

    // change id matching to using rank and file

    int isValid = validMove(board[intialy][intialx], board[finaly][finalx], board, intialx, intialy, finalx, finaly);
    printf("isvalidmove%d\n", isValid);
    if (isValid == 1)
    {
        printf("move checked\n");
        board[finaly][finalx] = board[intialy][intialx];
        board[finaly][finalx] -> y = finaly;
        board[finaly][finalx] -> x = finalx;
        //free(board[intialy][intialx]);
        board[intialy][intialx] = NULL;
        printf("move excuted\n");
    }
    return isValid;
}

