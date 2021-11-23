//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_PLAYERCONTROLLER_H
#define OOP_GAME_PLAYERCONTROLLER_H

#include <map>
#include <tuple>
#include <string>
#include "../../GameComponents/Response/Response.h"
#include "../../InteractiveObjectComponents/Enemy/Enemy.h"
#include "../../InteractiveObjectComponents/Character/Character.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../FieldComponents/FieldIterator/FieldIterator.h"
#include "../Controller/Controller.h"

class PlayerController: public Controller{
private:
    std::map<std::string, char> directions = {
            { "up", *"w"},
            { "down", *"s"},
            { "left", *"a"},
            { "right", *"d"}
    };

    Field &field;
    Player &player;
    Cell* curr_cell;

    bool is_able_to_exit = false;
public:
    PlayerController(Player &player, Field &field);
    void setControls(std::map<std::string, char> new_controls);
    std::pair<std::string, Combat> move(char direction);
    void toggleAbilityToLeave();
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
