#include <fstream>
#include <iostream>
#include "HashSet.h"

using namespace std;

//template <typename ItemType>

void load(char* argv[], HashSet<string>& set) {

	ifstream in;
	ofstream out;
	string command, item;

	in.open(argv[1]);
	out.open(argv[2]);

	while (in >> command) {
		if (command == "add") {
			in >> item;
			if (set.find(item) == "false") {
				set.add(item);
			}
			out << command << " " << item << endl;
		}
		else if (command == "find") {
			in >> item;
			out << command << " " << item << " " <<  set.find(item) << endl;
		}
		else if (command == "clear") {
			set.clear();
			out << "clear" << endl;
		}
		else if (command == "print") {
			out << command << endl;
			out << set.print();
		}
		else if (command == "remove") {
			in >> item;
			set.remove(item);
			out << command << " " << item << endl;
		}
	}
	in.close();
	out.close();
}

int main(int argc, char* argv[]) {
	
	HashSet<string> set;

	load(argv, set);

	return(0);
}	
