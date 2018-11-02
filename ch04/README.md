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

If the above expression is true, then `i` is even, otherwise it is odd.

**Exercise 4.7:** What does overflow mean? Show three expressions that will overflow.

**Solution:** Overflow means that the value that is computed is outside of the range of values that the type can represent.

```cpp
int i = 2147483647 + 1;  // this will wrap around to be -214783648
unsigned ui =  4294967295 + 1;  // this will overflow and evaluate to 0
short si = 32767 + 1;  // this will wrap around to be -32768
```

## Section 4.3: Logical and Relational Operators

## Section 4.4: Assignment Operators

## Section 4.5: Increment and Decrement Operators

## Section 4.6: The Member Access Operators

## Section 4.7: The Conditional Operator

## Section 4.8: The Bitwise Operators

## Section 4.9: The `sizeof` Operators

## Section 4.10: Comma Operator

## Section 4.11: Type Conversions
