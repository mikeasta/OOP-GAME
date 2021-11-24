//
// Created by mikeasta on 24.11.2021.
//

#ifndef OOP_GAME_TASKCLI_H
#define OOP_GAME_TASKCLI_H
#include "../../source/TaskComponents/TaskManager/TaskManager.h"
#include "../../source/TaskComponents/TaskManager/TaskManager.cpp"
#include "../CLI/CLI.h"
#include <iostream>

template <class TASK>
class TaskCLI:public CLI {
private:
    TaskManager<TASK> &tm;
public:
    TaskCLI(TaskManager<TASK> &tm):
            tm(tm) {};

    void print() override {
        std::cout << tm.getTaskText();
    };
};

#endif //OOP_GAME_TASKCLI_H
