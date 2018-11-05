// This program reads two integers from the standard input and prints the
// results of dividing the first number by the second
#include <iostream>
#include <stdexcept>

using std::cin; using std::cout; using std::endl;
using std::runtime_error;

int main()
{
    int i1, i2;    // define two integers
    cout << "Please enter two integers:" << endl;
    while (cin >> i1 >> i2) {
        try {
            if (!i2) throw runtime_error("Division by zero.");
            cout << i1 / i2 << endl;
            return 0;
        } catch (runtime_error err) {
            cout << err.what() << "\nTry again? (y/n)" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n' || c == 'N')
                break;
        }
    }
    return 0;
}
