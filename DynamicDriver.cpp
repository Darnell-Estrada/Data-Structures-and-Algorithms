// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 3
// DynamicDriver.cpp
// This program implements a dynamic linked list,
// using pop, push, enqueue, and dequeue functions.

#include "Dynamic.h"

void menu();

int main() {
	int num = 0;
	string sel = " ";
	Dynamic list;

	cout << "Dynamic Linked List\n";

	do {
		cout << "[ABCDEFGHIJKL]: ";
		cin >> sel;

		switch (sel[0]) {
			case 'A': case 'a': cout << "[CLEAR]\n";
				list.clear();
				cout << "The list is cleared.\n";
				break;
			case 'B': case 'b': cout << "[DEQUEUE]\n" << list.dequeue(num) << endl;
				break;
			case 'C': case 'c': cout << "[EMPTY?]\n" << list.isEmpty() << endl;
				break;
			case 'D': case 'd': cout << "[ENQUEUE]\nEnqueue an integer onto the queue: ";
				cin >> num;
				cout << list.enqueue(num) << endl;
				break;
			case 'E': case 'e': cout << "[FULL?]\n" << list.isFull() << endl;
				break;
			case 'F': case 'f': cout << "[LENGTH]\n" << list.length() << endl;
				break;
			case 'G': case 'g': cout << "[MENU]\n";
				menu();
				break;
			case 'H': case 'h': cout << "[PEEK]\n" << list.peek(num) << endl;
				break;
			case 'I': case 'i': cout << "[POP]\n" << list.pop(num) << endl;
				break;
			case 'J': case 'j': cout << "[PRINT]\n";
				list.print();
				cout << endl;
				break;
			case 'K': case 'k': cout << "[PUSH]\nPush an integer onto the stack: ";
				cin >> num;
				cout << list.push(num) << endl;
				break;
			case 'L': case 'l': cout << "[QUIT]\n";
				exit(0);
			default: cout << "Enter a valid menu option.\n";
				break;
		}
	} while (true);

	cin.ignore();
	cin.get();
	return 0;
}

void menu() {
	cout << "[A] CLEAR\n"
		"[B] DEQUEUE\n"
		"[C] EMPTY?\n"
		"[D] ENQUEUE\n"
		"[E] FULL?\n"
		"[F] LENGTH\n"
		"[G] MENU\n"
		"[H] PEEK\n"
		"[I] POP\n"
		"[J] PRINT\n"
		"[K] PUSH\n"
		"[L] QUIT\n";
}