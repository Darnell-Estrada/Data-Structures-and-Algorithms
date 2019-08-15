// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 1
// Students.h

#ifndef STUDENTS_H
#define STUDENTS_H

#include <iomanip>
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::setw;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

class Students {
	private:
		struct Student {
			bool used;
			double gpa;
			string name;
		};
	int cap;
	Student *s;
	public:
		Students(int);
		~Students();
		int remove(int);
		int insert(double, int, string);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		bool find(string) const;
		void print() const;
};

Students::Students(int c) {
	int i = 0;
	cap = c;
	s = new Student[c];
	for (i = 0; i < c; i++) {
		s[i].used = false;
	}
}

Students::~Students() {
	delete[] s;
	s = 0;
}

int Students::remove(int i) {
	if (i < 0 || cap <= i) {
		return -1;
	}
	else {
		s[i].used = false;
		return 0;
	}
}

int Students::insert(double gpa, int i, string name) {
	if (i < 0 || cap <= i) {
		return -1;
	}
	else {
		s[i].used = true;
		s[i].gpa = gpa;
		s[i].name = name;
		return 0;
	}
}

void Students::clear() {
	int i = 0;
	for (i = 0; i < cap; i++) {
		s[i].used = false;
	}
}

bool Students::isEmpty() const {
	int i = 0;
	for (i = 0; i < cap; i++) {
		if (s[i].used) {
			return false;
		}
	}
	return true;
}

bool Students::isFull() const {
	int i = 0;
	for (i = 0; i < cap; i++) {
		if (!s[i].used) {
			return false;
		}
	}
	return true;
}

bool Students::find(string name) const {
	int i = 0;
	for (i = 0; i < cap; i++) {
		if (s[i].name == name && s[i].used) {
			return true;
		}
	}
	return false;
}

void Students::print() const {
	int i = 0;
	for (i = 0; i < cap; i++) {
		if (s[i].used) {
			cout << left << "Name: " << setw(7) << right
				<< s[i].name << setw(7) << right << " GPA: "
				<< fixed << setprecision(2) << s[i].gpa << endl;
		}
	}
}

#endif STUDENTS_H