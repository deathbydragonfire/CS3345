#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H
#include <string>
#include "book.h"
class AVLNode {
private:
	//data held by node
	book *theBook;
	//other node relationships
	AVLNode *parent = nullptr;
	AVLNode *leftChild = nullptr;
	AVLNode *rightChild = nullptr;
	//other data
	int height = -1000000000;	//-100000000 is a bad case, please assign
	int key;
public:
	//constructors
	AVLNode(int isbn, std::string t, std::string n)
	{
		key = isbn;
		theBook = new book(isbn, t, n);
	 /* Constructor for the root or when relationships should be assigned through code */}
	AVLNode(int isbn, std::string t, std::string n, AVLNode *p)
	{
		key = isbn;
		theBook = new book(isbn, t, n);
	parent = p; /* Constructor for when adding a node with a parent */}
	//destructor
	~AVLNode() {
		delete theBook;
	}
	//getters and setters
	book* getBook() {
		return theBook;
	}
			//no update allowed for internal data

	AVLNode* getParent() {
		return parent;
	}
	void setParent(AVLNode *newParent) {
		parent = newParent;
	}
	AVLNode* getRightChild() {
		return rightChild;
	}
	void setRightChild(AVLNode *newRightChild) {
		rightChild = newRightChild;
	}
	AVLNode* getLeftChild() {
		return leftChild;
	}
	void setLeftChild(AVLNode *newLeftChild) {
		leftChild = newLeftChild;
	}
	int getHeight() {
		return height;
	}
	void setHeight(int newHeight) {
		height = newHeight;
	}
};

class AVLTree {
private: 
	AVLNode *root = nullptr;
	void rebalance();
	void rotateRight(AVLNode *parent);
	void rotateLeft(AVLNode *parent);
public:
	void insertNode(int isbn, std::string t, std::string n);
	void deleteNode(int key);

};
#endif // AVLTREE_H
