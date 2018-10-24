// This program prints the sum of a set of integers read from cin
#include <iostream>
int main()
{
    int sum = 0, val;
    while (std::cin >> val) 
	sum += val;
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
