// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 7
// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"

class HashTable {
	private:
		int size;
		List *table;

		int hash(string) const;

	public:
		HashTable(int);
		~HashTable();
		int insert(string);
		int remove(string);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		bool find(string) const;
		void print() const;
};

int HashTable::hash(string key) const {
	int sum = 0;
	unsigned int i = 0;

	for (i = 0; i < key.size(); i++)
		sum += int(key[i]);

	return sum % size;
}

HashTable::HashTable(int s) {
	size = s;
	table = new List[size];
}

HashTable::~HashTable() {
	clear();
	delete[] table;
	table = 0;
}

int HashTable::insert(string key) {
	if (isFull())
		return -1;
	else
		return table[hash(key)].append(key);
}

int HashTable::remove(string key) {
	if (isEmpty())
		return -1;
	else
		return table[hash(key)].remove(key);
}

void HashTable::clear() {
	int i = 0;

	if (isEmpty())
		return;
	else
		for (i = 0; i < size; i++)
			table[i].clear();
}

bool HashTable::isEmpty() const {
	int i = 0;

	for (i = 0; i < size; i++)
		if (!table[i].isEmpty())
			return false;

	return true;
}

bool HashTable::isFull() const {
	return table[0].isFull();
}

bool HashTable::find(string key) const {
	if (isEmpty())
		return false;
	else {
		if (table[hash(key)].find(key) == 0)
			return true;
		else
			return false;
	}
}

void HashTable::print() const {
	int i = 0;

	for (i = 0; i < size; i++) {
		cout << "Bucket " << i << ": ";
		table[i].print();
		cout << endl;
	}
}

#endif HASHTABLE_H