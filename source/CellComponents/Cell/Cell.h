#pragma once

#include "../../InteractiveObject/InteractiveObject.h"

class Cell {
protected:
    unsigned int coord_x;
    unsigned int coord_y;
    bool isEmpty = true;
    InteractiveObject* cell_content;
public:
    Cell(unsigned int coord_x, unsigned int coord_y);
    bool isEmptyGetter() { return isEmpty; }
    virtual ~Cell() = default;
    virtual Cell* cloneCell();
};
