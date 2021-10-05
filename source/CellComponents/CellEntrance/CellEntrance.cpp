#include "CellEntrance.h"

Cell* CellEntrance::cloneCell() {
    Cell* tmp = new CellEntrance(this->coord_x, this->coord_y);
    return tmp;
}