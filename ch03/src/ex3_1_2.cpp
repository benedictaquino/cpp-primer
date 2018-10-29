/* This program prints the numbers from 10 down to 0 */
#include <iostream>
using std::cout; using std::endl;
int main()
{
    int i = 10;
    while (i >= 0) {
        cout << i << " ";
        i--;
    }
    cout << endl;
    return 0;
}
