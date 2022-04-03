#pragma once
#include "Student.h"
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

class randomStudentGenerator {
private:
	vector<Student> all_student;
	int length;
public:
	int randomLength();
	void randomNameStudent();
	void printStudentRandom();
	void printStudentHigerGpa();
};