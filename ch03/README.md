# Chapter 3: Strings, Vectors, and Arrays

## Section 3.1: Namespace `using` Declarations

**Exercise 3.1:** Rewrite the exercises from [1.4.1](../ch01#section-141-the-while-statement) and [2.6.2](../ch02#section-262-using-the-sales_data-class) with appropriate `using` declarations.

[**Exercise 1.9 Solution:**](src/ex3_1_1.cpp)

```cpp
#include <iostream>
using std::cout; using std::endl;
int main()
{
    int sum = 0, i = 50;
    // Keep executing the while as long as i is less than or equal to 100
    while (i <= 100) {
        sum += i;
        i++;
    }
    cout << "Sum of 50 to 100 inclusive is " << sum << endl;
    return 0;
}
```

[**Exercise 1.10 Solution:**](src/ex3_1_2.cpp)

```cpp
/* This program prints the numbers from 10 down to 0 */
#include <iostream>
using std::cout; using std::endl;
int main()
{
    int i = 10;
    while (i >= 0) {
        cout << i << " ";
        i--;
    }
    cout << endl;
    return 0;
}
```

[**Exercise 1.11 Solution:**](src/ex3_1_3.cpp)

```cpp
/* This program prompts the user for two integers then prints each number in
 * the range specified by those two integers */
#include <iostream>
using std::cin; using std::cout; using std::endl;
int main()
{
    cout << "Enter two integers: " << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    while (v1 <= v2) {
        cout << v1 << " ";
        v1++;
    }
    cout << endl;
    return 0;
}
```

[**Exercise 1.20 Solution:**](src/ex3_1_4.cpp)

```cpp
/* This program reads a set of book sales transactions, writing each
 * transaction to the standard output */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl;
int main()
{
    Sales_data item;
    while (cin >> item.bookNo >> item.units_sold >> item.revenue)
        cout << item.bookNo << " " << item.units_sold << " "
             << item.revenue << endl;
    return 0;
}
```

[**Exercise 1.21 Solution:**](src/ex3_1_5.cpp)

```cpp
/* This program reads two Sales_data objects with the same bookNo and produces
 * their sum */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    // Define two Sales_data objects
    Sales_data item1, item2;
    // Read in data from standard input
    cin >> item1.bookNo >> item1.units_sold >> item1.revenue
        >> item2.bookNo >> item2.units_sold >> item2.revenue;
    // Check that item1 and item2 have the same bookNo
    if (item1.bookNo == item2.bookNo) {
        cout << item1.bookNo << " "
             << item1.units_sold + item2.units_sold << " "
             << item1.revenue + item2.revenue << " "
             << endl;
        return 0;
    } else {  // otherwise, print error message
        cerr << "Data must refer to the same bookNo" << endl;
        return -1;  // indicate failure`
    }
}
```

[**Exercise 1.22 Solution:**](src/ex3_1_6.cpp)

```cpp

```

[**Exercise 1.23 Solution:**](src/ex3_1_7.cpp)

```cpp

```

[**Exercise 1.25 Solution:**](src/ex3_1_8.cpp)

```cpp

```

## Section 3.2: Library `string` Type

## Section 3.3: Library `vector` Type

## Section 3.4: Introducing Iterators

## Section 3.5: Arrays

## Section 3.6: Multidimensional Arrays
