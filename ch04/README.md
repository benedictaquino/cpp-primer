# Chapter 4: Expressions

## Section 4.1 Fundamentals

### Section 4.1.1: Basic Concepts

### Section 4.1.2: Precedence and Associativity

**Exercise 4.1:**: What is the value returned by 5 + 10 * 20 / 2?

**Solution:** `105`

**Exercise 4.2:** Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:

* (a) `* vec.begin()`
* (b) `* vec.begin() + 1`

**Solution:**

* (a) `* (vec.begin())`
* (b) `(* (vec.begin())) + 1`

### Section 4.1.3: Order of Evaluation

**Exercise 4.3:** Order of evaluation for most of the binary operators is left undefined to give the compiler opportunities for optimization. This strategy presents a trade-off between efficient code generation and potential pitfalls in the use of the language by the programmer. Do you consider that an acceptable trade-off? Why or why not?

**Solution:** I believe that is an acceptable trade-off. It presents a challenge to the programmer to ensure their program is evaluating the operands as expected, but the efficient code generation is worth it.

## Section 4.2 Arithmetic Operators

**Exercise 4.4:** Parenthesize the folllowing expression to show how it is evaluated. Test your answer by compiling the expression (without parentheses) and printing its result.

```cpp
12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
```

[**Solution:**](src/ex4_4.cpp) 

```cpp
((12 / 3) * 4) + (5 * 15) + ((24 % 4) / 2)
```

This expression will evaluate to `91`.

**Exercise 4.5:** Determine the result of the following expressions.

* (a) `-30 * 3 + 21 / 5`
* (b) `-30 + 3 * 21 / 5`
* (c) `30 / 3 * 21 % 5`
* (d) `-30 / 3 * 21 % 4`

**Solution:**

* (a) `-86`
* (b) `-18`
* (c) `0`
* (d) `2`

**Exercise 4.6:** Write an expression to determine whether an `int` value is even or odd.

**Solution:**

```cpp
i % 2 == 0
```

If the above expression is `true`, then `i` is even, otherwise it is odd.

**Exercise 4.7:** What does overflow mean? Show three expressions that will overflow.

**Solution:** Overflow means that the value that is computed is outside of the range of values that the type can represent.

```cpp
int i = 2147483647 + 1;  // this will wrap around to be -214783648
unsigned ui =  4294967295 + 1;  // this will overflow and evaluate to 0
short si = 32767 + 1;  // this will wrap around to be -32768
```

## Section 4.3: Logical and Relational Operators

**Exercise 4.8:** Explain when operands are evaluated in the logical `AND`, logical `OR`, and equality operators.

**Solution:**

* The right side of an `&&` operator is evaluated if and only if the left side is `true`.
* The left side of an `||` operator is evaluated if and only if the left side is `false`.
* Like other operands, it is undefined when the operands are evaluated when using the `==` operator.

**Exercise 4.9:** Explain the behavior of the condition in the following `if`:

```cpp
const char *cp = "Hello World";
if (cp && *cp)
```

**Solution:** The left operand of the `&&` operator is evaluated first. If `cp` is any nonzero value, then the operand is evaluated as `true`, so the right operand is evaluated next. If `*cp` is any nonzero value, then it returns `true`. If `cp` was evaluated to be `false`, then the condition would be `false`.

**Exercise 4.10:** Write the condition for a `while` loop that would read `int`s from the standard input and stop when the value read is equal to `42`.

**Solution:**

```cpp
int i;
while (cin >> i && i != 42)
```

**Exercise 4.11:** Write an expression that tests four values, `a`, `b`, `c`, and `d`, and ensures that `a` is greater than `b`, which is greater than `c`, which is greater than `d`.

```cpp
if (a > b && b > c && c > d)
```

**Exercise 4.12:** Assuming `i`, `j`, and `k`, are all `int`s, explain what `i != j < k` means.

**Solution:** The first operator from left to right is the `!=` operator, so the truth of `i` being inequal to `j < k` will be evaluated. `j < k` returns a `bool`, so the expression will evaluate to `true` if `i` holds the value `1` and `j < k` is `true` or `i` holds the value `0` and `j < k` is `false`. Otherwise, it will return `false`.

