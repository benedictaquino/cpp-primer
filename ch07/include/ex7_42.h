#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Employee {
friend std::istream &read(std::istream&, Employee&);
friend std::ostream &print(std::ostream&, Employee&);
public:
    // nondelegating constructor
    Employee(std::string s1, std::string s2, unsigned n):
        name(s1), title(s2), salary(n) { }
    // delegating constructors
    Employee(): Employee("", "", 0) { }
    Employee(const std::string &s): Employee(s, "", 0) { }
    Employee(unsigned n): Employee("", "", n) { }
    Employee(const std::string &s1, const std::string &s2): Employee(s1, s2, 0) { }
    Employee(const std::string &s, unsigned n): Employee(s, "", n) { }
    Employee(std::istream &is): Employee() { read(is, *this); }
private:
    std::string name = "";
    std::string title = ""; 
    unsigned salary = 0;
};

// nonmember function declarations
std::istream &read(std::istream&, Employee&);
std::ostream &print(std::ostream&, Employee&);

#endif
