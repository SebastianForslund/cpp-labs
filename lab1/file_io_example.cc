#include"coding.h"
#include<iostream>
#include <iomanip>
#include<fstream>

void print_bytes(std::string infile)
{
    std::ifstream in{infile};

    int c;
    while((c = in.get()) != EOF ) {
        std::cout << "read: " << std::setw(3) << c << " [" << char(c) << "]" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    print_bytes(argv[1]);
    return 0;
}
