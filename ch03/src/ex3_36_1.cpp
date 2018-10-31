/* This program compares two arrays for equality */
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
    int ia1[10], ia2[10];  // initialize arrays with 10 undefined elements

    cout << "Initial values of the elements of ia1: \n";
    for (int &ri : ia1) cout << ri << " ";
    cout << "Initial values of the elements of ia2: \n";
    for (int &ri : ia2) cout << ri << " ";
    cout << endl;
