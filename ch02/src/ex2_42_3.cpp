#include <iostream>
#include "Sales_data.h"
int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // Read in first three values as members of sum
    std::cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    // Read in next three values as members of item while there is data
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        if (item.bookNo == sum.bookNo) {  // check that bookNo's match
            sum.units_sold += item.units_sold;
            sum.revenue += item.revenue;
        } else {  // print error message if bookNo's don't match
            std::cerr << "Data must refer to same bookNo" << std::endl;
            return -1;  // indicate failure
        }
    } // end while loop
    // Print sum of transactions
    std::cout << sum.bookNo << " " << sum.units_sold << " "
              << sum.revenue << " " << std::endl;
    return 0;
}
