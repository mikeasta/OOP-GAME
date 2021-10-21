#pragma once

#include "../Field/Field.h"
#include "../../CellComponents/Cell/Cell.h"

class FieldIterator {
private:
    Field* field;
    unsigned int current_coord_x = 0;
    unsigned int current_coord_y = 0;
public:
    explicit FieldIterator(Field* field);

    // Getters
    Cell* getCurrent();
    Cell* getNext();
    bool hasMore();
    bool isLastInARow();
};

