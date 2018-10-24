/* This program reads several transactions for the same ISBN and writes the sum
 * of all the transactions that were read */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item sum, item;
    // read in first value as sum
    std::cin >> sum;
    // read in inputs as item
    while(std::cin >> item) {
	if (item.isbn() == sum.isbn()) {   // check that ISBN's match
	    sum += item;                   // add item to sum
	}
	else {
	    // Print error message
	    std::cerr << "Data must refer to same ISBN" << std::endl;
	    return -1;                     // indicate failure
	}
    } // end while loop
    std::cout << sum << std::endl;
    return 0;
}
