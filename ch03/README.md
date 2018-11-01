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

### Section 3.4.1: Using Iterators

**Exercise 3.21:** Redo the first exercise from [3.3.3](#section-333-other-vector-operations) using iterators.

[**Solution:**](src/ex3_21.cpp)

```cpp
/* this program prints the size and contents of the vectors from exercise 3.13 */
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
    // initialize vector of integer vector pointers to iterate through
    vector<vector<int>*> vvi{&v1, &v2, &v3, &v4, &v5};
    // initialize string vectors
    vector<string> v6{10}, v7{10, "hi"};
    // initialize vector of string vector pointers to iterate through
    vector<vector<string>*> vvs{&v6, &v7};
    int i = 0;  // initialize counter
    for (auto it = vvi.begin(); it != vvi.end(); ++it) {
        cout << "v" << ++i << " has " << (*it)->size() << " elements:\n";
        for (auto it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    }
    for (auto it = vvs.begin(); it != vvs.end(); ++it) {
        cout << "v" << ++i << " has " << (*it)->size() << " elements:\n";
        for (auto it2 = (*it)->begin(); it2 != (*it)->end(); ++it2)
            cout << *it2 << " ";
        cout << endl;
    }
    return 0;
}
```

**Exercise 3.22:** Revise the loop that printed the first paragraph in `text` to instead change the elements in `text` that correspond to the first paragraph to all uppercase. After you've updated `text`, print its content.

**Solution:**

```cpp
for (auto it = text.begin(); it != text.end() && !it->empty(); ++it) {
    for (auto &c : *it)
        c = toupper(c);
    cout << *it << endl;
}
```

**Exercise 3.23:** Write a program to create a vector with ten `int` elements. Using an iterator, assign each element a value that is twice its current value. Test your program by printing the `vector`.

[**Solution:**](src/ex3_23.cpp)

```cpp
/* This program creates a vector with ten int elements. Using an iterator, it
 * assigns each element a value that is twice its current value. */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer object

    // prompt user to enter integers
    cout << "Enter integers: " << endl;

    while (cin >> i)  // read in integers from standard input
        ivec.push_back(i);  // append i to ivec

    for (auto it = ivec.begin(); it != ivec.end(); ++it) {
        *it *= 2;  // double the element referenced by it
        cout << *it << " ";
    }
    
    cout << endl;

    return 0;
}
```

### Section 3.4.2: Iterator Arithmetic

**Exercise 3.24:** Redo the last exercise from [3.3.3](#section-333-other-vector-operations) using iterators.

[**Solution 1:**](src/ex3_24_1.cpp)

```cpp
/* This program reads a set of integers into a vector. It then prints the sum
 * of each pair of adjacent elements */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;  // initialize empty integer vector
    int i;  // initialize integer
    while (cin >> i)  // read integers from standard input
        ivec.push_back(i);  // append i to ivec
    // print the sum of the adjacent elements
    for (auto it = ivec.cbegin(); it != ivec.cend(); it += 2)
        cout << *it + *(it + 1) << " ";
    cout << endl;
    return 0;
}
```

[**Solution 2:**](src/ex3_24_2.cpp)

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
    auto begin = ivec.begin(), end = ivec.end();
    for (auto it = begin; it != end - (end - begin) / 2 - 1; it++)
        cout << *it + *(end - (it - begin + 1)) << " ";
    // if there are an odd number of elements, then print the middle number
    if (ivec.size() % 2 != 0)
        cout << *(begin + (end - begin) / 2) << endl;
    else
        cout << endl;
    return 0;
}
```

**Exercise 3.25:** Rewrite the [grade clustering program](src/grades.cpp) from [3.3.3](#section-333-other-vector-operations) using iterators instead of subscripts.

[**Solution:**](src/ex3_25.cpp)

```cpp
/* This program reads in a collection of grades that range from 0 to 100 then
 * counts how many grades fall into various clusters of 10. Between 0 and 100
 * there are 101 possible grades. These grades can be represented by 11
 * clusters: 10 clusters of 10 grades each plus one cluster for a perfect 
 * score of 100. */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);  // 11 buckets, all initially 0
    unsigned grade;
    while (cin >> grade) {                   // read the grades
        if (grade <= 100)                    // handle only valid grades
            ++*(scores.begin() + grade/10);  // increment the counter for the current cluster
    }
    for (auto it = scores.begin(); it != scores.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
```

**Exercise 3.26:** In the binary search program on page 112, why did we write `mid = beg + (end - beg) / 2;` instead of `mid = (beg + end) / 2;`?


**Solution**: The expression `(beg + end) / 2` evaluates to an integer, since subtracting two iterators returns an integer value. We want to assign the iterator that refers to the object at position `(beg + end) / 2`, so to get an iterator object we add the expression `(end - beg) / 2` to the iterator object `beg`.

## Section 3.5: Arrays

### Section 3.5.1: Defining and Initializing Built-in Arrays

**Exercise 3.27:** Assuming `txt_size` is a function that takes no arguments and returns an `int` value, which of the following definitions are illegal? Explain why.

`unsigned buf_size = 1024;`

* (a) `int ia[buf_size];`
* (b) `int ia[4 * 7 - 14];`
* (c) `int ia[txt_size()];`
* (d) `char st[11] = "fundamental";`

**Solution:**

* (a) Illegal. `buf_size` is not a constant expression.
* (b) Legal. `4 * 7 - 14` is a constant expression.
* (c) Illegal, if `txt_size()` is not a constant expression, otherwise it is legal.
* (d) Illegal. `"fundamental"` is a string literal which ends with a null character, so there are 12 characters.

**Exercise 3.28:** What are the values in the following arrays?

```cpp
string sa[10];
int ia[10];
int main() {
    string sa2[10];
    int ia2[10];
}
```

**Solution:**

* `sa` is an array of 10 empty strings.
* `ia` is an array of 10 integers with value `0`.
* `sa2` is an array of 10 empty strings.
* `ia2` is an array of 10 undefined integers.

**Exercise 3.29:** List some of the drawbacks of using an array instead of a `vector`.

**Solution:** An array's dimension must be known at compile time and cannot change. Arrays cannot be initialized with a copy of another array nor can one array be assigned to another.

### Section 3.5.2: Accessing the Elements of an Array

**Exercise 3.30:** Identify the indexing errors in the following code:

```cpp
constexpr size_t array_size = 10;
int ia[array_size];
for (size_t ix = 1; ix <= array_size; ++ix)
    ia[ix] = ix;
```

**Solution:** 
* `ix` begins the for loop with value `1`, and since arrays are zero-indexed, no value is assigned to the first position of `ia`.
* `ix` increments until it is less than or equal to `array_size`. When `ix` holds the value `10`, it is used to index into position `10` of `ia`. However, since arrays are zero-indexed, `ia` does not have a position `10`.

**Exercise 3.31:** Write a program to define an array of ten `int`s. Give each element the same value as its position in the array.

[**Solution:**](src/ex3_31.cpp)

```cpp
/* This program defines an array of ten ints and gives each element the same
 * value as its position in the array */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int ia[10];
    for (int ix = 0; ix != 10; ix++) {
        ia[ix] = ix + 1;
    }
    for (int i; i != 10; i++)
        cout << "ia[" << i << "] = " << ia[i] << endl;
    return 0;
}
```

**Exercise 3.32:** Copy the array you defined in the previous exercise into another array. Rewrite your program to use `vector`s.

[**Solution 1:**](src/ex3_32_1.cpp)

```cpp
/* This program defines an array of ten ints and gives each element the same
 * value as its position in the array. Then it copies the values into another
 * array. */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    int ia1[10], ia2[10];  // initialize two integer arrays with dimension 10
    for (int ix = 0; ix != 10; ix++) 
        ia1[ix] = ix + 1;  // give each element the same value as its position
    for (int ix = 0; ix != 10; ix++)
        ia2[ix] = ia1[ix]; // copy the values from ia1 into ia2

    // print elements of array to verify
    for (int ix = 0; ix != 10; ix++) 
        cout << "ia1[" << ix << "] = " << ia1[ix] << "\t"
             << "ia2[" << ix << "] = " << ia2[ix] << endl;
    return 0;
}
```

[**Solution 2:**](src/ex3_32_2.cpp)

```cpp
/* This program defines a vector of ten ints and gives each element the same
 * value as its position in the array. Then it copies the values into another
 * vector */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> iv1, iv2;  // initialize two empty integer vectors
    for (int i = 1; i != 11; i++)
        iv1.push_back(i);  // append values 1 through 10 to iv1
    iv2 = iv1;  // copy iv1 to iv2

    // print elements of iv1 and iv2
    for (int i = 0; i != 10; i++)
        cout << "iv1[" << i << "] = " << iv1[i] << "\t"
             << "iv2[" << i << "] = " << iv2[i] << endl;
    return 0;
}
```

**Exercise 3.33:** What would happen if we did not initialize the `score`s array in the [program on page 116](src/pg116.cpp)?

**Solution:** If we did not initialize the `score`s array, then the initialized values would be undefined, so we incrementing them would not yield the results we want.

### Section 3.5.3: Pointers and Arrays

**Exercise 3.34:** Given that `p1` and `p2` point to elements in the same array, what does the following code do? Are there values of `p1` or `p2` that make this code illegal?

```cpp
p1 += p2 - p1
```

**Solution:** The code above evaluates the expression `p2 - p1` and take the resulting `ptrdiff_t` object and assign the sum of `p1` and `p2` to `p1`. There are no legal values for `p1` or `p2` that make this code illegal, but there are values that will cause the pointer to point outside the array. 

**Exercise 3.35:** Using pointers, write a program to set the elements in an array to zero.

[**Solution:**](src/ex3_35.cpp)

```cpp
/* This program sets the elements in an array to zero using pointers */
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
    int ia[10];                     // initialize array with undefined elements
    cout << "Initial values of the elements of ia: \n";
    for (int &ri : ia)
        cout << ri << " ";          // print all elements of ia
    cout << endl;
    int *p = begin(ia);             // initialize pointer with the first element of ia
    while (p != end(ia)) *p++ = 0;  // change all elements of ia to 0
    cout << "New values of the elements of ia: \n";
    for (int &ri : ia)
        cout << ri << " ";          // print all elements of ia
    cout << endl;
    return 0;
}
```

**Exercise 3.36:** Write a program to compare two arrays for equality. Write a similar program to compare two `vector`s.

[**Solution 1:**](src/ex3_36_1.cpp)

```cpp
/* This program compares two arrays for equality */
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::begin; using std::end;

