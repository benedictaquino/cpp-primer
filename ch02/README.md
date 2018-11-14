# Chapter 2: Variables and Basic Types

## Section 2.1: Primitive Built-in Types

### Section 2.1.1: Arithmetic Types

**Exercise 2.1:** What are the differences between `int`, `long`, `long long`, and `short`? Between an unsigned and signed type? Between a `float` and a `double`?

**Solution:** The `int`, `long`, `long long`, and `short` types are integer types of different size. Unsigned types only represent values greater than or equal to zero, while signed types include positive, negative, and zero values. The `float` and `double` are floating point types of different sizes.

**Exercise 2.2:** To calculate a mortage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type.

**Solution:** I would use the `double` for all three since I'd likely be using these variables for calculations and with mixed calculations any smaller types would be promoted to the larger type.

### Section 2.1.2: Type Conversions

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

[**Solution:**](src/ex2_4.cpp)

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

### Section 2.1.3: Literals

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

[**Solution:**](src/ex2_8_1.cpp)

```cpp
/* This program uses escape sequences to print 2M followed by a newline */
#include <iostream>
int main()
{
    std::cout << "\062\115\012" << std::endl;
    return 0;
}
```

[**Solution:**](src/ex2_8_2.cpp)

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

## Section 2.2: Variables

### Section 2.2.1: Variable Definitions

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

### Section 2.2.2: Variable Declarations and Definitions

**Exercise 2.11:** Explain whether each of the following is a declaration or a definition:

* (a) `extern int ix = 1024;`
* (b) `int iy;`
* (c) `extern int ix;`

**Solution:** 

* (a) Definition. `extern` is used but since there is an initializer, so the `extern` is overrided and this statement is now a definition.
* (b) Definition. `extern` is not used, so the object is defined.
* (c) Declaration. `extern` is used and there is no initializer, so it is a declaration.

### Section 2.2.3: Identifiers

**Exercise 2.12:** Which, if any, of the following names are invalid?
* (a) `int double 3.14;`
* (b) `int _;`
* (c) `int catch-22;`
* (d) `int 1_or_2;`
* (e) `double Double = 3.14;`

**Solution:**

* (a) Invalid. `double` is an invalid identifier because it is a C++ reserved name.
* (b) Valid. Identifiers can begin with underscores.
* (c) Invalid. `catch` is a reserved name and hyphens are invalid characters for identifiers.
* (d) Invalid. Identifiers must begin with a letter or an underscore.
* (e) Valid. Since identifiers are case-sensitive, `Double` is valid.

### Section 2.2.4: Scope of a Name

**Exercise 2.13:** What is the value of `j` in the following program?

```cpp
int i = 42;
int main()
{
    int i = 100;
    int j = i;
}
```

**Solution:** The value of `j` in this program is `100`. The object `j` is defined and initialized as `i`, which has a value of `100` in the inner scope.

**Exercise 2.14:** Is the following program legal? If so, what values are printed?

```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
    sum += i;
std::cout << i << " " << sum << std::endl;
```

**Solution:** This program is legal. The values printed should be `100 45`. inside the for loop, the object `i` in this inner scope is the iterator from 1 to 9. The object `i` in the outer scope remains `100`, then when the values are printed it prints `i` then `sum`.

## Section 2.3: Compound Types

### Section 2.3.1: References

**Exercise 2.15:** Which of the following definitions, if any, are invalid? Why?
* (a) `int ival = 1.01;`
* (b) `int &rval1 = 1.01;`
* (c) `int &rval2 = ival;`
* (d) `int &rval3;`

**Solution:** 
* (a) Valid. `ival` will be initialized with value `1` since `1.01` will be truncated.
* (b) Invalid. `rval1` is preceded by the `&` and a reference's initializer must be an object.
* (c) Assuming that `ival` is a defined integer object, then valid. `rval2` is preceded by the `&` symbol and the initializer is an object.
* (d) Invalid. `rval3` is preceded by the `&` symbol and a reference must be initialized.

