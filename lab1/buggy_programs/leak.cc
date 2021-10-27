#include <iostream>
using std::cout;

struct Foo{
    Foo(int s) :p{new int[s]} {}
    int* p;
};

struct Bar{
    Bar(int x) :f(x) {}
    Foo f;
};

void example1()
{
    Foo f(10);
    {
        cout << "entering inner block\n";
        Bar b(20);
        cout << "leaving inner block\n";
    }
    cout << "leaving example1\n";
}

int main()
{
    example1();
    cout << "leaving main\n";
}
