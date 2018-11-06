#include <iostream>

using std::cin; using std::cout; using std::endl;

// function that takes a reference to an int and sets the given object to zero
void reset(int &i)  // i is just another name for the object passed to reset
{
    i = 0;
}

int main()
{
    cout << "Enter an integer: " << endl;
    int j;
    cin >> j;
    cout << "reset(" << j << ")" << endl;
    reset(j);
    cout << j << endl;
    return 0;
}
