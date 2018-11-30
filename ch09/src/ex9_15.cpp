/* Exercise 9.15
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program determines whether two vectors of integers are
 * equal */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::istringstream;
using std::string;
using std::vector;

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

int main()
{
    cout << "Enter integers: ";
    vector<int> ivec1 = build_vector();
    cout << "Enter more integers: ";
    vector<int> ivec2 = build_vector();
    if (ivec1 == ivec2)
        cout << "Each element is equal and both vectors have the same size."
             << endl;
    else
        cout << "The vectors are not equal." << endl;
    return 0;
}
