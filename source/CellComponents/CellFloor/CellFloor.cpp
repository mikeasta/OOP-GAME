#include "CellFloor.h"

Cell* CellFloor::cloneCell() {
    Cell* tmp = new CellFloor(this->coord_x, this->coord_y);
    return tmp;
}

std::pair<bool, std::string> CellFloor::stepEffect(InteractiveObject* object) {
    bool isCellContent = isCellContentExist();
    std::pair<bool, std::string> response;
    if (!isCellContent) {
        this->setCellContent(object);
        // Set Player's object curr_cell
        response = std::make_pair(true, "FLOOR");
    } else {
        // Check for enemy and combat
    }
    return response;
}