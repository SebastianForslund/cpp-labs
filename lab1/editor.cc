#include "editor.h"
#include <iostream>
#include <string>

using std::string;
using size_type = Editor::size_type;
using std::cout;
using std::endl;


size_type Editor::get_size() const
{
    return text.size();
}

bool isInvalidInput(char x) {
	return !(x == ')' || x == '}' || x == ']'); 
}

char getCorrespondingParenthesis(char input) {
	char test = input;
	switch(test) {
	case '}':
		return '{';
		break;
	case ')':
		return '(';
		break;
	case ']':
		return '[';
		break;
	default:
		return 'x';
	}
}

size_type Editor::find_left_par(size_type pos) const {
	cout << endl << endl;
	auto currentCharPtr = &text[pos];
	auto startPtr = &text[0];
	cout << "Char entered: " << *currentCharPtr << endl;
	char correspondingParenthesis = getCorrespondingParenthesis(*currentCharPtr);
	cout << "Char to look for: " << correspondingParenthesis << endl;
	
	if (isInvalidInput(text[pos])) {
		cout << "Invalid input!" << endl;
		return string::npos;
	}
	cout << "Input is valid!" << endl;

	int leftParaCount = 0;
	int sameChar = 0;
	for(const char* ptr = &text[pos]; ptr != &text[0]; --ptr) {
		if (*ptr == *currentCharPtr) {
			sameChar++;
		}
		if (*ptr == correspondingParenthesis) {
			leftParaCount++;
		}
		if (sameChar == leftParaCount) {
			//Parenthesis found!
			cout << *ptr;
			return ptr - startPtr;
		}
		cout << *ptr;
	}

	return string::npos;
}
