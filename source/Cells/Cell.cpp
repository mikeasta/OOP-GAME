#include "Cell.h"

Cell::Cell(unsigned int coord_x, unsigned int coord_y):
    coord_x(coord_x),
    coord_y(coord_y),
    is_empty(true),
    inner_object(nullptr) {}

Cell* Cell::cloneCell() {
    Cell* tmp = new Cell(this->coord_x, this->coord_y);
    return tmp;
}