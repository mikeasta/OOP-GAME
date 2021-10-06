#pragma once

#include "../Field/Field.h"
#include "../../CellComponents/Cell/Cell.h"

class FieldIterator {
private:
    Field* field;
    unsigned int current_coord_x = 0;
    unsigned int current_coord_y = 0;
public:
    FieldIterator(Field* field = nullptr):field(field) {};

    // Getters
    const Cell* const getCurrent();
    const Cell* const getNext();
    bool hasMore();
    bool isLastInARow();
};

