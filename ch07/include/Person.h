#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
    std::string who() const { return name; }
    std::string where() const { return address; }
    std::string name;
    std::string address;
};

std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, const Person&);

#endif
