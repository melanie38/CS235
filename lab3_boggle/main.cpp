#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <set>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

// print a vector
void printVector(vector<string>& myVector) {
	for (unsigned int i = 0; i < myVector.size(); i++) {
		cout << myVector[i] << " ";
	}
	cout << endl;
}
// print dictionary
void printDic(char* argv[],set<string>& dictionary, ofstream& out) {

	for (set<string>::iterator i = dictionary.begin(); i != dictionary.end(); i++) {
		out << *i << endl;
	}
//	out.close();
}
// print board
void printBoard (char* argv[], vector<vector<string>>& board, ofstream& out) {

	for (unsigned int r = 0; r < board.size(); r++) {
		for (unsigned int c = 0; c < board[r].size(); c++) {
			out << board[r][c] << " ";
		}
		out << endl;
	}
	out << endl;
	//out.close();
}
// convert uppercase to lower cases
string check(string line) {
	stringstream ss(line);

	for (unsigned int i = 0; i < line.length(); i++) {
		if (isupper(line[i])) {
		line[i] = tolower(line[i]);
		}
	}

	return line;
}
// Load files
void loadFiles(int argc, char* argv[], set<string>& dictionary, vector<string>& temp) {

	ifstream in;
	string line, letter;

	for (int i = 1; i < argc; i++) {
		// load dictionary
		if (i == 1) {
			in.open(argv[i]);
			while (getline(in, line)) {
				if (line.length() >= 4) {
					dictionary.insert(check(line));
				}
			}
			in.close();
		}
		// load board
		else if (i == 2) {
			in.open(argv[i]);
			while (in >> letter) {
				temp.push_back(check(letter));
			}
			in.close();
		}
	}
}
// check if the number of letters is a perfect square
bool perfectSquare(vector<string>& temp) {
	int square = 0;
	int n = temp.size();

	if (n < 0) return false;
	
	int root = round(sqrt(n));
	square = root * root;

	if (square == n) {
		return true;
	}
	else {
		return false;
	}
}
// load letters in the board
void createBoard (vector<string>& temp, vector<vector<string>>& board) {
	const int ROW = sqrt(temp.size());
	const int COL = sqrt(temp.size());
	vector<string> col;

	if (perfectSquare(temp)) {
		for (int r = 0; r < ROW; r++) {
			for (int c = 0; c < COL; c++) {
				col.push_back(temp[0]);
				temp.erase(temp.begin());
			}
			board.push_back(col);
			col.clear();
		}
	}
}
// initialize the matrix
void initMatrix(vector<vector<int>>& usedLetters, vector<vector<string>>& board) {

	vector<int> init;

	usedLetters.clear();

	for (unsigned int r = 0; r < board.size();  r++) {
		for (unsigned int c = 0; c <board.size(); c++) {
			init.push_back(0);
		}
		usedLetters.push_back(init);
		init.clear();
	}
}
// compare prefix with dico
bool compare(set<string>& dictionary, string word) {
	set<string>::iterator i = dictionary.lower_bound(word);
	string wordInDico;

	if (i == dictionary.end()) {
//		cout << "prefix not in the dico" << endl;
		return false;
	}
	else wordInDico = *i;
	if (word == wordInDico.substr(0, word.length())) {
//		cout << "prefix in the dico!!! keep going" << endl;
		return true;
	}
	else {
//		cout << "prefix not in the dico" << endl;
		return false;
	}
}
// check if word is in the dictionary
bool checkWord (set<string>& dictionary, string word) {
	for (set<string>::iterator i = dictionary.begin(); i != dictionary.end(); i++) {
		if (word == *i) {
//			cout << "congrats, word is in dictionary!" << endl;
			return true;
		}
	}
//	cout << "the word is not in the dictionary" << endl;
	return false;
}
// check the boundaries
bool bounds(int r, int c, vector<vector<string>>& board) {
	unsigned int row = r;
	unsigned int col = c;
	
	if (row >= 0 && row < board.size()) {
		if (col >= 0 && col < board.size()) {
//			cout << "--- in bounds ";
			return true;
		}
		else {
//			cout << "--- out of bounds (col), ";
			return false;
		}
	}
	else {
//		cout << "--- out of bounds (row), ";
		return false;
	}
}
// check if the letter has already been used
bool used(int r, int c, vector<vector<int>>& usedLetters) {
	if (usedLetters[r][c] == 1) {
	//	cout << "letter already used ---" << endl;
		return true;
	}
	else {
	//	cout << "letter not used yet ---" << endl;
		return false;
	}
}
// get the next letter on the board
void getLetter(set<string>& foundOnBoard, vector<vector<int>>& usedLetters, vector<vector<string>>& board, string word, int r, int c, set<string>& dictionary) {
	
	if (!bounds(r, c, board) || used(r, c, usedLetters)) {
		return;
	}
	else {
		word.append(board[r][c]);
		//cout << word << endl;
	}
    if (!compare(dictionary, word)) {
        return;
    }
	if (word.length() > 3 && checkWord(dictionary, word)) {
		foundOnBoard.insert(word);
//		if (compare(dictionary, word)) {
//			usedLetters[r][c] = 1;
//			getLetter(foundOnBoard, usedLetters, board, word, r, c+1, dictionary);
//			getLetter(foundOnBoard, usedLetters, board, word, r+1, c+1, dictionary);
//     		getLetter(foundOnBoard, usedLetters, board, word, r+1, c, dictionary);
//     		getLetter(foundOnBoard, usedLetters, board, word, r+1, c-1, dictionary);
//     		getLetter(foundOnBoard, usedLetters, board, word, r, c-1, dictionary);
//     		getLetter(foundOnBoard, usedLetters, board, word, r-1, c-1, dictionary);
//     		getLetter(foundOnBoard, usedLetters, board, word, r-1, c, dictionary);
//     		getLetter(foundOnBoard, usedLetters, board, word, r-1, c+1, dictionary);
//			usedLetters[r][c] = 0;
//		}
//		return;
	}
//	else if (!compare(dictionary, word)) {
//		return;
//	}
	usedLetters[r][c] = 1;
		
	getLetter(foundOnBoard, usedLetters, board, word, r, c+1, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r+1, c+1, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r+1, c, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r+1, c-1, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r, c-1, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r-1, c-1, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r-1, c, dictionary);
	getLetter(foundOnBoard, usedLetters, board, word, r-1, c+1, dictionary);
	usedLetters[r][c] = 0;
	return;
}
// find words on the board
void findWord(set<string>& foundOnBoard, vector<vector<int>>& usedLetters, vector<vector<string>>& board, set<string>& dictionary) {
	string word = "";

	for (unsigned int r = 0; r < board.size(); r++) {
		for (unsigned int c = 0; c < board[r].size(); c++) {
			initMatrix(usedLetters, board);
			//printBoard(usedLetters);
			//word = board[r][c];
			//usedLetters[r][c] = 1;
			getLetter(foundOnBoard, usedLetters, board, word, r, c, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r, c+1, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r+1, c+1, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r+1, c, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r+1, c-1, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r, c-1, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r-1, c-1, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r-1, c, dictionary);
			//getLetter(foundOnBoard, usedLetters, board, word, r-1, c+1, dictionary);
		}
	}
}

int main(int argc, char* argv[]) {

	set<string> dictionary;
	vector<string> temp;
	vector<vector<string>> board;
	vector<vector<int>> usedLetters;
	set<string> foundOnBoard;

	loadFiles(argc, argv, dictionary, temp);
	createBoard(temp, board);	
	initMatrix(usedLetters, board);
	//printBoard(argv, board);
	findWord(foundOnBoard, usedLetters, board, dictionary);
	
	ofstream out;
	out.open(argv[3]);

	printBoard(argv, board, out);
	printDic(argv, foundOnBoard, out);
	
	out.close();

	return (0);
}
