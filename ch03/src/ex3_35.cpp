/* This program sets the elements in an array to zero using pointers */
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
    int ia[10];                     // initialize array with undefined elements
    cout << "Initial values of the elements of ia: \n";
    for (int &ri : ia)
        cout << ri << " ";          // print all elements of ia
    cout << endl;
    int *p = begin(ia);             // initialize pointer with the first element of ia
    while (p != end(ia)) *p++ = 0;  // change all elements of ia to 0
    cout << "New values of the elements of ia: \n";
    for (int &ri : ia)
        cout << ri << " ";          // print all elements of ia
    cout << endl;
    return 0;
}
