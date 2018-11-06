#include <iostream>

using std::cin; using std::cout; using std::endl;

int fact(int val)
{
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1) ret *= val--; // assign ret * val to ret and decrement val
    return ret; // return the result
}

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
