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