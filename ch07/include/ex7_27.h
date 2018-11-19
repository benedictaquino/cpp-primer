#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
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
    char get(pos, pos) const; 
    Screen &move(pos, pos);
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display is overloaded on whether the object is const or not
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
    // private member objects
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
    // private member functions
    void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) // define as inline outside of class body
{
    ++access_ctr;
    pos row = r * width;  // compute the row location
    cursor = row * c;     // move cursor to the column within that row
    return *this;         // return this object as an lvalue
}

inline char Screen::get(pos r, pos c) const 
{
    ++access_ctr;
    pos row = r * width;      // compute the row location
    return contents[row + c];  // return character at the given column
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;  // set the new value at the current cursor location
    return *this;          // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    contents[r * width + c] = ch;  // set specified location to given value
    return *this;                  // return this object as an lvalue
}

#endif
