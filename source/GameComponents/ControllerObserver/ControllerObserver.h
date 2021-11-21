//
// Created by mikeasta on 17.11.2021.
//

#ifndef OOP_GAME_CONTROLLEROBSERVER_H
#define OOP_GAME_CONTROLLEROBSERVER_H
#include "../../ControllerComponents/Controller/Controller.h"
#include <vector>
#include <string>

class ControllerObserver {
private:
   std::vector<Controller*> interest_controllers = {};
   std::string update_string = "";
public:
    void addController(Controller *controller);
    void removeController(int index);
    std::string popUpdates();
};

#endif //OOP_GAME_CONTROLLEROBSERVER_H
