/* This program defines an array of ten ints and gives each element the same
 * value as its position in the array */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int ia[10];
    for (int ix = 0; ix != 10; ix++) {
        ia[ix] = ix + 1;
    }
    for (int i; i != 10; i++)
        cout << "ia[" << i << "] = " << ia[i] << endl;
    return 0;
}
