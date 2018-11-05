# Chapter 5: Statements

## Section 5.1: Simple Statements

**Exercise 5.1:** What is a null statement? When might you use a null statement?

**Solution:** A null statement is a single semicolon `;`. It is a statement that does nothing. We might use a null statement when the language requires a statement but our program's logic does not.

**Exercise 5.2:** What is a block? When might you use a block?

**Solution:** A block is a compound statement; it is a sequence of statements and declarations surrounded by a pair of curly braces `{}`. A block is also a scope. Compound statements are used when the language requires a statement but our program's logic requires more than one.

**Exercise 5.3:** Use the comma operator to rewrite the `while` loop from [1.4.1](../ch01/src/p11.cpp) so that it no longer requires a block. Explain whether this rewrite improves or diminishes readability of this code.

[**Solution:**](src/ex5_3.cpp)

```cpp
#include <iostream>

using std::cout; using std::endl;

int main()
{
    int sum = 0, val = 1;
    // keep executing the while as long as val is less than or equal to 10
    while (val <= 10)
        sum += val, ++val; // assigns sum + val to sum then add 1 to val
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;
    return 0;
}
```

In general, I think using blocks rather than combining expressions in a comma operator improves readability of the code. However, in this instance, I think this code remains very readable, provided the reader understands the comma operator.

## Section 5.2: Statement Scope

**Exercise 5.4:** Explain each of the following examples, and correct any problems you detect.

* (a) 

```cpp
while (string::iterator iter != s.end()) { /* ... */ }`
```

* (b) 

```cpp
while (bool status = find(word)) { /* ... */ }
if (!status) { /* ... * / }`
```

**Solution:** 

* (a) The string iterator `iter` is created and initialized on each iteration. It is also an illegal declaration. This loop would never end because it would never meet the condition that `iter == s.end`. I would correct it as such:

```cpp
string::iterator iter = s.begin();
while(iter != s.end()) { /* ... */ }
```

* (b) The `bool` `status` is created and initialized at each iteration of the `while` loop, so it is out of scope for the `if` statement. I would correct is as such:

```cpp
bool status;
while (status = find(word)) { /* ... */ }
if (!status) { /* ... */ }
```

## Section 5.3: Conditional Statements

### Section 5.3.1: The `if` Statement

**Exercise 5.5:** Using an `if-else` statement, write your own version of the program to generate the letter grade from a numeric grade.

[**Solution:**](src/ex5_5.cpp)

```cpp
/* This program generates a letter grade from an numeric grade */
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> grades;
    int grade;
    while (cin >> grade) grades.push_back(grade);

    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    vector<string> lettergrades;
    string lettergrade;

    for (auto grade : grades) {
        if (grade < 60) lettergrade = scores[0];
        else {
            lettergrade = scores[(grade - 50)/10];
            if (grade != 100)
                if (grade % 10 > 7) lettergrade += '+';
                else if (grade % 10 < 3) lettergrade += '-';
        }
        lettergrades.push_back(lettergrade);
    }

    const size_t sz = grades.size();
    cout << "Score\tLetter\n-----\t------" << endl;
    for (size_t i = 0; i != sz; ++i) 
        cout << grades[i] << "\t" << lettergrades[i] << endl;

    return 0;
}
```

**Exercise 5.6:** Rewrite your grading program to use the conditional operator [4.7](ch04#section-47-the-conditional-operator) in place of an `if-else` statement.

[**Solution:**](src/ex5_6.cpp)

```cpp
/* This program generates a letter grade from an numeric grade */
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> grades;
    int grade;
    while (cin >> grade) grades.push_back(grade);

    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    vector<string> lettergrades;
    string lettergrade;

    for (auto grade : grades) {
        lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50)/10]; 
        (grade >= 60 && grade != 100)? 
            (grade % 10 > 7) ? lettergrade += '+'
            : (grade % 10 < 3) ? lettergrade += '-'
            : lettergrade
            : lettergrade;
        lettergrades.push_back(lettergrade);
    }

    const size_t sz = grades.size();
    cout << "Score\tLetter\n-----\t------" << endl;
    for (size_t i = 0; i != sz; ++i) 
        cout << grades[i] << "\t" << lettergrades[i] << endl;

    return 0;
}
```

**Exercise 5.7:** Correct the errors in each of the following code fragments:

* (a)

```cpp
if (ival! != ival2)
    ival1 = ival2
