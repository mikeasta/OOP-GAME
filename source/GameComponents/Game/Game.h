//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H
#include "../Response/Response.h"
#include "../../../client/FieldCLI/FieldCLI.h"
#include "../../../client/PlayerCLI/PlayerCLI.h"
#include "../../../client/CombatCLI/CombatCLI.h"
#include "../../../client/EquipmentCLI/EquipmentCLI.h"
#include "../../../client/Logger/Logger.h"
#include "../../../client/MenuComponents/MainMenu/MainMenu.h"
#include "../../../client/TaskCLI/TaskCLI.h"
#include "../../FieldComponents/FieldGenerator/FieldGenerator.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../FieldComponents/FieldObserver/FieldObserver.h"
#include "../../FieldComponents/FieldAggregate/FieldAggregate.h"
#include "../../ControllerComponents/PlayerController/PlayerController.h"
#include "../../ControllerComponents/EnemyManageCenter/EnemyManageCenter.h"
#include "../../TaskComponents/KillingSpreeTask/KillingSpreeTask.h"
#include "../../TaskComponents/CollectionerTask/CollectionerTask.h"

class Game {
private:
    bool game_is_started = false;
    bool game_goes = false;
public:
    void start();
    void stop();
};

#endif //OOP_GAME_GAME_H
