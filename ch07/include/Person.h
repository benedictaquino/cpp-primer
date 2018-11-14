#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
    std::string who() const { return name; }
    std::string where() const { return address; }
    std::string name;
    std::string address;
};

#endif
