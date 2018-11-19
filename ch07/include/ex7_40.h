#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book;
std::istream &read(std::istream&, Book&);

class Book {
friend std::istream &read(std::istream&, Book&);
friend std::ostream &print(std::ostream&, Book&);
public:
    // constructors
    Book(std::string s1 = "", std::string s2 = "Anonymous"): title(s1), author(s2) { }
    Book(std::string &s1, std::string &s2, unsigned i): 
        title(s1), author(s2) { }
    Book(std::istream &is) { read(is, *this); }
    // member functions
private:
    // private members
    std::string title, author = "Anonymous";
};

std::ostream &print(std::ostream&, Book&);

#endif
