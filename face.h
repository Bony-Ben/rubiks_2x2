#ifndef FACE_H
#define FACE_H

#include <array>

struct Face {
    std::array<char, 4> tiles;
    std::array<Face *, 4> adj;

    Face(char c);

    bool solved();
    void rotate();
};

#endif