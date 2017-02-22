#pragma once

#include <iostream>
#include <sstream>

#include "linkedList.h"

using namespace std;

template <typename ItemType>

class AVLTreeSet {
private:
	struct Node {
		ItemType item;
		int height;
		Node* left;
		Node* right;

		Node(ItemType in_item, int in_height):
			item(in_item), height(in_height) {
				left = NULL;
				right = NULL;
				}
	};

	Node* root = NULL;
	int itemInTree = 0;
	const int HEIGHT_LEAF = 1;

	int updateHeight(Node*& n) {
		if (n == NULL) return 0;
		if (getHeight(n->right) > getHeight(n->left)) {
			return getHeight(n->right) + 1;
		}
		else return getHeight(n->left) + 1;
	}

	int getHeight(Node*& n) {
		if (n == NULL) return 0;
		else return n->height;
	}

	void rotateRight(Node*& n) {
		Node* e = n->left;
		n->left = e->right;
		e->right = n;
		n->height = updateHeight(n);
		n = e;
	}

	void rotateLeft(Node*& n) {
		Node* e = n->right;
		n->right = e->left;
		e->left = n;
		n->height = updateHeight(n);
		n = e;
	}

	void balanceRight(Node*& n) {
		if (getHeight(n->left->right) > getHeight(n->left->left)) {
			rotateLeft(n->left);
		}
		rotateRight(n);
	}

	void balanceLeft(Node*& n) {
		if (getHeight(n->right->left) > getHeight(n->right->right)) {
			rotateRight(n->right);
		}
		rotateLeft(n);
	}

	void isBalanced(Node*& n) {
		if (n == NULL) return;

		if (getHeight(n->left) - getHeight(n->right) > 1) {
				balanceRight(n);
		}
		else if (getHeight(n->right) - getHeight(n->left) > 1) {
				balanceLeft(n);
		}
		n->height = updateHeight(n);
	}

	bool find(Node* n, const ItemType& itemToAdd) {
		if (n == NULL) {
			return false;
		}
		else if (itemToAdd < n->item) {
			return find(n->left, itemToAdd);
		}
		else if (itemToAdd > n->item) {
			return find(n->right, itemToAdd);
		}
		else {
			return true;
		}
	}

	void add(Node*& n, const ItemType& itemToAdd) {
		if (n == NULL) {
			n = new Node(itemToAdd, HEIGHT_LEAF);
			itemInTree++;
		}
		else if (itemToAdd < n->item) {
			//n->height += 1;
			add(n->left, itemToAdd);
		}
		else if (itemToAdd > n->item) {
			//n->height += 1;
			add(n->right, itemToAdd);
		}
		isBalanced(n);
	}

	void clear(Node*& n) {
		if (n != NULL) {
			clear(n->left);
			clear(n->right);
			delete n;
			n = NULL;
		}
	}

	string print(Node*& n) {
		if (n == NULL) return "";
		
		LinkedList<Node*> list;
		stringstream ss;
		Node* temp = NULL;
		string item;
		int height = 0;
		int level = 0;
		int printed = 0;

		list.insert(n);
		
		while (list.getSize() > 0) {
			
			ss << "level " << level << ":";
			
			int count = list.getSize();
			printed = 0;
		
			for (int i = 0; i < count; i++) {
				
				temp = list.pop();
				item = temp->item;
				height = temp->height;
	      		
	      		if (printed >= 8) {
					ss << endl << "level " << level << ":";
					printed = 0;
				}
				ss << " " << item << "(" << height << ")";
					
				printed++;

				if (temp->left != NULL) {
					list.insert(temp->left);
				}
				if (temp->right != NULL) {
					list.insert(temp->right);
				}
				
				
			}
			ss << endl;
			level++;
			
		}
		return ss.str();
	}
	
	Node* findMin(Node* n) {
		while (n->left != NULL) {
			n = n->left;
		}
		return n;
	}

	void remove(Node*& n, const ItemType& item) {
		if (n == NULL) {
			return;
		}
		
		if (item < n->item) {
			//n->height--;
			remove(n->left, item);
		}
		else if (item > n->item) {
			//n->height--;
			remove(n->right, item);
		}
		else if (n->left == NULL) {
			Node* temp = n;
			n = n->right;
			delete temp;
			itemInTree--;
		}
		else if (n->right == NULL) {
			Node* temp = n;
			n = n->left;
			delete temp;
			itemInTree--;
		}
		else {
			n->item = findMin(n->right)->item;
			remove(n->right, n->item);
		}
		isBalanced(n);
	}
	
public:
	
	~AVLTreeSet(){
		clear();
	}

	string find(const ItemType& itemToAdd) {
		if (find(root, itemToAdd)) return "true";
		else return "false";
	}

	void add(const ItemType& itemToAdd) {
		add(root, itemToAdd);
	}

	void clear() {
		clear(root);
	}

	string print() {
		return print(root);
	}

	void remove(const ItemType& item) {
		remove(root, item);
	}
};

