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

char &Face::getTile(Face *parent, Face *next, bool index) {
    for (int i = 0; i < 3; i++) {
        if (parent == adj[i]) {
            if (next == adj[i + 1]) {
                return index ? tiles[i + 1] : tiles[i];
            } else {
                return index ? tiles[i] : tiles[i + 1];
            }
        }
    }
    if (next == adj[0]) {
        return index ? tiles[0] : tiles[3];
    } else {
        return index ? tiles[3] : tiles[0];
    }
}

void Face::rotate() {
    char temp = tiles[(int)tiles.size() - 1];
    for (int i = (int)tiles.size() - 1; i > 0; i--) {
        tiles[i] = tiles[i - 1];
    }
    tiles[0] = temp;

    char temp1 = adj[3]->getTile(this, adj[0], false);
    char temp2 = adj[3]->getTile(this, adj[0], true);

    for (int i = (int)adj.size() - 1; i > 0; i--) {
        adj[i]->getTile(this, adj[(i + 1) % (int)adj.size()], false) = adj[i - 1]->getTile(this, adj[i], false);
        adj[i]->getTile(this, adj[(i + 1) % (int)adj.size()], true) = adj[i - 1]->getTile(this, adj[i], true);
    }

    adj[0]->getTile(this, adj[1], false) = temp1;
    adj[0]->getTile(this, adj[1], true) = temp2;
}

void Face::rotatePrime() {
    rotate();
    rotate();
    rotate();
}

std::ostream &operator<<(std::ostream &out, const Face &f) {
    out << f.tiles[0] << ' ' << f.tiles[1] << std::endl;
    out << f.tiles[3] << ' ' << f.tiles[2];
    return out;
}