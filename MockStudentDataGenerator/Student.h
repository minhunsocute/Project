#pragma once
	#include<iostream>
	#include<vector>
	#include<string.h>
	#include<string>
	using namespace std;
class Student {
private:
	string id;
	string name;
	double GPA;
	string telephone;
	string eMail;
	string DOB;
	string address;
public:
	//------CONSTRUCTOR-------//
	Student();
	Student(string ID, string Name, double gpa, string Telephone, string Email, string dob, string Address) {
		this->id = ID;
		this->name = Name;
		this->GPA = gpa;
		this->telephone = Telephone;
		this->eMail = Email;
		this->DOB = dob;
		this->address = Address;
	}
	~Student();
public:
	//------GET-------//
	string getID() { return id; }
	string getName() { return name; }
	double getGPA() { return GPA; }
	string getTelePhone() { return telephone; }
	string getEmail() { return eMail; }
	string getDOB() { return DOB; }
	string getAddress() { return address; }
public:
	//------SET-------//
	void setID(string val) { this->id = val; }
	void setName(string val) { this->name = val; }
	void setGPA(double val) { this->GPA = val; }
	void setTelephone(string val) { this->telephone = val; }
	void setEmail(string val) { this->eMail = val; }
	void setDOB(string val) { this->eMail = val; }
	void setAddress(string val) { this->address = val; }
};