//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_ENEMYMANAGECENTER_H
#define OOP_GAME_ENEMYMANAGECENTER_H
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../../FieldComponents/Field/Field.h"
#include "../EnemyController/EnemyController.h"
#include <string>
#include <tuple>

class EnemyManageCenter {
private:
    std::map<std::string, char> directions = {
            { "up", *"w"},
            { "down", *"s"},
            { "left", *"a"},
            { "right", *"d"}
    };
protected:
    std::vector<EnemyController*> controllers = {};
    Field* field;
public:
    explicit EnemyManageCenter(Field* field);

    void move_all();
};

#endif //OOP_GAME_ENEMYMANAGECENTER_H
