#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using std::cout;
using std::endl;

class User {
public:
    User() :cardNbr{0},name{"default"}{}
    User(int c, std::string n) :cardNbr{c},name{n} {}
    ~User() {cardNbr=-2; name="--------------------";} // overwrite values for security reasons
    User(const User& u) =default;
    User& operator=(const User&) =default;
    int getCardNbr() const {return cardNbr;}
    std::string getName() const {return name;}
    bool operator==(const User& u) const {return cardNbr == u.cardNbr && name == u.name;}
    bool operator!=(const User& u) const {return ! (u == *this);}
private:
    int cardNbr;
    std::string name;
};

std::ostream& operator<<(std::ostream& os, const User& u);
#endif
