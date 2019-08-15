// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 6
// AnotherDriver.cpp

#include "PQueue.h"

int main() {
	int i = 0,
		x = 0;
	PQueue pq(10);

	for (i = 0; i < 10; i++)
		pq.enqueue(rand() % 999);

	/////////////////////////////////////////////////////////////////
	// Values in the heap should be displayed in descending order. //
	/////////////////////////////////////////////////////////////////
	
	while (!pq.isEmpty()) {
		pq.dequeue(x);
		cout << x << " ";
	}

	cout << endl;

	cin.ignore();
	cin.get();
	return 0;
}