#include "CellEntrance.h"

Cell* CellEntrance::clone() {
    Cell* tmp = new CellEntrance(this->coord_x, this->coord_y);
    return tmp;
}

std::pair<bool, std::string> CellEntrance::stepEffect(InteractiveObject* object) {
    std::pair<bool, std::string> response;
    response = std::make_pair(true, "WALL");
    return response;
}