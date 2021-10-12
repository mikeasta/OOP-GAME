#include <iostream>
#include "FieldGenerator.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"

Cell*** FieldGenerator::generateField(unsigned int rows, unsigned int cols) {

    // Check if field area equal 0
    if (rows == 0 || cols == 0) {
        std::cout << "FieldGenerator: Field area equals zero\n";
        std::cout << "FieldGenerator: Field generation is finished\n";
        return nullptr;
    }


    // Define full size of field
    unsigned int rows_with_walls = rows + 2;
    unsigned int cols_with_walls = cols + 2;
    RandomNumberGenerator random_generator = RandomNumberGenerator();


    // Create two-dimensional array of cells
    Cell*** cells = new Cell**[rows_with_walls];
    for (unsigned int i = 0; i < rows_with_walls; i++)
        cells[i] = new Cell*[cols_with_walls];


    // Fill field
    for (unsigned int i = 0; i < rows_with_walls; i++) {
        for(unsigned int j = 0; j < cols_with_walls; j++) {
            // Check for being wall
            if (i == 0 || i == rows_with_walls - 1 || j == 0 || j == cols_with_walls - 1) {
                cells[i][j] = new CellWall(i, j);
            } else {
                cells[i][j] = new CellFloor(i, j);
            }
        }
    }


    // Define entrance and exit
    unsigned int chooseDirection = random_generator.generate(0, 1);
    if (chooseDirection == 0) {
        // Entrance and exit on first and last row
        unsigned int chooseEntranceSide = random_generator.generate(0, 1);
        if (chooseEntranceSide = 0) {
            // Entrance on the first row
            unsigned int entranceCol = random_generator.generate(1, cols);
            unsigned int exitCol     = random_generator.generate(1, cols);

            delete cells[0][entranceCol];
            cells[0][entranceCol] = new CellEntrance(entranceCol, 0);

            delete cells[rows+1][exitCol];
            cells[rows+1][exitCol] = new CellExit(exitCol, rows+1);
        } else {
            // Entrance on the last row
            unsigned int entranceCol = random_generator.generate(1, cols);
            unsigned int exitCol     = random_generator.generate(1, cols);

            delete cells[rows+1][entranceCol];
            cells[rows+1][entranceCol] = new CellEntrance(entranceCol, rows+1);

            delete cells[0][exitCol];
            cells[0][exitCol] = new CellExit(exitCol, 0);
        }
    } else {
        // Entrance and exit on first and last column
        unsigned int chooseEntranceSide = random_generator.generate(0, 1);
        if (chooseEntranceSide = 0) {
            // Entrance on the left
            unsigned int entranceRow = random_generator.generate(1, rows);
            unsigned int exitRow     = random_generator.generate(1, rows);

            delete cells[entranceRow][0];
            cells[entranceRow][0] = new CellEntrance(0, entranceRow);

            delete cells[exitRow][cols+1];
            cells[exitRow][cols+1] = new CellExit(cols+1, exitRow);
        } else {
            // Entrance on the right
            unsigned int entranceRow = random_generator.generate(1, rows);
            unsigned int exitRow     = random_generator.generate(1, rows);

            delete cells[entranceRow][cols+1];
            cells[entranceRow][cols+1] = new CellEntrance(cols+1, entranceRow);

            delete cells[exitRow][0];
            cells[exitRow][0] = new CellExit(0, exitRow);
        }
    }

    return cells;
}