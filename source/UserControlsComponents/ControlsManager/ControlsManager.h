//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_CONTROLSMANAGER_H
#define OOP_GAME_CONTROLSMANAGER_H
#include "../ControlsInterface/ControlsInterface.h"

class ControlsManager {
private:
    ControlsInterface& controls_interface;
public:
    ControlsManager(ControlsInterface& controls_interface);
    std::string listen();
    bool checkForMovement(std::string command);
    bool checkForSaving(std::string command);
    bool checkForLoading(std::string command);
};

#endif //OOP_GAME_CONTROLSMANAGER_H
