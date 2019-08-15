// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 6
// PQueueDriver.cpp
// This program implements a priority queue.

#include "PQueue.h"

void menu();

int main() {
	int num = 0;
	string s = " ";

	cout << "Priority Queue (Heap)"
		<< "\nEnter a capacity: ";
	cin >> num;

	PQueue pq(num);

	do {
		cout << "[CDEFMQV]: ";
		cin >> s;

		switch (s[0]) {
			case 'C': case 'c': pq.clear();
				cout << "The queue is cleared.\n";
				break;
			case 'D': case 'd': cout << "Dequeue: The highest priority integer is dequeued\n";
				cout << pq.dequeue(num) << endl;
				break;
			case 'E': case 'e': cout << "Enqueue: Enter an integer to enqueue: ";
				cin >> num;
				cout << pq.enqueue(num) << endl;
				break;
			case 'F': case 'f': cout << "Full? " << pq.isFull() << endl;
				break;
			case 'M': case 'm': menu();
				break;
			case 'Q': case 'q': exit(0);
				break;
			case 'V': case 'v': cout << "Empty? " << pq.isEmpty() << endl;
				break;
			default: cout << "Error: An invalid menu option was entered\n";
				break;
		}
	} while (true);

	cin.ignore();
	cin.get();
	return 0;
}

void menu() {
	cout << "C: Clear\n"
		"D: Dequeue\n"
		"E: Enqueue\n"
		"F: Full?\n"
		"M: Menu\n"
		"Q: Quit\n"
		"V: Vacant?\n";
}