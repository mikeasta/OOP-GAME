//
// Created by mikeasta on 21.12.2021.
//

#include "ControlsManager.h"

ControlsManager::ControlsManager(ControlsInterface &controls_interface):
    controls_interface(controls_interface) {
}

std::string ControlsManager::listen() {
    return controls_interface.listen();
}

bool ControlsManager::checkForMovement(std::string command) {
    if (command == "up" || command == "down" || command == "right" || command == "left") {
        return true;
    } else {
        return false;
    }
}

bool ControlsManager::checkForSaving(std::string command) {
    return command == "save";
}

bool ControlsManager::checkForLoading(std::string command) {
    return command == "load";
}