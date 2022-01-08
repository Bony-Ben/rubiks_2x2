#include "cube.h"

#include <stdlib.h>

#include <queue>
#include <string>
#include <unordered_map>

Cube::Cube() {
    reset();
}

Cube::Cube(const Cube &c) {
    for (int i = 0; i < 6; i++) {
        sides[i] = std::make_unique<Face>(*c.sides[i]);
    }
    connect();
}

void Cube::reset() {
    sides[0] = std::make_unique<Face>('W');
    sides[1] = std::make_unique<Face>('Y');
    sides[2] = std::make_unique<Face>('B');
    sides[3] = std::make_unique<Face>('G');
    sides[4] = std::make_unique<Face>('O');
    sides[5] = std::make_unique<Face>('R');
    connect();
}

void Cube::connect() {
    sides[0]->adj = {sides[2].get(), sides[5].get(), sides[3].get(), sides[4].get()};
    sides[1]->adj = {sides[2].get(), sides[4].get(), sides[3].get(), sides[5].get()};
    sides[2]->adj = {sides[1].get(), sides[5].get(), sides[0].get(), sides[4].get()};
    sides[3]->adj = {sides[1].get(), sides[4].get(), sides[0].get(), sides[5].get()};
    sides[4]->adj = {sides[1].get(), sides[2].get(), sides[0].get(), sides[3].get()};
    sides[5]->adj = {sides[1].get(), sides[3].get(), sides[0].get(), sides[2].get()};
}

void Cube::scramble() {
    for (int i = 0; i < 100; i++) {
        if (rand() % 2 == 0) {
            sides[rand() % 6]->rotate();
        } else {
            sides[rand() % 6]->rotatePrime();
        }
    }
}

bool Cube::solved() {
    for (int i = 0; i < (int)sides.size(); i++) {
        if (!sides[i]->solved()) {
            return false;
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const Cube &c) {
    out << "----" << std::endl;
    for (int i = 0; i < (int)c.sides.size(); i++) {
        out << *c.sides[i] << std::endl;
        out << "----" << std::endl;
    }
    return out;
}

void Cube::bfs() {
    std::unordered_map<std::string, bool> visited;

    std::queue<Position> q;
    q.push(Position{*this, std::vector<Move>{}});
    while (!q.empty()) {
        if (visited.size() % 10000 == 0) {
            std::cout << visited.size() << std::endl;
        }

        std::vector<Move> moves = q.front().moves;
        Cube cur = q.front().cube;
        q.pop();
        if (cur.solved()) {
            std::cout << "Done!" << std ::endl;
            for (int i = 0; i < (int)moves.size(); i++) {
                std::cout << "r " << moves[i].face << ' ' << moves[i].prime << std::endl;
            }
            return;
        }
        visited[cur.toString()] = true;
        for (int i = 0; i < (int)cur.sides.size(); i += 2) {
            Cube temp1 = cur;
            Cube temp2 = cur;
            temp1.sides[i]->rotate();
            temp2.sides[i]->rotatePrime();
            std::vector<Move> moves1 = moves;
            std::vector<Move> moves2 = moves;
            moves1.push_back(Move{i, false});
            moves2.push_back(Move{i, true});
            q.push(Position{temp1, moves1});
            q.push(Position{temp2, moves2});
        }
        while (!q.empty() && visited[q.front().cube.toString()]) {
            q.pop();
        }
    }
}

std::string Cube ::toString() {
    std::string s;
    for (int i = 0; i < (int)sides.size(); i++) {
        for (int j = 0; j < (int)sides[i]->tiles.size(); j++) {
            s += sides[i]->tiles[j];
        }
    }
    return s;
}