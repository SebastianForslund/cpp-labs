#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class sieve {
public:
sieve(int limit);
vector<int> get_primes_list();
string get_string_representation();

private:
int limit;
string sequence;
vector<int> primes;
};


#endif