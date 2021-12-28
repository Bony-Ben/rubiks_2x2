#include "face.h"

Face::Face(char c) {
    tiles.fill(c);
}

bool Face::solved() {
    return tiles[0] == tiles[1] && tiles[1] == tiles[2] && tiles[2] == tiles[3];
}

void Face::rotate() {
}