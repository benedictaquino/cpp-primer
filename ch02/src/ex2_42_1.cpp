/* This program reads a set of book sales transactions, writing each
 * transaction to the standard output */
#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data item;
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        item.revenue *= item.units_sold;
        std::cout << item.bookNo << " " 
                  << item.units_sold << " " 
                  << item.revenue << " "
                  << item.revenue / item.units_sold << std::endl;
    }
    return 0;
}
