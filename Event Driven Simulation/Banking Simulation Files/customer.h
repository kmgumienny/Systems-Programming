///customer.h - kmgumienny

#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include "event.h"

/*
 * Customer is a subclass of the Event class.
 */
class Customer: public Event{
private:
	int time;
public:
	Customer(){}
	Customer(int tme){
		time = tme;
	}
	void Action();
	void Action2();
	int getTime();
	Event* add();
	virtual ~Customer(){}
};


#endif /* CUSTOMER_H_ */
