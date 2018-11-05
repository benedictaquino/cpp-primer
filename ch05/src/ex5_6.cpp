/* This program generates a letter grade from an numeric grade */
#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

int main()
{
    vector<int> grades;
    int grade;
    while (cin >> grade) grades.push_back(grade);

    const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    vector<string> lettergrades;
    string lettergrade;

    for (auto grade : grades) {
        lettergrade = (grade < 60) ? scores[0] : scores[(grade - 50)/10]; 
        (grade >= 60 && grade != 100)? 
            (grade % 10 > 7) ? lettergrade += '+'
            : (grade % 10 < 3) ? lettergrade += '-'
            : lettergrade
            : lettergrade;
        lettergrades.push_back(lettergrade);
    }

    const size_t sz = grades.size();
    cout << "Score\tLetter\n-----\t------" << endl;
    for (size_t i = 0; i != sz; ++i) 
        cout << grades[i] << "\t" << lettergrades[i] << endl;

    return 0;
}
