/* This program copies a vector of ints into an array of ints */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;
using std::vector;

int main()
{
    vector<int> iv;  // initialize empty vector of ints
    int i;  // initialize integer object
    while (cin >> i)  // read values from standard input into i
        iv.push_back(i);  // append i to iv

    // Print elements of the vector
    cout << "Elements of the vector:\n";
    for (int j : iv)
        cout << j << " ";
    cout << endl;

    int ia[iv.size()];  // create an integer array the size of iv
    i = 0;
    for (int j : iv)  // loop through all the values of iv
        ia[i++] = j;  // copy j into ia at position i

    // Print elements of the array
    cout << "Elements of the array:\n";
    for (int j : ia)
        cout << j << " ";
    cout << endl;

    return 0;
}
