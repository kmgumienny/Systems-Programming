// Ant.h -- kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifndef ANT_H_
#define ANT_H_

#include "Organism.h"

class Ant : public Organism {
public:
	Ant(int X,int Y);
	virtual ~Ant(){}
	void print();
	int type();
	Organism* getnew();
	pair<int,int> move(Organism*** oldBoard, Organism*** newBoard);
	void breed(Organism*** oldBoard, Organism*** newBoard);
	int timeBreed();
};

#endif /* ANT_H_ */
