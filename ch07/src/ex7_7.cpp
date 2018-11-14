#include <iostream>
#include "../include/Sales_data.h"

using std::cin; using std::cout; using std::endl;

int main()
{
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (read(cin, total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(cin, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total = add(total, trans); // update the running total
            else { 
                // print the results for the previous books
                print(cout, total);
                cout << "\n";
                total = trans; // total now refers to the current book
            }
        }
        // print the last transaction
        print(cout, total);
        cout << endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
