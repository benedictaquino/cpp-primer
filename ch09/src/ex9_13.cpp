/* Exercise 9.13
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program tests my solution to exercise 9.13. */
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

int main()
{
    cout << "Enter integers: ";  // prompt user to enter integers
    string line;                 // object to store input
    getline(cin, line);          // read line from standard input
    istringstream iss(line);     // istringstream holding line
    int i;                       // object to hold each integer
    list<int> ilst;              // list to hold the integers
    // read integers from iss into ilst
    while (iss >> i) ilst.push_back(i);
    // print elements of the list
    cout << "Elements of the list:\n";
    for (const auto &j : ilst) cout << j << " ";
    // initialize vector with iterator constructor
    vector<int> ivec(ilst.cbegin(), ilst.cend());
    // print elements of the vector 
    cout << "\n"
         << "Elements of the vector:\n";
    for (const auto &j : ilst) cout << j << " ";
    cout << endl;
    return 0;
}
