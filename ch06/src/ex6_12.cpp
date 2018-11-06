#include <iostream>

using std::cin; using std::cout; using std::endl;

void swap(int &r1, int &r2)
{
    int temp = r1;
    r1 = r2; r2 = temp;
}

int main()
{
    /* prompt user to input two integers */
    cout << "Enter two integers:" << endl;
    int i1, i2;
    cin >> i1 >> i2;

    swap(i1, i2);

    cout << i1 << " " << i2 << endl;

    return 0;
}
