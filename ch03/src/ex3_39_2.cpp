/* This program compares two C-style strings */
#include <iostream>
#include <cstring>

using std::cin; using std::cout; using std::endl;
using std::strcmp; using std::strlen;

int main()
{
    char ca1[80], ca2[80];
    cout << "Enter first string:" << endl;
    cin.getline(ca1, 80);
    cout << "Enter second string:" << endl;
    cin.getline(ca2, 80);
    // check equality of C-style strings
    if (strcmp(ca1, ca2) == 0)
        cout << "The two strings are equal." << endl;
    else if (strlen(ca1) == strlen(ca2))
        cout << "The two strings are equal length." << endl;
    else if (strlen(ca1) < strlen(ca2))
        cout << "The first string is shorter than the second string." << endl;
    else if (strlen(ca1) > strlen(ca2))
        cout << "The first string is longer than the second string." << endl;
    return 0;
}
