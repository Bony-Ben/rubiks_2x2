#ifndef FACE_H
#define FACE_H

#include <array>
#include <iostream>

struct Face {
    std::array<char, 4> tiles;
    std::array<Face *, 4> adj;

    Face(char c);

    char &getTile(Face *parent, Face *next, bool index);

    bool solved();
    void rotate();
    void rotatePrime();

    friend std::ostream &operator<<(std::ostream &out, const Face &f);
};

#endif