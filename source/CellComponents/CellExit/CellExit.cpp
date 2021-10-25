#include "CellExit.h"

Cell* CellExit::clone() {
    Cell* tmp = new CellExit(this->coord_x, this->coord_y);
    return tmp;
}

std::string CellExit::stepEffect(InteractiveObject* object) {
    auto response_lib = Response().getResponseLib();
    return response_lib["exit"];
}