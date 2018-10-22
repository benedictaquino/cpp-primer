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

[helloworld.cpp](helloworld.cpp)

```cpp
#include <iostream>
int main()
{
    std::cout << "Hello, World" << std::endl;
    return 0;
}
```

**Exercise 1.4:** Our program used the addition operator, `+`, to add two numbers. Write a program that uses the multiplication operator, `*`, to print the product instead.

[multiply.cpp](multiply.cpp)

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

[main2.cpp](main2.cpp)

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

[comments.cpp](comments.cpp)

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

[ex1_8.cpp](ex1_8.cpp)

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
