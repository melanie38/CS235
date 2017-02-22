#pragma once
#include "LinkedList.h"
#include <sstream>

using namespace std;

template <typename ItemType>

class HashSet {
private:
	LinkedList<ItemType>* table;
    int tableSize; // size of the set
	int numOfItem; // number of item in the set
	int index;

public:
    HashSet(){
		tableSize = 0;
		numOfItem = 0;
		index = 0;
		table = new LinkedList<ItemType>[tableSize];	
	}
	~HashSet() {
		delete[] table;
	}

	void hashCode(const string& item) {
		unsigned hashIndex = 0;
		for (unsigned int i = 0; i < item.size(); i++) {
			hashIndex *= 31;
			hashIndex += item[i];
		}
		index = hashIndex % tableSize;
	}

	void hashCode(const string& item, int new_tableSize) {
		unsigned hashIndex = 0;
		for (unsigned int i = 0; i < item.size(); i++) {
			hashIndex *= 31;
			hashIndex += item[i];
		}
		index = hashIndex % new_tableSize;
	}

	void reHash(int new_tableSize) {
		
		if (tableSize == 1 && tableSize > new_tableSize) {
			delete[] table;
			table = new LinkedList<ItemType>[new_tableSize];
			tableSize = new_tableSize;
		}
		else if (tableSize == 0) {
			delete[] table;
			table = new LinkedList<ItemType>[new_tableSize];
			tableSize = new_tableSize;
			//if (new_tableSize == 0) delete[] table;
		}
		else {
			LinkedList<ItemType>* temp = new LinkedList<ItemType>[new_tableSize];
		
			for (unsigned i = 0; i < tableSize; i++) {
				while (table[i].getSize() > 0) {
					string item = table[i].pop();
					//cout << "test" << endl;
					hashCode(item, new_tableSize);
					temp[index].insert(item);
				}
			}
			LinkedList<ItemType>* ptr = table;
			table = temp;
			delete[] ptr;
			//temp = ptr;
			//delete[] temp;
			tableSize = new_tableSize;
		}
		

	}
	
	void add(const ItemType& item) {
		if (numOfItem == tableSize) {
			int new_tableSize = tableSize * 2 + 1;
			reHash(new_tableSize);
		}
		//cout << tableSize << endl;
		hashCode(item);
		table[index].insert(item);
		numOfItem++;
		//if (numOfItem == tableSize) reHash();
	}

	void remove(const ItemType& item) {
		if (find(item) == "false") return;

		hashCode(item);
		int toRemove = table[index].find(item);
		table[index].remove(toRemove);
		numOfItem--;
	
		if (numOfItem == (tableSize-1) / 2) {
			int new_tableSize = (tableSize - 1) / 2; 
			reHash(new_tableSize);
		}
	}
	
	string find(const ItemType& item) {
		if (tableSize == 0) return "false";
		
		hashCode(item);
		if (table[index].find(item) != -1) return "true";
		else return "false";
	}

	void clear() {
		if (table == NULL) return;
		
		for (unsigned i = 0; i < tableSize; i++) {
			table[i].clear();
		}
		delete[] table;
		tableSize = 0;
		numOfItem = 0;
		table = new LinkedList<ItemType>[0];
		//table = NULL;
	}

	string print() {
		if (tableSize == 0) return "";
		//cout << tableSize << endl;
		stringstream ss;


		for (unsigned i = 0; i < tableSize; i++) {
			ss << table[i].print(i) << endl;
		}

		return ss.str();
	}
};

