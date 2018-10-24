/* This program uses escape sequences to print 2M followed by a newline */
#include <iostream>
int main()
{
    std::cout << "\062\115\012" << std::endl;
    return 0;
}
