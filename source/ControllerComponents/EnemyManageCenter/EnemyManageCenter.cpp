//
// Created by mikeasta on 17.10.2021.
//

#include "EnemyManageCenter.h"

std::vector<std::string> directions = {"w", "a", "s", "d"};

EnemyManageCenter::EnemyManageCenter(Field *field):
    field(field){
    FieldIterator iterator = FieldIterator(field);
    Cell* it_cell          = iterator.getCurrent();
    InteractiveObject* content;
    while (it_cell) {
        content = it_cell->getCellContent();
        if (content)
            if (typeid(*content) == typeid(Enemy))
                controllers.push_back(new EnemyController(dynamic_cast<Enemy*>(content), field, it_cell));

        it_cell = iterator.getNext();
    }
}

void EnemyManageCenter::move_all() {
    for (int i = 0; i < controllers.size(); i++) {
        EnemyController* curr_controller = controllers[i];

        // Calc move chance
        RandomNumberGenerator randomizer;
        std::string option = directions[int(randomizer.generate(0, 3))];
        std::string response = curr_controller->move(option);

        if (response == "DIED")
            controllers.erase(controllers.begin() + i);
    }
    return;
}