## Section 4.4: Assignment Operators

**Exercise 4.13:** What are the values of `i` and `d` after each assignment?

```cpp
int i; double d;
```

* (a) `d = i = 3.5;`
* (b) `i = d = 3.5;`

**Solution:** 

* (a) `i` has the value `3` and `d` has the value `3`
* (b) `i` has the value `3` and `d` has the value `3.5`

**Exercise 4.14:** Explain what happens in each of the `if` tests:

```cpp
if (42 = i)  // ...
if (i = 42)  // ...
```

**Solution:** 

```cpp
if (42 = i)  // error: literals are rvalues
if (i = 42)  // true
```

In the first condition, `42` is an `int` literal so it cannot be assigned the value of `i`. In the second condition, `i` is assigned the value `42`, and since it is a nonzero value the condition evaluates as `true`.

**Exercise 4.15:** The following assignment is illegal. Why? How would you correct it?

```cpp
double dval; int ival; int *pi;
dval = ival = pi = 0;
```

**Solution:** `pi` is an `int` pointer, so the value `0` cannot be assigned to it. 

**Exercise 4.16:** Although the following are legal, they probably do not behave as the programmer expects. Why? Rewrite the expressions as you think they should be.

* (a) `if (p = getPtr() != 0)`
* (b) `if (i = 1024)`

**Solution:**

* (a) `if (p = getPtr())`. The programmer likely expects this condition to evaluate whether the value returned by getPtr() is not zero. It will not work that way, because assignment has lower precedence, so the `!=` expression would be evaluated first, then assign the `bool` value to `p`.  `if (p = getPtr())` will evaluate whether or not `p` is nonzero.
* (b) `if (i == 1024)`. The programmer likely intended this condition to check if `i` is equal to `1024`. As it is written above, it will assign the value `1024` to `i` then return evaluate as `true`, because `i` is nonzero.

## Section 4.5: Increment and Decrement Operators

**Exercise 4.17:** Explain the difference between prefix and postfix increment.

**Solution:** The prefix increment increments the object and yields the value of the incremented object. The postfix increment increments the object but yields the value of the unincremented object.

**Exercise 4.18:** What would happen if the `while` loop on page 148 that prints the elements from a vector used the prefix increment operator?

```cpp
auto pbeg = v.begin();
// print elements up to the first negative value
while (pbeg != v.end() && *beg >= 0)
    cout << *pbeg++ << endl; // print the current value and advance pbeg
```

**Solution:** If it used the prefix increment operator, then the `while` loop would not print the first element of the vector, but begin with the element in position `1` of the vector. Then it would continue to print the elements up until either the first negative value or the last value.

**Exercise 4.19:** Given that `ptr` points to an `int`, that `vec` is a `vector<int>`, and that `ival` is an `int`, explain the behavior of each of these expressions. Which, if any, are likely to be incorrect? Why? How might each be corrected?

* (a) `ptr != 0 && *ptr++`
* (b) `ival++ && ival`
* (c) `vec[ival++] <= vec[ival]`

**Solution:**

* (a) This expression evaluates if `ptr` is nonzero, then if it is true, it yields the address of the object that `ptr` points to, then increments the pointer.
* (b) This expression yields `ival` then increments it, and if `ival` holds a nonzero value, then the incremented `ival` is yielded.
* (c) This expression is likely incorrect. It is comparing `vec[ival++]` and `vec[ival]`, however, since it is undefined which operand will be evaluated before the comparison, it may not function as intended. I would correct it as `vec[ival] <= vec[ival + 1]`.

## Section 4.6: The Member Access Operators

**Exercise 4.20:** Assuming that `iter` is a `vector<string>::iterator`, indicate which, if any, of the following expressions are legal. Explain the behavior of the legal expressions and why those that aren't legal are in error.

* (a) `*iter++;`
* (b) `(*iter)++;`
* (c) `*iter.empty();`
* (d) `iter->empty();`
* (e) `++*iter;`
* (f) `iter++->empty();`

**Solution:** 

