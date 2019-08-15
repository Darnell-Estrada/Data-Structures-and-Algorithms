// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 7
// HashDriver.cpp

#include "HashTable.h"

void menu();

int main() {
	int num;
	string s;

	cout << "Hash Table"
		<< "\nEnter a capacity: ";
	cin >> num;

	HashTable ht(num);

	do {
		cout << "[CEFIMPQRS]: ";
		cin >> s;

		switch (s[0]) {
			case 'C': case 'c': ht.clear();
				cout << "The table is cleared.\n";
				break;
			case 'E': case 'e': cout << "Empty? " << ht.isEmpty() << endl;
				break;
			case 'F': case 'f': cout << "Full? " << ht.isFull() << endl;
				break;
			case 'I': case 'i': cout << "Enter a string to insert: ";
				cin >> s;
				cout << ht.insert(s) << endl;
				break;
			case 'M': case 'm': menu();
				break;
			case 'P': case 'p': ht.print();
				break;
			case 'Q': case 'q': exit(0);
				break;
			case 'R': case 'r': cout << "Enter a string to remove: ";
				cin >> s;
				cout << ht.remove(s) << endl;
				break;
			case 'S': case 's': cout << "Enter a string to search: ";
				cin >> s;
				cout << ht.find(s) << endl;
				break;
			default: cout << "Error: You entered an invalid menu option\n";
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