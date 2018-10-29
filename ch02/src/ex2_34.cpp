#include <iostream>
int main()
{
    int i = 0, &r = i;
    auto a = r;  // a is an int (r is an alias for i, which has type int)

    const int ci = i, &cr = ci;
    auto b = ci;  // b is an int (top-level const in ci is dropped)
    auto c = cr;  // c is an int (cr is an alias for ci whos const is top-level)
    auto d = &i;  // d is an int* (& of an int object is int*)
    auto e = &ci; // e is const int* (& of a const object is low-level const)
    
    const auto f = ci;  // deduced type of ci is int; f has type const int
    auto &g = ci;       // g is a const int& that is bound to ci
    const auto &j = 42; // ok: we can bind a const reference to a literal

    std::cout << "a = " << a << std::endl;
    a = 42;  // a is assigned the value 42
    std::cout << "a = 42;\na = " << a << std::endl;

    std::cout << "b = " << b << std::endl;
    b = 42;  // b is assigned the value 42
    std::cout << "b = 42\nb = " << b << std::endl;

    std::cout << "c = " << c << std::endl;
    c = 42;  // c is assigned the value 42
    std::cout << "c = 42;\nc = " << c << std::endl;

    std::cout << "d = " << d << std::endl;
    // d = 42;  // error: d is an int pointer and cannot be assigned an integer value

    std::cout << "e = " << e << std::endl;
    // e = 42;  // error: e is a const int pointer and cannot be assigned an integer value

    std::cout << "g = " << g << std::endl;
    // g = 42;  // error: g is an int reference and cannot be assigned an integer value

    return 0;
}
