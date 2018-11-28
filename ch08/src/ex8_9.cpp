/* Exercise 8.9
 * Author: Benedict Aquino
 * Date: 2018-11-29 
 * Description: This program prints the contents of an istringstream object */ 

#include <iostream>
#include <string>
#include <sstream>

using std::cin; using std::cout; using std::endl; using std::istream;
using std::string;
using std::istringstream;

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

int main()
{
    string str;
    getline(cin, str);
    istringstream instring(str);
    read_stream(instring);
    return 0;
}
