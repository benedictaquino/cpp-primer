#include <iostream>

using std::cin; using std::cout; using std::endl;

void f()
{
    cout << "f() was called." << endl;
}

void f(int ival)
{
    cout << "f(int) was called." << endl;
}

void f(int ival1, int ival2)
{
    cout << "f(int, int) was called." << endl;
}

void f(double dval1, double dval2 = 3.14)
{
    cout << "f(double, double) was called." << endl;
}

int main()
{
//  cout << "f(2.56, 42) => ";
//  f(2.56, 42);  // error: call of overloaded 'f(double, int)' is ambiguous
    cout << "f(42) => ";
    f(42);
    cout << "f(42, 0) => ";
    f(42, 0);
    cout << "f(2.56, 3.14) => ";
    f(2.56, 3.14);
    return 0;
}
