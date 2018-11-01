/* This program compares two strings */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string s1, s2;  // initialize two empty strings
    cout << "Enter first string:" << endl;
    getline(cin, s1);
    cout << "Enter second string:" << endl;
    getline(cin, s2);
    // check equality of strings
    if (s1 == s2) 
        cout << "The two strings are equal." << endl;
    else if (s1.size() == s2.size()) 
        cout << "The two strings are equal length." << endl;
    else if (s1.size() > s2.size())
        cout << "The first string is longer than the second string." << endl;
    else if (s1.size() < s2.size()) 
        cout << "The first string is shorter than the second string." << endl;
    return 0;
}
