// This program reads two integers from the standard input and prints the
// results of dividing the first number by the second
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int i1, i2;    // define two integers
    cout << "Please enter two integers:" << endl;
    cin >> i1 >> i2;
    cout << i1 / i2 << endl;
    return 0;
}
