//Doodlebug.cpp -- kmgumienny

#ifndef BOARD_H_
#define BOARD_H_

void printStep(int gridsize, Organism*** oldBoard);
int check(int x,int y);
void play(int gridsize, Organism*** OldBoard, int turnNum, int count=1);
#endif /* BOARD_H_ */
