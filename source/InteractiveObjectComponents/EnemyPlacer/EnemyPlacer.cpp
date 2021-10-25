//
// Created by mikeasta on 16.10.2021.
//

#include "EnemyPlacer.h"

void EnemyPlacer::place(Enemy* curr_enemy, Cell* curr_cell) {
    curr_cell->setCellContent(curr_enemy);
}

void EnemyPlacer::fillField(Field &field) {
    int count  = 3, chance_percent = 10;
    RandomNumberGenerator rd;

    auto iterator = new FieldIterator(field);
    Cell* curr_cell = iterator->getCurrent();
    while (curr_cell) {
        bool isEmpty = !curr_cell->isCellContentExist();
        if ((typeid(*curr_cell) == typeid(CellFloor)) & isEmpty & rd.simulate_chance(chance_percent) & count > 0) {
            Enemy enemy_generator = Enemy();
            place(Enemy().create(enemy_voc), curr_cell);
            count--;
        }
        curr_cell = iterator->getNext();
    }
}
