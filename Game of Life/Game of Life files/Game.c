/*
 * Game.c -- Kamil Gumienny

 */
#include <stdio.h>
#include <stdlib.h>
#include "Life.h"
/*
 * a method that prints the contents of a 2D array by looking at every element
 * and printing a space if the spot holds an 'o' and and 'x' if the array
 * holds an x
 */
void printArrays(int width, int height, char** anArray) {
	// The loop invariant is i < height and i >= 0
	for (int i = 0; i < height; i++) {
		// The loop invariant is j < width and j >= 0
		for (int j = 0; j < width; j++) {
			if (anArray[i][j] == 'x')
				printf("x");
			if (anArray[i][j] == 'o')
				printf(" ");
			if (j == width - 1)
				printf("\n");
		}
	}

}

/*
 *  looks at the neighbors of the given cell
 *  and determines how many surround that block in the 2D array.
 *  Conditions for when the block being checked is on the edge of
 *  the board;
 */

int NeighborCheck(char **Old, int i, int j, int width, int height) {
	int counter = 0;
	if (i == 0) {
		if (j == 0) {
			if (Old[i][j + 1] == 'x')
				counter++;
			if (Old[i + 1][j] == 'x')
				counter++;
			if (Old[i + 1][j + 1] == 'x')
				counter++;
			return counter;
		}
		if (j == width - 1) {
			if (Old[i][j - 1] == 'x')
				counter++;
			if (Old[i + 1][j - 1] == 'x')
				counter++;
			if (Old[i + 1][j] == 'x')
				counter++;
			return counter;
		} else {
			if (Old[i][j - 1] == 'x')
				counter++;
			if (Old[i][j + 1] == 'x')
				counter++;
			if (Old[i + 1][j - 1] == 'x')
				counter++;
			if (Old[i + 1][j] == 'x')
				counter++;
			if (Old[i + 1][j + 1] == 'x')
				counter++;
			return counter;
		}

	}
	if (i == height - 1) {
		if (j == 0) {
			if (Old[i - 1][j] == 'x')
				counter++;
			if (Old[i - 1][j + 1] == 'x')
				counter++;
			if (Old[i][j + 1] == 'x')
				counter++;
			return counter;
		}
		if (j == width - 1) {
			if (Old[i][j - 1] == 'x')
				counter++;
			if (Old[i - 1][j - 1] == 'x')
				counter++;
			if (Old[i - 1][j] == 'x')
				counter++;
			return counter;
		} else {
			if (Old[i][j - 1] == 'x')
				counter++;
			if (Old[i][j + 1] == 'x')
				counter++;
			if (Old[i - 1][j - 1] == 'x')
				counter++;
			if (Old[i - 1][j] == 'x')
				counter++;
			if (Old[i - 1][j + 1] == 'x')
				counter++;
			return counter;
		}
	}
	if (j == 0 && (i != 0 || height - 1)) {
		if (Old[i - 1][j] == 'x')
			counter++;
		if (Old[i - 1][j + 1] == 'x')
			counter++;
		if (Old[i][j + 1] == 'x')
			counter++;
		if (Old[i + 1][j + 1] == 'x')
			counter++;
		if (Old[i + 1][j] == 'x')
			counter++;
		return counter;
	}
	if (j == (width - 1) && (i != 0 || height - 1)) {
		if (Old[i - 1][j] == 'x')
			counter++;
		if (Old[i - 1][j - 1] == 'x')
			counter++;
		if (Old[i][j - 1] == 'x')
			counter++;
		if (Old[i + 1][j - 1] == 'x')
			counter++;
		if (Old[i + 1][j] == 'x')
			counter++;
		return counter;
	} else {
		if (Old[i - 1][j] == 'x')
			counter++;
		if (Old[i - 1][j - 1] == 'x')
			counter++;
		if (Old[i - 1][j + 1] == 'x')
			counter++;
		if (Old[i][j + 1] == 'x')
			counter++;
		if (Old[i][j - 1] == 'x')
			counter++;
		if (Old[i + 1][j] == 'x')
			counter++;
		if (Old[i + 1][j + 1] == 'x')
			counter++;
		if (Old[i + 1][j - 1] == 'x')
			counter++;

		return counter;
	}
	return 'o';
}

/*
 * the function looks at the cell, determines if it is
 * inhabited ('x' for inhabited, 'o' for empty) and then
 * passes it along to NeighborCheck to see how many neighbors
 * it has.  If there are 0,1,4,5,6,7, or 8 neighbors and the cell is
 * inhabited, the function returns an 'o'. If the cell is not
 * inhabited and has 3 neighbors, the function returns an 'x'.
 * If the cell is inhabited and has 2 or 3 neighbors, an 'x'
 * is returned.
 */

int countNeighbors(char** Old, int i, int j, int width, int height) {
	int numberNeighbors;
	if (Old[i][j] == 'x') {
		numberNeighbors = NeighborCheck(Old, i, j, width, height);
		if (numberNeighbors == 0 || numberNeighbors == 1 || numberNeighbors == 4
				|| numberNeighbors == 5 || numberNeighbors == 6
				|| numberNeighbors == 7 || numberNeighbors == 8)
			return 'o';
		if (numberNeighbors == 2 || numberNeighbors == 3)
			return 'x';
		else
			printf("countNeightbors found %d neighbors. error\n",
					numberNeighbors);
		return 'o';
	}
	if (Old[i][j] == 'o') {
		numberNeighbors = NeighborCheck(Old, i, j, width, height);
		if (numberNeighbors == 3)
			return 'x';
		else
			return 'o';
	}
	return 'o';

}

/*
 * PlayOne is a function that cycles through the New 2D array
 * by using two nested for loops and
 * for every space in the array, calls the function countNeighbors
 * with the old array to determine how many neighbors a cell has
 * and then either places an 'x' or an 'o' depending on how many
 * neighbors the old array had
 */
void PlayOnce(int width, int height, char** Old, char** New) {
	//Loop Invariant- i >= 0 & i < height
	for (int i = 0; i < height; i++) {
		//Loop Invariant- j >= 0 & j < width
		for (int j = 0; j < width; j++) {
			New[i][j] = countNeighbors(Old, i, j, width, height);
		}
	}

}

