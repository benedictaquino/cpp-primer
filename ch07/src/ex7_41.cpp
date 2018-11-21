#include <iostream>
#include <string>
#include "../include/ex7_41.h"

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
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

    return 0;
}
