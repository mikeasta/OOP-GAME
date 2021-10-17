//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#define OOP_GAME_PLAYERCONTROLLER_H
#include <tuple>
#include <string>
#include "../../InteractiveObjectComponents/Enemy/Enemy.h"
#include "../../InteractiveObjectComponents/Character/Character.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"

class PlayerController {
private:
    Field* field;
    Player* player;
    Cell* curr_cell;
public:
    PlayerController(Player* player, Field* field);
    ~PlayerController() = default;

    std::string move(std::string direction);
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
