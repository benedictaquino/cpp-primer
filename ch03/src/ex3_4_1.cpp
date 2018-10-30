/* This program reads two strings and reports whether the strings are equal.
 * If not, the program reports which of the two is larger. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;
int main()
{
    string s1, s2;    // initialize two empty strings
    cin >> s1 >> s2;  // read in two strings from standard input
    if (s1 == s2)     // check if strings are equal
        cout << "\"" << s1 << "\" and \"" << s2 << "\" are equal." << endl;
    else {
        if (s1 > s2)  // check if s1 is greater than s2
            cout << "\"" << s1 << "\" is greater than \"" << s2 << "\"" << endl;
        else
            cout << "\"" << s2 << "\" is greater than \"" << s1 << "\"" << endl;
    }
    return 0;
}
