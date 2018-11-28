/* Exercise 8.6
 * Author: Benedict Aquino
 * Date: 2018-11-27
 * Description: This program reads book store transactions from a file,
 * combines transactions of the same type, then prints the sum of the 
 * transactions to the standard output */

#include <iostream>
#include <fstream>
#include "../include/Sales_data.h"

using std::cout; using std::endl; using std::cerr;
using std::ifstream;

int main(int argc, char *argv[])
{
    if (!argv[1]) { // check if a filename was passed in
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    ifstream infile(argv[1]);
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (read(infile, total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(infile, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn()) {
                // update the running total
                total.combine(trans);
            } else { // print the results for the previous books
                print(cout, total);
                total = trans; // total now refers to the next book
            }
        }
        // print the last transaction
        print(cout, total);
    } else { // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
