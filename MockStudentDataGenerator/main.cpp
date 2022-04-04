#include "Student.h"
#include "dataAccess.h"
#include "randomStudentGenerator.h"

void outFile(randomStudentGenerator r) {
	ofstream fout;
	fout.open("data/Student.txt");
	for (auto it : r.getAll()) {
		fout << "Student: " << it.getID() << " - " << it.getName() << "\n";
		fout << "\tGPA=" << it.getGPA() << ", Telephone=" << it.getTelePhone() << "\n";
		fout << "\tEmail=" << it.getEmail() << "\n";
		fout << "\tDOB=" << it.getDOB() << "\n";
		fout << "\tAddress=" << it.getAddress() << "\n";
	}
	fout.close();
}

int main() {
	randomStudentGenerator r;
	r.randomStudent();
	outFile(r);
	system("pause");
}