#include <iostream>

#include "cube.h"
#include "face.h"

int main() {
    srand(time(NULL));
    Cube cube;
    char in;
    while (std::cin >> in) {
        switch (in) {
            case 'r':
                int index;
                bool prime;
                std::cin >> index >> prime;
                prime ? cube.sides[index]->rotatePrime() : cube.sides[index]->rotate();
                break;
            case 'x':
                cube.reset();
                break;
            case 's':
                cube.scramble();
                break;
            case 'd':
                std::cout << cube.solved() << std::endl;
                break;
            case 'a':
                cube.bfs();
                break;
            default:
                std::cout << cube.toString() << std::endl;
                std::cout << cube << std::endl;
        }
    }
}