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

## Section 4.6: The Member Access Operators

## Section 4.7: The Conditional Operator

## Section 4.8: The Bitwise Operators

## Section 4.9: The `sizeof` Operators

## Section 4.10: Comma Operator

## Section 4.11: Type Conversions
