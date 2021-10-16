//
// Created by mikeasta on 16.10.2021.
//

#ifndef OOP_GAME_GAME_H
#define OOP_GAME_GAME_H
#include "../../../client/FieldCLI/FieldCLI.h"
#include "../../FieldComponents/FieldGenerator/FieldGenerator.h"
#include "../../FieldComponents/Field/Field.h"
#include "../../InteractiveObjectComponents/Player/Player.h"
#include "../../InteractiveObjectComponents/ItemPlacer/ItemPlacer.h"
#include "../../InteractiveObjectComponents/EnemyPlacer/EnemyPlacer.h"

class Game {
private:
    bool game_is_started = false;
public:
    void start();
};
#endif //OOP_GAME_GAME_H