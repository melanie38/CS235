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

	Node* head;
	Node* tail;
	int size;

public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
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

	void remove(int index) {
    
		//string itemToDelete = "";

		if (head == NULL || index < 0 || index > size - 1) return;
     
		Node* temp;

/*		while (temp->item != item) {
			temp = temp->next;
			if (temp->next == NULL) return;
		}
		
		if (temp == head) {
			if (size == 1) {
				delete head;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = temp->next;
				head->prev = NULL;
				delete temp;
				size--;
			}
		}
		else if (temp == tail) {
			tail = temp->prev;
			tail->next = NULL;
			delete temp;
			size--;
		}
		else {
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			size--;
		}
*/
		if (size == 1) {
			//itemToDelete = head->item;
			delete head;
			head = NULL;
			tail = NULL;
			size = 0;
		}
/*		else if (index == 0) {
			temp = head;
			//itemToDelete = temp->item;
			head = temp->next;
			head->prev = NULL;
			delete temp;
			//temp = NULL;
			size--;
		}
*/
		else if (index == size-1) {
			temp = tail;
			//itemToDelete = temp->item;
			tail = temp->prev;
			tail->next = NULL;
			delete temp;
			size--;
		}
		else if (index == 0) {
			temp = head;
			head = temp->next;
			head->prev = NULL;
			delete temp;
			size--;
		}
		else {
			temp = getNode(index);
			//itemToDelete = temp->item;					
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			//temp = NULL;
			size--;
		}
		return;
	}

	void clear() {
		while (size > 0) {
			remove(0);
		}
		//out << "clear" << endl;
	}
	
	int getSize() {
		return size;
	}
	
	string print(int n) {
		stringstream ss;
		int printed = 0;
		Node* toPrint = head;

		ss << "hash " << n << ":";

		for (int i = 0; i < size; i++) {
			if (printed == 8) {
				ss << endl << "hash " << n << ":";
				printed = 0;
			}
			ss << " " << toPrint->item;
			toPrint = toPrint->next;
			printed++;
		}
		//ss << endl;
		return ss.str();
	}

	ItemType pop() {
		
		string itemToPop = "";

		if (head == NULL) {
			return itemToPop;
		}
	
		itemToPop = head->item;	
		remove(0);
	
		return itemToPop;
	}
};

