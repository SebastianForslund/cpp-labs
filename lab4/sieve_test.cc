#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "sieve.h"

using namespace std;

int main() {
	
	sieve s(35);
	vector<int> primes = s.get_primes_list();
	vector<int> correctPrimes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	auto it1 = correctPrimes.begin();
	cout << "Checking all primes below 35: " << endl;
	for (auto it = primes.begin(); it != primes.end(); ++it) {
		if (*it != *it1) {
			cout << "Incorrect!!!!" << endl;
		}
		++it1;
	}
	string correct = "CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCCC";
	cout << "String representation comparison number: " << s.get_string_representation().compare(correct) << endl;
	cout << "O utput sequence: \t" << s.get_string_representation() << "\tsize: " << s.get_string_representation().size() << endl;
	cout << "Correct sequence: \t" << correct << "\tsize: " << correct.size() << endl << endl;
	
	sieve two(200);
	vector<int> twoVector = two.get_primes_list();
	cout << "All primes below 200: " << endl;
	for (auto it = twoVector.begin(); it != twoVector.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	
	sieve big(100000);
	vector<int> biggestPrime = big.get_primes_list();
	cout << "The biggest prime below 100 000 is: " << biggestPrime.back() << endl;
	return 0;
}
