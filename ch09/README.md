# Chapter 9: Sequential Containers

## Section 9.1: Overview of the Sequential Containers

**Exercise 9.1:** Which is the most appropriate&mdash;a `vector`, a `deque`, or a `list`&mdash;for the following program tasks? Explain the rationale for your choide. If there is no reason to prefer one or another container, explain why not.

* (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. We'll see in the next chapter that associative containers are better suited to this problem.
* (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
* (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

**Solution:**

* (a) A **`list`** would be the best container for this task. Since the words need to be sorted alphabetically, we will need to insert elements in the middle of the container.
* (b) A **`deque`** would be the best container for this task. A `deque` is best when the program only needs to insert or delete elements at the front and back and not the middle.
* (c) Either a **`vector`** or a **`list`** would be the best container for this task. If we want to sort the integers after creating the container, then we may need random access so a `vector` is preferred. If we want to sort the integers while inserting them into the container, then a `list` is preferred because we need to insert elements into the middle of the container. However, since we will have many small elements, if space overhead matters, then we do not want to use a `list`. 

## Section 9.2: Container Library Overview

**Exercise 9.2:** Define a `list` that holds elements that are `deque`s that hold `int`s.

[**Solution:**](src/ex9_2.cpp)

```cpp
list<deque<int>> int_dq_lst;  // a list of deques of ints
```

### Section 9.2.1: Iterators

**Exercise 9.3:** What are the constraints on the iterators that form iterator ranges?

**Solution:** Iterators that form an iterator range must refer to elements of, or one past the end of, the same conainer, and it must be possible to reach the ending iterator by repeatedly incrementing the beginning iterator.

**Exercise 9.4:** Write a function that takes a pair of iterators to a `vector<int>` and an `int` value. Look for that value in the range and return a `bool` indicating whether it was found.

[**Solution:**](src/ex9_4.cpp)

```cpp
bool findInt(vector<int>::iterator iter1, const vector<int>::iterator &iter2, int i)
{
    while (iter1 != iter2) {
        if (*iter1 == i) return true;
        ++iter1;
    }
    return false;
}
```

**Exercise 9.5:** Rewrite the previous program to return an iterator to the requested element. Note that the program must handle the case where the element is not found.

[**Solution:**](src/ex9_5.cpp)

```cpp
vector<int>::iterator findInt(vector<int>::iterator iter1, 
                              const vector<int>::iterator &iter2, 
                              int i)
{
    while (iter1 != iter2) {
        if (*iter1 == i) return iter1;
        ++iter1;
    }
    return iter2;
}
```

**Exercise 9.6:** What is wrong with the following program? How might you correct it?

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
                    iter2 = lst1.end();
while (iter1 < iter2) /* .. */
```

[**Solution:**](src/ex9_6.cpp) The `<` operator cannot be used on iterators. We need to use the `!=` operator. Also, since `lst1` is empty, then using the `begin` and `end` functions return the same iterator, so the iterator range is empty.

```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin,
                    iter2 = lst1.end,
while (iter1 != iter2) /* ... */
```

### Section 9.2.2: Container Type Members

**Exercise 9.7:** What type should be used as the index into a `vector` of `int`s?

**Solution:** `vector<int>::size_type`

**Exercise 9.8:** What type should be used to read elements in a `list` of `string`s? To write them?

**Solution:** `list<string>::const_iterator` for reading and `list<string>::iterator` to write

### Section 9.2.3: `begin` and `end` Members

**Exercise 9.9:** What is the difference between the `begin` and `cbegin` functions?

**Solution:** `begin` returns an `iterator` or a `const_iterator` since it is an overloaded function. `cbegin` only returns a `const_iterator`. 

**Exercise 9.10:** What are the types of the following four objects?

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

[**Solution:**](src/ex9_10.cpp) 
* `it1` is a `vector<int>::iterator`. 
* `it2` is a `vector<int>::const_iterator`. Since `v2` is a `const vector<int>`, it returns references to `const` references. As well, since `it1` and `it2` are different types, they must be defined in separate statements.
* `it3` is a `vector<int>::const_iterator`.
* `it4` is a `vector<int>::const_iterator`.

```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(); // iterator 
auto it2 = v2.begin(); // const_iterator
auto it3 = v1.cbegin(), it4 = v2.cbegin(); // const_iterator
```

### Section 9.2.4: Defining and Initializing a Container

**Exercise 9.11:** Show an example of each of the six ways to create and initialize a `vector`. Explain what values each `vector` contains.

[**Solution:**](src/ex9_11.cpp)

```cpp
vector<int> v1;           // default constructor; v1 is empty
vector<int> v2(v1);       // v2 is a copy of v1
vector<int> v3 = v2;      // v3 is a copy of v2
vector<int> v4{0,1,2};    // v4 is a copy of the elements in the initializer list
vector<int> v5 = {0,1,2}; // v5 is a copy of the elements in the initializer list
auto b(v5.begin()), e(v5.end());
vector<int> v6(b,e);      // v6 is a copy of the elements in the range 
                          // denoted by b and e
```

**Exercise 9.12:** Explain the differences between the constructor that takes a container to copy and the constructor that takes two iterators.

**Solution:** The constructor that takes a container to copy copies all of the elements in the container passed into the constructor. The container passed into this constructor must be the same container type and hold the same element type. The constructor that takes two iterators only copies the elements in the iterator range between the two iterators passed in. The container type does not need to be the same for this constructor, and the element type only needs to be compatible not the same.

**Exercise 9.13:** How would you initialize a `vector<double>` from a `list<int>`? From a `vector<int>`? Write code to check your answers.

[**Solution:**](src/ex9_13.cpp) I would use `cbegin` and `cend` on the `list<int>` and pass those iterators as my arguments to use the container constructor that takes in two iterators to initialize the `vector<double>`.

```cpp
int main()
{
    cout << "Enter integers: ";  // prompt user to enter integers
    string line;                 // object to store input
    getline(cin, line);          // read line from standard input
    istringstream iss(line);     // istringstream holding line
    int i;                       // object to hold each integer
    list<int> ilst;              // list to hold the integers
    // read integers from iss into ilst
    while (iss >> i) ilst.push_back(i);
    // print elements of the list
    cout << "Elements of the list:\n";
    for (const auto &j : ilst) cout << j << " ";
    // initialize vector with iterator constructor
    vector<int> ivec(ilst.cbegin(), ilst.cend());
    // print elements of the vector 
    cout << "\n"
         << "Elements of the vector:\n";
    for (const auto &j : ilst) cout << j << " ";
    cout << endl;
    return 0;
}
```

### Section 9.2.5: Assignment and `swap`

**Exercise 9.14:** Write a program to assign the elements from a `list` of `char*` pointers to C-style character strings to a `vector` of `string`s.

[**Solution:**](src/ex9_14.cpp)

```cpp
int main()
{
    // list of char* pointers to C-style strings
    list<const char*> clst{"You", "know,", "I'm", "something", "of", "a",
                           "scientist", "myself."};
    for (auto &c : clst) cout << c << " "; // print elements of list
    cout << endl;
    vector<string> svec;                   // vector of strings
    svec.assign(clst.begin(), clst.end()); // assign elements of list to vector
    for (auto &s : svec) cout << s << " "; // print elements of vector
    cout << endl;
    return 0;
}
```

### Section 9.2.6: Container Size Operations

### Section 9.2.7: Relational Operators

**Exercise 9.15:** Write a program to determine whether two `vector<int>`s are equal.

[**Solution:**](src/ex9_15.cpp)

```cpp
vector<int> build_vector()
{
    string nums;
    getline(cin,nums);
    istringstream iss(nums);
    vector<int> ivec;
    int i;
    while (iss >> i) ivec.push_back(i);
    return ivec;
}

int main()
{
    cout << "Enter integers: ";
    vector<int> ivec1 = build_vector();
    cout << "Enter more integers: ";
    vector<int> ivec2 = build_vector();
    if (ivec1 == ivec2)
        cout << "Each element is equal and both vectors have the same size."
             << endl;
    else
        cout << "The vectors are not equal." << endl;
    return 0;
}
```

**Exercise 9.16:** Repeat the previous program, but compare elements in a `list<int>` to a `vector<int>`.

[**Solution:**](src/ex9_16.cpp)

```cpp
vector<int> build_vector()
{
    string nums;
    getline(cin,nums);
    istringstream iss(nums);
    vector<int> ivec;
    int i;
    while (iss >> i) ivec.push_back(i);
    return ivec;
}

list<int> build_list()
{
    string nums;
    getline(cin,nums);
    istringstream iss(nums);
    list<int> ilst;
    int i;
    while (iss >> i) ilst.push_back(i);
    return ilst;
}

int main()
{
    cout << "Enter integers: ";
    vector<int> iv = build_vector();
    cout << "Enter more integers: ";
    list<int> il = build_list();
    if (iv.size() != il.size()) {
        cout << "The vector and list are not equal." << endl;
        return 0;
    }
    vector<int>::const_iterator ivit = iv.cbegin();
    list<int>::const_iterator ilit = il.cbegin();
    while (ivit != iv.cend() && ilit != il.cend()) {
        if (*ivit != *ilit) {
            cout << "The vector and list are not equal." << endl;
            return 0;
        }
        ++ivit, ++ilit;
    }
    cout << "Each element is equal and the vector and list have the same size."
         << endl;
    return 0;
}
```

**Exercise 9.17:** Assuming `c1` and `c2` are containers, what (if any) constraints does the following usage place on the types of `c1` and `c2`?

```cpp
if (c1 < c2)
```

**Solution:** `c1` and `c2` must be the same type of container and contain the same element type. Also, they `<` operation must be defined for the element type of the containers.

## Section 9.3: Sequential Container Operations

### Section 9.3.1: Adding Elements to a Sequential Container

**Exercise 9.18:** Write a program to read a sequence of `string`s from the standard input into a `deque`. Use iterators to write a loop to print the elements in the `deque`.

**Exercise 9.19:** Rewrite the program from the previous exercise to use a `list`. List the changes you needed to make.

**Exercise 9.20:** Write a program to copy elements from a `list<int>` into two `deque`s. The even-valued elements should go into one `deque` and the odd ones into the other.

**Exercise 9.21:** Explain how the loop from page 345 that used the return from `insert` to add elements to a `list` would work if we inserted into a `vector` instead.

**Exercise 9.22:** Assuming `iv` is a `vector` of `int`s, what is wrong with the following program? How might you correct the problem(s)?

```cpp
vector<int>::iterator iter = iv.begin(),
                             mid = iv.begin() + iv.size()/2;
while (iter != mid)
    if (*iter == some_val)
        iv.insert(iter, 2 * some_val);
```

### Section 9.3.2: Accessing Elements

**Exercise 9.23:** In the first program in this section on page 346, what would the values of `val`, `val2`, `val3`, and `val4` be if `c.size()` is `1`?

**Exercise 9.24:** Write a program that fetches the first element in a `vector` using `at`, the subscript operator, `front`, and `begin`. Test your program on an empty `vector`.

### Section 9.3.3: Erasing Elements

**Exercise 9.25:** In the program on page 349 that erased a range of elements, what happens if `elem1` and `elem2` are equal? What if `elem1` or both `elem1` and `elem2` are the off-the-end iterator?

**Exercise 9.26:** Using the following definition of `ia` copy `ia` into a `vector` and into a `list`. Use the single-iterator form of `erase` to remove the elements with odd values from your `list` and even values from your `vector`.

```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

### Section 9.3.4: Specialized `forward_list` Operations

**Exercise 9.27:** Write a program to find and remove the odd-valued elements in a `forward_list<int>`.

**Exercise 9.28:** Write a function that takes a `forward_list<string>` and two additional `string` arguments. The function should find the first `string` and insert the second immediately following the first. If the first `string` is not found, then insert the second `string` at the end of the list.

### Section 9.3.5: Resizing a Container

**Exercise 9.29:** Given that `vec` holds 25 elements, what does `vec.resize(100)` do? What if we next wrote `vec.resize(10)`?

**Exercise 9.30:** What, if any, restrictions does using the version of `resize` that takes a single argument place on the element type?

### Section 9.3.6: Container Operations May Invalidate Iterators

**Exercise 9.31:** The program on page 354 to remove even-valued elements and duplicate odd ones woll not work on a `list` or `forward_list`. Why? Revise the program so that it works on these types as well.

**Exercise 9.32:** In the program on page 354 would it be legal to write the call to `insert` as follows? If not, why not?

```cpp
iter = v1.insert(iter, *iter++);
```

**Exercise 9.33:** In the final example in this section what would happen if we did not assign the result of `insert` to `begin`? Write a program that omits this assignment to see if you expectation was correct.

**Exercise 9.34:** Assuming `vi` is a container of `int`s that includes even and odd values, predict the behavior of the following loop. After you've analuzed this loop, write a program to test whether your expectations were correct.

```cpp
iter = vi.begin();
while (iter != vi.end())
    if (*iter % 2)
        iter = vi.insert(iter, *iter);
    ++iter;
```

## Section 9.4: How a `vector` Grows

**Exercise 9.35:** Explain the difference between a `vector`'s `capacity` and its `size`.

**Exercise 9.36:** Can a container have a `capacity` less than its `size`?

**Exercise 9.37:** Why don't `list` or `array` have a `capacity` member?

**Exercise 9.38:** Write a program to explore how `vector`s grow in the library you use.

**Exercise 9.39:** Explain what the following program fragment does:

```cpp
vector<string> svec;
svec.reserve(1024);
```

**Exercise 9.40:** If the program in the previous exercise reads 256 words, what is its likely `capacity` after it is `resized`? What if it reads 512? 1,000? 1,048?

## Section 9.5: Additional `string` Operations

### Section 9.5.1: Other Ways to Construct `string`s

**Exercise 9.41:** Write a program that initializes a `string` from a `vector<char>`.

**Exercise 9.42:** Given that you want to read a character at a time into a `string`, and you know that you need to read at least 100 characters, how might you improve the performance of your program?

### Section 9.5.2: Other Ways to Change a `string`

**Exercise 9.43:** Write a function that takes three `string`s, `s`, `oldVal`, and `newVal`. Using iterators, and the `insert` and `erase` functions replace all instances of `oldVal` that appear in `s` by `newVal`. Test your function by using it to replace common abbreviations, such as "tho" by "though" and "thru" by "through".

**Exercise 9.44:** Rewrite the previous function using an index and `replace`.

**Exercise 9.45:** Write a function that takes a `string` representing a name and two other `string`s representing a prefix, such as "Mr." or "Ms." and a suffix, such as "Jr." or "III". Using iterators and the `insert` and `append` functions, generate and return a new `string` with the suffix and prefix added to the given name.

**Exercise 9.46:** Rewrite the previous exercise using a position and length to manage the `string`s. This time use only the `insert` function.

### Section 9.5.3: `string` Search Operations

**Exercise 9.47:** Write a program that finds each numeric character and then each alphabetic character in the `string` `"ab2c3d7R4E6"`. Write two version of the program. The first should use `find_first_of`, and the second `find_first_not_of`.

**Exercise 9.48:** Given the definitions of `name` and `numbers` on page 365, what does `numbers.find(name)` return?

**Exercise 9.49:** A letter has an ascender if, as with `d` or `f`, part of the letter extends above the middle of the line. A letter has a descender if, as with `p` or `g`, part of the letter extends below the line. Write a program that reads a file containing words and reports the longest word that contains neither ascenders or descenders.

### Section 9.5.4: The `compare` Functions

### Section 9.5.5: Numeric Conversions

**Exercise 9.50:** Write a program to process a `vector<string>` whose elements represent integral values. Produce the sum of all the elements in that vector. Change the program so that it sums `string`s that represent floating-point values.

**Exercise 9.51:** Write a class that has three `unsigned` members representing year, month, and day. Write a constructor that takes a `string` representing a date. Your constructor should handle a variety of date formats, such as January 1, 1990. 1/1/1990, Jan 1, 1990, and so on.

## Section 9.6: Container Adaptors

**Exercise 9.52:** Use a `stack` to process parenthesized expressions. When you see an open parenthesis, note that it was seen. When you see a close parenthesis after an open parenthesis, `pop` elements down to and including the open parenthesis off the `stack`. `push` a value onto the `stack` to indicate that a parenthesized expression was replaced.
