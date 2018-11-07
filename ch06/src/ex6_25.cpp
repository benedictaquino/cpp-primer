#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl; using std::cerr;
using std::string;

int main(int argc, char *argv[])
{
    if (!argv[1] || !argv[2]) {
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    string str1 = argv[1], str2 = argv[2], str = str1 + ' ' + str2;
    cout << str << endl;
    return 0;
}
