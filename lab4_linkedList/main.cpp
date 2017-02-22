#include <iostream>
#include "linkedList.h"
#include <fstream>

using namespace std;

// load command
void load(char* argv[], LinkedList<string>& list) {

	ifstream in;
	ofstream out;

	string command, item;
	int index = -1;

	in.open(argv[1]);
	out.open(argv[2]);

	while (in >> command) {

		if (command == "insert") {
			in >> index >> item;
			list.insert(index, item);
			out << command << " " << index << " " << item << endl;
		}
		else if (command == "clear") {
			list.clear();
			out << "clear" << endl;
		}
        else if (command == "remove") {
			in >> index;
            out << command << " " << index << " " << list.remove(index) << endl;
		}
		else if (command == "find") {
			in >> item;
            out << command << " " << item << " " << list.find(item) << endl;
		}	
		else if (command == "print") {
            out << list.print();
		}
	}
	in.close();
}

int main(int argc, char* argv[]) {

	LinkedList<string> list;

	load(argv, list);

	return (0);
}
