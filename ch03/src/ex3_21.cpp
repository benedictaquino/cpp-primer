/* this program prints the size and contents of the vectors from exercise 3.13 */
#include <iostream>
#include <string>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;

int main()
{
    // initialize integer vectors
    vector<int> v1, v2(10), v3(10, 42), v4{10}, v5{10, 42};
    // initialize vector of integer vector pointers to iterate through
    vector<vector<int>*> vvi{&v1, &v2, &v3, &v4, &v5};
    // initialize string vectors
    vector<string> v6{10}, v7{10, "hi"};
    // initialize vector of string vector pointers to iterate through
    vector<vector<string>*> vvs{&v6, &v7};
    int i = 0;  // initialize counter
    for (auto it = vvi.begin(); it != vvi.end(); ++it) {
        cout << "v" << ++i << " has " << (*it)->size() << " elements:\n";
        for (auto it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    }
    for (auto it = vvs.begin(); it != vvs.end(); ++it) {
        cout << "v" << ++i << " has " << (*it)->size() << " elements:\n";
        for (auto it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    }
    return 0;
}
