//
// Created by mikeasta on 03.11.2021.
//

#include "Logger.h"
Logger::Logger (Controller& controller):
    controller(controller) {};

std::ostream& operator<<(std::ostream &out, const Logger &logger) {
    out << logger.controller.popUpdate();
    return out;
}
