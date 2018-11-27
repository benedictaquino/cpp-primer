/* Exercise 8.1
 * Author: Benedict Aquino
 * Date: 2018-11-27 
 * Description: This function takes and returns an istream&. It reads the 
 * stream until it hits end-of-file. The function prints what it reads to
 * the standard output. */

#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::istream;
using std::string;

istream &read_stream(istream &is)
{
    string s;
    is.clear();   // make istream valid
    // while istream is valid, print to standard output
    while (is >> s) cout << s << " ";
    cout << endl; // newline and flush
    is.clear();   // reset istream
    return is;
}
