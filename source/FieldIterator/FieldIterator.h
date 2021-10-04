#include <iostream>
#include "../Field/Field.h"
#include "../Cell/Cell.h"

class FieldIterator {
private:
    Field* field;
    int rows;
    int cols;
    int curr_row = 0;
    int curr_col = 0;
public:
    FieldIterator(Field* field):
        field(field), 
        rows(sizeof((*field).getField())),
        cols(sizeof((*field).getField()[0])) {}

    bool hasMore() {
        // Check, if there is at least 1 cell after current
        return (curr_row + 1 < rows) || (curr_col + 1 < cols) ? true : false;
    }

    Cell* getCurrent() {
        return &field->getField()[curr_row][curr_col];
    }

    Cell* next() {
        if (curr_col + 1 < cols) {
            curr_col++;
            return FieldIterator::getCurrent();
        } else if (curr_row + 1 < rows) {
            curr_col = 0;
            curr_row++;
            return FieldIterator::getCurrent();
        } 

        return nullptr;
    }

    bool isLastInARow(Cell* cell) {
        Cell** cells = (*field).getField();
        for (int i = 0; i < rows; i++)
            if (cell == &cells[i][cols-1])
                return true;
        return false;
    }
};