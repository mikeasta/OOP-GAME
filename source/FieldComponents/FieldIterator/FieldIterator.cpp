#include "FieldIterator.h"

FieldIterator::FieldIterator(Field &field):
    field(field) {}

bool FieldIterator::hasMore() {
    unsigned int field_cols = field.getCols();
    unsigned int field_rows = field.getRows();

    return (current_coord_x < field_cols - 1) ||
    (current_coord_x == field_cols - 1 & current_coord_y < field_rows - 1);
}

bool FieldIterator::isLastInARow() {
    unsigned int field_cols = field.getCols();
    return (current_coord_x == field_cols - 1);
}

Cell* FieldIterator::getCurrent() {
    return field.getCells()[current_coord_y][current_coord_x];
}

Cell* FieldIterator::getNext() {
    unsigned int field_cols = field.getCols();

    if (hasMore()) {
        if (current_coord_x == field_cols - 1) {
            current_coord_y++;
            current_coord_x = 0;
        } else {
            current_coord_x++;
        }
        return getCurrent();
    } else {
        current_coord_x = 0;
        current_coord_y = 0;
        return nullptr;
    }
}