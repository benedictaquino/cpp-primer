/* This program reads a set of integers into a vector. It then prints the sum
 * of each pair of adjacent elements */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer
    while (cin >> i)  // read integers from standard input
        ivec.push_back(i);  // append i to ivec
    // print the sum of the adjacent elements
    for (auto it = ivec.cbegin(); it != ivec.cend(); it += 2)
        cout << *it + *(it + 1) << " ";
    cout << endl;
    return 0;
}
