#include "CellExit.h"

Cell* CellExit::cloneCell() {
    Cell* tmp = new CellExit(this->coord_x, this->coord_y);
    return tmp;
}