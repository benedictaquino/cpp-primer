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

[**Solution:**](include/ex7_2.h)

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

[**Solution:**](include/ex7_4.h)

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

[**Solution:**](include/ex7_5.h) Yes, these functions should be `const`. I do not want these operations to modify the members of my `Person` object, only return them.

```cpp
struct Person {
    std::string who() const { return name; }
    std::string where() const { return address; }
    std::string name;
    std::string address;
};
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

[**Solution:**](include/ex7_15.h)

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

**Solution:** There are no constraints on where or how often an access specifier may appear inside a class definition. Members that are accessible to all parts of the program should be defined after the `public` specifier. Members that should only be accessible to the member functions of the class and not accessible to the code that uses the class should be after the `private` specifier.

**Exercise 7.17:** What, if any, are the differences between using `class` or `struct`?

**Solution:** The difference between the `class` and `struct` keywords is the access to the members defined before the first access specifier. Members defined before the first access specifier for a class using the `struct` keyword are `public`; members defined before the first access specifier for a class using the `class` keyword are `private`.

**Exercise 7.18:** What is encapsulation? Why is it useful?

**Solution:** Encapsulation is hiding the implementation of members in a class. This is useful if we want to limit the amount users or the program can meddle with a class' implementation.

**Exercise 7.19:** Indicate which members of your `Person` class you would declare as `public` and which you would declare as `private`. Explain your choice.

**Solution:** I would declare the constructors to be `public` as well as the member functions `who` and `where`. the members `name` and `address` I would declare as `private`.

### Section 7.2.1: Friends

**Exercise 7.20:** When are friends useful? Discuss the pros and cons of using friends.

**Solution:** Friends are useful when we want nonmember classes or functions to have access to a class' `private` members. The benefit of friends is that we can allow specific functions or classes to have access to any `private` members of a class. The negative is that it begins to get rid of the benefits of encapsulation; user code can now inadvertently corrupt the state of an encapsulated object and an encapsulated class may require change to user-code to change the implementation.

**Exercise 7.21:** Update your `Sales_data` class to hide its implementation. The programs you've written to use `Sales_data` operations should still continue to work. Recompile those programs with your new class definition to verify that they still work.

[**Solution:**](include/ex7_21.h)

```cpp
class Sales_data {
// friend declarations for nonmember operations
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
public:
    // constructors
    Sales_data(): bookNo(), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream&);
    // public member functions
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&); 
private:
    // private member functions
    double avg_price() const { return units_sold ? revenue/units_sold : 0; }
    // member objects
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember declarations
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
```

**Exercise 7.22:** Update your `Person` class to hide its implementation.

[**Solution:**](include/ex7_22.h)

```cpp
class Person {
// friend declarations
friend std::istream &read(std::istream&, Person&);
friend std::ostream &print(std::ostream&, Person&);
public:
    // constructors
    Person() = default;
    Person(const std::string &s): name(s) { }
    Person(const std::string &s1, const std::string &s2): name(s1), address(s2) { }
    Person(std::istream&);
    // member functions
    std::string who() const { return name; }
    std::string where() const { return address; }
private:
    // member objects
    std::string name;
    std::string address;
};

// nonmember declarations
std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);
```

## Section 7.3: Additional Class Features

### Section 7.3.1: Class Members Revisited

**Exercise 7.23:** Write your own version of the `Screen` class

[**Solution:**](include/ex7_23.h)

```cpp
class Screen {
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    char get() const { return contents[cursor]; } // get character at the cursor
    inline char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
};

inline Screen &Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

char Screen::get(pos r, pos c) const // declared inline inside class body
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}
```

**Exercise 7.24:** Give your `Screen` class three constructors: a default constructor; a constructor that takes values for height and width and initializes the contents to hold the given number of blanks; and a constructor that takes values for height, width, and a character to use as the contents of the screen.

[**Solution:**](include/ex7_24.h)

```cpp
class Screen {
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    char get() const { return contents[cursor]; } // get character at the cursor
    char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
};

inline Screen &Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const // declared inline inside class body
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}
```

**Exercise 7.25:** Can `Screen` safely rely on the default vesions of copy and assignment? If so, why? If not, why not?

**Solution:** **Yes, `Screen` can safely rely on the default versions of copy and assignment.** `Screen`'s members are using primitive built-in types and a `string` object, which all play nicely with the synthesized default versions of copy and assignment.

**Exercise 7.26:** Define `Sales_data::avg_price` as an `inline` function.

[**Solution:**](include/ex7_26.h)

```cpp
class Sales_data {
// friend declarations for nonmember operations
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
public:
    // constructors
    Sales_data(): bookNo(), units_sold(0), revenue(0.0) { }
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream&);
    // public member functions
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&); 
private:
    // private member functions
    inline double avg_price() const { return units_sold ? revenue/units_sold : 0; }
    // member objects
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

