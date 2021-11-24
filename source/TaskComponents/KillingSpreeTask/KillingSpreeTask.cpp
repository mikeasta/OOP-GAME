//
// Created by mikeasta on 24.11.2021.
//

#include "KillingSpreeTask.h"

KillingSpreeTask::KillingSpreeTask(std::map<std::string, int> field_stats):
    current_enemy_count(field_stats["enemy_count"]),
    initial_enemy_count(field_stats["enemy_count"]){
    RandomNumberGenerator rd = RandomNumberGenerator();
    int count = rd.generate(1, initial_enemy_count);
    need_to_kill = count;
}

bool KillingSpreeTask::update(std::map<std::string, int> field_stats, std::string player_response) {
    current_enemy_count = field_stats["enemy_count"];
    if ((initial_enemy_count - current_enemy_count) == need_to_kill) {
        return true;
    }
    return false;
}

std::string KillingSpreeTask::getTaskText() {
    std::string text = "\n\"Killing spree\"";
    int num = need_to_kill - (initial_enemy_count - current_enemy_count);
    if (num < 0) {
        num = 0;
    }

    text += "\nKill " + std::to_string(num) + " enemies ";
    if (num == 0) {
        text += "(done)";
    }
    return text;
}
