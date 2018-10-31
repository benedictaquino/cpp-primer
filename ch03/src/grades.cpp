/* This program reads in a collection of grades that range from 0 to 100 then
 * counts how many grades fall into various clusters of 10. Between 0 and 100
 * there are 101 possible grades. These grades can be represented by 11
 * clusters: 10 clusters of 10 grades each plus one cluster for a perfect
 * score of 100. */
#include <iostream>
#include <vector>

using std::cin; using std::cout; using std::endl;
using std::vector;

int main()
{
    vector<unsigned> scores(11, 0);  // 11 buckets, all initially 0
    unsigned grade;
    while (cin >> grade) {       // read the grades
        if (grade <= 100)        // handle only valid grades
            ++scores[grade/10];  // increment the counter for the current cluster
    }
    for (auto &rgrade : scores)
        cout << rgrade << " ";
    cout << endl;
    return 0;
}
