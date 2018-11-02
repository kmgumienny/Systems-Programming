/*
 * Life.h -- Kamil Gumienny
 *
 */

#ifndef LIFE_H_
#define LIFE_H_

void FillArray(FILE *input, char **A, int startAtWidth, int startAtHeight,
		int endAtWidth, int endAtHeight, int width, int height);
int getFileDimensions(FILE *input, int x);
void readAFile(char* fileSource, char** A, int width, int height);
int checkSameArrays(char **A, char **C, int width, int height);
int checkEmpty(char **A, int width, int height);
void allocateSpaceA(char **A, int width, int height);
void allocateSpaceB(char **B, int width, int height);
void allocateSpaceC(char **C, int width, int height);
void printArrays(int width, int height, char** anArray);
int NeighborCheck(char** Old, int i, int j, int width,int height);
int countNeighbors(char** Old, int i, int j, int width, int height);
void switchBoards(char **new, char **old, int width, int height);
void PlayOnce(int width, int height, char** Old, char** New);

#endif /* LIFE_H_ */
