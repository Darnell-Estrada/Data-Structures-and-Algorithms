// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 3
// Static.h

#ifndef STATIC_H
#define STATIC_H

#include <iostream>
#include <string>
using namespace std;

class Static {
	private:
		int cap,
			front,
			back,
			*head;

	public:
		Static(int);
		~Static();
		int push(int);
		int pop(int&);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		int length() const;
		int peek(int&) const;
		void print() const;
};

Static::Static(int c) {
	head = new int[c];
	cap = c;
	clear();
	length();
	back = -1;
}

Static::~Static() {
	delete [] head;
	head = 0;
}

int Static::push(int i) {
	if (isFull())
		return -1;
	else {
		front++;
		head[front] = i;

		return 0;
	}
}

int Static::pop(int& i) {
	if (isEmpty())
		return -1;
	else {
		i = head[front];
		front--;

		return 0;
	}
}

void Static::clear() {
	front = -1;
}

bool Static::isEmpty() const {
	return front == -1;
}

bool Static::isFull() const {
	return front == cap - 1;
}

int Static::length() const {
	int i = 0;

	while (i <= front)
		i++;

	return i;
}

int Static::peek(int& i) const {
	if (isEmpty())
		return false;
	else {
		i = head[0];

		return true;
	}
}

void Static::print() const {
	int i = 0;

	if (isEmpty())
		cout << "The list is empty.";
	else
		for (i = 0; i <= front; i++)
			cout << head[i] << " ";
}

#endif STATIC_H