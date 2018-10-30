/* This program uses a traditional for loop to replace all characters in a 
 * string with 'X' */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;  // initialize empty string s
    cin >> s;  // read string from standard input into s
    for (int i = 0; i < s.size(); i++) 
        s[i] = 'X';  // replace character in position i with 'X'
    cout << s << endl;
    return 0;
}
