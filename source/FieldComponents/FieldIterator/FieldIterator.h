#ifndef OOP_GAME_FIELD_ITERATOR_HEADLINE
#define OOP_GAME_FIELD_ITERATOR_HEADLINE

#include "../Field/Field.h"
#include "../../CellComponents/Cell/Cell.h"

class FieldIterator {
private:
    Field* field;
    unsigned int current_coord_x;
    unsigned int current_coord_y;
public:
    FieldIterator(Field* field = nullptr):field(field) {};

    // Getters
    const Cell* const getCurrent() {};
    const Cell* const getNext() {};
    bool hasMore() {};
};

#endif