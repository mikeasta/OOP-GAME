//
// Created by mikeasta on 16.10.2021.
//

#include "EnemyPlacer.h"

void EnemyPlacer::place(Enemy* curr_enemy, Cell* curr_cell) {
    curr_cell->setCellContent(curr_enemy);
}

void EnemyPlacer::fillField(Field *field) {
    int count          = 3;
    int chance_percent = 10;
    bool onePlaced     = false;
    RandomNumberGenerator rd;

    FieldIterator* iterator = new FieldIterator(field);
    Cell* curr_cell = iterator->getCurrent();
    while (!onePlaced) {
        while (curr_cell) {
            bool isEmpty = !curr_cell->isCellContentExist();
            if ((typeid(*curr_cell) == typeid(CellFloor)) & isEmpty & rd.simulate_chance(chance_percent) & count > 0) {
                Enemy enemy_generator = Enemy();
                curr_cell->setCellContent(enemy_generator.create());
                count--;
                onePlaced = true;
            }
            curr_cell = iterator->getNext();
        }
    }

}
