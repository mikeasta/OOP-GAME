#ifndef OOP_GAME_CELL_EXIT_HEADLINE
#define OOP_GAME_CELL_EXIT_HEADLINE
#include "../Cell/Cell.h"

class CellExit: public Cell {
public:
    CellExit(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellExit() override = default;
    virtual Cell* cloneCell();
};

#endif