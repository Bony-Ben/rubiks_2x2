#ifndef CUBE_H
#define CUBE_H

#include <memory>

#include "face.h"

struct Cube {
    std::array<std::unique_ptr<Face>, 6> sides;

    Cube();

    void reset();
    void scramble();
    bool solved();
};

#endif