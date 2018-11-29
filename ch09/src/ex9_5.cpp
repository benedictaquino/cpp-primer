/* Exercise 9.5
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program takes a pair of iterators to a vector<int> and
 * an int value. It looks for the int value in the range and returns an
 * iterator to the value if it is found, otherwise it returns the second
 * iterator. */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

vector<int>::iterator findInt(vector<int>::iterator iter1, 
                              const vector<int>::iterator &iter2, 
                              int i)
{
    while (iter1 != iter2) {
        if (*iter1 == i) return iter1;
        ++iter1;
    }
    return iter2;
}

int main()
{
    cout << "Enter integers: ";
    vector<int> ivec;
    int i;
    while (cin >> i) ivec.push_back(i);
    cout << "Search vector for: ";
    cin.clear();
    int j;
    cin >> j;
    if (*findInt(ivec.begin(), ivec.end(), j) == j)
        cout << "Found " << j << " inside the vector." << endl;
    else
        cout << j << " not found inside the vector." << endl;
    return 0;
}
