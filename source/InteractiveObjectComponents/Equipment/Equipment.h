//
// Created by mikeasta on 13.10.2021.
//

#ifndef OOP_GAME_EQUIPMENT_H
#define OOP_GAME_EQUIPMENT_H

#include "../Item/Item.h"
#include <vector>
#include <tuple>
#include <string>

class Equipment {
private:
    std::vector<Item*> items;
public:
    Equipment();
    ~Equipment() = default;

    void addItem(Item* new_item);
    void removeItem(int order_num);
    int getAttackBuff();
    int getStaminaBuff();
    int getDefenceBuff();
    std::map<std::string, int> getItemLabels();
};

#endif //OOP_GAME_EQUIPMENT_H
