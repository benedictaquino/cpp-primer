/* Exercise 8.5
 * Author: Benedict Aquino
 * Date: 2018-11-27
 * Description: This program opens a file for input, reads its contents into a
 * vector of strings, storing each word as a separate element in the vector. */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout; using std::endl; using std::flush; using std::cerr;
using std::vector;
using std::string;
using std::ifstream;

vector<string> read_file(const string &filename)
{
    string str;
    vector<string> str_vec;
    ifstream infile(filename);
    while(infile >> str) str_vec.push_back(str);
    return str_vec;
}

int main(int argc, char *argv[])
{
    if (!argv[1]) {
        cerr << "Not enough arguments supplied." << endl;
        return -1;
    }
    for (auto &r : read_file(argv[1])) cout << r << " ";
    cout << endl;
    return 0;
}
