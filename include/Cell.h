#ifndef CELL_H
#define CELL_H

#include <iostream>

class Cell {
private:
    int x;
    int y;
    char type;
public:
    Cell(int x = 0, int y = 0, char type = ' ');

    int get_x() const {return x;}
    int get_y() const {return y;}
    char get_tipo() const {return type;}
    void set_tipo(char c) {type = c;}


    Cell shift_copy(int x_shift, int y_shift) const;
    void move(int x_mover, int y_mover);
    void set_coordinate(int x_new, int y_new);

    bool operator==(const Cell &rhs) const;
};


#endif // CELL_H
