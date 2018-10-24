// This program prints the numbers from 10 down to zero
#include <iostream>
int main()
{
    int i = 10;
    while (i >= 0) {
	std::cout << i << " ";
	i--;
    }
    std::cout << std::endl;
    return 0;
}
