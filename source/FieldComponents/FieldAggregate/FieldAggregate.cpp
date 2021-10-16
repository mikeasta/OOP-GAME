//
// Created by mikeasta on 16.10.2021.
//

#include "FieldAggregate.h"

void FieldAggregate::aggregate(Field *field, Player *player) {
    if (!field_is_aggregated) {
        field_is_aggregated = true;
        ItemPlacer item_placer;
        EnemyPlacer enemy_placer;
        player->spawn(field);
        item_placer.fillField(field);
        enemy_placer.fillField(field);
    }
}

