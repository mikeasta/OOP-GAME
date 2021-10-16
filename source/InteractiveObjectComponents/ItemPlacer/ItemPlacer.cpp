//
// Created by mikeasta on 16.10.2021.
//

#include "ItemPlacer.h"

void ItemPlacer::place(Item* curr_item, Cell* curr_cell) {
    curr_cell->setCellContent(curr_item);
}

void ItemPlacer::fillField(Field *field) {
    int count = 3;
    int chance_percent = 10;
    RandomNumberGenerator rd;

    FieldIterator* iterator = new FieldIterator(field);
    Cell* curr_cell = iterator->getCurrent();
    while (curr_cell != nullptr) {
        bool isEmpty = !curr_cell->isCellContentExist();
        float coef   = rd.generate(0, 100);
        if ((typeid(*curr_cell) == typeid(CellFloor)) & isEmpty & coef <= chance_percent & count > 0) {
            Item item_generator = Item();
            curr_cell->setCellContent(item_generator.create());
            count--;
        }
        curr_cell = iterator->getNext();
    }
}
