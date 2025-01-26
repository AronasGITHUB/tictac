// libraries
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// variables (global)
char Table[3][3];
const char PLAYER = 'X';
const char BOT = 'O';

// function declarations
void resetTable();
void outputTable();
void moveUser();
void moveBot();
void outputWinner(char);
int freeSpace();
char winnerCheck();

// main script
int main() {
	
	// variables (local)
	char Winner = ' ';
	
	// welcome screen
	printf("~~~~~ Welcome to TicTac, a Tic Tac Toe game made in C! ~~~~~\n");

	// main game 
	resetTable();
	
	while (Winner == ' ' && freeSpace() != 0) {
		outputTable();

		moveUser();
		Winner = winnerCheck();

		// if there is a winner, or there arent free space left, break out of while loop.
		if (Winner != ' ' || freeSpace() == 0) {
			break;
		}

		moveBot();
		Winner = winnerCheck();

		// if there is a winner, or there arent free space left, break out of while loop.
		if (Winner != ' ' || freeSpace() == 0) {
			break;
		}

		// Print output to player
		outputTable();
		outputWinner(Winner);
	}

	// End script
	return 0;
}


// functions
void resetTable() {
	for (int i = 0; i < 3; i++) {

		for (int a = 0; a < 3; a++) {
			Table[i][a] = ' ';
		}

	}
}

void outputTable() {

	printf("-------------\n");
	printf("| %c | %c | %c | \n", Table[0][0], Table[0][1], Table[0][2]);
	printf("|---|---|---|\n");
	printf("| %c | %c | %c |\n", Table[1][0], Table[1][1], Table[1][2]);
	printf("|---|---|---|\n");
	printf("| %c | %c | %c |\n", Table[2][0], Table[2][1], Table[2][2]);
	printf("|---|---|---|\n");
	printf("-------------\n");

}

int freeSpace() {
	
	int Space = 9;

	for (int i = 0; i < 3; i++) {

		for (int a = 0; a < 3; a++) {

			if (Table[i][a] != ' ') {
			       Space--;	
			}

		}
	
	}
	
	// if no space is left, end game	
	return Space;

}

void moveUser() {
	
	// local variables representing position
	int hor;
	int ver;
	
	do {
		// prompts
		printf("Enter row 1-3: ");
		scanf("%d", &hor);
		hor--;

		printf("\nEnter column 1-3: ");
		scanf("%d", &ver);
		ver--;

		if (Table[hor][ver] != ' ') {
			printf("[!] Invalid position.");
		} else {
			Table[hor][ver] = PLAYER;
			break;
		}

	} while (Table[hor][ver] != ' ');
		
}

void moveBot() {

	// generate seed from time
	srand(time(0));
	int hor;
	int ver;
	
	// randomly generate until free space is available
	if (freeSpace() > 0) {
		do {
			hor = rand() % 3;
			ver = rand() % 3;
		} while (Table[hor][ver] != ' ');

		Table[hor][ver] = BOT;
	} else {
		outputWinner(' ');
	}
}

char winnerCheck() {
	// check rows
	for (int i = 0; i < 3; i++) {

		if (Table[i][0] == Table[i][1] && Table[i][0] == Table[i][2]) {
			return Table[i][0];
		}

	}

	// check collumns
	for (int i = 0; i < 3; i++) {

		if (Table[0][i] == Table[1][i] && Table[0][i] == Table[2][i]) {
			return Table[0][i];
		}

	}

	// check diagonals
	if (Table[0][0] == Table[1][1] && Table[0][0] == Table[2][2]) {
		return Table[0][0];
	}

	if (Table[0][2] == Table[1][1] && Table[0][2] == Table[2][0]) {
		return Table[0][2];
	}
	
	// if no winner, return empty character
	return ' ';
}

void outputWinner(char Winner) {

	if (Winner == PLAYER) {
		printf("~~ You Win! ~~\n");
	} else if (Winner == BOT) {
		printf("~~ Bot Wins! ~~\n");
	} else {
		printf("~~ No one won. ~~\n");
	}
}


