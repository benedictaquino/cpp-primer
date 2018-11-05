// This program reads two integers from the standard input and prints the
// results of dividing the first number by the second
#include <iostream>
#include <stdexcept>

using std::cin; using std::cout; using std::endl;
using std::runtime_error;

int main()
{
    int i1, i2;    // define two integers
    cout << "Please enter two integers:" << endl;
    cin >> i1 >> i2;
    if (!i2) throw runtime_error("Division by zero.");
    cout << i1 / i2 << endl;
    return 0;
}
