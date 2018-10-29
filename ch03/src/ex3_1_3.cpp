/* This program prompts the user for two integers then prints each number in
 * the range specified by those two integers */
#include <iostream>
using std::cin; using std::cout; using std::endl;
int main()
{
    cout << "Enter two integers: " << endl;
    int v1 = 0, v2 = 0;
    cin >> v1 >> v2;
    while (v1 <= v2) {
        cout << v1 << " ";
        v1++;
    }
    cout << endl;
    return 0;
}
