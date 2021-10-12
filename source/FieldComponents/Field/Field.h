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
    Field(Cell*** cells, unsigned int rows, unsigned int cols):
        cells(cells),
        rows(rows+2),
        cols(cols+2) {};
    ~Field();

    // Copy & Move
    Field (Field& other_field);
    Field& operator=(Field& other_field);
    Field (Field&& other_field);
    Field& operator=(Field&& other_field);

    // Getters
    unsigned int getRows() { return rows; }
    unsigned int getCols() { return cols; }
    Cell*** getCells() { return cells; }
    Cell* getSpecificCell(unsigned int coord_x, unsigned int coord_y);
};
