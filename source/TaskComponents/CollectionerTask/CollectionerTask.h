//
// Created by mikeasta on 24.11.2021.
//

#ifndef OOP_GAME_COLLECTIONERTASK_H
#define OOP_GAME_COLLECTIONERTASK_H
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"
#include <string>
#include <map>

class CollectionerTask {
private:
    int current_item_count = 0;
    int initial_item_count = 0;
    int need_to_take       = 0;
public:
    CollectionerTask(std::map<std::string, int> field_stats);
    bool update(std::map<std::string, int> field_stats, std::string player_response);
    std::string getTaskText();
};

#endif //OOP_GAME_COLLECTIONERTASK_H
