#include <iostream>

using std::cin; using std::cout; using std::endl;

struct X {
    X (int i, int j): rem(i % j), base(i)  { }
    int rem, base;
};

int main()
{
    cout << "Enter two integers: ";
    int i, j; cin >> i >> j;
    X test(i, j);
    cout << "base = " << test.base << " rem = " << test.rem << endl;
    return 0;
}
