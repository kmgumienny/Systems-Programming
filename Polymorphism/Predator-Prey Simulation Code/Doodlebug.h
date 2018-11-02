//Doodlebug.cpp -- kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#include "Organism.h"

#ifndef DOODLEBUG_H_
#define DOODLEBUG_H_

class Doodlebug : public Organism {
public:
	Doodlebug(int X,int Y);
	virtual ~Doodlebug(){}
	int type();
	void print();
	pair<int,int> move(Organism*** oldBoard, Organism*** newBoard);
	pair<int,int> findAnt(Organism*** oldBoard, Organism*** newBoard);
	void starvation(Organism*** oldBoard);
	int time_to_bread();
	Organism* getnew();
	void breed(Organism*** oldBoard, Organism*** newBoard);
};

#endif /* DOODLEBUG_H_ */
