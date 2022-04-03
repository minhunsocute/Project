#include "dataAccess.h"

void DataAccess::readFile() {
	ifstream fin;
	fin.open("Student.txt");
	string str;
	int countLine = 0;
	while (std::getline(fin, str)) {
		if (countLine == 5) {
			countLine = 0;
		}
		int index = 0;
		if (countLine == 0) {
			int find1 = str.find(':');
			int find2 = str.find('-');
			string Id = str.substr(find1+2,find2-find1-3);
			string Name =str.substr(find2 + 2,str.length());
			id.push_back(Id);
			name.push_back(Name);
		}
		else if (countLine == 1) {
			int find1 = str.find('=');
			int find2 = str.find('=', find1 + 1);
			int find3 = str.find(',');
			string doub = str.substr(find1+1, find3 - find1-1);
			string tele = str.substr(find2 + 1, str.length());
			doub.push_back(convertStringtoDouble(doub));
			telephone.push_back(tele);
		}
		else if (countLine == 2) {
			eMail.push_back(str.substr(str.find('=') + 1, str.length()));
		}
		else if (countLine == 3) {
			dob.push_back(str.substr(str.find('=') + 1, str.length()));
		}
		else if (countLine == 4) {
			address.push_back(str.substr(str.find('=') + 1, str.length()));
		}
		countLine++;
	}
	//for (auto it : id) {
	//	cout << it << "\n";
	//}
	//for (auto it : name) {
	//	cout << it << "\n";
	//}

	//for (auto it : telephone) {
	//	cout << it << "\n";
	//}

	//for (auto it : gpa) {
	//	cout << it << "\n";
	//}

	//for (auto it : dob) {
	//	cout << it << "\n";
	//}

	//for (auto it : eMail) {
	//	cout << it << "\n";
	//}

	//for (auto it : address) {
	//	cout << it << "\n";
	//}

	fin.close();
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
DataAccess::DataAccess() {

}
DataAccess::~DataAccess() {

}