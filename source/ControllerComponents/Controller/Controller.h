//
// Created by mikeasta on 31.10.2021.
//

#ifndef OOP_GAME_CONTROLLER_H
#define OOP_GAME_CONTROLLER_H
#include <string>
#include <stdio.h>
#include <time.h>
#include <chrono>

class Controller {
private:
    std::string update_message;
public:
    void update(std::string upd_str);
    std::string popUpdate();
};

#endif //OOP_GAME_CONTROLLER_H
