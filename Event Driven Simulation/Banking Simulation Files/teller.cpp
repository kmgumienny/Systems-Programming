//teller.cpp - kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "teller.h"
#include "event.h"
extern int tellers;
extern int* tellerLines;
extern TellerQueue* tellerQueues;
extern EventQueue *evntQueue;
extern TellerQueue tellerQueue;
extern int totalTime;
extern int avgTranTime;
extern int timesIdle;
extern int transactionTime;
extern int simulationTime;
using namespace std;

/*
 * Used to add an Event to a Teller's queue based on
 * their times.
 */
void Teller::Action() {
	tellerQueue.aQueue.push(this);
}

/*
 * The function first goes through tellerLines and checks
 * if there are no people in the lines. If there are no
 * people in the lines, the teller goes idle. Otherwise,
 * the teller pulls people from the largest line. Then, the
 * line gets sent to the Transation function.
 */

void Teller::Action2() {
	if (tellerLines[lineNumber] == 0) {
		int pnt = 0;
		for (int i = 0; i < tellers; i++) {
			if (tellerLines[i])
				pnt = 1;
		}
		if (pnt == 0) {
			this->addTime(this->getIdle());
			idleTime += this->getIdle();
			timesIdle++;

			if (this->getTime() <= simulationTime)
				evntQueue->addEvent(this);
		}
		else {
			int maximum = 0, numMax = 0;

			for (int i = 0; i < tellers; i++) {
				if (tellerLines[maximum] < tellerLines[i])
					maximum = i;
			}
			for (int i = 0; i < tellers; i++) {
				if (tellerLines[maximum] == tellerLines[i])
					numMax++;
			}
			int random = rand() % numMax;
			for (int i = 0; i < tellers; i++) {
				if (tellerLines[maximum] == tellerLines[i]) {
					if (random == 0) {
						Transaction(i);
						break;
					}
					random--;
				}
			}
		}
		return;
	}
	Transaction(lineNumber);
}

/*
 * the function creates an event and assigns the first Customer
 * in the queue to it then deletes the Customer from the queue
 * and updates the amount of people in the line. A transaction time
 * is then generated, the statistics for time are updated, and the teller
 * is put back into the event queue.
 */

void Teller::Transaction(int lineNumber) {
	Event* evnt = tellerQueues[lineNumber].getTop();
	tellerQueues[lineNumber].remove();
	tellerLines[lineNumber]--;
	int transTime= avgTranTime + rand()%50;
	addTime(transTime);
	totalTime += (getTime() - evnt->getTime());
	transactionTime += transTime;
	evntQueue->addEvent(this);
}

/*
 * function adds time to the teller object for use in the
 * event queue.
 */

void Teller::addTime(int transTime) {
	this->time += transTime;
}

/*
 * getIdle is a getter for a Teller's idleTime
 */
int Teller::getIdle() {
	return idleTime;
}


/*
 * getTime is a getter for a Teller's time.
 */
int Teller::getTime() {
	return time;
}

/*
 * method creates an Event object for a
 * Teller and creates a random idle time from
 * 1 to 600 seconds.
 */

Event* Teller::add() {
	int idle = 1 + rand() % 600;
	Event* in = new Teller(idle);
	return in;
}
