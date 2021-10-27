#include <iostream>
#include <numeric>
#include <memory>
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
    std::unique_ptr<int[]> xs(new int[10]);
    std::iota(xs.get(), xs.get()+10, 0);
    print(xs.get(), 15);
}

int main()
{
    example();
}
