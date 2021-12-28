#include "face.h"

Face::Face(char c) {
    tiles.fill(c);
}

bool Face::solved() {
    for (int i = 0; i < (int)tiles.size() - 1; i++) {
        if (tiles[i] != tiles[i + 1]) {
            return false;
        }
    }
    return true;
}

void Face::rotate() {
}