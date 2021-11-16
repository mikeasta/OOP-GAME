//
// Created by mikeasta on 13.10.2021.
//

#include "Item.h"

#include <utility>

Item::Item(std::string item_name, int bonus_attack, int bonus_stamina, int bonus_defence):
    item_name(std::move(item_name)),
    bonus_attack(bonus_attack),
    bonus_stamina(bonus_stamina),
    bonus_defence(bonus_defence) {}

Item* Item::create(std::map<std::string, std::vector<int>> item_voc) {
    RandomNumberGenerator randomizer;
    auto curr = item_voc.begin();

    std::advance(curr, randomizer.generate(0, 8));
    return new Item(curr->first, curr->second[0], curr->second[1], curr->second[2]);
}

std::string Item::getName() {
    return this->item_name;
}

int Item::getBonusAttack() const {
    return this->bonus_attack;
}

int Item::getBonusStamina() const {
    return this->bonus_stamina;
}

int Item::getBonusDefence() const {
    return this->bonus_defence;
}

InteractiveObject* Item::clone() {
    return new Item(item_name, bonus_attack, bonus_stamina, bonus_defence);
}

std::ostream& operator<< (std::ostream& out, const Item &item) {
    out << "\nItem \"" << item.item_name << "\":";
    out << "\nBonus attack: " << item.bonus_attack;
    out << "\nBonus defence: " << item.bonus_defence;
    out << "\nBonus stamina (healing): " << item.bonus_stamina;

    return out;
}