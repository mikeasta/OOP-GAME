#include "CellWall.h"

Cell* CellWall::cloneCell() {
    Cell* tmp = new CellWall(this->coord_x, this->coord_y);
    return tmp;
}

std::pair<bool, std::string> CellWall::stepEffect(InteractiveObject* object) {
    std::pair<bool, std::string> response;
    response = std::make_pair(true, "WALL");
    return response;
}