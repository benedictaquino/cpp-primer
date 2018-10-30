/* This program uses a range for to change all the characters in a string to X */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;  // initialize empty string s
    cin >> s;  // read string from standard input to s
    for (auto &c : s)  // for every char c in string s
        c = 'X';       // assign the value 'X' to char in s
    cout << s << endl;
    return 0;
}
