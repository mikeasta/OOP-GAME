//
// Created by mikeasta on 03.11.2021.
//

#ifndef OOP_GAME_LOGGER_H
#define OOP_GAME_LOGGER_H
#include <iostream>
#include <string>
#include "../../source/ControllerComponents/Controller/Controller.h"

class Logger {
private:
    Controller& controller;
public:
    Logger(Controller& controller);

    friend std::ostream& operator<<(std::ostream &out, const Logger &logger);
};

#endif //OOP_GAME_LOGGER_H
