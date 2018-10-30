/* This program reads two strings and reports whether the strings have the
 * same length. If not, then it reports which one is longer. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s1, s2;                  // initialize two empty strings
    cin >> s1 >> s2;                // read two strings from standard input
    if (s1.size() == s2.size())     // check if the two strings have the same length
        cout << "\"" << s1 << "\" and \"" << s2 << "\" are the same length" << endl;
    else {
        if (s1.size() > s2.size())  // check if s1 is longer than s2
            cout << "\"" << s1 << "\" is longer than \"" << s2 << "\"" << endl;
        else
            cout << "\"" << s2 << "\" is longer than \"" << s1 << "\"" << endl;
    }
    return 0;
}
