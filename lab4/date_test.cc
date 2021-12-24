#include <iostream>
#include <iomanip> // for setw and setfill
#include <sstream>
#include "date.h"

using namespace std;

/*
 * Prints the date d in the format yyyy-mm-dd. You shall replace this
 * function with an overloaded operator<<, and add an overloaded operator>>.
 *
 */
void print(const Date& d) {
	cout << setw(4) << setfill('0') << d.getYear() << '-';
	cout << setw(2) << setfill('0') << d.getMonth() << '-';
	cout << setw(2) << setfill('0') << d.getDay();
}

template <class T>
string toString(T input) {
	ostringstream oss;
	oss << input;
	return oss.str();
}

template <typename T> T string_cast(string input) {
	istringstream iss(input);
	T output;
	iss >> output;
	if (!iss.fail() && iss.eof()) {
		return output;
	} else {
		throw invalid_argument("Invalid input.");
		//return null; //vettefan här
	}
}

int main() {
	// Check input and output of dates. Uncomment the following when you 
	// have added operator>> and operator<<.
	
	cout << "Testing the toString template: " << endl;
	Date dateToString;
	cout << "Date toString result: " << toString(dateToString) << endl;
	double d = 1234.222;
	cout << "Double toString result: " << toString(d) << endl;
	char iq = 'P';
	cout << "Char toString result: " << toString(iq) << endl;
	char* ptr = &iq;
	cout << "Pointer toString result: " << toString(ptr) << endl; //Denna ger inget :0
	int x = 10;
	int& ref = x;
	cout << "Reference toString result: " << toString(ref) << endl;
	cout << "Reference address toString result: " << toString(&ref) << endl << endl;
	//Av någon anledning så kommer output vartannan gång när man gör en felaktig input.
	
	cout << "Testing the string_cast template: " << endl;
	int integer = string_cast<int>("123");
	cout << "Int string_cast result: " << integer << endl;
	
	double doub = string_cast<double>("123.33");
	cout << "Double string_cast result: " << doub << endl;
	
	Date det = string_cast<Date>("2000-06-22");
	cout << "Date string_cast result: " << det << endl;
	
	cout << "123abc should not work: " << endl;
	try {
		int pipi = string_cast<int>("123a");
		cout << "Int string_cast result: " << pipi << endl;
	} catch(const exception& e) {
		cout << "It did not work." << endl;
	}
	
	//Denna onskefulla rad gör att programmet inte längre vill kompilera.
	//cout << "Double conversion boogaloo: " << string_cast<int&>(toString(ref)) << endl;
	
	bool cont = true;
	while (cont) {
		cout << "Type a date: ";
		Date aDate;
		cin >> aDate;
		if (cin.eof()) {
			cont = false;
		} else if (!cin.good()) {
			cout << "Wrong input format" << endl;
			// restore stream state and ignore the rest of the line
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else {
			cout << "Output: " << aDate << endl;
		}
	}
	
	
	// Check 'next' by creating an object describing today's date, then
	// printing dates more than a month ahead
	cout << "--- Today and more than a month ahead:" << endl;
	Date d1;
	print(d1);
	cout << endl;
	for (int i = 1; i <= 35 ; ++i) {
		d1.next();
		print(d1);
		cout << endl;
	}
	
	// Check so 'next' functions correctly from one year to the next
	cout << "--- New Year's Eve and the next day:" << endl;
	Date d2(2013, 12, 31);
	print(d2);
	cout << endl;
	d2.next();
	print(d2);
	cout << endl;
}
