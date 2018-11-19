#include <iostream>
#include <string>
#include "../include/Book.h"

using std::istream; using std::ostream;
using std::string;

istream &read(istream &is, Book &book)
{
    getline(is, book.title);
    getline(is, book.author);
    return is;
}

ostream &print(ostream &os, Book &book)
{
    os << "Title: " <<  book.title << "\n"
       << "Author: " << book.author << "\n";
    return os;
}