int main()
{
    int ia1[10], ia2[10];  // initialize arrays with 10 undefined elements

    // print values of elements of arrays ia1 and ia2
    cout << "Values of the elements of ia1: \n";
    for (int &ri : ia1) cout << ri << " ";
    cout << "\nValues of the elements of ia2: \n";
    for (int &ri : ia2) cout << ri << " ";
    cout << endl;

    // compare two arrays for equality
    bool equal = 1;
    for (int ix = 0; ix != 10; ix++) {
        if (ia1[ix] != ia2[ix]) equal = 0;
    }
    if (equal) cout << "The two arrays are equal." << endl;
    else cout << "The two arrays are not equal." << endl;
    return 0;
}
```

[**Solution 2:**](src/ex3_36_2.cpp)

```cpp
/* This program compares two vectors for equality */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> iv1(10,42), iv2(10);  // initialize two vectors

    // print values of elements in vectors iv1 and iv2
    cout << "Values of the elements of iv1:\n";
    for (auto &ri : iv1) cout << ri << " ";
    cout << "\nValues of the elements of iv2:\n";
    for (auto &ri : iv2) cout << ri << " ";
    cout << endl;

    // compare vectors for equality
    if (iv1 == iv2) cout << "The two vectors are equal." << endl;
    else cout << "The two vectors are not equal."  << endl;

    return 0;
}
```

### Section 3.5.4: C-Style Character Strings

**Exercise 3.37:** What does the following program do?

```cpp
const char ca[] = {'h', 'e', 'l', 'l', 'o'};
const char *cp = ca;
while (*cp) {
    cout << *cp << endl;
    ++cp;
}
```

**Solution:** This program creates a C-style character string that is not null-terminated. It will print `hello` to the standard output then continue as the pointer `cp` is incremented to address values beyond the array.

**Exercise 3.38:** In this section, we noted that it was not only illegal but meaningless to try to add two pointers. Why would adding two pointers be meaningless?

**Solution:** Adding two pointers would be meaningless because pointers are address values. It would be difficult to predetermine what address the resulting pointer would contain.

**Exercise 3.39:** Write a program to compare two `string`s. Now write a program to compare the values of two C-style character strings.

[**Solution 1:**](src/ex3_39_1.cpp)

```cpp
/* This program compares two strings */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string s1, s2;  // initialize two empty strings
    cout << "Enter first string:" << endl;
    getline(cin, s1);
    cout << "Enter second string:" << endl;
    getline(cin, s2);
    // check equality of strings
    if (s1 == s2) 
        cout << "The two strings are equal." << endl;
    else if (s1.size() == s2.size()) 
        cout << "The two strings are equal length." << endl;
    else if (s1.size() > s2.size())
        cout << "The first string is longer than the second string." << endl;
    else if (s1.size() < s2.size()) 
        cout << "The first string is shorter than the second string." << endl;
    return 0;
}
```

[**Solution 2:**](src/ex3_39_2.cpp)

```cpp
/* This program compares two C-style strings */
#include <iostream>
#include <cstring>

