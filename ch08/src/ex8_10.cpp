/* Exercise 8.10
 * Author: Benedict Aquino
 * Date 2018-11-28
 * Description: This program stores each line from a file in a vector<string>
 * Then uses an istringstream to read each element from the vector a word at
 * a time. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::cout; using std::cerr; using std::flush;
using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;

int main(int argc, char *argv[])
{
    if (!argv[1]) {
        cerr << "Not enough arguments supplied." << flush;
        return -1;
    }
    ifstream infile(argv[1]); // input file
    string line;
    vector<string> str_vec; // object to hold each line from file 
    // append each line to str_vec
    while (getline(infile, line)) str_vec.push_back(line);
    istringstream instring; // istringstream object to bind to line
    for (auto &s : str_vec) {  // for each line
        instring.clear(); // reset instring
        instring.str(s); // copy line to instring
        string word;
        // read each word and print to standard output
        while (instring >> word) cout << word << " ";
        cout << "\n";
    }
    cout << flush;
    return 0;
}
