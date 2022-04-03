#pragma once
#include "Student.h"
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<fstream>
using namespace std;

class DataAccess{
private:
	vector<string> id;
	vector<string> name;
	vector<double> gpa;
	vector<string> telephone;
	vector<string> eMail;
	vector<string> dob;
	vector<string> address;
public:
	DataAccess();
	~DataAccess();
public :
	vector<string> getId() { return id; }
	vector<string> getName() { return name; }
	vector<double> getGpa() { return gpa; }
	vector<string> getTelephone() { return telephone; }
	vector<string> getEmail() { return eMail; }
	vector<string> getDob() { return dob; }
	vector<string> getAddress() { return address; }
public:
	void readFile();
	double convertStringtoDouble(string);
};