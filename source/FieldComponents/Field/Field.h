#pragma once 

#include "../../CellComponents/Cell/Cell.h"
#include "../FieldGenerator/FieldGenerator.h"

class FieldIterator;

class Field {
protected:
    Cell*** cells;
public:
    Field(Cell*** cells = nullptr):cells(cells) {}
    ~Field() {}

    // Getters
    unsigned int getRows() { return sizeof(cells); }
    unsigned int getCols() { return sizeof(cells[0]); }
    Cell*** getCells() { return cells; }
    Cell* getSpecificCell(unsigned int coord_x, unsigned int coord_y);
};
