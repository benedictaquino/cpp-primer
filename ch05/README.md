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

## Section 5.4: Iterative Statements

## Section 5.5: Jump Statements

## Section 5.6: `try` Blocks and Exception Handling
