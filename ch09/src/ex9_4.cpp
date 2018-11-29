/* Exercise 9.4
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program takes a pair of iterators to a vector<int> and
 * an int value. It looks for the int value in the range and returns a bool 
 * indicating whether or not it was found */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

bool findInt(vector<int>::iterator iter1, const vector<int>::iterator &iter2, int i)
{
    while (iter1 != iter2) {
        if (*iter1 == i) return true;
        ++iter1;
    }
    return false;
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
    if (findInt(ivec.begin(), ivec.end(), j))
        cout << "Found " << j << " inside the vector." << endl;
    else
        cout << j << " not found inside the vector." << endl;
    return 0;
}
