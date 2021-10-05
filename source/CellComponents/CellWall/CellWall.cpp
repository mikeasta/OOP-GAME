#include "CellWall.h"

Cell* CellWall::cloneCell() {
    Cell* tmp = new CellWall(this->coord_x, this->coord_y);
    return tmp;
}