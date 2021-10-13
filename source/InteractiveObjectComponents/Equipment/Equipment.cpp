//
// Created by mikeasta on 13.10.2021.
//

#include "Equipment.h"

Equipment::Equipment():items({}) {};

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

Equipment::~Equipment() {
    int equipment_size = items.size();
    for (int i = equipment_size - 1; i >= 0 ; i--) {
        delete items[i];
    }

    delete this;
}

int Equipment::getAttackBuff() {
    int equipment_size = items.size();
    int attack_buff    = 0;
    for (int i = 0; i < equipment_size; i++)
        attack_buff += items[i]->getBonusAttack();
    return attack_buff;
}

int Equipment::getStaminaBuff() {
    int equipment_size = items.size();
    int stamina_buff    = 0;
    for (int i = 0; i < equipment_size; i++)
        stamina_buff += items[i]->getBonusStamina();
    return stamina_buff;
}

int Equipment::getDefenceBuff() {
    int equipment_size = items.size();
    int defence_buff    = 0;
    for (int i = 0; i < equipment_size; i++)
        defence_buff += items[i]->getBonusDefence();
    return defence_buff;
}