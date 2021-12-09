#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "TagRemover.h"


using namespace std;




int main() {
	/*
	ofstream outputStream;
	outputStream.open("TagRemoverOutput.html");
	
	ifstream inputStream;
	inputStream.open("test.html");
	*/
	
	ostringstream outputStream;
	
	string in = "This is a line without a tag\nThis is <tag tag> a line with one tag\nAnd this <tag> line has two tags <...>\nA line with a starting tag < ..... continues\n... we're still in a tag ...\n... finishes> which finished on this line <last tag>\nSpecial chars: &lt;&gt;&nbsp;&amp;";
	istringstream inputStream(in);
	
	TagRemover t;

	t.tr(inputStream);
	t.print(outputStream);
	
	string supposedOutput = "This is a line without a tag\nThis is  a line with one tag\nAnd this  line has two tags \nA line with a starting tag \n\n which finished on this line \nSpecial chars: ";
	
	cout << "Output from function: \n" << outputStream.str() << endl << "------------------" << endl;
	cout << "Supposed output: \n" << supposedOutput << endl << "------------------" << endl;
	
	cout << "Comparing the two strings: " << outputStream.str().compare(supposedOutput) << endl;
	
	
	return 0;
}
