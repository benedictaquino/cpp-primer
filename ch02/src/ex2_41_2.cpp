/* This program reads two Sales_data objects with the same ISBN and produces
 * their sum */
#include <iostream>
struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main()
{
    // Define two Sales_data objects
    Sales_data item1, item2;
    // Read in data from standard input
    std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue
             >> item2.bookNo >> item2.units_sold >> item2.revenue;
    // check that item1 and item2 have the same ISBN
    if (item1.bookNo == item2.bookNo) {
        std::cout << item1.bookNo << " "
                  << item1.units_sold + item2.units_sold << " "
                  << item1.revenue + item2.revenue << " "
                  << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to the same ISBN" << std::endl;
        return -1;
    }
}
