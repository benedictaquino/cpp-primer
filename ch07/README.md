# Chapter 7: Classes

## Section 7.1: Defining Abstract Data Types

### Section 7.1.1: Designing the `Sales_data` Class

**Exercise 7.1:** Write a version of the transaction-processing [program](../ch01/src/ex1_25.cpp) from [1.6](../ch01#section-16-the-bookstore-program) using the [`Sales_data`](../ch02/src/Sales_data.h) class you defined for the exercises in [2.6.1](../ch02#section-261-defining-the-sales_data-type).

[**Solution:**](src/ex7_1.cpp)

```cpp
int main()
{
    Sales_data total;  // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        total.revenue *= total.units_sold;
        Sales_data trans;  // variable to hold the running sum
        // read and process the remaining transactions
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // if we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                // update the running total
                total.revenue += trans.revenue * trans.units_sold;  
                total.units_sold += trans.units_sold;
            } else { // print the results for the previous books
                cout << total.bookNo << " "
                     << total.units_sold << " "
                     << total.revenue << " "
                     << total.revenue / total.units_sold << "\n";
                total = trans;  // total now refers to the next book
                total.revenue *= total.units_sold;
            } 
        }
        // print the last transaction
        cout << total.bookNo << " " 
             << total.units_sold << " " 
             << total.revenue <<  " "
             << total.revenue / total.units_sold << endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" << endl;
        return -1;  // indicate failure
    }
    return 0;
}
```

### Section 7.1.2: Defining the Revised `Sales_data` Class

**Exercise 7.2:** Add the `combine` and `isbn` members to the [`Sales_data`](../ch02/src/Sales_data.h) class you wrote for the exercises in [2.6.2](../ch02#section-262-using-the-sales_data-class).

[**Solution:**](include/Sales_data.h)

```cpp
#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &rhs) {
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;
        return *this;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

#endif
```

**Exercise 7.3:** Revise your transaction-processing program from [7.1.1](#section-711-designing-the-sales_data-class)

[**Solution:**](src/ex7_3.cpp)

```cpp
int main()
{
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        total.revenue *= total.units_sold;
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            // if we're still processing the same book
            trans.revenue *= trans.units_sold;
            if (total.isbn() == trans.isbn()) 
                total.combine(trans); // update the running total
            else { // print the results for the previous books
                cout << total.bookNo << " "
                     << total.units_sold << " "
                     << total.revenue << " "
                     << total.revenue / total.units_sold << "\n";
                total = trans;
            }
        }
        // print the last transaction
        cout << total.bookNo << " "
             << total.units_sold << " "
             << total.revenue << " "
             << total.revenue / total.units_sold << endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
```

**Exercise 7.4:** Write a class named `Person` that represents the name and address of a person. Use a `string` to hold each of these elements. Subsequent exercises will incrementally add features to this class.

[**Solution:**](include/Person.h)

```cpp
#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    std::string name;
    std::string address;
};

#endif
```

**Exercise 7.5:** Provide operations in your `Person` class to return the name and address. Should these functions be `const`? Explain your choice.

[**Solution:**](include/Person.h) Yes, these functions should be `const`. I do not want these operations to modify the members of my `Person` object, only return them.

```cpp
#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    std::string who() const { return name; }
    std::string where() const { return address; }
    std::string name;
    std::string address;
};

#endif
```

### Section 7.1.3: Defining Nonmember Class-Related Functions

**Exercise 7.6:** Define your own versions of the `add`, `read`, and `print` functions.

[**Solution:**](src/sales_functions.cpp)

```cpp
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, const Sales_data &item) 
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    cout << item.bookNo << " "
         << item.units_sold << " "
         << item.revenue << " "
         << item.avg_price();
    return os;
}
```

**Exercise 7.7:** Rewrite the transaction-processing program you wrote for the exercises in [7.1.2](#section-712-defining-the-revised-sales_data-class)

[**Solution:**](src/ex7_7.cpp)

```cpp
int main()
{
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (read(cin, total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(cin, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn())
                total = add(total, trans); // update the running total
            else { 
                // print the results for the previous books
                print(cout, total);
                cout << "\n";
                total = trans; // total now refers to the current book
            }
        }
        // print the last transaction
        print(cout, total);
        cout << endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
```

**Exercise 7.8:** Why does `read` define its `Sales_data` parameter as a plain reference and `print` define its parameter as a reference to `const`?

**Solution:** `read` defines its `Sales_data` parameter as a plain reference because it writes to the `Sales_data` object. `print` defines its `Sales_data` parameter as a reference to `const` because it does not need to write to the `Sales_data` object.

**Exercise 7.9:** Add operations to read and print `Person` objects to the code you wrote for the exercises in [7.1.2](#section-712-defining-the-revised-sales_data-class)

[**Solution:**](src/person_functions.cpp)

```cpp
istream &read(istream &is, Person &dude)
{
    getline(is, dude.name);
    getline(is, dude.address);
    return is;
}

ostream &print(ostream &os, const Person &dude)
{
    os << dude.who() << " lives at " << dude.where(); 
    return os;
}
```

**Exercise 7.10:** What does the condition in the following `if` statement do?

```cpp
if (read(read(cin, data1), data2))
```

**Solution:** The innermost `read` reads the `istream` object to the members of `data1`, then the `istream` object is passed to the the outer `read` function and the data is read to the members of `data2`. So, the condition in this `if` statement tests if there is enough correct data from the standard input to read `data1` and `data2`.

### Section 7.1.4: Constructors

**Exercise 7.11:** Add constructors to your `Sales_data` class and write a program to use each of the constructurs.

[**Solution:**](src/ex7_11.cpp)

```cpp
struct Sales_data {
    // constructors
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &is);
    // member functions
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&); 
    double avg_price() const;
    // member objects
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

```

```cpp
int main()
{
    // default constructor
    cout << "Testing default constructor:\n...\n";
    Sales_data item_default;
    print(cout, item_default);
    cout << "\n";

    // string parameter constructor
    cout << "Testing single string parameter constructor:\n...\n";
    Sales_data item_string("0-201-78345-X");
    print(cout, item_string);
    cout << "\n";

    // three parameter constructor
    cout << "Testing full parameter constructor:\n...\n";
    Sales_data item_params("0-201-78345-X", 3, 20.75);
    print(cout, item_params);
    cout << "\n";

    // istream constructor
    cout << "Testing istream constructor:\n...\n";
    Sales_data item_istream(cin);
    print(cout, item_istream);
    cout << endl;

    return 0;
}
```

**Exercise 7.12:** Move the definition of the `Sales_data` constructor that takes an `istream` into the body of the `Sales_data` class.

[**Solution:**](include/Sales_data.h)

```cpp
struct Sales_data; // declared before used in read operator
std::istream &read(std::istream&, Sales_data&); // declared before used inside class body

struct Sales_data {
    // constructors
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &is) {
        read(is, *this);
    }
    // member functions
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&); 
    double avg_price() const;
    // member objects
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

```

**Exercise 7.13:** Rewrite the [program from page 255](src/pg255.cpp) to use the `istream` constructor.

[**Solution:**](src/ex7_13.cpp)

```cpp
int main()
{
    Sales_data total(cin);       // variable to hold the running sum
    if (cin) {                   // read the first transaction
        Sales_data trans(cin);   // variable to hold data for the next transaction
        while (cin) {            // read the remaining transactions
            if (total.isbn() == trans.isbn()) // check the isbns
                total.combine(trans);         // update the running total
            else {
                print(cout, total) << endl;   // print the results
                total = trans;                // process the next book
            }
            read(cin, trans);
        }
        print (cout, total) << endl;   // print the last transaction
    } else {                           // there was no input
        cerr << "No data ?!" << endl; // notify the user
        return -1;                     // indicate failure
    }
    return 0;
}
```

**Exercise 7.14:** Write a version of the default constructor that explicitly initializes the members to the values we have provided as in-class initializers.

[**Solution:**](include/Sales_data.h)

```cpp
struct Sales_data; // declared before used in read operator
std::istream &read(std::istream&, Sales_data&); // declared before used inside class body

struct Sales_data {
    // constructors
    Sales_data(): bookNo(), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &is) {
        read(is, *this);
    }
    // member functions
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&); 
    double avg_price() const;
    // member objects
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
```

**Exercise 7.15:** Add appropriate constructors to your `Person` class.

[**Solution:**](include/Person.h)

```cpp
struct Person {
    // constructors
    Person() = default;
    Person(const std::string &s): name(s) { }
    Person(const std::string &s1, const std::string &s2): name(s1), address(s2) { }
    Person(std::istream&);
    // member functions
    std::string who() const { return name; }
    std::string where() const { return address; }
    // member objects
    std::string name;
    std::string address;
};
```

```cpp
Person::Person(istream &is)
{
    read(is, *this);
}
```

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

**Exercise 7.33:** What would happen if we gave the `Screen` a `size` member defined as follows? Fix any problems you identify.

```cpp
pos Screen::size() const
{
    return height * width;
}
```

### Section 7.4.1: Name Lookup and Class Scope

**Exercise 7.34:** What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

**Exercise 7.35:** Explain the following code, indicating which definition of `Type` or `initVal` is used for each of those names. Say how you would fix any errors.

```cpp
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
pritvate:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

## Section 7.5: Constructors Revisited

### Section 7.5.1: Constructor Initializer List

**Exercise 7.36:** The following initializer is in error. Identify and fix the problem.

```cpp
struct X {
    X (int i, int j): base(i), rem(base % j) { }
    int rem, base;
};
```

**Exercise 7.37:** Using the version of [`Sales_data`](include/Sales_data.h) from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:

```cpp
Sales_data first_item(cin);

int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```

**Exercise 7.38:** We might want to supply `cin` as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses `cin` as a default argument.

**Exercise 7.39:** Would it be legal for both the constructor that takes a `string` and the one that takes an `istream&` to have default arguments? If not, why not?

**Exercise 7.40:** Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.

* (a) `Book`
* (b) `Date`
* (c) `Employee`
* (d) `Vehicle`
* (e) `Object`
* (f) `Tree`

### Section 7.5.2: Delegating Constructors

**Exercise 7.41:** Rewrite your own version of the `Sales_data` class to uyse delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

**Exercise 7.42:** For the class you wrote for [exercise 7.40](src/ex7_40.cpp) in [7.5.1](#section-751-constructor-initializer-list), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

## Section 7.5.3: The Role of the Default Constructor

**Exercise 7.43:** Assume we have a class named `NoDefault` that has a constructor that takes an `int`, but has no default constructor. Define a class `C` that has a member of type `NoDefault`. Define the default constructor for `C`.

**Exercise 7.44:** Is the following declaration legal? If not, why not?

```cpp
vector<NoDefault> vec(10);
```

**Exercise 7.45:** What if we defined the `vector` in the previous exercise to hold objects of type `C`?

**Exercise 7.46:** Which, if any, of the following statements are untrue? Why?

* (a) A Class must provide at least one constructor.
* (b) A default constructor is a constructor with an empty parameter list.
* (c) If there are no meaningful default values for a class, the class should not provide a default constructor.
* (d) If a class does not define a default constructor, the compiler generates on that initializes each data member to the default value of its associated type.

### Section 7.5.4: Implicit Class-Type Conversions

**Exercise 7.47:** Explain whether the `Sales_data` constructor that takes a `string` should be `explicit`. What are the benefits of making the constructor `explicit`? What are the drawbacks?

**Exercise 7.48:** Assuming the `Sales_data` constructors are not `explicit`, what operations happen during the following definitions?

```cpp
    string null_isbn("9-999-99999-9");
    Sales_data item1(null_isbn);
    Sales_data item2("9-999-99999-9");
```

What happens if the `Sales_data` constructors are `explicit`?

**Exercise 7.49:** For each of the three following declarations of `combine`, explain what happens if we call `i.combine(s)`, where `i` is a `Sales_data` and `s` is a `string`:

* (a) `Sales_data &combine(Sales_data);`
* (b) `Sales_data &combine(Sales_data&);`
* (c) `Sales_data &combine(const Sales_data&) const;`

**Exercise 7.50:** Determine whether any of your `Person` class constructors should be `explicit`.

**Exercise 7.51:** Why do you think `vector` defines it single-argument constructor as `explicit`, but `string` does not?

### Section 7.5.5: Aggregate Classes

**Exercise 7.52:** Using our first version of [`Sales_data`](../ch02/src/Sales_data.h) from  [2.6.1](../ch02#section-261-defining-the-sales_data-type), explain the following initialization. Identify and fix any problems.

```cpp
Sales_data item = {"978-0590353403", 25, 15.99};
```

### Section 7.5.6: Literal Classes

**Exercise 7.53:** Define your own version of `Debug`.

**Exercise 7.54:** Should the members of `Debug` that begin with `set_` be declared as `constexpr`? If not, why not?

**Exercise 7.55:** Is the [`Data`](src/Data.h) class from [7.5.5](#section-755-aggregate-classes) a literal class? If not, why not? If so, explain why it is literal.

## Section 7.6: `static` Class Members

**Exercise 7.56:** What is a `static` class member? What are the advantagses of `static` members? How do they differ from ordinary members?

**Exercise 7.57:** Write your own version of the `Account` class.

**Exercise 7.58:** Which, if any, of the following `static` data member declarations and deginitions are errors? Explain why.

```cpp
// example.h
class Example {
public:
    static double rate = 6.5;
    static const int vecSize = 20;
    static vector<double> vec(vecSize);
};
```

```cpp
// example.C
#include "example.h"
double Example::rate;
vector<double> Example::vec;
```
