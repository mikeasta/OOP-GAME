//
// Created by mikeasta on 23.11.2021.
//

#ifndef OOP_GAME_FIELDOBSERVER_H
#define OOP_GAME_FIELDOBSERVER_H
#include "../Field/Field.h"
#include "../FieldIterator/FieldIterator.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../InteractiveObjectComponents/Enemy/Enemy.h"
#include "../../InteractiveObjectComponents/Item/Item.h"
#include <string>
#include <map>

class FieldObserver {
private:
    Field& field;
    std::map<std::string, int> current_field_stats = {
            {"enemy_count", 0},
            {"item_count", 0},
            {"floor_cells_count", 0}
    };
    void analyze();
public:
    FieldObserver(Field &field);
    std::map<std::string, int> getFieldStats();
};

#endif //OOP_GAME_FIELDOBSERVER_H
