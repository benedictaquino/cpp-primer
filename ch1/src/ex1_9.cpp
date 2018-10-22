// This program uses a while loop to sum the numbers from 50 to 100
#include <iostream>
int main()
{
    int sum = 0, i = 50;
    // keep executing the while as long as i is less than or equal to 100
    while (i <= 100) {
	sum += i;
	i++;
    }
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}
