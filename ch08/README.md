# Chapter 8: The IO Library

## Section 8.1: The IO Classes

### Section 8.1.1: No Copy or Assign for IO Objects

### Section 8.1.2: Condition States

**Exercise 8.1:** Write a function that takes and returns an `istream&`. The function should read the stream until it hits end-of-file. The function should print what it reads to the standard output. Reset the stream so that it is valid before returning the stream.

[**Solution:**](src/ex8_1.cpp)

```cpp
istream &read_stream(istream &is)
{
    string s;
    is.clear();   // make istream valid
    // while istream is valid, print to standard output
    while (is >> s) cout << s << " ";
    cout << endl; // newline and flush
    is.clear();   // reset istream
    return is;
}
```

**Exercise 8.2:** Test your function by calling it, passing `cin` as an argument.

[**Solution:**](src/ex8_2.cpp)

```cpp
int main()
{
    read_stream(cin);
    return 0;
}
```

[**Input:**](data/test/txt)

```
Who am I? You sure you want to know? The story of my life is not for the faint
of heart. If somebody told you it was a happy little tale, if somebody told
you I was just your average ordinary guy, not a care in the world... somebody
lied. But let me assure you, this, like any story worth telling, is all about
a girl. That girl, The girl next door. Mary Jane Watson. The woman I loved
since before I even liked girls. I'd like to tell you that's me next to her.
Aw, heck, I'd even take him. That's me...
```

**Output:**

```
Who am I? You sure you want to know? The story of my life is not for the faint of heart. If somebody told you it was a happy little tale, if somebody told you I was just your average ordinary guy, not a care in the world... somebody lied. But let me assure you, this, like any story worth telling, is all about a girl. That girl, The girl next door. Mary Jane Watson. The woman I loved since before I even liked girls. I'd like to tell you that's me next to her. Aw, heck, I'd even take him. That's me...
```

**Exercise 8.3:** What causes the following `while` to terminate?

```cpp
while (cin >> i) /* ... */
```

**Solution:** If the state of `cin` returned from the `>>` expression is invalid, then the `while` loop terminates. The three condition states that will be considered invalid are `badbit`, `failbit`, or `eofbit`.

### Section 8.1.3: Managing the Output Buffer

## Section 8.2: File Input and Output

### Section 8.2.1: Using File Stream Objects

**Exercise 8.4:** Write a function to open a file for input and read its contents into a `vector` of `string`s, storing each line as a separate element in the `vector`.

[**Solution:**](src/ex8_4.cpp)

```cpp
vector<string> read_file(const string &filename)
{
    string str;
    vector<string> str_vec;
    ifstream infile(filename);
    while(getline(infile, str)) str_vec.push_back(str);
    return str_vec;
}
```

**Exercise 8.5:** Rewrite the previous program to store each word in a separate element.

[**Solution:**](src/ex8_5.cpp)

```cpp
vector<string> read_file(const string &filename)
{
    string str;
    vector<string> str_vec;
    ifstream infile(filename);
    while(infile >> str) str_vec.push_back(str);
    return str_vec;
}
```

