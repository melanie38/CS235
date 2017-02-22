#pragma once
#include <sstream>
#include <fstream>

using namespace std;

template <typename ItemType>

class LinkedList {
private:
	struct Node {
		ItemType item;
		Node* next;
	    Node* prev;
		
		Node(ItemType in_item, Node* ptr_next = NULL, Node* ptr_prev = NULL):
			item(in_item), next(ptr_next), prev(ptr_prev) {}
	};

	Node* head = NULL;
	Node* tail = NULL;
	int size = 0;

public:
	
	~LinkedList() {
		clear();
	}
	
	Node* getNode(int index) {
	  Node* ptr;
	  
	  if (index <= size/2) {
	    ptr = head;
	    for (int i = 0; i < index; i++) {
	      ptr = ptr->next;
	    }
	  }
	  else {
	    ptr = tail;
	    for (int i = size-1; i > index; i--) {
	      ptr = ptr->prev;
	    }
	  }
	  return ptr;
	}
	void insert(const ItemType& item) {
		/* index not valid
		if (index < 0 || index > size) {
			return;
		}
		*/
		Node* temp;
		// creates the very first node
		if (size == 0) {
			head = new Node(item);
			tail = head;
			size++;
		}
		/* insert at the head
		else if (index == 0) {
			temp = new Node(item, head, NULL);
			head->prev = temp;
			head = temp;
			size++;
		}
		*/
		// insert at the tail
		else { //if (index == size) {
			temp = new Node(item, NULL, tail);
			tail->next = temp;
			tail = temp;
			size++;
		}
		/*else {
		 Node* ptr = getNode(index);
		        temp = new Node(item, ptr, ptr->prev);
			ptr->prev->next = temp;
			ptr->prev = temp;
			size++;
		}
		*/
		//out << "insert " << index << " " << item << endl;
	}
	
	int find(const ItemType& itemToFind) {
		int indexOfItem = 0;

		if (head != NULL) {
			Node* temp = head;
			while (temp != NULL) {
				if (temp->item != itemToFind) {
					temp = temp->next;
					indexOfItem++;
				}
				else {
					return indexOfItem;
				}
			}	
		}
		return -1;
	}
	ItemType remove(int index) {
    
		ItemType itemToDelete = NULL;
		Node* temp;

		if (head == NULL || index < 0 || index > size-1) return itemToDelete;
      	if (size == 1) {
			itemToDelete = head->item;
			delete head;
			head = NULL;
			tail = NULL;
			size = 0;
		}
		else if (index == 0) {
			temp = head;
			itemToDelete = temp->item;
			head = temp->next;
			head->prev = NULL;
			delete temp;
			//temp = NULL;
			size--;
		}
		else if (index == size-1) {
			temp = tail;
			itemToDelete = temp->item;
			tail = temp->prev;
			tail->next = NULL;
			delete temp;
			size--;
		}
		else {
			temp = getNode(index);
			itemToDelete = temp->item;					
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			//temp = NULL;
			size--;
		}
		return itemToDelete;
	}

	void clear() {
		while (size != 0) {
			remove(0);
		}
		//out << "clear" << endl;
	}
	
	int getSize() {
		return size;
	}
	
	string print() {
		stringstream ss;	
		Node* toPrint = head;
		
		ss << "print" << endl;

		for (int i = 0; i < size; i++) {
			ss << "node " << i << ": " << toPrint->item << endl;
			toPrint = toPrint->next;
		}
		return ss.str();
	}

	ItemType pop() {
		ItemType itemToPop = NULL;
		
		if (head == NULL) {
			return itemToPop;
		}

		itemToPop = head->item;
		remove(0);
		
		return itemToPop;
	}
};

