#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

bool has_capital(const string &s)
{
    bool capital = 0;
    for (auto c : s) 
        if (isupper(c)) {
            capital = 1;
            break;
        }
    return capital;
}

void to_lower(string &s)
{
    for (auto &c : s) if (isupper(c)) c = tolower(c);
}

int main()
{
    /* prompt user for a string */
    cout << "Enter a string:" << endl;
    string s; getline(cin, s);
    if (has_capital(s)) to_lower(s);
    cout << s << endl;
    return 0;
}
