// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 3
// Dynamic.h

#ifndef DYNAMIC_H
#define DYNAMIC_H

#include <iostream>
#include <string>
using namespace std;

class Dynamic {
	private:
		struct Node {
			int value;
			Node *next;
		};
		Node *head;

	public:
		Dynamic();
		~Dynamic();
		void clear();
		int push(int);
		int enqueue(int);
		int pop(int&);
		int dequeue(int&);
		bool isEmpty() const;
		bool isFull() const;
		int length() const;
		int peek(int&) const;
		void print() const;
};

Dynamic::Dynamic() {
	head = NULL;
}

Dynamic::~Dynamic() {
	clear();
}

void Dynamic::clear() {
	Node *currPtr = NULL;

	if (isEmpty())
		return;
	else {
		while (head) {
			currPtr = head;
			head = head->next;
			delete currPtr;
		}
	}
}

int Dynamic::push(int i)  {
	Node *newPtr = NULL;

	if (isFull())
		return -1;
	else {
		newPtr = new Node;

		newPtr->value = i;
		newPtr->next = NULL;

		if (isEmpty())
			head = newPtr;
		else {
			newPtr->next = head;
			head = newPtr;
		}

		return 0;
	}
}

int Dynamic::enqueue(int i) {
	Node *newPtr = NULL,
		*currPtr = NULL;

	if (isFull())
		return -1;
	else {
		newPtr = new Node;

		newPtr->value = i;
		newPtr->next = NULL;

		if (!head)
			head = newPtr;
		else {
			currPtr = head;

			while (currPtr->next)
				currPtr = currPtr->next;
			currPtr->next = newPtr;
		}

		return 0;
	}
}

int Dynamic::pop(int& i) {
	Node *endPtr = NULL;

	if (isEmpty())
		return -1;
	else {
		i = head->value;
		endPtr = head->next;
		delete head;
		head = endPtr;

		return 0;
	}
}

int Dynamic::dequeue(int& i) {
	Node *frontPtr = NULL;

	if (isEmpty())
		return -1;
	else {
		i = head->value;
		frontPtr = head->next;
		delete head;
		head = frontPtr;
		return 0;
	}
}

bool Dynamic::isEmpty() const {
	return !head;
}

bool Dynamic::isFull() const {
	Node *temp = new Node;

	return !temp;
}

int Dynamic::length() const {
	int count = 0;
	Node *currPtr = NULL;

	if (isEmpty())
		return 0;
	else {
		currPtr = head;

		while (currPtr) {
			count++;
			currPtr = currPtr->next;
		}

		return count;
	}
}

int Dynamic::peek(int& i) const {
	if (isEmpty())
		return -1;
	else {
		i = head->value;

		return 0;
	}
}

void Dynamic::print() const {
	Node *nodePtr = head;

	if (isEmpty())
		cout << "The list is empty.";
	else {
		while (nodePtr) {
			cout << nodePtr->value << " ";
			nodePtr = nodePtr->next;
		}
	}
}

#endif DYNAMIC_H