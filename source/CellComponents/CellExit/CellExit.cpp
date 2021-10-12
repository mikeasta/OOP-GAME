#include "CellExit.h"

Cell* CellExit::cloneCell() {
    Cell* tmp = new CellExit(this->coord_x, this->coord_y);
    return tmp;
}

std::pair<bool, std::string> CellExit::stepEffect(InteractiveObject* object) {
    std::pair<bool, std::string> response;
    response = std::make_pair(true, "EXIT");
    return response;
}