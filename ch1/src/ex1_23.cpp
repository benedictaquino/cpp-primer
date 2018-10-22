/* This program reads several transactions and counts how many transactions 
 * occur for each ISBN */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item currItem, item;
    // read in first transaction and ensure there is data to process
    if (std::cin >> currItem) {
	int cnt = 1;    // store the count for the current item
	while (std::cin >> item) {              // read the remaining numbers
	    if (item.isbn() == currItem.isbn()) // if the ISBNs are the same
		++cnt;                          // add 1 to cnt
	    else { // otherwise, print the count for the previous value
		std::cout << "There were " << cnt << " transactions for ISBN "
		          << currItem.isbn() << std::endl;
		currItem = item;
		cnt = 1;
	    }
	} // while loop ends here
	std::cout << "There were " << cnt << " transactions for ISBN "
	          << currItem.isbn() << std::endl;
    } // outermost if statement ends here
    return 0;
}
