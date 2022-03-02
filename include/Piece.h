#ifndef PIECE_H
#define PIECE_H

#include "Cell.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

enum tipo_pieza {
    t_piece,
    i_piece,
    o_piece,
    l_piece,
    j_piece,
    s_piece,
    z_piece
};

enum move_direction {
    right = 1,
    left = -1
};

class Piece {
private:
    enum tipo_pieza type;
    std::vector<Cell> body;
    Cell pos;


public:
    Piece() = default;
    Piece(Cell pos);
    void caer();
    std::vector<Cell> next_caer_body();
    void move(enum move_direction dir);
    std::vector<Cell> next_mover_body(enum move_direction dir);
    void rotate();
    std::vector<Cell> next_rotar_body();

    std::vector<Cell> get_body() {return body;}
    void set_body(std::vector<Cell> body) {this->body = body;}

};

#endif // PIECE_H
