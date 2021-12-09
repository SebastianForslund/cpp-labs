#include <iostream>
#include <string>
#include <vector>
#include <math.h> 

#include "sieve.h"

using namespace std;

sieve::sieve(int limit){
	this->limit = limit;
	string sequence = "CC";
	vector<int> primes;
	sequence.resize(limit);
	sequence.replace(2, limit, limit-1, 'P');
	for (int i = 2; i <= sqrt(limit); ++i) {
		if (sequence[i] == 'P') {
			for (int y = i+i; y <= limit; y = y+i) {
				sequence[y] = 'C';
			}
		}
	}
	
	this->sequence = sequence;
}

vector<int> sieve::get_primes_list(){
	if (this->primes.size() == 0) {
		//Find the primes.
		string temp = this->sequence;
		while (true) {
			size_t number = temp.find('P');
			if (static_cast<unsigned int>(number) == static_cast<unsigned int>(size_t(-1))) { //string::npos, this is feels insane.
				break;
			}
			temp[number] = 'C';
			this->primes.push_back(number);
		}
		return this->primes;
	} else {
		return this->primes;
	}
}

string sieve::get_string_representation() {
	return this->sequence;
}