#include <iostream>

using std::cin; using std::cout; using std::endl;

int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
// returns a reference to an array of five int elements
decltype((odd)) arrRef(int i)
{
    return (i % 2) ? odd : even;
}

int main()
{
    cout << "Enter an integer:" << endl;
    int val; cin >> val;
    int (&ref)[5] = arrRef(val);
    for (int i = 0; i != 5; ++i) cout << ref[i] << " ";
    cout << endl;
    return 0;
}
