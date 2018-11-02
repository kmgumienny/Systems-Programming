//Doodlebug.cpp -- kmgumienny


using namespace std;

#ifndef ORGANISM_H_
#define ORGANISM_H_

class Organism {
public:
	Organism();
	virtual ~Organism(){}
	int xCoord, yCoord;
	int timer;
	int eatCounter;
	virtual void print();
	virtual int type(){return 0;}
	virtual Organism* getNew(){return NULL;}
	virtual int time_to_bread(){return 0;}
	virtual pair<int,int> move(Organism*** oldBoard, Organism*** newBoard){return make_pair(-1,-1);}
	virtual void breed(Organism*** oldBoard, Organism*** newBoard){}
	virtual void starvation(Organism*** newBoard){}

};

#endif /* ORGANISM_H_ */
