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

### Section 3.2.1: Defining and Initializing `strings`

### Section 3.2.2: Operations on `strings`

**Exercise 3.2:** Write a program to read the standard input a line at a time. Modify your program to read a word at a time.

[**Solution 1:**](src/ex3_2_1.cpp)

```cpp
/* This program reads the standard input a line at a time */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;
int main()
{
    string line;                // initialize empty string
    while (getline(cin, line))  // read line from standard input
        cout << line << endl;   // print line to standard output
    return 0;
}
```

[**Solution 2:**](src/ex3_2_2.cpp)

```cpp
/* This program reads the standard input one word at a time */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string word;               // initialize empty string
    while (cin >> word)        // read word from standard input 
        cout << word << endl;  // write word to standard output
    return 0;
}
```

**Exercise 3.3:** Explain how whitespace characters are handled in the `string` input operator and in the `getline` function.

**Solution:** The `string` input operator reads and discards leading whitespace then reads characters until the next whitespace character. So the `string` input operator will not read in whitespace. The `getline` function reads an input stream up to and including the first newline and stores what it read excluding the newline, but including any whitespace characters.

**Exercise 3.4:** Write a program to read two `string`s and report whether the `string`s are equal. If not, report which of the two is larger. Now, change the program to report whether the `string`s have the same length, and it not, report which is longer.

[**Solution 1:**](src/ex3_4_1.cpp)

```cpp
/* This program reads two strings and reports whether the strings are equal.
 * If not, the program reports which of the two is larger. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;
int main()
{
    string s1, s2;    // initialize two empty strings
    cin >> s1 >> s2;  // read in two strings from standard input
    if (s1 == s2)     // check if strings are equal
        cout << "\"" << s1 << "\" and \"" << s2 << "\" are equal." << endl;
    else {
        if (s1 > s2)  // check if s1 is greater than s2
            cout << "\"" << s1 << "\" is greater than \"" << s2 << "\"" << endl;
        else
            cout << "\"" << s2 << "\" is greater than \"" << s1 << "\"" << endl;
    }
    return 0;
}
```

[**Solution 2:**](src/ex3_4_2.cpp)

```cpp
/* This program reads two strings and reports whether the strings have the
 * same length. If not, then it reports which one is longer. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s1, s2;                  // initialize two empty strings
    cin >> s1 >> s2;                // read two strings from standard input
    if (s1.size() == s2.size())     // check if the two strings have the same length
        cout << "\"" << s1 << "\" and \"" << s2 << "\" are the same length" << endl;
    else {
        if (s1.size() > s2.size())  // check if s1 is longer than s2
            cout << "\"" << s1 << "\" is longer than \"" << s2 << "\"" << endl;
        else
            cout << "\"" << s2 << "\" is longer than \"" << s1 << "\"" << endl;
    }
    return 0;
}
```

**Exercise 3.5:** Write a program to read `string`s from the standard input, concatenating what is read into one large `string`. Print the concatenated `string`. Next, change the program to separate adjacent input `string`s by a space.

[**Solution 1:**](src/ex3_5_1.cpp)

```cpp
/* This program reads strings from the standard input, concatenating what is
 * read into one large string. Then it prints the concatenated string */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string concat, s;  // initialize empty strings
    while (cin >> s)   // read from standard input
        concat += s;   // concatenate into one long string
    cout << concat << endl;
    return 0;
}
```

[**Solution 2:**](src/ex3_5_2.cpp)

```cpp
/* This program reads strings from the standard input, concatenating what is
 * read into onge large string, separating adjacent input strings by a space.
 * Then it prints the string to the standard output */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string concat, s;        // initialize empty strings
    cin >> concat;           // read first string to concat
    while (cin >> s)         // read from standard input
        concat += " " + s;   // concatenate strings with whitespace between
    cout << concat << endl;  // print to standard output
    return 0;
}
```

### Section 3.2.3: Dealing with the Characters in a `string`

**Exercise 3.6:** Use a range `for` to change all the characters in a `string` to `X`.

[**Solution:**](src/ex3_6.cpp)

```cpp
/* This program uses a range for to change all the characters in a string to X */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;  // initialize empty string s
    cin >> s;  // read string from standard input to s
    for (auto &c : s)  // for every char c in string s
        c = 'X';       // assign the value 'X' to char in s
    cout << s << endl;
    return 0;
}
```

**Exercise 3.7:** What would happen if you define the loop control in the previous exercise as type `char`? Predict the results and then change your program to use a `char` to see if you were right.

[**Solution:**](src/ex3_7.cpp) The program should run as intended without any changes.

```cpp
/* This program uses a range for to replace all the characters in a string to
 * 'X', but defines the loop control variable */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;           // initialize empty string s
    cin >> s;            // read string from standard input into s
    for (char &c : s)   // for char c in string s
        c = 'X';        // replace char in s with 'X'
    cout << s << endl;  // print s to standard output
    return 0;
}
```