else ival1 = ival2 = 0;
```

* (b) 

```cpp
if (ival < minval)
    minval = ival;
    occurs = 1;
```

* (c) 

```cpp
if (int ival = get_value())
    cout << "ival = " << ival << endl;
if (!ival)
    cout << "ival = 0\n";
```

* (d)

```cpp
if (ival = 0)
    ival = get_value();
```

**Solution:**

* (a) The `if else` statement is missing a `;` in the first statement.

```cpp
if (ival != ival2)
    ival1 = ival2;
else ival1 = ival2 = 0;
```

* (b) The statement `occurs = 1;` is outside of the `if` statement, we need to use a block.

```cpp
if (ival < minval) {
    minval = ival;
    occurs = 1;
}
```

* (c) `ival` is initialized inside the condition of the first `if` statement, so it is not within scope for the second `if` statement.

```cpp
int ival = get_value();
if (ival)
    cout << "ival = " << ival << endl;
else 
    cout << "ival = 0" << endl;
```

* (d) `ival` is being assigned the value `0` in the condition, rather than checking if it is nonzero.

```cpp
if (ival)
    ival = get_value();
```

**Exercise 5.8:** What is a "dangling `else`"? How are `else` clauses resolved in C++?

**Solution:** A dangling `else` statement is an issue that arises when using more `if` branches than `else` branches. `else` clauses are resolved by matching each `else` with the closest preceding unmatched `if`. The best way to manage the execution path of `if else` statements to avoid a dangling `else` is to use braces.

### Section 5.3.2: The `switch` Statement

**Exercise 5.9:** Write a program using a series of `if` statements to count the number of vowels in text read from cin.

[**Solution:**](src/ex5_9.cpp)

```cpp
/* This program uses a series of if statements to count the number of vowels 
 * in text read from the standard input */
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        ch = tolower(ch);
        if (ch == 'a') ++aCnt;
        else if (ch == 'e') ++eCnt;
        else if (ch == 'i') ++iCnt;
        else if (ch == 'o') ++oCnt;
        else if (ch == 'u') ++uCnt;
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << endl;

    return 0;
}
```

**Exercise 5.10:** There is one problem with our vowel-counting program as we've implemented it. It doesn't count capital letters as vowels. Write a program that counts both lower- and uppercase letters as the appropriate vowel--that is, your porgram should count both `'a'` and `'A'` as part of `aCnt` and sof forth.

[**Solution:**](src/ex5_10.cpp)

```cpp
/* This program uses a switch statement to count the number of vowels in text
 * read from standard input */ 
#include <iostream>

using std::cin; using std::cout; using std::endl;

int main()
{
    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> ch) {
        ch = tolower(ch);
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
        }
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << endl;

    return 0;
}
```

**Exercise 5.11:** Modify our vowel-counting program so that it also counts the number of blank spaces, tabs, and newlines read.

[**Solution:**](src/ex5_11.cpp)

```cpp
/* This program uses a switch statement to count the number of vowels, blank 
 * spaces, tabs, and newlines read from standard input */
#include <iostream>

using std::cin; using std::cout; using std::endl; using std::noskipws;

int main()
{
    // initialize counters for each vowel, blank spaces, tabs, and newlines
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             spCnt = 0, tabCnt = 0, nwlCnt = 0;
    char ch;
    while (cin >> noskipws >> ch) {
        ch = tolower(ch);
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++nwlCnt;
                break;
        }
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << "\n"
         << "Number of spaces:\t" << spCnt << "\n"
         << "Number of tabs:\t\t" << tabCnt << "\n"
         << "Number of newlines:\t" << nwlCnt << endl;

    return 0;
}
```

**Exercise 5.12:** Modify our vowel-counting program so that it counts the number of occurences of the following two-character sequences `ff`, `f1`, and `fi`.

[**Solution:**](src/ex5_12.cpp)

```cpp
/* This program uses a switch statement to count the number of vowels, blank 
 * spaces, tabs, newlines, ff, f1, and fi read from standard input */
