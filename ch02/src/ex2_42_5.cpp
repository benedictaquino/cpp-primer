#include <iostream>
#include "Sales_data.h"
int main()
{
    Sales_data total;  // object to hold the data for the next transaction
    // Read the first transaction and ensure there are data to process
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;  // object to hold the running sum
        // Read and process the remaining transactions
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // If we are still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else { // otherwise, print the results for the previous book
                std::cout << total.bookNo << " " << total.units_sold << " "
                          << total.revenue << std::endl;
                total = trans;   // total now refers to the next book
            }
        }
        // Print the values of total
        std::cout << total.bookNo << " " << total.units_sold << " " 
                  << total.revenue << " " << std::endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" << std::endl;
        return -1;  // indicate failure
    }
    return 0;
}
