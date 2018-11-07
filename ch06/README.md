# Chapter 6: Functions

## Section 6.1: Function Basics

**Exercise 6.1:** What is the difference between a parameter and an argument?

**Solution:** A parameter is part of the function definition. An argument is passed into the function through the call operator to initialize the function's parameters.

**Exercise 6.2:** Indicate which of the following functions are in error and why. Suggest how you might correct the problems.

* (a)

```cpp
int f() {
    string s;
    // ...
    return s;
}
```

* (b)

```cpp
f2(int i) { /* ... */ }
```

* (c) 

```cpp
int calc(int v1, int v1) /* ... */}
```

* (d)

```cpp
double square(double x) return x * x;
```

**Solution:**

* (a) The return type of `f` is `int`, but `s` is a `string`.

```cpp
string f() {
    string s;
    // ...
    return s;
}
```

* (b) No return type is specified for `f2`. If the function does not return a value, then the `void` type must be specified.

```cpp
void f2(int i) { /* ... */ }
```

* (c) The function body is missing the first bracket enclosing the statement block. Also, no two parameters can have the same name, but `calc` uses `v1` twice.

```cpp
int calc(int v1, int v2} { /* ... */ }
```

* (d) The body of the function must be a statement block.

```cpp
double square(double x) {return x * x;}
```

**Exercise 6.3:** Write and test your own version of `fact`.

[**Solution:**](src/ex6_3.cpp)

```cpp
int fact(int val)
{
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1) ret *= val--; // assign ret * val to ret and decrement val
    return ret; // return the result
}
```

**Exercise 6.4:** Write a function that interacts with the user, asking for a number and generating the factorial of that number. Call this function from `main`.

[**Soluton:**](src/ex6_4.cpp)

```cpp
void fun_fact()
{
    // prompt user for an integer and read it from standard input into i
    cout << "Enter an integer:" << endl;
    int val;
    cin >> val;
    cout << val << "! is " << flush;
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1) ret *= val--; // assign ret * val to ret and decrement val
    cout << ret << endl;
}
```

**Exercise 6.5:** Write a function to return the absolute value of its argument.

[**Solution:**](src/ex6_5.cpp)

```cpp
double abs(double d)
{
    if (d < 0) d -= 2 * d;
    return d;
}
```

### Section 6.1.1: Local Objects

**Exercise 6.6:** Explain the differences between a parameter, a local variable, and a local `static` variable. Give an example of a function in which each might be useful.

**Solution:** Parameters are local variables declared in the function's parameter list. A local variable is a variable defined inside of the function body. They hide declarations of the same name made in an outer scope. A local `static` variable is initialized the first time execution passes through an object's definition. They are not destroyed when a function ends, they remain until the program terminates.

**Exercise 6.7:** Write a function that returns `0` when it is first called and then generates numbers in sequence each time it is called again.

[**Solution:**](src/ex6_7.cpp)

```cpp
int sequence()
{
    static int i = 0;
    return i++;
}
```

### Section 6.1.2: Function Declarations

