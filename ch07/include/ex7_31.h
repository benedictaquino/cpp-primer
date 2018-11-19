#ifndef X_Y_H
#define X_Y_H

// class declarations
struct X;
struct Y;

// class definitions
struct X {
    Y *y_guy;
};

struct Y {
    X x_guy;
};

#endif