// nonmember declarations
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
```

### Section 7.3.2: Functions That Return `*this`

**Exercise 7.27:** Add the `move`, `set`, and `display` operations to your version of `Screen`. Test your class by executing the following code:

```cpp
Screen myScreen(5, 5, 'X');
myScreen.move(4,0).set('#').display(cout);
cout << "\n";
myScreen.display(cout);
cout << "\n";
```

[**Solution:**](include/ex7_27.h)

```cpp
class Screen {
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    char get() const { return contents[cursor]; } // get character at the cursor
    char get(pos, pos) const; 
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display is overloaded on whether the object is const or not
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
    // private member objects
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
    // private member functions
    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const 
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;  // set the new value at the current cursor location
    return *this;          // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;  // set specified location to given value
    return *this;                  // return this object as an lvalue
}
```

**Exercise 7.28:** What would happen in the previous exercise if the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`?

**Solution:** If the return type of `move`, `set`, and `display` was `Screen` rather than `Screen&`, then it would return a copy of the object rather than the object itself. `move` and `set` would modify the copy and return the modified copy, and the original object would remain unchanged. `display` would make a copy of the object then print its contents.

So in the previous exercise, the output would be as such:

```
#XXXXXXXXXXXXXXXXXXXXXXXX
XXXXXXXXXXXXXXXXXXXXXXXXX
```

**Exercise 7.29:** Revise your `Screen` class so that `move`, `set`, and `display` functions return `Screen` and check your prediction from the previous exercise.

[**Solution:**](include/ex7_28.h)

```cpp
class Screen {
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    // get character at the cursor
    char get() const { ++access_ctr; return contents[cursor]; } 
    char get(pos, pos) const; 
    // move cursor
    Screen move(pos, pos);
    // set character
    Screen set(char); // at cursor location
    Screen set(pos, pos, char); // at specified location
    // display contents of Screen
    Screen display(std::ostream &os) { do_display(os); return *this; }
    const Screen display(std::ostream &os) const { do_display(os); return *this; }
private:
    // private member objects
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
    // private member functions
    void do_display(std::ostream &os) const { ++access_ctr; os << contents; }
};

inline Screen Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const 
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}

inline Screen Screen::set(char c)
{
    ++access_ctr;
    contents[cursor] = c;  // set the new value at the current cursor location
    return *this;          // return this object as an lvalue
}

inline Screen Screen::set(pos r, pos c, char ch)
{
    ++access_ctr;
    contents[r * width + c] = ch;  // set specified location to given value
    return *this;                  // return this object as an lvalue
}
```
**Exercise 7.30:** It is legal but redundant to refer to members through the `this` pointer. Discuss the pros and cons of explicitly using the `this` pointer to access members.

**Solution:** Explicitly referring to the `this` pointer when referring to members would make the code clearer when it is referring to member objects, however it would be more verbose. This could be beneficial when defining member functions outside of the class body to make things clearer.

### Section 7.3.3 Class Types

**Exercise 7.31:** Define a pair of classes `X` and `Y`, in which `X` has a pointer to `Y`, and `Y` has an object of type `X`.

[**Solution:**](include/ex7_31.h)

```cpp
// class declarations
struct X;
struct Y;

// class definitions
struct X {
    Y *y_guy;
};

struct Y {
    X x_guy;
};
```

### Section 7.3.4: Friendship Revisited

**Exercise 7.32:** Define your own version of `Screen` and `Window_mgr` in which `clear` is a member of `Window_mgr` and a friend of `Screen`.

[**Solution:**](include/ex7_32.h)

