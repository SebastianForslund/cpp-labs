#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::unordered_set;
using std::endl;
using std::cout;
using std::ifstream;
using std::sort;

Dictionary::Dictionary() {
	ifstream inputStream;
	inputStream.open("words");
	
	//this.max_characters = 25; change it in the header file
	
	string in = "";
	string currentWord = "";
	vector<Word> words[max_characters];
	vector<string> trigrams;
	while (std::getline(inputStream, in, '\n')){
		
		currentWord = "";
		for (auto it = in.begin(); *it != ' ' && it != in.end(); ++it) {
			currentWord += *it;
		}

		string currentTrig = "";
		for (auto it = in.begin() + currentWord.size(); *it != '\n' && it != in.end(); ++it) {
			if (*it != ' ') {
				currentTrig += *it;
			} else {
				trigrams.push_back(currentTrig);
				currentTrig = "";
			}
		}
		Word w(currentWord, trigrams);
		words[currentWord.size()].push_back(w);
	}
}

bool Dictionary::contains(const string& word) const {
	if (allWords.find(word) == allWords.end()) {
		return false;
	} else {
		cout << *allWords.find(word) << endl;
		return true;
	}
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string> suggestions, const string& input) const {
	vector<string> input_trigrams;
	if (input.size() > 2) {
		for (auto it = input.begin(); it != input.end()-2; ++it) {
			string trig = {*it, *(it+1), *(it+2)};
			input_trigrams.push_back(trig); //Kan jag göra detta i en rad?
		}
	}
	
	sort(input_trigrams.begin(), input_trigrams.end()); //trigrams are now in a sorted vector
	
	if (input.size() > 0 && input.size() < this->max_characters) {
		cout << "input size check passed." << endl;
		cout << "random words size: " << this->words[input.size()].size() << endl; //Words är tom just nu
		for (int i=-1; i<1; ++i) { //Checks words of similar length
			vector<Word> words_vector = this->words[input.size() + i];
			for (auto it = words_vector.begin(); it != words_vector.end(); ++it) {
				Word w = *it; //*it.get_matches() didn't work for some reason
				int matches = w.get_matches(input_trigrams);
				cout << "matches: " << matches << endl;
				if (matches >= input_trigrams.size()/2) {
					w = *it;
					suggestions.push_back(w.get_word());
					cout << "Added a suggestion." << endl;
				}
			}
		}		
	}
	
}

void Dictionary::rank_suggestions(vector<string> suggestions, const string& input) const {
	sort(suggestions.begin(), suggestions.end(), 
		[input, this](string a, string b) {
			return this->edit_distance(a, input) < this->edit_distance(b, input);
		}); 
}

unsigned int Dictionary::edit_distance(const string& s1, const string& s2) const {
	const std::size_t len1 = s1.size(), len2 = s2.size();
	vector<vector<unsigned int>> d(len1 + 1, vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j)
                      // note that std::min({arg1, arg2, arg3}) works only in C++11,
                      // for C++98 use std::min(std::min(arg1, arg2), arg3)
                      d[i][j] = std::min({ d[i - 1][j] + 1, 
				      d[i][j - 1] + 1, 
				      d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
	return d[len1][len2];
}

void Dictionary::trim_suggestions(vector<string> suggestions) const {
	if (suggestions.size() > 5) {
		suggestions.resize(5);
	}
}

