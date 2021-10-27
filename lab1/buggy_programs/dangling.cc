#include <iostream>
#include <numeric>
using std::cout;

struct Foo{
    Foo(int s) :p(new int[s]), sz(s) {}
    ~Foo() {delete[] p;}
    int* begin() {return p;}
    int* end() {return begin()+sz;}
    const int* begin() const {return p;}
    const int* end() const {return begin()+sz;}
    int* p;
    int sz;
};

void print(Foo f)
{
    for(const auto& x : f) cout << x << " ";
    endl(cout);
}
void example1()
{
    Foo f(10);
    std::iota(std::begin(f), std::end(f), 0);

    print(f);
    cout << "after first print\n";
    *f.begin()=123;
    cout << "printing again\n";
    print(f);
    cout << "done\n";
}

int main()
{
    example1();
}
