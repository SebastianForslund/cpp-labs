#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "TagRemover.h"

using namespace std;

TagRemover::TagRemover() {
	
}

void TagRemover::tr(istream& input) {
	string inputString;
	string wholeInput;
	while (getline(input, inputString)) {
		wholeInput += inputString + "\n";
	}
	while (wholeInput.find('<') != string::npos) { //This loop removes the tags.
		auto index1 = wholeInput.find('<');
		auto index2 = wholeInput.find('>');
		auto lengthindex = index2-index1+1;
		
		string substr = wholeInput.substr(index1, lengthindex);
		int newlineCount = 0;
		for (auto it = substr.begin(); it != substr.end(); ++it) { //Lite fult men lyckades inte göra det med string.find
			if (*it == '\n') {
				newlineCount++;
			}
		}
		wholeInput.erase(index1, lengthindex);
		for (int i = 0; i < newlineCount; ++i) {
			wholeInput.insert(index1, "\n");
		}
	}
	while (wholeInput.find('&') != string::npos && wholeInput.find(';') != string::npos) {
		auto index1 = wholeInput.find('&');
		auto index2 = wholeInput.find(';')+1;
		auto lengthindex = index2-index1;
		string character = wholeInput.substr(index1+1, lengthindex-2);
		wholeInput.erase(index1, lengthindex);
		
		string specialChar;
		if (character == "lt") {
			specialChar = '<';
		} else if (character == "gt") {
			specialChar = '>';
		} else if (character == "nbsp") {
			specialChar = ' ';
		} else if (character == "amp") {
			specialChar = '&';
		} else {
			specialChar = '?';
		}
		wholeInput.insert(index1, specialChar);
		cout << wholeInput << endl;
	}
	wholeInput.pop_back(); //icke nice
	this->text = wholeInput;
	return;
}

void TagRemover::print(ostream& output) {
	if (this->text.length() == 0) {
		output << "No text has been processed!";
		return;
	} else {
		output << this->text;
		return;
	}
}
