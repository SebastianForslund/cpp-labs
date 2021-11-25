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
	//auto b = t.begin(); //Why is this frickin vector empty
	//cout << "Bapparappa " << *b << endl;
	this->trigramVector = const_cast<vector<string>&>(t); //This is always 0
	cout << "word trigram vector size: " << this->trigramVector.size() << " other: " << t.size() << endl;
}

string Word::get_word() const {
	return this->word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	for (auto it = t.begin(); it != t.end(); ++it) {
		//cout << "Trigram in word: "<< *it << endl;
	}
	auto it1 = this->trigramVector.begin();
	//auto it2 = t.begin();
	cout << *it1 << endl;
	//cout << *it2 << endl;
	int matches = 0;
	/*
	while (it1 != trigramVector.end() && it2 != t.end()) {
		cout << "Comparing: " << *it1 << " and: " << *it2 << endl;
		if (*it1 == *it2) {
			cout << "theyre equal." << endl;
			matches++;
			it1++;
			it2++;
		} else if (*it1 < *it2) {
			it1++;
		} else {
			it2++;
		}
	}*/
	return matches;
}
