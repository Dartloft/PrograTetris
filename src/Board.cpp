#include "Board.h"

Board::Board(int width, int height)
    :width{width}, height{height} {
        for (int i{0}; i < width; i++)
            for (int j{0}; j < height; j++)
                all_puntos.push_back(Cell(i, j));

        set_border();
}

void Board::refresh() {
    set_border();
    for (auto &all_pnt : all_puntos)
        for (auto built_pnt : built_puntos)
            if (all_pnt == built_pnt)
                all_pnt = built_pnt;    //seting the char of all_pnt to built pnt
}

void Board::insert_to_built_puntos (std::vector<Cell> insert_puntos) {
    built_puntos.insert(built_puntos.end(), insert_puntos.begin(), insert_puntos.end());
}

void Board::set_border() {
    for (auto &point : all_puntos) {
        if (point.get_x() == 0 || point.get_y() == 0 || point.get_x() == width - 1 || point.get_y() == height - 1)
            point.set_tipo('#');
        else
            point.set_tipo(' ');
    }
}

int Board::remover_fila() {
    int remover_filas{0};
    int i{1};
    while(i < height) {

        int built_puntos_count = std::count_if(built_puntos.begin(), built_puntos.end(), [i](const Cell &point) {
           return (point.get_y() == i);
        });

         if (built_puntos_count == (width - 2)) {
            remover_filas++;


            auto it = std::remove_if(built_puntos.begin(), built_puntos.end(), [i](Cell point) {
                                return (point.get_y() == i);
                                });
            built_puntos.erase(it, built_puntos.end());

            std::for_each(built_puntos.begin(), built_puntos.end(), [i](Cell &point) {
                if (point.get_y() > i)
                    point.move(0, -1);
            });

        } else
            i++;
    }

    return remover_filas;
}
