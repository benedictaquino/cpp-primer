/* This program compares two arrays for equality */
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
    int ia1[10], ia2[10];  // initialize arrays with 10 undefined elements

    // print values of elements of arrays ia1 and ia2
    cout << "Values of the elements of ia1: \n";
    for (int &ri : ia1) cout << ri << " ";
    cout << "\nValues of the elements of ia2: \n";
    for (int &ri : ia2) cout << ri << " ";
    cout << endl;

    // compare two arrays for equality
    bool equal = 1;
    for (int ix = 0; ix != 10; ix++) {
        if (ia1[ix] != ia2[ix]) equal = 0;
    }
    if (equal) cout << "The two arrays are equal." << endl;
    else cout << "The two arrays are not equal." << endl;
    return 0;
}
