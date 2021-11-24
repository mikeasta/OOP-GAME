//
// Created by mikeasta on 24.11.2021.
//

#ifndef OOP_GAME_TASKMANAGER_H
#define OOP_GAME_TASKMANAGER_H
#include <string>
#include <map>

template <typename TASK>
class TaskManager {
private:
    TASK &task;
public:
    explicit TaskManager(TASK &task):
        task(task) {}

    bool update(std::map<std::string, int> field_stats, std::string response) {
        return task.update(field_stats, response);
    }

    std::string getTaskText() {
        return task.getTaskText();
    }
};

#endif //OOP_GAME_TASKMANAGER_H
