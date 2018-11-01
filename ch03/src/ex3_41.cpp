/* This program initializes a vector from an array of ints */
#include <iostream>
#include <vector>

using std::begin; using std::end;
using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    // Read in integers from standard input and place them in an array
    int size = 10;
    int ia[size];
    for (int *p = begin(ia); p != end(ia); ++p)
        cin >> *p;
    // Print array elements
    cout << "Elements of the array:\n";
    for (int i : ia)
        cout << i << " ";
    cout << endl;
    // Initialize vector with array
    vector<int> iv(begin(ia), end(ia));
    // Print vector elements
    cout << "Elements of the vector:\n";
    for (int i : iv)
        cout << i << " ";
    cout << endl;
    return 0;
}