**Exercise 2.16:** Which, if any, of the following assignments are invalid? IF they are valid, explain what they do.

```cpp
int i = 0, &r1 = i; double d = 0, &r2 = d;
```

* (a) `r2 = 3.14159;`
* (b) `r2 = r1;`
* (c) `i = r2;`
* (d) `r1 = d;`

**Solution:**
* (a) Valid. `r2` references the floating-point object `d` and we are now assigned the floating-point value `3.14159` to `d`.
* (b) Valid. `r1` references `i` with value `0` which is assigned to the object `d` and the type is converted from `int` to `float`.
* (c) Valid. The object `i` is being assigned the value of `r2` which is a reference to `d`. The floating-point value is truncated and assigned to `i`.
* (d) Valid. The reference `r1` refers to object `i` which is assigned the value of `d`. The floating-point value is truncated and assigned to `i`.

**Exercise 2.17:** What does the following code print?

```cpp
int i, &ri = i;
i = 5; r1 = 10;
std::cout << i << " " << r1 << std::endl;
```

**Solution:** The code above prints `10 10`. The integer object `i` is defined and the reference `ri` is defined with initializer `i`. `i` is then assigned the value `5`, then the value `10` is assigned to `i`, because `ri` is a reference to `i`. `i` is then printed, followed by a space, then `i` is printed again because `ri` refers to `i`.

### Section 2.3.2 Pointers

**Exercise 2.18:** Write code to change the value of a pointer. Write code to change the value to which the pointer points.

**Solution:**

```cpp
int i = 0;            // Initialize integer object i with value 0
int *pi = nullptr;    // Initialize null pointer pi 
pi = &i               // Assign address of object i to pointer pi
*pi = 10;             // Assign the value 10 to the object which pi points to
```

**Exercise 2.19:** Explain the key differences between pointers and references.

**Solution:** Unlike references, pointers do not need to be initialized at the time of definition. References refer to objects, but pointers point to the address of another object. As well, the address value stored in a pointer does not need to point to an object.

**Exercise 2.20:** What does the following program do?

```cpp
int i = 42;
int *p1 = &i;
*p1 = *p1 * *p1;
```

**Solution:** The above program initializes integer object `i` with the value `42`. Then initializes the integer pointer `p1` with the address of `i`. Then the object that `p1` points to (`i`) is assigned the value of the expression `*p1 * *p1`. Since `p1` points to `i` which has a value of `42`, the final value is `1764`.

**Exercise 2.21:** Assuming `p` is a pointer to `int`, explain the following code:

```cpp
if (p) // ...
if (*p) // ...
```

**Solution:** 

```cpp
if (p) // evaluates the value of the pointer
if (*p) // evaluates the value of the object the pointer points to
```

If the pointer is the null pointer, then the `if` statement evaluates as `false`. For any non-zero pointer values, the condition is `true`.

**Exercise 2.23:** Given a pointer `p`, can you determine whether `p` points to a valid object? If so, how? If not, why not?

**Solution:** No. The pointer only contains an address of an object, it does not contain any information about whether or not the pointed object is valid.

**Exercise 2.24:** Why is the initialization of `p` legal but that of `lp` illegal?

```cpp
int i = 42;
void *p = &i;
long *lp = &i;
```

**Solution:** The initialization of `p` is legal because a `void*` pointers can hold the address of any object. The initialization of `lp` is illegal because it is a `long` pointer so it must hold the address of a `long` object.

### Section 2.3.3 Understanding Compound Type Declarations

**Exercise 2.25:** Determine the types and values of each of the following variables.

* (a) `int* ip, i, &r = i;`
* (b) `int i, *ip = 0;`
* (c) `int* ip, ip2;`

**Solution:** 

* (a) `int* ip, i, &r = i;`
  * `ip` is an `int` pointer with an undefined value.
  * `i` is an `int` object with an undefined value. 
  * `r` is an `int` reference for `i`
