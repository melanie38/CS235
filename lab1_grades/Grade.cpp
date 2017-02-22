/*
 * Grade.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: mlalahar
 */

#include "Grade.h"

Grade::Grade(string course, string ID, string grade) {
	this->course = course;
	this->ID = ID;
	this->grade = grade;
}

Grade::~Grade() {
	// TODO Auto-generated destructor stub
}

string Grade::toString() {
	stringstream ss;
	ss << ID << "\t"
	   << grade << "\t"
	   << course << endl;
	return ss.str();
}

