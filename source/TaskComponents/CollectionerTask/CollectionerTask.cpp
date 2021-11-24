//
// Created by mikeasta on 24.11.2021.
//

#include "CollectionerTask.h"

CollectionerTask::CollectionerTask(std::map<std::string, int> field_stats):
    current_item_count(field_stats["item_count"]),
    initial_item_count(field_stats["item_count"]){
    RandomNumberGenerator rd = RandomNumberGenerator();
    int count = rd.generate(1, initial_item_count);
    need_to_take = count;
}

bool CollectionerTask::update(std::map<std::string, int> field_stats, std::string player_response) {
    current_item_count = field_stats["item_count"];
    if ((initial_item_count - current_item_count) == need_to_take) {
        return true;
    }
    return false;
}

std::string CollectionerTask::getTaskText() {
    std::string text = "\n\"Collectioner\"";
    int num = need_to_take - (initial_item_count - current_item_count);
    if (num < 0) {
        num = 0;
    }

    text += "\nTake " + std::to_string(num) + " items ";
    if (num == 0) {
        text += "(done)";
    }
    return text;
}
