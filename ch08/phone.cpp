#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using std::cin; using std::cout; using std::flush;
using std::istringstream;
using std::vector;
using std::string;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;  // will hold a line and word from input, respectively
    vector<PersonInfo> people;  // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-file (or another error)
    istringstream record;
    while (getline(cin, line)) {
        PersonInfo info;      // create an object to hold this record's data
        record.clear();  // reset record
        record.str(line); // bind record to the line we just read
        record >> info.name;  // read the name
        while (record >> word)       // read the phone numbers
            info.phones.push_back(word);  // and store them
        people.push_back(info); // append this record to people
    }
    for (auto &person : people) {
        cout << person.name << "\n";
        for (auto &phone : person.phones) cout << "  " << phone << "\n";
    }
    cout << flush;
    return 0;
}
