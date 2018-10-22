/* This program reads a set of book sales transactions, writing each 
 * transaction to the standard output */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item;
    while (std::cin >> item)
	std::cout << item << std::endl;
    return 0;
}
