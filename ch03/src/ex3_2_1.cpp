/* This program reads the standard input a line at a time */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;
int main()
{
    string line;                // initialize empty string
    while (getline(cin, line))  // read line from standard input
        cout << line << endl;   // print line to standard output
    return 0;
}
