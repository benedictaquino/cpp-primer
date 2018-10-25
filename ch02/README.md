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
