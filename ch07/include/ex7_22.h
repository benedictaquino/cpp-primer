#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
// friend declarations
friend std::istream &read(std::istream&, Person&);
friend std::ostream &print(std::ostream&, Person&);
public:
    // constructors
    Person() = default;
    Person(const std::string &s): name(s) { }
    Person(const std::string &s1, const std::string &s2): name(s1), address(s2) { }
    Person(std::istream&);
    // member functions
    std::string who() const { return name; }
    std::string where() const { return address; }
private:
    // member objects
    std::string name;
    std::string address;
};

// nonmember declarations
std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);

#endif
