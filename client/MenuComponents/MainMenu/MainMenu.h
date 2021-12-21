//
// Created by mikeasta on 23.11.2021.
//

#ifndef OOP_GAME_MAINMENU_H
#define OOP_GAME_MAINMENU_H
#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "../Controls/Controls.h"
#include "../../../source/UserControlsComponents/ControlsInterface/ControlsInterface.h"

class MainMenu {
    std::vector<std::string> __menu_options = {
            "Start Game",
            "Controls",
            "Exit"
    };
public:
    void call(ControlsInterface& control_interface);
};

#endif //OOP_GAME_MAINMENU_H
