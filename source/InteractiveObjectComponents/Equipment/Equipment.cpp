//
// Created by mikeasta on 13.10.2021.
//

#include "Equipment.h"

Equipment::Equipment():items({}) {}

void Equipment::addItem(Item *new_item) {
    items.push_back(new_item);
}

void Equipment::removeItem(int order_num) {
    // Order_num is a num between 1 and equipment length
    // So we have to iterate with order_num - 1
    Item* tmp = items[order_num-1];
    items[order_num-1] = nullptr;
    delete tmp;
    items.erase( items.begin() + (order_num - 1));
}

int Equipment::getAttackBuff() {
    unsigned int equipment_size = items.size();
    int attack_buff = 0;

    for (int i = 0; i < equipment_size; i++)
        attack_buff += items[i]->getBonusAttack();
    return attack_buff;
}

int Equipment::getStaminaBuff() {
    unsigned int equipment_size = items.size();
    int stamina_buff = 0;

    for (int i = 0; i < equipment_size; i++)
        stamina_buff += items[i]->getBonusStamina();
    return stamina_buff;
}

int Equipment::getDefenceBuff() {
    unsigned int equipment_size = items.size();
    int defence_buff = 0;

    for (int i = 0; i < equipment_size; i++)
        defence_buff += items[i]->getBonusDefence();
    return defence_buff;
}

std::map<std::string, int> Equipment::getItemLabels() {
    std::map<std::string, int> item_count_voc;
    unsigned int equipment_length = items.size();
    for (int i = 0; i < equipment_length; i++) {
        if (item_count_voc[items[i]->getName()])
            item_count_voc[items[i]->getName()]++;
        else
            item_count_voc[items[i]->getName()] = 1;
    }

    return item_count_voc;
}