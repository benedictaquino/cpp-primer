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
