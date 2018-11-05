#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string; using std::getline;

int main()
{
    do {
        string s1, s2;
        cout << "Enter the first string:" << endl;
        getline(cin, s1);
        cout << "Enter the second string:" << endl;
        getline(cin, s2);
        if (s1.size() > s2.size())
            cout << "The first string is longer than the second string." << endl;
        else if (s1.size() < s2.size())
            cout << "The first string is shorter than the second string." << endl;
        else if (s1.size() == s2.size())
            cout << "The strings are the same length." << endl;
    } while (cin);
    
    return 0;
}
