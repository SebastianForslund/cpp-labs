#ifndef USERTABLE_H
#define USERTABLE_H

#include <iostream>

#include "User.h"

class UserTable{
public:
    UserTable();
    UserTable(const std::string&);
    ~UserTable() {std::cout << "deleted table" << std::endl;}

    void addUser(const User&);
    User find(int) const;
    User find(std::string) const;

    int getNbrUsers() const {
        return n;
    }

    void print(std::ostream&) const;

    static const User user_not_found;
private:
    int capacity{1000};
    void ensureCapacity(int);
    int n{0};
    User* users;

    friend int testFindNbr(const UserTable ut);
};
#endif
