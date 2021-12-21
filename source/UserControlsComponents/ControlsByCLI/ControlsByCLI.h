//
// Created by mikeasta on 21.12.2021.
//

#ifndef OOP_GAME_CONTROLSBYCLI_H
#define OOP_GAME_CONTROLSBYCLI_H
#include "../ControlsInterface/ControlsInterface.h"
#include <map>
#include <string>
#include <iostream>
#include "../../GameComponents/Response/Response.h"

class ControlsByCLI: public ControlsInterface {
private:
    std::map<std::string, std::string> binds = {
            {"w", "up"},
            {"a", "left"},
            {"s", "down"},
            {"d", "right"}
    };
public:
    ControlsByCLI(std::map<std::string, std::string> binds = {});
    ~ControlsByCLI() override = default;
    std::string listen() final;
    std::map<std::string, std::string> getBinds();
    void changeBind(std::string command, std::string new_bind);
};
#endif //OOP_GAME_CONTROLSBYCLI_H
