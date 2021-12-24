#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <string>
#include <ios>

using namespace std;

class Date {
public:
	Date();                    // today's date
	Date(int y, int m, int d); // yyyy-mm-dd
	int getYear() const;       // get the year
	int getMonth() const;      // get the month
	int getDay() const;        // get the day
	
	friend istream& operator>> (istream& is, Date &d) {
		string in;
		getline(is, in);
		int yearNumber;
		int monthNumber;
		int dayNumber;
		size_t first = in.find('-');
		//cout << "First dash: " << first << endl;
		if (first > 0 && first < 5) {
			string year = in.substr(0, first);
			yearNumber = stoi(year);
			in.erase(0, first+1);	//+1 to remove the dash
		} else {
			is.setstate(ios::failbit);
			return is;
		}
		size_t second = in.find('-');
		//cout << "Second dash: " << second << endl;
		if (second > 0 && second < 3) {
			string month = in.substr(0, second);
			monthNumber = stoi(month);
			in.erase(0, second+1);	//+1 to remove the dash
		} else {
			is.setstate(ios::failbit);
			return is;
		}
		size_t third = in.size();
		//cout << "Third dash: " << third << endl;
		if (third > 0 && third < 3) {
			string day = in.substr(0, third);
			dayNumber = stoi(day);
			in.erase(0, third);	//no +1 cause no dash
		} else {
			is.setstate(ios::failbit);
			return is;
		}
		
		if (yearNumber < 0 || yearNumber > 9999 || monthNumber > 12 || monthNumber < 0 
		|| dayNumber > 31 || dayNumber < 0) {
			is.setstate(ios::failbit);
			return is;
		}
		d.year = yearNumber;
		d.month = monthNumber;
		d.day = dayNumber;
		return is;
	}
	friend ostream& operator<< (ostream& os, const Date &d) {
		char ch[10] = {'0', '0', '0', '0', '-', '0', '0', '-', '0', '0'};
		string year = to_string(d.getYear());
		string month = to_string(d.getMonth());
		string day = to_string(d.getDay());

		size_t pos1 = 3;
		for (auto it = year.rbegin(); it != year.rend(); ++it) {
			ch[pos1] = *it;
			--pos1;
		}
		size_t pos2 = 6;
		for (auto it = month.rbegin(); it != month.rend(); ++it) {
			ch[pos2] = *it;
			--pos2;
		}
		size_t pos3 = 9;
		for (auto it = day.rbegin(); it != day.rend(); ++it) {
			ch[pos3] = *it;
			--pos3;
		}
		//If the code reaches this line, input should be correct.
		for (int i=0; i<=9; ++i) {
			os.put(ch[i]);
		}
		return os;
	}
	
	void next();               // advance to next day
private:
	int year;  // the year (four digits)
	int month; // the month (1-12)
	int day;   // the day (1-..)
	static int daysPerMonth[12]; // number of days in each month
};
	


#endif
