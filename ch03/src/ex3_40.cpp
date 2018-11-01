/* This program defines two character arrays initialized from string literals
 * Then it defines a third character array to hold the concatenation of the two
 * arrays */
#include <iostream>
#include <string>
#include <cstring>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::strlen; using std::strcpy; using std::strcat;

int main()
{
    // initialize character arrays with string literals
    char ca1[] = "First string literal.";
    char ca2[] = "Second string literal.";

    cout << "First string: \"" << ca1 << "\"\n" 
         << "Second string: \"" << ca2 << "\"" << endl;

    char ca3[strlen(ca1) + strlen(ca2)]; 
    strcpy(ca3, ca1);
    strcat(ca3, " ");
    strcat(ca3, ca2);

    cout << "Third string: \"" << ca3 << "\"" << endl;

    return 0;
}