**Exercise 3.8:** Rewrite the program in the first exercise, first using a `while` and again using a traditional `for` loop. Which of the three approaches do you prefer and why?

[**Solution 1:**](src/ex3_8_1.cpp)

```cpp
/* This program uses a while loop to replace all characters in a string with 'X' */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;   // initialize empty string s
    cin >> s;   // read string from standard input into s
    int i = 0;  // initialize iterator
    while (i < s.size()) {  // while i is less than the length of s
        s[i] = 'X';  // replace character in position i with 'X'
        i++;         // increment i by 1
    }  // end while loop
    cout << s << endl;  // print string to standard output
    return 0;
}
```

[**Solution 2:**](src/ex3_8_2.cpp)

```cpp
/* This program uses a traditional for loop to replace all characters in a 
 * string with 'X' */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;  // initialize empty string s
    cin >> s;  // read string from standard input into s
    for (int i = 0; i < s.size(); i++) 
        s[i] = 'X';  // replace character in position i with 'X'
    cout << s << endl;
    return 0;
}
```
I prefer to use the range `for` loop in this situation, it appears to be the most streamlined option to code.

**Exercise 3.9:** What does the following program do? Is it valid? If not, why not?

```cpp
string s;
cout << s[0] << endl;
```

**Solution:** This program prints the `char` in the first position of the `string` `s` to the standard ouput. It is valid, but it prints nothing because `s` is initialized as an empty `string`.

**Exercise 3.10:** Write a program that reads a string of characters including punctuation and writes what was read but with the punctuation removed."

[**Solution:**](src/ex3_10.cpp)

```cpp
/* This program reads a string of characters including punctuation and writes
 * what was read but with the punctuation removed. */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string s;   // initialize empty string s 
    cin >> s;   // read string from standard input into s
    int i = 0;  // initialize iterator
    while (i < s.size()) { 
        if (ispunct(s[i]))  // delete character if punctuation
            s.erase(i,1);
        else                // move onto next position if character is not punctuation
            i++;
    }
    cout << s << endl;
    return 0;
}
```

**Exercise 3.11:** Is the following range `for` legal? If so, what is the type of `c`?

```cpp
const string s = "Keep out!";
for (auto &c : s) { /* ... */ }
```

**Solution:** Yes, it is legal. `c` is a reference to a `const` character.

## Section 3.3: Library `vector` Type

### Section 3.3.1: Defining and Initializing `vectors`

**Exercise 3.12:** Which, if any, of the following `vector` definitions are in error? For those that are legal, explain what the definition does. For those that are not legal, explain why they are illegal.

* (a) `vector<vector<int>> ivec;`
* (b) `vector<string> svec = ivec;`
* (c) `vector<string> svec(10, "null");`


**Solution:** 

* (a) Legal. `ivec` is an empty `vector` of `vector`s of `int`s.
* (b) Illegal. `svec` is a `vector` of `string`s and cannot be initialized with `ivec`.
* (c) Legal. `svec` is a `vector` of `string`s with 10 elements with value `"null"`.

**Exercise 3.13:** How many elements are there in each of the following `vectors`? What are the values of the elements?

* (a) `vector<int> v1;`
* (b) `vector<int> v2(10);`
* (c) `vector<int> v3(10, 42);`
* (d) `vector<int> v4{10};`
* (e) `vector<int> v5{10, 42};`
* (f) `vector<string> v6{10};`
* (g) `vector<string> v7{10, "hi"};`

**Solution:**

* (a) `v1` has no elements; it is the empty vector.
* (b) `v2` has 10 elements each initialized with `0`.
* (c) `v3` has 10 elements each initialized with `42`.
* (d) `v4` has 1 element initialized with `10`.
* (e) `v5` has 2 elements with values `10` and `42`.
* (f) `v6` has 10 elements default-initialized to the empty `string`.
* (g) `v7` has 10 elements initialized with `hi`.

### Section 3.3.2: Adding Elements to a `vector`

**Exercise 3.14:** Write a program to read a sequence of `int`s from `cin` and store those values in a `vector`.

[**Solution:**](src/ex3_14.cpp)

```cpp
/* This program reads a sequence of ints from cin and stores the values in a vector */
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;  // initialize empty int vector
    int i;             // initialize integer i
    while (cin >> i) // read integers from standard input into i
        ivec.push_back(i);  // append i to ivec
    for (auto &ri : ivec)
        cout << ri << endl;  // read elements of ivec to standard output
    return 0;
}
```

**Exercise 3.15:** Repeat the previous program but read `string`s this time.

[**Solution:**](src/ex3_15.cpp)

```cpp
/* This program reads a sequence of strings from cin and stores the values in a vector */
#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> svec;  // initialize empty string vector
    string s;             // initialize empty string
    while (cin >> s)  // read strings from standard input into s
        svec.push_back(s);  // append s to svec
    for (auto &rs : svec)
        cout << rs << endl;  // read elements of svec to standard output
    return 0;
}
```

### Section 3.3.3: Other `vector` Operations

