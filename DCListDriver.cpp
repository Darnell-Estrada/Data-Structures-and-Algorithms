// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 4
// DCListDriver.cpp
// This program implements a doubly-circular linked list.

#include "DCList.h"

void menu();

int main() {
	char ch = ' ';
	string s = " ";
	DCList list;

	cout << "Doubly Circular Linked List\n";

	do {
		cout << "[ACDEFILMNPQR]: ";
		cin >> s;

		switch (s[0]) {
			case 'A': case 'a': cout << "Enter a character to append to the list: ";
				cin >> ch;
				cout << list.append(ch) << endl;
				break;
			case 'C': case 'c': list.clear();
				cout << "The list is cleared.\n";
				break;
			case 'D': case 'd': cout << "Enter a character to delete from the list: ";
				cin >> ch;
				cout << list.remove(ch) << endl;
				break;
			case 'E': case 'e': cout << "Empty? " << list.isEmpty() << endl;
				break;
			case 'F': case 'f': cout << "Full? " << list.isFull() << endl;
				break;
			case 'I': case 'i': cout << "Enter a character to insert to the list: ";
				cin >> ch;
				cout << list.insert(ch) << endl;
				break;
			case 'L': case 'l': cout << "Length: " << list.length() << endl;
				break;
			case 'M': case 'm': menu();
				break;
			case 'N': case 'n': cout << "Next: ";
				cout << list.next(ch) << endl;
				break;
			case 'P': case 'p': list.print();
				cout << endl;
				break;
			case 'Q': case 'q': exit(0);
				break;
			case 'R': case 'r': list.reverse();
				cout << endl;
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
	cout << "A: Append\n"
		"C: Clear\n"
		"D: Delete\n"
		"E: Empty?\n"
		"F: Full?\n"
		"I: Insert\n"
		"L: Length\n"
		"M: Menu\n"
		"N: Next\n"
		"P: Print\n"
		"Q: Quit\n"
		"R: Reverse\n";
}