#include "CellWall.h"

Cell* CellWall::clone() {
    Cell* tmp = new CellWall(this->coord_x, this->coord_y);
    return tmp;
}

std::string CellWall::stepEffect(InteractiveObject* object) {
    auto response_lib = Response().getResponseLib();
    return response_lib["wall"];
}