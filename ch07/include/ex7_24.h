#ifndef SCREEN_H
#define SCREEN_H

#include <string>

class Screen {
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    char get() const { return contents[cursor]; } // get character at the cursor
    char get(pos ht, pos wd) const; // explicitly inline
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
};

inline Screen &Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const // declared inline inside class body
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}

#endif
