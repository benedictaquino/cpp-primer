/* This program assigns high pass, pass, low pass, and fail to grades */
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> scores; int score;
    while (cin >> score) scores.push_back(score);

    vector<string> finalgrades; string finalgrade;
    for (int grade : scores) {
        finalgrade = (grade > 90) ? "high pass"
                   : (grade > 75) ? "pass"
                   : (grade >= 60) ? "low pass"
                   : "fail";
        finalgrades.push_back(finalgrade);
    }

    cout << "Scores\tFinal Grades\n" 
         << "------\t------------" << endl;
    for (int i = 0; i != scores.size(); ++i)
        cout << scores[i] << "\t" << finalgrades[i] << endl;

    return 0;
}
