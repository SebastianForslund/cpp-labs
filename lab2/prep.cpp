#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::vector;

int main(int argc, char**args) {
	string fileTo = args[1];
	string wordsFile = "words";
	
	ofstream outStream {fileTo};
	ifstream inStream {wordsFile};
	string inputWord;
	int lineCount = 0;
	while (std::getline(inStream, inputWord)) {
		int length = inputWord.length();
		if (length > 2) {
			int trigramCount = length-2; //Includes the 0.
			inputWord += ' ';
			inputWord += std::to_string(trigramCount);
			
			string output = "";
			vector<string> trigrams;
			for (int i=0; i < trigramCount; i++) {
				output = {inputWord[i], inputWord[i+1], inputWord[i+2]};
				trigrams.push_back(output);
			}
			
			std::sort(trigrams.begin(), trigrams.end(), [](string a, string b) {
				return a<b;
			});
			
			for (auto it = trigrams.begin(); it != trigrams.end(); ++it) {
				inputWord += ' ' + *it;	
			}
			
			inputWord += '\n';
			std::for_each(inputWord.begin(), inputWord.end(), [](char & c) {
				c = tolower(c);
			});

			if (!inputWord.find("Å") || !inputWord.find("é") || !inputWord.find("'")) { 
				// "'" doesn't work for some reason
				inputWord = "";
			}
			lineCount++;
			cout << inputWord << "linecount: " << lineCount << endl;
			outStream << inputWord;
		}
	}
	return 0;	
}
