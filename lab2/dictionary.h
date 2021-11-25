#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "Word.h"

class Dictionary {
public:
	std::unordered_set<std::string> allWords = {};
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	
private:
	static const size_t max_characters = 25;
	std::vector<Word> words[max_characters];
	std::vector<std::string> suggestions;
	
	void add_trigram_suggestions(std::vector<std::string> suggestions, const std::string& input) const;
	void rank_suggestions(std::vector<std::string> suggestions, const std::string& input) const;
	void trim_suggestions(std::vector<std::string> suggestions) const;
	
	unsigned int edit_distance(const std::string& s1, const std::string& s2) const;
};

#endif
