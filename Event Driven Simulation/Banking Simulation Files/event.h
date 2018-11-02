//event.h - kmgumienny


#ifndef EVENT_H_
#define EVENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>

using namespace std;

/*
 * Event is an abstract class with virtual methods for
 * the subclasses Customer and Teller to use. int lineNumber
 * keeps track of which line of customers Action2 uses.
 */

class Event{
public:
	Event(){}
	int lineNumber;
	virtual Event* add (){
		return NULL;
	}
	virtual void Action (){}
	virtual int getTime (){
		return 0;
	}
	virtual int getIdle(){
		return 0;
	}
	virtual void Action2 (){}
	virtual void addTime (int trans_time){}
	virtual ~Event(){}
};

/*
 * Compares 2 events by looking using the GetTime method.
 */
struct compareEvents {
    bool operator()(Event *a, Event *b)
    {
        return (a->getTime()>b->getTime());
    }
};

/*
 * Event queue is a priority queue that adds events in certainZ
 * places based on the results of the compareEvents method.
 * Has methods that work on the queue such as removing events
 * adding events, and calling Action and Action  on
 */

class EventQueue{
public:
	std::priority_queue<Event *,std::vector<Event *>,compareEvents> aQueue;
	EventQueue(){}
	void remove();
	void addEvent(Event *a);
	void getEvent();
	void getEvent2();
	Event* getTop();
};


#endif /* EVENT_H_ */
