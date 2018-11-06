#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int *ip1, int *ip2)
{
    int temp = *ip1;
    *ip1 = *ip2;
    *ip2 = temp;
    return;
}

int main()
{
    // prompt user to input two integers
    cout << "Enter two integers:" << endl;
    int i1, i2;
    cin >> i1 >> i2;

    swap(&i1, &i2);

    cout << i1 << " " << i2 << endl;

    return 0;
}
