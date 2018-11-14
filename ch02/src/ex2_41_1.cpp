/* This program reads a set of book sales transactions, writing each
 * transaction to the standard output */

#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

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
