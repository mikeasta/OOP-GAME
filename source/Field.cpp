#include <iostream>
#include "Cell.cpp"

class Field {
protected:
    int rows     = 0;
    int cols     = 0;
    Cell** cells = nullptr;
public:
    // Доделать
    Field(Cell** cells): cells(cells) {

        rows = sizeof(cells);
        cols = sizeof(cells[0]);
    }
    
    ~Field() {
        for (int i = 0; i < rows; i++)
            delete[] cells[i];

        delete[] cells; 
    }

    Field (const Field& other) {
        for (int i = 0; i < rows; i++)
            delete[] cells[i];
        delete[] cells; 
        cells = other.cells;
    }

    Field& operator=(const Field& other) {
        if (this != &other) {
            for (int i = 0; i < rows; i++)
                delete[] cells[i];

            delete[] cells; 
            cells = other.cells;
        }

        return *this;
    }

    Field (Field&& other) {
        Cell* buff;
        for (int i = 0; i < rows; i++) {
            buff = cells[i];
            cells[i] = other.cells[i];
            delete[] buff;
        }

        other.cells = nullptr;

    }

    Field& operator=(Field&& other) {
        if (this != &other) {
            Cell* buff;
            for (int i = 0; i < rows; i++) {
                buff = cells[i];
                cells[i] = other.cells[i];
                delete[] buff;
            }

            other.cells = nullptr;
        }

        return *this;
    }
};