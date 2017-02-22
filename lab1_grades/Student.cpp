/*
 * Student.cpp
 *
 *  Created on: Jun 26, 2015
 *      Author: mlalahar
 */

#include "Student.h"

Student::Student(string ID, string name, string address, string phone) {
	this->ID = ID;
	this->name = name;
	this->address = address;
	this->phone = phone;

}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

string Student::toString() {
	stringstream ss;
	ss << name << endl;
	ss << ID << endl;
	ss << phone << endl;
	ss << address << endl;
	return ss.str();
}

