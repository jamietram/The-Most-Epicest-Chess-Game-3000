#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "PlayGame.h"
#include "Board.h"
#include "Move.h"
#include "AI.h"

void PlayGame(int pOption, int P1, int P2)
{
	char input[10];

	//OPEN AND CREATE LOG FILE
	FILE *log;
	log = fopen("./bin/log.txt", "w");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(log, "THE MOST EPICEST CHESS GAME\nCREATED BY TEAM TBD ON:\n%02d/%02d/%d AT %02d:%02d\n", tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
	char moveLine[10];
	int moveCount = 1;
	int logMove;
	char compMove[10];

	//GENERATE AND PRINT INITIAL BOARD
	Piece *board[12][12];
	generateBoard(board);
	printBoard(board);

	//USER TURN
	int playerCount = 1;
	char playerTurn[10];
	//LOOP USER INPUT AND PLAY GAME
	printf("\nWhite's turn!\n");
	printf("\nInput move\nFormat (e2e4)\n");
	scanf("%s", input);
	if(strcmp(input, "log") != 0 && strcmp(input, "exit") != 0){
		while(colorCheck(board, input, P1, P2, playerCount)){
			printf("\nInvalid move! Please try again\n");
			printf("White's turn!\n");
			scanf("%s",input);
		}
	}

	//LOOP TILL 'exit'
	while(strcmp(input, "exit") != 0){
		//IF 'log' PRINT log.txt
		if(strcmp(input, "log") == 0){
			fclose(log);
			log = fopen("./bin/log.txt", "r");
			while(fgets(moveLine, 50, log) != NULL){
				puts(moveLine);
			}
			fclose(log);
			log = fopen("./bin/log.txt", "a");
			printBoard(board);
			if(playerCount % 2 == 1)
				strcpy(playerTurn, "White");
			else
				strcpy(playerTurn, "Black");
			printf("%s's turn!\n", playerTurn);
			printf("\nInput move\nFormat (e2e4)\n");
			scanf("%s", input);
			if(strcmp(input, "log") != 0 && strcmp(input, "exit") != 0){
				while(colorCheck(board, input, P1, P2, playerCount)){
					printf("\nInvalid move! Please try again\n");
					printf("%s's turn!\n", playerTurn);
					scanf("%s",input);
				}
			}
			if(strcmp(input, "exit") == 0)
				break;
		}
		logMove = move(board, input);
		if(logMove == 1){
			fprintf(log, "%d. %s\n", moveCount, input);
			moveCount++;
		}

		if(strcmp(input, "log") != 0){
			if(pOption == 2){
				strcpy(compMove, PlayGameAI(board));
				fprintf(log, "%d. %s\n", moveCount, compMove);
				moveCount++;
			}
			else{
				playerCount++;
				if(playerCount % 2 == 1)
					strcpy(playerTurn, "White");
				else
					strcpy(playerTurn, "Black");
				printBoard(board);
				printf("\n%s's Turn!\n", playerTurn);
			}

			//CHECK FOR WIN/LOSS
			if(kingCap(board, BLACK) == 0){
				printf("\nWHITE WINS\nBLACK L\n");
				break;
			}
			if(kingCap(board, WHITE) == 0){
				printf("\nBLACK WINS\nWHITE L\n");
				break;
			}

			promote(board, input, playerCount);
			printf("\nInput move\nFormat (e2e4)\n");
			scanf("%s", input);
			if(strcmp(input, "log") != 0 && strcmp(input, "exit") != 0){
				while(colorCheck(board, input, P1, P2, playerCount)){
						printf("\nInvalid move! Please try again\n");
						printf("%s's turn!\n", playerTurn);
						scanf("%s",input);
				}
			}
		}
	}
	fclose(log);
}

const char* PlayGameAI(Piece *board[12][12])
{
	//Piece *board[12][12];
	//printBoard(board);
	Piece* movingPiece;
	int* locationArray;
	char* input;

	/*move(board, "e7e5");
	move(board, "a7a5");
	move(board, "b7b5");
	move(board, "c7c5");
	move(board, "d7d5");
	move(board, "f7f5");
	move(board, "g7g5");
	move(board, "h7h5");*/
	//move(board, "g8f6");
	//move(board, "f8h6");


	int validAIMove = 0;
	while (!validAIMove)
	{
		movingPiece = chooseRandPiece(board);
		if(movingPiece != NULL){
			locationArray = generateAIMove(movingPiece, board);
			input = AIinput(movingPiece, locationArray);
			validAIMove = move(board, input);
		}
	}
	printBoard(board);
	return input;
}

int colorCheck(Piece *board[12][12], char input[10], int P1, int P2, int playerCount){

	int Valid = 0;
	//CONVERT INPUT TO COORDS
	int initialx = fileToInt(input[0]);
    int initialy = rankToInt(input[1]);

	//IF PLAYER 1 TURN
	if(playerCount % 2 == 0){
			//IF PLAYER1 IS WHITE
			if(P1 == 1){
					if(board[initialy][initialx] != NULL && board[initialy][initialx] -> idNum == 16){
						Valid = 1;
					}
					else
						return Valid;
			}
			//IF PLAYER1 IS BLACK
			else if(P1 == 2){
					if(board[initialy][initialx] != NULL && board[initialy][initialx] -> idNum > -1 && board[initialy][initialx] -> idNum < 16){
						Valid = 1;
					}
					else
						return Valid;
			}
	}

	//IF PLAYER 2 TURN
	else{
		//IF PLAYER2/AI IS WHITE
		if(P2 == 1){
				if(board[initialy][initialx] != NULL && board[initialy][initialx] -> idNum == 16){
					Valid = 1;
				}
				else
					return Valid;
		}
		//IF PLAYER2/AI IS BLACK
		else if(P2 == 2){
				if(board[initialy][initialx] != NULL && board[initialy][initialx] -> idNum > -1 && board[initialy][initialx] -> idNum < 16){
					Valid = 1;
				}
				else
					return Valid;
		}
	}
	return Valid;
}

void promote(Piece *board[12][12], char input[10], int playerCount){
    int finalx = fileToInt(input[2]);
    int finaly = rankToInt(input[3]);

	int invChoice = 1;
	char pieceChange[10];

	//WHITE PAWN MOVES
	if(playerCount % 2 == 1){
		if(board[finaly][finalx] -> type == PAWN){
			if(finaly == 2){
				printf("Pawn is able to promote!\nPlease choose a piece to promote to:\n");
				printf("ROOK   KNIGHT   BISHOP   QUEEN\n");
				scanf("%s", pieceChange);
				while(invChoice == 1){
					if(strcmp(pieceChange, "ROOK") == 0 || strcmp(pieceChange, "rook") == 0){
						board[finaly][finalx] -> type = ROOK;
						break;
					}
					else if(strcmp(pieceChange, "KNIGHT") == 0 || strcmp(pieceChange, "knight") == 0){
						board[finaly][finalx] -> type = KNIGHT;
						break;
					}
					else if(strcmp(pieceChange, "BISHOP") == 0 || strcmp(pieceChange, "bishop") == 0){
						board[finaly][finalx] -> type = BISHOP;
						break;
					}
					else if(strcmp(pieceChange, "QUEEN") == 0 || strcmp(pieceChange, "queen") == 0){
						board[finaly][finalx] -> type = QUEEN;
						break;
					}
					else{
						invChoice = 1;
					}
				}
			}
		}
	}
}

int kingCap(Piece *board[12][12], Color color){
	int kingAlive = 0;
	for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
			if(board[i][j] == NULL)
				continue;
			if ((board[i][j]-> color == color) && (strcmp(board[i][j]->id, "K") == 0))
				kingAlive = 1;
		}
	}
	return kingAlive;
}