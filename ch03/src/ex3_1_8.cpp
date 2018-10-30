/* This program reads in transactions from standard input, sums the totals for
 * the same bookNos, then prints to standard output. */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    Sales_data total;  // object to hold the data for the next transaction
    // Read the first transaction and ensure there are data to process
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;  // object to hold the running sum
        // Read and process the remaining transactions
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // If we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // Print results for previous book
                cout << total.bookNo << " " << total.units_sold << " "
                     << total.revenue << endl;
                total = trans;  // total now refers to the next book
            }
        }  // end while loop
        cout << total.bookNo << " " << total.units_sold << " " 
             << total.revenue << endl;
    } else {  // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1;  // indicate failure
    }
    return 0;
}
