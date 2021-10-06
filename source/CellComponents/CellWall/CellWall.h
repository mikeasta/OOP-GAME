#pragma once

#include "../Cell/Cell.h"

class CellWall: public Cell {
public:
    CellWall(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellWall() override = default;
    virtual Cell* cloneCell();
};

