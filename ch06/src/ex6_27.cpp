#include <iostream>
#include <initializer_list>

using std::cout; using std::endl;
using std::initializer_list;

int int_sum(initializer_list<int> int_lst)
{
    int sum = 0;
    for (auto &int_ref : int_lst) sum += int_ref;
    return sum;
}

int main()
{
    int sum = int_sum({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    cout << "The sum of the integers 1 through 10 inclusive is " << sum << endl;
    return 0;
}