**Exercise 6.8:** Write a header file named `Chapter6.h` that contains declarations for the functions you wrote for the exercises in [6.1](#section-61-function-basics)

[**Solution:**](include/Chapter6.h)

```cpp
#ifndef CHAPTER6_H
#define CHAPTER6_H

int fact(int val);
void fun_fact();
double abs(double d);
int sequence();

#endif
```

### Section 6.1.3: Separate Compilation

**Exercise 6.9:** Write your own versions of `fact.cc` and `factMain.cc` files. These files should include your `Chapter6.h` from exercises in the previous section. Use these files to understand how your compiler supports separate compilation.

**Solution:**

[**`fact.cpp`:**](src/fact.cpp)

```cpp
#include "../include/Chapter6.h"

int fact(int val)
{
    int ret = 1; // local variable to hold the result as we calculate it
    while (val > 1) ret *= val--; // assign ret * val to ret and decrement val
    return ret;
}
```

[**`factMain.cpp`:**](src/factMain.cpp)

```cpp
#include <iostream>
#include "../include/Chapter6.h"

using std::cin; using std::cout; using std::endl;

int main()
{
    // prompt user for an integer and read it from standard input into i
    cout << "Enter an integer:" << endl;
    int i;
    cin >> i;
    int j = fact(i);
    cout << i << "! is " << j << endl;
    return 0;
}
```

## Section 6.2: Argument Passing

### Section 6.2.1: Passing Arguments by Value

**Exercise 6.10:** Using pointers, write a function to swap the values of two `int`s. Test the function by calling it and printing the swapped values.

[**Solution:**](src/ex6_10.cpp)

```cpp
void swap(int *ip1, int *ip2)
{
    int temp = *ip1;
    *ip1 = *ip2;
    *ip2 = temp;
    return;
}
```

### Section 6.2.2: Passing Arguments by Reference

**Exercise 6.11:** Write and test your own version of `reset` that takes a reference.

[**Solution:**](src/ex6_11.cpp)

```cpp
// function that takes a reference to an int and sets the given object to zero
void reset(int &i)  // i is just another name for the object passed to reset
{
    i = 0;
}
```

**Exercise 6.12:** Rewrite the program from [exercise 6.10](#section-621-passing-arguments-by-value) to use references instead of pointers to swap the value of two `int`s. Which version do you think would be easier to use and why?

[**Solution:**](src/ex6_12.cpp)

```cpp
void swap(int &r1, int &r2)
{
    int temp = r1;
    r1 = r2; r2 = temp;
}
```

References seem easier to use. Using references, we don't need to dereference the pointers or use the `&` operator to get the address-of the objects.

**Exercise 6.13:** Assuming `T` is the name of a type, explain the difference between a function declared as `void f(T)` and `void f(T&)`.

**Solution:** The function declared as `void f(T)` takes the object of type `T` as an argument passed by value. The function declared `void f(T&)` is called by reference. So the object outside of the function `f` can be modified.

**Exercise 6.14:** Give an example of when a parameter should be a reference type. Give an example of when a parameter should not be a reference.

**Solution:** Parameters should be reference types when we want to return additional information or we want to avoid copies. For example, if we have a function that takes two large objects as arguments (and are not changed inside the function) then we would use references to `const`. 

If we are writing functions that manipulate small objects then we can just pass our arguments as values.

**Exercise 6.15:** Explain the rational for the type of each `find_char`'s parameters. In particular, why is `s` a reference to `const` but `occurs` is a plain reference? Why are these parameters references, but the `char` parameter `c` is not? What would happen if we made a plain reference? What if we made `occurs` a reference to `const`?

**Solution:** 

* `s` is a `string` reference because `string`s are typically large objects and we want to avoid making an unnecessary copy. It is specifically a reference to `const` because we are not changing `s` inside the function.

* `c` is a `char` passed as a value because `char`s are small sized objects and we are not changing it inside the function.

* `occurs` is a `string:size_type` reference because we want to return additional information outside of the `return` statement. We return `ret` which holds the position of the first occurence of `c` in `s`, and the count of occurrences is implicitly returned in `occurs`.

### Section 6.2.3: `const` Parameters and Arguments

**Exercise 6.16:** The following function, although legal, is less useful than it might be. Identify and correct the limitation on this function.

```cpp
bool is_empty(string& s) { return s.empty(); }
```

**Solution:** This function cannot be used on `const string`s. As well, since it is not changing the value of `s`, we should be using a `const string` parameter as best practices.

```cpp
bool is_empty(const string &s) { return s.empty(); }
```

**Exercise 6.17:** Write a function to determine whether a `string` contains any capital letters. Write a function to change a `string` to all lowercase. Do the parameters you used in these functions have the same type? If so, why? If not, why not?

[**Solution:**](src/ex6_17.cpp)

```cpp
bool has_capital(const string &s)
{
    bool capital = 0;
    for (auto c : s) 
        if (isupper(c)) {
            capital = 1;
            break;
        }
    return capital;
}

void to_lower(string &s)
{
    for (auto &c : s) if (isupper(c)) c = tolower(c);
}
```

My function `has_capital` uses a reference to `const string` because I do not want to copy the `string` object and I am not changing the `string` in the function body. My function `to_lower` uses a `string` reference because I do not want to copy the string but I do want to change it in the function body.

**Exercise 6.18:** Write declarations for each of the following functions. When you write these declarations, use the name of the function to indicate what the function does.

* (a) A function named `compare` that returns a `bool` and has two parameters tha are references to a class named `matrix`. 

* (b) A function named `change_val` that returns a `vector<int>` iterator and takes two parameters: One is an `int` and the other is an iterator for a `vector<int>`.

**Solution:**

* (a)

```cpp
bool compare(matrix&, matrix&);
```

* (b)

```cpp
vector<int>::iterator change_val(int, vector<int>::iterator);
```

**Exercise 6.19:** Given the following declarations, determine which calls are legal and which are illegal. For those that are illegal, explain why.

```cpp
double calc(double);
int count(const string &, char);
int sum(vector<int>::iterator, vector<int>::iterator, int);
vector<int> vec(10);
```

* (a)

```cpp
calc(23.4, 55.1);
```

* (b)

```cpp
count("abcda", 'a');
```

* (c)

```cpp
calc(66);
```

* (d)

```cpp
sum(vec.begin(), vec.end(), 3.8);
```

**Solution:**

* (a) Illegal. `calc` only has one `double` parameter and this function call passes in two `double` arguments.

* (b) Legal. `count` has a reference to `const string` parameter and a `char` parameter, and this function call passes in a `string` literal and a `char` literal as the arguments.

* (c) Legal. `calc` takes a single `double` parameter and this function call passes an integer literal `66` as an argument which will be converted to a `double` in the function body.

* (d) Legal. `sum` takes three parameters: two `vector<int>` iterators and an `int`. The first two arguments passed in the function call match the correct type, and the floating-point literal passed as the third argument will be truncated and converted to an `int`.

**Exercise 6.20:** When should reference parameters be references to `const`? What happens if we make a parameter a plain reference when it could be a reference to `const`?

**Solution:** Reference parameters should be references to `const` whenever we are not changing the referenced object inside the function body. If we make a parameter a plain reference when it could be a reference to `const`, then it will be unable to take in `const` objects as arguments.

### Section 6.2.4: Array Parameters

**Exercise 6.21:** Write a function that takes an `int` and a pointer to an `int` and returns the larger of the `int` value or the value to which the pointer points. What type should you use for the pointer?

[**Solution:**](src/ex6_21.cpp)

```cpp
int larger(int ival, const int *ip)
{
   return (ival > *ip) ? ival : *ip;
}
```

**Exercise 6.22:** Write a function to swap two `int` pointers.

[**Solution:**](src/ex6_22.cpp)

```cpp
void swap(int* &ip1, int* &ip2)
{
    int *temp = ip1;
    ip1 = ip2;
    ip2 = temp;
}
```

**Exercise 6.23:** Write your own versions of each of the `print` functions presented in this section. Call each of these functions to print `i` and `j` defined as follows:

```cpp
int i = 0, j[2] = {0, 1};
```

[**Solution:**](src/ex6_23.cpp)

```cpp
#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::end;

void print(const int *ip)
{
    if (ip) cout << *ip++ << " ";
}

void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << " "; // print the current element
    cout << endl;               // and advance the pointer
}

void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) cout << ia[i] << " ";
    cout << endl;
}

void print(int (&arr)[2])
{
    for (auto elem : arr)
        cout << elem <<  " ";
    cout << endl;
}

int main()
{
    int i = 0, j[2] = {0, 1};
    // print(const int*)
    cout << "print(const int *ip)\ni: ";
    print(&i); 
    cout << endl;
    cout << "j: ";
    for (auto val : j) print(&val);
    cout << endl;
    // print(const int *beg, const int *end)
    cout << "print(const int *beg, const int *end)\ni: ";
    print(&i, &i + 1);
    cout << "j: ";
    print(j, end(j));
    // print(const int ia[], size_t size)
    cout << "print(const int ia[], size_t size)\ni: ";
    print(&i, 1);
    cout << "j: ";
    print(j, 2);
    // print(const int (&arr)[n])
    cout << "print(const int (&arr)[n])\ni: ";
    int ia[2];
    ia[0] = i;
    print(ia);
    cout << "j: ";
    print(j);
    return 0;
}
```

**Exercise 6.24:** Explain the behavior of the following function. If there are problems in the code, explain what they are and how you might fix them.

```cpp
void print(const int ia[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

**Solution:** The `print` function has a single `const int*` parameter. The function then does 10 iterations, indexing from the initial `const int*` address passed in. One issue is that the `[10]` subscript in the function definition does not actually limit the function to only take in `int` arrays of size 10. To fix it, we need to use a reference to an array of size 10.

```cpp
void print(const int (&ia)[10])
{
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << endl;
}
```

### Section 6.2.5: `main`: Handling Command-Line Options

**Exercise 6.25:** Write a main function that takes two arguments. Concatenate the supplied arguments and print the resulting `string`.

[**Solution:**](src/ex6_25.cpp)

```cpp
int main(int argc, char *argv[])
{
    if (!argv[1] || !argv[2]) {
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    string str1 = argv[1], str2 = argv[2], str = str1 + ' ' + str2;
    cout << str << endl;
    return 0;
}
```

**Exercise 6.26:** Write a program that accepts the options presented in this section. Print the values of the arguments passed to `main`.

[**Solution:**](src/ex6_26.cpp)

```cpp
int main(int argc, char *argv[])
{
    string str;
    int i = 0;
    while (argv[i]) {
        str = argv[i++];
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
```

### Section 6.2.6: Functions with Varying Parameters

**Exercise 6.27:** Write a function that takes an `initializer_list<int>` and produces the sum of the elements in the list.

[**Solution:**](src/ex6_27.cpp)

```cpp
int int_sum(initializer_list<int> int_lst)
{
    int sum = 0;
    for (auto &int_ref : int_lst) sum += int_ref;
    return sum;
}
```

**Exercise 6.28:** In the second version of `error_msg` that has an `ErrCode` parameter, what is the type of `elem` in the `for` loop?

**Solution:** `elem` is a reference to `const string` in the `for` loop.

**Exercise 6.29:** When you use an `initializer_list` in a range `for` would you ever use a reference as the loop control variable? If so, why? If not, why not?

**Solution:** Yes, if we do not want to make an unnecessary copy of the objects in the `initializer_list`.

## Section 6.3: Return Types and the `return` Statement

### Section 6.3.1: Functions with No Return Value

### Section 6.3.2: Functions that Return a Value

**Exercise 6.30:** Compile the version of `str_subrange` as presented on page 223 to see what your compiler does with the indicated errors.

**Exercise 6.31:** When is it valid to return a reference? A reference to `const`?

**Exercise 6.32:** Indicate whether the following function is legal. If so, explain what it does; if not, correct any errors and then explain it.

**Exercise 6.33:** Write a recursive function to print the contents of a `vector`.

**Exercise 6.34:** What would happen if the stopping condition in `factorial` were

```cpp
if (val != 0)
```

**Exercise 6.35:** In the call to `factorial`, why did we pass `val - 1` rather than `val--`?

### Section 6.3.3: Returning a Pointer to an Array

**Exercise 6.36:** Write the declaration for a function that returns a reference to an array of ten `string`s, without using either a trailing return, `decltype`, or a type alias.

**Exercise 6.37:** Write three additional declarations for the function in the previous exercise. Omne should use a type alias, one should use a trailing return, and the third should use `decltype`. Which form do you prefer and why?

**Exercise 6.38** Revise the `arrPtr` function on to return a reference to the array.

## Section 6.4: Overloaded Functions

**Exercise 6.39:** Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

* (a) 

```cpp
int cal(int, int);
int calc(const int, const int);
```

* (b)

```cpp
int get();
double get();
```

* (c)

```cpp
int *reset(int *);
double *reset(double *);
```

### Section 6.4.1: Overloading and Scope

## Section 6.5: Features for Specialized Uses

### Section 6.5.1: Default Arguments

**Exercise 6.40:** Which, if either, of the following declarations are errors? Why?

* (a) 

```cpp
int ff(int a , int b = 0, int c = 0);
```

* (b)

```cpp
char v*init(int ht = 2, int wd, char backgrnd);
```

**Exercise 6.41:** Which, if any of the following calls are illegal? Why? Which, if any, are legal but unlikely to match the programmer's intent? Why?

```cpp
char *init(int ht, int wd = 80, char backgrnd = ' ';
```

* (a) 

```cpp
init();
```

* (b)

```cpp
init(24,10);
```

* (c)

```cpp
init(14, '*');
```

**Exercise 6.42:** Give the third paramter of `make_plural` a default argument of `'s'`. Test your program by printing singular and plural versions of the words `success` and `failure`.


### Section 6.5.2: Inline and `constexpr` Functions

**Exercise 6.43:** Which one of the following declarations and definitions would you put in a header? In a source file? Explain why.

* (a) 

```cpp
inline bool eq(const BigInt&, const BigInt&) {...}
```

* (b)

```cpp
void putValues(int *arr, int sie);
```

**Exercise 6.44:** Rewrite `isShorter` function from [6.2.2](#section-622-passing-arguments-by-reference) to be `inline`.

**Exercise 6.45:** Review the programs you've written for the earlier exercises an ddecide whether they should be defined as `inline`. If so, do so. If not, explain why they should not be `inline`.

**Exercise 6.46:** Would it be possible to define `isShorter` as a `constexpr`? If so, do so. If not, explain why not.

### Section 6.5.3: Aids for Debugging

**Exercise 6.47:** Revise the program you wrote in the exercises in [6.3.2](#section-632-functions-that-return-a-value) that used recursion to print the contents of a `vector` to conditionally print information about its execution. For example, you might print the size of the `vector` on each call. Compile and run the program with debugging turned on and again with it turned off.

**Exercise 6.48:** Explain what this loop does and wheter it is a good use of `assert`:

```cpp
string s;
while (cin >> s && s != sought) { }  // empty body
assert(cin);
```

## Section 6.6: Function Matching

**Exercise 6.49:** What is a candidate function? What is a viable function?

**Exercise 6.50:** Given the declarations for `f` from page 242, list viable functions, if any, for each of the following calls. Indicate which function is the best match, or if the call is illegal whether there is no match or why the call is ambiguous.

```cpp
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
f(5.6);  // calls void f(double, double)
```

* (a) 

```cpp
f(2.56, 42)
```

* (b)

```cpp
f(42)
```

* (c)

```cpp
f(42, 0)
```

* (d)

```cpp
f(2.56, 3.14)
```

**Exercise 6.51:** Write all four versions of `f`. Each function should print a distinguishing message. Check your answers for the previous exercise. If your answers were incorrect, study this section until you understand why your answers were wrong.

### Section 6.6.1: Argument Type Conversions

**Exercise 6.52:** Given the following declarations,

```cpp
void manip(int, int);
double dobj;
```

what is the rank of each conversion in the following calls?

* (a) 

```cpp
manip('a', 'z');
```

* (b)

```cpp
manip(55.4, dobj);
```

**Exercise 6.53:** Explain the effect of the second declaration in each one of the following sets of declarations. Indicate which, if any, are illegal.

* (a)

```cpp
int calc(int&, int&);
int calc(const int&, const int&);
```

* (b)

```cpp
int calc(char*, char*);
int calc(const char*, const char*);
```

* (c)

```cpp
int calc(char*, char*);
int calc(char* const, char* const);
```

## Section 6.7: Pointers to Functions

**Exercise 6.54:** Write a declaration for a function that takes two `int` parameters and returns an `int`, and declare a `vector` whose elements have this function pointer type.

**Exercise 6.55:** Write four functions that add, subtract, multiply and divide two `int` values. Store pointers to these functions in your `vector` from the previous exercise.

**Exercise 6.56:** Call each element in the `vector` and print their result.
