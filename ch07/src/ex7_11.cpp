#include <iostream>
#include "../include/Sales_data.h"

using std::cin; using std::cout; using std::endl;

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
