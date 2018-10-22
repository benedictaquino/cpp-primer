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

## Exercises Section 1.4.3
**Exercise 1.16:** Write your own version of a program that prints the sum of a set of integers read from `cin`.

[ex1_16.cpp](src/ex1_16.cpp)

```cpp
// This program prints the sum of a set of integers read from cin
#include <iostream>
int main()
{
    int sum = 0, val;
    while (std::cin >> val) 
	sum += val;
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
```

## Exercises Section 1.4.4
**Exercise 1.17:** What happens in the program presented in this section if the input values are all equal? What if there are no duplicated values?

If the input values are all equal, then during the while loop the inner if statement is always true, then once the while loop ends, the count is printed.

If there are no duplicate values, then the inner if statement is always false, so the the count is printed every iteration.

**Exercise 1.18:** Compile and run the program from this section giving it only equal values as input. Run it again giving it values in which no number is repeated.

[if.cpp](src/if.cpp)

```cpp
#include <iostream>
int main()
{
    // currVal is the number we're counting; we'll read new values into val
    int currVal = 0, val = 0;
    // read first number and ensure we have data to process
    if (std::cin >> currVal) {
	int cnt = 1;  // store the count for the current value we're processing
	while (std::cin >> val) { // read the remaining numbers
	    if (val == currVal)   // if the values are the same
		++cnt;            // add 1 to cnt
	    else { // otherwise, print the count for the previous alue
		    std::cout << currVal << " occurs " << cnt << " times "
		              << std::endl;
	            currVal = val;
		    cnt = 1;
		 }
	} // while loop ends here
	// remember to print the count for the last value in the file
	std::cout << currVal << " occurs " << cnt << " times " << std::endl;
    } // outermost if statement ends here
    return 0;
}
```

**Exercise 1.19:** Revise the program you wrote for exercises in [1.4.1](#exercises-section-141) that printed a range of numbers so that it handles input in which the first number is smaller than the second.

[ex1_19.cpp](src/ex1_19.cpp)

```cpp
/* This program prompts the user for two intergers then prints each number in 
 * the range specified by those two integers */
#include <iostream>
int main()
{
    std::cout << "Enter two integers: " << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    if (v1 <= v2) {
	for (v1; v1 <= v2; v1++)
	    std::cout << v1 << " ";
    }
    else {
	for (v1; v1 >= v2; v1--)
	    std::cout << v1 << " ";
    }
    std::cout <<std::endl;
    return 0;
}
```
## Exercises Section 1.5.1
**Exercise 1.20:** Write a program that reads a set of book sales transactions, writing each transaction to the standard output.

[ex1_20.cpp](src/ex1_20.cpp)

```cpp
/* This program reads a set of book sales transactions, writing each 
 * transaction to the standard output */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item;
    while (std::cin >> item)
	std::cout << item << std::endl;
    return 0;
}
```

**Exercise 1.21:** Write a program that reads two `Sales_item` objects that have the same ISBN and produces their sum.

[ex1_21.cpp](src/ex1_21.cpp)

```cpp
/* This program reads two Sales_item objects with the same ISBN and produces 
 * their sum */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // check that item1 and item2 have the same ISBN
    if (item1.isbn() == item2.isbn()) {
	std::cout << item1 + item2 << std::endl;
	return 0;
    }
    else {
	std::cerr << "Data must refer to same ISBN" << std::endl;
	return -1;
    }
}
```

**Exercise 1.22:** Write a program that reads several transactions for the same `ISBN`. Write the sum of all the transactions that were read.

[ex1_22.cpp](src/ex1_22.cpp)

```cpp
/* This program reads several transactions for the same ISBN and writes the sum
 * of all the transactions that were read */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item sum, item;
    // read in first value as sum
    std::cin >> sum;
    // read in inputs as item
    while(std::cin >> item) {
	if (item.isbn() == sum.isbn()) {   // check that ISBN's match
	    sum += item;                   // add item to sum
	}
	else {
	    // Print error message
	    std::cerr << "Data must refer to same ISBN" << std::endl;
	    return -1;                     // indicate failure
	}
    } // end while loop
    std::cout << sum << std::endl;
    return 0;
}
```

## Exercises Section 1.5.2
**Exercise 1.23:** Write a program that reads several transactions and counts how many transactions occur for each ISBN.

[ex1_23.cpp](src/ex1_23.cpp)

```cpp
/* This program reads several transactions and counts how many transactions 
 * occur for each ISBN */
#include <iostream>
#include "Sales_item.h"
int main()
{
    Sales_item currItem, item;
    // read in first transaction and ensure there is data to process
    if (std::cin >> currItem) {
	int cnt = 1;    // store the count for the current item
	while (std::cin >> item) {              // read the remaining numbers
	    if (item.isbn() == currItem.isbn()) // if the ISBNs are the same
		++cnt;                          // add 1 to cnt
	    else { // otherwise, print the count for the previous value
		std::cout << "There were " << cnt << " transactions for ISBN "
		          << currItem.isbn() << std::endl;
		currItem = item;
		cnt = 1;
	    }
	} // while loop ends here
	std::cout << "There were " << cnt << " transactions for ISBN "
	          << currItem.isbn() << std::endl;
    } // outermost if statement ends here
    return 0;
}
```
**Exercise 1.24:** Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.
