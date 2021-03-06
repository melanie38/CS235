/*
 * Student.h
 *
 *  Created on: Jun 26, 2015
 *      Author: mlalahar
 */
#pragma once

#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
#include <sstream>

using namespace std;

class Student {
private:
	string ID;
	string name;
	string address;
	string phone;

public:
	Student(string ID, string name, string address, string phone);
	virtual ~Student();
	string getID() const {return ID;}
	string getName() const {return name;}
	string getAddress() const {return address;}
	string getPhone() const {return phone;}
	string toString();
	bool operator < (Student s) const {return ID < s.ID;}
};

#endif /* STUDENT_H_ */
