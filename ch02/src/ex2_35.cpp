#include <iostream>
#include <typeinfo>
int main()
{
    const int i = 42;           // i is a const int with value 42
    auto j = i;                 // j is an int (the top-level const of i is ignored)
    const auto &k = i;          // k is a const int reference to i
    auto *p = &i;               // p is a const int pointer to i
    const auto j2 = i, &k2 = i; // j2 is a const int and k2 is a const int reference

    std::cout << "i is a " << typeid(i).name() << "\ni = " << i << "\n"
              << "j is a " << typeid(j).name() << "\nj = " << j << "\n"
              << "k is a " << typeid(k).name() << "\nk = " << k << "\n"
              << "p is a " << typeid(p).name() << "\np = " << p << "\n*p = " << *p << "\n"
              << "j2 is a " << typeid(j2).name() << "\nj2 = " << j2 << "\n"
              << "k2 is a " << typeid(k2).name() << "\nk2 = " << k2 << std::endl;

    return 0;
}
