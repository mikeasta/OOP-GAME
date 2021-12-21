//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_CONTROLSINTERFACE_H
#define OOP_GAME_CONTROLSINTERFACE_H
#include <string>
#include <map>

class ControlsInterface {
public:
    virtual ~ControlsInterface() = default;
    virtual std::string listen() = 0;
    virtual std::map<std::string, std::string> getBinds() = 0;
    virtual void changeBind(std::string command, std::string new_bind) = 0;
};

#endif //OOP_GAME_CONTROLSINTERFACE_H
