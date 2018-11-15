#include <iostream>
#include <string>
#include "../include/Sales_data.h"

using std::cin; using std::cout; using std::endl;
using std::istream; using std::ostream;

// istream constructor moved into Sales_data body
// Sales_data::Sales_data(std::istream &is)
// {
//     read(is, *this);
// }

Sales_data& Sales_data::combine(const Sales_data &rhs) 
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

// changed to private member function
// double Sales_data::avg_price() const 
// {
//     if (units_sold) return revenue/units_sold;
//     else return 0;
// }
 
Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item) 
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
