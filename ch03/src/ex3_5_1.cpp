/* This program reads strings from the standard input, concatenating what is
 * read into one large string. Then it prints the concatenated string */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string concat, s;  // initialize empty strings
    while (cin >> s)   // read from standard input
        concat += s;   // concatenate into one long string
    cout << concat << endl;
    return 0;
}
