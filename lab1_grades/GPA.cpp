#include "GPA.h"

GPA::GPA(string ID, double studentGPA, string name) {
	this->ID = ID;
	this->studentGPA = studentGPA;
	this->name = name;
}

GPA::~GPA() {}

string GPA::toString() {
	stringstream ss;
	ss << ID << "\t"
	   << fixed << setprecision(2) << setfill('0') <<  studentGPA << "\t"
	   << name << endl;
	return ss.str();
}
