//
// Created by mikeasta on 13.10.2021.
//

#ifndef OOP_GAME_ITEM_H
#define OOP_GAME_ITEM_H

#include "../InteractiveObject/InteractiveObject.h"
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include <iostream>
#include "../../../utils/RandomNumberGenerator/RandomNumberGenerator.h"

class Item: public InteractiveObject {
protected:
    std::string item_name;
    int bonus_attack;
    int bonus_stamina;
    int bonus_defence;
public:
    // Constructor
    explicit Item(std::string item_name = "item", int bonus_attack = 0, int bonus_stamina = 0, int bonus_defence = 0);
    ~Item() override = default;

    // Getter
    std::string getName();
    int getBonusAttack() const;
    int getBonusStamina() const;
    int getBonusDefence() const;

    // Pattern: Prototype
    // Clones current Item
    InteractiveObject* clone() override;

    // Pattern: Factory Method
    Item* create(std::map<std::string, std::vector<int>> item_voc);

    friend std::ostream& operator<< (std::ostream& out, const Item &item);
};

#endif //OOP_GAME_ITEM_H
