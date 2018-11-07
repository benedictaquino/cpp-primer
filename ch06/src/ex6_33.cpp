#include <iostream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::vector;
using std::string;

void print(vector<string> &str_vec, vector<string>::iterator iter)
{
    if (iter != str_vec.end()) {
        cout << *iter << " ";
        print(str_vec, ++iter);
    } else cout << endl;
}

int main()
{
    vector<string> str_vec = {"Hello", "there,", "General", "Kenobi."};
    print(str_vec, str_vec.begin());
    return 0;
}
