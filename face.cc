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
    char temp = tiles[(int)tiles.size() - 1];
    for (int i = (int)tiles.size() - 1; i > 0; i--) {
        tiles[i] = tiles[i - 1];
    }
    tiles[0] = temp;

    for (int i = 0; i < (int)adj.size(); i++) {
        char a;
        char b;
        
    }
}

void Face::rotatePrime() {
    rotate();
    rotate();
    rotate();
}