#ifndef OOP_GAME_CELL_WALL_HEADLINE
#define OOP_GAME_CELL_WALL_HEADLINE
#include "../Cell/Cell.h"

class CellWall: public Cell {
public:
    CellWall(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellWall() override = default;
    virtual Cell* cloneCell() {};
};

#endif