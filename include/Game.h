#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "windows.h"

#include "Cell.h"
#include "Piece.h"
#include "Board.h"

class Game {
private:
    Board board;
    Piece curr_piece;
    std::vector<Cell> final_puntos;
    int score;
    int speed;
    bool run;
public:

    Game();
    void controles();
    void correr();
    bool hit_built_puntos();

    bool chequear_mover(enum move_direction dir);
    bool chequear_rotacion();

    void draw();
    void refresh_final_puntos();

    void ClearScreen();
    bool game_over();
    bool regame();


};


#endif // GAME_H
