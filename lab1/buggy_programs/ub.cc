#include <iostream>
#include <vector>
#include <cassert>
#include <numeric>
using std::cout;
using std::endl;

std::vector<int> create_vector(int s)
{
    assert(s >= 0);
    std::vector<int> res(s);
}

template <typename C>
void print_seq(const C& c)
{
    for(const auto& x : c) cout << x << " ";
    cout << "\n";
}

void example()
{
    auto v = create_vector(10);
    std::iota(begin(v), end(v), 0);
    print_seq(v);
}

int main()
{
    example();
}
