// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 2
// DynamicList.h

#ifndef DYNAMICLIST_H
#define DYNAMICLIST_H

#include <iostream>
#include <string>
using namespace std;

class DynamicList {
	private:
		struct Node {
			int i;
			Node *next;
		};
		Node *head;
	public:
		DynamicList();
		~DynamicList();
		int append(int);
		int insert(int);
		int remove(int);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		int getLength() const;
		int find(int) const;
		int peek(int&) const;
		void print() const;
};

DynamicList::DynamicList() {
	head = NULL;
}

DynamicList::~DynamicList() {
	clear();
}

int DynamicList::append(int i) {
	Node *newPtr = NULL,
		*currPtr = NULL;

	if (isFull()) {
		return -1;
	}
	else {
		newPtr = new Node;
		newPtr->i = i;
		newPtr->next = NULL;
		if (!head) {
			head = newPtr;
		}
		else {
			currPtr = head;
			while (currPtr->next) {
				currPtr = currPtr->next;
			}
			currPtr->next = newPtr;
		}
		return 0;
	}
}

int DynamicList::insert(int i) {
	Node *newPtr = NULL,
		*prevPtr = NULL,
		*currPtr = NULL;
	if (isFull()) {
		return -1;
	}
	else {
		newPtr = new Node;
		newPtr->i = i;
		newPtr->next = NULL;
		if (!head) {
			head = newPtr;
		}
		else {
			currPtr = head;	
			while (currPtr && currPtr->i < i) {
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

int DynamicList::remove(int i) {
	Node *currPtr = NULL,
		*prevPtr = NULL;
	if (isEmpty()) {
		return -1;
	}
	else {
		if (head->i == i) {
			currPtr = head->next;
			delete head;
			head = currPtr;
		}
		else {
			currPtr = head;
			while (currPtr && currPtr->i != i) {
				prevPtr = currPtr;
				currPtr = currPtr->next;
			}
			if (!currPtr) {
				return -1;
			}
			else {
				prevPtr->next = currPtr->next;
				delete currPtr;
			}
		}
		return 0;
	}
}

void DynamicList::clear() {
	Node *currPtr = NULL;
	if (isEmpty()) {
		return;
	}
	else {
		while (head) {
			currPtr = head;
			head = head->next;
			delete currPtr;
		}
	}
}

bool DynamicList::isEmpty() const {
	return !head;
}

bool DynamicList::isFull() const {
	Node *tempPtr = new Node;
	if (tempPtr) {
		delete tempPtr;
		return false;
	}
	else {
		return true;
	}
}

int DynamicList::getLength() const {
	int count = 0;
	Node *currPtr = NULL;
	if (isEmpty()) {
		return 0;
	}
	else {
		currPtr = head;
		while (currPtr) {
			count++;
			currPtr = currPtr->next;
		}
		return count;
	}
}

int DynamicList::find(int i) const {
	int temp = 0;
	Node *currPtr = head;
	while (currPtr) {
		if (currPtr->i == i) {
			return temp;
		}
		currPtr = currPtr->next;
		temp++;
	}
	return -1;
}

int DynamicList::peek(int& i) const {
	if (isEmpty()) {
		return -1;
	}
	else {
		i = head->i;
		return 0;
	}
}

void DynamicList::print() const {
	Node *currPtr = head;
	if (isEmpty()) {
		cout << "The list is empty.";
	}
	else {
		while (currPtr) {
			cout << currPtr->i << " ";
			currPtr = currPtr->next;
		}
	}
}

#endif DYNAMICLIST_H