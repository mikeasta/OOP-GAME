//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_CONTROLSINTERFACE_H
#define OOP_GAME_CONTROLSINTERFACE_H
#include <string>

class ControlsInterface {
public:
    virtual ~ControlsInterface() = default;
    virtual std::string listen() = 0;
};

#endif //OOP_GAME_CONTROLSINTERFACE_H
