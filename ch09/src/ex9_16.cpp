/* Exercise 9.16
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program determines whether two vectors of integers are
 * equal */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>

using std::cin; using std::cout; using std::endl;
using std::istringstream;
using std::string;
using std::vector;
using std::list;

vector<int> build_vector()
{
    string nums;
    getline(cin,nums);
    istringstream iss(nums);
    vector<int> ivec;
    int i;
    while (iss >> i) ivec.push_back(i);
    return ivec;
}

list<int> build_list()
{
    string nums;
    getline(cin,nums);
    istringstream iss(nums);
    list<int> ilst;
    int i;
    while (iss >> i) ilst.push_back(i);
    return ilst;
}

int main()
{
    cout << "Enter integers: ";
    vector<int> iv = build_vector();
    cout << "Enter more integers: ";
    list<int> il = build_list();
    if (iv.size() != il.size()) {
        cout << "The vector and list are not equal." << endl;
        return 0;
    }
    vector<int>::const_iterator ivit = iv.cbegin();
    list<int>::const_iterator ilit = il.cbegin();
    while (ivit != iv.cend() && ilit != il.cend()) {
        if (*ivit != *ilit) {
            cout << "The vector and list are not equal." << endl;
            return 0;
        }
        ++ivit, ++ilit;
    }
    cout << "Each element is equal and the vector and list have the same size."
         << endl;
    return 0;
}
