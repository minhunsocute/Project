#pragma once
#include "Student.h"
#include "dataAccess.h"
#include "Date.h"
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
	int randomNo(int left, int right) {
		return rand() % (right - left + 1) + left;
	}
	int randomLength();
	string randomNameStudent(DataAccess da);
	string randomIdStudent();
	string randomTelePhone(DataAccess da);
	string randomDateBorn();
	string randomAddress(DataAccess da);
	double randomGPA();
	string randomEmail(DataAccess da,string name);
	void randomStudent();
	void printStudentRandom(vector<Student> all,int&index);
	void printStudentHigerGpa(vector<Student> all);
public:
	vector<Student> getAll() { return all_student; }
};