* (b) `int i, *ip = 0;`
  * `i` is an `int` object with an undefined value
  * `ip` is a null pointer 
* (c) `int* ip, ip2;`
  * `ip` is an `int` pointer with an undefined value
  * `ip2` is an `int` object with an undefined value

## Section 2.4: `const` Qualifier

**Exercise 2.26:** Which of the following are legal?

* (a) `const int buf;`
* (b) `int cnt = 0;`
* (c) `const int sz = cnt`
* (d) `++cnt; ++sz;`

**Solution:**

* (a) Illegal. `buf` is an uninitialized `const` object
* (b) Legal. `cnt` is an `int` object with value `0`
* (c) Legal. `sz` is an `int` object with value `0`
* (d) `++cnt` is a legal statement. `cnt` is incremented by 1. `++sz` is an illegal statement. `sz` is a `const` object so it cannot be changed.

### Section 2.4.1: References to `const`

### Section 2.4.2: Pointers and `const`

**Exercise 2.27:** Which of the following initializations are legal? Explain why.

* (a) `int i = -1, &r = 0;`
* (b) `int *const p2 = &i2;`
* (c) `const int i = -1, &r = 0;`
* (d) `const int *const p3 = &i2;`
* (e) `const int *p1 = &i2;`
* (f) `const int &const r2;`
* (g) `const int i2 = i; &r = i;`

**Solution:**

* (a) Illegal. `r` is not a reference to `const` so it cannot be bound to `0`.
* (b) Legal. `p2` is a `const int` pointer to the address of i2.
* (c) Legal. `i` is a `const int` initialized with the value `-1` and `r2` is a reference to `const`.
* (d) Legal. `p3` is a `const` pointer to a `const int` object.
* (e) Legal. `p1` is a pointer to a `const int` object.
* (f) Illegal. The `&` qualifer cannot be applied to a `const int` and `r2` is an uninitialized reference.
* (g) Legal. `i2` is a `const int` with the value of `i` and `r` is a reference to a const `i`.

**Exercise 2.28:** Explain the following definitions. Identify any that are illegal.

* (a) `int i, *const cp;`
* (b) `int *p1, *const p2;`
* (c) `const int ic, &r = ic;`
* (d) `const int *const p3;`
* (e) `const int *p;`

**Solution:** 

* (a) Illegal. `cp` is an uninitialized `const` pointer.
* (b) Illegal. `p2` is an uninitialized `const` pointer.
* (c) Illegal. `ic` is an uninitialized `const` int.
* (d) Illegal. `p3` is an uninitialized `const` pointer.
* (e) Legal. `p` is an uninitialized pointer to a `const int` object.

**Exercise 2.29:** Using the variables in the previous exercise, which of the following assignments are legal? Explain why.

* (a) `i = ic;`
* (b) `p1 = p3;`
* (c) `p1 = &ic;`
* (d) `p3 = &ic;`
* (e) `p2 = p1;`
* (f) `ic = *p3;` 

**Solution:**

* (a) Legal. The value in `ci` is copied to into `i`.
* (b) Illegal. `p3` is a `const` pointer to a `const int` and `p1` is an `int` pointer so it cannot poinrt to the address of a `const int` 
* (c) Illegal. `ic` is a `const int` and `p1` is an `int` pointer so it cannot point to a `const int` address.
* (d) Illegal. `p3` is a `const` pointer so the address value stored in `p3` cannot be changed.
* (e) Illegal. `p2` is a `const` pointer so the address value stored in `p2` cannot be changed.
* (f) Illegal. `ic` is a `const int` so the value stored in `ic` cannot be changed.

### Section 2.4.3: Top-level `const`

**Exercise 2.30:** For each of the following declarations indicate whether the object being declared has top-level or low-level `const`.

```cpp
const int v2 = 0;
int v1 = v2;
int *p1 = &v1, &r1 = v1;
const int *p2 = &v2, *const p3 = &i, &r2 = v2;
```

