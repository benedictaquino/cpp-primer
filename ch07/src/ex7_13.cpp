#include <iostream>
#include "../include/Sales_data.h"

using std::cin; using std::cout; using std::endl; using std::cerr;

int main()
{
    Sales_data total(cin);       // variable to hold the running sum
    if (cin) {                   // read the first transaction
        Sales_data trans(cin);   // variable to hold data for the next transaction
        while (cin) {            // read the remaining transactions
            if (total.isbn() == trans.isbn()) // check the isbns
                total.combine(trans);         // update the running total
            else {
                print(cout, total) << endl;   // print the results
                total = trans;                // process the next book
            }
            read(cin, trans);
        }
        print (cout, total) << endl;   // print the last transaction
    } else {                           // there was no input
        cerr << "No data ?!" << endl; // notify the user
        return -1;                     // indicate failure
    }
    return 0;
}
