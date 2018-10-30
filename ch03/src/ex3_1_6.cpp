/* This program reads several transactions for the same ISBN and writes the sum
 * of all the transactions that were read */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // Read in the first values as members of sum
    cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    // Read in input as members of item
    while (cin >> item.bookNo >> item.units_sold >> item.revenue) {
        if (item.bookNo == sum.bookNo) {  // check that bookNo's match
            sum.units_sold += item.units_sold;
            sum.revenue += item.revenue;
        } else {  // print error message if bookNo's don't match
            cerr << "Data must refer to same bookNo" << endl;
            return -1;  // indicate failure
        }
    }  // end while loop
    // Print sum of transactions
    cout << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << endl;
    return 0;
}