**Solution:** 

* `v2` is a `const int` object so it has top-level `const`.
* `v1` is a an `int` that copies the value of `v2`, so top-level `const` is ignored.
* `p1` is an `int` pointer that holds the address of `int` object `v1` and `r1` is a reference to an `int` object `v1`. Neither have `const`.
* `p2` is a pointer that stores the address of `const int` object `v2`, so it has low-level `const`. `p3` is a `const` pointer that stores the address of `const int` object `i`, so it has both top-level and low-level `const`. `r2` is a reference to a `const int` object `v2`, so it has low-level const.

**Exercise 2.31:** Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level `const` applies to each case.

```cpp
r1 = v2;
p1 = p2;
p2 = p1;
p1 = p3;
p2 = p3;
```

**Solution:**

* `r1 = v2;` is a legal assignment. `r1` is a reference to a `const int` and `v2` is a `const int`.
* `p1 = p2;` is an illegal assignment. `p2` has low-level `const` and `p1` does not.
* `p2 = p1;` is a legal assignment. `int*` can be converted to `const int*`.
* `p1 = p3;` is an illegal assignment. `p3` has low-level `const` and `p1` does not.
* `p2 = p3;` is a legal assignment. Both `p2` and `p3` have low-level `const` and the high-level `const` of `p3` can be ignored.

### Section 2.4.4: `constexpr` and Constant Expressions

**Exercise 2.32:** Is the following code legal or not? If not, how might you make it legal?

```cpp
int null = 0, *p = null;
```

**Solution:** The code is illegal. To make it legal, `p` must be initialized with an address of an `int` object, not an `int` object.

```cpp
int null = 0, *p = &null;
```

Alternatively, one can initialize `p` as a null pointer.

```cpp
int null = 0, *p = nullptr;
```

## Section 2.5: Dealing with Types

### Section 2.5.1: Type Aliases

### Section 2.5.2: The `auto` Type Specifier

**Exercise 2.33:** Using the variable definitions from this section, determine what happens in each of these assignments:

```cpp
int i = 0, &r = i;
auto a = r;  // a is an int (r is an alias for i, which has type int)

const int ci = i, &cr = ci;
auto b = ci;  // b is an int (top-level const in ci is dropped)
auto c = cr;  // c is an int (cr is an alias for ci whost const is top-level)
auto d = &i;  // d is an int* (& of an int object is int*)
auto e = &ci; // e is const int* (& of a const object is low-level const)

const auto f = ci;  // deduced type of ci is int; f has type const int
auto &g = ci;       // g is a const int& that is bound to ci
auto &h = 42;       // error: we can't bind a plain reference to a literal
const auto &j = 42; // ok: we can bind a const reference to a literal

a = 42;
b = 42;
c = 42;
d = 42;
e = 42;
g = 42;
```

**Solution:**

* `a = 42;` `a` is assigned the value `42`.
* `b = 42;` `b` is assigned the value `42`.
* `c = 42;` `c` is assigned the value `42`.
* `d = 42;` error: `d` is a `int` pointer to `i` and cannot be assigned an integer value.
* `e = 42;` error: `e` is a `const int` pointer to `ci` and cannot be assigned an integer value.
* `g = 42;` error: `g` is a `int` reference to `ci` and cannot be assigned an integer value

**Exercise 2.34:** Write a program containing the variables and assignments from the previous exercise. Print the variables before and after the assignments to check whether your predictions in the previous exercise were correct. If not, study the examples until you  an convince yourself you know what led you to the wrong conclusion.

[**Solution:**](src/ex2_34.cpp)

```cpp
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
```

**Exercise 2.35:** Determine the types deduced in each of the following definitions. Once you've figured out the types, write a program to see whether you were correct.

```cpp
const int i = 42;
auto j = i;
const auto &k = i;
auto *p = &i;
const auto j2 = i, &k2 = i;
```

