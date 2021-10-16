//
// Created by mikeasta on 13.10.2021.
//

#include "Item.h"

Item::Item(std::string item_name, int bonus_attack, int bonus_stamina, int bonus_defence):
    item_name(item_name),
    bonus_attack(bonus_attack),
    bonus_stamina(bonus_stamina),
    bonus_defence(bonus_defence) {};

std::string Item::getName() {
    return this->item_name;
}

int Item::getBonusAttack() {
    return this->bonus_attack;
}

int Item::getBonusStamina() {
    return this->bonus_stamina;
}

int Item::getBonusDefence() {
    return this->bonus_defence;
}

InteractiveObject* Item::clone() {
    return new Item(item_name, bonus_attack, bonus_stamina, bonus_defence);
}