#include <iostream>

using std::cin; using std::cout; using std::endl; using std::noskipws;

int main()
{
    // initialize counters for each vowel, blank spaces, tabs, newlines
    // ff, f1, and fi
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0,
             spCnt = 0, tabCnt = 0, nwlCnt = 0,
             ffCnt = 0, f1Cnt = 0, fiCnt = 0;
    char ch, chOld;
    while (cin >> noskipws >> ch) {
        ch = tolower(ch);
        switch(ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                if (chOld == 'f') ++fiCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u':
                ++uCnt;
                break;
            case ' ':
                ++spCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case '\n':
                ++nwlCnt;
                break;
            case '1':
                if (chOld == 'f') ++f1Cnt;
                break;
            case 'f':
                if (chOld == 'f') ++ffCnt;
        }
        chOld = ch;
    }
    // print results
    cout << "Number of vowel a:\t" << aCnt << "\n"
         << "Number of vowel e:\t" << eCnt << "\n"
         << "Number of vowel i:\t" << iCnt << "\n"
         << "Number of vowel o:\t" << oCnt << "\n"
         << "Number of vowel u:\t" << uCnt << "\n"
         << "Number of spaces:\t" << spCnt << "\n"
         << "Number of tabs:\t\t" << tabCnt << "\n"
         << "Number of newlines:\t" << nwlCnt << "\n"
         << "Number of ff's:\t\t" << ffCnt << "\n"
         << "Number of f1's:\t\t" << f1Cnt << "\n"
         << "Number of fi's:\t\t" << fiCnt << endl;

    return 0;
}
```

**Exercise 5.12:** Each of the programs highlighted text on page 184 contain a common programming error. Identify and correct each error.

* (a) 

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_text();
switch (ch) {
    case 'a': aCnt++;
    case 'e': eCnt++;
    default: iouCnt++;
}
```

* (b) 

```cpp
unsigned index = some_value();
switch (index) {
    case 1:
        int ix = get_value();
        ivec[ ix ] = index;
        break;
    default:
        ix = ivec.size() - 1;
        ivec[ ix ] = index;
}
```

* (c)

```cpp
unsigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
}
```

* (d)

```cpp
unsigned ival=512, jval=1024, kval=4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

**Solution:**

* (a) The first two cases do not have a `break` statement. As well, there is an unnecessary usage of the postfix increment operators.

```cpp
unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
char ch = next_test()
switch (ch) {
    case 'a': ++aCnt; break;
    case 'e': ++eCnt; break;
    default: ++iouCnt; break;
}
```

* (b) `ix` is defined in the `case 1` clause of the `switch`, so it may be out of scope in the `default` case. The `default` case is also missing a `break` statement.

```cpp
unsigned index = some_value()
switch(index) {
    case 1:
        ivec[get_value()] = index;
        break;
    default:
        ivec[ivec.size() - 1] = index;
        break;
```

* (c) Each integer needs its own `case` label. Also, the `c`s in `oddcnt` and `evencnt` need  to be capitalized. There is also unnecessary use of the postfix increment operators. Also, `digit` will never be `10`, it should check for value `0`.

```cpp
usigned evenCnt = 0, oddCnt = 0;
int digit = get_num() % 10;
switch (digit) {
    case 1: case 3: case 5: case 7: case 9:
        ++oddCnt;
        break;
    case 0: case 2: case 4: case 6: case 8:
        ++evenCnt;
        break;
}
```

A better way to count evens and odds using a `switch` statement is below:

```cpp
unsigned evenCnt = 0, oddCnt = 0;
bool odd = get_num() % 2;
switch (odd) {
    case 1:
       ++oddCnt;
       break;
    case 0:
       ++evenCnt;
       break;
}
```

* (d) The `case` values must be constant integral expressions.

```cpp
const unsigned ival = 512, jval = 1024, kval = 4096;
unsigned bufsize;
unsigned swt = get_bufCnt();
switch(swt) {
    case ival:
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
}
```

## Section 5.4: Iterative Statements

### Section 5.4.1: The `while` Statement

**Exercise 5.14:** Write a program to read `string`s from standard input looking for duplicated words. The program should find places in the input where one word is followed immediately by itself. Keep track of the largest number of times a single repetition occurs and which word is repeated. Print the maximum number of duplicates, or else print a message saying that no word was repeated. For example if the input is 
``` 
how now now now brown cow cow 
```
the output should indicate that the word `now` occurred three times.

[**Solution:**](src/ex5_14.cpp)

```cpp
/* This program reads strings from standard input and looks for duplicated words */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string word, oldWord, maxWord;
    cin >> oldWord;
    unsigned cnt = 1, maxCnt = 0;
    while (cin >> word) {
        if (word == oldWord) 
            ++cnt;
        else if (cnt > maxCnt) {
            maxCnt = cnt;
            maxWord = oldWord;
            cnt = 1;
        }
        else cnt = 1;
        oldWord = word;
    }

    if (cnt > maxCnt) {
        maxCnt = cnt;
        maxWord = oldWord;
    }

    cout << "The word " << maxWord << " occured " << maxCnt << " times." << endl;

    return 0;
}
```

### Section 5.4.2: Traditional `for` Statement

**Exercise 5.15:** Explain each of the following loops. Correct any problems you detect.

* (a) 

```cpp
for (int ix = 0; ix != sz; ++ix) { /* ... */ }
if (ix != sz)
    // ...
