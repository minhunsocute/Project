#include "randomStudentGenerator.h"


int randomStudentGenerator::randomLength() {
	return randomNo(5, 10);
}
string randomStudentGenerator::randomNameStudent(DataAccess da) {
	string name = "";
	name += da.getFirstName().at(randomNo(0,da.getFirstName().size()-1))+" ";
	name += da.getMiddleName().at(randomNo(0, da.getMiddleName().size()-1)) + " ";
	name += da.getLastName().at(randomNo(0, da.getLastName().size()-1));
	return name;
}
string randomStudentGenerator::randomIdStudent() {
	string id = to_string((rand() % (2200000 - 2100000 + 1) + 2100000));
	return id;
}
string randomStudentGenerator::randomTelePhone(DataAccess da) {
	string telephone = "";
	telephone += da.getTelephone().at(randomNo(0, da.getTelephone().size()-1)) + "-";
	for (int i = 0; i < 7; i++) {
		telephone += to_string(rand() % (9 - 0 + 1));
	}
	return telephone;
}
string randomStudentGenerator::randomDateBorn() {
	Date d;
	string dob = "";
	d.ranDomDate();
	dob += d.toString();
	return dob;
}
string randomStudentGenerator::randomAddress(DataAccess da) {
	string address = "";
	address += to_string(rand() % (50) + 1) + " " + da.getStreet().at(randomNo(0, da.getStreet().size()-1)) + ",";
	address +=" Ward "+ da.getWard().at(randomNo(0, da.getWard().size()-1)) + ",";
	address += " District " + da.getDistrict().at(randomNo(0, da.getDistrict().size()-1)) + ",";
	address += " Ho Chi Minh city";
	return address;
}
double randomStudentGenerator::randomGPA() {
	double no = (double(rand()) / double((RAND_MAX)) * 10);
	return round(no * 100) / 100;
}
string randomStudentGenerator::randomEmail(DataAccess da,string name) {
	string email = "";
	int find1 = name.find(' ');
	int find2 = name.find(' ', find1 + 1);
	string firstName = name.substr(0, find1);
	string middleName = name.substr(find1 + 1, find2 - find1-1);
	string lastName = name.substr(find2 + 1, name.length() - 1);
	lastName = char(int(lastName[0]) + 32) + lastName.substr(1, lastName.length());
	email += char(int(firstName[0])+32);
	email += char(int(middleName[0])+32);
	email += lastName + da.getEmail().at(randomNo(0, da.getEmail().size() - 1));
	return email;
}
void randomStudentGenerator::randomStudent() {
	DataAccess ds;
	ds.readAllFile();
	all_student = ds.readFileStudent();
	int index = 0;
	cout << "* Print Student in file text:\n";
	printStudentRandom(all_student, index);
	srand(time(NULL));
	length = randomLength();
	cout << "* Random number generated in range [5,10]:" << length<<'\n';
	for (int i = 0; i < length; i++) {
		Student s;
		s.setID(randomIdStudent());
		s.setName(randomNameStudent(ds));
		s.setGPA(randomGPA());
		s.setTelephone(randomTelePhone(ds));
		s.setEmail(randomEmail(ds, s.getName()));
		s.setDOB(randomDateBorn());
		s.setAddress(randomAddress(ds));
		all_student.push_back(s);
	}
	printStudentRandom(all_student,index);
	cout << "\n";
	printStudentHigerGpa(all_student);
}
void randomStudentGenerator::printStudentRandom(vector<Student> all,int&index) {
	cout << "* The average GPA of all students" << "\n";
	for (index; index < all.size();index++) {
		cout << "Student: " << all.at(index).getID() << " - " << all.at(index).getName() << "\n";
		cout << "\tGPA=" << all.at(index).getGPA() << ", Telephone=" << all.at(index).getTelePhone() << "\n";
		cout << "\tEmail=" << all.at(index).getEmail() << "\n";
		cout << "\tDOB=" << all.at(index).getDOB() << "\n";
		cout << "\tAddress=" << all.at(index).getAddress() << "\n";
	}
}
void randomStudentGenerator::printStudentHigerGpa(vector<Student> all) {
	double no = (double(rand()) / double((RAND_MAX)) * 10);
	double averageGPA = round(no * 100) / 100;
	cout << "* Random the average GPA: " << averageGPA << "\n";
	for (auto it : all) {
		if (it.getGPA() > averageGPA) {
			cout << it.getID() << " - " << it.getName() << ", GPA: " << it.getGPA()<<"\n";
		}
	}
}