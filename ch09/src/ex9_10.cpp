/* Exercise 9.10
 * Author: Benedict Aquino
 * Date: 2018-11-29
 * Description: This program tests my solution to exercise 9.10. */
#include <vector>

using std::vector;

int main()
{
    vector<int> v1;
    const vector<int> v2;
    auto it1 = v1.begin(); 
    auto it2 = v2.begin();
    auto it3 = v1.cbegin(), it4 = v2.cbegin();

    return 0;
}
