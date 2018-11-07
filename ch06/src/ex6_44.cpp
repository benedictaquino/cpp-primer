#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

// compare the length of two strings
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main()
{
    // prompt the user for two strings
    cout << "Enter the first string:" << endl;
    string str1; getline(cin, str1);
    cout << "Enter the second string:" << endl;
    string str2; getline(cin, str2);

    cout << "isShorter(\"" << str1 << "\", \"" << str2 << "\") = " 
         << isShorter(str1, str2) << endl;

    return 0;
}
