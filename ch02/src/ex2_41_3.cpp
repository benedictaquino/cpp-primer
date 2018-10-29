/* This program reads several transactions for the same ISBN and writes the sum
 * of all the transactions that were read */
#include <iostream>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // read in first values as members of sum
    std::cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    // read in input as members of item
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
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
              << sum.revenue 
              << std::endl;
    return 0;
}
