Kamil Gumienny- kmgumienny

This project is a simulation of a banking system. There are variables that are randomly generating regarding queue time, the amount of tellers at any given point, and the amount of customers wishing to complete a transaction.

Global Variables:


int customers and int tellers store the amount of tellers and customers
specified in terminal

int stores simulation time specified in terminal

int totalTime keeps track of the time passed in the code.

int idleTime keeps track of how much time tellers spent being idle

int avgTranTime keeps track of the average transaction time

int timesIdle keeps track of the amount of times a teller went idle

int transationTime summation of random customer transaction times

int* tellerLines used to store pointers to teller lines

Teller tel is a default teller and Customer cust is a default customer
Event* sampleTeller and Event* sampleCustomer use their location
when creating other customer and Teller Objects

Event** allTellers and Event** allCustomers are pointers
to pointers of Tellers and Customers

TellerQueue tellerQueue and TellerQueue *tellerQueues are subclasses of the EventQueue
that keep track of people in line for tellers

EventQueue *evntQueue is a queue that stores all the events



main

* main first checks the arguments provided to make sure there
* are enough. It then sets up the seed, crates/opens a file to hold
* the statistics, and runs the simulations once with only one line
* and then again with multiple lines. Prints statistics once a
* simulation is complete, clears the statistics and does the simulation
* again.


oneLine

* function goes through the simulation once with 1 line in the bank.
* creates all the teller and customer objects and adds them to the
* queue. The queue continues until it is empty. Then, all the objects are
* deleted from the memory.

multLines

* function goes through the simulation again using multiple lines in the bank.
* creates all the teller and customer objects and puahes them to the
* queue. The queue continues until it is empty. Then, all the objects are
* deleted from the memory.


print

* print method prints all the statistics it has collected while running through the simulations
* to a file opened/created in the main class.


EventQueue::getEvent

* getEvent creates an event and takes the first thing from the
* queue an assigns it to the new event, running it through the action
* method. The queue then gets rid of that event. Used in single line.


EventQueue::getEvent2

* works exactly as getEvent but runs the item on top of the queue
* in Action2. This is used in multiple lines.


EventQueue::getTop

* take the first event in the queue and returns it.


EventQueue::remove()

* removes the first Event in the queue using pop


EventQueue::addEvent

* pushes an Event into the queue.


Customer::Action()


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


Customer::Action2


* Action 2 is used when there are multiple lines in the bank.
* The first for-loop finds the teller with the smallest line
* The second loop checks to see if there are other lines
* with an equal number of customers. A random number is then
* generated based on how many lines there are of smallest
* amounts of customers and a for loop is run, adding the
* customer to either one of the smallest teller lines.


Customer::getTime

* Returns a customers wait time


Customer::add

* function generates a random time for a customer
* and creates a customer arriving at that time.


Teller::Action()


* Used to add an Event to a Teller's queue based on
* their times.


Teller::Action2()


* The function first goes through tellerLines and checks
* if there are no people in the lines. If there are no
* people in the lines, the teller goes idle. Otherwise,
* the teller pulls people from the largest line. Then, the
* line gets sent to the Transation function.



Teller::Transaction

* the function creates an event and assigns the first Customer
* in the queue to it then deletes the Customer from the queue
* and updates the amount of people in the line. A transaction time
* is then generated, the statistics for time are updated, and the teller
* is put back into the event queue.




Teller::add

* method creates an Event object for a
* Teller and creates a random idle time from
* 1 to 600 seconds.








*************
The program is ran using ./qSim #customers #tellers simulationTime averageServiceTime and <seed>
seed is optional.

Customers and Tellers are subclasses of event that inherit the functions, but event itself is not an abstract class because it is used to take tellers and customers from the eventQueue.

A bank with a single queue is almost always better because in a system with multiple
lines, customers can end up waiting for tellers to come out of their idle state if no one is in the bank at a certain time, making the waiting time slightly longer.


I received a lot of help for this project, mostly from classmates but also using a multitude of online sources including runnable, chegg, cplusplus, stackoverflow, cprogramming, and the university of buffalo website. All the functions are explained in the code above function headers, if not in the README.
