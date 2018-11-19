#include <iostream>
#include <string>
#include "include/Book.h"

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
    cout << "Default constructor:\n";
    Book book_default;
    print(cout, book_default);

    cout << "Title constructor:\n";
    Book book_title("Beowulf");
    print(cout, book_title);

    cout << "Title and Author constructor:\n";
    Book book_title_author("Harry Potter and the Goblet of Fire", "J. K. Rowling");
    print(cout, book_title_author);

    cout << "istream constructor:\n";
    Book book_is(cin);
    print(cout, book_is);

    return 0;
}
