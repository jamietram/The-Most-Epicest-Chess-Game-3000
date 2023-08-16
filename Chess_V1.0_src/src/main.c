#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "Board.h"
#include "Move.h"
#include "Setting.h"
#include "PlayGame.h"

int main(){
	//Piece *board[12][12];
	const int EXIT = 3;
	int userInput, settingInput, play_Menu_Input;
	int cChoice = 1;
	int dChoice = 1;
	int p2color = 2;
	char colorChoice[6], diffChoice[12];
	PrintMenu();
	printf("\nYour choice: ");
	scanf("%d", &userInput);
	while(userInput != EXIT){
		switch(userInput){
			// generate chess board with settings
			case 1:
				//Piece *board[12][12];               // 2D ARRAY OF POINTERS TO PIECE STRUCT
               			//generateBoard(board);               // GENERATES INITIAL BOARD
                		//printBoard(board);                  // PRINT BOARD
                		//move(board);                // MOVE TO ROW 5, COLUMN A
                		//printBoard(board);                  // PRINT UPDATED BOARD
                		//move(board);
                		//printBoard(board);
                		playMenu();
				printf("\nYour choice: ");
				scanf("%d",&play_Menu_Input);
				while(play_Menu_Input != EXIT){
					switch(play_Menu_Input){
						case 1:
							printf("\n\x1b[34mYou chose to play --Player vs Player mode--\x1b[0m \n\n");
							//PlayGame();
							PlayGame(play_Menu_Input, cChoice, p2color);
							break;
						case 2:
							printf("\n\x1b[33mYou chose to play --Player vs AI mode--\x1b[0m \n\n");
							PlayGame(play_Menu_Input, cChoice, p2color);
							
							break;
						default:
							break;
					}
					playMenu();
					printf("\nYour choice: ");
					scanf("%d", &play_Menu_Input);
				}	
				break;
			
			case 2:
				Settings();
				printf("\nYour choice: ");
				scanf("%d", &settingInput);
				while(settingInput != EXIT){
					switch(settingInput){
						// User chooses color
						case 1:
							printf("\n\nPlease select a color to play as:\n");
							printf("White     Black\n");
							printf("\nYour choice: ");
							scanf("%s", colorChoice);
							cChoice = pickColor(colorChoice);
							//SET PLAYER2/AI COLOR
							if(cChoice == 1)
								p2color = 2;
							else if(cChoice == 2)
								p2color = 1;
							printf("\n\nYou chose to play as %s.\n", colorChoice);
							while(cChoice == 0){
								printf("You chose an invalid color! Please try again.\n");
								printf("\nYour choice: ");
								scanf("%s", colorChoice);
								cChoice = pickColor(colorChoice);
								if(cChoice == 1)
									p2color = 2;
								else if(cChoice == 2)
									p2color = 1;
								printf("\n\nYou chose to play as %s.\n", colorChoice);
							}
							//userColor();
							break;

						// User chooses difficulty
						case 2:
							printf("\n\nPlease select a difficulty for the AI:\n");
							printf("Beginner   Intermediate   Expert\n");
							printf("\nYour choice: ");
							scanf("%s", diffChoice);
							dChoice = pickDifficulty(diffChoice);
							printf("\n\nYou chose the %s difficulty.\n", diffChoice);
							while(dChoice == 0){
								printf("You chose an invalid difficulty! Please try again.\n");
								printf("\nYour choice: ");
								scanf("%s", diffChoice);
								dChoice = pickDifficulty(diffChoice);
								printf("\n\nYou chose the %s difficulty.", diffChoice);
							}
							break;
						default:
							break;
					}
					Settings();
					printf("\nYour choice: ");
					scanf("%d", &settingInput);
				}
				break;
			default:
				break;
		}
		
		if(userInput > 3 && userInput < 1){
			printf("Invalid input! Please try again");
		}

		PrintMenu();
		printf("\nYour choice: ");
		scanf("%d", &userInput);
	}
	printf("Thank you for playing!\n");
}
