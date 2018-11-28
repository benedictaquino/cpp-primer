/* Exercise 8.8
 * Author: Benedict Aquino
 * Date: 2018-11-28
 * Description: This program reads book store transactions from a file,
 * combines transactions of the same type, then appends the sum of the 
 * transactions to a file*/

#include <iostream>
#include <fstream>
#include "../include/Sales_data.h"

using std::endl; using std::cerr;
using std::ifstream; using std::ofstream;

int main(int argc, char *argv[])
{
    if (!argv[1] || !argv[2]) { // check if two filenames were passed in
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    ifstream infile(argv[1]);
    ofstream outfile(argv[2], ofstream::app);
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
            } else { // write the results for the previous books
                print(outfile, total);
                total = trans; // total now refers to the next book
            }
        }
        // write the last transaction
        print(outfile, total);
    } else { // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
