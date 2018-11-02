//main.cpp - kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <fstream>
#include "event.h"
#include "customer.h"
#include "teller.h"
using namespace std;

// customers and tellers store the amount of tellers and customers
// specified in terminal
int customers, tellers;

// int stores simulation time specified in terminal
int simulationTime;

// int avgTranTime keeps track of the average transaction time
int avgTranTime;

// totalTime keeps track of the time passed in the code.
int totalTime;

// idle time keeps track of how much time tellers spent being idle
int idleTime;

// timesIdle keeps track of the amount of times a teller went idle
int timesIdle;

// summation of random customer transaction times
int transactionTime;

// used to store pointers to teller lines
int* tellerLines;

// Teller tel is a default teller and Customer cust is a default customer
// Event* sampleTeller and Event* sampleCustomer use their location
// when creating other customer and Teller Objects
Teller tel;
Customer cust;
Event* sampleTeller = &tel;
Event* sampleCustomer = &cust;

// Event** allTellers and Event** allCustomers are pointers
// to pointers of Tellers and Customers
Event** allTellers;
Event** allCustomers;

// tellerQueue and tellerQueues are subclasses of the EventQueue
// that keep track of people in line for tellers
TellerQueue tellerQueue;
TellerQueue* tellerQueues;

//EventQueue is a queue that stores all the events
EventQueue *evntQueue;

/*
 * function goes through the simulation once with 1 line in the bank.
 * creates all the teller and customer objects and adds them to the
 * queue. The queue continues until it is empty. Then, all the objects are
 * deleted from the memory.
 */
void oneLine() {

	evntQueue = new EventQueue();
	allCustomers = new Event*[customers];
	allTellers = new Event*[tellers];
	for (int i = 0; i < customers; i++) {
		allCustomers[i] = sampleCustomer->add();
		evntQueue->aQueue.push(allCustomers[i]);
	}

	for (int i = 0; i < tellers; i++) {
		allTellers[i] = sampleTeller->add();
		evntQueue->aQueue.push(allTellers[i]);
	}

	while (!evntQueue->aQueue.empty()) {
		evntQueue->getEvent();
	}
	delete[] allCustomers;
	delete[] allTellers;
	delete evntQueue;
}

/*
 * function goes through the simulation again using multiple lines in the bank.
 * creates all the teller and customer objects and pushes them to the
 * queue. The queue continues until it is empty. Then, all the objects are
 * deleted from the memory.
 */

void multLines() {

	tellerQueues = new TellerQueue[tellers];
	evntQueue = new EventQueue();
	allCustomers = new Event*[customers];
	allTellers = new Event*[tellers];

	for (int i = 0; i < customers; i++) {
		allCustomers[i] = sampleCustomer->add();
		evntQueue->aQueue.push(allCustomers[i]);
	}

	for (int i = 0; i < tellers; i++) {
		allTellers[i] = sampleTeller->add();
		allTellers[i]->lineNumber = i;
		evntQueue->aQueue.push(allTellers[i]);
	}

	tellerLines = new int[tellers];

	for (int i = 0; i < tellers; i++)
		tellerLines[i] = 0;

	while (!evntQueue->aQueue.empty()) {
		evntQueue->getEvent2();
	}

	delete[] allCustomers;
	delete[] allTellers;
}


/*
 * print method prints all the statistics it has collected while running through the simulations
 * to a file opened/created in the main class.
 */
void print() {
	printf("The Average Transaction Time-                 %7.2f\n", double(transactionTime)
			/ double(customers));
	printf("Total Teller Idle Time                        %7d \n", idleTime);
	printf("Times Teller Idle                             %7d \n", timesIdle);
	printf("Average waiting time                          %7.2f \n", double(totalTime) / double(customers));
	printf("Total time                                    %7d \n", totalTime);

}

/*
 * main first checks the arguments provided to make sure there
 * are enough. It then sets up the seed, crates/opens a file to hold
 * the statistics, and runs the simulations once with only one line
 * and then again with multiple lines. Prints statistics once a
 * simulation is complete, clears the statistics and does the simulation
 * again.
 */
int main(int argc, char *argv[]) {
	if (argc < 5) {
		cout << "Too few command line arguments." << endl;
		return 1;
	}
	if (argc == 6) {
		int x = atoi(argv[5]);
		if (x >= 0)
			srand(atoi(argv[5]));
		else {
			cout << "Please enter a non-negative number for the seed" << endl;
			return 1;
		}
	}
	else
		srand(time(NULL));
	customers = atoi(argv[1]);
	tellers = atoi(argv[2]);
	simulationTime = atoi(argv[3]);
	avgTranTime = atoi(argv[4]);
	freopen("output", "w", stdout);

	cout << "Simulation with only one line" << endl << endl;

	oneLine();
	print();
	totalTime = idleTime = timesIdle = transactionTime = 0;
	cout << endl << endl;
	cout << "Simulation with a line for each teller" << endl << endl;
	multLines();
	print();
	return 0;
}

