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

## Section 4.3: Logical and Relational Operators

## Section 4.4: Assignment Operators

## Section 4.5: Increment and Decrement Operators

## Section 4.6: The Member Access Operators

## Section 4.7: The Conditional Operator

## Section 4.8: The Bitwise Operators

## Section 4.9: The `sizeof` Operators

## Section 4.10: Comma Operator

## Section 4.11: Type Conversions
