/* This program prints the size and contents of the vectors from exercise 3.13 */
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
    // initialive vector of integer vectors to iterate through
    vector<vector<int>> vvi{v1, v2, v3, v4, v5};
    // initialize string vectors
    vector<string> v6{10}, v7{10, "hi"};
    // initialize vector of strings to iterate through
    vector<vector<string>> vvs{v6, v7};
    int i = 0;
    for (auto &rvi : vvi) {
        cout << "v" << ++i << " has " << rvi.size() << " elements:\n";
        for (auto &ri : rvi)
            cout << ri << " ";
        cout << endl;
    }
    for (auto &rvs : vvs) {
        cout << "v" << ++i << " has " << rvs.size() << " elements:\n";
        for (auto &rs : rvs)
            cout << rs << " ";
        cout << endl;
    }
    return 0;
}