```

* (b)

```cpp
int ix;
for (ix != sz; ++ix) { /* ... */ }
```

* (c)

```cpp
for (int ix = 0; ix != sz; ++ix, ++sz) { /* ... */ }
```

**Solution:** 

* (a) `ix` cannot be used in the `if` statement because it is defined in the init-statement of the `for` loop. Also, the `if` statement is redundant; once the condition `ix != sz` is `true`, the `for` loop ends. So when the `for` loop ends, it means that `ix != sz` is `true`.

```cpp
for (int ix = 0; ix != sz; ++ix) { /* ... */ }
// ...
```

If for some reason we do still need to check if the condition `ix != sz` is true, we can initialize `ix` outside of the `for` loop so it is within scope for the `if` statement.

```cpp
int ix;
for (ix = 0; ix != sz; ++ix) { /* ... */ }
if (ix != sz)
    // ...
```

* (b) The `for` header is missing a `;` for the init-statement.

```cpp
int ix;
for ( /* null */ ; ix != sz; ++ix) { /* ... */ }
```

* (c) This `for` loop will likely not end unless `ix` is incremented elsewhere in the `for` statement.

```cpp
for (int ix = 0; ix != sz; ++ix) { /* ... */ }
```

**Exercise 5.16:** The `while` loop is particularly good at executing while some condition holds; for example, when we need to read values unti end-of-file. The `for` loop is generally thought of as a step loop: An index steps through a range of values in a collection. Write an idiomatic use of each loop and then rewrite each using the other loop construct. If you could only use one loop, which would you choose? Why?

**Solution:** 

```cpp
for (auto iter = vec.begin(); iter != vec.end(); ++iter) { /* ... */ }

