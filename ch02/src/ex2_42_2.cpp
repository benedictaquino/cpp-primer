#include <iostream>
#include "Sales_data.h"

int main()
{
    // Define two Sales_data objects
    Sales_data item1, item2;
    // Read in data from standard input
    std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue
             >> item2.bookNo >> item2.units_sold >> item2.revenue;
    item1.revenue *= item1.units_sold;
    item2.revenue *= item2.units_sold;
    // Check that item1 and item2 havethe same bookNo
    if (item1.bookNo == item2.bookNo) {
        // Print sum of two transactions
        unsigned total_units_sold = item1.units_sold + item2.units_sold;
        double total_revenue = item1.revenue + item2.revenue;
        std::cout << item1.bookNo << " "
                  << total_units_sold << " "
                  << total_revenue << " "
                  << total_revenue / total_units_sold << std::endl;
        return 0;
    } else { // otherwise print error message
        std::cerr << "Data must refer to the same bookNo" << std::endl;
        return -1;
    }
}
