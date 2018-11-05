#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::noskipws;
using std::vector;

int main()
{
    vector<int> v1, v2;
    char c;
    int i;
    while (cin >> noskipws >> c) {
        if (isspace(c)) break;
        else {
            i = c - '0';
            v1.push_back(i);
        }
    }
    while (cin >> noskipws >> c) {
        i = c - '0';
        v2.push_back(i);
    }
    size_t smallSz = (v1.size() < v2.size()) ? v1.size() : v2.size();
    bool prefix = 1;
    for (size_t ix = 0; ix != smallSz; ++ix) 
        if (v1[ix] != v2[ix]) prefix = 0;
    return prefix;
}