```cpp
class Screen;

class Window_mgr {
public:
    // constructors
    Window_mgr();  // declare outside of class body
    // location ID for each screen on the window
    typedef std::vector<Screen>::size_type ScreenIndex;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
    // add Screen to Window_mgr
    Window_mgr &add(Screen&);
    // display Screen at given position
    Window_mgr &display(std::ostream&, ScreenIndex);
    const Window_mgr &display(std::ostream&, ScreenIndex) const;
private:
    std::vector<Screen> screens;
};

class Screen {
friend void Window_mgr::clear(ScreenIndex);
friend Window_mgr &Window_mgr::display(std::ostream&, ScreenIndex);
friend const Window_mgr &Window_mgr::display(std::ostream&, ScreenIndex) const;
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    // get character 
    char get() const { ++access_ctr; return contents[cursor]; }  // at cursor
    char get(pos, pos) const; // at specified location
    // move cursor
    Screen &move(pos, pos); // to specified location
    // set character 
    Screen &set(char); // at cursor
    Screen &set(pos, pos, char); // at specified location
    // display contents of Screen
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
    // private member objects
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
    // private member functions
    void do_display(std::ostream &os) const { ++access_ctr; os << contents; }
};

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} { }

void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr &Window_mgr::add(Screen &s)
{
    screens.push_back(s);
    return *this;
}

Window_mgr &Window_mgr::display(std::ostream &os, ScreenIndex i)
{
    screens[i].display(os);
    return *this;
}

const Window_mgr &Window_mgr::display(std::ostream &os, ScreenIndex i) const
{
    screens[i].display(os);
    return *this;
}

inline Screen &Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const 
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}

inline Screen &Screen::set(char c)
{
    ++access_ctr;
    contents[cursor] = c;  // set the new value at the current cursor location
    return *this;          // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    ++access_ctr;
    contents[r * width + c] = ch;  // set specified location to given value
    return *this;                  // return this object as an lvalue
}
```
## Section 7.4: Class Scope

**Exercise 7.33:** What would happen if we gave the `Screen` a `size` member defined as follows? Fix any problems you identify.

```cpp
pos Screen::size() const
{
    return height * width;
}
```

**Solution:** `size` should return the value of the expression `height * width`. However, if we are defining `size` outside of the class body, then we need use the scoping operator to use `pos` from inside `Screen`.

```cpp
Screen::pos Screen::size() const
{
    return height * width;
}
```

### Section 7.4.1: Name Lookup and Class Scope

**Exercise 7.34:** What would happen if we put the `typedef` of `pos` in the `Screen` class on page 285 as the last line in the class?

**Solution:** If we put the `typedef` of `pos` as the last line of the class, then we would not be to use the `pos` type name in any of the declarations or definitions above that line. The program would not compile because `pos` was not defined before trying to use it.

**Exercise 7.35:** Explain the following code, indicating which definition of `Type` or `initVal` is used for each of those names. Say how you would fix any errors.

```cpp
typedef string Type;
Type initVal();
class Exercise {
public:
    typedef double Type;
    Type setVal(Type);
    Type initVal();
private:
    int val;
};
Type Exercise::setVal(Type parm) {
    val = parm + initVal();
    return val;
}
```

**Solution:** `Type` is first defined in the outer scope as a type name for `string`. Then `initVal` is declared as a function with return type `Type` (or `string`).

Inside the class body of `Exercise`, `Type` is defined as a name for `double`. This is an error, but since compilers are not required to diagnose this error, some may quietly accept this code. Then `setVal` and `initVal` are declared as a member functions with an `Exercise::Type` and a return type of `Exercise::Type`. These are legal declarations, the name `setVal` is not used yet, and the name `initVal` from the outer scope is masked by the declaration in the inner scope.

I would rename or remove the definition of `Type` on the first line, and in the definition of `setVal` I would specify the scope of `Type`. As well, `Exercise::initVal` needs to be defined before being used in `setVal`'s definition.

```cpp
Exercise::Type Exercise::setVal(Type parm) {
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

[**Solution:**](src/7_36.cpp) `rem` is declared before `base` in the class definition, so it is initialized first. So trying to initialize `rem` with the expression `base % j` will result in undefined behavior.

I would rewrite this constructor to have `rem` before `base` to match the order that the members are declared. As well, I would not use `base` inside the expression to initialize `rem`, I would use `i % j`.

```cpp
struct X {
    X (int i, int j): rem(i % j), base(i)  { }
    int rem, base;
};
```

**Exercise 7.37:** Using the version of [`Sales_data`](include/p290.h) from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:

```cpp
Sales_data first_item(cin);

