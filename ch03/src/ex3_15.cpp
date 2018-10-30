/* This program reads a sequence of strings from cin and stores the values in a vector */
#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> svec;  // initialize empty string vector
    string s;             // initialize empty string
    while (cin >> s)  // read strings from standard input into s
        svec.push_back(s);  // append s to svec
    for (auto &rs : svec)
        cout << rs << endl;  // read elements of svec to standard output
    return 0;
}
