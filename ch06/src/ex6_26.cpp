#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;

int main(int argc, char *argv[])
{
    string str;
    int i = 0;
    while (argv[i]) {
        str = argv[i++];
        cout << str << " ";
    }
    cout << endl;
    return 0;
}
