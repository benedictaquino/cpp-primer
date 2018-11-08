#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;
using fcn_ptr = int(*)(int, int);

int add(int ival1, int ival2) { return ival1 + ival2; }
int subtract(int ival1, int ival2) { return ival1 - ival2; }
int multiply(int ival1, int ival2) { return ival1 * ival2; }
int divide(int ival1, int ival2) { return ival1 / ival2; }

int main()
{
    cout << "Enter two integers: " << endl;
    int ival1, ival2;
    cin >> ival1 >> ival2 ;
    cout << ival1 << " + " << ival2 << " = " << add(ival1, ival2) << endl;
    cout << ival1 << " - " << ival2 << " = " << subtract(ival1, ival2) << endl;
    cout << ival1 << " * " << ival2 << " = " << multiply(ival1, ival2) << endl;
    cout << ival1 << " / " << ival2 << " = " << divide(ival1, ival2) << endl;
    vector<fcn_ptr> fcn_ptr_vec = {&add, &subtract, &multiply, &divide};
    for (auto fp : fcn_ptr_vec) cout << fp(ival1, ival2) << " "; cout << endl;
    return 0;
}
