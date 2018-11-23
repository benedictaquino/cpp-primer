#ifndef DEBUG_H
#define DEBUG_H

class Debug {
public:
    constexpr Debug(bool b = true): hw(b), sw(b), io(b), other(b) { }
    constexpr Debug(bool h, bool s, bool i, bool o): hw(h), sw(s) io(i), other(o) { }
    constexpr bool any() { return hw || sw || io || other; }
    void set_hw(bool b) { hw = b; }
    void set_sw(bool b) { sw = b; }
    void set_io(bool b) { io = b; }
    void set_other(bool b) { hw = b; }
private:
    bool hw;    // hardware errors other than IO errors
    bool sw;    // software errors
    bool io;    // IO errors
    bool other; // other errors
};

#endif
