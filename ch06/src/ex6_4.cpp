#include <iostream>

using std::cin; using std::cout; using std::endl; using std::flush;

void fun_fact()
{
    // prompt user for an integer and read it from standard input into i
    cout << "Enter an integer:" << endl;
    int val;
    cin >> val;
    cout << val << "! is " << flush;
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1) ret *= val--; // assign ret * val to ret and decrement val
    cout << ret << endl;
}

int main()
{
    fun_fact();
    return 0;
}
