/* This program defines an array of ten ints and gives each element the same
 * value as its position in the array. Then it copies the values into another
 * array. */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int ia1[10], ia2[10];  // initialize two integer arrays with dimension 10
    for (int ix = 0; ix != 10; ix++) 
        ia1[ix] = ix + 1;  // give each element the same value as its position
    for (int ix = 0; ix != 10; ix++)
        ia2[ix] = ia1[ix]; // copy the values from ia1 into ia2

    // print elements of array to verify
    for (int ix = 0; ix != 10; ix++) 
        cout << "ia1[" << ix << "] = " << ia1[ix] << "\t"
             << "ia2[" << ix << "] = " << ia2[ix] << endl;
    return 0;
}
