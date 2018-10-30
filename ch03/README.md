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
/* This program reads several transactions for the same ISBN and writes the sum
 * of all the transactions that were read */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    // Define sum and item Sales_data objects
    Sales_data sum, item;
    // Read in the first values as members of sum
    cin >> sum.bookNo >> sum.units_sold >> sum.revenue;
    // Read in input as members of item
    while (cin >> item.bookNo >> item.units_sold >> item.revenue) {
        if (item.bookNo == sum.bookNo) {  // check that bookNo's match
            sum.units_sold += item.units_sold;
            sum.revenue += item.revenue;
        } else {  // print error message if bookNo's don't match
            cerr << "Data must refer to same bookNo" << endl;
            return -1;  // indicate failure
        }
    }  // end while loop
    // Print sum of transactions
    cout << sum.bookNo << " " << sum.units_sold << " " << sum.revenue << endl;
    return 0;
}
```

[**Exercise 1.23 Solution:**](src/ex3_1_7.cpp)

```cpp
/* This program reads several transactions and counts how many transactions
 * occur for each bookNo */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    // Define Sales_data objects
    Sales_data currItem, item;
    // Read in first transaction and ensure there is data to process
    if (cin >> currItem.bookNo >> currItem.units_sold >> currItem.revenue) {
        int cnt = 1;  // store the count for the current item
        // Read the remaining transactions
        while (cin >> item.bookNo >> item.units_sold >> item.revenue) {
            if (item.bookNo == currItem.bookNo)  // check if the bookNo's are the same
                ++cnt;  // iterate count
            else {  // otherwise, print the count for the previous value
                cout << "There were " << cnt << " transactions for book number "
                     << currItem.bookNo << endl;
                currItem = item;  // assign item to currItem
                cnt = 1;          // reset count
            }
        }  // end while loop
        // Print data from last bookNo
        cout << "There were " << cnt << " transactions for book number "
             << currItem.bookNo << endl;
    } else {  // print error message if there is no data
        cerr << "No Data?!" << endl;
        return -1;  // indicate failure
    }
    return 0;
}
```

[**Exercise 1.25 Solution:**](src/ex3_1_8.cpp)

```cpp
/* This program reads in transactions from standard input, sums the totals for
 * the same bookNos, then prints to standard output. */
#include <iostream>
#include "Sales_data.h"
using std::cin; using std::cout; using std::endl; using std::cerr;
int main()
{
    Sales_data total;  // object to hold the data for the next transaction
    // Read the first transaction and ensure there are data to process
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data trans;  // object to hold the running sum
        // Read and process the remaining transactions
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // If we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // Print results for previous book
                cout << total.bookNo << " " << total.units_sold << " "
                     << total.revenue << endl;
                total = trans;  // total now refers to the next book
            }
        }  // end while loop
        cout << total.bookNo << " " << total.units_sold << " " 
             << total.revenue << endl;
    } else {  // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1;  // indicate failure
    }
    return 0;
}
```

## Section 3.2: Library `string` Type

## Section 3.3: Library `vector` Type

## Section 3.4: Introducing Iterators

## Section 3.5: Arrays

## Section 3.6: Multidimensional Arrays
