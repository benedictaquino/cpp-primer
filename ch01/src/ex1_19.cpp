/* This program prompts the user for two intergers then prints each number in 
 * the range specified by those two integers */
#include <iostream>
int main()
{
    std::cout << "Enter two integers: " << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v1 <= v2) {
	for (v1; v1 <= v2; v1++)
	    std::cout << v1 << " ";
    }
    else {
	for (v1; v1 >= v2; v1--)
	    std::cout << v1 << " ";
    }
    std::cout <<std::endl;
    return 0;
}
