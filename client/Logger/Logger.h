//
// Created by mikeasta on 03.11.2021.
//

#ifndef OOP_GAME_LOGGER_H
#define OOP_GAME_LOGGER_H
#include <iostream>
#include <string>
#include <fstream>
#include "../../source/ControllerComponents/Controller/Controller.h"


class Logger {
private:
    Controller& controller;
    bool log_to_console = true;
    bool log_to_file = true;
    std::string filepath = "/home/mikeasta/Programming/OOP-GAME/client/Logger/log.txt";
public:
    Logger(Controller& controller);
    ~Logger();

    friend std::ostream& operator<<(std::ostream &out, const Logger &logger);
    void log();
};

#endif //OOP_GAME_LOGGER_H
