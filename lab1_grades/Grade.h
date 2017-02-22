/*
 * Grade.h
 *
 *  Created on: Jun 26, 2015
 *      Author: mlalahar
 */

#ifndef GRADE_H_
#define GRADE_H_
#include <iostream>
#include <sstream>

using namespace std;

class Grade {
private:
	string course;
	string ID;
	string grade;

public:
	Grade(string course, string ID, string grade);
	virtual ~Grade();
	string getCourse() const {return course;}
	string getID() const {return ID;}
	string getGrade() const {return grade;}
	string toString();
	bool operator < (Grade g) const { return 
		ID < g.ID ||
		(ID == g.ID && course < g.course) ||
		(ID == g.ID && course == g.course && grade < g.grade);}
};

#endif /* GRADE_H_ */
