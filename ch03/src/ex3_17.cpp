/* This program reads a sequence of words from cin and stores the value in a
 * a vector. After the words are read, it processes the vector to change each
 * word to uppercase. Then it prints the transformed elements. */
#include <iostream>
#include <string>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
int main()
{
    vector<string> sv;    // initialize empty string vector
    string s;             // initialize empty string
    while (cin >> s)      // read in strings from standard input
        sv.push_back(s);  // append s to sv
    int i = 0;            // initialize counter
    for (string &c : sv) {  // iterate through the elements of sv
        if (i < 8) {  // print character and space if i is less than 8 
            cout << c << " ";
            i++;  // increment i by 1
        } else {  // otherwise, print character and newline
            cout << c << "\n";
            i = 0;  // reset counter
        }
    }
    cout << endl;
    return 0;
}
        
