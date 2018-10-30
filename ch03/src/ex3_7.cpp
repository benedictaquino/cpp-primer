/* This program uses a range for to replace all the characters in a string to
 * 'X', but defines the loop control variable */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;           // initialize empty string s
    cin >> s;            // read string from standard input into s
    for (char &c : s)   // for char c in string s
        c = 'X';        // replace char in s with 'X'
    cout << s << endl;  // print s to standard output
    return 0;
}
