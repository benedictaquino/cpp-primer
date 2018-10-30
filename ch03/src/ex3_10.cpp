/* This program reads a string of characters including punctuation and writes
 * what was read but with the punctuation removed. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;   // initialize empty string s 
    cin >> s;   // read string from standard input into s
    int i = 0;  // initialize iterator
    while (i < s.size()) { 
        if (ispunct(s[i]))  // delete character if punctuation
            s.erase(i,1);
        else                // move onto next position if character is not punctuation
            i++;
    }
    cout << s << endl;
    return 0;
}
