#pragma once 

#include "../../CellComponents/Cell/Cell.h"
#include "../FieldGenerator/FieldGenerator.h"

class FieldIterator;

class Field {
protected:
    Cell*** cells;
    unsigned int rows;
    unsigned int cols;
public:
    Field(FieldGenerator generator, unsigned int new_rows = 0, unsigned int new_cols = 0):
        cells(generator.generateStandartField(new_rows, new_cols)),
        rows(generator.getTmpRows()),
        cols(generator.getTmpCols()) {}
    ~Field();

    // Getters
    unsigned int getRows() { return rows; }
    unsigned int getCols() { return cols; }
    Cell*** getCells() { return cells; }
    Cell* getSpecificCell(unsigned int coord_x, unsigned int coord_y);
};
