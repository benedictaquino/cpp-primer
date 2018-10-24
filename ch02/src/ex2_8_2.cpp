/* This program uses escape sequences to print 2, then a tab, then an M, 
 * followed by a newline */
#include <iostream>
int main()
{
    std::cout << "\062\011\115\012" << std::endl;
    return 0;
}
