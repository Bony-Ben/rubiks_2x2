#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "face.h"
struct Cube {
    std::array<std::unique_ptr<Face>, 6> sides;

    Cube();
    Cube(const Cube &c);

    void connect();

    void reset();
    void scramble();
    bool solved();

    void bfs();
    std::string toString();

    friend std::ostream &operator<<(std::ostream &out, const Cube &c);
};

struct Move {
    int face;
    bool prime;
};
struct Position {
    Cube cube;
    std::vector<Move> moves;
};

#endif