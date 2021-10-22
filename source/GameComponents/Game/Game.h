//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H
#include "../../../client/FieldCLI/FieldCLI.h"
#include "../../../client/PlayerCLI/PlayerCLI.h"
#include "../../../client/CombatCLI/CombatCLI.h"
#include "../../../client/EquipmentCLI/EquipmentCLI.h"
#include "../../FieldComponents/FieldGenerator/FieldGenerator.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../FieldComponents/FieldAggregate/FieldAggregate.h"
#include "../../ControllerComponents/PlayerController/PlayerController.h"
#include "../../ControllerComponents/EnemyManageCenter/EnemyManageCenter.h"
#include <unistd.h>
#include <ncurses.h>

class Game {
private:
    bool game_is_started = false;
    bool game_goes = false;
public:
    void start();
};

#endif //OOP_GAME_GAME_H
