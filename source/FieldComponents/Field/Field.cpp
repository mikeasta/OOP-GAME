#include "Field.h"
#include <iostream>

Field::Field(Cell*** cells, unsigned int rows, unsigned int cols):
    cells(cells),
    rows(rows+2),
    cols(cols+2) {}

Field::~Field() {
    for (unsigned int i = 0; i < rows; i++) {
        for (unsigned int j = 0; j < cols; j++) {
            delete cells[i][j];
        }
        delete[] cells[i];
    }
    delete[] cells;
}


Cell* Field::getCell(unsigned int coord_x, unsigned int coord_y) {
    return cells[coord_y][coord_x];
}

Cell*** Field::getCells() {
    return cells;
}

unsigned int Field::getRows() const {
    return rows;
}

unsigned int Field::getCols() const {
    return cols;
}


Field::Field(Field& other_field) {
    rows  = other_field.getRows();
    cols  = other_field.getCols();
    cells = new Cell**[rows];
    Cell*** other_cells = other_field.getCells();

    for (int i = 0; i < rows; i++) {
        cells[i] = new Cell*[cols];
        for (int j = 0; j < cols; j++) {
            cells[i][j] = other_cells[i][j]->clone();
        }
    } 
}

Field& Field::operator=(Field& other_field) {
    if (this != &other_field) {
        // Deletion
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete cells[i][j];
            }
            delete[] cells[i];
        }
        delete[] cells;

        // Assignment
        rows = other_field.getRows();
        cols = other_field.getCols();
        Cell*** other_cells = other_field.getCells();
        cells = new Cell**[rows];

        for (int i = 0; i < rows; i++) {
            cells[i] = new Cell*[cols];
            for (int j = 0; j < cols; j++) {
                cells[i][j] = other_cells[i][j]->clone();
            }
        } 
    }

    return *this;
}

Field::Field(Field&& other_field) noexcept {
    std::swap(rows, other_field.rows);
    std::swap(cols, other_field.cols);
    std::swap(this->cells, other_field.cells);
}

Field& Field::operator=(Field&& other_field) noexcept{
    if (this != &other_field) {
        std::swap(rows, other_field.rows);
        std::swap(cols, other_field.cols);
        std::swap(this->cells, other_field.cells);
    }

    return *this;
}