#include "CellEntrance.h"

Cell* CellEntrance::clone() {
    Cell* tmp = new CellEntrance(this->coord_x, this->coord_y);
    return tmp;
}

std::string CellEntrance::stepEffect(InteractiveObject* object) {
    std::pair<bool, std::string> response;
    auto response_lib = Response().getResponseLib();
    return response_lib["entrance"];
}