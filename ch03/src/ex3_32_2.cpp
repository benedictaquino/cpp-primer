/* This program defines a vector of ten ints and gives each element the same
 * value as its position in the array. Then it copies the values into another
 * vector */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> iv1, iv2;  // initialize two empty integer vectors
    for (int i = 1; i != 11; i++)
        iv1.push_back(i);  // append values 1 through 10 to iv1
    iv2 = iv1;  // copy iv1 to iv2

    // print elements of iv1 and iv2
    for (int i = 0; i != 10; i++)
        cout << "iv1[" << i << "] = " << iv1[i] << "\t"
             << "iv2[" << i << "] = " << iv2[i] << endl;
    return 0;
}
