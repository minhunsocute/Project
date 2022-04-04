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
	vector<string> first_name;
	vector<string> middle_name;
	vector<string> last_name;
	vector<string> telephone;
	vector<string> eMail;
	vector<string> Street;
	vector<string> Ward;
	vector<string> District;
public:
	DataAccess();
	~DataAccess();
public :
	vector<string> getFirstName() { return first_name; }
	vector<string> getMiddleName() { return middle_name; }
	vector<string> getLastName() { return last_name; }
	vector<string> getStreet() { return Street; }
	vector<string> getWard() { return Ward; }
	vector<string> getDistrict() { return District; }
	vector<string> getTelephone() { return telephone; }
	vector<string> getEmail() { return eMail; }
	
public:
	vector<Student> readFileStudent();
	void readFileFirstName();
	void readFileMiddleName();
	void readFileLastName();
	void readFileStreet();
	void readFileWard();
	void readFileDistrict();
	void readFileTelePhone();
	void readFileEmail();
	void readAllFile();
	double convertStringtoDouble(string);
};