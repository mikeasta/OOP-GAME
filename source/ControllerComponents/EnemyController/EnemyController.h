//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_ENEMYCONTROLLER_H
#define OOP_GAME_ENEMYCONTROLLER_H

#include "../../GameComponents/Response/Response.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Enemy/Enemy.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include "../Controller/Controller.h"
#include <string>
#include <tuple>
#include <map>

class EnemyController: public Controller {
private:
    Field& field;
    Enemy* enemy;
    Cell* curr_cell;
public:
    EnemyController(Enemy* enemy, Field& field, Cell* curr_cell);

    std::string move(std::map<std::string, char> direction_voc, char direction);
};

#endif //OOP_GAME_ENEMYCONTROLLER_H
