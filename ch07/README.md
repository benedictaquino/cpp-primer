# Chapter 7: Classes

## Section 7.1: Defining Abstract Data Types

### Section 7.1.1: Designing the `Sales_data` Class

**Exercise 7.1:** Write a version of the transaction-processing [program](../ch01/src/ex1_25.cpp) from [1.6](../ch01#section-16-the-bookstore-program) using the [`Sales_data`](../ch02/src/Sales_data.h) class you defined for the exercises in [2.6.1](../ch02#section-261-defining-the-sales_data-type).

### Section 7.1.2: Defining the Revised `Sales_data` Class

**Exercise 7.2:** Add the `combine` and `isbn` members to the `Sales_data` class you wrote for the exercises in [2.6.2](../ch02#section-262-using-the-sales_data-class).

**Exercise 7.3:** Revise your transaction-processing program from [7.1.1](#section-711-designing-the-sales_data-class)

**Exercise 7.4:** Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subsequent exercises will incrementally add features to this class.

**Exercise 7.5:** Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

### Section 7.1.3: Defining the Nonmember Class-Related Functions

**Exercise 7.6:** Define your own versions of the `add`, `read`, and `print` functions.

**Exercise 7.7:** Rewrite the transaction-processing program you wrote for the exercises in [7.1.2](#section-712-defining-the-revised-sales_data-class)

**Exercise 7.8:** Why does `read` define its `Sales_data` parmeter as a plain reference and `print` define its parameter as a reference to `const`?

**Exercise 7.9:** Add operations to read and print `Person` objects to the code you wrote for the exercises in [7.1.2](#section-712-defining-the-revised-sales_data-class)

**Exercise 7.10:** What does the condition in the following `if` statement do?

```cpp
if (read(read(cin, data1), data2))
```

### Section 7.1.4: Constructors

**Exercise 7.11:** Add constructors to your `Sales_data` class and write a program to use each of the constructurs.

**Exercise 7.12:** Move the definition of the `Sales_data` constructor that takes an `istream` into the body of the `Sales_data` class.

**Exercise 7.13:** Rewrite the program from page 255 to use the `istream` constructor.

**Exercise 7.14:** Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

**Exercise 7.15:** Add appropriate constructors to your `Person` class.

## Section 7.2: Access Control and Encapsulation

**Exercise 7.16:** What, if any, are the constraints on where and how often an access specifier may appear inside a class definition? What kinds of members should be defined after a `public` specifier? What kinds should be `private`?

**Exercise 7.17:** What, if any, are the differences between using `class` or `struct`?

**Exercise 7.18:** What is encapsulation? Why is it useful?

**Exercise 7.19:** Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

### Section 7.2.1: Friends

**Exercise 7.20:** When are friends useful? Discuss the pros and cons of using friends.

**Exercise 7.21:** Update your `Sales_data` class to hide its implementation. The programs you've written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

**Exercise 7.22:** Update your `Person` class to hide its implementation.

## Section 7.3: Additional Class Features

### Section 7.3.1: Class Members Revisited

**Exercise 7.23:** Write your own version of the `Screen` class

**Exercise 7.24:** Give your `Screen` class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

**Exercise 7.25:** Can `Screen` safely rely on the default vesions of copy and assignment? If so, why? If not, why not?

**Exercise 7.26:** Define `Sales_data::avg_price` as an `inline` function.

### Section 7.3.2: Functions That Return `*this`

**Exercise 7.27:** Add the `move`, `set`, and `display` operations to your version of `Screen`. Test your class by executing the following code:

```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

**Exercise 7.28:** What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`?

**Exercise 7.29:** Revise your `Screen` class so that `move`, `set`, and `display` functions return `Screen` and check your prediction from the previous exercise.

**Exercise 7.30:** It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

### Section 7.3.3 Class Types

**Exercise 7.33:** Define a pair of classes `X` and `Y`, in which `X` has a pointer to `Y`, and `Y` has an object of type `X`.

### Section 7.3.4: Friendship Revisited

**Exercise 7.32:** Define your own version of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`.

## Section 7.4: Class Scope

## Section 7.5: Constructors Revisited

## Section 7.6: `static` Class Members
