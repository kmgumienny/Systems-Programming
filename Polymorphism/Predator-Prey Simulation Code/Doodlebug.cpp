//Doodlebug.cpp -- kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Doodlebug.h"
#include "Board.h"

using namespace std;
extern vector<pair<int, int> > moves;
Doodlebug::Doodlebug(int X, int Y) {
	xCoord = X;
	yCoord = Y;
}

// if an instance of Doodlebug is on the board, an "x" is printed
void Doodlebug::print() {
	cout << "x";
	return;
}

//function returns 2 when an instance of Doodlebug is on the board
int Doodlebug::type() {
	return 2;
} // end type

//returns a non 0 integer when a Doodlebug's timer is greater than 8
int Doodlebug::time_to_bread() {
	return (timer >= 8);
}

/*
 * first the moves are shuffled and an cell with an ant is located.
 * if the ant hasn't been eaten yet on the newBoard, the doodleBug
 * is out over the Ant's place on the newBoard.
 */
pair<int, int> Doodlebug::findAnt(Organism*** oldBoard, Organism*** newBoard) {
	random_shuffle(moves.begin(), moves.end());
	for (int i = 0; i < 4; i++) {
		int newx = xCoord + moves[i].first;
		int newy = yCoord + moves[i].second;
		if (!check(newx, newy))
			continue;

		if (oldBoard[newx][newy]->type() == 1
				&& newBoard[newx][newy]->type() == 0) {
			newBoard[newx][newy] = new Doodlebug(newx, newy);
			newBoard[newx][newy]->timer = timer + 1;
			newBoard[newx][newy]->eatCounter = 0;
			return make_pair(xCoord, yCoord);
		}
	}
	return make_pair(-1, -1);
}

/*
 * First the function checks to see if there is an Ant that
 * can be eaten by the doodleBug. If there is, the function ends.
 * otherwise, the moves are shuffled so a random direction is chosen
 * and the location is checked on the new and old Boards and if there
 * it is available, the doodleBug will move there and its eat counter will
 * be incremented. The new location of the doodleBug is returned.
 */
pair<int, int> Doodlebug::move(Organism*** oldBoard, Organism*** newBoard) {
	pair<int, int> trial = this->findAnt(oldBoard, newBoard);
	if (trial != make_pair(-1, -1)) {
		return trial;
	}

	random_shuffle(moves.begin(), moves.end());
	for (int i = 0; i < 4; i++) {
		int newx = xCoord + moves[i].first;
		int newy = yCoord + moves[i].second;
		if (!check(newx, newy))
			continue;
		if (oldBoard[newx][newy]->type() > 0
				|| newBoard[newx][newy]->type() != 0) {
			continue;
		} else {
			newBoard[newx][newy] = new Doodlebug(newx, newy);
			newBoard[newx][newy]->timer = timer + 1;
			newBoard[newx][newy]->eatCounter = eatCounter + 1;
			return make_pair(xCoord, yCoord);
		}
	}
	return make_pair(-1, -1);
}

/*
 * first the move vector is shuffled and so a random
 * direction is selected. If an empty location is found,
 * a new doodleBug is put in on the board.
 */
void Doodlebug::breed(Organism*** oldBoard, Organism*** newBoard) {
	random_shuffle(moves.begin(), moves.end());
	random_shuffle(moves.begin(), moves.end());
	for (int i = 0; i < 4; i++) {
		int newx = xCoord + moves[i].first;
		int newy = yCoord + moves[i].second;

		if (!check(newx, newy))
			continue;

		if (newBoard[newx][newy]->type() == 0) {
			newBoard[newx][newy] = new Doodlebug(newx, newy);
			newBoard[newx][newy]->timer = 0;
			timer = 0;
		}
	}
}

/*
 * a constructor for a doodleBug from an existing
 * doodleBug.
 */
Organism* Doodlebug::getnew() {
	Doodlebug* a = new Doodlebug(xCoord, yCoord);
	a->timer = timer;
	a->eatCounter = eatCounter;
	return a;
}

/*
 * If the eatCounter is greater than 3, an
 * Organism replaces the doodleBug on the new
 * Board, which is essentially an empty space.
 */
void Doodlebug::starvation(Organism*** newBoard) {
	if (eatCounter >= 3) {
		newBoard[xCoord][yCoord] = new Organism();
		return;
	}
}
