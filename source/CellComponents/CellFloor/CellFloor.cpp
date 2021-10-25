#include "CellFloor.h"

Cell* CellFloor::clone() {
    Cell* tmp = new CellFloor(this->coord_x, this->coord_y);
    return tmp;
}

std::string CellFloor::stepEffect(InteractiveObject* object) {
    bool isCellContent = isCellContentExist();

    if (!isCellContent) {
        this->setCellContent(object);
    }
    auto response_lib = Response().getResponseLib();
    return response_lib["floor"];
}