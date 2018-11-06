#include <iostream>

using std::cin; using std::cout; using std::endl;

int sequence()
{
    static int i = 0;
    return i++;
}

int main()
{
    cout << "How many times would you like to call the function?" << endl;
    unsigned cnt;
    cin >> cnt;
    for (int j = 0; j != cnt; ++j) cout << sequence() << endl;
    return 0;
}
