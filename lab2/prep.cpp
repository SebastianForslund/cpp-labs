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
	char x[32];
	int lineCount = 0;
	while (inStream.getline(x, 32)) {
		string newX = "";
		int length = 0;
		while (x[length] != '\0') {
			newX+=x[length];
			length++;
		}
		if (length > 2) {
			int trigramCount = length-2; //Includes the 0.
			newX += ' ';
			newX += std::to_string(trigramCount);
			
			string output = "";
			vector<string> names;
			for (int i=0; i < trigramCount; i++) {
				output = {x[i], x[i+1], x[i+2]};
				names.push_back(output);
			}
			
			std::sort(names.begin(), names.end(), [](string a, string b) {
				return a<b;
			});
			
			for (auto it = names.begin(); it != names.end(); ++it) {
				newX += ' ' + *it;	
			}
			
			newX += '\n';
			std::for_each(newX.begin(), newX.end(), [](char & c) {
				c = tolower(c);
			});

			if (!newX.find("Å") || !newX.find("é") || !newX.find("'")) { // "'" doesn't work for some reason
				newX = "";
			}
			lineCount++;
			cout << newX << "linecount: " << lineCount << endl;
			outStream << newX;
		}
	}
	return 0;	
}
