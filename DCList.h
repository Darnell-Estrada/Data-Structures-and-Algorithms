// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 4
// DCList.h

#ifndef DCLIST_H
#define DCLIST_H

#include <iostream>
#include <string>
using namespace std;

class DCList {
	private:
		struct Node {
			char C;
			Node *next,
				*prev;
		};
		Node *head,
			*tail,
			*curr;

	public:
		DCList();
		~DCList();
		int append(char);
		int insert(char);
		int remove(char);
		int next(char&);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		int length() const;
		void print() const;
		void reverse() const;
};

DCList::DCList() {
	head = tail = curr = NULL;
}

DCList::~DCList() {
	clear();
}

int DCList::append(char c) {
	Node *newPtr = NULL;

	if (isFull())
		return -1;
	else {
		newPtr = new Node;

		newPtr->C = c;
		newPtr->next = NULL;

		if (isEmpty()) {
			head = tail = newPtr;
			newPtr->next = newPtr->prev = newPtr;
			curr = head;
		}
		else {
			tail->next = newPtr;
			tail->next->prev = tail;
			tail = newPtr;
			tail->next = head;
			head->prev = tail;
		}

		return 0;
	}
}

int DCList::insert(char c) {
	Node *newPtr = NULL,
		*bhndPtr = NULL,
		*travPtr = NULL;

	if (isFull())
		return -1;
	else {
		newPtr = new Node;

		newPtr->C = c;
		newPtr->next = newPtr->prev = NULL;

		if (isEmpty()) {
			head = tail = newPtr;
			newPtr->next = newPtr->prev = newPtr;
			curr = head;
		}
		else {
			bhndPtr = NULL;
			travPtr = head;

			do {
				if (newPtr->C < head->C) {
					head = curr = newPtr;
					newPtr->next = travPtr;
					travPtr->prev = newPtr;
					newPtr->prev = tail;
					tail->next = head;

					return 0;
				}
				else {
					bhndPtr = travPtr;
					travPtr = travPtr->next;
				}
			} while (travPtr != head && travPtr->C < c);

			bhndPtr->next = newPtr;
			newPtr->prev = bhndPtr;
			newPtr->next = travPtr;
			travPtr->prev = newPtr;

			if (newPtr->next == head)
				tail = newPtr;
		}

		return 0;
	}
}

int DCList::remove(char c) {
	Node *bhndPtr = NULL,
		*travPtr = NULL;

	if (isEmpty())
		return -1;
	else {
		travPtr = head;

		do {
			if (head->C == c) {
				if (head == tail) {
					delete travPtr;
					head = tail = NULL;

					return 0;
				}

				travPtr = head->next;
				delete head;
				head = curr = travPtr;
				tail->next = head;
				head->prev = tail;

				return 0;
			}

			bhndPtr = travPtr;
			travPtr = travPtr->next;
		} while (travPtr != head && travPtr->C != c);

		if (travPtr == head)
			return -1;
		else if (travPtr == tail)
			tail = bhndPtr;

		bhndPtr->next = curr = travPtr->next;
		travPtr->next->prev = bhndPtr;
		delete travPtr;

		return 0;
	}
}

int DCList::next(char& c) {
	if (isEmpty())
		return -1;
	else {
		curr = curr->next;
		c = curr->C;
		cout << c << endl;
		return 0;
	}
}

void DCList::clear() {
	Node *travPtr = NULL;

	if (isEmpty())
		return;
	else {
		head->prev = tail->next = NULL;
		travPtr = head;

		while (travPtr) {
			travPtr = head->next;
			delete head;
			head = travPtr;
		}

		tail = head;
	}
}

bool DCList::isEmpty() const {
	return !head;
}

bool DCList::isFull() const {
	Node *temp = new Node;

	return !temp;
}

int DCList::length() const {
	int i = 0;
	Node *travPtr = NULL;

	if (isEmpty())
		return 0;
	else {
		travPtr = head;
		
		do {
			i++;
			travPtr = travPtr->next;
		} while (travPtr != head);

		return i;
	}
}

void DCList::print() const {
	Node *travPtr = NULL;

	if (isEmpty())
		cout << "The list is empty.";
	else {
		travPtr = head;
		
		do {
			cout << travPtr->C << " ";
			travPtr = travPtr->next;
		} while (travPtr != head);
	}
}

void DCList::reverse() const {
	Node *travPtr = NULL;

	if (isEmpty())
		return;
	else {
		travPtr = tail;

		do {
			cout << travPtr->C << " ";
			travPtr = travPtr->prev;
		} while (travPtr != tail);
	}
}

#endif DCLIST_H