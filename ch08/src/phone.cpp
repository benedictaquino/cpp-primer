#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using std::cin; using std::cout; using std::cerr; using std::endl;
using std::istringstream; using std::ostringstream;
using std::vector;
using std::string;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &s)
{
    if (s.size() != 10) return 0;
    for (auto c : s) if (!isdigit(c)) return 0;
    return 1;
}

string format(const string &s)
{
    string formatted_str("(");
    for (int i = 0; i != 3; ++i) formatted_str += s[i];
    formatted_str += ") ";
    for (int i = 3; i != 6; ++i) formatted_str += s[i];
    formatted_str += "-";
    for (int i = 6; i != 10; ++i) formatted_str += s[i];
    return formatted_str;
}

int main()
{
    string line, word;  // will hold a line and word from input, respectively
    vector<PersonInfo> people;  // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file (or another error)
    while (getline(cin, line)) {
        PersonInfo info;      // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        record >> info.name;  // read the name
        while (record >> word)       // read the phone numbers
            info.phones.push_back(word);  // and store them
        people.push_back(info); // append this record to people
    }
    for (const auto &entry : people) {    // for each entry in people
        ostringstream formatted, badNums; // objects created on each loop 
        for (const auto &nums : entry.phones) {  // for each number
            if (!valid(nums)) {
                badNums << " " << nums;  // string in badNums
            } else // "writes" to formatted's string
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())     // there were no bad numbers
            cout << entry.name << " "  // print the name 
                 << formatted.str() << endl; // and reformatted numbers
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s) " << badNums.str() << endl;
    }
    return 0;
}
