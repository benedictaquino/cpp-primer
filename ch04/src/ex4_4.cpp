/* This program evaluates the expression from Exercise 4.4 in order to validate
 * my prediction */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int i = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
    cout << "12 / 3 * 4 + 5 * 15 + 24 % 4 / 2  = " << i << endl;
    return 0;
}
