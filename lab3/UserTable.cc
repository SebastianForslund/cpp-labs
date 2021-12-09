#include "UserTable.h"
#include <fstream>
#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;
using std::string;
const User UserTable::user_not_found = User{-1,"Not Found"};

UserTable::UserTable() :users{new User[capacity]} { }

UserTable::UserTable(const std::string& fname) :UserTable{}
{
	users = new User[capacity];
    std::ifstream ufile(fname, std::ifstream::in);

    if(ufile.is_open()) {
        while(ufile.good()) {
            int cn;
            if(ufile >> cn) {
				//cout << cn << endl;
                ufile.ignore(); // skip space
				std::string n;
				std::getline(ufile, n);
				//cout << n << endl;
				n.pop_back(); //finns en newline på varje rad av txt-filen.
				User u(cn, n);
				//cout << u << endl;
                addUser(u);
            }
        }
    } else {
        std::cout << "Could not open " << fname << std::endl;
    }
}

void UserTable::addUser(const User& u)
{
    // gör tabellen större vid behov
    ensureCapacity(n+1);
    // 1. Hitta rätt plats
    int pos{0};
    while ( (pos < n) && (users[pos].getCardNbr() < u.getCardNbr())){
        ++pos;
    }
    //2. skapa lucka i vektorn
    for(int i=n; i > pos; --i){
        users[i] = users[i-1];
    }
    //3. stoppa in den nya användaren i luckan
    users[pos] = u;
	n++;
}

User UserTable::find(int c) const
{
    // binärsökning (baserad på Holm, 2007)
    int low = 0;
    int high = n - 1;
    int mid = -1;
    bool found = false;
    while (low <= high && ! found) { //ändrade till <=.
        mid = low + (high - low) / 2; //Ändrat fån (low + high) / 2
        //
        int midnbr = users[mid].getCardNbr();
        if (midnbr == c) {
            found = true;
        } else if (users[mid].getCardNbr() < c) {
            low = mid + 1;
        } else { // >c
            high = mid - 1;
        }
    }

    return found ? users[mid] : user_not_found;
}
User UserTable::find(std::string name) const //ingen aning varför denna inte funkar.
{
	//cout << "n: " << n << endl;
	//cout << typeid(name).name() << endl;
    for (int i = 0; i < n; ++i) {
		//cout << i << endl;
		//cout << typeid(users[i].getName()).name() << endl;
        if (users[i].getName() == name) { //Något måste vara fucked up här
            return users[i];
        }
    }
    return user_not_found;
}

void UserTable::ensureCapacity(int s)
{
    if(s>capacity) {
        while(s > capacity) {
            capacity*=4;
        }
        auto tmp = new User[capacity];
        std::copy(users, users+n, tmp);
        delete[] users;
        users=tmp;
    }

}
void UserTable::print(std::ostream& os) const
{
    os << "-------------" << std::endl;
    for(int i = 0; i != getNbrUsers(); ++i) {
        const auto& u = users[i];
        os << "(" <<u.getCardNbr() << ") " << u.getName() << std::endl;
    }
    os << "=============" << std::endl;
}
/**
    * Testmetod för binärsökningen:
    * går igenom alla användare och kollar att deras kortnummer kan sökas upp.
    * Om något kortnummer inte kunde sökas upp returneras detta. Annars, om
    * alla sökningar lyckades, returneras 0.
    */
int testFindNbr(const UserTable &ut)
{
    for (int i = 0; i < ut.n; i++) {
        int nbr = ut.users[i].getCardNbr();
        if (ut.find(nbr) != ut.users[i]) {
            return nbr;
        }
    }
    return 0;
}

