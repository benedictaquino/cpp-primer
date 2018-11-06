#include <iostream>
#include "../include/Chapter6.h"

using std::cin; using std::cout; using std::endl;

int main()
{
    // prompt user for an integer and read it from standard input into i
    cout << "Enter an integer:" << endl;
    int i;
    cin >> i;
    int j = fact(i);
    cout << i << "! is " << j << endl;
    return 0;
}
