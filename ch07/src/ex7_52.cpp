#include <iostream>
#include <string>
#include "../include/ex7_52.h"

using std::cout; using std::endl;
using std::string;

int main()
{
    Sales_data item = {"978-059035403", 25, 15.99 * 25};
    cout << item.bookNo << " " << item.units_sold << " " << item.revenue << "\n";
    return 0;
}
