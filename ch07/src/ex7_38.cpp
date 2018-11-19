#include <iostream>
#include <string>

class Sales_data {
public:
    // defines the default constructor as well as one that takes a string agument
    Sales_data(std::string = " "): bookNo(s) { }
    // remaining constructors unchanged
    Sales_data(std::string s, unsigned cnt, double rev):
        bookNo(s), units_sold(cnt), revenue(rev * cnt) { }
    Sales_data(std::istream &is) { read(is, *this) }