**Exercise 3.16:** Write a program to print the size and contents of the `vectors` from exercise [3.13](#section-331-defining-and-initializing-vectors). Check whether your answers to that exercise were correct. If not, restudy [3.3.1](#section-331-defining-and-initializing-vectors) until you understand why you were wrong.

[**Solution:**](src/ex3_16.cpp)

```cpp
/* This program prints the size and contents of the vectors from exercise 3.13 */
#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
int main()
{
    // initialize integer vectors
    vector<int> v1, v2(10), v3(10, 42), v4{10}, v5{10, 42};
    // initialive vector of integer vectors to iterate through
    vector<vector<int>> vvi{v1, v2, v3, v4, v5};
    // initialize string vectors
    vector<string> v6{10}, v7{10, "hi"};
    // initialize vector of strings to iterate through
    vector<vector<string>> vvs{v6, v7};
    int i = 0;
    for (auto &rvi : vvi) {
        cout << "v" << ++i << " has " << rvi.size() << " elements:\n";
        for (auto &ri : rvi)
            cout << ri << " ";
        cout << endl;
    }
    for (auto &rvs : vvs) {
        cout << "v" << ++i << " has " << rvs.size() << " elements:\n";
        for (auto &rs : rvs)
            cout << rs << " ";
        cout << endl;
    }
    return 0;
}
```

**Exercise 3.17:** Read a sequence of words from `cin` and store the values in a `vector`. After you've read all the words, process the `vector` and change each word to uppercase. Print the transformed elements, eight words to a line.

[**Solution:**](src/ex3_17.cpp)

```cpp
/* This program reads a sequence of words from cin and stores the value in a
 * a vector. After the words are read, it processes the vector to change each
 * word to uppercase. Then it prints the transformed elements. */
#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> sv;    // initialize empty string vector
    string s;             // initialize empty string
    while (cin >> s)      // read in strings from standard input
        sv.push_back(s);  // append s to sv
    int i = 0;            // initialize counter
    for (string &c : sv) {  // iterate through the elements of sv
        if (i < 8) {  // print character and space if i is less than 8 
            cout << c << " ";
            i++;  // increment i by 1
        } else {  // otherwise, print character and newline
            cout << c << "\n";
            i = 0;  // reset counter
        }
    }
    cout << endl;
    return 0;
}
        
```

**Exercise 3.18:** Is the following program legal? If not, how might you fix it?

```cpp
vector<int> ivec;
ivec[0] = 42;
```

**Solution:** No, it is illegal. `ivec` is an empty integer `vector`, so we cannot assign a value to `ivec[0]` because it does not exist. It can be fixed by using `push_back` to append `42` to `ivec`.

```cpp
vector<int> ivec;
ivec.push_back(42);
```

**Exercise 3.19:** List three ways to define a `vector` and give it ten elements, each with the value 42. Indicate whether there is a preferred way to do so and why.

**Solution:** 

```cpp
// Initialize the vector with 10 elements with value 42
vector<int> ivec(10, 42);
// Initialize empty vector, then append 42 10 times
vector<int> ivec;
for (int i = 0; i < 10; i++)
    ivec.push_back(42);
// Initialize a vector of size 10, then change all values to 42
vector<int> ivec(10);
for (int i = 0; i < 10; i++)
    ivec[i] = 42;
```  

The first way is the preferred way. It is typically more efficient to define an empty `vector` and add elements at run time, but the only exception to this is when all elements need to be the same value.

**Exercise 3.20:** Read a set of integers into a `vector`. Print the sum of each pair of adjacent elements. Change your program so that it prints the sum of the first and last elements, followed by the sum of the second and second-to-last, and so on.

[**Solution 1:**](src/ex3_20_1.cpp)

```cpp
/* This program reads a set of integers into a vector. It then prints the sum
 * of each pair of adjacent elements. */
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer
    while (cin >> i)   // read integers from standard input
        ivec.push_back(i);  // append i to ivec
    // Print the sum of adjacent elements
    for (int j = 0; j < ivec.size(); j += 2) 
        cout << ivec[j] + ivec[j + 1] << endl;
    return 0;
}
```

[**Solution 2:**](src/ex3_20_2.cpp)

```cpp
/* This program reads a set of integers into a vector. It then prints the sum
 * of the first and last elements, followed by the sum of the second and
 * second-to-last, and so on. */
#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;
int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer
    while (cin >> i)  // read integers from standard output
        ivec.push_back(i);  // append i to ivec
    // print sums
    for (int j = 0; j < ivec.size() / 2; j++)
        cout << ivec[j] + ivec[ivec.size() - (j + 1)] << " ";
    // if there are an odd number of elements, then print the middle number
    if (ivec.size() % 2 != 0)
        cout << ivec[ivec.size() / 2] << endl;
    else
        cout << endl;
    return 0;
}
```

## Section 3.4: Introducing Iterators

## Section 3.5: Arrays

## Section 3.6: Multidimensional Arrays