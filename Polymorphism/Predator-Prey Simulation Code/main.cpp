//Doodlebug.cpp -- kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#include "Organism.h"
#include "Ant.h"
#include "Doodlebug.h"
#include "Board.h"

using namespace std;

//aBoard is the game Board
Organism*** aBoard;
//vestor for all the possible moves
vector<pair<int, int> > moves;
//the default grid size, 20
int gridSize = 20;
// the default number of doodleBugs, 5
int doodlebugNum = 5;
//the default number of Ants, 100
int antNum = 100;
//the default number of turns, 1000
int turnNum = 1000;
//The seed is stored here.
int seed;
//the default pause is set to false.
int pause = 0;

/*
 * main first goes through the command line arguments and
 * changes the default parameters. A new board is then made
 * and every location is made Null. Then Ants and DoodleBugs are
 * placed thoughout the board randomly. Then, all the NULL spaces
 * are replaced with Organisms. The move vector is then created
 * and the play function is called.
 */
int main(int argc, char *argv[]) {

	if (argc == 2)
		gridSize = atoi(argv[1]);
	srand(time(NULL));

	if (argc == 3) {
		gridSize = atoi(argv[1]);
		doodlebugNum = atoi(argv[2]);
		srand(time(NULL));
	}
	if (argc == 4) {
		gridSize = atoi(argv[1]);
		doodlebugNum = atoi(argv[2]);
		antNum = atoi(argv[3]);
		srand(time(NULL));
	}
	if (argc == 5) {
		gridSize = atoi(argv[1]);
		doodlebugNum = atoi(argv[2]);
		antNum = atoi(argv[3]);
		turnNum = atoi(argv[4]);
		srand(time(NULL));
	}
	if (argc == 6) {
		gridSize = atoi(argv[1]);
		doodlebugNum = atoi(argv[2]);
		antNum = atoi(argv[3]);
		turnNum = atoi(argv[4]);
		seed = atoi(argv[5]);
		srand(seed);
	}
	if (argc == 6) {
		gridSize = atoi(argv[1]);
		doodlebugNum = atoi(argv[2]);
		antNum = atoi(argv[3]);
		turnNum = atoi(argv[4]);
		seed = atoi(argv[5]);
		srand(seed);
		int x = atoi(argv[6]);
		if (x)
			pause = 1;
	}

	aBoard = (Organism ***) malloc(sizeof(Organism**) * gridSize);
	for (int i = 0; i < gridSize; i++) {
		aBoard[i] = (Organism **) malloc(sizeof(Organism*) * gridSize);
	}

	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < gridSize; j++) {
			aBoard[i][j] = NULL;
		}

	int numAnts = antNum;

	while (numAnts) {
		int X = rand() % gridSize;
		int Y = rand() % gridSize;
		if (aBoard[X][Y] != NULL)
			continue;
		numAnts--;
		aBoard[X][Y] = new Ant(X, Y);
	}

	int numDood = doodlebugNum;

	while (numDood) {
		int X = rand() % gridSize;
		int Y = rand() % gridSize;
		if (aBoard[X][Y] != NULL)
			continue;
		numDood--;
		aBoard[X][Y] = new Doodlebug(X, Y);
	}

	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < gridSize; j++) {
			if (aBoard[i][j] == NULL)
				aBoard[i][j] = new Organism();
		}

	moves.push_back(make_pair(0, -1));
	moves.push_back(make_pair(1, 0));
	moves.push_back(make_pair(0, 1));
	moves.push_back(make_pair(-1, 0));

	printStep(gridSize, aBoard);
	play(gridSize, aBoard, turnNum);
	return 0;
}
