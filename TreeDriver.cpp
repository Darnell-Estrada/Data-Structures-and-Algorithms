// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 5
// TreeDriver.h
// This program implements a binary tree.

#include "Tree.h"

void menu();

int main() {
	string s = " ",
		name = " ",
		phone = " ";
	Tree tree;

	cout << "Binary Tree\n";

	do {
		cout << "[CEFIMPQRS]: ";
		
		cin >> s;
		
		switch (s[0]) {
			case 'C': case 'c': tree.clear();
				cout << "The list is cleared.\n";
				break;
			case 'E': case 'e': cout << "Empty? " << tree.isEmpty() << endl;
				break;
			case 'F': case 'f': cout << "Full? " << tree.isFull() << endl;
				break;
			case 'I': case 'i': cout << "Insert a name: ";
				cin >> name;
				cout << "Enter a phone number: ";
				cin >> phone;
				tree.insert(name, phone);
				break;
			case 'M': case 'm': menu();
				break;
			case 'P': case 'p': tree.print();
				break;
			case 'Q': case 'q': exit(0);
				break;
			case 'R': case 'r': cout << "Enter a name to remove: ";
				cin >> name;
				cout << tree.remove(name) << endl;
				break;
			case 'S': case 's': cout << "Enter a name to search: ";
				cin >> name;
				cout << tree.find(name) << endl;
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
		"E: Empty?\n"
		"F: Full?\n"
		"I: Insert\n"
		"M: Menu\n"
		"P: Print\n"
		"Q: Quit\n"
		"R: Remove\n"
		"S: Search\n";
}