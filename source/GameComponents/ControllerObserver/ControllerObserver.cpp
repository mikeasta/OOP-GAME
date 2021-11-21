//
// Created by mikeasta on 17.11.2021.
//

#include "ControllerObserver.h"

void ControllerObserver::addController(Controller *controller) {
    // Clear all previous updates
    controller->popUpdate();

    interest_controllers.push_back(controller);
}

void ControllerObserver::removeController(int index) {
    interest_controllers.erase(interest_controllers.begin() + index);
}

std::string ControllerObserver::popUpdates() {
    for (auto controller : interest_controllers) {
        update_string += controller->popUpdate();
    }

    auto tmp = update_string;
    update_string = "";
    return tmp;
}