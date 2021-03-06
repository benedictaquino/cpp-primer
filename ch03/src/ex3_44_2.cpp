/* This program prints the elements of a multidimensional array */
#include <iostream>

using std::cin; using std::cout; using std::endl;
using int_array = int[4];

int main()
{
    // Initialize 2-dimensional array
    int ia[3][4] = {     // three elements; each element is an array of size 4
        {0, 1, 2, 3},    // initializers for the row indexed by 0
        {4, 5, 6, 7},    // initializers for the row indexed by 1
        {8, 9, 10, 11}   // initializers for the row indexed by 2
    };
    for (int m = 0; m != 3; m++) {
        for (int n = 0; n !=4; n++)
            cout << ia[m][n] << " ";
        cout << endl;
    }
    return 0;
}
