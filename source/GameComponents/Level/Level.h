//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_LEVEL_H
#define OOP_GAME_LEVEL_H
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
#include "../../UserControlsComponents/ControlsManager/ControlsManager.h"
#include "../../UserControlsComponents/ControlsByCLI/ControlsByCLI.h"

class Level {
private:
    Field& field;
    Player& player;
    ControlsManager& controls_manager;
    bool game_goes = false;
    std::string result;
public:
    Level(Field& field, Player& player, ControlsManager& controls_manager);
    std::string start();
    void game_end();
};

#endif //OOP_GAME_LEVEL_H
