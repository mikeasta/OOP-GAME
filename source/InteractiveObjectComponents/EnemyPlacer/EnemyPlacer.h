//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_ENEMYPLACER_H
#define OOP_GAME_ENEMYPLACER_H
#include "../Enemy/Enemy.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"

class EnemyPlacer {
public:
    void place(Enemy* curr_enemy, Cell* curr_cell);
    void fillField(Field* field);
};

#endif //OOP_GAME_ENEMYPLACER_H