using std::cin; using std::cout; using std::endl;
using std::strcmp; using std::strlen;

int main()
{
    char ca1[80], ca2[80];
    cout << "Enter first string:" << endl;
    cin.getline(ca1, 80);
    cout << "Enter second string:" << endl;
    cin.getline(ca2, 80);
    // check equality of C-style strings
    if (strcmp(ca1, ca2) == 0)
        cout << "The two strings are equal." << endl;
    else if (strlen(ca1) == strlen(ca2))
        cout << "The two strings are equal length." << endl;
    else if (strlen(ca1) < strlen(ca2))
        cout << "The first string is shorter than the second string." << endl;
    else if (strlen(ca1) > strlen(ca2))
        cout << "The first string is longer than the second string." << endl;
    return 0;
}
```

**Exercise 3.40:** Write a program to define two character arrays initialized from string literals. Now define a third character array to hold the concatenation of the two arrays. Use `strcpy` and `strcat` to copy the two arrays into the third.

[**Solution:**](src/ex3_40.cpp)

```cpp
/* This program defines two character arrays initialized from string literals
 * Then it defines a third character array to hold the concatenation of the two
 * arrays */
#include <iostream>
#include <string>
#include <cstring>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::strlen; using std::strcpy; using std::strcat;

int main()
{
    // initialize character arrays with string literals
    char ca1[] = "First string literal.";
    char ca2[] = "Second string literal.";

    cout << "First string: \"" << ca1 << "\"\n" 
         << "Second string: \"" << ca2 << "\"" << endl;

    char ca3[strlen(ca1) + strlen(ca2)]; 
    strcpy(ca3, ca1);
    strcat(ca3, " ");
    strcat(ca3, ca2);

    cout << "Third string: \"" << ca3 << "\"" << endl;

    return 0;
}
```

## Section 3.6: Multidimensional Arrays
