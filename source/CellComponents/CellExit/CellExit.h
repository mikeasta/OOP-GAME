#pragma once

#include "../Cell/Cell.h"

class CellExit: public Cell {
public:
    CellExit(unsigned int coord_x, unsigned int coord_y):Cell(coord_x, coord_y) {};
    ~CellExit() override = default;
    virtual Cell* clone();
    virtual std::pair<bool, std::string> stepEffect(InteractiveObject* object);
};

