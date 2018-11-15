#include <iostream>
#include "../include/Person.h"

using std::istream; using std::ostream; 

Person::Person(istream &is)
{
    read(is, *this);
}

istream &read(istream &is, Person &dude)
{
    getline(is, dude.name);
    getline(is, dude.address);
    return is;
}

ostream &print(ostream &os, const Person &dude)
{
    os << dude.who() << " lives at " << dude.where(); 
    return os;
}
