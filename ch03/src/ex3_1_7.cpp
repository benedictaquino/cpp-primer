/* This program reads several transactions and counts how many transactions
 * occur for each bookNo */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    // Define Sales_data objects
    Sales_data currItem, item;
    // Read in first transaction and ensure there is data to process
    if (cin >> currItem.bookNo >> currItem.units_sold >> currItem.revenue) {
        int cnt = 1;  // store the count for the current item
        // Read the remaining transactions
        while (cin >> item.bookNo >> item.units_sold >> item.revenue) {
            if (item.bookNo == currItem.bookNo)  // check if the bookNo's are the same
                ++cnt;  // iterate count
            else {  // otherwise, print the count for the previous value
                cout << "There were " << cnt << " transactions for book number "
                     << currItem.bookNo << endl;
                currItem = item;  // assign item to currItem
                cnt = 1;          // reset count
            }
        }  // end while loop
        // Print data from last bookNo
        cout << "There were " << cnt << " transactions for book number "
             << currItem.bookNo << endl;
    } else {  // print error message if there is no data
        cerr << "No Data?!" << endl;
        return -1;  // indicate failure
    }
    return 0;
}
