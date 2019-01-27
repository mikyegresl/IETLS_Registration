#include "AVLTree.h"
#include <iostream>

//private functions

int AVLTree::max(int a, int b){
	if (a > b){ return a; }
	return b;
}

int AVLTree::height(Node* entry){
	if (entry == NULL){ return 0; }
	return entry->height;
}

Node* AVLTree::rotateRight(Node* entry){
	Node* entry_left = entry->left;
	Node* entry_left_right = entry_left->right;

	entry_left->right = entry;
	entry->left = entry_left_right;

	entry->height = max(height(entry->left), height(entry->right))+1;
	entry_left->height = max(height(entry_left->left), height(entry_left->right))+1;
	return entry_left;
}

Node* AVLTree::rotateLeft(Node* entry){
	Node* entry_right = entry->right;
	Node* entry_right_left = entry_right->left;

	entry_right->left = entry;
	entry->right = entry_right_left;

	entry->height = max(height(entry->left), height(entry->right))+1;
	entry_right->height = max(height(entry_right->left), height(entry_right->right))+1;
	return entry_right;
}

int AVLTree::getBalance(Node* entry){
	if (entry == NULL){ return 0; }
	return (height(entry->left) - height(entry->right));
}

Node* AVLTree::minValueEntry(Node* entry){
	Node* temp = entry;
	while (temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}
//INSERTION
Node* AVLTree::insertHelper(Node* _root, const int &key){
	if (_root == NULL){
		Node* newEntry = new Node(key);
		return newEntry;
	}

	if (key < _root->key){
		_root->left = insertHelper(_root->left, key);

	}
	else if (key > _root->key){

		_root->right = insertHelper(_root->right, key);

	}
	else{ throw AlreadyExistingKey(); }
	
	
	
	////

	_root->height = 1 + max(height(_root->left), height(_root->right));

	int checkBalance = getBalance(_root);

	//Left left Case
	if (checkBalance > 1 && key < _root->left->key){
		return rotateRight(_root);
	}

	//Right Right Case
	if (checkBalance< -1 && key > _root->right->key){
		return rotateLeft(_root);
	}

	// Left Right Case
	if (checkBalance > 1 && key > _root->left->key){
		_root->left = rotateLeft(_root->left);
		return rotateRight(_root);
	}
	// Right Left Case
		if (checkBalance < -1 && key < _root->right->key){
			_root->right = rotateRight(_root->right);
			return rotateLeft(_root);
	}
		
	
	return _root;

}


//ERASE

Node* AVLTree::eraseHelper(Node* _root, const int &key){

	if (_root == NULL){ throw NonexistingKey(); }

	if (key < _root->key){
		_root->left = eraseHelper(_root->left, key);
	}
	else if (key>_root->key){
		_root->right = eraseHelper(_root->right, key);
	}

	else{
		if ((_root->left == NULL) || (_root->right == NULL)){
			Node* temp;

			if (root->left == NULL){ temp = _root->right; }
			else { temp = _root->left; }

			if (temp ==NULL){
				temp = _root;
				_root = NULL;
		}
			else{
				*_root = *temp;
			}

			delete[] temp;
	}
	else{
			Node* temp = AVLTree::minValueEntry(_root->right);
			_root->key = temp->key;
			_root->right = eraseHelper(_root->right, temp->key);
		}

	}

	if (_root == NULL){ return _root; }

	//
	_root->height = 1 + max(height(_root->left), height(_root->right));

	//Get balance

	int checkBalance = AVLTree::getBalance(_root);

	//Left Left case
	if (checkBalance > 1 && getBalance(_root->left) >= 0){
		return rotateRight(_root);
	}

	//Left Right case
	if (checkBalance>1 && getBalance(_root->left) < 0){
		_root->left = rotateLeft(_root->left);
		return rotateRight(_root);
	}

	//Right Right case
	if (checkBalance < -1 && getBalance(_root->right) <= 0){
		return rotateLeft(_root);
	}

	//Right Left case
	if (checkBalance <-1 && getBalance(_root->right) > 0){
		_root->right = rotateRight(_root->right);
		return rotateLeft(_root);
	}

	return _root;
}

//Access

Node* AVLTree::accessHelper(Node* _root, const int& key){
	if (_root==NULL){
	 throw NonexistingKey();
	}
		if (key < _root->key){ _root = accessHelper(_root->left,key); }
		if (key > _root->key){ _root = accessHelper(_root->right,key); }
		
		return _root; 	
}

void AVLTree::inorderHelper(Node *_root)
{
	if (_root == NULL){ return; }

	AVLTree::inorderHelper(_root->left);
	std::cout << std::endl << _root->key;
	std::cout << " ---> Status: "; if (_root->occupied_places <= 255){ std::cout << "Available"; }
	else{ std::cout << "NOT Available"; }
	AVLTree::inorderHelper(_root->right);
}

//public functions

void AVLTree::insert(const int& key){	
	root = insertHelper(root, key);
}

void AVLTree::erase(const int& key){
	root = eraseHelper(root, key);
}

Node* AVLTree::access(const int& key){
	return accessHelper(root, key);
}

void AVLTree::inorder() { 
	AVLTree::inorderHelper(root); }
