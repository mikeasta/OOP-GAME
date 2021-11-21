//
// Created by mikeasta on 03.11.2021.
//

#ifndef OOP_GAME_LOGGER_H
#define OOP_GAME_LOGGER_H
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include "../LoggerUnit/LoggerUnit.h"
#include "../../source/GameComponents/ControllerObserver/ControllerObserver.h"
#include "../../source/ControllerComponents/Controller/Controller.h"

class Logger {
private:
    ControllerObserver& cont_obs;
    std::vector<LoggerUnit*> logger_units = {};
public:
    Logger(ControllerObserver& controller);
    ~Logger();

    void addLoggerUnit(std::ostream& output, bool is_input_enable, std::string logger_unit_id);
    void addLoggerUnit(LoggerUnit& logger_unit);
    void log();

    void toggleLog(std::string stream_id);
};

#endif //OOP_GAME_LOGGER_H
