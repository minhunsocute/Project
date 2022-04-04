#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
class Date {
private:
	int day;
	int month;
	int year;
public:
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	void setDay(int value) { day = value; }
	void setMonth(int value) { month = value; }
	void setYear(int value) { year = value; }
	int ranDomDay(int month) {
		return rand() % (month)+1;
	}
	int ranDomMonth() {
		return rand() % (12) + 1;
	}
	int ranDomYear() {
		return rand() % (2004 - 1995 + 1) + 2000;
	}
	bool checkYear(int year) {
		if (year % 400 == 0)
			return true;
		if (year % 4 == 0 && year % 100 != 0)
			return true;
		return false;
	}
	Date ranDomDate() {
		vector<int> month_31{ 1,3,5,7,8,10,12 };
		vector<int> month_30{ 4,6,9,11 };
		Date d;
		d.setYear(ranDomYear());
		d.setMonth(ranDomMonth());
		if (find(month_31.begin(), month_31.end(), d.getMonth()) != month_31.end()) {
			d.setDay(ranDomDay(31));
		}
		if (find(month_30.begin(), month_30.end(), d.getMonth()) != month_30.end()) {
			d.setDay(ranDomDay(30));
		}
		if (d.getMonth() == 2) {
			if (checkYear(d.getYear()) == true) {
				d.setDay(ranDomDay(29));
			}
			else
				d.setDay(ranDomDay(28));
		}
		return d;
	}
	string toString() {
		stringstream builder;
		builder << day << "/" << month << "/" << year;
		string result = builder.str();
		return result;
	}
};