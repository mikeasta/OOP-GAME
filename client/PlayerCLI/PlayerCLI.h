//
// Created by mikeasta on 17.10.2021.
//

#ifndef OOP_GAME_PLAYERCLI_H
#define OOP_GAME_PLAYERCLI_H
#include "../CLI/CLI.h"
#include "../../source/InteractiveObjectComponents/Player/Player.h"
#include <iostream>
#include <string>

class PlayerCLI: public CLI {
protected:
    Player& player;
public:
    PlayerCLI(Player& player);

    void print() override;
};

#endif //OOP_GAME_PLAYERCLI_H
