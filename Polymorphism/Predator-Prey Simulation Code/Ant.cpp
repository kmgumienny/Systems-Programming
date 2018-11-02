//Ant.cpp //kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Ant.h"
#include "Board.h"
#include "Organism.h"

using namespace std;

extern vector<pair<int, int> > moves;

//constuctor for an ant that takes in coordinates.
Ant::Ant(int X, int Y) {
	xCoord = X;
	yCoord = Y;
}

//For every instance of an ant, a "o" is printed.
void Ant::print() {
	cout << "o";
	return;
}

//Used for checking what is in a cell
int Ant::type() {
	return 1;
}

/*
 * function looks at the cells around the ant and finds an
 * empty cell. Once it finds an empty cell in both the new,
 * and old boards, it creates a new ant in the newBoard and
 * increments its times. Returns the x and y coordinates of
 * the new position.
 */
pair<int, int> Ant::move(Organism*** oldBoard, Organism*** newBoard) {
	random_shuffle(moves.begin(), moves.end());
	for (int i = 0; i < 4; i++) {	// check surroundings
		int newx = xCoord + moves[i].first;
		int newy = yCoord + moves[i].second;
		if (!check(newx, newy))
			continue;
		if (oldBoard[newx][newy]->type() > 0
				|| newBoard[newx][newy]->type() != 0) {
			continue;  // not empty
		} else {
			newBoard[newx][newy] = new Ant(newx, newy);
			newBoard[newx][newy]->timer = timer + 1;
			return make_pair(xCoord, yCoord);
		}
	}
	return make_pair(-1, -1);
}

/*
 * generates a new Ant
 */
Organism* Ant::getnew() {
	Ant* a = new Ant(xCoord, yCoord);
	a->timer = timer;
	return a;
}

/*
 * returns an int specifying whether it's time to breed or not.
 */
int Ant::timeBreed() {
	return (timer >= 3);
}

/*
 * first the move vector is shuffled and so a random
 * direction is selected. If an empty location is found,
 * a new ant is put in on the board.
 */
void Ant::breed(Organism*** oldBoard, Organism*** newBoard) {
	random_shuffle(moves.begin(), moves.end());
	random_shuffle(moves.begin(), moves.end());
	for (int i = 0; i < 4; i++) {	// check surroundings
		int newx = xCoord + moves[i].first;
		int newy = yCoord + moves[i].second;
		if (!check(newx, newy))
			continue;
		if (newBoard[newx][newy]->type() == 0) {
			newBoard[newx][newy] = new Ant(newx, newy);
			newBoard[newx][newy]->timer = 0;
			timer = 0;
		}
	}
}	// end breed
