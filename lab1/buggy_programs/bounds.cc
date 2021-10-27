#include <iostream>
#include <numeric>
using std::cout;


void print(int* a, int size)
{
    for(int i=0; i < size; ++i){
        cout << a[i] << " ";
    }
    cout << "\n";
}

void example()
{
    int xs[10];
    std::iota(xs, xs+10, 0);
    print(xs, 15);
}

int main()
{
    example();
}
