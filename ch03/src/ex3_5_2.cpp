/* This program reads strings from the standard input, concatenating what is
 * read into onge large string, separating adjacent input strings by a space.
 * Then it prints the string to the standard output */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string concat, s;        // initialize empty strings
    cin >> concat;           // read first string to concat
    while (cin >> s)         // read from standard input
        concat += " " + s;   // concatenate strings with whitespace between
    cout << concat << endl;  // print to standard output
    return 0;
}