[**Solution:**](src/ex2_35.cpp)

* `i` is a `const int` storing the value `42`.
* `j` is an `int` storing the value `42` because the top-level `const` of `i` is ignored.
* `k` is a `const int` reference to `i`
* `p` is a `const int` pointer to `i`
* `j2` is a `const int` and `k2` is a `const int` reference.

```cpp
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
```

### Section: 2.5.3 The `decltype` Type Specifier

**Exercise 2.36:** In the following code, determine the type of each variable and the value each variable has when the code finishes:

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype((b)) d = a;
++c;
++d;
```

**Solution:**

* `a = 4`. `a` is an `int` initialized with the literal `3`, then `d` is defined as an `int` reference to `a`. When the `++` operator is used on `d`, `a` is incremented by one.
* `b = 4`. `b` is an `int` initialized with the literal `4`.
* `c = 4`. `c` is an `int` initialized with `a` so it copies the value `3`. When the `++` operator is used on `c` it is incremented by one.
* `d = 4`. `d` is an `int` reference to `a`.

**Exercise 2.37:** Assignment is an example of an expression that yields a reference type. A type is a reference to the type of the left-hand operand. That is, if `i` is an `int`, then the type of the expression `i = x` is `int&`. Using that knowledge, determine the type and value of each variable in this code:

```cpp
int a = 3, b = 4;
decltype(a) c = a;
decltype(a = b) d = a;
```

**Solution:** 
* `a = 3`. `a` is an `int` initialized with the value `3`.
* `b = 4`. `b` is an `int` initialized with the value `4`.
* `c = 3`. `c` is an `int` initialized with `a` so it copies the value `3` from `a`.
* `d = 3`. `d` is an `int&` initialized with `a` so it is a reference to `a`.

**Exercise 2.38:** Describe the differences in type deduction between `decltype` and `auto`. Give an example of an expression where `auto` and `decltype` will deduce the same type and an example where they will deduce differing types.

**Solution:** The `auto` type specifier deduces the type from the initializing expression. The `decltype` type specifier deduces the type from the expression passed to `decltype`. `auto` and `decltype` will deduce the same type if the expression in the initializer for `auto` evaluates to the same type as the expression passed into `decltype`.

```cpp
int a = 10;
auto b = a;
decltype(a) c = a;
```

In the above example, `b` and `c` are both `int` objects.

`auto` and `decltype` will deduce differing types if the expression in initializer for `auto` and the expression pass into `decltype`. 

```cpp
int a = 10;
auto b = a;
decltype(a = 1) c = a;
```

In the above example, `b` is an `int` object and `c` is an `int` reference.

## Section 2.6: Defining Our Own Data Structures

### Section 2.6.1: Defining the `Sales_data` Type

**Exercise 2.39:** Compile the following program to see what happens when you forget the semicolon after a class definition. Remember the message for future reference.

```cpp
struct Foo { /* empty */ } // Note: no semicolon
int main()
{
    return 0;
}
```

[**Solution:**](src/ex2_39.cpp)

```
ch02/src/ex2_39.cpp:1:27: error: expected ';' after struct definition
 struct Foo { /* empty */ } // Note: no semicolon
                           ^
                           ;
```

**Exercise 2.40:** Write your own version of the `Sales_data` class.

[**Solution:**](src/ex2_40.cpp)

```cpp
struct Sales_data {
    std::string bookNo;
    std::string bookName;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double price = 0.0;
}
```

### Section 2.6.2: Using the `Sales_data` class

**Exercise 2.41:** Use your `Sales_data` class to rewrite the exercises in [1.5.1](../ch01#section-151-the-sales_item-class), [1.5.2](../ch01#section-152-a-first-look-at-member-functions), and [1.6](../ch01#section-16-the-bookstore-program). For now, you should define your `Sales_data` class in the same file as your `main` function.

[**Exercise 1.20 Solution:**](src/ex2_41_1.cpp)

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data item;
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        item.revenue *= item.units_sold;
        std::cout << item.bookNo << " " 
                  << item.units_sold << " " 
                  << item.revenue << " "
                  << item.revenue / item.units_sold << std::endl;
    }
    return 0;
}
```

