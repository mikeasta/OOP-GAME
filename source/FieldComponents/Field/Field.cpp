#include "Field.h"
#include <iostream>

Field::~Field() {
    std::cout << "Field: Field deletion started\n";
    unsigned int rows = sizeof(cells);
    unsigned int cols = sizeof(cells[0]);

    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            delete cells[i][j];
        }

        delete[] cells[i];
    }

    delete[] cells;
    std::cout << "Field: Field deletion finished\n";
}

Cell* Field::getSpecificCell(unsigned int coord_x, unsigned int coord_y) {
    return cells[coord_y][coord_x];
}