#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;
using std::unordered_set;
using std::endl;
using std::cout;
using std::ifstream;
using std::sort;
using std::stringstream;

Dictionary::Dictionary() {
	ifstream inputStream;
	inputStream.open("wordsOut.txt");
	//this.max_characters = 25; change it in the header file
	int wordCount = 0;
	string in = "";
	vector<string> trigrams;
	while (std::getline(inputStream, in, '\n')){
		string item = "";
		stringstream ss(in);
		string currentWord;
		int ignoreCount = 2;
		vector<string> trigVector;
		
		while (std::getline(ss, item, ' ')) {
			if (ignoreCount == 2) {
				currentWord = item;
			} 
			if (ignoreCount != 0) {
				ignoreCount--;
			} else {
				trigVector.push_back(item);
			}
		}
		wordCount++;
		Word w(currentWord, trigVector);
		this->words[currentWord.size()].push_back(w);
		this->allWords.insert(currentWord);
		cout << "word number " << wordCount << " out of approx. 102 199." << endl;
	}
	cout << "Dictionary load compelted." << endl;
}

bool Dictionary::contains(const string& word) const {
	if (allWords.find(word) == allWords.end()) {
		return false;
	} else {
		return true;
	}
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	/*
	cout << "Showing raw suggestions: " << endl;
	for (auto it = suggestions.begin(); it != suggestions.end(); ++it) {
		cout  << *it << endl;
	}
	*/
	rank_suggestions(suggestions, word);
	/*
	cout << "Showing ranked suggestions: " << endl;
	for (auto it = suggestions.begin(); it != suggestions.end(); ++it) {
		cout  << *it << endl;
	}
	*/
	trim_suggestions(suggestions);
	/*
	cout << "Showing trimmed suggestions: " << endl;
	for (auto it = suggestions.begin(); it != suggestions.end(); ++it) {
		cout  << *it << endl;
	}
	*/
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& input) const {
	vector<string> input_trigrams;
	if (input.size() > 2) {
		for (auto it = input.begin(); it != input.end()-2; ++it) { //Finds all trigrams
			string trig = {*it, *(it+1), *(it+2)};
			input_trigrams.push_back(trig); //Går det att göra detta i en rad?
		}
	}
	sort(input_trigrams.begin(), input_trigrams.end()); //The trigram vector is now alphabetically sorted.
	Word baba("word", input_trigrams);

	if (input.size() > 0 && input.size() < this->max_characters) {
		cout << "Word length: " << input.size() << endl;
		cout << "There are " << this->words[input.size()].size() << " words of this length in the dictionary: " << endl;
		for (int i = -1; i < 2; ++i) { //Checks words of similar length
			vector<Word> words_vector = this->words[input.size() + i]; //Gets the words of the current length.
			
			for (auto it = words_vector.begin(); it != words_vector.end(); ++it) {
				Word w = *it;
				int matches = w.get_matches(input_trigrams);
				if (matches >= input_trigrams.size()/2) { //Add as a suggestion if more than half of tris are matches.
					w = *it;
					suggestions.push_back(w.get_word());
				}
			}
		}		
	} else {
		cout << "ERROR: This input exceeds the maximum length of inputs! (or is empty)" << endl;
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& input) const {
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

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	if (suggestions.size() > 5) {
		suggestions.resize(5);
	}
}

