/* This program reads the standard input one word at a time */
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl;
using std::string;
int main()
{
    string word;               // initialize empty string
    while (cin >> word)        // read word from standard input 
        cout << word << endl;  // write word to standard output
    return 0;
}
