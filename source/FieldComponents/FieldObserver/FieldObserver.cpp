//
// Created by mikeasta on 23.11.2021.
//

#include "FieldObserver.h"

FieldObserver::FieldObserver(Field &field):
    field(field) {}

void FieldObserver::analyze() {
    current_field_stats["floor_cells_count"] = 0;
    current_field_stats["enemy_count"] = 0;
    current_field_stats["item_count"] = 0;

    auto iterator = new FieldIterator(field);
    Cell* curr_cell = iterator->getCurrent();
    while (curr_cell) {
        if (typeid(*curr_cell) == typeid(CellFloor)) {
            current_field_stats["floor_cells_count"]++;
        }

        auto content = curr_cell->getCellContent();
        if (content) {
            if (typeid(*content) == typeid(Enemy)) {
                current_field_stats["enemy_count"]++;
            } else if (typeid(*content) == typeid(Item)) {
                current_field_stats["item_count"]++;
            }
        }

        curr_cell = iterator->getNext();
    }
}

std::map<std::string, int> FieldObserver::getFieldStats() {
    this->analyze();
    return current_field_stats;
};

