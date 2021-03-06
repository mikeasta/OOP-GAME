//
// Created by mikeasta on 18.10.2021.
//

#ifndef OOP_GAME_COMBATCLI_H
#define OOP_GAME_COMBATCLI_H
#include "../CLI/CLI.h"
#include "../../source/GameComponents/Combat/Combat.h"
#include <tuple>
#include <string>
#include <iostream>

class CombatCLI: public CLI {
private:
    Combat last_combat;
public:
    void setLastCombat(Combat new_combat);
    void print() final;
};

#endif //OOP_GAME_COMBATCLI_H
