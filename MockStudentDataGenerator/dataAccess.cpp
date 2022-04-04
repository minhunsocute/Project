#include "dataAccess.h"

vector<Student> DataAccess::readFileStudent() {
	ifstream fin;
	fin.open("data/Student.txt");
	vector<Student> allS;
	string str;
	int countLine = 0;
	Student s;
	while (std::getline(fin, str)) {
		if (countLine == 5) {
			countLine = 0;
			allS.push_back(s);
		}
		int index = 0;
		if (countLine == 0) {
			int find1 = str.find(':');
			int find2 = str.find('-');
			s.setID(str.substr(find1 + 2, find2 - find1 - 3));
			s.setName(str.substr(find2 + 2, str.length()));
			
		}
		else if (countLine == 1) {
			int find1 = str.find('=');
			int find2 = str.find('=', find1 + 1);
			int find3 = str.find(',');
			string doub = str.substr(find1 + 1, find3 - find1 - 1);
			string tele = str.substr(find2 + 1, str.length());
			s.setGPA(convertStringtoDouble(doub));
			s.setTelephone(tele);
		}
		else if (countLine == 2) {
			s.setEmail(str.substr(str.find('=') + 1, str.length()));
		}
		else if (countLine == 3) {
			s.setDOB(str.substr(str.find('=') + 1, str.length()));
		}
		else if (countLine == 4) {
			s.setAddress(str.substr(str.find('=') + 1, str.length()));
		}
		countLine++;
	}
	if (s.getName() != "") {
		allS.push_back(s);
	}
	fin.close();
	return allS;
}
double DataAccess::convertStringtoDouble(string s) {
	double result = 0;
	int index = 0;
	double check = 0;
	while (index < s.length()) {
		if (s[index] == '.')
			check = 0.1;
		else {
			if (check == 0) {
				result = result * 10 + int(s[index]) - 48;
			}
			else {
				result = result + (int(s[index]) - 48) * check;
				check *= 0.1;
			}
		}
		index++;
	}
	return result;
}

void DataAccess::readFileFirstName() {
	ifstream fin;
	fin.open("data/FirstName.txt");
	string str;
	while (std::getline(fin, str)) {
		first_name.push_back(str);
	}
	fin.close();
}
void DataAccess::readFileMiddleName() {
	ifstream fin;
	fin.open("data/MiddleName.txt");
	string str;
	while (std::getline(fin, str)) {
		middle_name.push_back(str);
	}
	fin.close();
}
void DataAccess::readFileLastName() {
	ifstream fin;
	fin.open("data/LastName.txt");
	string str;
	while (std::getline(fin, str)) {
		last_name.push_back(str);
	}
	fin.close();
}
void DataAccess::readFileStreet() {
	ifstream fin;
	fin.open("data/Street.txt");
	string str;
	while (std::getline(fin, str)) {
		Street.push_back(str);
	}
	fin.close();
}
void DataAccess::readFileWard() {
	ifstream fin;
	fin.open("data/Ward.txt");
	string str;
	while (std::getline(fin, str)) {
		Ward.push_back(str);
	}
	fin.close();
}
void DataAccess::readFileDistrict() {
	ifstream fin;
	fin.open("data/District.txt");
	string str;
	while (std::getline(fin, str)) {
		District.push_back(str);
	}
	fin.close();
}
void DataAccess::readFileTelePhone() {
	fstream fin;
	fin.open("data/Telephone.txt");
	string str;
	while (std::getline(fin, str)) {
		telephone.push_back(str);
	}
	fin.close();
}

void DataAccess::readFileEmail() {
	fstream fin;
	fin.open("data/email.txt");
	string str;
	while (std::getline(fin, str)) {
		eMail.push_back(str);
	}
	fin.close();
}	

void DataAccess::readAllFile() {
	readFileStudent();
	readFileStreet();
	readFileDistrict();
	readFileWard();
	readFileTelePhone();
	readFileEmail();
	readFileFirstName();
	readFileMiddleName();
	readFileLastName();
}
DataAccess::DataAccess() {

}
DataAccess::~DataAccess() {

}