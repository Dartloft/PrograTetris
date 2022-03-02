#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>
#include <algorithm>


class Board {
private:
    int width;
    int height;
    std::vector<Cell> all_puntos;
    std::vector<Cell> built_puntos;
public:
    Board(int width = 30, int height = 30);

    int get_width() {return width;}
    int get_height() {return height;}
    std::vector<Cell> get_all_puntos() {return all_puntos;}
    std::vector<Cell> get_built_puntos() {return built_puntos;}
    void set_built_puntos(std::vector<Cell> built_puntos) {this->built_puntos = built_puntos;}
    void set_border();

    void insert_to_built_puntos (std::vector<Cell> insert_puntos);
    int remover_fila();
    void refresh();

};


#endif // BOARD_H
