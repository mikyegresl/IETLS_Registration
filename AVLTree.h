#include "Node.h"
#include <iostream>
class AVLTree{
private:
	Node* root;
public:

	AVLTree(){ root = NULL; }
	void insert(const int &key);
	void erase(const int &key);
	Node* access(const int &key);
	void inorder();
	void preorder();
	Node* getRoot(){ return root; }
private:
	int max(int, int);
	Node* minValueEntry(Node*);
	int height(Node*);
	Node* rotateRight(Node*);
	Node* rotateLeft(Node*);
	int getBalance(Node*);
	Node* eraseHelper(Node* _root, const int &key);
	Node* insertHelper(Node* _root, const int &key);
	void inorderHelper(Node* _root);
	Node* accessHelper(Node* _root, const int &key);
};

class NonexistingKey : public runtime_error {
public:

	NonexistingKey()
		: runtime_error("Nonexisting Exam Date Accessed")
	{
		std::cerr << "Nonexisting Exam Date Accessed";
	}
};

class AlreadyExistingKey : public runtime_error {
public:

	AlreadyExistingKey()
		: runtime_error("The Date is Already Exist")
	{
		std::cerr << "The Date is Already Exist";
	}
};
