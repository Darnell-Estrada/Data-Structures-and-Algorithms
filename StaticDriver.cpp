// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 3
// StaticDriver.cpp
// This program implements a static linked list.

#include "Static.h"

void menu();

int main() {
	int num = 0;
	string sel = " ";

	cout << "Static Linked List"
		<< "\nEnter a capacity: ";
	cin >> num;

	Static list(num);

	do {
		cout << "[ABCDEFGHIJKL]: ";
		cin >> sel;

		switch (sel[0]) {
		case 'A': case 'a': cout << "[CLEAR]\n";
			list.clear();
			cout << "The list is cleared.\n";
			break;
		case 'B': case 'b': cout << "[EMPTY?]\n" << list.isEmpty() << endl;
			break;
		case 'C': case 'c': cout << "[FULL?]\n" << list.isFull() << endl;
			break;
		case 'D': case 'd': cout << "[LENGTH]\n" << list.length() << endl;
			break;
		case 'E': case 'e': cout << "[MENU]\n";
			menu();
			break;
		case 'F': case 'f': cout << "[PEEK]\n" << list.peek(num) << endl;
			break;
		case 'G': case 'g': cout << "[POP]\n" << list.pop(num) << endl;
			break;
		case 'H': case 'h': cout << "[PRINT]\n";
			list.print();
			cout << endl;
			break;
		case 'I': case 'i': cout << "[PUSH]\nPush an integer onto the stack: ";
			cin >> num;
			cout << list.push(num) << endl;
			break;
		case 'J': case 'j': cout << "[QUIT]\n";
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
		"[B] EMPTY?\n"
		"[C] FULL?\n"
		"[D] LENGTH\n"
		"[E] MENU\n"
		"[F] PEEK\n"
		"[G] POP\n"
		"[H] PRINT\n"
		"[I] PUSH\n"
		"[J] QUIT\n";
}