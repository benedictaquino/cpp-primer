#include <iostream>
#include "../include/ex7_43.h"

using std::cout;

NoDefault::NoDefault(int i): member(i) { }

int main()
{
    C object;
    cout << object.c_member.member << "\n";
    return 0;
}
