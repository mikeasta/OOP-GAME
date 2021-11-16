//
// Created by mikeasta on 03.11.2021.
//

#include "Logger.h"
Logger::Logger(Controller& controller):
    controller(controller) {}

Logger::~Logger() {
    for (auto unit: logger_units) {
        delete unit;
    }
}

void Logger::addLoggerUnits(std::ostream &output, bool is_input_enable, std::string logger_unit_id) {
    auto new_unit = new LoggerUnit(output, is_input_enable, logger_unit_id);
    logger_units.push_back(new_unit);
}

void Logger::log() {
    std::string message = controller.popUpdate();
    for (auto unit: logger_units) {
        unit->log(message);
    }
}

void Logger::toggleLog(std::string stream_id) {
    for (auto unit: logger_units) {
        if (unit->getId() == stream_id) {
            unit->toggleOutput();
        }
    }
}
