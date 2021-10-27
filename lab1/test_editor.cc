#include "editor.h"

#include <iostream>

void test_equals(Editor::size_type x, Editor::size_type y)
{
    if(x != y) {
        std::cout << "Wrong result: " << x << " != " << y << std::endl;
    };
}
int main() {
	Editor ed("...(...(...[...]...)...)...{...}...");

    std::cout << "editor.size(): " << ed.get_size() << std::endl;

	test_equals( ed.find_left_par(15), 11);
	test_equals( ed.find_left_par(19), 7);
	test_equals( ed.find_left_par(23), 3);
	test_equals( ed.find_left_par(31), 27);
	test_equals( ed.find_left_par(32), std::string::npos);
    std::cout << "test done." << std::endl;
}
