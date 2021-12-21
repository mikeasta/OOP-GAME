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
    std::map<std::string, std::pair<unsigned int, unsigned int>> directions = {
            { "up",    {0, -1}},
            { "down",  {0,  1}},
            { "left",  {-1, 0}},
            { "right", {1,  0}}
    };

    Field &field;
    Player &player;
    Cell* curr_cell;

    bool is_able_to_exit = false;
public:
    PlayerController(Player &player, Field &field);
    std::pair<std::string, Combat> move(std::string direction);
    void enableLeaving();
};

#endif //OOP_GAME_PLAYERCONTROLLER_H
