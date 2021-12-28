#include "cube.h"

Cube::Cube() {
    reset();
}

void Cube::reset() {
    sides[0] = std::make_unique<Face>('W');
    sides[1] = std::make_unique<Face>('Y');
    sides[2] = std::make_unique<Face>('B');
    sides[3] = std::make_unique<Face>('G');
    sides[4] = std::make_unique<Face>('O');
    sides[5] = std::make_unique<Face>('R');

    sides[0]->adj = {sides[2].get(), sides[5].get(), sides[3].get(), sides[4].get()};
    sides[1]->adj = {sides[2].get(), sides[4].get(), sides[3].get(), sides[5].get()};
    sides[2]->adj = {sides[1].get(), sides[5].get(), sides[0].get(), sides[4].get()};
    sides[3]->adj = {sides[1].get(), sides[4].get(), sides[0].get(), sides[5].get()};
    sides[4]->adj = {sides[1].get(), sides[2].get(), sides[0].get(), sides[3].get()};
    sides[5]->adj = {sides[1].get(), sides[3].get(), sides[0].get(), sides[2].get()};
}

void Cube::scramble() {
}

bool Cube::solved() {
    for (int i = 0; i < (int) sides.size(); i++) {
        if (!sides[i]->solved()) {
            return false;
        }
    }
    return true;
}