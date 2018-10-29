#include <iostream>
#include "Sales_data.h"
int main()
{
    // Define a Sales_data object item
    Sales_data item;
    // While there is data to process, print to standard output
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue)
        std::cout << item.bookNo << " " 
                  << item.units_sold << " "
                  << item.revenue << std::endl;
    return 0;
}