**Exercise 8.6:** Rewrite the [bookstore program](../ch07/src/ex7_1.cpp) from [7.1.1](../ch07#section-71-defining-abstract-data-types) to read its transactions from a file. Pass the name of the file as an argument to `main`.

[**Solution:**](src/ex8_6.cpp)

```cpp
int main(int argc, char *argv[])
{
    if (!argv[1]) { // check if a filename was passed in
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    ifstream infile(argv[1]);
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (read(infile, total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(infile, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn()) {
                // update the running total
                total.combine(trans);
            } else { // print the results for the previous books
                print(cout, total);
                total = trans; // total now refers to the next book
            }
        }
        // print the last transaction
        print(cout, total);
    } else { // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
```

### Section 8.2.2: File Modes

**Exercise 8.7:** Revise the bookstore program from the previous section to write its output to a file. Pass the name of that file as a second argument to `main`.

[**Solution:**](src/ex8_7.cpp)

```cpp
int main(int argc, char *argv[])
{
    if (!argv[1] || !argv[2]) { // check if two filenames were passed in
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    ifstream infile(argv[1]);
    ofstream outfile(argv[2]);
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (read(infile, total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(infile, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn()) {
                // update the running total
                total.combine(trans);
            } else { // write the results for the previous books
                print(outfile, total);
                total = trans; // total now refers to the next book
            }
        }
        // write the last transaction
        print(outfile, total);
    } else { // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
```

[**Input:**](data/items.txt)

```
0-201-78345-X 3 20.75
0-201-78345-X 2 25.50
0-201-78345-X 1 15.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-16209-X 4 55.00
0-201-16209-X 6 95.00
0-201-16209-X 1 35.00
0-201-16209-X 2 45.00
```

```bash
g++ src/sales_data.cpp src/ex8_7.cpp -o bin/ex8_7
bin/ex8_7 data/items.txt data/ex8_7.txt
```

[**Output:**](data/ex8_7.txt)

```
0-201-78345-X 6 128.25 21.375
0-201-87649-X 14 350 25
0-201-30957-X 12 300 25
0-201-16209-X 13 915 70.3846
```

**Exercise 8.8:** Revise the program from the previous exercise to append its output to its given file. Run the program on the same output file at least twice to ensure the data are preserved.

[**Solution:**](src/ex8_8.cpp)

```cpp
int main(int argc, char *argv[])
{
    if (!argv[1] || !argv[2]) { // check if two filenames were passed in
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    ifstream infile(argv[1]);
    ofstream outfile(argv[2], ofstream::app);
    Sales_data total; // variable to hold data for the next transaction
    // read the first transaction and ensure there are data to process
    if (read(infile, total)) {
        Sales_data trans; // variable to hold the running sum
        // read and process the remaining transactions
        while (read(infile, trans)) {
            // if we're still processing the same book
            if (total.isbn() == trans.isbn()) {
                // update the running total
                total.combine(trans);
            } else { // write the results for the previous books
                print(outfile, total);
                total = trans; // total now refers to the next book
            }
        }
        // write the last transaction
        print(outfile, total);
    } else { // no input! warn the user
        cerr << "No Data?!" << endl;
        return -1; // indicate failure
    }
    return 0;
}
```

[**Input:**](data/items.txt)

```
0-201-78345-X 3 20.75
0-201-78345-X 2 25.50
0-201-78345-X 1 15.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-87649-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-30957-X 2 25.00
0-201-16209-X 4 55.00
0-201-16209-X 6 95.00
0-201-16209-X 1 35.00
0-201-16209-X 2 45.00
```

```bash
g++ src/sales_data.cpp src/ex8_8.cpp -o bin/ex8_8
bin/ex8_8 data/items.txt data/ex8_8.txt
bin/ex8_8 data/items.txt data/ex8_8.txt
```

[**Output:**](data/ex8_8.txt)

```
0-201-78345-X 6 128.25 21.375
0-201-87649-X 14 350 25
0-201-30957-X 12 300 25
0-201-16209-X 13 915 70.3846
0-201-78345-X 6 128.25 21.375
0-201-87649-X 14 350 25
0-201-30957-X 12 300 25
0-201-16209-X 13 915 70.3846
```

## Section 8.3: `string` Streams

### Section 8.3.1: Using an `istringstream`

**Exercise 8.9:** Use the function you wrote for the [first exercise](src/ex8_1.cpp) in [8.1.2](#section-812-condition-states) to print your contents of an `istringstream` object.

[**Solution:**](src/ex8_9.cpp)

```cpp
int main()
{
    string str;
    getline(cin, str);
    istringstream instring(str);
    read_stream(instring);
    return 0;
}
```

**Exercise 8.10:** Write a program to store each line from a file in a `vector<string>`. Now use an `istringstream` to read each element from the `vector` a word at a time.

[**Solution:**](src/ex8_10.cpp)

```cpp
int main(int argc, char *argv[])
{
    if (!argv[1]) {
        cerr << "Not enough arguments supplied." << flush;
        return -1;
    }
    ifstream infile(argv[1]); // input file
    string line;
    vector<string> str_vec; // object to hold each line from file 
    // append each line to str_vec
    while (getline(infile, line)) str_vec.push_back(line);
    istringstream instring; // istringstream object to bind to line
    for (auto &s : str_vec) {  // for each line
        instring.clear(); // reset instring
        instring.str(s); // copy line to instring
        string word;
        // read each word and print to standard output
        while (instring >> word) cout << word << " ";
        cout << "\n";
    }
    cout << flush;
    return 0;
}
```

**Exercise 8.11:** The [program](src/person_info.cpp) in this section defined its `istringstream` object inside the outer `while` loop. What changes would you need to make if `record` were defined outside that loop? Rewrite the program, moving the definition of `record` outside the `while`, and see whether you thought all of the changes that are needed.

[**Solution:**](src/ex8_11.cpp) If `record` were defined outside the outer `while` loop, then I would need to use `record.clear()` to reset the condition of `record` and `record.str(line)` inside the `while` loop. If I did not reset the condition of `record`, then the inner `while` loop would evaluate as invalid and the phone numbers would not be stored to `info`. 

```cpp
int main()
{
    string line, word;  // will hold a line and word from input, respectively
    vector<PersonInfo> people;  // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file (or another error)
    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;      // create an object to hold this record's data
        record.clear();  // reset record
        record.str(line); // bind record to the line we just read
        record >> info.name;  // read the name
        while (record >> word)       // read the phone numbers
            info.phones.push_back(word);  // and store them
        people.push_back(info); // append this record to people
    }
    for (auto &person : people) {
        cout << person.name << "\n";
        for (auto &phone : person.phones) cout << "  " << phone << "\n";
    }
    cout << flush;
    return 0;
}
```

**Exercise 8.12:** Why didn't we use in-class initializers in `PersonInfo`?

**Solution:** We did not use in-class initializers in `PersonInfo` because the members are of type `string` and `vector` of `strings`, which work with the synthesized default initializer since they have default constructors.

### Section 8.3.2: Using `ostringstream`s

**Exercise 8.13:** Rewrite the [phone number program](src/phone.cpp) from this section to read from a named file rather than a `cin`.

[**Solution:**](src/ex8_13.cpp)

```cpp
int main(int argc, char *argv[])
{
    if (!argv[1]) {
        cerr << "No input file supplied." << endl;
        return -1;
    }
    ifstream infile(argv[1]); // input file
    string line, word;  // will hold a line and word from input, respectively
    vector<PersonInfo> people;  // will hold all the records from the input
    // read the input file a line at a time until it hits end-of-file (or another error)
    while (getline(infile, line)) {
        PersonInfo info;      // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        record >> info.name;  // read the name
        while (record >> word)       // read the phone numbers
            info.phones.push_back(word);  // and store them
        people.push_back(info); // append this record to people
    }
    for (const auto &entry : people) {    // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop 
        for (const auto &nums : entry.phones) {  // for each number
            if (!valid(nums)) {
                badNums << " " << nums;  // string in badNums
            } else // "writes" to formatted's string
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())     // there were no bad numbers
            cout << entry.name << " "  // print the name 
                 << formatted.str() << endl; // and reformatted numbers
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}
```

**Exercise 8.14:** Why did we declare `entry` and `nums` as `const auto &`?

**Solution:** We declare `entry` and `nums` as `const auto&` because we do not want to manipulate the original values in `people`.
