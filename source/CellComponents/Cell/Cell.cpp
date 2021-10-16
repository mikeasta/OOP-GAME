#include "Cell.h"

Cell::Cell(unsigned int coord_x, unsigned int coord_y):
    coord_x(coord_x),
    coord_y(coord_y),
    cell_content(nullptr) {}

Cell* Cell::clone() {
    Cell* tmp = new Cell(this->coord_x, this->coord_y);
    return tmp;
}

bool Cell::isCellContentExist() {
    return (this->cell_content) ? true: false;
}

void Cell::setCellContent(InteractiveObject *object) {
    cell_content = object;
}

InteractiveObject* Cell::getCellContent(){
    return cell_content;
}

void Cell::clearCellContent() {
    this->setCellContent(nullptr);
}

std::pair<unsigned int, unsigned int> Cell::getCoords() {
    std::pair<unsigned int, unsigned int> response;
    response = std::make_pair(coord_x, coord_y);
    return response;
}

std::pair<bool, std::string> Cell::stepEffect(InteractiveObject* object) {
    std::pair<bool, std::string> response;
    response = std::make_pair(true, "WALL");
    return response;
}