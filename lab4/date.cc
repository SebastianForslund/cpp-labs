#include <ctime>  // time and localtime
#include <iostream>
#include <string>

#include "date.h"

using namespace std;
int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d) {
	this->year = y;
	this->month = m;
	this->day = d;
}


int Date::getYear() const { //dessa kan vara fel
	return year;
}

int Date::getMonth() const {//dessa
	return month;
}

int Date::getDay() const {//dessa
	return day;
}

void Date::next() {
}

