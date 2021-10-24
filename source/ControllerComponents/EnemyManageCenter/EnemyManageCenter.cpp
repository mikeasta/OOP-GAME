//
// Created by mikeasta on 17.10.2021.
//

#include "EnemyManageCenter.h"

EnemyManageCenter::EnemyManageCenter(Field &field):
    field(field) {
    FieldIterator iterator = FieldIterator(field);
    Cell* it_cell = iterator.getCurrent();
    InteractiveObject* content;

    while (it_cell) {
        content = it_cell->getCellContent();
        if (content) {
            if (typeid(*content) == typeid(Enemy)) {
                auto new_enemy_controller = new EnemyController(dynamic_cast<Enemy*>(content), field, it_cell);
                controllers.push_back(new_enemy_controller);

                std::cout << "\nControllers count: " << controllers.size();
            }
        }


        it_cell = iterator.getNext();
    }
}

void EnemyManageCenter::move_all() {
    std::cout << "\nEMG:Controllers count: " << controllers.size();
    for (int i = 0; i < controllers.size(); i++) {
        std::cout << "\nMove Enemy#" << i;
        EnemyController* curr_controller = controllers[i];

        // Calc move chance
        RandomNumberGenerator randomizer;
        auto curr = directions.begin();
        std::advance(curr, randomizer.generate(0, 3));

        char option = curr->second;
        std::string response = curr_controller->move( directions, option);

        if (response == "DIED") {
            controllers.erase(controllers.begin() + i);
        }

    }
}