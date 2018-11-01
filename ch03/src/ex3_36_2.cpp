/* This program compares two vectors for equality */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> iv1(10,42), iv2(10);  // initialize two vectors

    // print values of elements in vectors iv1 and iv2
    cout << "Values of the elements of iv1:\n";
    for (auto &ri : iv1) cout << ri << " ";
    cout << "\nValues of the elements of iv2:\n";
    for (auto &ri : iv2) cout << ri << " ";
    cout << endl;

    // compare vectors for equality
    if (iv1 == iv2) cout << "The two vectors are equal." << endl;
    else cout << "The two vectors are not equal."  << endl;

    return 0;
}
