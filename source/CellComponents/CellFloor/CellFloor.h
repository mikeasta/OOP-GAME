#pragma once

#include "../Cell/Cell.h"

class CellFloor: public Cell {
public:
    CellFloor(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellFloor() override = default;
    virtual Cell* cloneCell();
};

