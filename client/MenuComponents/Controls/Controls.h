//
// Created by mikeasta on 23.11.2021.
//

#ifndef OOP_GAME_CONTROLS_H
#define OOP_GAME_CONTROLS_H
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include "../../../source/UserControlsComponents/ControlsInterface/ControlsInterface.h"

class Controls {
public:
    void call(ControlsInterface& controls);
};

#endif //OOP_GAME_CONTROLS_H
