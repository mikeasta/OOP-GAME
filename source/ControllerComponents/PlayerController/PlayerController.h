//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#define OOP_GAME_PLAYERCONTROLLER_H
#include <tuple>
#include <string>
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"

class PlayerController {
private:
    Player* player;
    Field* field;
    Cell* curr_cell;
public:
    PlayerController(Player* player, Field* field);
    ~PlayerController() = default;

    std::string move(std::string direction);
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
