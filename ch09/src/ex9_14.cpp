/* Exercise 9.14
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program assigns the elements of a list of char* pointers
 * to C-style character strings to a vector of strings */

#include <iostream>
#include <list>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::list;
using std::vector;
using std::string;

int main()
{
    // list of char* pointers to C-style strings
    list<const char*> clst{"You", "know,", "I'm", "something", "of", "a",
                           "scientist", "myself."};
    for (auto &c : clst) cout << c << " "; // print elements of list
    cout << endl;
    vector<string> svec;                   // vector of strings
    svec.assign(clst.begin(), clst.end()); // assign elements of list to vector
    for (auto &s : svec) cout << s << " "; // print elements of vector
    cout << endl;
    return 0;
}
