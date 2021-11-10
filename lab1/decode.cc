#include <iostream>
#include <fstream>
#include <string>

#include "coding.h"

using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;

int main(int argc, char** argv) {
	
	string inputFilePath {argv[1]};
	string outputFilePath {argv[2]};

	ifstream myFile {inputFilePath};
	ofstream myFileDec {outputFilePath};
	
	if (myFile.is_open() && myFileDec.is_open()) {
		char x;
		while (myFile.get(x)) {
			myFileDec.put(decode(x));
		}
	} else {
		cout << "Could not open file." << endl;
		return 1;
	}
	return 0;
}
