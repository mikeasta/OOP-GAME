#ifndef OOP_GAME_CELL_ENTRANCE_HEADLINE
#define OOP_GAME_CELL_ENTRANCE_HEADLINE
#include "../Cell/Cell.h"

class CellEntrance: public Cell {
public:
    CellEntrance(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellEntrance() override = default;
    virtual Cell* cloneCell();
};

#endif