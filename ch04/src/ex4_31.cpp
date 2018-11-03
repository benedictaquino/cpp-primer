#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> ivec(10);
    // Original program
    vector<int>::size_type cnt = ivec.size();
    // assign values from size...1 to the elements in ivec
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    // print elements
    cout << "Elements of the vector in the original program\n";
    for (int &i : ivec) cout << i << " "; cout << endl;

    // Modified program with postfix increment operators
    cnt = ivec.size();
    // assign values from size...1 to the elements in ivec
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    // print elements
    cout << "Elements of the vector in the modified program\n";
    for (int &i : ivec) cout << i << " "; cout << endl;
 
    return 0;
}
