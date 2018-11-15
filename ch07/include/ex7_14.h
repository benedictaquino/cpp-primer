#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

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

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);

#endif
