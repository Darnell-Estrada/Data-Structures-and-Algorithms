// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 8
// Graph.h

#ifndef GRAPH_H
#define GRAPH_H

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Graph {
	private:
		struct Vertex {
			bool mark;
		    string name;
		};
		bool **G;
		int size,
			length,
			span;
		Vertex popped,
			*V;

		void initialize();
		void clearMarks();
		void pop(Vertex*);
		void push(Vertex*, Vertex);
		bool isEmpty() const;
		bool isFull() const;
		int find(string) const;

	public:
		Graph();
		Graph(int);
		~Graph();
		void addVertex(string);
		void removeVertex(string);
		void addEdge(string, string);
		void removeEdge(string, string);
		void printPath(string, string);
		void test() const;
};

void Graph::initialize() {
	int i = 0,
		r = 0,
		c = 0;
	
	length = span = 0;
	V = new Vertex[size];
	G = new bool*[size];

	for (i = 0; i < size; i++)
		V[i].name = " ";

	for (r = 0; r < size; r++) {
		G[r] = new bool[size];

		for (c = 0; c < size; c++)
			G[r][c] = false;
	}
}

void Graph::clearMarks() {
	int i = 0;

	for (i = 0; i < size; i++)
		V[i].mark = false;
}

void Graph::pop(Vertex* A) {
	popped = A[span - 1];
	span--;
}

void Graph::push(Vertex* A, Vertex vertex) {
	span++;
	A[span - 1] = vertex;
}

bool Graph::isEmpty() const {
	return length == 0;
}

bool Graph::isFull() const {
	return length == size;
}

int Graph::find(string name) const {
	int i = 0;

	for (i = 0; i < length; i++)
		if (V[i].name == name)
			return i;

	return -1;
}

Graph::Graph() {
	size = 10;
	initialize();
	clearMarks();
}

Graph::Graph(int s) {
	size = s;
	initialize();
	clearMarks();
}

Graph::~Graph() {
	int r = 0;

	delete [] V;

	for (r = 0; r < size; r++)
		delete [] G[r];
	
	delete [] G;
}

void Graph::addVertex(string name) {
	if (isFull()) {
		cout << "Error: The graph is full\n";
		
		return;
	}

	length++;
	V[length - 1].name = name;
}

void Graph::removeVertex(string name) {
	int loc = find(name),
		i = 0,
		r = 0,
		c = 0,
		x = 0,
		y = 0;

	if (isEmpty()) {
		cout << "Error: The graph is empty\n";

		return;
	}
	else if (loc == -1) {
		cout << "Error: Your vertex is not in the graph\n";
		return;
	}
	else {
		for (i = loc; i < length - 1; i++)
			V[i] = V[i + 1];

		for (r = 0; r < length; r++)
			for (c = loc; c < length - 1; c++)
				G[r][c] = G[r][c + 1];

		for (c = 0; c < length; c++)
			for (r = loc; r < length - 1; r++)
				G[r][c] = G[r + 1][c];

		length--;
	}
}

void Graph::addEdge(string from, string to) {
	if (find(from) == -1 || find(to) == -1) {
		cout << "Error: At least one of your vertices is not in the graph\n";
		
		return;
	}

	G[find(from)][find(to)] = true;
}

void Graph::removeEdge(string from, string to) {
	if (find(from) == -1 || find(to) == -1) {
		cout << "Error: At least one of your vertices is not in the graph\n";

		return;
	}

	G[find(from)][find(to)] = false;
}

void Graph::printPath(string from, string to) {
	bool found = false;
	int i = 0,
		stretch = 0;
	Vertex *S = NULL,
		*P = NULL;

	if (find(from) == -1 || find(to) == -1)
		found = false;
	else if (from == to) {
		if (G[find(from)][find(to)]) {
			found = true;

			cout << from << " " << to;
		}
	}
	else {
		span = 0;
		S = new Vertex[size];
		P = new Vertex[size];

		clearMarks();

		push(S, V[find(from)]);

		while (span != 0) {
			pop(S);
			popped.mark = true;

			stretch++;
			P[stretch - 1] = popped;

			if (popped.name == to) {
				found = true;
				break;
			}

			for (i = 0; i < size; i++)
				if (G[find(popped.name)][i])
					push(S, V[i]);
		}

		if (P[stretch - 1].name != to)
			found = false;
		else {
			found = true;

			for (i = 0; i < size; i++)
				cout << P[i].name << " ";
		}
	}

	if (!found)
		cout << "NO PATH FOUND";
	else
		return;
}

void Graph::test() const {
	int r = 0,
		c = 0;

	if (isEmpty())
		return;
	else {
		cout << endl << "  ";

		for (c = 0; c < length; c++)
			cout << c;

		cout << "\n  ";

		for (r = 0; r < length; r++)
			cout << "_";

		cout << endl;

		for (r = 0; r < length; r++) {
			cout << r << "|";

			for (c = 0; c < length; c++)
				cout << G[r][c];

			cout << "| [" << r << "]: "
				<< V[r].name << ", " << V[r].mark << endl;
		}

		cout << "  ";

		for (c = 0; c < length; c++)
			cout << "-";

		cout << "\n\n";
	}
}

#endif GRAPH_H