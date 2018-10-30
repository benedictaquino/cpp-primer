/* This program reads a sequence of ints from cin and stores the values in a vector */
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;  // initialize empty int vector
    int i;             // initialize integer i
    while (cin >> i) // read integers from standard input into i
        ivec.push_back(i);  // append i to ivec
    for (auto &ri : ivec)
        cout << ri << endl;  // read elements of ivec to standard output
    return 0;
}
