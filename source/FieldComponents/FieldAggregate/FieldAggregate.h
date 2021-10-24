//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_FIELDAGGREGATE_H
#define OOP_GAME_FIELDAGGREGATE_H
#include "../Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../InteractiveObjectComponents/ItemPlacer/ItemPlacer.h"
#include "../../InteractiveObjectComponents/EnemyPlacer/EnemyPlacer.h"

class FieldAggregate {
private:
    bool field_is_aggregated = false;
public:
    void aggregate(Field &field, Player &player);
};

#endif //OOP_GAME_FIELDAGGREGATE_H
