// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 8
// GraphDriver.cpp
// This program implements graph theory.
// Printed cycles are not implemented.

#include "Graph.h"

void menu();
void subMenu();

int main() {
	int num = 0;
	string s = " ",
		from = " ",
		to = " ";

	cout << "Graph"
		<< "\nEnter the number of vertices: ";
	cin >> num;

	Graph g(num);

	do {
		cout << "[AMPQRT]: ";
		cin >> s;

		switch (s[0]) {
			case 'A': case 'a': {
				do {
					cout << "[BESV]: ";
					cin >> s;
					if (s[0] == 'B' || s[0] == 'b')
						break;
					switch (s[0]) {
						case 'E': case 'e': {
							cout << "Add Edge\nFrom: ";
							cin >> from;
							cout << "To: ";
							cin >> to;
							g.addEdge(from, to);
							break;
						}
						case 'S': case 's': {
							subMenu();
							break;
						}
						case 'V': case 'v': {
							cout << "Add a string as a vertex: ";
							cin >> s;
							g.addVertex(s);
							break;
						}
						default: {
							cout << "Error: An invalid submenu option was entered\n";
							break;
						}
					}
				} while (true);
				break;
			}
			case 'M': case 'm': {
				menu();
				break;
			}
			case 'P': case 'p': {
				cout << "Print a path\nFrom: ";
				cin >> from;
				cout << "To: ";
				cin >> to;
				g.printPath(from, to);
				cout << endl;
				break;
			}
			case 'Q': case 'q': {
				exit(0);
				break;
			}
			case 'R': case 'r': {
				do {
					cout << "[BESV]: ";
					cin >> s;
					if (s[0] == 'B' || s[0] == 'b')
						break;
					switch (s[0]) {
						case 'E': case 'e': {
							cout << "Remove Edge\nFrom: ";
							cin >> from;
							cout << "To: ";
							cin >> to;
							g.removeEdge(from, to);
							break;
						}
						case 'S': case 's': {
							subMenu();
							break;
						}
						case 'V': case 'v': {
							cout << "Remove a string as a vertex: ";
							cin >> s;
							g.removeVertex(s);
							break;
						}
						default: {
							cout << "Error: An invalid submenu option was entered\n";
							break;
						}
					}
				} while (true);
				break;
			}
			case 'T': case 't': {
				g.test();
				break;
			}
			default: {
				cout << "Error: An invalid menu option was entered\n";
				break;
			}
		}
	} while (true);

	cin.ignore();
	cin.get();
	return 0;
}

void menu() {
	cout << "A: Add\n"
		"M: Menu\n"
		"P: Print\n"
		"Q: Quit\n"
		"R: Remove\n"
		"T: Test\n";
}

void subMenu() {
	cout << "B: Back\n"
		"E: Edge\n"
		"S: Submenu\n"
		"V: Vertex\n";
}