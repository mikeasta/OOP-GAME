#pragma once

#include "../Cell/Cell.h"

class CellFloor: public Cell {
public:
    CellFloor(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellFloor() override = default;
    Cell* clone() final;
    std::string stepEffect(InteractiveObject* object) final;
};

