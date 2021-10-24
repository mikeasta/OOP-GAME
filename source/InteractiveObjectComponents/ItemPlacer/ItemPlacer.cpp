//
// Created by mikeasta on 16.10.2021.
//

#include "ItemPlacer.h"

void ItemPlacer::place(Item* curr_item, Cell* curr_cell) {
    curr_cell->setCellContent(curr_item);
}

void ItemPlacer::fillField(Field &field) {
    int count = 3;
    int chance_percent = 10;
    RandomNumberGenerator rd;

    auto iterator   = new FieldIterator(field);
    Cell* curr_cell = iterator->getCurrent();
    while (curr_cell) {
        bool isEmpty = !curr_cell->isCellContentExist();
        if ((typeid(*curr_cell) == typeid(CellFloor)) & isEmpty & rd.simulate_chance(chance_percent) & count > 0) {
            Item* new_item = Item().create(item_voc);
            place(new_item, curr_cell);
            count--;
        }
        curr_cell = iterator->getNext();
    }
}
