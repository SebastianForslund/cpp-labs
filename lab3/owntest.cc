#include <iostream>
#include <vector>
#include <fstream>


#include "User.h"
#include "UserTable.h"

using std::cout;
using std::endl;
using std::vector;
using std::cin;
using std::string;

int main() {
	UserTable table("users.txt");
	cout << "find 21330: " << table.find(21330) << endl;
	cout << "find 21331: " << table.find(21331) << endl;
	cout << "find Irene: " << table.find("Irene Danielsson") << endl;
	cout << "find Jonas Andersson: " << table.find("Jonas Andersson") << endl;
	//table.print(cout);
	cout << "Number of users: " << table.getNbrUsers() << endl;
	cout << "Adding a new user to the table." << endl;
	string s = "Sven Sveger";
	User u(99999, s);
	table.addUser(u);
	string m = "Swag Swagger";
	User u1(99998, m);
	table.addUser(u1);
	User u2(38250, "Jonas Andersson");
	table.addUser(u2);
	cout << "find Sven Sveger: " << table.find("Sven Sveger") << endl; 
	cout << "find Swag Swagger: " << table.find("Swag Swagger") << endl;
	cout << "find Jonas Andersson: " << table.find("Jonas Andersson") << endl;
	
	
	cout << "Number of users after adding 3 users: " << table.getNbrUsers() << endl;
	//table.print(cout);
	cout << "testFindNbr result: " << testFindNbr(table) << endl;
	return 0;
}








