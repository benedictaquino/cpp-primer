#include <iostream>
#include "../include/Sales_data.h"

using std::cin; using std::cout; using std::endl;

int main()
{
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        total.revenue *= total.units_sold;
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // if we're still processing the same book
            trans.revenue *= trans.units_sold;
            if (total.isbn() == trans.isbn()) 
                total.combine(trans); // update the running total
            else { // print the results for the previous books
                cout << total.bookNo << " "
                     << total.units_sold << " "
                     << total.revenue << " "
                     << total.revenue / total.units_sold << "\n";
                total = trans;
            }
        }
        // print the last transaction
        cout << total.bookNo << " "
             << total.units_sold << " "
             << total.revenue << " "
             << total.revenue / total.units_sold << endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
