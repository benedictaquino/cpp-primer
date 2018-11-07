#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int* &ip1, int* &ip2)
{
    int *temp = ip1;
    ip1 = ip2;
    ip2 = temp;
}

int main()
{
    /* prompt user for two integers */
    cout << "Enter two integers:" << endl;
    int i1, i2;
    cin >> i1 >> i2;
    int *p1 = &i1, *p2 = &i2;
    swap(p1, p2);
    cout << *p1 << " " << *p2 << endl;
    return 0;
}
