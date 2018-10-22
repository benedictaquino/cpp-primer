// This program uses a for loop to sum the numbers from 50 to 100
#include <iostream>
int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; i++)
	sum += i;
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}
