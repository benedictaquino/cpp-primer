/* This program reads several transactions and counts how many transactions
 * occur for each bookNo */
#include <iostream>
#include "Sales_data.h"

int main()
{
    // Define Sales_data objects
    Sales_data currItem, item;
    // read in first transaction and ensure there is data to process
    if (std::cin >> currItem.bookNo >> currItem.units_sold >> currItem.revenue) {
        currItem.revenue *= currItem.units_sold;
        int cnt = 1;    // store the count for the current item
        // read the remaining transactions
        while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) { 
            item.revenue *= item.units_sold;
            if (item.bookNo == currItem.bookNo) // check if the bookNo's are the same
                ++cnt;
            else { // otherwise, print the count for the previous value
                std::cout << "There were " << cnt << " transactions for book number "
                    << currItem.bookNo << std::endl;
                currItem = item; // assign item to currItem
                cnt = 1;         // reset count
            }
        } // while loop ends here
        // Print last bookNo
        std::cout << "There were " << cnt << " transactions for book number " 
            << currItem.bookNo << std::endl;
    }
    return 0;
}
