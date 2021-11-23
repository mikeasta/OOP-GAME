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

class MainMenu {
private:
    std::map<std::string, char> controls = {
            {"up", *"w"},
            {"down", *"s"},
            {"left", *"a"},
            {"right", *"d"}
    };
    std::vector<std::string> __menu_options = {
            "Start Game",
            "Controls",
            "Exit"
    };
public:
    std::map<std::string, char> call();
};

#endif //OOP_GAME_MAINMENU_H