* (a) `iter++;` is legal. It increments the iterator by one to point at the next element of the vector.
* (b) `(*iter)++;` is illegal. It dereferences `iter` and attempts to increment the `string` object.
* (c) `*iter.empty();` is illegal. The member operator has lower precedence than the dereferencing operator, so this expression attempts to get the member named `empty()` which `iter` does not have.
* (d) `iter->empty();` is legal. It dereferences `iter` and uses the `empty()` member function of the `string` that `iter` points to. 
* (e) `++*iter;` is illegal. This expression dereferences `iter` then attempts to increment it.
* (e) `iter++->empty();` is legal. This expression increments `iter` then accesses the `empty()` member function of the `string` that `iter` points to.

## Section 4.7: The Conditional Operator

**Exercise 4.21:** Write a program to use a conditional operator to find the elements in a `vector<int>` that have odd value and double the value of each such element.

[**Solution:**](src/ex4_21.cpp)

```cpp
/* This program uses a conditional operator to find the elements in a
 * vector<int> that have odd value and doubles the value of each such element */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> iv; // initialize empty vector of integers
    int i; // define integer object
    while (cin >> i) iv.push_back(i); // read integers from standard input to iv

    cout << "Elements of the original vector:\n";
    for (auto j : iv) cout << j << " "; cout << endl;

    // Double the odd elements of the vector
    for (auto &r : iv) (r % 2 == 1) ? r *= 2 : r;

    cout << "Elements of the changed vector:\n";
    for (auto j : iv) cout << j << " "; cout << endl;

    return 0;
}
```

**Exercise 4.22:** Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. Write two versions: One version that uses only conditional operators; the other should use one or more `if` statement. Which version do you think is easier to understand and why?

[**Solution 1:**](src/ex4_22_1.cpp)

```cpp
/* This program assigns high pass, pass, low pass, and fail to grades */
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> scores; int score;
    while (cin >> score) scores.push_back(score);

    vector<string> finalgrades; string finalgrade;
    for (int grade : scores) {
        finalgrade = (grade > 90) ? "high pass"
                   : (grade > 75) ? "pass"
                   : (grade >= 60) ? "low pass"
                   : "fail";
        finalgrades.push_back(finalgrade);
    }

    cout << "Scores\tFinal Grades\n" 
         << "------\t------------" << endl;
    for (int i = 0; i != scores.size(); ++i)
        cout << scores[i] << "\t" << finalgrades[i] << endl;

    return 0;
}
```

[**Solution 2:**](src/ex4_22_2.cpp)

```cpp
/* This program assigns high pass, pass, low pass, and fail to grades */
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> scores; int score;
    while (cin >> score) scores.push_back(score);

    vector<string> finalgrades; string finalgrade;
    for (int grade : scores) {
        if (grade > 90) finalgrade = "high pass";
        else if (grade > 75) finalgrade = "pass";
        else if (grade >= 60) finalgrade = "low pass";
        else finalgrade = "fail";
        finalgrades.push_back(finalgrade);
    }

    cout << "Scores\tFinal Grades\n" 
         << "------\t------------" << endl;
    for (int i = 0; i != scores.size(); ++i)
        cout << scores[i] << "\t" << finalgrades[i] << endl;

    return 0;
}
```

I think using conditional operators makes the code cleaner and more concise, but the one using `if` statements are easier to understand. It's clearer what the code is doing in the second program, however it is more verbose.

