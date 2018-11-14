/* This program reads several transactions for the same ISBN and writes the sum
 * of all the transactions that were read */
#include <iostream>
#include "Sales_data.h"

int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // read in first values as members of sum
    std::cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    sum.revenue *= sum.units_sold;
    // read in input as members of item
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        item.revenue *= item.units_sold;
        if (item.bookNo == sum.bookNo) {  // check that bookNo's match
            sum.units_sold += item.units_sold;
            sum.revenue += item.revenue;
        } else {  // print error message if bookNo's do not match
            std::cerr << "Data must refer to same bookNo" << std::endl;
            return -1;
        }
    } // end while loop
    std::cout << sum.bookNo << " " 
              << sum.units_sold << " " 
              << sum.revenue  << " "
              << sum.revenue / sum.units_sold
              << std::endl;
    return 0;
}
