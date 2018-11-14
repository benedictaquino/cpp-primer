#include <iostream>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data total;  // object to hold the data for the next transaction
    // read the first transaction and ensure there are data to process
    if (std::cin >> total.bookNo >> total.units_sold >> total.revenue) {
        total.revenue *= total.units_sold;
        Sales_data trans;  // object to hold the running sum
        // read and process the remaining transactions
        while (std::cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
            trans.revenue *= trans.units_sold;
            // if we're still processing the same book
            if (total.bookNo == trans.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                // print results for previous book
                std::cout << total.bookNo << " "
                          << total.units_sold << " "
                          << total.revenue << " "
                          << total.revenue / total.units_sold << "\n";
                total = trans;  // total now refers to the next book
            }
        }
        std::cout << total.bookNo << " "
                  << total.units_sold << " "
                  << total.revenue << " "
                  << total.revenue / total.units_sold 
                  << std::endl;
    } else { // no input! warn the user
        std::cerr << "No Data?!" <<std::endl;
        return -1;  // indicate failure
    }
    return 0;
}
