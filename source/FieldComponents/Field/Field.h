#pragma once 

#include "../../CellComponents/Cell/Cell.h"
#include "../FieldGenerator/FieldGenerator.h"

class FieldIterator;

class Field {
protected:
    Cell ***cells{};
    unsigned int rows{};
    unsigned int cols{};
public:
    Field(Cell*** cells, unsigned int rows, unsigned int cols);
    ~Field();

    // Copy & Move
    Field (Field& other_field);
    Field& operator=(Field& other_field);
    Field (Field&& other_field) noexcept;
    Field& operator=(Field&& other_field) noexcept;

    // Getters
    unsigned int getRows() const;
    unsigned int getCols() const;
    Cell*** getCells();
    Cell* getCell(unsigned int coord_x, unsigned int coord_y);
};
