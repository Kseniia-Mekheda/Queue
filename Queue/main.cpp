#include <iostream>
#include "queue.h"
using namespace std;

int main() {
	cout << "SIMPLE QUEUE: " << endl;
	Queue Q(3); 
	Q.addToQueue(10);
	Q.addToQueue(12);
	Q.addToQueue(4); 
	Q.addToQueue(9);
	cout << "Size of your queue: " << Q.checkSize() << endl;
	cout << "Your queue: " << endl;
	Q.display(); 
	cout << "Remove first in queue: " << Q.removeFromQueue() << endl;
	cout << "Is queue full: " << Q.isFull() << endl; 
	cout << "Does queue have at least one element: " << Q.isAny() << endl;
	cout << "See first item: " << Q.peek() << endl;

	cout << endl;
	cout << endl;

	cout << "PRIORITY QUEUE: " << endl;
	PriorityQueue P; 
	P.fillQueue(4, 12);
	P.fillQueue(5, 1);
	P.fillQueue(6, 8); 

	P.printOut();

	cout<< "Remove Item with value: " << P.removeItem() << endl;
	P.printOut();

	cout << "Is queue empty: " << P.noItems() << endl;
	return 0;
}