auto iter = vec.begin();
while (iter != vec.end() { /* ... */ }
```

```cpp
string word;
while (cin >> word) { /* ... */ }

for (string word; /* null */ ; /* null */ ) {
        if (cin >> word) { /* ... */ }
        else break;
}
```

I would choose the `for` loop. The `for` loop can do what a `while` loop can, but a `while` loop cannot do everything that a `for` loop can.

**Exercise 5.17:** Given two `vector`s of `int`s, write a program to determine whether one `vector` is a prefix of the other. For `vector`s of unequal length, compare the number of elements of the smaller `vector`. For example, given the `vector`s containing `0`, `1`, `1`, and `2` and `0`, `1`, `1`, `2`, `3`, `5`, `8`, respectively your program should return `true`.

[**Solution:**](src/ex5_17.cpp)

```cpp
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl; using std::noskipws;
using std::vector;

int main()
{
    vector<int> v1, v2;
    char c;
    int i;
    while (cin >> noskipws >> c) {
        if (isspace(c)) break;
        else {
            i = c - '0';
            v1.push_back(i);
        }
    }
    while (cin >> noskipws >> c) {
        i = c - '0';
        v2.push_back(i);
    }
    size_t smallSz = (v1.size() < v2.size()) ? v1.size() : v2.size();
    bool prefix = 1;
    for (size_t ix = 0; ix != smallSz; ++ix) 
        if (v1[ix] != v2[ix]) prefix = 0;
    return prefix;
}
```

### Section 5.4.3: Range `for` Statement

### Section 5.4.4: The `do while` Statement

**Exercise 5.18:** Explain each of the following loops. Correct any problems you detect.

* (a)

```cpp
do
    int v1, v2;
    cout << "Please enter two numbers to sum:" ;
    if (cin >> v1 >> v2)
        cout << "Sum is: " << v1 + v2 << endl;
while (cin);
```

* (b)

```cpp
do {
    // ...
} while (int ival = get_response());
```

* (c)

```cpp
do {
    int ival = get_response();
} while (ival);
```

**Solution:**

* (a) The `do` statement is missing brackets.

```cpp
do {
    int v1, v2;
    cout << "Please enter two numbers to sum: ";
    if (cin >> v1 >> v2)
        cout << "Sum is " << v1 + v2 << endl;
} while (cin);
```

* (b) There is a declaration in the `do while` condition.

```cpp
int ival;
do {
   ival = get_response();
   // ...
} while (ival);
```

* (c) Variables used in the `do while` condition must be defined outside the body of the `do while` statement.

```cpp
int ival;
do {
    ival = get_response();
} while (ival);
```

**Exercse 5.19:** Write a program that uses a `do while` loop to repetitively request two `string`s from the user and report which `string` is less than the other.

[**Solution:**](src/ex5_19.cpp)

```cpp
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;

int main()
{
    do {
        string s1, s2;
        cout << "Enter the first string:" << endl;
        getline(cin, s1);
        cout << "Enter the second string:" << endl;
        getline(cin, s2);
        if (s1.size() > s2.size())
            cout << "The first string is longer than the second string." << endl;
        else if (s1.size() < s2.size())
            cout << "The first string is shorter than the second string." << endl;
        else if (s1.size() == s2.size())
            cout << "The strings are the same length." << endl;
    } while (cin);
    
    return 0;
}
```

## Section 5.5: Jump Statements

### Section 5.5.1: The `break` Statement

**Exercise 5.20:** Write a program to read a sequence of `string`s from the standard input until either the same word occurs twice in succession or all the words have been read. Use a `while` loop to read the text one word at a time. Use the `break` statement to terminate the loop if a word occurs twice in succession. Print the word if it occurs twice in succession, or else print a message saying that no word was repeated.

[**Solution:**](src/ex5_20.cpp)

```cpp
/* This program reads a sequence of strings from the standard input until
 * either the same word occurs twice in succession or all the words have 
 * been read. */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string word, oldWord; // initialize empty strings
    cin >> oldWord;       // read first string from standard input
    while (cin >> word) { // read strings from standard input
        // if a word is repeated print word and terminate loop
        if (word == oldWord) {
            cout << "The word \"" << word << "\" was repeated." << endl;
            break;
        }
        oldWord = word; // copy the value from word into oldWord
    }
    if (!cin) cout << "No words were repeated." << endl;
    return 0;
}
```

### Section 5.5.2: The `continue` Statement

**Exercise 5.21:** Revise the program from the exercise in [5.5.1](#section-551-the-break-statement) so that it looks only for duplicated words that start with an uppercase letter.

[**Solution:**](src/ex5_21.cpp)

```cpp
/* This program reads a sequence of strings from the standard input until
 * either the same word that begins with an uppercase letter is repeated
 * or all the words have been read. */
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    string word, oldWord; // initialize empty strings
    while (cin >> word) { // read strings from standard input
        // if word does not begin with an uppercase letter continue to next word
        if (!isupper(word[0])) {
            oldWord = word;
            continue;
        }
        // if a word is repeated print word and terminate loop
        if (word == oldWord) {
            cout << "The word \"" << word << "\" was repeated." << endl;
            break;
        }
        oldWord = word; // copy the value from word into oldWord
    }
    if (!cin) cout << "No words that begin with an uppercase letter were repeated." << endl;
    return 0;
}
```

## Section 5.6: `try` Blocks and Exception Handling
