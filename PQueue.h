// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 6
// PQueue.h

#ifndef PQUEUE_H
#define PQUEUE_H

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class PQueue {
	private:
		int cap,
			length,
			*heap;

		void reheapup(int, int);
		void reheapdown(int, int);

	public:
		PQueue(int);
		~PQueue();
		bool isEmpty() const;
		bool isFull() const;
		int enqueue(int);
		int dequeue(int&);
		void clear();
};

void PQueue::reheapup(int top, int bot) {
	int parent = 0,
		temp = 0;

	while (top < bot) {
		parent = (bot - 1) / 2;
		
		if (heap[parent] < heap[bot]) {
			temp = heap[parent];
			heap[parent] = heap[bot];
			heap[bot] = temp;
		}
		else
			break;

		bot = parent;
	}
}

void PQueue::reheapdown(int top, int bot) {
	int left = 0,
		right = 0,
		big = 0,
		temp = 0;

	while (top < bot) {
		left = (2 * top) + 1;
		right = (2 * top) + 2;

		if (left > bot)
			return;
		else if (left == bot)
			big = left;
		else {
			if (heap[left] > heap[right])
				big = left;
			else
				big = right;
		}

		if (heap[top] < heap[big]) {
			temp = heap[top];
			heap[top] = heap[big];
			heap[big] = temp;
		}

		top = big;
	}
}

PQueue::PQueue(int c) {
	cap = c;
	heap = new int[cap];
	length = 0;
}

PQueue::~PQueue() {
	delete [] heap;
	heap = 0;
}

bool PQueue::isEmpty() const {
	return length == 0;
}

bool PQueue::isFull() const {
	return length == cap;
}

int PQueue::enqueue(int i) {
	if (isFull())
		return -1;
	else {
		heap[length] = i;
		length++;
		reheapup(0, length-1);
		
		return 0;
	}
}

int PQueue::dequeue(int& i) {
	if (isEmpty())
		return -1;
	else {
		i = heap[0];
		heap[0] = heap[length-1];
		length--;
		reheapdown(0, length - 1);
		
		return 0;
	}
}

void PQueue::clear() {
	length = 0;
}

#endif PQUEUE_H