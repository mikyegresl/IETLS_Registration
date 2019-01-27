#include "Examinee.h"
class Node{
	public: // public functions
		Node(int key)
		{
			this->key = key;
			this->left = NULL;
			this->right =  NULL;
			this->height = 1;
		}
		Examinee* examinees;
		int key;
		int height;
		Node *left, *right;
		short occupied_places = 0;

	};


