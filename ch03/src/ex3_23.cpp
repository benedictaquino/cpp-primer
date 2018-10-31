/* This program creates a vector with ten int elements. Using an iterator, it
 * assigns each element a value that is twice its current value. */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer object

    // prompt user to enter integers
    cout << "Enter integers: " << endl;

    while (cin >> i)  // read in integers from standard input
        ivec.push_back(i);  // append i to ivec

    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it *= 2;  // double the element referenced by it
        cout << *it << " ";
    }
    
    cout << endl;

    return 0;
}
