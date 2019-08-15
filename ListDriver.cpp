// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 2
// ListDriver.cpp
// This program implements a dynamic linked list.

#include "DynamicList.h"

void menu();

int main() {
	int num = 0;
	string s = " ";
	DynamicList list;
	cout << "Dynamic Linked List\n";
	do {
		cout << "[ACDEFILMPQRS]: ";
		cin >> s;
		switch (s[0]) {
			case 'A': case 'a': {
				cout << "Enter an integer to append to the list: ";
				cin >> num;
				cout << list.append(num) << endl;
				break;
			}
			case 'C': case 'c': {
				list.clear();
				cout << "The list is cleared.\n";
				break;
			}
			case 'D': case 'd': {
				list.print(); cout << endl;
				break;
			}
			case 'E': case 'e': {
				cout << "Empty? " << list.isEmpty() << endl;
				break;
			}
			case 'F': case 'f': {
				cout << "Full? " << list.isFull() << endl;
				break;
			}
			case 'I': case 'i': {
				cout << "Enter an integer to insert to the list: ";
				cin >> num;
				cout << list.insert(num) << endl;
				break;
			}
			case 'L': case 'l': {
				cout << "Length: " << list.getLength() << endl;
				break;
			}
			case 'M': case 'm': {
				menu();
				break;
			}
			case 'P': case 'p': {
				cout << "Peek: " << list.peek(num) << endl;
				break;
			}
			case 'Q': case 'q': {
				exit(0);
				break;
			}
			case 'R': case 'r': {
				cout << "Enter an integer to remove from the list: ";
				cin >> num;
				cout << list.remove(num) << endl;
				break;
			}
			case 'S': case 's': {
				cout << "Enter an integer to search for: ";
				cin >> num;
				cout << "Position: " << list.find(num) << endl;
				break;
			}
			default: {
				cout << "Error: You entered an invalid menu option\n";
				break;
			}
		}
	} while (true);
	cin.ignore();
	cin.get();
	return 0;
}

void menu() {
	cout << "A: Append\n"
		"C: Clear\n"
		"D: Display\n"
		"E: Empty?\n"
		"F: Full?\n"
		"I: Insert\n"
		"L: Length\n"
		"M: Menu\n"
		"P: Peek\n"
		"Q: Quit\n"
		"R: Remove\n"
		"S: Search\n";
}