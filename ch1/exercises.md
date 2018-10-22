# Chapter 1 Exercises
## Exercises Section 1.1.1
**Exercise 1.1:** Review the documentation for your compiler and determine what file naming convention it uses. Compile and run the `main` program from page 2.

```cpp
int main()
{
    return 0;
}
```

**Exercise 1.2** Change the program to return -1. A return value of -1 is often treated as an indicator that the program failed. Recompile and rerun your program to see how your system treats a failure indicator from `main`.

```cpp
int main()
{
    return -1;
}
```
## Exercises Section 1.2
**Exercise 1.3:** Write a program to print `Hello, World` on the standard output.

[helloworld.cpp](src/helloworld.cpp)

```cpp
#include <iostream>
int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

**Exercise 1.4:** Our program used the addition operator, `+`, to add two numbers. Write a program that uses the multiplication operator, `*`, to print the product instead.

[multiply.cpp](src/multiply.cpp)

```cpp
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2 << " is "
	<< v1 * v2 << std::endl;
    return 0;
}
```

**Exercise 1.5:** We wrote the output in one large statement. Rewrite the program to use a separate statement to print each operand.

[main2.cpp](src/main2.cpp)

```cpp
#include <iostream>
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The sum of "; 
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 + v2 << std::endl; 
    return 0;
}
```

**Exercise 1.6:** Explain whether the following program fragment is legal.

```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```

The program is not legal. The output operator needs an `ostream` object as the left-hand operand.

```cpp
std::cout << "The sum of " << v1;
std::cout << " and " << v2;
std::cout << " is " << v1 + v2 << std::endl;
```

The above program fragment would be legal.

## Exercises Section 1.3
**Exercise 1.7:** Compile a program that has incorrectly nested comments.

[comments.cpp](src/comments.cpp)

```cpp
/*
 * comment pairs /* */ cannot nest,
 * "cannot nest" is considered source code,
 * as is the rest of the program
 */
int main()
{
    return 0;
}
```

**Exercise 1.8:** Indicate which, if any, of the following output statements are legal:

```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```

The first two output statements are legal.

[ex1_8.cpp](src/ex1_8.cpp)

```cpp
#include <iostream>
int main()
{
    std::cout << "/*";
    std::cout << "*/";
    std::cout << "*/";
    std::cout << "*/" "/*" << std::endl;
    return 0;
}
```
## Exercises Section 1.4.1
**Exercise 1.9:** Write a program that uses a `while` to sum the numbers from 50 to 100.

[ex1_9.cpp](src/ex1_9.cpp)

```cpp
// This program uses a while loop to sum the numbers from 50 to 100
#include <iostream>
int main()
{
    int sum = 0, i = 50;
    // keep executing the while as long as i is less than or equal to 100
    while (i <= 100) {
	sum += i;
	i++;
    }
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}
```

**Exercise 1.10:** In addition to the `++` operator that adds 1 to its operands, there is a decrement operator (`--`) that subtracts 1. Use the decrement operator to write a `while` that prints the numbers from ten down to zero.

[ex1_10.cpp](src/ex1_10.cpp)

```cpp
// This program prints the numbers from 10 down to zero
#include <iostream>
int main()
{
    int i = 10;
    while (i >= 0) {
	std::cout << i << " ";
	i--;
    }
    std::cout << std::endl;
    return 0;
}
```

**Exercise 1.11:** Write a program that prompts the user for two integers. Print each number in the range specified by those two integers.

[ex1_11.cpp](src/ex1_10.cpp)

```cpp
/* This program prompts the user for two integers then prints each number in 
 * the range specified by those two integers */
#include <iostream>
int main()
{
    std::cout << "Enter two integers: " << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    while (v1 <= v2) {
	std::cout << v1 << " ";
	v1++;
    }
    std::cout << std::endl;
    return 0;
}
```

## Exercises Section 1.4.2
**Exercise 1.12:** What does the following `for` loop do? What is the value of `sum`?

```cpp
int sum = 0;
for (int i = -100; i <=100; ++i)
    sum += i;
```

The for loop calculates the sum of the numbers -100 to 100 inclusive. The final value of sum is 0.

**Exercise 1.13:** Rewrite the first two exercises from [1.4.1](#exercises-section-141) using `for` loops using `for` loops.

[ex1_13_1.cpp](src/ex1_13_1.cpp)

```cpp
// This program uses a for loop to sum the numbers from 50 to 100
#include <iostream>
int main()
{
    int sum = 0;
    for (int i = 50; i <= 100; i++)
	sum += i;
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}
```

[ex1_13_2.cpp](src/ex1_13_2.cpp)

```cpp
// This program prints the numbers from 10 down to zero with a for loop
#include <iostream>
int main()
{
    for (int i = 10; i >= 0; i--)
	std::cout << i << " ";
    std::cout << std::endl;
    return 0;
}
```

**Exercise 1.14:** Compare and contrast the loops that used a for with those using a while. Are there advantages or disadvantages to using either form?

The for loops allow for more concise code. While loops can be more flexible with the conditions. For loops are limited to incremental loops.

**Exercise 1.15:** Write programs that contain the common errors discussed in the box on page 16. Familiarize your self with the messages the compiler generates.
