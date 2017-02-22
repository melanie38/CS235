#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class GPA {
private:
	string ID;
	double studentGPA;
	string name;

public:
	GPA(string ID, double studentGPA, string name);
	virtual ~GPA();
	string getID() const { return ID;}
	double getGPA() const { return studentGPA;}
	string getName() const { return name;}
	string toString();
};
