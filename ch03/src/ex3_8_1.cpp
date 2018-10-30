/* This program uses a while loop to replace all characters in a string with 'X' */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;   // initialize empty string s
    cin >> s;   // read string from standard input into s
    int i = 0;  // initialize iterator
    while (i < s.size()) {  // while i is less than the length of s
        s[i] = 'X';  // replace character in position i with 'X'
        i++;         // increment i by 1
    }  // end while loop
    cout << s << endl;  // print string to standard output
    return 0;
}
