//
// Created by mikeasta on 24.11.2021.
//

#ifndef OOP_GAME_KILLINGSPREETASK_H
#define OOP_GAME_KILLINGSPREETASK_H
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <string>
#include <map>

class KillingSpreeTask {
private:
    int current_enemy_count = 0;
    int initial_enemy_count = 0;
    int need_to_kill        = 0;
public:
    KillingSpreeTask(std::map<std::string, int> field_stats);
    bool update(std::map<std::string, int> field_stats, std::string player_response);
    std::string getTaskText();
};

#endif //OOP_GAME_KILLINGSPREETASK_H
