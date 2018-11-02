/*
 * Board.c -- Kamil Gumienny
 */

#include <stdio.h>
#include <stdlib.h>
#include "Life.h"


/*
 * This function goes through the current generation array and checks
 * every cell in the array to see if there is an 'x'. If there is
 * the function returns 0. Otherwise, it returns a 1.
 */
int checkEmpty(char **A, int width, int height) {
	//Loop invariant: i >= 0 & i < height
	for (int i = 0; i < height; i++) {
		//Loop invariant: j >= 0 & j < width
		for (int j = 0; j < width; j++) {
			if (A[i][j] != 'o') {
				return 0;
			}
		}
	}
	return 1;
}

/*
 * This function goes through an array by using a nested for loop
 * and checks the current generation's board to the old generation's
 * board to see if there is a loop. As soon as there is one difference
 * between the two arrays, it returns 0. Otherwise it returns a 1.
 */
int checkSameArrays(char **A, char **C, int width, int height) {
	//Loop invariant: i >= 0 & i < height
	for (int i = 0; i < height; i++) {
		//Loop invariant: j >= 0 & j < width
		for (int j = 0; j < width; j++) {
			if (A[i][j] != C[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}
/*
 * this function takes in two 2D arrays and switches the contents from
 * the old array to the new array by using a nested for loop.
 */

void switchBoards(char **new, char **old, int width, int height) {
	//Loop invariant: i >= 0 & i < height
	for (int i = 0; i < height; i++) {
		//Loop invariant: j >= 0 & j < width
		for (int j = 0; j < width; j++) {
			new[i][j] = old[i][j];
		}
	}
}

/*
 * originally fills the entire Malloc'd array with "o" characters,
 * then centerers the input file. It goes to the starting position
 * for the height and width and continues to read the starting document
 * until it reaches both end width and end height.
 */

void FillArray(FILE *input, char **A, int startAtWidth, int startAtHeight,
		int endAtWidth, int endAtHeight, int width, int height) {
	int num[1000];
	int counter2 = 0;
	int currCharacter = 0;
	int counter = 0;
	//Loop invariant: i >= 1 and <1000. Continues until EOF is reached
	//unless input file is >1000 characters
	for (int i = 0; i < 1000; i++) {
		currCharacter = fgetc(input);
		if (currCharacter == EOF)
			break;
		if (currCharacter == 120 || currCharacter == 111) {
			num[counter] = currCharacter;
			counter++;
		}

	}
	//Loop invariant: i >= 0 & i < height
	for (int i = 0; i < height; i++) {
		//Loop invariant: j >= 0 & j < width
		for (int j = 0; j < width; j++) {
			A[i][j] = 'o';
		}
	}
	//Loop invariant: i >= 0 & i < height
	for (int i = startAtHeight; i <= endAtHeight; i++) {
		//Loop invariant: j >= 0 & j < width
		for (int j = startAtWidth; j <= endAtWidth; j++) {
			A[i][j] = num[counter2];
			counter2++;

		}
	}
	printArrays(width, height, A);
}

/*
 * this function goes though the file that has been provided by the user
 * and gets the size of the longest row and the amount of columns in the
 * file using a while loop
 */
int getFileDimensions(FILE *input, int booleanX) {
	int heightCounter = 0, widthCounter = 0, longestRow = 0;
	int c = 0;
	//The loop invariant is that the loop will continue until it reaches
	//the end-of-file variable
	while ((c = fgetc(input)) != EOF) {
		if (c == '\n') {
			heightCounter++;
			if (longestRow < widthCounter)
				longestRow = widthCounter;
			widthCounter = 0;

		}
		widthCounter++;
	}
	if (booleanX == 1)
		return heightCounter;
	else
		return (longestRow - 1);
}

/*
 * function goes through the input file, determines the longest line
 * and centers the array, if necessary.
 * int dimensions is an array that store the files {width, height};
 */
void readAFile(char* fileSource, char** A, int width, int height) {
	int startAtWidth = 0, startAtHeight = 0, fileWidth = 0, fileHeight = 0;
	FILE *sourceFile;
	sourceFile = fopen(fileSource, "r");
	if (!sourceFile) {
		printf("Unable to open file");
	}
	fileWidth = getFileDimensions(sourceFile, 0) - 1;
	rewind(sourceFile);
	fileHeight = getFileDimensions(sourceFile, 1) - 1;
	startAtWidth = (width - fileWidth) / 2;
	startAtHeight = (height - fileHeight) / 2;
	if (startAtWidth < 0 || startAtHeight < 0) {
		printf("The width or height you provided is smaller than the "
				"width or height of the file that was provided \n");
		printf("startAtWidth %d \n", fileWidth);
		printf("startAtHeight %d 'n", fileHeight);
		exit(0);
	}
	int endAtWidth = fileWidth + startAtWidth;
	int endAtHeight = fileHeight + startAtHeight;
	rewind(sourceFile);
	FillArray(sourceFile, A, startAtWidth, startAtHeight, endAtWidth,
			endAtHeight, width, height);
}

/*
 * The functions allocates space in the heap for three 2D arrays by
 * making pointers to pointers named A, B, and C.
 */
void allocateSpaceA(char **A, int width, int height) {
	if (A)
		//Loop invariant: i >= 0 & i < height. Will run *height* number
		//of times
		for (int i = 0; i < height; i++) {
			A[i] = malloc(width * sizeof(char *));
		}
}

void allocateSpaceB(char **B, int width, int height) {
	if (B)
		//Loop invariant: i >= 0 & i < height. Will run *height* number
		//of times
		for (int i = 0; i < height; i++) {
			B[i] = malloc(width * sizeof(char *));
		}
}

void allocateSpaceC(char **C, int width, int height) {
	if (C)
		//Loop invariant: i >= 0 & i < height. Will run *height* number
		//of times
		for (int i = 0; i < height; i++) {
			C[i] = malloc(width * sizeof(char *));
		}
}

int main(int argc, char **argv) {
	int width, height, gens, print, pause;
	char c;
	int booleanSame = 0, booleanEmpty = 0;
	if (argc < 5) {
		printf("Missing operators");
		return 1;
	}

	width = atoi(argv[1]);
	height = atoi(argv[2]);
	gens = atoi(argv[3]);

	if (width <= 0 || height <= 0 || gens <= 0) {
		printf("Entered invalid number for width, height, or generations");
		return 1;
	}

	if (argc >= 6 && *argv[5] == 'y')
		print = 1;
	else
		print = 0;

	if (argc >= 7 && *argv[6] == 'y')
		pause = 1;
	else
		pause = 0;

	char **A = malloc(width * sizeof(char *));
	char **B = malloc(width * sizeof(char *));
	char **C = malloc(width * sizeof(char *));
	allocateSpaceA(A, width, height);
	allocateSpaceB(B, width, height);
	allocateSpaceC(C, width, height);

	readAFile(argv[4], A, width, height);
	// The loop invariant is i < generations and i >= 0
	for (int i = 0; i <= gens; i++) {
		if (pause)
			scanf("%c", &c);
		booleanSame = checkSameArrays(A, C, width, height);
		if (booleanSame == 1) {
			printf("The game is in a loop. It is generation %d. Exiting\n", i);
			return 1;
		}
		booleanEmpty = checkEmpty(A, width, height);
		if (booleanEmpty == 1) {
			printf("The game has ended. It is generation %d. Exiting\n", i);
			return 1;
		}
		switchBoards(C, B, width, height);
		switchBoards(B, A, width, height);
		PlayOnce(width, height, B, A);
		if (print) {
			if (i > 0)
				printf("The previous generations board\n\n");
			printArrays(width, height, B);
			printf("The %d generation board\n\n", i);
			printArrays(width, height, A);
		}
	}
	return 0;

}
