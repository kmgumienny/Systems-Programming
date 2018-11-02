// customer.cpp -- kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include "teller.h"
#include "customer.h"

using namespace std;

extern TellerQueue tellerQueue;
extern int totalTime;
extern int avgTranTime;
extern int idleTime;
extern int timesIdle;
extern int transactionTime;
extern int* tellerLines;
extern int tellers;
extern TellerQueue* tellerQueues;
extern int simulationTime;


/*
 * The customer Action class first checks the first item in the
 * queue and checks if the arrival time is greater than the tellers
 * current time. If the top item is arriving later, a new event is made
 * and the next customer is removed from the queue. Idle time is generated
 * for the teller. That same time is added to the customer's wait time
 * and puts him back in the queue. Statistics are then updated for Idles.
 * If the customer's time is equal to or less than the teller's time,
 * he is removed from the queue, a random transaction time is geterated
 * from 1 to 500 seconds, statistics are updated and the customer is
 * added into the tellerQueue.
 */

void Customer::Action(){
	Event* now = new Event();

	while(tellerQueue.getTop()->getTime() < this->time){
		Event* now2 = new Event();
		now2 = (tellerQueue.getTop());
		tellerQueue.remove();
		now2->addTime(now2->getIdle());
		tellerQueue.addEvent(now2);
		idleTime += now2->getIdle();
		timesIdle++;
	}
	now=tellerQueue.getTop();
	tellerQueue.remove();
	int transTime= avgTranTime + rand()%50;
	now->addTime(transTime);
	totalTime += (now->getTime()-this->time);
	transactionTime += transTime;
	tellerQueue.addEvent(now);
}

/*
 * Action 2 is used when there are multiple lines in the bank.
 * The first for-loop finds the teller with the smallest line
 * The second loop checks to see if there are other lines
 * with an equal number of customers. A random number is then
 * generated based on how many lines there are of smallest
 * amounts of customers and a for loop is run, adding the
 * customer to either one of the smallest teller lines.
 */

void Customer::Action2(){
	int min=0,numMin=0;

	for(int i=0;i<tellers;i++){
		if(tellerLines[min]>tellerLines[i])
			min=i;
	}

	for(int i=0;i<tellers;i++){
		if(tellerLines[min]==tellerLines[i])
			numMin++;
	}

	int randnum=rand()%numMin;

	for(int i=0;i<tellers;i++) {
			if(tellerLines[min]==tellerLines[i]){
				if(randnum==0){
					tellerLines[i]++;
					tellerQueues[i].addEvent(this);
					break;
				}
				randnum--;
			}
	}
}

/*
 * Returns a customers wait time
 */
int Customer::getTime(){
	return time;
}

/*
 * function generates a random time for a customer
 * and creates a customer arriving at that time.
 */
Event* Customer::add(){
	int newtime=rand()%simulationTime + 1;
	Event* cust=new Customer(newtime);
	return cust;
}
