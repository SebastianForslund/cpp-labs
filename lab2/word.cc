#include <string>
#include <vector>
#include "word.h"

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {}

string Word::get_word() const {
	return string();
}

unsigned int Word::get_matches(const vector<string>& t) const {
	return 0;
}
