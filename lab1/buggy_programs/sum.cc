#include <iostream>

#define N (4)

int x = 1000;
int	a[]{ 1, 2, 3, 4 };
int y = 2000;

int main()
{
	int	sum{0};

    std::cout << "welcome to the buggy sum program. the sum should be 10\n";

	for (int i = 0; i <= N; i++)
		sum += a[i];

    std::cout << "sum = " << sum << "\n";
	return 0;
}