int main() {
    Sales_data next;
    Sales_data last("9-999-99999-9");
}
```

**Solution:** `next` is initialized with the default constructor `Sales_data(std::string s = "")`.The default values are the empty string for `bookNo`, `0` for `units_sold`, and `0.0` for `revenue`.

`last` is also initialized with the `Sales_data(std::string)` constructor, but it passes in a `string` as an argument. This initializes `bookNo` with the string literal `"9-999-99999-9"` and leaves `units_sold` and `revenue` with their default initializations defined in the class body.

**Exercise 7.38:** We might want to supply `cin` as a default argument to the constructor that takes an `istream&`. Write the constructor declaration that uses `cin` as a default argument.

[**Solution:**](src/ex7_38.cpp)

```cpp
Sales_data::Sales_data(std::istream &is = cin)
{
    read(is, *this);
}
```

**Exercise 7.39:** Would it be legal for both the constructor that takes a `string` and the one that takes an `istream&` to have default arguments? If not, why not?

**Solution:** No, because then initializing a `Sales_data` object without any arguments would be ambiguous.

**Exercise 7.40:** Choose one of the following abstractions (or an abstraction of your own choosing). Determine what data are needed in the class. Provide an appropriate set of constructors. Explain your decisions.

* (a) `Book`
* (b) `Date`
* (c) `Employee`
* (d) `Vehicle`
* (e) `Object`
* (f) `Tree`


**Book Solution:** The data I would want in my `Book` class are `title` and `author`. I would default initialize `title` to the empty string and `author` as `"Anonymous"`.

My constructors are as such:

```cpp
// defines the default constructor as well as one that takes a string argument
Book(std::string s1 = "", std::string s2 = "Anonymous"): title(s1), author(s2) { }
// defines a constructor that initializes the members from an istream
Book(std::istream &is) { read(is, *this); }
```

The first constructor kills three birds in one stone for me. If I pass in no arguments, the object is default initialized. If I pass in an argument for `title`, then the `author` remains `"Anonymous"`; for some famous novels the true writer is anonymous, such as *Beowulf*. If I know both the title and the author, then I can pass in both of those arguments. The second constructor uses data from the standard input to initialize the members.

[**Book Header File:**](include/ex7_40.h)

```cpp
class Book;
std::istream &read(std::istream&, Book&);

class Book {
friend std::istream &read(std::istream&, Book&);
friend std::ostream &print(std::ostream&, Book&);
public:
    // constructors
    Book(std::string s1 = "", std::string s2 = "Anonymous"): title(s1), author(s2) { }
    Book(std::istream &is) { read(is, *this); }
    // member functions
private:
    // private members
    std::string title, author = "Anonymous";
};

std::ostream &print(std::ostream&, Book&);
```

[**Book Source File:**](src/ex7_40.cpp)

```cpp
using std::istream; using std::ostream;
using std::string;

istream &read(istream &is, Book &book)
{
    getline(is, book.title);
    getline(is, book.author);
    return is;
}

ostream &print(ostream &os, Book &book)
{
    os << "Title: " <<  book.title << "\n"
       << "Author: " << book.author << "\n";
    return os;
}
```

[**Book Constructor Test:**](src/ex7_40_test.cpp)

```cpp
int main()
{
    cout << "Default constructor:\n";
    Book book_default;
    print(cout, book_default);

    cout << "Title constructor:\n";
    Book book_title("Beowulf");
    print(cout, book_title);

    cout << "Title and Author constructor:\n";
    Book book_title_author("Harry Potter and the Goblet of Fire", "J. K. Rowling");
    print(cout, book_title_author);

    cout << "istream constructor:\n";
    Book book_is(cin);
    print(cout, book_is);

    return 0;
}
```

**Output:**

```
Default constructor:
Title:
Author: Anonymous
Title constructor:
Title: Beowulf
Author: Anonymous
Title and Author constructor:
Title: Harry Potter and the Goblet of Fire
Author: J. K. Rowling
istream constructor:
Blood Meridian or Evening Redness in the West
Cormac McCarthy
Title: Blood Meridian or Evening Redness in the West
Author: Cormac McCarthy
```

### Section 7.5.2: Delegating Constructors

**Exercise 7.41:** Rewrite your own version of the `Sales_data` class to use delegating constructors. Add a statement to the body of each of the constructors that prints a message whenever it is executed. Write declarations to construct a `Sales_data` object in every way possible. Study the output until you are certain you understand the order of execution among delegating constructors.

[**Solution:**](include/ex7_41.h)

```cpp
// nondelegating constructor
Sales_data(std::string s, unsigned cnt, double price):
    bookNo(s), units_sold(cnt), revenue(cnt * price) {
        std::cout << "Nondelegating constructor.\n";
    }
