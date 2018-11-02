//Doodlebug.cpp -- kmgumienny

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Organism.h"

using namespace std;

extern int pause;
extern int gridSize;

/*
 * function looks at a coordinate and checks to see if it exists on
 * the board. returns 0 if false, 1 if true.
 */
int check(int x, int y) {  // checks if (x,y) is in the range of board
	if (x < 0 || y < 0 || x >= gridSize || y >= gridSize)
		return 0;
	return 1;
}

/*
 * Goes through the entire board and calls the print
 * function of the organism in that location.
 */
void printStep(int gridsize, Organism*** aBoard) {
	for (int i = 0; i < gridsize; i++) {
		for (int j = 0; j < gridsize; j++) {
			aBoard[i][j]->print();
		}
		cout << endl;
	}
	cout << endl;
}

/*
 * The function first checks to see if it should be done. It then
 * generates a newBoard to be the same size as the oldBoard.
 * It then places an organism in each of the spaces on the board.
 * A loop then runs and assigns the organisms their coordinates
 * so organisms can track where they are on the board. A loop is ran
 * on the oldBoard that locates Doodlebugs and makes them move.
 * The same is then done for the Ants. A loop is then ran to check
 * whether a doodleBug is starving. Lastly all the cells are checked
 * to see if the organism is ready to breed and if it is, it breeds.
 * Finally, the board is printed, the oldBoard is freed, and the
 * function calls itself recursively.
 */
void play(int gridsize, Organism*** oldBoard, int turnNum, int count = 1) {
	if (turnNum == 0) {
		return;
	}
	int rows, columns;
	rows = columns = gridsize;
	Organism ***newBoard = (Organism ***) malloc(sizeof(Organism**) * gridsize);

	for (int i = 0; i < rows; i++) {
		newBoard[i] = (Organism**) malloc(columns * sizeof(Organism*));
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			newBoard[i][j] = new Organism();
		}
	}

	for (int i = 0; i < gridsize; i++)
		for (int j = 0; j < gridsize; j++)
			oldBoard[i][j]->xCoord = i, oldBoard[i][j]->yCoord = j;

	for (int i = 0; i < gridsize; i++)
		for (int j = 0; j < gridsize; j++) {
			if (oldBoard[i][j]->type() == 0)
				continue;
			if (oldBoard[i][j]->type() == 2) {
				pair<int, int> new_loc = oldBoard[i][j]->move(oldBoard,
						newBoard);

				if (new_loc == make_pair(-1, -1)) {
					newBoard[i][j] = oldBoard[i][j]->getNew();
					newBoard[i][j]->timer++;
				}

			}
		}

	for (int i = 0; i < gridsize; i++)
		for (int j = 0; j < gridsize; j++) {
			if (oldBoard[i][j]->type() == 0)
				continue;
			if (oldBoard[i][j]->type() == 1 && newBoard[i][j]->type() != 2) {
				pair<int, int> new_loc = oldBoard[i][j]->move(oldBoard,
						newBoard);

				if (new_loc == make_pair(-1, -1)) {

					newBoard[i][j] = oldBoard[i][j]->getNew();
					newBoard[i][j]->timer++;
				}
			}
		}

	for (int i = 0; i < gridsize; i++)
		for (int j = 0; j < gridsize; j++) {
			if (newBoard[i][j]->type() == 0)
				continue;
			if (newBoard[i][j]->type() == 2) {
				newBoard[i][j]->starvation(newBoard);
			}
			if (newBoard[i][j]->time_to_bread()) {
				newBoard[i][j]->breed(oldBoard, newBoard);
			}
		}

	printStep(gridsize, newBoard);

	if (pause) {
		getchar();
	}

	for (int i = 0; i < rows; i++) {
		free(oldBoard[i]);
	}

	free(oldBoard);
	play(gridsize, newBoard, turnNum - 1, count + 1);
}