[**Exercise 1.21 Solution:**](src/ex2_41_2.cpp)

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    // Define two Sales_data objects
    Sales_data item1, item2;
    // Read in data from standard input
    std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue
             >> item2.bookNo >> item2.units_sold >> item2.revenue;
    item1.revenue *= item1.units_sold;
    item2.revenue *= item2.units_sold;
    // Check that item1 and item2 havethe same bookNo
    if (item1.bookNo == item2.bookNo) {
        // Print sum of two transactions
        unsigned total_units_sold = item1.units_sold + item2.units_sold;
        double total_revenue = item1.revenue + item2.revenue;
        std::cout << item1.bookNo << " "
                  << total_units_sold << " "
                  << total_revenue << " "
                  << total_revenue / total_units_sold << std::endl;
        return 0;
    } else { // otherwise print error message
        std::cerr << "Data must refer to the same bookNo" << std::endl;
        return -1;
    }
}
```

[**Exercise 1.22 Solution:**](src/ex2_41_3.cpp)

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // read in first values as members of sum
    std::cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    sum.revenue *= sum.units_sold;
    // read in input as members of item
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        item.revenue *= item.units_sold;
        if (item.bookNo == sum.bookNo) {  // check that bookNo's match
            sum.units_sold += item.units_sold;
            sum.revenue += item.revenue;
        } else {  // print error message if bookNo's do not match
            std::cerr << "Data must refer to same bookNo" << std::endl;
            return -1;
        }
    } // end while loop
    std::cout << sum.bookNo << " " 
              << sum.units_sold << " " 
              << sum.revenue  << " "
              << sum.revenue / sum.units_sold
              << std::endl;
    return 0;
}
```

[**Exercise 1.23 Solution:**](src/ex2_41_4.cpp)

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    // Define Sales_data objects
    Sales_data currItem, item;
    // read in first transaction and ensure there is data to process
    if (std::cin >> currItem.bookNo >> currItem.units_sold >> currItem.revenue) {
        currItem.revenue *= currItem.units_sold;
        int cnt = 1;    // store the count for the current item
        // read the remaining transactions
        while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) { 
            item.revenue *= item.units_sold;
            if (item.bookNo == currItem.bookNo) // check if the bookNo's are the same
                ++cnt;
            else { // otherwise, print the count for the previous value
                std::cout << "There were " << cnt << " transactions for book number "
                    << currItem.bookNo << std::endl;
                currItem = item; // assign item to currItem
                cnt = 1;         // reset count
            }
        } // while loop ends here
        // Print last bookNo
        std::cout << "There were " << cnt << " transactions for book number " 
            << currItem.bookNo << std::endl;
    }
    return 0;
}
```

[**Exercise 1.25 Solution:**](src/ex2_41_5.cpp)

```cpp
#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;  // object to hold the data for the next transaction
    // read the first transaction and ensure there are data to process
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        total.revenue *= total.units_sold;
        Sales_data trans;  // object to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            trans.revenue *= trans.units_sold;
            // if we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // print results for previous book
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " "
                          << total.revenue / total.units_sold << "\n";
                total = trans;  // total now refers to the next book
            }
        }
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << " "
                  << total.revenue / total.units_sold 
                  << std::endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" <<std::endl;
        return -1;  // indicate failure
    }
    return 0;
}
```

### Section 2.6.3: Writing Our Own Header Files

**Exercise 2.42:** Write your own version of the `Sales_data.h` header and use it to rewrite the exercise from [2.6.2](#section-262-using-the-sales_data-class).

[**Exercise 1.20 Solution:**](src/ex2_42_1.cpp)

```cpp
#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data item;
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        item.revenue *= item.units_sold;
        std::cout << item.bookNo << " " 
                  << item.units_sold << " " 
                  << item.revenue << " "
                  << item.revenue / item.units_sold << std::endl;
    }
    return 0;
}
```

[**Exercise 1.21 Solution:**](src/ex2_42_2.cpp)

```cpp
#include <iostream>
#include "Sales_data.h"

