#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <ctype.h>
#include <map>
#include <list>

using namespace std;

// print a set
void printSet(set<string> dictionary) {
	for (set<string>::iterator i = dictionary.begin(); i != dictionary.end(); i++) {
		cout << *i << endl;
	}
}
// print a map
void printMap(char* argv[], map<string, list<int>> misspelled) {

  ofstream out;
  out.open(argv[3]);

	for (auto pair : misspelled) {
	  out << pair.first << ": ";
	  for (double d : pair.second) {
	    out << d << " ";
	  }
	  out << endl;
	}
}
// compare a word to the content of a dictionary
bool compare(string word, set<string> dictionary) {

  int count = 0;

  for (set<string>::iterator i = dictionary.begin(); i != dictionary.end(); i++) {
    if (word == *i) count++;
  }
  if (count == 0) return false;
  else return true;

}
// verify that the words in the document are in the dictionary
void checkSpell(string line, set<string> dictionary, map<string, list<int>>& misspelled, int lineNum, list<int> numOfLines) {
	stringstream ss(line);
	string word;

	while (ss >> word) {
	  if (!compare(word, dictionary)) {
	    misspelled[word].push_back(lineNum);  
	  }
	}
}
// verify that all the characters in the line are alphabetical
string check(string line) {
	stringstream ss(line);

	for (unsigned int i = 0; i < line.length(); i++) {
		if (!isalpha(line[i])) {
		  line[i] = ' ';
		}
		else if (isupper(line[i])) {
		  line[i] = tolower(line[i]);
	        }
	}
	return line;
}
// load a dictionary
void loadFiles(int argc, char* argv[], set<string>& dictionary, map<string, list<int>>& misspelled, list<int>& numOfLines) {
	
	ifstream in;
	string line;
	int lineNum = 1;

	for (int i = 1; i < argc; i++) {
		if (i == 1) {
		  in.open(argv[i]);
		  while (getline(in, line)) {
		    dictionary.insert(check(line));
		  }
		  in.close();
		}
		if (i == 2) {
		  in.open(argv[i]);
		  while (getline(in, line)) {
		    checkSpell(check(line), dictionary, misspelled, lineNum, numOfLines);
		    lineNum++;
		  }
			in.close();
		}
	}
}

int main(int argc, char* argv[]) {

	set<string> dictionary;
	map<string, list<int>> misspelled;
	list<int> numOfLines;

	loadFiles(argc, argv, dictionary, misspelled, numOfLines);
	//	printSet(dictionary);
	printMap(argv, misspelled);

	return(0);
}
