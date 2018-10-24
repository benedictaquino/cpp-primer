/* This program prompts the user for two integers then prints each number in 
 * the range specified by those two integers */
#include <iostream>
int main()
{
    std::cout << "Enter two integers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    while (v1 <= v2) {
	std::cout << v1 << " ";
	v1++;
    }
    std::cout << std::endl;
    return 0;
}
