#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class TagRemover {
public:
	TagRemover();
    void tr(istream& input);
    void print(ostream& output);


private:
string text;

};


#endif