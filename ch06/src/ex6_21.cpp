#include <iostream>

using std::cin; using std::cout; using std::endl;

int larger(int ival, const int *ip)
{
   return (ival > *ip) ? ival : *ip;
}

int main()
{
    /* prompt user for two integers */
    cout << "Enter two integers:" << endl;
    int i1, i2; 
    cin >> i1 >> i2;;
    cout << larger(i1, &i2) << " is the larger number." << endl;
    return 0;
}
