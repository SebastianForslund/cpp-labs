#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "coding.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main(int argc, char**argv) {

	std::string inputFilePath {argv[1]};
	std::string outputFilePath {argv[2]};

	cout << "Filepath is: " << inputFilePath << endl;	
	
	ifstream myFile {inputFilePath};
	ofstream myFileEnc {outputFilePath};

	if (myFile.is_open() && myFileEnc.is_open()) {
		char x;
		while (myFile.get(x)) {
			myFileEnc.put(encode(x));
		}

	} else {
		cout << "rip, can't open file" << endl;
		cout << "Input file path: " << inputFilePath <<endl;
		cout << "Output file path: " << outputFilePath << endl;
		return 1;
	}
	return 0;
}
