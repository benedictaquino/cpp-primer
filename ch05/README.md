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

## Section 5.3: Conditional Statements

## Section 5.4: Iterative Statements

## Section 5.5: Jump Statements

## Section 5.6: `try` Blocks and Exception Handling
