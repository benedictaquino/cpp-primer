/* Exercise 9.6
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program tests my solution to exercise 9.6. */
#include <iostream>
#include <list>

using std::cin; using std::cout; using std::endl;
using std::list;

int main()
{
    list<int> lst1(10);
    list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();
    int i = 0;
    while (iter1 != iter2) cout << "Loop " << (++iter1, ++i) << "\n";
    cout << std::flush;
    return 0;
}
