#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>
#include <vector>

class Screen;

class Window_mgr {
public:
    // constructors
    Window_mgr();  // declare outside of class body
    // location ID for each screen on the window
    typedef std::vector<Screen>::size_type ScreenIndex;
    // reset the Screen at the given position to all blanks
    void clear(ScreenIndex);
    // add Screen to Window_mgr
    Window_mgr &add(Screen&);
    // display Screen at given position
    Window_mgr &display(std::ostream&, ScreenIndex);
    const Window_mgr &display(std::ostream&, ScreenIndex) const;
private:
    std::vector<Screen> screens;
};

class Screen {
friend void Window_mgr::clear(ScreenIndex);
friend Window_mgr &Window_mgr::display(std::ostream&, ScreenIndex);
friend const Window_mgr &Window_mgr::display(std::ostream&, ScreenIndex) const;
public:
    // define type pos
    typedef std::string::size_type pos;
    // constructors
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    // public member functions
    // get character 
    char get() const { ++access_ctr; return contents[cursor]; }  // at cursor
    char get(pos, pos) const; // at specified location
    // move cursor
    Screen &move(pos, pos); // to specified location
    // set character 
    Screen &set(char); // at cursor
    Screen &set(pos, pos, char); // at specified location
    // display contents of Screen
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }
    pos size() const;
private:
    // private member objects
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;  // count number of calls to any member function
    // private member functions
    void do_display(std::ostream &os) const;
};

Window_mgr::Window_mgr() : screens{Screen(24, 80, ' ')} { }

void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of that Screen to all blanks
    s.contents = std::string(s.height * s.width, ' ');
}

Window_mgr &Window_mgr::add(Screen &s)
{
    screens.push_back(s);
    return *this;
}

Window_mgr &Window_mgr::display(std::ostream &os, ScreenIndex i)
{
    screens[i].display(os);
    return *this;
}

const Window_mgr &Window_mgr::display(std::ostream &os, ScreenIndex i) const
{
    screens[i].display(os);
    return *this;
}

void Screen::do_display(std::ostream &os = std::cout) const
{
    ++access_ctr;
    os << contents << "\n";
}

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
    ++access_ctr;
    contents[cursor] = c;  // set the new value at the current cursor location
    return *this;          // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos c, char ch)
{
    ++access_ctr;
    contents[r * width + c] = ch;  // set specified location to given value
    return *this;                  // return this object as an lvalue
}

Screen::pos Screen::size() const
{
    return height * width;
}

#endif
