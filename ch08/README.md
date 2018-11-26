# Chapter 8: The C++ Library

## Section 8.1: The IO Classes

### Section 8.1.1: No Copy or Assign for IO Objects

### Section 8.1.2: Condition States

**Exercise 8.1:** Write a function that takes and returns an `istream&`. The function should read the stream until it hits end-of-file. The function shold print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

**Exercise 8.2:** Test your function by calling it, passing `cin` as an argument.

**Exercise 8.3:** What causes the following `while` to terminate?

### Section 8.1.3: Managing the Output Buffer

## Section 8.2: File Input and Output

### Section 8.2.1: Using File Stream Objects

**Exercise 8.4:** Write a function to open a file for input and read its contents into a `vector` of `string`s, storing each line as a separate element in the `vector`.

**Exercise 8.5:** Rewrite the previous program to stroe each word in a separate element.

**Exercise 8.6:** Rewrite the [bookstore program](../ch07/src/ex7_1.cpp) from [7.1.1](../ch07#section-71-defining-abstract-data-types) to read its transactions from a file. PAss the name of the file as an argument to `main`.

### Section 8.2.2: File Modes

**Exercise 8.7:** Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to `main`.

**Exercise 8.8:** Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure the data are preserved.

## Section 8.3: `string` Streams

### Section 8.3.1: Using an `istringstream`

**Exercise 8.9:** Use the function you wrote for the [first exercise](src/ex8_1.cpp) in [8.1.2](#section-812-condition-states) to print your contents of an `istringstream` object.

**Exercise 8.10:** Write a program to store each line from a file in a `vector<string>`. Now use an `istringstream` to read each element from the `vector` a word at a time.

**Exercise 8.11:** The program in this section defined its `istringstream` object inside the outer `while` loop. What changes would you need to make if `record` were defined outside that loop? Rewrite the program, moving the definition of `record` outside the `while`, and see whether you thought all of the changes that are needed.

**Exercise 8.12:** Why didn't we use in-class initializers in `PersonInfo`?

### Section 8.3.2: Using `ostringstream`s

**Exercise 8.13:** Rewrite the phone number program from this section to read from a named file rather than a `cin`.

**Exercise 8.14:** Why did we declare `entry` and `nums` as `const auto &`?
