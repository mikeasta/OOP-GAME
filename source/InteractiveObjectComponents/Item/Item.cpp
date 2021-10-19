//
// Created by mikeasta on 13.10.2021.
//

#include "Item.h"

std::map<std::string, std::vector<int>> item_voc = {
        { "light damage",  {5, 0, 0} },
        { "medium damage", {25, 5, 5} },
        { "large damage",  {100, 10, 10} },
        { "light stamina", {0, 5, 0} },
        { "medium stamina",{5, 25, 5} },
        { "large stamina", {10, 100, 10} },
        { "light defence", {0, 0, 5} },
        { "medium defence",{5, 5, 25} },
        { "large defence", {10, 0, 50} },
};

Item::Item(std::string item_name, int bonus_attack, int bonus_stamina, int bonus_defence):
    item_name(item_name),
    bonus_attack(bonus_attack),
    bonus_stamina(bonus_stamina),
    bonus_defence(bonus_defence) {};

Item* Item::create(std::string item_type) {
    auto curr = item_voc.begin();

    // Search for correct pair
    curr = item_voc.find(item_type);
    return new Item(curr->first, curr->second[0], curr->second[1], curr->second[2]);
}

Item* Item::create() {
    RandomNumberGenerator randomizer;
    auto curr = item_voc.begin();
    std::advance(curr, randomizer.generate(0, 8));
    return new Item(curr->first, curr->second[0], curr->second[1], curr->second[2]);
}

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