int main()
{
    // Define two Sales_data objects
    Sales_data item1, item2;
    // Read in data from standard input
    std::cin >> item1.bookNo >> item1.units_sold >> item1.revenue
             >> item2.bookNo >> item2.units_sold >> item2.revenue;
    item1.revenue *= item1.units_sold;
    item2.revenue *= item2.units_sold;
    // Check that item1 and item2 havethe same bookNo
    if (item1.bookNo == item2.bookNo) {
        // Print sum of two transactions
        unsigned total_units_sold = item1.units_sold + item2.units_sold;
        double total_revenue = item1.revenue + item2.revenue;
        std::cout << item1.bookNo << " "
                  << total_units_sold << " "
                  << total_revenue << " "
                  << total_revenue / total_units_sold << std::endl;
        return 0;
    } else { // otherwise print error message
        std::cerr << "Data must refer to the same bookNo" << std::endl;
        return -1;
    }
}
```

[**Exercise 1.22 Solution:**](src/ex2_42_3.cpp)

```cpp
#include <iostream>
#include "Sales_data.h"

int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // read in first values as members of sum
    std::cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    sum.revenue *= sum.units_sold;
    // read in input as members of item
    while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) {
        item.revenue *= item.units_sold;
        if (item.bookNo == sum.bookNo) {  // check that bookNo's match
            sum.units_sold += item.units_sold;
            sum.revenue += item.revenue;
        } else {  // print error message if bookNo's do not match
            std::cerr << "Data must refer to same bookNo" << std::endl;
            return -1;
        }
    } // end while loop
    std::cout << sum.bookNo << " " 
              << sum.units_sold << " " 
              << sum.revenue  << " "
              << sum.revenue / sum.units_sold
              << std::endl;
    return 0;
}
```

[**Exercise 1.23 Solution:**](src/ex2_42_4.cpp)

```cpp
#include <iostream>
#include "Sales_data.h"

int main()
{
    // Define Sales_data objects
    Sales_data currItem, item;
    // read in first transaction and ensure there is data to process
    if (std::cin >> currItem.bookNo >> currItem.units_sold >> currItem.revenue) {
        currItem.revenue *= currItem.units_sold;
        int cnt = 1;    // store the count for the current item
        // read the remaining transactions
        while (std::cin >> item.bookNo >> item.units_sold >> item.revenue) { 
            item.revenue *= item.units_sold;
            if (item.bookNo == currItem.bookNo) // check if the bookNo's are the same
                ++cnt;
            else { // otherwise, print the count for the previous value
                std::cout << "There were " << cnt << " transactions for book number "
                    << currItem.bookNo << std::endl;
                currItem = item; // assign item to currItem
                cnt = 1;         // reset count
            }
        } // while loop ends here
        // Print last bookNo
        std::cout << "There were " << cnt << " transactions for book number " 
            << currItem.bookNo << std::endl;
    }
    return 0;
}
```

[**Exercise 1.25 Solution:**](src/ex2_42_5.cpp)

```cpp
#include <iostream>
#include "Sales_data.h"

int main()
{
    Sales_data total;  // object to hold the data for the next transaction
    // read the first transaction and ensure there are data to process
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        total.revenue *= total.units_sold;
        Sales_data trans;  // object to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            trans.revenue *= trans.units_sold;
            // if we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // print results for previous book
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " "
                          << total.revenue / total.units_sold << "\n";
                total = trans;  // total now refers to the next book
            }
        }
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << " "
                  << total.revenue / total.units_sold 
                  << std::endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" <<std::endl;
        return -1;  // indicate failure
    }
    return 0;
}
```
