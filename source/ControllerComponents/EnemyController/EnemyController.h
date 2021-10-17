//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_ENEMYCONTROLLER_H
#define OOP_GAME_ENEMYCONTROLLER_H

#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Enemy/Enemy.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <string>

class EnemyController {
private:
    Field* field;
    Enemy* enemy;
    Cell* curr_cell;
public:
    EnemyController(Enemy* enemy, Field* field, Cell* curr_cell);
    // ~EnemyController() = default;

    std::string move(std::string direction);
};

#endif //OOP_GAME_ENEMYCONTROLLER_H
