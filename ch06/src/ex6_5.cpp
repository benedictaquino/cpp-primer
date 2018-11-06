#include <iostream>

using std::cin; using std::cout; using std::endl;

double abs(double d)
{
    if (d < 0) d -= 2 * d;
    return d;
}

int main()
{
    cout << "Enter a number:" << endl;
    double dval;
    cin >> dval;
    double abs_d = abs(dval);
    cout << "The absolute value of " << dval << " is " << abs_d << endl;
    return 0;
}
