/* This program reads a set of integers into a vector. It then prints the sum
 * of each pair of adjacent elements. */
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer
    while (cin >> i)   // read integers from standard input
        ivec.push_back(i);  // append i to ivec
    // Print the sum of adjacent elements
    for (int j = 0; j < ivec.size(); j += 2) 
        cout << ivec[j] + ivec[j + 1] << endl;
    return 0;
}
