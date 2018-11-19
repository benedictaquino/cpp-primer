#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data {
// friend declarations for nonmember operations
friend Sales_data add(const Sales_data&, const Sales_data&);
friend std::istream &read(std::istream&, Sales_data&);
friend std::ostream &print(std::ostream&, const Sales_data&);
public:
    // constructors
    // defines the defualt constructor as well as one that takes a string argument
    Sales_data(std::string s = ""): bookNo(s) { }
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

#endif
