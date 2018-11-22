#ifndef NO_DEFAULT_H
#define NO_DEFAULT_H

class NoDefault {
public:
    NoDefault(int);
    int member;
};

struct C {
    C(): c_member(0) { }
    NoDefault c_member;
};

#endif
