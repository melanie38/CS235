#include "AVLTreeSet.h"
#include <fstream>

using namespace std;

// load command
void load(char* argv[], AVLTreeSet<string>& tree) {

	ifstream in;
	ofstream out;	
	string command, item;

	in.open(argv[1]);
	out.open(argv[2]);

	while (in >> command) {
		if (command == "add") {
			in >> item;
			//cout << "try to add " << item << endl;
			if (tree.find(item) == "false") {
				//cout << item << " is not found in the list" << endl;
				tree.add(item);
			}
			out << command << " " << item << endl;
		}
		else if (command == "find") {
			in >> item;
			out << command << " " << item << " " << tree.find(item) << endl;
		}
		else if (command == "clear") {
			tree.clear();
			out << command << endl;
		}
		else if (command == "print") {
			out << command << endl;
			out << tree.print();
		}
		else if (command == "remove") {
			in >> item;
			tree.remove(item);
			out << command << " " << item << endl;
		}
	}
	in.close();
	out.close();
}

int main(int argc, char* argv[]) {

	AVLTreeSet<string> tree;

	load(argv, tree);

	return (0);
}
