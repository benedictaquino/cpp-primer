# Chapter 2 Exercises
## Exercises Section 2.1.1
**Exercise 2.1:** What are the differences between `int`, `long`, `long long`, and `short`? Between an unsigned and signed type? Between a `float` and a `double`?

**Solution:** The `int`, `long`, `long long`, and `short` types are integer types of different size. Unsigned types only represent values greater than or equal to zero, while signed types include positive, negative, and zero values. The `float` and `double` are floating point types of different sizes.

**Exercise 2.2:** To calculate a mortage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

**Solution:** I would use the `double` for all three since I'd likely be using these variables for calculations and with mixed calculations any smaller types would be promoted to the larger type.

## Exercises Section 2.1.2
**Exercise 2.3:** What output will the following code produce?
```cpp
unsigned u = 10, u2=42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;

int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;

std::cout << i - u << std::endl;
std::cout << u - i << std::endl;
```

**Solution:** The output will be as such:

```
32
4294967296
32
-32
0
0
```

The expression `u2 - u` evaluates to `32` because it is `42 - 10` and `32` is in range of the `unsigned int` type.

The expression `u - u2` evaluates to `4294967296` because `-32` is out-of-range of the `unsigned` type and so it loops around.

The expression `i2 - i` evaluates to `32` because it is in range of the `int` type.

The expression `i - i2` evaluates to `-32` because it is in range of the `int` type.

The expressions `i - u` and `u - i` evaluate to `0` because it is in range of the `unsigned` type.

**Exercise 2.4:** Write a program to check whether your predictions were correct. If not, study this section until you understand what the problem is.

[ex2_4.cpp](src/ex2_4.cpp)

```cpp
/* This program runs the code from exercise 2.3 to check if my predictions were
 * correct */
#include <iostream>
int main()
{
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;

    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;

    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;

    return 0;
}
```
