//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_ENEMYPLACER_H
#define OOP_GAME_ENEMYPLACER_H
#include "../Enemy/Enemy.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"

class EnemyPlacer {
private:
    std::map<std::string, std::vector<int>> enemy_voc = {
            { "enemy_1", {5, 30, 5} },
            { "enemy_2", {5, 50, 40} },
            { "enemy_3", {5, 100, 15} },
    };
public:
    void place(Enemy* curr_enemy, Cell* curr_cell);
    void fillField(Field &field);
};

#endif //OOP_GAME_ENEMYPLACER_H
