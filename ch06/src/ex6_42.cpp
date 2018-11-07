#include <iostream>
#include <string>

using std::cout; using std::endl;
using std::string;

// return the plural version of word if ctr is greater than 1
string make_plural(size_t ctr, const string &word, const string &ending = "s")
{
    return (ctr > 1) ? word + ending : word;
}

int main()
{
    string success = "success", failure = "failure";
    cout << make_plural(success.size(), success, "es") << "\n"
         << make_plural(failure.size(), failure) << endl;
    return 0;
}
