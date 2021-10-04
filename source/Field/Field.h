#include <iostream>
//#include "../Cell/Cell.h"
#include "../CellSequenceGenerator/CellSequenceGenerator.h"

class Field {
protected:
    int rows_with_borders;
    int cols_with_borders;
    Cell** cells;
public:
    Field () {}

    Field (Cell **cells):cells(cells) {
        rows_with_borders = sizeof(cells);
        cols_with_borders = sizeof(cells[0]);
    }

    Field (int input_rows = 0, int input_cols = 0, int input_lava_cells_percentage = 0) {
        std::cout << "Field generates with CellSequenceGenerator";
        CellSequenceGenerator generator;
        cells = generator.generate_field(input_rows, input_cols, input_lava_cells_percentage);
        rows_with_borders  = sizeof(cells);
        cols_with_borders  = sizeof(cells[0]);
    }
    
    ~Field() {
        for (int i = 0; i < rows_with_borders; i++)
            delete[] cells[i];

        delete[] cells; 
    }

    Field (const Field& other) {
        for (int i = 0; i < rows_with_borders; i++)
            delete[] cells[i];
        delete[] cells; 
        cells = other.cells;
    }

    Field& operator=(const Field& other) {
        if (this != &other) {
            for (int i = 0; i < rows_with_borders; i++)
                delete[] cells[i];

            delete[] cells; 
            cells = other.cells;
        }

        return *this;
    }

    Field (Field&& other) {
        Cell* buff;
        for (int i = 0; i < rows_with_borders; i++) {
            buff = cells[i];
            cells[i] = other.cells[i];
            delete[] buff;
        }

        other.cells = nullptr;

    }

    Field& operator=(Field&& other) {
        if (this != &other) {
            Cell* buff;
            for (int i = 0; i < rows_with_borders; i++) {
                buff = cells[i];
                cells[i] = other.cells[i];
                delete[] buff;
            }

            other.cells = nullptr;
        }

        return *this;
    }

    Cell** getField() const {
        return cells;
    }

    int getRows() {
        return rows_with_borders;
    }

    int getCols() {
        return cols_with_borders;
    }
};