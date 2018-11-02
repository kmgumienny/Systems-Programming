//event.cpp - kmgumienny

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include "event.h"

/*
 * getEvent creates an event and takes the first thing from the
 * queue an assigns it to the new event, running it through the action
 * method. The queue then gets rid of that event. Used in single line.
 */
void EventQueue::getEvent(){
	Event *eTop=aQueue.top();
	aQueue.pop();
	eTop->Action();
}

/*
 * works exactly as getEvent but runs the item on top of the queue
 * in Action2. This is used in multiple lines.
 */
void EventQueue::getEvent2(){
	Event *eTop=aQueue.top();
	aQueue.pop();
	eTop->Action2();
}

/*
 * take the first event in the queue and returns it.
 */
Event* EventQueue::getTop(){
	return aQueue.top();
}

/*
 * removes the first Event in the queue
 */
void EventQueue::remove(){
	aQueue.pop();
}

/*
 * pushes an Event into the queue.
 */
void EventQueue::addEvent(Event *a){
	aQueue.push(a);
}
