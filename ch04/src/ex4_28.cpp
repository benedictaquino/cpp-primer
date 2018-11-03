/* This program prints the size of each of the built-in types */
#include <iostream>

using std::cout; using std::endl;

int main()
{
    cout << "Built-in Type\tSize\n" 
         << "-------------\t----\n" << "\n"
         << "bool\t\t" << sizeof(bool) << "\n"
         << "char\t\t" << sizeof(char) << "\n"
         << "wchar_t\t\t" << sizeof(wchar_t) << "\n"
         << "char16_t\t" << sizeof(char16_t) << "\n"
         << "char32_t\t" << sizeof(char32_t) << "\n"
         << "short\t\t" << sizeof(short) << "\n"
         << "int\t\t" << sizeof(int) << "\n"
         << "long\t\t" << sizeof(long) << "\n"
         << "long long\t" << sizeof(long long) << "\n"
         << "float\t\t" << sizeof(float) << "\n"
         << "double\t\t" << sizeof(double) << "\n"
         << "long double\t" << sizeof(long double) << endl;
    return 0;
}
