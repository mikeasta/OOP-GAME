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
    return this->cell_content != nullptr;
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

unsigned int Cell::getX() const { return coord_x; }
unsigned int Cell::getY() const { return coord_y; }

std::string Cell::stepEffect(InteractiveObject* object) {
    auto response_lib = Response().getResponseLib();
    return response_lib["wall"];
}