// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 7 (HOMEWORK 2 MODIFIED)
// List.h

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
using namespace std;

class List {
	private:
		struct Node {
			string s;
			Node *next;
		};
		Node *head;

	public:
		List();
		~List();
		int append(string);
		int insert(string);
		int remove(string);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		int getLength() const;
		int find(string) const;
		int peek(string&) const;
		void print() const;
};

List::List() {
	head = NULL;
}

List::~List() {
	clear();
}

int List::append(string s) {
	Node *newPtr = NULL,
		*currPtr = NULL;

	if (isFull())
		return -1;
	else {
		newPtr = new Node;

		newPtr->s = s;
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

int List::insert(string s) {
	Node *newPtr = NULL,
		*prevPtr = NULL,
		*currPtr = NULL;

	if (isFull())
		return -1;
	else {
		newPtr = new Node;

		newPtr->s = s;
		newPtr->next = NULL;

		if (!head)
			head = newPtr;
		else {
			currPtr = head;

			while (currPtr && currPtr->s < s) {
				prevPtr = currPtr;
				currPtr = currPtr->next;
			}

			if (!prevPtr) {
				head = newPtr;
				newPtr->next = currPtr;
			}
			else {
				prevPtr->next = newPtr;
				newPtr->next = currPtr;
			}
		}

		return 0;
	}
}

int List::remove(string s) {
	Node *currPtr = NULL,
		*prevPtr = NULL;

	if (isEmpty())
		return -1;
	else {
		if (head->s == s) {
			currPtr = head->next;
			delete head;
			head = currPtr;
		}
		else {
			currPtr = head;

			while (currPtr && currPtr->s != s) {
				prevPtr = currPtr;
				currPtr = currPtr->next;
			}

			if (!currPtr)
				return -1;
			else {
				prevPtr->next = currPtr->next;
				delete currPtr;
			}
		}

		return 0;
	}
}

void List::clear() {
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

bool List::isEmpty() const {
	return !head;
}

bool List::isFull() const {
	Node *tempPtr = new Node;

	if (tempPtr) {
		delete tempPtr;

		return false;
	}
	else
		return true;
}

int List::getLength() const {
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

int List::find(string s) const {
	int temp = 0;
	Node *currPtr = head;

	while (currPtr) {
		if (currPtr->s == s)
			return 0;

		currPtr = currPtr->next;
		temp++;
	}

	return -1;
}

int List::peek(string& s) const {
	if (isEmpty())
		return -1;
	else {
		s = head->s;

		return 0;
	}
}

void List::print() const {
	Node *currPtr = head;

	if (isEmpty())
		return;
	else {
		while (currPtr) {
			cout << currPtr->s << " ";
			currPtr = currPtr->next;
		}
	}
}

#endif LIST_H