// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 1
// Students_menu.cpp
// This program implements a class.

#include "Students.h"

void menu();

int main() {
	int num = 0;
	string sel = " ";
	cout << "Array\n"
		<< "Enter a number to construct an array: ";
	cin >> num;
	Students s(num);
	do {
		cout << "[CEFIMPQRS]: ";
		cin >> sel;
		switch (sel[0]) {
			case 'C': case 'c': {
				s.clear();
				cout << "The array is cleared.\n";
				break;
			}
			case 'E': case 'e': {
				cout << "EMPTY? " << s.isEmpty() << endl;
				break;
			}
			case 'F': case 'f': {
				cout << "FULL? " << s.isFull() << endl;
				break;
			}
			case 'I': case 'i': {
				double gpa;
				int num;
				string name;
				cout << "Enter an element number: ";
				cin >> num;
				cout << "Enter a name: ";
				cin >> name;
				cout << "Enter a GPA: ";
				cin >> gpa;
				cout << s.insert(gpa, num, name) << endl;
				break;
			}
			case 'M': case 'm': {
				menu();
				break;
			}
			case 'P': case 'p': {
				if (s.isEmpty()) {
					cout << "The list is empty.\n";
				}
				else {
					s.print();
				}
				break;
			}
			case 'Q': case 'q': {
				exit(0);
				break;
			}
			case 'R': case 'r': {
				int num;
				cout << "Enter an element number: ";
				cin >> num;
				cout << s.remove(num) << endl;
				break;
			}
			case 'S': case 's': {
				string name;
				cout << "Enter a name to search for: ";
				cin >> name;
				cout << s.find(name) << endl;
				break;
			}
			default: {
				cout << "Error: Invalid option entered\n";
				break;
			}
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