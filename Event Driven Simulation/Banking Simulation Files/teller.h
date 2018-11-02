//teller.h - kmgumienny

#ifndef TELLER_H_s
#define TELLER_H_

#include "event.h"

/*
 * Teller is a subclass of the Event class.
 */

class Teller: public Event {
private:
	int idleTime;
	int time;
public:
	Teller(){}
	Teller(int timeIdle) {
		time = 0;
		idleTime = timeIdle;
	}
	void Transaction(int line_number);
	void Action();
	void Action2();
	void addTime(int trans_time);
	int getIdle();
	int getTime();
	Event* add();
	virtual ~Teller() {}
};


/*
 * TellerQueue is a subclass of the EventQueue.
 */

class TellerQueue: public EventQueue {
public:
	TellerQueue() {}
};

#endif /* TELLER_H_ */
