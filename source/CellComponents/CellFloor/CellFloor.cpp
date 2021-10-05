#include "CellFloor.h"

Cell* CellFloor::cloneCell() {
    Cell* tmp = new CellFloor(this->coord_x, this->coord_y);
    return tmp;
}