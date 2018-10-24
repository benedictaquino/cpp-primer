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

## Exercises Section 2.1.3
**Exercise 2.5:** Determine the type of each of the following literals. Explain the differences among the literals in each of the four examples:

* (a) `'a'`, `L'a'`,`"a"`, `L"a"`
* (b) `10`, `10u`, `10L`, `10uL`, `012`, `0xC`
* (c) `3.14`, `3.14f`, `3.14L`
* (d) `10`, `10u`, `10.`, `10e-2`

**Solution:** 

* (a) `char`, `wchar_t`, `const char*`, `const wchar_t*`

  The first literal `'a'` is enclosed in single quotes so it is a literal of type `char`. The `L` prefix changes this to a literal of type `wchar_t`. The literal `"a"` is enclosed in double quotation marks so it is a string literal of `char`s. The `L` prefix changes this to a string literal of type `wchar_t`.

* (b) `int`, `unsigned int`, `long`, `unsigned long`, `int`, `int`

  The first literal `10` is written in decimal form, the second literal is `10` written in decimal form with the suffix `u` specifying it as an `unsigned` type, the third literal `10L` is written in decimal form with the suffix `L` specifying it as a `long` type. The fourth literal `012` is 10 written in octal form. The fifth literal is `12` written in hexadecimal form.

* (b) `double`, `float`, `long double`

  The first literal `3.14` is a floating point and they default to the `double` type. The second literal has the `f` suffix which specifies the type as `float`. The third literal has the `L` suffix which specifies the type as `long double`.

* (d) `int`, `unsigned int`, `double`, `double`

  The first literal is evidently of type `int`. The second literal had the `u` suffix which specifies the type as `unsigned int`. The third literal has the decimal point notation, so it is a floating-point literal of type `double`. The fourth literal has scientific notation, so it is a floating-point literal of type `double`.

**Exercise 2.6:** What, if any, are the differences between the following definitions:

```cpp
int month = 9, day = 7;
int month = 09, day = 07;
```

**Solution:** On the first line `month` and `day` are decimal notation and defined as `9` and `7` respectively. The second line `month` and `day` are in octal notation so the `09` is an invalid value and `07` is `7`.

**Exercise 2.7:** What values do these literals represent? What type does each have?

* (a) `"Who goes with F\145rgus?\012"`
* (b) `3.14e1L`
* (c) `1024f`
* (d) `3.14L`

**Solution:**

* (a) This literal's value is `"Who goes with Fergus?\n"` and it is a string literal of type  `const char*`.
* (b) This literal's value is `31.4` and it is a floating-point literal of type `long double`.
* (c) This literal's value is invalid because `1024` is an integer literal of type `int` but the `f` suffix is for floating-point literals.
* (d) This literal's value is `3.14` and it is a floating-point literal of type `long double`.

**Exercise 2.8:** Using escape sequences, write a program to print `2M` followed by a newline. Modify the program to print `2`, then a tab, then an `M`, followed by a newline.

[ex2_8_1.cpp](src/ex2_8_1.cpp)

```cpp
/* This program uses escape sequences to print 2M followed by a newline */
#include <iostream>
int main()
{
    std::cout << "\062\115\012" << std::endl;
    return 0;
}
```

[ex2_8_2.cpp](src/ex2_8_2.cpp)

```cpp
/* This program uses escape sequences to print 2, then a tab, then an M, 
 * followed by a newline */
#include <iostream>
int main()
{
    std::cout << "\062\011\115\012" << std::endl;
    return 0;
}
```

## Exercises Section 2.2.1
**Exercise 2.9:** Explain the following definitions. For those that are illegal, explain what's wrong and how to correct it.
* (a) `std::cin >> int input_value;`
* (b) `int i = { 3.14 };`
* (c) `double salary = wage = 9999.99;`
* (d) `int i = 3.14;`

**Solution:**
* (a) This definition is illegal. The object `input_value` must be declared before it can be assigned a value by `cin`. 
* (b) This definition is illegal because a narrowing conversion is required.
* (c) This definition is illegal because an object cannot be initialized to an undeclared object.
* (d) This definition is legal. It will truncate `3.14` to `3`.

**Exercise 2.10:** What are the initial values, if any, of each of the following variables?

```cpp
std::string global_str;
int global_int;
int main()
{
    int local_int;
    std::string local_str;
}
```

**Solution:** The initial values of both `global_str` and `local_str` are the empty string because the `string` class says that if we do not supply an initializer, then the result is the empty string.

The initial value of `global_int` is zero initialized since it is a global object. The `local_int` variable has an undefined behavior, it could be initialized to anything.
