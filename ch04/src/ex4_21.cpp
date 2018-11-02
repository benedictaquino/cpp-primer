/* This program uses a conditional operator to find the elements in a
 * vector<int> that have odd value and doubles the value of each such element */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> iv; // initialize empty vector of integers
    int i; // define integer object
    while (cin >> i) iv.push_back(i); // read integers from standard input to iv

    cout << "Elements of the original vector:\n";
    for (auto j : iv) cout << j << " "; cout << endl;

    // Double the odd elements of the vector
    for (auto &r : iv) (r % 2 == 1) ? r *= 2 : r;

    cout << "Elements of the changed vector:\n";
    for (auto j : iv) cout << j << " "; cout << endl;

    return 0;
}
