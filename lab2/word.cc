#include <string>
#include <vector>
#include <iostream>
#include "word.h"

using std::vector;
using std::string;
using std::cout;
using std::endl;

Word::Word(const string& w, const vector<string>& t) {
	this->word = const_cast<string&>(w);
	this->trigramVector = const_cast<vector<string>&>(t);
}

string Word::get_word() const {
	return this->word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	auto it1 = this->trigramVector.begin();
	auto it2 = t.begin();
	int matches = 0;
	while (it1 != trigramVector.end() && it2 != t.end()) {
		if (*it1 == *it2) {
			matches++;
			it1++;
			it2++;
		} else if (*it1 < *it2) {
			it1++;
		} else {
			it2++;
		}
	}
	return matches;
}
