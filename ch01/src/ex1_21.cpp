/* This program reads two Sales_item objects with the same ISBN and produces 
 * their sum */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // check that item1 and item2 have the same ISBN
    if (item1.isbn() == item2.isbn()) {
	std::cout << item1 + item2 << std::endl;
	return 0;
    }
    else {
	std::cerr << "Data must refer to same ISBN" << std::endl;
	return -1;
    }
}
