// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 1
// Students_driver.cpp
// This program implements a class.

#include "Students.h"

int main() {
	Students s(5);
	cout << "EMPTY? " << s.isEmpty()
		<< "\nFULL? " << s.isFull()
		<< "\n\nFRANK? " << s.find("Frank");
	s.print();
	cout << "\n\nINSERT\n"
		<< s.insert(3.5, 0, "Sarah") << endl
		<< s.insert(3.75, 1, "Tim") << endl
		<< s.insert(3.15, 4, "Masiha") << endl
		<< s.insert(1.75, 22, "Jake")
		<< "\n\nTim? " << s.find("Tim")
		<< "\nAlan? " << s.find("Alan")
		<< "\n\nPRINT\n";
	s.print();
	cout << "\nREMOVE ELEM 1: " << s.remove(1)
		<< "\nREMOVE ELEM 10: " << s.remove(10)
		<< "\n\nPRINT\n";
	s.print();
	cout << "\nTim? " << s.find("Tim")
		<< "\n\nEMPTY? " << s.isEmpty()
		<< "\nFULL? " << s.isFull()
		<< "\n\nINSERT\n"
		<< s.insert(1.59, 1, "John") << endl
		<< s.insert(4.00, 2, "Lisa") << endl
		<< s.insert(3.87, 3, "George")
		<< "\n\nEMPTY? " << s.isEmpty()
		<< "\nFULL? " << s.isFull()
		<< "\n\nPRINT\n";
	s.print();
	cout << "\nCLEAR";
	s.clear();
	cout << "\n\nEMPTY? " << s.isEmpty()
		<< "\nFULL? " << s.isFull()
		<< "\n\nPRINT\n";
	s.print();
	cin.ignore();
	cin.get();
	return 0;
}