// delegating constructors
Sales_data(): Sales_data("", 0, 0.0) { 
    std::cout << "Default constructor\n"; 
}
Sales_data(const std::string &s): Sales_data(s, 0, 0.0) { 
    std::cout << "ISBN constructor.\n";
}
Sales_data(unsigned n): Sales_data("", n, 0.0) {
    std::cout << "Units sold constructor.\n";
}
Sales_data(double p): Sales_data("", 0, p) {
    std::cout << "Price constructor.\n";
}
Sales_data(const std::string &s, unsigned n): Sales_data(s, n, 0.0) {
    std::cout << "ISBN and units sold constructor.\n";
}
Sales_data(const std::string &s, double p): Sales_data(s, 0, p) {
    std::cout << "ISBN and price constructor.\n";
}
Sales_data(unsigned n, double p): Sales_data("", n, p) {
    std::cout << "Units sold and price constructor.\n";
}
Sales_data(std::istream &is): Sales_data() { 
    read(is, *this); 
    std::cout << "istream constructor.\n";
}
```

[**Test Script:**](src/ex7_41.cpp)

```cpp
cout << "Default constructor:\n";
Sales_data item_default;
print(cout, item_default);

cout << "ISBN constructor:\n";
Sales_data item_isbn("0-201-16209-X");
print(cout, item_isbn);

cout << "Units sold constructor:\n";
Sales_data item_units(10u);
print(cout, item_units);

cout << "Price constructor:\n";
Sales_data item_price(100.);
print(cout, item_price);

cout << "ISBN and units sold constructor:\n";
Sales_data item_isbn_units("0-201-78345-X", 3u);
print(cout, item_isbn_units);

cout << "ISBN and price constructor:\n";
Sales_data item_isbn_price("0-201-78345-X", 20.75);
print(cout, item_isbn_price);

cout << "Units sold and price constructor:\n";
Sales_data item_units_price(3u, 20.75);
print(cout, item_units_price);

cout << "Full transaction constructor:\n";
Sales_data item_full("0-201-78345-X", 3u, 20.75);
print(cout, item_full);

cout << "istream constructor:\n";
Sales_data item_is(cin);
print(cout, item_is);
```

**Output:**

```
Default constructor:
Nondelegating constructor.
Default constructor
 0 0 0
ISBN constructor:
Nondelegating constructor.
ISBN constructor.
0-201-16209-X 0 0 0
Units sold constructor:
Nondelegating constructor.
Units sold constructor.
 10 0 0
Price constructor:
Nondelegating constructor.
Price constructor.
 0 0 0
ISBN and units sold constructor:
Nondelegating constructor.
ISBN and units sold constructor.
0-201-78345-X 3 0 0
ISBN and price constructor:
Nondelegating constructor.
ISBN and price constructor.
0-201-78345-X 0 0 0
Units sold and price constructor:
Nondelegating constructor.
Units sold and price constructor.
 3 62.25 20.75
Full transaction constructor:
Nondelegating constructor.
0-201-78345-X 3 62.25 20.75
istream constructor:
Nondelegating constructor.
Default constructor
istream constructor.
0-201-78345-X 3 62.25 20.75
```

**Exercise 7.42:** For the class you wrote for [exercise 7.40](src/ex7_40.cpp) in [7.5.1](#section-751-constructor-initializer-list), decide whether any of the constructors might use delegation. If so, write the delegating constructor(s) for your class. If not, look at the list of abstractions and choose one that you think would use a delegating constructor. Write the class definition for that abstraction.

[**Solution:**](include/ex7_42.h)

```cpp
class Employee {
friend std::istream &read(std::istream&, Employee&);
friend std::ostream &print(std::ostream&, Employee&);
public:
    // nondelegating constructor
    Employee(std::string s1, std::string s2, unsigned n):
        name(s1), title(s2), salary(n) { }
    // delegating constructors
    Employee(): Employee("", "", 0) { }
    Employee(const std::string &s): Employee(s, "", 0) { }
    Employee(unsigned n): Employee("", "", n) { }
    Employee(const std::string &s1, const std::string &s2): Employee(s1, s2, 0) { }
    Employee(const std::string &s, unsigned n): Employee(s, "", n) { }
    Employee(std::istream &is): Employee() { read(is, *this); }
private:
    std::string name = "";
    std::string title = ""; 
    unsigned salary = 0;
};
```

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

**Exercise 7.58:** Which, if any, of the following `static` data member declarations and definitions are errors? Explain why.

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
