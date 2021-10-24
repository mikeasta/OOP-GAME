//
// Created by mikeasta on 20.10.2021.
//

#ifndef OOP_GAME_EQUIPMENTCLI_H
#define OOP_GAME_EQUIPMENTCLI_H
#include "../CLI/CLI.h"
#include "../../source/InteractiveObjectComponents/Player/Player.h"
#include <tuple>
#include <map>
#include <string>
#include <iostream>

class EquipmentCLI: public CLI {
private:
    Player &player;
public:
    explicit EquipmentCLI(Player& player);
    void print() final;
};

#endif //OOP_GAME_EQUIPMENTCLI_H