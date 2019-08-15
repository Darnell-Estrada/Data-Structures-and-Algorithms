// DARNELL JAMES V. ESTRADA
// CS 3240 SEC 02SP
// HOMEWORK 5
// Tree.h

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <string>
using namespace std;

class Tree {
	private:
		struct Node {
			string name,
				phone;
			Node *left,
				*right;
		};
		Node *root;

		int remove(Node*&, string);
		void clear(Node*);
		void insert(Node*&, string, string);
		void print(Node*) const;
		string find(Node*, string) const;

	public:
		Tree();
		~Tree();
		int remove(string);
		int insert(string, string);
		void clear();
		bool isEmpty() const;
		bool isFull() const;
		void print() const;
		string find(string) const;
};

int Tree::remove(Node*& r, string n) {
	Node *temp = NULL;

	if (!r)
		return -1;
	else if (n == r->name) {
		if (!r->left && !r->right) {
			delete r;
			r = NULL;
		}
		else if (!r->left) {
			temp = r;
			r = r->right;
			delete temp;
		}
		else if (!r->right) {
			temp = r;
			r = r->left;
			delete temp;
		}
		else {
			temp = r->right;

			while (temp->left)
				temp = temp->left;

			temp->left = r->left;
			temp = r;
			r = r->right;
			delete temp;
		}

		return 0;
	}
	else if (n < r->name)
		return remove(r->left, n);
	else
		return remove(r->right, n);
}

void Tree::clear(Node* r) {
	if (!r)
		return;
	else {
		clear(r->left);
		clear(r->right);
		delete r;
	}
}

void Tree::insert(Node*& r, string n, string p) {
	if (!r) {
		r = new Node;

		r->name = n;
		r->phone = p;
		r->left = r->right = NULL;

		return;
	}
	else if (n < r->name)
		insert(r->left, n, p);
	else
		insert(r->right, n, p);
}

void Tree::print(Node* r) const {
	if (!r)
		return;
	else {
		print(r->left);

		cout << r->name << "....."
			<< r->phone << endl;

		print(r->right);
	}
}

string Tree::find(Node* r, string n) const {
	if (!r)
		return "";
	else if (n == r->name)
		return r->phone;
	else if (n < r->name)
		return find(r->left, n);
	else
		return find(r->right, n);
}

Tree::Tree() {
	root = NULL;
}

Tree::~Tree() {
	clear();
}

int Tree::remove(string n) {
	return remove(root, n);
}

int Tree::insert(string n, string p) {
	if (isFull())
		return -1;
	else {
		insert(root, n, p);

		return 0;
	}
}

void Tree::clear() {
	clear(root);
	root = NULL;
}

bool Tree::isEmpty() const {
	return !root;
}

bool Tree::isFull() const {
	Node *temp = new Node;

	if (!temp) {
		delete temp;
		
		return true;
	}
	else {
		delete temp;
		
		return false;
	}
}

void Tree::print() const {
	if (isEmpty())
		cout << "The tree is empty.\n";
	else
		print(root);
}

string Tree::find(string n) const {
	if (find(root, n) == "")
		return "NOT FOUND";
	else
		return find(root, n);
}

#endif TREE_H