**Exercise 4.23:** The following expression fails to compile due to operator precedence. Using [Table 4.12](#section-412-operator-precedence-table), explain why it fails. How would you fix it?

```cpp
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

**Solution:** The expression fails to compile because the conditional operator has lower precedence than the addition operator. So `s + s[s.size() - 1]` is evaluated first, then the equality operator checks if `s + s[s.size() - 1]` is equal to `s`, which is illegal because they are different types. I would fix it as such:

```cpp
string s = "word";
string pl = s + (s[s.size() - 1] == 's' ? "" : "s");
```

**Exercise 4.24:** Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how the that operator would be evaluated if the operator were left associative.

**Solution:** If the operator were left associative, then at the first conditional operator, if `grade > 90` is `true`, then the result is `"high pass"` which would then be passed on to the `(grade < 60)` condition. This would return `true`, so `finalgrade` would always be `"fail"`. 

## Section 4.8: The Bitwise Operators

**Exercise 4.25:** What is the value of `~'q' << 6` on a machine with 32-bit `int`s and 8-bit `char`s, that uses Latin-1 character set in which `'q'` has the bit pattern `01110001`?

**Solution:** The `~` operator promotes `'q'` to the larger integral type `int`, so `'q' = 01110001` is promoted to `00000000 00000000 00000000 01110001`. Then this is inverted by the `~` operator, resulting in `11111111 11111111 11111111 100011101`. This is then shifted left by 6 bits, resulting in `11111111 11111111 11100011 10000000` which, when conveted to decimal, is `-7296`. 

**Exercise 4.26:** In our grading example in this section, what you happen if you used `unsigned int` as the type for `quiz1`?

**Solution:** Since we want `quiz1` to track each student's quiz results, we need at least 30 bits. If we used `unsigned int` and the implementation only stored 16 bits for that type, then this would cause undefined behavior.

**Exercise 4.27:** What is the result of each of these expressions?

```cpp
unsigned long ul1 = 3, ul2 = 7;
```

* (a) `ul1 & ul2`
* (b) `ul1 | ul2`
* (c) `ul1 && ul2`
* (d) `ul1 || ul2`

**Solution:**

* (a) `ul1 & ul2` evaluates to `3`. The binary representation of `3` is `00000000 00000000 00000000 00000011` and `7` is `00000000 00000000 00000000 00000111`. The `&` operator returns the bits that are `1` for both `ul1` and `ul2`, so it returns `00000000 00000000 00000000 00000011`, which `3` in decimal.
* (b) `ul1 | ul2` evaluates to `7`. The `|` operator returns the bits that are `1` in either `ul1` or `ul2`, so it returns `00000000 00000000 00000000 00000111`, which is `7` in decimal.
* (c) `ul1 && ul2` evaluates to `1`. The `&&` operator first evaluates `ul1` to see if it holds a nonzero value, then since `3` is nonzero, it evaluates `ul2` for a nonzero value. Since both are nonzero, it returns `1`.
* (d) `ul1 || ul2` evaluates to `1`. The `||` operator first evaluates `ul1` to see if it holds a nonzero value, then since `3` is nonzero, it returns `1`.

## Section 4.9: The `sizeof` Operators

**Exercise 4.28:** Write a program to print the size of each of the built-in types.

[**Solution:**](src/ex4_28.cpp)

```cpp
/* This program prints the size of each of the built-in types */
#include <iostream>

using std::cout; using std::endl;

int main()
{
    cout << "Built-in Type\tSize\n" 
         << "-------------\t----\n" << "\n"
         << "bool\t\t" << sizeof(bool) << "\n"
         << "char\t\t" << sizeof(char) << "\n"
         << "wchar_t\t\t" << sizeof(wchar_t) << "\n"
         << "char16_t\t" << sizeof(char16_t) << "\n"
         << "char32_t\t" << sizeof(char32_t) << "\n"
         << "short\t\t" << sizeof(short) << "\n"
         << "int\t\t" << sizeof(int) << "\n"
         << "long\t\t" << sizeof(long) << "\n"
         << "long long\t" << sizeof(long long) << "\n"
         << "float\t\t" << sizeof(float) << "\n"
         << "double\t\t" << sizeof(double) << "\n"
         << "long double\t" << sizeof(long double) << endl;
    return 0;
}
```

**Exercise 4.29:** Predict the output of the following code and explain your reasoning. Now run the program. Is the output what you expected? If not, figure out why.

[**Solution:**](src/ex4_29.cpp) I predict that the program will print the following output:

```
10
2
```

It should do the above because in the first output stream, the expression `sizeof(x)/sizeof(*x)` essentially counts how many elements are in an array. It is dividing the array size by the element size. Since there are 10 elements in `x`, it should return `10`. The second expression `sizeof(p)/sizeof(*p)` should evaluate to `8`. `sizeof` of a pointer returns the size needed to hold a pointer, and `sizeof` a dereferenced pointer returns the size of an object of the type to which the pointer points. So `sizeof(p)` should evaluate to `8` and `sizeof(*p)` should evaluate to `4`.

My [program](src/ex4_29.cpp) validates the above prediction.

```cpp
/* This program runs the code from Exercise 4.29 to validate my predictions */
#include <iostream>

using std::cout; using std::endl;

int main()
{
    int x[10]; int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    return 0;
}
```

**Exercise 4.30:** Using [Table 4.12](#section-412-operator-precedence-table), parenthesize the following expressions to match the default evaluation:

* (a) `sizeof x + y`
* (b) `sizeof p->mem[i]`
* (c) `sizeof a < b`
* (d) `sizeof f()`

**Solution:**

* (a) `(sizeof x) + y`
* (b) `sizeof ((p->mem)[i])`
* (c) `(sizeof a) < b`
* (d) `sizeof (f())`

## Section 4.10: Comma Operator

**Exercise 4.31:** The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix versions? Rewrite the program using postfix operators.

[**Solution:**](src/ex4_31.cpp) We use the prefix operator and not the postfix because the results are the same either way, and the prefix operator is preferred since we do not have to hold a copy as if we used the postfix operator. 

In the original program, the `for` loop begins with `ix` at `0`, and `cnt` at `ivec.size()`. The first iteration of the `for` loop assigns the value of `ivec.size()` to `ivec[0]`, then increments `ix` to `1` and `cnt` to `ivec.size - 1`. This continues until `ix` holds the same value as `ivec.size()`. So the values of the elements in `ivec` should begin at `ivec.size()` and end at `1`.

In the program with the postfix operators, the `for` loop behaves the same way, except when `ix` and `cnt` are incremented, they yield the unincremented value. However, those values are never used by the program, so it is an unnecessary copy.

```cpp
#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<int> ivec(10);
    // Original program
    vector<int>::size_type cnt = ivec.size();
    // assign values from size...1 to the elements in ivec
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ++ix, --cnt)
        ivec[ix] = cnt;
    // print elements
    cout << "Elements of the vector in the original program\n";
    for (int &i : ivec) cout << i << " "; cout << endl;

    // Modified program with postfix increment operators
    cnt = ivec.size();
    // assign values from size...1 to the elements in ivec
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
        ivec[ix] = cnt;
    // print elements
    cout << "Elements of the vector in the modified program\n";
    for (int &i : ivec) cout << i << " "; cout << endl;
 
    return 0;
}
```

**Exercise 4.32:** Explain the following loop.

```cpp
constexpr int_size 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0; ix != size && ptr != ia+size; ++ix, ++ptr) { /* ... */ }
```

**Solution:** The `for` loop begins with the pointer `*ptr` holding the address of the first element of `ia`, and `ix` holding the value `0`. At the end of each loop, `ix` and `ptr` are incremented by one. The loop ends when `ix` holds the value `5` and `ptr` holds the address of an object outside of `ia`.

**Exercise 4.33:** Using [Table 4.12](#section-412-operator-precedence-table) explain what the following expression does:

```cpp
someValue ? ++x, ++y : --x, --y
```

**Solution:** According to operator precedence, the above expression will be evaluated in the order below:

```cpp
(someValue ? (++x, ++y) : --x), --y)
```
The conditional operator takes precedence above the comma operator, so if `someValue` is nonzero, then the expression returns `++x, ++y, --y`, so the first comma operator returns `++y`, then the second comma operator returns `--y`. So `y` is incremented, then decremented, yielding the original value of `y`. 

If `someValue` is `0`, then the expression returns `--x, --y`, so `y` is decremented and yielded.

## Section 4.11: Type Conversions

## Section 4.12: Operator Precedence Table

| **Associativity and Operator** | Function | Use |
|:-------------------------------|----------|-----|
| L `::`              | global scope           | `::`name                 |
| L `::`              | class cope             | class`::`name            | 
| L `::`              | namespace scope        | namespace`::`name        |
| -                   | -                      | -                        |
| L `.`               | member selectors       | object`.`member          |  
| L `->`              | member selector        | pointer`->`member        |
| L `[]`              | subscript              | expr`[`expr`]`           |
| L `()`              | function call          | name`(`expr_list`)`      |
| L `()`              | type construction      | type`(`expr_lstr`)`      |
| -                   | -                      | -                        |
| R `++`              | postfix increment      | lvalue`++`               |
| R `--`              | postfix increment      | lvalue`--`               |
| R `typeID`          | type ID                | `typeid`(type)           |
| R `typeID`          | run-time type ID       | `typeid`(expr)           |
| R explicit cast     | type conversion        | *cast_name*<type\>(expr) |
| -                   | -                      | -                        |
| R `++`              | prefix increment       | `++`lvalue               |
| R `--`              | prefix increment       | `--`lvalue               |
| R `~`               | bitwise `NOT`          | `~`expr                  |
| R `!`               | logical `NOT`          | `!`expr                  |
| R `-`               | unary minus            | `-`expr                  |
| R `+`               | unary plus             | `+`expr                  |
| R `*`               | dereference            | `*`expr                  |
| R `&`               | address-of             | `&`lvalue                |
| R `()`              | type conversion        | `(`type`)`expr           |
| R `sizeof`          | size of object         | `sizeof`expr             |
| R `sizeof`          | size of type           | `sizeof`( type )         |
| R `sizeof...`       | size of parameter pack | `sizeof...`( name )      |
| R `new`             | allocate object        | `new` type               |
| R `new[]`           | allocate array         | `new` type`[`size`]`     |
| R `delete`          | deallocate object      | `delete` expr            |
| R `delete[]`        | deallocate array       | `delete[]` expr          |
| R `noexcept`        | can expr throw         | `noexcept` ( expr )      |
| -                   | -                      | -                        |
| L `->*`             | ptr to member select   | ptr`->*`ptr_to_member    |
| L `.*`              | ptr to member select   | obj`.*`ptr_to_member     |
| -                   | -                      | -                        |
| L `*`               | multiply               | expr `*` expr            |
| L `/`               | divide                 | expr `/` expr            |
| L `%`               | modulo                 | expr `%` expr            |
| -                   | -                      | -                        |
| L `+`               | add                    | expr `+` expr            |
| L `-`               | subtract               | expr `-` expr            |
| -                   | -                      | -                        |
| L `<<`              | bitwise shift left     | expr `<<` expr           |
| L `>>`              | bitwise shift right    | expr `>>` expr           |
| -                   | -                      | -                        |
| L `<`               | less than              | expr `<` expr            |
| L `<=`              | less than or equal     | expr `<=` expr           |
| L `>`               | greater than           | expr `>` expr            |
| L `>=`              | greater than or equal  | expr `>=` expr           |
| -                   | -                      | -                        |
| L `==`              | equality               | expr `==` expr           |
| L `!=`              | inequality             | expr `!=` expr           |
| -                   | -                      | -                        |
| L `&`               | bitwise `AND`          | expr `&` expr            |
| -                   | -                      | -                        |
| L `^`               | bitwise `XOR`          | expr `^` expr            |
| -                   | -                      | -                        |
| L `|`               | bitwise `OR`           | expr `|` expr            |
| -                   | -                      | -                        |
| L `&&`              | logical `AND`          | expr `&&` expr           |
| -                   | -                      | -                        |
| L `||`              | logical `OR`           | expr `||` expr           |
| -                   | -                      | -                        |
| R `?:`              | conditional            | expr`?`expr`:`expr       |
| -                   | -                      | -                        |
| R `=`               | assignment             | lvalue `=` expr          |
| R `*=`, `/=`, `%=`  | compound assign        | lvalue `+=` expr, etc.   |
| R `+=`, `-=`,       |
| R `<<=`, `>>=`      |
| R `&=`, `\|=`, `^=` |
| -                   | -                      | -                        |
| R `throw`           | throw exception        | `throw` expr             |
| -                   | -                      | -                        |
| L `,`               | comma                  | expr `,` expr            |
