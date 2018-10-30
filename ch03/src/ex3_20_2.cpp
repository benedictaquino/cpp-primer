/* This program reads a set of integers into a vector. It then prints the sum
 * of the first and last elements, followed by the sum of the second and
 * second-to-last, and so on. */
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer
    while (cin >> i)  // read integers from standard output
        ivec.push_back(i);  // append i to ivec
    // print sums
    for (int j = 0; j < ivec.size() / 2; j++)
        cout << ivec[j] + ivec[ivec.size() - (j + 1)] << " ";
    // if there are an odd number of elements, then print the middle number
    if (ivec.size() % 2 != 0)
        cout << ivec[ivec.size() / 2] << endl;
    else
        cout << endl;
    return 0;
}
